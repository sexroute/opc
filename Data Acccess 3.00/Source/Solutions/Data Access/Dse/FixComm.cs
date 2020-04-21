using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;


namespace Dse
{
    using Aco;
    using DseHelper;

    public class FixComm : IDisposable
    {
        public delegate int ServiceHandler(FixComm fixcomm);

        internal const short  SERVICE_SYSTEM_LOGIN    = 25015;
        internal const string SERVICE_SYSTEM_TAG      = "ICEP";

        enum Mode
        {
            None,
            Client,
            Server,
        }

        enum Direction
        {
            Unknown,
            Request,
            Response
        }

        public enum Message
        {
            TraceLocator,
            TraceNetwork,
            TraceProtocol,
            TraceRetry,
            TraceSlicing,
            TraceThreadPool,

            WarnAMICallback,
            WarnConnections,
            WarnDatagrams,
            WarnDispatch,
            WarnEndpoints,
            WarnUnknownProperties,
            WarnUnusedProperties,
        }

        internal sealed class Getter
        {
            internal bool Valid { get; private set; }

            internal Dictionary<int, SFieldContent> Current { get; private set; }

            internal int Count { get; private set; }

            internal short Function { get; private set; }

            private IEnumerator<Dictionary<int, SFieldContent>> _enumerator;

            private static readonly Dictionary<int, SFieldContent>[] _empty
                = new Dictionary<int, SFieldContent>[]
            {
            };

            private static readonly Dictionary<int, SFieldContent>[] _dummy
                = new Dictionary<int, SFieldContent>[]
            {
                new Dictionary<int, SFieldContent>()
            };

            internal Getter(short function, Dictionary<int, SFieldContent>[] packets, bool allowEmpty = false)
            {
                if (packets == null || packets.Length == 0)
                {
                    this.Count = 0;

                    if(allowEmpty)
                    {
                        this._enumerator = _dummy.AsEnumerable().GetEnumerator();
                    }
                    else
                    {
                        this._enumerator = _empty.AsEnumerable().GetEnumerator();
                    }
                }
                else
                {
                    this.Count = packets.Length;

                    this._enumerator = packets.AsEnumerable().GetEnumerator();
                }

                this.Function = function;

                _Next();
            }

            internal bool Next()
            {
                if (!this.Valid)
                {
                    Debug.Assert(false);

                    return false;
                }

                _Next();

                return this.Valid;
            }

            internal bool Get(int key, out SFieldContent value)
            {
                bool ret = this.Current.TryGetValue(key, out value);

                if (!ret)
                {
/*
                    Debug.WriteLine(
                        string.Format("Function {0}: Field {1} Not Exist",
                            this.Function, key));*/
                }

                return ret;
            }

            internal bool Exist(int key)
            {
                return this.Current.ContainsKey(key);
            }

            private void _Next()
            {
                this.Valid = this._enumerator.MoveNext();

                if (this.Valid) this.Current = this._enumerator.Current;
            }
        }

        internal sealed class Setter
        {
            internal Dictionary<int, SFieldContent> Current { get; private set; }

            internal int Count
            {
                get
                {
                    int count = this._contents.Count;

                    if(count == 1)
                    {
                        if(this.Current.Count == 0)
                        {
                            return 0;
                        }
                    }

                    return count;
                }
            }

            private List<Dictionary<int, SFieldContent>> _contents;

            internal Setter()
            {
                this.Current = new Dictionary<int, SFieldContent>(7);

                this._contents = new List<Dictionary<int, SFieldContent>>(1);

                this._contents.Add(this.Current);
            }

            internal void Increment()
            {
                this.Current = new Dictionary<int, SFieldContent>(7);

                this._contents.Add(this.Current);
            }

            internal void Decrement()
            {
                this._contents.RemoveAt(this._contents.Count - 1);
            }

            internal void Add(int key, SFieldContent value)
            {
                this.Current.Add(key, value);
            }

            internal bool Get(int key, out SFieldContent value)
            {
                return this.Current.TryGetValue(key, out value);
            }

            internal bool Exist(int key)
            {
                return this.Current.ContainsKey(key);
            }

            internal void Reset()
            {
                if(this._contents.Count == 1)
                {
                    if(this._contents[0] == this.Current)
                    {
                        this.Current.Clear();

                        return;
                    }
                }

                this.Current.Clear();

                this._contents.Clear();

                this._contents.Add(this.Current);
            }

            internal Dictionary<int, SFieldContent>[] ToArray()
            {
                if(this._contents.Count == 1 && this.Current.Count == 0)
                {
                    return new Dictionary<int, SFieldContent>[0];
                }

                return this._contents.ToArray();
            }
        }

