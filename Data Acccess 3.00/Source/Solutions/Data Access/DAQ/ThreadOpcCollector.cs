using System;
using System.Collections.Generic;
using System.Text;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;

using System.Text;
using System.Windows.Forms;
using Opc;
using OpcCom;
using Opc.Da;
using System.Diagnostics;
using System.Threading;
using SinaWeiBo4wm.UiThread;
using System.Security.Principal;

using System.Data.Odbc;

namespace DAQ
{
    public delegate void StatusChangedEventHandler(object sender, CollectorStatusEventArgs e);

    public delegate void DataChangedEventHandler(object sender, CollectorDataEventArgs e);

    public class CollectorStatusEventArgs : EventArgs
    {
        public CollectorStatusEventArgs(COLLECTOR_STATUS aEnumStatus)
        {
            this.m_EnumStatus = aEnumStatus;

        }

        protected COLLECTOR_STATUS m_EnumStatus = COLLECTOR_STATUS.STOPPED;
        public DAQ.COLLECTOR_STATUS Status
        {
            get { return m_EnumStatus; }
        }
    }

    public class CollectorDataEventArgs : EventArgs
    {
        public CollectorDataEventArgs(ServerSetting aoSetting)
        {
            this.m_oSetting = aoSetting;

        }

        protected ServerSetting m_oSetting = null;
        public DAQ.ServerSetting Setting
        {
            get { return m_oSetting; }
        }
    }

    public class ConstantValueHolder
    {
        public static string SPLITER = "{~}|{~}";
    }

    public class ThreadOpcCollector
    {

        public ThreadOpcCollector()
        {

        }

        public event StatusChangedEventHandler OnCollectorStatusChanged;
        public event DataChangedEventHandler OnDataChanged;

        protected Opc.Da.Server m_pTargetServer = null;
        protected Opc.Da.Subscription m_pSubscription = null;


        ServerSetting m_oServerSetting = new ServerSetting();


        COLLECTOR_STATUS m_nStatus = COLLECTOR_STATUS.STOPPED;

        public DAQ.COLLECTOR_STATUS Status
        {
            get
            {
                return m_nStatus;
            }

        }

        protected DAQ.COLLECTOR_STATUS _Status
        {
            set
            {
                m_nStatus = value;

                CollectorStatusEventArgs e = new CollectorStatusEventArgs(m_nStatus);

                this.FireStatusChanged(e);
            }
        }

        protected virtual void FireDataChanged(CollectorDataEventArgs e)
        {
            if (OnDataChanged != null)
            {
                OnDataChanged(this, e);
            }
        }

        protected virtual void FireStatusChanged(CollectorStatusEventArgs e)
        {
            if (OnCollectorStatusChanged != null)
            {
                OnCollectorStatusChanged(this, e);
            }
        }

        public DAQ.ServerSetting ServerSetting
        {
            get { return m_oServerSetting; }
            set { m_oServerSetting = value; }
        }