        // TimeOut: seconds
        public int TimeOut
        {
            get
            {
                return this._timeout;
            }

            set
            {
                if (this._proxy != null)
                {
                    int milliseconds = value * 1000;

                    this._proxy.ice_timeout(milliseconds);
                }

                this._timeout = value;
            }
        }
        private int _timeout = 10;


        public int Logging
        {
            get { return _logging; }
            set { _logging = value; }
        }
        private int _logging;

        public int Processor
        {
            get
            {
                return this._processor;
            }

            set
            {
                this._processor = value;
            }
        }
        private int _processor = 4;

        public bool AllowOverride
        {
            get
            {
                return _allow_multiple_set;
            }

            set
            {
                _allow_multiple_set = value;
            }
        }
        private bool _allow_multiple_set;

        public string MessageEncoding
        {
            get
            {
                return _messageEncoding;
            }

            set
            {
                _messageEncoding = value;
            }
        }
        private string _messageEncoding = "gb2312";

        public int MessageSizeMax
        {
            get
            {
                return _messageSizeMax;
            }

            set
            {
                _messageSizeMax = value;
            }
        }
        private int _messageSizeMax = 102400;


        private string _key;

        private Ice.Communicator _communicator;

        private RequestPrx       _proxy;   // client

        Ice.ObjectAdapter _adapter; // server: adapter
        RequestI _impl;             // server: implementation

        private Mode _mode;
        private Direction _direction;

        private bool _active; // 连接正常

        private SDataPacket _request;  // 请求数据
        private SDataPacket _response; // 响应数据

        private bool _tx; // 成功发送请求
        private bool _rx; // 成功接收请求

        private Getter _getter;
        private Setter _setter;

        private bool _disposed;

        public bool Pooling { get; set; }

        private static FixCommPool _pool = new FixCommPool();

        static FixComm()
        {
        }

        public static FixComm New(string host, string port)
        {
            string key = Key(host, port);

            FixComm fixcomm = FixComm._pool.Get(key);

            if(fixcomm != null)
            {
                return fixcomm;
            }

            fixcomm = new FixComm();

            if (fixcomm.Link(host, port))
            {
                fixcomm.Pooling = true;

                return fixcomm;
            }

            fixcomm.Close();

            return null;
        }

        public static string Key(string host, string port)
        {
            return host + ":" + port;
        }

        public FixComm()
        {
            this._mode = Mode.None;
            this._direction = Direction.Unknown;

            this._request = new SDataPacket();
            this._request.msgHeader = new SMessageHeader();
            //this._request.msgHeader.sessionid = SERVICE_SYSTEM_TAG;
        }

        internal FixComm(SDataPacket dpIn, SDataPacket dpOut)
        {
            if(dpIn == null)
            {
                throw new ArgumentException("dpIn");
            }

            if (dpOut == null)
            {
                throw new ArgumentException("dpOut");
            }

            this._mode = Mode.None;
            this._direction = Direction.Unknown;

            this._request  = dpIn;
            this._tx = true;
            this._response = dpOut;
            this._rx = true;

            this._getter = new Getter(
                this._request.msgHeader.nServiceCode,
                this._request.packet,
                allowEmpty: true);
        }

        ~FixComm()
        {
            Dispose(false);
        }

        public void Dispose()
        {
            if(this.Pooling)
            {
                if(this._mode == Mode.Client && this._active)
                {
                    FixComm._pool.Add(this._key, this);
                }
            }
            else
            {
                Dispose(true);
                GC.SuppressFinalize(this);
            }
        }

        protected virtual void Dispose(bool disposing)
        {
            if(this._disposed)
            {
                return;
            }

            if (this._adapter != null)
            {
                this._adapter.deactivate();
            }

            if (this._communicator != null)
            {
                try
                {
                    this._communicator.destroy();
                }
                catch (Exception x)
                {
                    Trace.TraceError(x.ToString());
                }
            }

            this._disposed = true;
        }

        public void Close()
        {
            Dispose();
        }

        #region Server

        public bool Bind(string host, string port)
        {
            if (this._active)
            {
                return false;
            }

            this._mode = Mode.Server;

            this._key = Key(host, port);

            var sb = new StringBuilder();

            var dat = new Ice.InitializationData();

            dat.properties = Ice.Util.createProperties();

            dat.properties.setProperty("Request.Endpoints",
                string.Format("tcp -h {0} -p {1}", host, port));

            dat.properties.setProperty("Ice.ThreadPool.Server.SizeMax", (this._processor + 3).ToString());
            dat.properties.setProperty("Ice.ThreadPool.Server.SizeWarn", (this._processor + 2).ToString());
            dat.properties.setProperty("Ice.ThreadPool.Server.Size", this._processor.ToString());

            dat.properties.setProperty("Ice.MessageSizeMax", this._messageSizeMax.ToString());

            dat.properties.setProperty("Ice.MessageEncoding", this._messageEncoding);

            if(this._logging != 0)
            {
                Parse(dat, this._logging);
            }

            this._communicator = Ice.Util.initialize(dat);

            try
            {
                this._adapter = this._communicator.createObjectAdapter("Request");
            }
            catch (Ice.Exception x)
            {
                Trace.TraceError(x.ToString());

                throw new FixCommException(sb.ToString(), x);
            }

            if (null == this._adapter)
            {
                Trace.WriteLine("object adapter null");

                throw new FixCommException(sb.ToString());
            }

            try
            {
                this._impl = new RequestI();

                this._adapter.add(
                    this._impl,
                    Ice.Util.stringToIdentity("request"));

                this._adapter.activate();

            }
            catch (Exception x)
            {
                Trace.TraceError(x.ToString());

                throw new FixCommException(sb.ToString());
            }

            this._active = true;

            return true;
        }

        public bool Add(int service, ServiceHandler handler)
        {
            if(this._mode != Mode.Server)
            {
                Debug.Assert(false);
                return false;
            }

            if(this._impl == null)
            {
                Debug.Assert(false);
                return false;
            }

            this._impl.AddHandler(service, handler);

            return true;
        }

        public bool Serve()
        {
            ThrowUnlessValid();

            if (this._mode != Mode.Server)
            {
                throw new FixCommNotSupportedException();
            }

            this._communicator.waitForShutdown();

            return true;
        }

        public bool Stop()
        {
            ThrowUnlessValid();

            if (this._mode != Mode.Server)
            {
                throw new FixCommNotSupportedException();
            }

            if (this._communicator.isShutdown())
            {
                return true;
            }

            this._communicator.shutdown();

            return true;
        }

        public bool CreateAnswer()
        {
            ThrowUnlessValid();

            if (this._direction == Direction.Request)
            {
                throw new FixCommNotSupportedException();
            }

            this._direction = Direction.Response;

            Clear();

            return true;
        }

        public bool Write()
        {
            ThrowUnlessSettable();

            if(this._setter.Count < 1)
            {
                Debug.Assert(false);
                return false;
            }

            if(this._response == null)
            {
                Debug.Assert(false);
                return false;
            }

            if (this._setter.Current.Count < 1)
            {
                this._setter.Decrement();
            }

            if (this._setter.Count > 0)
            {
                this._response.packet = this._setter.ToArray();
            }

            return true;
        }

        #endregion

        #region Client

        public bool Link(string host, string port)
        {
            if(this._active)
            {
                return false;
            }

            this._mode = Mode.Client;

            this._key = Key(host, port);

            var sb = new StringBuilder();

            var dat = new Ice.InitializationData();

            dat.properties = Ice.Util.createProperties();

            dat.properties.setProperty("Request.Proxy",
                string.Format("request:tcp -h {0} -p {1}", host, port));

            dat.properties.setProperty("Ice.MessageSizeMax", this._messageSizeMax.ToString());

            dat.properties.setProperty("Ice.MessageEncoding", this._messageEncoding);

            dat.properties.setProperty("Ice.ConsoleListener", "0");
            if (this._logging != 0)
            {
                Parse(dat, this._logging);
            }

            this._communicator = Ice.Util.initialize(dat);

            Ice.ObjectPrx obj = null;

            try
            {
                obj = this._communicator.propertyToProxy("Request.Proxy");
            }
            catch (Ice.Exception x)
            {
                Trace.TraceError(x.ToString());

                throw new FixCommException(sb.ToString(), x);
            }

            if (null == obj)
            {
                Trace.WriteLine("object proxy null");

                throw new FixCommException(sb.ToString());
            }

            RequestPrx proxy = null;

            try
            {
                proxy = RequestPrxHelper.checkedCast(obj);
            }
            catch(Ice.Exception x)
            {
                if (x.InnerException != null)
                {
                    Trace.TraceError(x.InnerException.Message);

                    sb.Append(x.InnerException.Message);
                }
                else
                {
                    sb.Append(x.Message);
                }

                throw new FixCommException(sb.ToString());
            }

            if (null == proxy)
            {
                Trace.WriteLine("request proxy null");

                throw new FixCommException(sb.ToString());
            }

            proxy.ice_twoway().ice_secure(false).ice_timeout(this._timeout * 1000);

            this._proxy = proxy;

            this._active = true;

            if(!Login())
            {
                Trace.WriteLine("FixComm login failure");

                throw new FixCommException(sb.ToString());
            }

            return true;
        }