        private void DisconnectFromServer()
        {
            try
            {
                if (this.m_pSubscription != null)
                {
                    try
                    {
                        if (this.m_pTargetServer != null)
                        {
                            this.m_pTargetServer.CancelSubscription(this.m_pSubscription);
                        }
                    }
                    catch (System.Exception ex)
                    {
                        ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                    }
                    this.m_pSubscription.Dispose();
                    this.m_pSubscription = null;
                }

            }
            catch (System.Exception ex)
            {
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
            finally
            {
                this.m_pSubscription = null;
            }


            try
            {
                if (this.m_pTargetServer != null)
                {
                    this.m_pTargetServer.Disconnect();
                    this.m_pTargetServer.Dispose();
                }
            }
            catch (System.Exception ex)
            {
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
            finally
            {
                this.m_pTargetServer = null;
            }
        }

        private Boolean ConnectOpcServer()
        {
            Opc.IDiscovery m_discovery = null;
            Boolean lbResult = false;
            try
            {
                m_discovery = new OpcCom.ServerEnumerator();

                Opc.Server[] servers = m_discovery.GetAvailableServers(
                    Specification.COM_DA_20,
                    this.m_oServerSetting.Machine,
                    null);

                foreach (Opc.Da.Server server in servers)
                {

                    if (server.Name.CompareTo(this.m_oServerSetting.ProgID) == 0)
                    {
                        m_pTargetServer = server;
                        break;
                    }

                    if (server.Name.CompareTo(this.m_oServerSetting.Machine + "." + this.m_oServerSetting.ProgID) == 0)
                    {
                        m_pTargetServer = server;
                    }
                }


                if (m_pTargetServer == null)
                {
                    this._Status = COLLECTOR_STATUS.STOPPING;
                    return false;
                }

                try
                {
                    m_pTargetServer.Connect();
                    lbResult = true;
                }
                catch (System.Exception ex)
                {
                    try
                    {
                        this.m_pTargetServer.Dispose();

                    }
                    catch (System.Exception e2)
                    {
                        Debug.Assert(false);
                        Debug.WriteLine(e2.Message);
                        ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                    }
                    this.m_pTargetServer = null;
                    Debug.Assert(false);
                    Debug.WriteLine(ex.Message);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                }

                return lbResult;

            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.Message);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                return lbResult;
            }
            finally
            {
                try
                {
                    m_discovery.Dispose();
                }
                catch (System.Exception ex)
                {
                    Debug.Assert(false);
                    Debug.WriteLine(ex.Message);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                }
            }
        }

        private Boolean AddItems()
        {
            Boolean lbResult = false;
            //1.Change ItemSetting to Item
            Item[] items = new Item[this.m_oServerSetting.TotalItems.Count];//定义数据项，即item

            for (int i = 0; i < this.m_oServerSetting.TotalItems.Count; i++)
            {
                ItemSetting lpItemSetting = this.m_oServerSetting.TotalItems[i];
                try
                {
                    items[i] = new Item();//创建一个项Item对象。
                    items[i].ClientHandle = i;//客户端给该数据项分配的句柄。
                    items[i].ItemPath = null; //该数据项在服务器中的路径。
                    items[i].ItemName = lpItemSetting.TagName; //该数据项在服务器中的名字。
                }
                catch (System.Exception ex)
                {
                    if (lpItemSetting != null)
                    {
                        lpItemSetting.OpcStatus = 0;
                    }
                }
            }//for (int i = 0; i < this.m_oServerSetting.TotalItems.Count;i++ )

            //2.subscription the items
            try
            {
                Opc.Da.SubscriptionState state = null;
                state = new Opc.Da.SubscriptionState();                     //组（订阅者）状态，相当于OPC规范中组的参数
                state.Name = Guid.NewGuid().ToString();                     //组名
                state.ServerHandle = null;                                  //服务器给该组分配的句柄。
                state.ClientHandle = Guid.NewGuid().ToString();             //客户端给该组分配的句柄。
                state.Active = true;                                        //激活该组。
                state.UpdateRate = this.m_oServerSetting.TimeInterval;      //刷新频率为1秒。
                state.Deadband = 0;                                         // 死区值，设为0时，服务器端该组内任何数据变化都通知组。
                state.Locale = null;                                        //不设置地区值。
                //添加组

                m_pSubscription = (Opc.Da.Subscription)m_pTargetServer.CreateSubscription(state);//创建组

                //添加Item
                m_pSubscription.AddItems(items);

                lbResult = true;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                if (null != m_pSubscription)
                {
                    try
                    {
                        m_pSubscription.Dispose();
                        this.m_pSubscription = null;
                    }
                    catch (System.Exception e2)
                    {
                        Debug.Assert(false);
                        Debug.WriteLine(e2.ToString());
                        ThreadUiController.log(e2.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                    }
                }
            }// catch (System.Exception ex)

            return lbResult;
        }

        private Boolean Read()
        {
            try
            {
                ItemValueResult[] values = this.m_pSubscription.Read(this.m_pSubscription.Items);


                int lnDataIndex = 0;
                int lnItemIndex = 0;
                foreach (ItemValueResult value in values)
                {
                    lnDataIndex = (int)this.m_pSubscription.Items[lnItemIndex].ClientHandle;
                    Debug.Assert(value.ItemName == this.ServerSetting.TotalItems[lnDataIndex].TagName);
                    this.ServerSetting.TotalItems[lnDataIndex].Value = value.Value;
                    double ldbl = 0;
                    if (double.TryParse(value.Value.ToString(), out ldbl))
                    {
                        this.ServerSetting.TotalItems[lnDataIndex].Value = ldbl * this.ServerSetting.TotalItems[lnDataIndex].K + this.ServerSetting.TotalItems[lnDataIndex].B;
                    }
                    this.ServerSetting.TotalItems[lnDataIndex].Quality = value.Quality;
                    this.ServerSetting.TotalItems[lnDataIndex].UpdateTime = value.Timestamp;
                    this.ServerSetting.TotalItems[lnDataIndex].UpdateCount++;
                    // lnDataIndex++;
                    lnItemIndex++;
                }

                return lnItemIndex > 0;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log("ThreadOpcCollector::Read() Failed:" + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            return false;
        }

        private void CollectorThreadStart()
        {
            while (!this.ShouldStop)
            {
                //0.disconnected from previous server
                this.DisconnectFromServer();

                //1.connect to server
                if (!this.ConnectOpcServer())
                {
                    this._Status = COLLECTOR_STATUS.STOPPED;

                    Thread.Sleep(10000);

                    continue;
                }

                //2.Add Item
                if (!this.AddItems())
                {
                    this._Status = COLLECTOR_STATUS.STOPPED;

                    Thread.Sleep(10000);

                    continue;
                }

                //3.read Data,and fire CallBack
                while (!this.ShouldStop)
                {
                    int lnTimeStart = System.Environment.TickCount;
                    Boolean lbShouldRestart = false;
                    if (this.Read())
                    {
                        CollectorDataEventArgs e = new CollectorDataEventArgs(this.ServerSetting);
                        this.FireDataChanged(e);
                    }
                    else
                    {
                        lbShouldRestart = true;
                    }

                    //this._Status = COLLECTOR_STATUS.STARTED;
                    int lnTimeStop = System.Environment.TickCount;
                    int lnTimeElapsed = lnTimeStop - lnTimeStart;

                    int lnTimeToSleep = this.m_oServerSetting.TimeInterval - lnTimeElapsed;

                    if (lnTimeToSleep < 0)
                    {
                        lnTimeToSleep = 0;
                    }
                    this._Status = COLLECTOR_STATUS.STARTED;
                    Thread.Sleep(lnTimeToSleep);
                    if (lbShouldRestart)
                    {
                        //sth wrong happened reconnect to opc server

                        break;
                    }
                }//while (!this.ShouldStop)


            }// while (!this.ShouldStop)

        }


        Boolean m_bShouldStop = false;
        public System.Boolean ShouldStop
        {
            get { return m_bShouldStop; }
            set { m_bShouldStop = value; }
        }
        public void Start()
        {
            if (this.Status != COLLECTOR_STATUS.STOPPED
                || this.m_pServerThread != null)
            {
                this.Stop();
            }

            this._Status = COLLECTOR_STATUS.STARTING;

            try
            {
                this.m_pServerThread = new Thread(new ThreadStart(CollectorThreadStart));
                this.m_pServerThread.IsBackground = true;
                this.m_pServerThread.Start();

            }
            catch (System.Exception ex)
            {
                this.m_pServerThread = null;
                this._Status = COLLECTOR_STATUS.STOPPED;

                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
        }
        public void Stop()
        {
            try
            {
                this._Status = COLLECTOR_STATUS.STOPPING;

                this.ShouldStop = true;

                if (this.m_pServerThread != null)
                {
                    this.m_pServerThread.Join(2000);
                    this.m_pServerThread.Abort();

                    try
                    {
                        if (this.m_pSubscription != null)
                        {
                            this.m_pSubscription.Dispose();
                            this.m_pSubscription = null;
                        }
                    }
                    catch (System.Exception ex)
                    {
                        Debug.Assert(false);
                        Debug.WriteLine(ex.ToString());
                        ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                    }

                    if (this.m_pTargetServer != null)
                    {
                        try
                        {
                            m_pTargetServer.Disconnect();
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }

                        try
                        {
                            m_pTargetServer.Dispose();
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }

                        try
                        {
                            m_pTargetServer = null;
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }
                    }
                }

                this._Status = COLLECTOR_STATUS.STOPPED;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
        }

        private Thread m_pServerThread = null;
    }

    public class ThreadBHCollector
    {
        public ThreadBHCollector()
        {
            //only online supported
            // m_pFixComm.SetCommType(1);
        }

        public event StatusChangedEventHandler OnCollectorStatusChanged;
        public event DataChangedEventHandler OnDataChanged;

        protected Opc.Da.Server m_pTargetServer = null;
        protected Opc.Da.Subscription m_pSubscription = null;


        ServerSetting m_oServerSetting = new ServerSetting();


        COLLECTOR_STATUS m_nStatus = COLLECTOR_STATUS.STOPPED;

        public DAQ.COLLECTOR_STATUS Status
        {
            get
            {
                return m_nStatus;
            }

        }

        protected DAQ.COLLECTOR_STATUS _Status
        {
            set
            {
                m_nStatus = value;

                CollectorStatusEventArgs e = new CollectorStatusEventArgs(m_nStatus);

                this.FireStatusChanged(e);
            }
        }

        protected virtual void FireDataChanged(CollectorDataEventArgs e)
        {
            if (OnDataChanged != null)
            {
                if (!this.m_bShouldStop)
                {
                    OnDataChanged(this, e);
                }
            }
        }

        protected virtual void FireStatusChanged(CollectorStatusEventArgs e)
        {
            if (OnCollectorStatusChanged != null)
            {
                OnCollectorStatusChanged(this, e);
            }
        }

        public DAQ.ServerSetting ServerSetting
        {
            get { return m_oServerSetting; }
            set { m_oServerSetting = value; }
        }

        CBHFixComLib.ICBHFixComImp m_pFixComm = null;

        private Boolean ConnectBHServer()
        {
            if (null == this.m_pFixComm)
            {
                this.m_pFixComm = new CBHFixComLib.CBHFixComImp();
                this.m_pFixComm.SetCommType(1);
            }

            String lstrConnstr = string.Format("{0},{1}/TCP",
                                                this.m_oServerSetting.ServerIp,
                                                this.m_oServerSetting.ServerPort + "");
            String lstrDept = "";

            if (this.m_pFixComm.Link(ref lstrConnstr, ref lstrDept) > 0)
            {
                return true;
            }

            return false;
        }

        private Boolean ConnectOpcServer()
        {
            Opc.IDiscovery m_discovery = null;
            Boolean lbResult = false;
            try
            {
                m_discovery = new OpcCom.ServerEnumerator();

                Opc.Server[] servers = m_discovery.GetAvailableServers(
                    Specification.COM_DA_20,
                    this.m_oServerSetting.Machine,
                    null);

                foreach (Opc.Da.Server server in servers)
                {

                    if (server.Name.CompareTo(this.m_oServerSetting.ProgID) == 0)
                    {
                        m_pTargetServer = server;
                        break;
                    }
                }


                if (m_pTargetServer == null)
                {
                    this._Status = COLLECTOR_STATUS.STOPPING;
                    return false;
                }

                try
                {
                    m_pTargetServer.Connect();
                    lbResult = true;
                }
                catch (System.Exception ex)
                {
                    try
                    {
                        this.m_pTargetServer.Dispose();

                    }
                    catch (System.Exception e2)
                    {
                        Debug.Assert(false);
                        Debug.WriteLine(e2.Message);
                        ThreadUiController.log(e2.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                    }
                    this.m_pTargetServer = null;
                    Debug.Assert(false);
                    Debug.WriteLine(ex.Message);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                }

                if (!this.m_bShouldStop)
                {
                    this.OpcServerStarted = true;
                    if (this.m_bBHServerStarted)
                    {
                        this._Status = COLLECTOR_STATUS.STARTED;
                    }
                }

                return lbResult;

            }
            catch (System.Exception ex)
            {
                return lbResult;
            }
            finally
            {
                try
                {
                    m_discovery.Dispose();
                }
                catch (System.Exception ex)
                {
                    Debug.Assert(false);
                    Debug.WriteLine(ex.Message);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                }
            }
        }

        private Boolean AddItems()
        {
            Boolean lbResult = false;
            //1.Change ItemSetting to Item
            Item[] items = new Item[this.m_oServerSetting.TotalItems.Count];//定义数据项，即item

            for (int i = 0; i < this.m_oServerSetting.TotalItems.Count; i++)
            {
                ItemSetting lpItemSetting = this.m_oServerSetting.TotalItems[i];
                try
                {
                    items[i] = new Item();//创建一个项Item对象。
                    items[i].ClientHandle = i;//客户端给该数据项分配的句柄。
                    items[i].ItemPath = null; //该数据项在服务器中的路径。
                    items[i].ItemName = lpItemSetting.TagName; //该数据项在服务器中的名字。
                }
                catch (System.Exception ex)
                {
                    if (lpItemSetting != null)
                    {
                        lpItemSetting.OpcStatus = qualityBits.bad;
                    }
                }
            }//for (int i = 0; i < this.m_oServerSetting.TotalItems.Count;i++ )

            //2.subscription the items
            try
            {
                Opc.Da.SubscriptionState state = null;
                state = new Opc.Da.SubscriptionState();                     //组（订阅者）状态，相当于OPC规范中组的参数
                state.Name = "test";                                        //组名
                state.ServerHandle = null;                                  //服务器给该组分配的句柄。
                state.ClientHandle = Guid.NewGuid().ToString();             //客户端给该组分配的句柄。
                state.Active = true;                                        //激活该组。
                state.UpdateRate = this.m_oServerSetting.TimeInterval;      //刷新频率为1秒。
                state.Deadband = 0;                                         // 死区值，设为0时，服务器端该组内任何数据变化都通知组。
                state.Locale = null;                                        //不设置地区值。
                //添加组

                m_pSubscription = (Opc.Da.Subscription)m_pTargetServer.CreateSubscription(state);//创建组

                //添加Item
                m_pSubscription.AddItems(items);

                lbResult = true;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                if (null != m_pSubscription)
                {
                    try
                    {
                        m_pSubscription.Dispose();
                    }
                    catch (System.Exception e2)
                    {
                        Debug.Assert(false);
                        Debug.WriteLine(e2.ToString());
                        ThreadUiController.log(e2.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                    }
                }
            }// catch (System.Exception ex)

            return lbResult;
        }

        private Boolean ReadOPC()
        {
            try
            {
                ItemValueResult[] values = this.m_pSubscription.Read(this.m_pSubscription.Items);

                int lnDataIndex = 0;

                foreach (ItemValueResult value in values)
                {
                    Debug.Assert(value.ItemName == this.ServerSetting.TotalItems[lnDataIndex].TagName);

                    this.ServerSetting.TotalItems[lnDataIndex].Value = value.Value;
                    this.ServerSetting.TotalItems[lnDataIndex].Quality = value.Quality;
                    this.ServerSetting.TotalItems[lnDataIndex].UpdateTime = value.Timestamp;
                    this.ServerSetting.TotalItems[lnDataIndex].UpdateCount++;
                    String lstrData = String.Format("同步读：ITEM:{0},value:{1},quality:{2}", value.ItemName, value.Value, value.Quality);
                    Console.WriteLine(lstrData);
                    lnDataIndex++;
                }

                return true;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }


            return false;
        }


        private Boolean m_bOpcServerStarted = false;
        public System.Boolean OpcServerStarted
        {
            get { return m_bOpcServerStarted; }
            set { m_bOpcServerStarted = value; }
        }
        private Boolean m_bBHServerStarted = false;
        public System.Boolean BHServerStarted
        {
            get { return m_bBHServerStarted; }
            set { m_bBHServerStarted = value; }
        }

        private void ReadBH()
        {
            try
            {
                Boolean lbShouldDoRead = true;
                int lnTictLimit = 2000;
                int lnTictCount = 0;
                int lnTictLast = 0;
                while (!this.ShouldStop)
                {
                    if (lbShouldDoRead)
                    {
                        lnTictLast = System.Environment.TickCount;
                        String lstrkey = "";
                        SortedDictionary<string, SortedDictionary<string, List<int>>> loChanns
                            = new SortedDictionary<string, SortedDictionary<string, List<int>>>();
                        for (int i = 0; i < ServerSetting.TotalItems.Count; i++)
                        {
                            lstrkey = ServerSetting.TotalItems[i].Company
                                        + ConstantValueHolder.SPLITER + ServerSetting.TotalItems[i].Factory
                                        + ConstantValueHolder.SPLITER + ServerSetting.TotalItems[i].Plant;
                            if (!loChanns.ContainsKey(lstrkey))
                            {
                                SortedDictionary<string, List<int>> loTemp
                                     = new SortedDictionary<string, List<int>>();
                                loChanns.Add(lstrkey, loTemp);
                            }

                            if (!loChanns[lstrkey].ContainsKey(ServerSetting.TotalItems[i].RemoteTageName))
                            {
                                loChanns[lstrkey].Add(ServerSetting.TotalItems[i].RemoteTageName, new List<int>());
                            }
                            loChanns[lstrkey][ServerSetting.TotalItems[i].RemoteTageName].Add(i);

                        }
                        Boolean lbConnected = false;
                        try
                        {
                            lbConnected = this.ConnectBHServer();
                        }
                        catch (System.Exception ex)
                        {
                            ThreadUiController.log("ConnectBHServer Failed: " + ex.Message, ThreadUiController.LOG_LEVEL.FATAL);
                            Debug.Assert(false);
                        }

                        if (lbConnected)
                        {
                            try
                            {
                                foreach (KeyValuePair<string, SortedDictionary<string, List<int>>> lpValue in loChanns)
                                {
                                    this.m_pFixComm.CreateHead(20026);
                                    string[] lpKeys = lpValue.Key.Split(ConstantValueHolder.SPLITER.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                                    String lstrCompany = (lpKeys[0]);
                                    String lstrFactory = (lpKeys[1]);
                                    String lstrPlant = (lpKeys[2]);

                                    this.m_pFixComm.SetItemString(15004, ref lstrCompany);
                                    this.m_pFixComm.SetItemString(15003, ref lstrFactory);
                                    this.m_pFixComm.SetItemString(10013, ref lstrPlant);
                                    SortedDictionary<string, List<int>> loAllChannsInPlant = lpValue.Value;
                                    while (this.m_pFixComm.More() > 0)
                                    {
                                        string lstrChann = this.m_pFixComm.GetItem(10014);
                                        float lfChannValue = (float)this.m_pFixComm.GetDouble(10020);
                                        if (lpValue.Value.ContainsKey(lstrChann))
                                        {
                                            for (int i = 0; i < lpValue.Value[lstrChann].Count; i++)
                                            {
                                                int lnIndex = lpValue.Value[lstrChann][i];

                                                this.m_oServerSetting.TotalItems[lnIndex].Value = lfChannValue;
                                                this.m_oServerSetting.TotalItems[lnIndex].BHStatus = Opc.Da.qualityBits.good;
                                                this.m_oServerSetting.TotalItems[lnIndex].UpdateTime = System.DateTime.Now;
                                                this.m_oServerSetting.TotalItems[lnIndex].UpdateCount++;
                                            }//for (int i = 0; i < lpValue.Value[lstrChann].Count; i++)
                                            loAllChannsInPlant.Remove(lstrChann);

                                        }//if (lpValue.Value.ContainsKey(lstrChann))

                                    }//while (this.m_pFixComm.More() > 0)

                                    foreach (KeyValuePair<string, List<int>> lpPair in loAllChannsInPlant)
                                    {
                                        for (int i = 0; i < lpPair.Value.Count; i++)
                                        {
                                            int lnIndex = lpPair.Value[i];
                                            this.m_oServerSetting.TotalItems[lnIndex].BHStatus = Opc.Da.qualityBits.bad;
                                        }

                                    }
                                }//foreach (KeyValuePair<string, SortedDictionary<string, List<int>>> lpValue in loChanns)
                            }
                            catch (System.Exception ex)
                            {
                                ThreadUiController.log("Read Data From BH Server Failed: " + ex.Message, ThreadUiController.LOG_LEVEL.FATAL);
                                Debug.Assert(false);
                            }
                        } // if (lbConnected)
                        else
                        {
                            for (int i = 0; i < this.ServerSetting.TotalItems.Count; i++)
                            {
                                this.ServerSetting.TotalItems[i].BHStatus = qualityBits.badNotConnected;
                            }
                        }

                        if (!this.m_bShouldStop)
                        {
                            this.BHServerStarted = true;
                            if (this.OpcServerStarted)
                            {
                                this._Status = COLLECTOR_STATUS.STARTED;
                            }
                            CollectorDataEventArgs e = new CollectorDataEventArgs(this.ServerSetting);
                            this.FireDataChanged(e);
                        }

                    }//if (lbShouldDoRead)

                    lnTictCount = System.Environment.TickCount - lnTictLast;
                    if (lnTictCount < lnTictLimit)
                    {
                        Thread.Sleep(100);
                        lbShouldDoRead = false;
                    }
                    else
                    {
                        lbShouldDoRead = true;
                    }

                }// while (!this.ShouldStop)
            }
            catch (System.Exception ex)
            {
                ThreadUiController.log("ReadBH Failed: " + ex.Message, ThreadUiController.LOG_LEVEL.FATAL);
                Debug.Assert(false);
            }

        }

        private Boolean WriteOpc()
        {
            try
            {
                int lnDataIndex = 0;

                ItemValueResult[] values = this.m_pSubscription.Read(this.m_pSubscription.Items);
                System.Collections.Generic.List<ItemValueResult> loValues
                    = new System.Collections.Generic.List<ItemValueResult>();

                System.Collections.Generic.Dictionary<string, List<int>> loIndexes
                    = new System.Collections.Generic.Dictionary<string, List<int>>();
                int lnItemIndex = 0;
                foreach (ItemValueResult value in values)
                {
                    lnDataIndex = (int)(this.m_pSubscription.Items[lnItemIndex].ClientHandle);
                    Debug.Assert(value.ItemName == this.ServerSetting.TotalItems[lnDataIndex].TagName);
                    value.Value = this.ServerSetting.TotalItems[lnDataIndex].Value;
                    this.ServerSetting.TotalItems[lnDataIndex].SendTime = System.DateTime.Now;
                    value.Quality = Opc.Da.Quality.Good;
                    value.QualitySpecified = true;
                    value.Timestamp = System.DateTime.Now;
                    value.TimestampSpecified = true;

                    loValues.Add(value);
                    string lstrKey = value.ItemPath + "|" + value.ItemName;
                    if (!loIndexes.ContainsKey(lstrKey))
                    {
                        loIndexes.Add(lstrKey, new List<int>());
                    }

                    loIndexes[lstrKey].Add(lnDataIndex);
                    lnItemIndex++;
                }

                IdentifiedResult[] lpResults = this.m_pSubscription.Write(loValues.ToArray());
                lnDataIndex = 0;

                foreach (IdentifiedResult result in lpResults)
                {
                    string lstrKey = result.ItemPath + "|" + result.ItemName;
                    List<int> loListIndexes = loIndexes[lstrKey];
                    for (int i = 0; i < loListIndexes.Count; i++)
                    {
                        int lnIndex = loListIndexes[i];
                        if (result.ResultID != ResultID.S_OK)
                        {
                            this.ServerSetting.TotalItems[lnIndex].OpcStatus = Opc.Da.qualityBits.bad;
                        }
                        else
                        {
                            this.ServerSetting.TotalItems[lnIndex].OpcStatus = Opc.Da.qualityBits.good;
                        }
                    }

                }

                CollectorDataEventArgs e = new CollectorDataEventArgs(this.ServerSetting);
                this.FireDataChanged(e);

                return true;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log("WriteOpc Failed : " + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                return false;
            }

        }

        private void CollectorThreadStart()
        {
            //1.connect to BH server
            //             if (!this.ConnectBHServer())
            //             {
            //                 this._Status = COLLECTOR_STATUS.STOPPED;
            // 
            //                 return;
            //             }

            if (this.m_pServerReadBH != null)
            {
                try
                {
                    this.m_pServerReadBH.Join(1000);
                    this.m_pServerReadBH.Abort();
                    this.m_pServerReadBH = null;
                }
                catch (System.Exception ex)
                {
                    Debug.Assert(false);
                    ThreadUiController.log("this.m_pServerReadBH.Abort() Failed : " + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                }
            }

            try
            {
                this.m_pServerReadBH = new Thread(new ThreadStart(ReadBH));
                this.m_pServerReadBH.IsBackground = true;
                this.m_pServerReadBH.Name = "Read Data From BH";
                this.m_pServerReadBH.Start();
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log("this.m_pServerReadBH.Start() Failed : " + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);

            }

            //1.1 connect to opc server
            if (!this.ConnectOpcServer())
            {
                this._Status = COLLECTOR_STATUS.STOPPED;

                return;
            }

            //2.Add Item
            if (!this.AddItems())
            {
                this._Status = COLLECTOR_STATUS.STOPPED;

                return;
            }

            //3.read Data,and fire CallBack
            while (!this.ShouldStop)
            {
                int lnTimeStart = System.Environment.TickCount;

                if (!this.WriteOpc())
                {
                    Debug.Assert(false);
                }

                int lnTimeStop = System.Environment.TickCount;
                int lnTimeElapsed = lnTimeStop - lnTimeStart;

                int lnTimeToSleep = this.m_oServerSetting.TimeInterval - lnTimeElapsed;

                if (lnTimeToSleep < 0)
                {
                    lnTimeToSleep = 0;
                }

                Thread.Sleep(lnTimeToSleep);
            }
        }


        Boolean m_bShouldStop = false;
        public System.Boolean ShouldStop
        {
            get { return m_bShouldStop; }
            set { m_bShouldStop = value; }
        }
        public void Start()
        {
            this.OpcServerStarted = false;
            this.BHServerStarted = false;

            if (this.Status != COLLECTOR_STATUS.STOPPED
                || this.m_pServerThread != null)
            {
                this.Stop();
            }

            this._Status = COLLECTOR_STATUS.STARTING;

            try
            {
                this.m_pServerThread = new Thread(new ThreadStart(CollectorThreadStart));
                this.m_pServerThread.IsBackground = true;
                this.m_pServerThread.Start();

            }
            catch (System.Exception ex)
            {
                this.m_pServerThread = null;
                this._Status = COLLECTOR_STATUS.STOPPED;

                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
        }
        public void Stop()
        {
            try
            {
                this._Status = COLLECTOR_STATUS.STOPPING;

                this.ShouldStop = true;

                if (this.m_pServerThread != null)
                {
                    this.m_pServerThread.Join(2000);
                    this.m_pServerThread.Abort();

                    try
                    {
                        if (this.m_pSubscription != null)
                        {
                            this.m_pSubscription.Dispose();
                            this.m_pSubscription = null;
                        }
                    }
                    catch (System.Exception ex)
                    {
                        Debug.Assert(false);
                        Debug.WriteLine(ex.ToString());
                        ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                    }

                    if (this.m_pTargetServer != null)
                    {
                        try
                        {
                            m_pTargetServer.Disconnect();
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }

                        try
                        {
                            m_pTargetServer.Dispose();
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }

                        try
                        {
                            m_pTargetServer = null;
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }
                    }
                }

                this._Status = COLLECTOR_STATUS.STOPPED;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
        }

        private Thread m_pServerThread = null;
        private Thread m_pServerReadBH = null;
    }

    public class ThreadAspenCollector
    {

        public ThreadAspenCollector()
        {

        }

        public event StatusChangedEventHandler OnCollectorStatusChanged;
        public event DataChangedEventHandler OnDataChanged;

        protected Opc.Da.Server m_pTargetServer = null;
        protected Opc.Da.Subscription m_pSubscription = null;


        ServerSetting m_oServerSetting = new ServerSetting();


        COLLECTOR_STATUS m_nStatus = COLLECTOR_STATUS.STOPPED;

        public DAQ.COLLECTOR_STATUS Status
        {
            get
            {
                return m_nStatus;
            }

        }

        protected DAQ.COLLECTOR_STATUS _Status
        {
            set
            {
                m_nStatus = value;

                CollectorStatusEventArgs e = new CollectorStatusEventArgs(m_nStatus);

                this.FireStatusChanged(e);
            }
        }

        protected virtual void FireDataChanged(CollectorDataEventArgs e)
        {
            if (OnDataChanged != null)
            {
                OnDataChanged(this, e);
            }
        }

        protected virtual void FireStatusChanged(CollectorStatusEventArgs e)
        {
            if (OnCollectorStatusChanged != null)
            {
                OnCollectorStatusChanged(this, e);
            }
        }

        public DAQ.ServerSetting ServerSetting
        {
            get { return m_oServerSetting; }
            set { m_oServerSetting = value; }
        }


        private void DisconnectFromServer()
        {
            try
            {


            }
            catch (System.Exception ex)
            {
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
            finally
            {

            }


            try
            {

            }
            catch (System.Exception ex)
            {
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
            finally
            {
            }
        }

        private Boolean ConnectAspenServer()
        {
            using (OdbcConnection connection = new OdbcConnection("DRIVER={AspenTech SQLplus};HOST=" + this.ServerSetting.Machine + ";"))
            {
                DataSet ds = new DataSet();
                try
                {
                    connection.Open();

                }
                catch (Exception ex)
                {
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);

                    return false;
                }
                finally
                {
                    try
                    {
                        connection.Close();
                    }
                    catch (System.Exception ex)
                    {
                        ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);

                    }
                }

                return true;
            }
        }

        private Boolean AddItems()
        {
            Boolean lbResult = true;

            return lbResult;
        }

        private Boolean Read()
        {
            try
            {

                OdbcConnection connection = new OdbcConnection("DRIVER={AspenTech SQLplus};HOST=" + this.ServerSetting.Machine + ";");

                try
                {
                     connection.Open();
                }
                catch (System.Exception ex)
                {
                	Debug.Assert(false);
                    Debug.WriteLine(ex.ToString());
                    ThreadUiController.log("ThreadAspenCollector::Read() Failed:" + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                    return false;
                }

                 int lnItemIndex = 0;
                 
                foreach (ItemSetting value in this.ServerSetting.TotalItems)
                {
                    String lstrSql = "select * from IP_AnalogDef where name = '" + value.TagName + "'";
                    OdbcDataAdapter command = new OdbcDataAdapter(lstrSql, connection);
                    DataSet ds = new DataSet();
                   command.Fill(ds,"ds");
                   Boolean lbGood = false;
                    if (ds.Tables.Count>0)
                    {
                        if (ds.Tables[0].Rows.Count>0)
                        {
                            value.Value = (float)ds.Tables[0].Rows[0]["IP_INPUT_VALUE"];
                          value.OpcStatus = qualityBits.good;
                          value.UpdateTime = System.DateTime.Now;
                          value.UpdateCount++;
                          lbGood = true;
                        }
                    }
                    if (!lbGood)
                    {
                        value.OpcStatus = qualityBits.bad;
                    }
                    try
                    {
                        ds.Dispose();
                    }
                    catch (System.Exception ex)
                    {
                    	
                    }

                    try
                    {
                        command.Dispose();
                    }
                    catch (System.Exception ex)
                    {

                    }
                    //
                    //String lstrSql = "select "+this.ServerSetting.ProgID+" from IP_AnalogDef where name like '%" + value.TagName + "%'";
/*
                    lnDataIndex = (int)this.m_pSubscription.Items[lnItemIndex].ClientHandle;
                    Debug.Assert(value.ItemName == this.ServerSetting.TotalItems[lnDataIndex].TagName);
                    this.ServerSetting.TotalItems[lnDataIndex].Value = value.Value;
                    double ldbl = 0;
                    if (double.TryParse(value.Value.ToString(), out ldbl))
                    {
                        this.ServerSetting.TotalItems[lnDataIndex].Value = ldbl * this.ServerSetting.TotalItems[lnDataIndex].K + this.ServerSetting.TotalItems[lnDataIndex].B;
                    }
                    this.ServerSetting.TotalItems[lnDataIndex].Quality = value.Quality;
                    this.ServerSetting.TotalItems[lnDataIndex].UpdateTime = value.Timestamp;
                    this.ServerSetting.TotalItems[lnDataIndex].UpdateCount++;*/
                    // lnDataIndex++;
                    lnItemIndex++;
                }


                try
                {
                    connection.Close();
                }
                catch (System.Exception ex)
                {
                	Debug.Assert(false);
                    Debug.WriteLine(ex.ToString());
                    ThreadUiController.log("ThreadAspenCollector::Read() Failed:" + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                    return false;
                }

                return lnItemIndex > 0;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log("ThreadAspenCollector::Read() Failed:" + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            return false;
        }

        private void CollectorThreadStart()
        {
            while (!this.ShouldStop)
            {
                //0.disconnected from previous server
                this.DisconnectFromServer();

                //1.connect to server
                if (!this.ConnectAspenServer())
                {
                    this._Status = COLLECTOR_STATUS.STOPPED;

                    Thread.Sleep(10000);

                    continue;
                }

                //2.Add Item
                if (!this.AddItems())
                {
                    this._Status = COLLECTOR_STATUS.STOPPED;

                    Thread.Sleep(10000);

                    continue;
                }

                //3.read Data,and fire CallBack
                while (!this.ShouldStop)
                {
                    int lnTimeStart = System.Environment.TickCount;
                    Boolean lbShouldRestart = false;
                    if (this.Read())
                    {
                        CollectorDataEventArgs e = new CollectorDataEventArgs(this.ServerSetting);
                        this.FireDataChanged(e);
                    }
                    else
                    {
                        lbShouldRestart = true;
                    }

                    //this._Status = COLLECTOR_STATUS.STARTED;
                    int lnTimeStop = System.Environment.TickCount;
                    int lnTimeElapsed = lnTimeStop - lnTimeStart;

                    int lnTimeToSleep = this.m_oServerSetting.TimeInterval - lnTimeElapsed;

                    if (lnTimeToSleep < 0)
                    {
                        lnTimeToSleep = 0;
                    }
                    this._Status = COLLECTOR_STATUS.STARTED;
                    Thread.Sleep(lnTimeToSleep);
                    if (lbShouldRestart)
                    {
                        //sth wrong happened reconnect to opc server

                        break;
                    }
                }//while (!this.ShouldStop)


            }// while (!this.ShouldStop)

        }


        Boolean m_bShouldStop = false;
        public System.Boolean ShouldStop
        {
            get { return m_bShouldStop; }
            set { m_bShouldStop = value; }
        }
        public void Start()
        {
            if (this.Status != COLLECTOR_STATUS.STOPPED
                || this.m_pServerThread != null)
            {
                this.Stop();
            }

            this._Status = COLLECTOR_STATUS.STARTING;

            try
            {
                this.m_pServerThread = new Thread(new ThreadStart(CollectorThreadStart));
                this.m_pServerThread.IsBackground = true;
                this.m_pServerThread.Start();

            }
            catch (System.Exception ex)
            {
                this.m_pServerThread = null;
                this._Status = COLLECTOR_STATUS.STOPPED;

                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
        }
        public void Stop()
        {
            try
            {
                this._Status = COLLECTOR_STATUS.STOPPING;

                this.ShouldStop = true;

                if (this.m_pServerThread != null)
                {
                    try
                    {
                    	this.m_pServerThread.Join(2000);
                    }
                    catch (System.Exception ex)
                    {
                    	
                    }
                    try
                    {
                    	this.m_pServerThread.Abort();
                    }
                    catch (System.Exception ex)
                    {
                    	
                    }

                    try
                    {
                    }
                    catch (System.Exception ex)
                    {
                        Debug.Assert(false);
                        Debug.WriteLine(ex.ToString());
                        ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                    }

                    if (this.m_pTargetServer != null)
                    {
                        try
                        {
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }

                        try
                        {
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }

                        try
                        {
                        }
                        catch (System.Exception ex)
                        {
                            Debug.Assert(false);
                            Debug.WriteLine(ex.ToString());
                            ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                        }
                    }
                }

                this._Status = COLLECTOR_STATUS.STOPPED;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
        }

        private Thread m_pServerThread = null;
    }
}