        public bool Connect()
        {
            return Login();
        }

        public bool CreateHead(short nFunc)
        {
            ThrowUnlessValid();

            if(this._direction == Direction.Response)
            {
                return false;
            }

            this._direction = Direction.Request;

            Clear();

            this._request.msgHeader.nServiceCode = nFunc;

            return true;
        }

        public bool More()
        {
            ThrowUnlessValid();

            if (this._tx)
            {
                if (this._rx)
                {
                    if(this._getter == null)
                    {
                        return false;
                    }

                    if(!this._getter.Valid)
                    {
                        Debug.Assert(false);

                        return false;
                    }

                    return this._getter.Next();
                }
                else
                {
                    Debug.Assert(false);

                    return false;
                }
            }
            else
            {
                if (!Send())
                {
                    return false;
                }

                if (!Receive())
                {
                    return false;
                }

                return true;
            }
        }

        #endregion

        #region Setter

        public void SetItem(int aFixCode, string aValue)
        {
            Set(aFixCode, aValue);
        }

        public void SetItem(int aFixCode, int aValue)
        {
            Set(aFixCode, aValue);
        }

        public void SetItem(int aFixCode, long aValue)
        {
            Set(aFixCode, aValue);
        }

        public void SetItem(int aFixCode, float aValue)
        {
            Set(aFixCode, aValue);
        }

        public void SetItem(int aFixCode, double aValue)
        {
            Set(aFixCode, aValue);
        }

        public void SetItem(int aFixCode, DateTime aValue)
        {
            Set(aFixCode, aValue);
        }

        public void SetItem(int aFixCode, byte[] aValue)
        {
            Set(aFixCode, aValue);
        }

        public void Set(int aFixCode, string aValue)
        {
            ThrowUnlessSettable();

            SFieldContent field;

            if (this._setter.Get(aFixCode, out field))
            {
                if (!this._allow_multiple_set)
                {
                    Debug.WriteLine(string.Format("Field {0}: Multiple Set", aFixCode.ToString()));

                    return;
                }

                field.fType = EFieldType.FTString;
                field.strValue = aValue;
            }
            else
            {
                field = new SFieldContent();

                field.fType = EFieldType.FTString;
                field.strValue = aValue;

                this._setter.Add(aFixCode, field);
            }
        }

        public void Set(int aFixCode, int aValue)
        {
            ThrowUnlessSettable();

            SFieldContent field;

            if (this._setter.Get(aFixCode, out field))
            {
                if (!this._allow_multiple_set)
                {
                    Debug.Assert(false);
                    return;
                }

                field.fType = EFieldType.FTInt;
                field.iValue = aValue;
            }
            else
            {
                field = new SFieldContent();

                field.fType = EFieldType.FTInt;
                field.iValue = aValue;

                this._setter.Add(aFixCode, field);
            }
        }

        public void Set(int aFixCode, long aValue)
        {
            Set(aFixCode, (int)aValue);
        }

        public void Set(int aFixCode, float aValue)
        {
            ThrowUnlessSettable();

            SFieldContent field;

            if (this._setter.Get(aFixCode, out field))
            {
                if (!this._allow_multiple_set)
                {
                    Debug.Assert(false);
                    return;
                }

                field.fType = EFieldType.FTFloat;
                field.fValue = aValue;
            }
            else
            {
                field = new SFieldContent();

                field.fType = EFieldType.FTFloat;
                field.fValue = aValue;

                this._setter.Add(aFixCode, field);
            }
        }

        public void Set(int aFixCode, double aValue)
        {
            Set(aFixCode, (float)aValue);
        }

        public void Set(int aFixCode, DateTime aValue)
        {
            ThrowUnlessSettable();

            SFieldContent field;

            string value = aValue.ToString(DateTimeHelper.DATETIME_FORMAT_FULL);

            if (this._setter.Get(aFixCode, out field))
            {
                if (!this._allow_multiple_set)
                {
                    Debug.Assert(false);
                    return;
                }

                field.fType = EFieldType.FTString;
                field.strValue = value;
            }
            else
            {
                field = new SFieldContent();

                field.fType = EFieldType.FTString;
                field.strValue = value;

                this._setter.Add(aFixCode, field);
            }
        }

        public void Set(int aFixCode, byte[] aValue)
        {
            ThrowUnlessSettable();

            SFieldContent field;

            if (this._setter.Get(aFixCode, out field))
            {
                if (!this._allow_multiple_set)
                {
                    Debug.Assert(false);
                    return;
                }

                field.fType = EFieldType.FTBytes;
                field.buf = aValue;
            }
            else
            {
                field = new SFieldContent();

                field.fType = EFieldType.FTBytes;
                field.buf = aValue;

                this._setter.Add(aFixCode, field);
            }
        }

        #endregion

        #region Getter

        public short GetFunc()
        {
            ThrowUnlessValid();

            return this._request.msgHeader.nServiceCode;
        }

        public int GetRet()
        {
            ThrowUnlessValid();

            return this._request.nRetCode;
        }

        public int GetCount()
        {
           if(! ThrowUnlessValid())
            {
                return 0;
            }

            if (this._getter == null)
            {
                return 0;
            }

            if (!this._getter.Valid)
            {
                return 0;
            }

            return this._getter.Count;
        }

        public bool Exist(int aFixCode)
        {
            ThrowUnlessGettable();

            return this._getter.Exist(aFixCode);
        }

        public IEnumerable<KeyValuePair<int, object>> GetItems()
        {
            if (!ThrowUnlessValid())
            {
                return new Dictionary<int,object>();
            }

            return this._getter.Current.Select(fs =>
                new KeyValuePair<int, object>(
                    fs.Key,
                    fs.Value.ToObject()
                )
            );
        }

        public string Get(int aFixCode)
        {
            if (!ThrowUnlessValid())
            {
                return "";
            }

            string ret = string.Empty;

            SFieldContent field;
            if (!this._getter.Get(aFixCode, out field))
            {
                return ret;
            }

            if (field == null)
            {
                Debug.Assert(false);
                return ret;
            }

            return field.ToString();
        }

        public object GetItem(int aFixCode)
        {
            if (!ThrowUnlessValid())
            {
                return null;
            }

            object ret = null;

            SFieldContent field;
            if (!this._getter.Get(aFixCode, out field))
            {
                //Debug.Assert(false);

                return ret;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            return field.ToObject();
        }

        public string GetString(int aFixCode)
        {
            if (!ThrowUnlessValid())
            {
                return "";
            }

            string ret = string.Empty;

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                //Debug.Assert(false);

                return ret;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            if (field.fType == EFieldType.FTString)
            {
                ret = field.strValue;
            }
            else
            {
                Debug.Assert(false);
            }

            return ret;
        }

        public bool GetString(int aFixCode, out string aValue)
        {
            if (!ThrowUnlessValid())
            {
                aValue = "";
                return false;
            }

            aValue = null;

            bool ret = false;

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                return false;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            if (field.fType != EFieldType.FTString)
            {
                return ret;
            }

            aValue = field.strValue;

            ret = true;

            return ret;
        }

        public int GetInt(int aFixCode)
        {
            if (!ThrowUnlessValid())
            {
                return 0;
            }

            int ret = 0;

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                //Debug.Assert(false);

                return ret;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            if(field.fType == EFieldType.FTInt)
            {
                ret = field.iValue;
            }
            else
            {
                Debug.Assert(false);
            }

            return ret;
        }

        public bool GetInt(int aFixCode, out int aValue)
        {
            if (!ThrowUnlessValid())
            {
                aValue = 0;
                return false;
            }

            bool ret = false;

            aValue = 0;

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                return ret;
            }

            if (field == null)
            {
                return ret;
            }

            if (field.fType != EFieldType.FTInt)
            {
                return ret;
            }

            aValue = field.iValue;

            ret = true;

            return ret;
        }

        public long GetLong(int aFixCode)
        {
            return GetInt(aFixCode);
        }

        public bool GetLong(int aFixCode, out long aValue)
        {
            int val;

            bool ret = GetInt(aFixCode, out val);

            aValue = val;

            return ret;
        }

        public float GetFloat(int aFixCode)
        {
            if (!ThrowUnlessValid())
            {
                return 0;
            }

            float ret = 0;

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                //Debug.Assert(false);

                return ret;
            }

            Debug.Assert(field != null);

            if(field == null)
            {
                return ret;
            }

            if (field.fType == EFieldType.FTFloat)
            {
                ret = field.fValue;
            }
            else
            {
              //  Debug.Assert(false);
            }

            return ret;
        }

        public bool GetFloat(int aFixCode, out float aValue)
        {
            if (!ThrowUnlessValid())
            {
                aValue = 0;
                return false;
            }

            bool ret = false;

            aValue = 0;

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                return ret;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            if (field.fType != EFieldType.FTFloat)
            {
                return ret;
            }

            aValue = field.fValue;

            ret = true;

            return ret;
        }

        public double GetDouble(int aFixCode)
        {
            return GetFloat(aFixCode);
        }

        public bool GetDouble(int aFixCode, out double aValue)
        {
            float val;

            bool ret = GetFloat(aFixCode, out val);

            aValue = val;

            return ret;
        }

        public DateTime GetTime(int aFixCode)
        {
            if (!ThrowUnlessValid())
            {
                return DateTime.Parse("1980-01-01");
            }

            DateTime ret = DateTimeHelper.Default;

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                //Debug.Assert(false);

                return ret;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            if (field.fType != EFieldType.FTString)
            {
                Debug.Assert(false);

                return ret;
            }

            return field.strValue.ToDateTime();
        }

        public bool GetTime(int aFixCode, out DateTime aValue)
        {
            if (!ThrowUnlessValid())
            {
                aValue = DateTime.Parse("1980-01-01");
                return false;
            }

            bool ret = false;

            aValue = DateTimeHelper.Default;

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                return ret;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            if (field.fType != EFieldType.FTString)
            {
                return ret;
            }

            aValue = field.strValue.ToDateTime();

            if(aValue == DateTimeHelper.Default)
            {
                return false;
            }

            return true;
        }

        public byte[] GetBuffer(int aFixCode)
        {
            if (!ThrowUnlessValid())
            {
                return new byte[0];
            }

            byte[] ret = new byte[0];

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                //Debug.Assert(false);

                return ret;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            if (field.fType == EFieldType.FTBytes)
            {
                if(null == field.buf)
                {
                    Debug.Assert(false);

                    return ret;
                }

                ret = field.buf;
            }
            else
            {
                Debug.Assert(false);
            }

            return ret;
        }

        public bool GetBuffer(int aFixCode, out byte[] aValue)
        {
            if (!ThrowUnlessValid())
            {
                aValue = new byte[0];
                return false;
            }

            bool ret = false;

            aValue = new byte[0];

            SFieldContent field;

            if (!this._getter.Get(aFixCode, out field))
            {
                return ret;
            }

            Debug.Assert(field != null);

            if (field == null)
            {
                return ret;
            }

            if (field.fType != EFieldType.FTBytes)
            {
                return ret;
            }

            if (null == field.buf)
            {
                Debug.Assert(false);

                return ret;
            }

            aValue = field.buf;

            ret = true;

            return ret;
        }

        #endregion

        public bool CreateNext()
        {
            ThrowUnlessValid();

            if(this._setter == null)
            {
                this._setter = new Setter();
            }

            this._setter.Increment();

            return true;
        }

        private static void Parse(Ice.InitializationData data, int logging)
        {
            Func<int, Message, bool> __isSet = (int request, Message type) =>
            {
                int setting = 1 << (int)type;
                return (request & setting) != 0;
            };

            if(__isSet(logging, Message.TraceLocator))
            {
                /*
                 * 0 No locator trace (default).
                 * 1 Trace Ice locator and locator registry requests.
                 * 2 Like 1, but also trace the removal of endpoints from the cache.
                 */
                data.properties.setProperty("Ice.Trace.Locator", "2");
            }

            if (__isSet(logging, Message.TraceNetwork))
            {
                /*
                 * 0 No network trace (default).
                 * 1 Trace successful connection establishment and closure.
                 * 2 Like 1, but also trace attempts to bind, connect, and disconnect sockets.
                 * 3 Like 2, but also trace data transfer, the published endpoints for an object adapter, and the current list of local addresses for an
                 *   endpoint that uses the wildcard address.
                 */
                data.properties.setProperty("Ice.Trace.Network", "3");
            }

            if (__isSet(logging, Message.TraceProtocol))
            {
                /*
                 * 0 No protocol trace (default).
                 * 1 Trace Ice protocol messages.
                 */
                data.properties.setProperty("Ice.Trace.Protocol", "1");
            }


            if (__isSet(logging, Message.TraceRetry))
            {
                /*
                 * 0 No request retry trace (default).
                 * 1 Trace Ice operation call retries.
                 * 2 Also trace Ice endpoint usage.
                 */
                data.properties.setProperty("Ice.Trace.Retry", "2");
            }

            if (__isSet(logging, Message.TraceSlicing))
            {
                /*
                 * 0 No trace of slicing activity (default).
                 * 1 Trace all exception and class types that are unknown to the receiver and therefore sliced.
                 */
                data.properties.setProperty("Ice.Trace.Slicing", "1");
            }

            if (__isSet(logging, Message.TraceThreadPool))
            {
                /*
                 * 0 No trace of thread pool activity (default).
                 * 1 Trace the creation, growing, and shrinking of thread pools.
                 */
                data.properties.setProperty("Ice.Trace.ThreadPool", "1");
            }

            if (__isSet(logging, Message.WarnAMICallback))
            {
                /*
                 * If num is set to a value larger than zero, warnings are printed if an AMI callback raises an exception.
                 * The default value is 1.
                 */
                data.properties.setProperty("Ice.Warn.AMICallback", "1");
            }

            if (__isSet(logging, Message.WarnConnections))
            {
                /*
                 * If num is set to a value larger than zero, Ice applications print warning messages for certain exceptional conditions in connections.
                 * The default value is 0.
                 */
                data.properties.setProperty("Ice.Warn.Connections", "1");
            }

            if (__isSet(logging, Message.WarnDispatch))
            {
                /*
                 * 0 No warnings.
                 * 1 Print warnings for unexpected Ice::LocalException, Ice::UserException, C++ exceptions, and Java run-time exceptions
                 *   (default).
                 * 2 Like 1, but also issue warnings for Ice::ObjectNotExistException, Ice::FacetNotExistException, and
                 *   Ice::OperationNotExistException.
                 */
                data.properties.setProperty("Ice.Warn.Dispatch", "2");
            }

            if (__isSet(logging, Message.WarnEndpoints))
            {
                data.properties.setProperty("Ice.Warn.Endpoints", "1");
            }

            if (__isSet(logging, Message.WarnUnknownProperties))
            {
                data.properties.setProperty("Ice.Warn.UnknownProperties", "1");
            }

            if (__isSet(logging, Message.WarnUnusedProperties))
            {
                data.properties.setProperty("Ice.Warn.UnusedProperties", "1");
            }
        }

        private bool Login()
        {
#if true
            Clear();

            this._request.msgHeader.nServiceCode = SERVICE_SYSTEM_LOGIN;
            this._request.msgHeader.sessionid    = SERVICE_SYSTEM_TAG;

            if (!Send())
            {
                return false;
            }

            if (this._response == null)
            {
                return false;
            }

            if (this._response.nRetCode != 1)
            {
                return false;
            }

            return true;
#else
            try
            {
                this._proxy.sayHello(0);
            }
            catch (System.Exception x)
            {
                Trace.TraceError(x.ToString());

                return false;
            }

            return true;
#endif
        }

        private bool Send()
        {
            if (this._setter.Count > 0)
            {
                this._request.packet = this._setter.ToArray();
            }

            try
            {
                this._response = this._proxy.RequestData(this._request);
            }
            catch (Ice.ConnectionLostException x)
            {
                throw new FixCommException("请求失败，连接关闭", x);
            }
            catch (System.Exception x)
            {
                Trace.TraceError(x.ToString());

                throw new FixCommException("请求失败，" + x.Message, x);
            }

            this._tx = true;

            return true;
        }

        private bool Receive()
        {
            if(this._tx != true)
            {
                return false;
            }

            if(null == this._response)
            {
                return false;
            }

            this._rx = true;

            this._getter = new Getter(
                this._request.msgHeader.nServiceCode,
                this._response.packet,
                allowEmpty: false);

            return this._getter.Valid;
        }

        private void Clear()
        {
            if(this._mode != Mode.None)
            {
                this._request.packet = null;
                this._response = null;
            }

            this._tx = false;
            this._rx = false;

            if (this._setter == null)
            {
                this._setter = new Setter();
            }
            else
            {
                this._setter.Reset();
            }

            this._getter = null;
        }

        private bool ThrowUnlessValid()
        {
            if (this._disposed)
            {
               return false;
            }

            if(this._mode != Mode.None)
            {
                if (!this._active)
                {
                    return false;
                }
            }

            return true;
        }

        private bool ThrowUnlessGettable()
        {
            ThrowUnlessValid();

            if(this._getter == null)
            {
                //throw new FixCommException("数据未准备好");
                return false;
            }

            if (!this._getter.Valid)
            {
                // throw new FixCommException("数据未准备好");
                return false;
            }

            return true;
        }

        private bool ThrowUnlessSettable()
        {
            ThrowUnlessValid();

            if (this._setter == null)
            {
                throw new FixCommException("Call CreateHead/CreateAnswer beforehand");
            }

            return true;
        }
    }

    sealed class RequestI : RequestDisp_
    {
        public override Aco.SDataPacket RequestData(Aco.SDataPacket dp, Ice.Current current__)
        {
            int service = dp.msgHeader.nServiceCode;

            if(service == FixComm.SERVICE_SYSTEM_LOGIN)
            {
                if (dp.msgHeader.sessionid == FixComm.SERVICE_SYSTEM_TAG)
                {
                    dp.nRetCode = 1;
                }
                else
                {
                    dp.nRetCode = -1;
                }

                return dp;
            }

            FixComm.ServiceHandler h;
            if (!this.__services.TryGetValue(service, out h))
            {
                if (!this.__services.TryGetValue(0, out h))
                {
                    Trace.TraceWarning("Service {0} NOT supported.", service);

                    return null;
                }
            }

            Aco.SDataPacket rp = Aco.SDataPacket.Empty;

            rp.msgHeader.nServiceCode = dp.msgHeader.nServiceCode;
            //rp.msgHeader.sessionid  = dp.msgHeader.sessionid;

            FixComm fixcomm = new FixComm(dp, rp);

            try
            {
                rp.nRetCode = h(fixcomm);
            }
            catch (Exception x)
            {
                Trace.TraceError(x.ToString());

                return null;
            }

            return rp;
        }

        public override void sayHello(int delay, Ice.Current current__)
        {
            Trace.WriteLine($"FixComm: sayHello({delay})");
        }

        public override void shutdown(Ice.Current current__)
        {
            Trace.WriteLine("FixComm: shutdown");
        }

        public void AddHandler(int service, FixComm.ServiceHandler handler)
        {
            FixComm.ServiceHandler h;
            if(this.__services.TryGetValue(service, out h))
            {
                h += handler;
            }
            else
            {
                this.__services[service] = handler;
            }
        }

        public void RemoveHandler(int service, FixComm.ServiceHandler handler)
        {
            FixComm.ServiceHandler h;
            if (this.__services.TryGetValue(service, out h))
            {
                h -= handler;
            }
            else
            {
                Debug.Assert(false);
            }
        }

        private Dictionary<int, FixComm.ServiceHandler> __services = new Dictionary<int, FixComm.ServiceHandler>();
    }

    public class FixCommException : System.Exception
    {
        public FixCommException()
        {

        }

        public FixCommException(string message)
            : base(message)
        {

        }

        public FixCommException(string message, System.Exception exception)
            : base(message, exception)
        {

        }
    }

    public class FixCommNotSupportedException : FixCommException
    {
        public FixCommNotSupportedException()
        {

        }

        public FixCommNotSupportedException(string message)
            : base(message)
        {

        }

        public FixCommNotSupportedException(string message, Exception exception)
            : base(message, exception)
        {

        }
    }

    public class FixCommAlreadyActiveException : FixCommException
    {
        public FixCommAlreadyActiveException()
        {

        }

        public FixCommAlreadyActiveException(string message)
            : base(message)
        {

        }

        public FixCommAlreadyActiveException(string message, Exception exception)
            : base(message, exception)
        {

        }
    }

    sealed class FixCommPool
    {
        private object _SyncRoot = new object();

        class FixCommCollection
        {
            public FixCommCollection()
            {
                this._collection = new Stack<FixComm>();
            }

            public FixCommCollection(int capacity)
            {
                this._collection = new Stack<FixComm>(capacity);
            }

            internal void Add(FixComm fixcomm)
            {
                this._collection.Push(fixcomm);
            }

            internal FixComm Take()
            {
                if(this._collection.Count > 0)
                {
                    return this._collection.Pop();
                }

                return null;
            }

            private Stack<FixComm> _collection;
        }

        private Dictionary<string, FixCommCollection> _pool;

        public FixCommPool()
        {
            this._pool = new Dictionary<string, FixCommCollection>();
        }

        internal void Add(string key, FixComm fixcomm)
        {
            if(fixcomm == null)
            {
                return;
            }

            lock(this._SyncRoot)
            {
                FixCommCollection collection = null;

                if(this._pool.TryGetValue(key, out collection))
                {
                    collection.Add(fixcomm);
                }
                else
                {
                    collection = new FixCommCollection(4);

                    collection.Add(fixcomm);

                    this._pool[key] = collection;
                }
            }
        }

        internal FixComm Get(string key)
        {
            lock (this._SyncRoot)
            {
                FixCommCollection fixcommList = null;

                if (this._pool.TryGetValue(key, out fixcommList))
                {
                    return fixcommList.Take();
                }
                else
                {
                    return null;
                }
            }
        }
    }
}
