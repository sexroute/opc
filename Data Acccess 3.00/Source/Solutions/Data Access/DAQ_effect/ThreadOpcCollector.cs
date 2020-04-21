using System;
using System.Collections.Generic;
using System.Text;

using System.ComponentModel;
using System.Data;
using System.Drawing;


using System.Windows.Forms;
using Opc;
using OpcCom;
using Opc.Da;
using System.Diagnostics;
using System.Threading;
using EricZhao.UiThread;
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

        Dictionary<String, ItemSetting> m_oCalculatedItems = new Dictionary<String, ItemSetting>();
        public Dictionary<String, ItemSetting> CalculatedItems
        {
            get { return m_oCalculatedItems; }
            set { m_oCalculatedItems = value; }
        }

        Dictionary<String, ItemSetting> m_oAllReadItems = new Dictionary<String, ItemSetting>();
        public Dictionary<String, ItemSetting> ToReadItems
        {
            get { return m_oAllReadItems; }
            set { m_oAllReadItems = value; }
        }

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
                    this.CallbackFunctionAdded = false;
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

        private String m_StrOpcUserName = "";
        public System.String OpcUserName
        {
            get { return m_StrOpcUserName; }
            set { m_StrOpcUserName = value; }
        }
        private String m_StrOpcPassword = "";
        public System.String OpcPassword
        {
            get { return m_StrOpcPassword; }
            set { m_StrOpcPassword = value; }
        }

        private Boolean ConnectOpcServer()
        {
            Opc.IDiscovery m_discovery = null;
            Boolean lbResult = false;
            this.OpcUserName = this.m_oServerSetting.OpcUserName;
            this.OpcPassword = this.m_oServerSetting.OpcPassword;
            try
            {
                m_discovery = new OpcCom.ServerEnumerator();

                Opc.Server[] servers = null;
                Opc.Server[] servers2 = null;
                Opc.Server[] servers3 = null;

                Opc.ConnectData mConnectData = null;

                if ((!String.IsNullOrEmpty(this.OpcUserName)) && (!String.IsNullOrEmpty(this.OpcPassword)))
                {
                    System.Net.NetworkCredential mCredentials = new System.Net.NetworkCredential();
                    mCredentials.UserName = this.OpcUserName;
                    mCredentials.Password = this.OpcPassword;
                    mConnectData = new Opc.ConnectData(mCredentials);
                }
                try
                {
                    servers = m_discovery.GetAvailableServers(
                                                               Specification.COM_DA_10,
                                                               this.m_oServerSetting.Machine,
                                                               mConnectData);
                }
                catch (Exception ex)
                {
                    Debug.Assert(false);
                    Debug.WriteLine(ex.Message);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);

                }


                try
                {

                    servers2 = m_discovery.GetAvailableServers(
                                                           Specification.COM_DA_20,
                                                           this.m_oServerSetting.Machine,
                                                           mConnectData);
                }
                catch (Exception ex)
                {

                   // Debug.Assert(false);
                    Debug.WriteLine(ex.Message);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                }

                try
                {

                    servers3 = m_discovery.GetAvailableServers(
                                                           Specification.COM_DA_30,
                                                           this.m_oServerSetting.Machine,
                                                           mConnectData);
                }
                catch (Exception ex)
                {
                    //  Debug.Assert(false);
                    Debug.WriteLine(ex.Message);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);

                }

                Dictionary<Opc.Server, String> loServers = new Dictionary<Opc.Server, String>();

                if (servers != null)
                {
                    foreach (Opc.Da.Server server in servers)
                    {
                        loServers.Add(server, "COM_DA_10");
                    }
                }

                if (servers2 != null)
                {
                    foreach (Opc.Da.Server server in servers2)
                    {
                        loServers.Add(server, "COM_DA_20");
                    }
                }

                if (servers3 != null)
                {
                    foreach (Opc.Da.Server server in servers3)
                    {
                        loServers.Add(server, "COM_DA_30");
                    }
                }

                foreach (Opc.Da.Server server in loServers.Keys)
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
                    m_pTargetServer.Connect(mConnectData);
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
                   // Debug.Assert(false);
                    Debug.WriteLine(ex.Message);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                }

                return lbResult;

            }
            catch (System.Exception ex)
            {

               // Debug.Assert(false);
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
            int lnToReadItemCount = 0;
            for (int i = 0; i < this.m_oServerSetting.TotalItems.Count; i++)
            {
                if (this.m_oServerSetting.TotalItems[i].ItemType == 0)
                {
                    lnToReadItemCount++;
                }
            }

            List<Item> items = new List<Item>();
            //  Item[] items = new Item[lnToReadItemCount];//定义数据项，即item
            this.CalculatedItems.Clear(); //清空自计算条目项
            this.ToReadItems.Clear();
            for (int i = 0; i < this.m_oServerSetting.TotalItems.Count; i++)
            {
                ItemSetting lpItemSetting = this.m_oServerSetting.TotalItems[i];
                //no need read from opc server
                if (lpItemSetting.ItemType != 0)
                {
                    this.CalculatedItems.Add(lpItemSetting.Key, lpItemSetting);
                    continue;
                }
                try
                {

                    this.ToReadItems.Add(lpItemSetting.Key, lpItemSetting);
                    Item lpItem = new Item();//创建一个项Item对象。
                    items.Add(lpItem);
                    lpItem.ClientHandle = i;//客户端给该数据项分配的句柄。
                    lpItem.ItemPath = null; //该数据项在服务器中的路径。
                    lpItem.ItemName = lpItemSetting.TagName; //该数据项在服务器中的名字。
                }
                catch (System.Exception ex)
                {
                    if (lpItemSetting != null)
                    {
                        lpItemSetting.SourceStatus = 0;
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
                m_pSubscription.AddItems(items.ToArray());

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

        private int m_nErrorCount = 0;
        private Boolean m_bReadFailed = false;
        public System.Boolean ReadFailed
        {
            get { return m_bReadFailed; }
            set { m_bReadFailed = value; }
        }

        AutoResetEvent m_pAsyncReadEvent = new AutoResetEvent(false);
        private void OnDataChange(object subscriptionHandle, object requestHandle, ItemValueResult[] values)
        {
            try
            {
                if (this.m_pSubscription == null)
                {
                    this.ReadFailed = true;
                    return;
                }

                int lnDataIndex = 0;
                int lnItemIndex = 0;
                foreach (ItemValueResult value in values)
                {
                    lnDataIndex = (int)this.m_pSubscription.Items[lnItemIndex].ClientHandle;
                    Debug.Assert(value.ItemName == this.ServerSetting.TotalItems[lnDataIndex].TagName);

                    bool lbRet = false;

                    if (Boolean.TryParse(value.Value.ToString(), out lbRet))
                    {
                        if (lbRet)
                        {
                            value.Value = 1;
                        }
                        else
                        {
                            value.Value = 0;
                        }

                    }
                    //else
                    {
                        double ldbl = 0;
                        if (double.TryParse(value.Value.ToString(), out ldbl))
                        {
                            this.ServerSetting.TotalItems[lnDataIndex].Value = ldbl * this.ServerSetting.TotalItems[lnDataIndex].K
                                                                                + this.ServerSetting.TotalItems[lnDataIndex].B;
                        }
                    }

                    this.ServerSetting.TotalItems[lnDataIndex].Quality = value.Quality;
                    this.ServerSetting.TotalItems[lnDataIndex].SourceStatus = value.Quality.QualityBits;
                    this.ServerSetting.TotalItems[lnDataIndex].LastUpdateTime = this.ServerSetting.TotalItems[lnDataIndex].UpdateTime;
                    this.ServerSetting.TotalItems[lnDataIndex].UpdateTime = value.Timestamp;
                    this.ServerSetting.TotalItems[lnDataIndex].UpdateCount++;
                    // lnDataIndex++;
                    lnItemIndex++;
                    m_pAsyncReadEvent.Set();
                }
            }
            catch(Exception e)
            {
                this.ReadFailed = true;
            }
        }

        private void SyncRead()
        {
            ItemValueResult[] values = this.m_pSubscription.Read(this.m_pSubscription.Items);

            int lnDataIndex = 0;
            int lnItemIndex = 0;
            foreach (ItemValueResult value in values)
            {
                lnDataIndex = (int)this.m_pSubscription.Items[lnItemIndex].ClientHandle;
                Debug.Assert(value.ItemName == this.ServerSetting.TotalItems[lnDataIndex].TagName);

                bool lbRet = false;

                if (Boolean.TryParse(value.Value.ToString(), out lbRet))
                {
                    if (lbRet)
                    {
                        value.Value = 1;
                    }
                    else
                    {
                        value.Value = 0;
                    }

                }
                //else
                {
                    double ldbl = 0;
                    if (double.TryParse(value.Value.ToString(), out ldbl))
                    {
                        this.ServerSetting.TotalItems[lnDataIndex].Value = ldbl * this.ServerSetting.TotalItems[lnDataIndex].K
                                                                            + this.ServerSetting.TotalItems[lnDataIndex].B;
                    }
                }

                this.ServerSetting.TotalItems[lnDataIndex].Quality = value.Quality;
                this.ServerSetting.TotalItems[lnDataIndex].SourceStatus = value.Quality.QualityBits;
                this.ServerSetting.TotalItems[lnDataIndex].LastUpdateTime = this.ServerSetting.TotalItems[lnDataIndex].UpdateTime;
                this.ServerSetting.TotalItems[lnDataIndex].UpdateTime = value.Timestamp;
                this.ServerSetting.TotalItems[lnDataIndex].UpdateCount++;
                // lnDataIndex++;
                lnItemIndex++;
            }
        }

        Boolean m_bCallbackFunctionAdded = false;
        public System.Boolean CallbackFunctionAdded
        {
            get { return m_bCallbackFunctionAdded; }
            set { m_bCallbackFunctionAdded = value; }
        }
        private Boolean Read()
        {
            try
            {
                if (this.m_oServerSetting.OpcAsyncRead)
                {
                    this.ReadFailed = false;
                    if(!this.CallbackFunctionAdded)
                    {
                        this.m_pSubscription.DataChanged += new Opc.Da.DataChangedEventHandler(OnDataChange);
                        this.CallbackFunctionAdded = true;
                    }

                    Boolean lbAnyUpdated = false;
                    lbAnyUpdated = this.m_pAsyncReadEvent.WaitOne(20 * 1000);
                    if (!lbAnyUpdated)
                    {
                        return false;
                    }

                }
                else
                {
                    try
                    {
                        this.SyncRead();
                    }
                    catch (Exception e)
                    {
                        
                       return false;
                    }

                }

               

                    foreach (KeyValuePair<String, ItemSetting> lpCalculatedItemPair in this.CalculatedItems)
                {
                    ItemSetting lpCalculatedItem = lpCalculatedItemPair.Value;

                    if (null == lpCalculatedItem
                        || lpCalculatedItem.ItemType == 0
                        || String.IsNullOrEmpty(lpCalculatedItem.ScriptContent))
                    {
                        Debug.Assert(false);
                        continue;
                    }
                    List<object> loArgs = new List<object>();
                    Boolean lbAnyArgsUpdated = false;
                    System.DateTime loDatetime = System.DateTime.MinValue;

                    if (lpCalculatedItem.Vars != null && lpCalculatedItem.Vars.Count > 0)
                    {
                        foreach (string lstrVarKey in lpCalculatedItem.Vars)
                        {
                            if (!this.ToReadItems.ContainsKey(lstrVarKey))
                            {
                                // Debug.Assert(false);
                                continue;
                            }
                            ItemSetting lpItemArg = this.ToReadItems[lstrVarKey];
                            if (null == lpItemArg)
                            {
                                //Debug.Assert(false);
                                continue;
                            }
                            object loValue = lpItemArg.Value;
                            if (lpCalculatedItem.VariableTypes.ContainsKey(lstrVarKey))
                            {
                                if (lpCalculatedItem.VariableTypes[lstrVarKey] != ItemSetting.BH_ITEM_TYPE.PROC)
                                {
                                    if (lpItemArg.Buffer != null)
                                    {
                                        loValue = lpItemArg.Buffer.Clone();
                                    }
                                    else
                                    {
                                        loValue = new double[0];
                                    }

                                }

                            }

                            if (lpItemArg.LastUpdateTime <= lpItemArg.UpdateTime)
                            {
                                lbAnyArgsUpdated = true;
                                loDatetime = lpItemArg.UpdateTime;
                            }

                            loArgs.Add(loValue);
                        }
                    }
                    else
                    {
                        lbAnyArgsUpdated = true;
                    }

                    if (!lbAnyArgsUpdated)
                    {
                        lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                        lpCalculatedItem.SourceStatus = Opc.Da.qualityBits.badLastKnownValue;
                        lpCalculatedItem.BHQuality = Opc.Da.Quality.Bad;
                        lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                        continue;
                    }
                    string lstrScript = lpCalculatedItem.ScriptContent;
                    object[] loArgObjs = loArgs.ToArray();
                    String lstrError = "";
                    List<System.CodeDom.Compiler.CompilerError> loErrors = null;
                    object loRetValue = ScriptingInterface.CompilerRunner.Run(lstrScript, loArgObjs, ref lstrError, ref loErrors);
                    try
                    {
                        double ldblValue = 0.0;
                        if (!double.TryParse(loRetValue.ToString(), out ldblValue) || double.IsNaN(ldblValue))
                        {
                            ThreadUiController.log("Custom compute error :" + lstrError, ThreadUiController.LOG_LEVEL.FATAL);
                            this.m_nErrorCount++;
#if DEBUG
#else   
                            if (this.m_nErrorCount>20)
                            {
                                Thread.Sleep(10000);
                                ThreadUiController.ApplicationExit();
                            }
#endif
                            loRetValue = 0.0;
                            lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                            lpCalculatedItem.SourceStatus = Opc.Da.Quality.Bad.QualityBits;
                            ScriptingInterface.CompilerRunner.clearSource();
                        }
                        else
                        {
                            this.m_nErrorCount = 0;
                            loRetValue = ldblValue * lpCalculatedItem.K + lpCalculatedItem.B;
                            lpCalculatedItem.Quality = Opc.Da.Quality.Good;
                            lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                            lpCalculatedItem.SourceStatus = Opc.Da.Quality.Good.QualityBits;
                            lpCalculatedItem.UpdateTime = loDatetime;

                        }
                        lpCalculatedItem.UpdateCount++;
                    }
                    catch (System.Exception ex)
                    {
                        Debug.WriteLine(ex.Message);
                    }
                    lpCalculatedItem.Value = loRetValue;
                }

                return true;
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
                    this._Status = COLLECTOR_STATUS.ERROR_RETRYING;
                    Thread.Sleep(3000);
                    continue;
                }

                //2.Add Item
                if (!this.AddItems())
                {
                    this._Status = COLLECTOR_STATUS.ERROR_RETRYING;
                    Thread.Sleep(3000);
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

                    if(this.ReadFailed)
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

                    if(!lbShouldRestart)
                    {
                        this._Status = COLLECTOR_STATUS.STARTED;
                    }else
                    {
                        this._Status = COLLECTOR_STATUS.STARTING;
                    }
                   
                    Thread.Sleep(lnTimeToSleep);
                    if (lbShouldRestart)
                    {
                        foreach (ItemSetting lpItem in this.ServerSetting.TotalItems)
                        {
                            lpItem.BHQuality = Opc.Da.Quality.Bad;
                            lpItem.Quality = Opc.Da.Quality.Bad;
                            lpItem.SourceStatus = qualityBits.badNotConnected;
                        }

                        CollectorDataEventArgs e = new CollectorDataEventArgs(this.ServerSetting);
                        this.FireDataChanged(e);
                        //sth wrong happened reconnect to opc server
                        this._Status = COLLECTOR_STATUS.ERROR_RETRYING;
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
            ScriptingInterface.CompilerRunner.clearSource();

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

        Dictionary<String, ItemSetting> m_oCalculatedItems = new Dictionary<String, ItemSetting>();
        public Dictionary<String, ItemSetting> CalculatedItems
        {
            get { return m_oCalculatedItems; }
            set { m_oCalculatedItems = value; }
        }

        Dictionary<String, ItemSetting> m_oAllReadItems = new Dictionary<String, ItemSetting>();
        public Dictionary<String, ItemSetting> ToReadItems
        {
            get { return m_oAllReadItems; }
            set { m_oAllReadItems = value; }
        }

        Dictionary<String, ItemSetting> m_oBufferedReadItems = new Dictionary<String, ItemSetting>();
        public Dictionary<String, ItemSetting> BufferReadItems
        {
            get { return m_oBufferedReadItems; }
            set { m_oBufferedReadItems = value; }
        }


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
            int lnServerType = (int)this.m_oServerSetting.BHServerTpyeSrc;
            if (lnServerType == (int)DAQ.ServerSetting.BHServerType.NEW)
            {

                try
                {
                    using (Dse.FixComm loFixComm = Dse.FixComm.New(this.m_oServerSetting.ServerIp, 
                        "" + this.m_oServerSetting.ServerPort))
                    {
                        if (loFixComm.Link(this.m_oServerSetting.DstServerIp, "" + this.m_oServerSetting.DstServerPort))
                        {
                            return true;
                        }
                        else
                        {
                            FormMain.checkHealth(this.m_oServerSetting.HandleLimitCount);
                        }
                    }
                }
                catch (Exception)
                {

                    return false;
                }
            }
            else
            {
                if (null == this.m_pFixComm)
                {
                    this.m_pFixComm = new CBHFixComLib.CBHFixComImp();
                    lnServerType = (int)this.m_oServerSetting.BHServerTpyeSrc;
                    if (lnServerType > (int)DAQ.ServerSetting.BHServerType.OLD)
                    {
                        lnServerType = (int)DAQ.ServerSetting.BHServerType.OLD;
                    }
                    this.m_pFixComm.SetCommType(lnServerType);
                }

                String lstrConnstr = string.Format("{0},{1}/TCP",
                                                    this.m_oServerSetting.ServerIp,
                                                    this.m_oServerSetting.ServerPort + "");
                String lstrDept = "";

                try
                {
                    if (this.m_pFixComm.Link(ref lstrConnstr, ref lstrDept) > 0)
                    {
                        return true;
                    }
                    else
                    {
                        FormMain.checkHealth(this.m_oServerSetting.HandleLimitCount);
                    }
                }
                catch (System.Exception ex)
                {

                }
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

                Opc.Server[] servers = null;

                try
                {
                    servers = m_discovery.GetAvailableServers(
                                                               Specification.COM_DA_10,
                                                               this.m_oServerSetting.Machine,
                                                               null);
                }
                catch (Exception e)
                {


                }

                if (servers == null || servers.Length == 0)
                {
                    servers = m_discovery.GetAvailableServers(
                                                               Specification.COM_DA_20,
                                                               this.m_oServerSetting.Machine,
                                                               null);

                }

                foreach (Opc.Da.Server server in servers)
                {

                    if (server.Name.CompareTo(this.m_oServerSetting.DstProgID) == 0)
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
                        lpItemSetting.DstStatus = qualityBits.bad;
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

        class BH_REQUEST_KEY
        {
            public string m_strCompany = "";
            public string Company
            {
                get { return m_strCompany; }
                set { m_strCompany = value; }
            }
            public string m_strFactory = "";
            public string Factory
            {
                get { return m_strFactory; }
                set { m_strFactory = value; }
            }
            public string m_strPlant = "";
            public string Plant
            {
                get { return m_strPlant; }
                set { m_strPlant = value; }
            }
            Dictionary<string, ItemSetting> m_oItems = null;
            public Dictionary<string, ItemSetting> Items
            {
                get { return m_oItems; }
                set { m_oItems = value; }
            }

            public string m_strRequestKey = "";
            public string RequestKey
            {
                get { return m_strRequestKey; }
                set { m_strRequestKey = value; }
            }
        }

        public static double[] convertByteArrayTodoubleArray(byte[] apBuffer, System.Type anBufferType, Double K, Double B)
        {

            double[] lpRet = null;
            int aDoubleCoverBytes = 0;
            if (anBufferType == typeof(Double))
            {
                aDoubleCoverBytes = 8;
            }
            else if (anBufferType == typeof(System.Single))
            {
                aDoubleCoverBytes = 4;
            }
            else if (anBufferType == typeof(System.Int32))
            {
                aDoubleCoverBytes = 4;
            }
            else if (anBufferType == typeof(System.UInt32))
            {
                aDoubleCoverBytes = 4;
            }
            else if (anBufferType == typeof(System.Int16))
            {
                aDoubleCoverBytes = 2;
            }
            else if (anBufferType == typeof(System.UInt16))
            {
                aDoubleCoverBytes = 2;
            }
            else if (anBufferType == typeof(byte))
            {
                aDoubleCoverBytes = 1;
            }
            else if (anBufferType == typeof(char))
            {
                aDoubleCoverBytes = 1;
            }
            else if (anBufferType == typeof(char))
            {
                aDoubleCoverBytes = 1;
            }
            else if (anBufferType == typeof(System.Int64))
            {
                aDoubleCoverBytes = 8;
            }
            else if (anBufferType == typeof(System.UInt64))
            {
                aDoubleCoverBytes = 8;
            }

            if ((null == apBuffer)
                || (aDoubleCoverBytes <= 0)
                || (apBuffer.Length < aDoubleCoverBytes)
                || (aDoubleCoverBytes % 2 != 0 && aDoubleCoverBytes > 1)
                || aDoubleCoverBytes > 8)
            {
                lpRet = new double[0];
                return lpRet;
            }
            int lnDoubleCount = apBuffer.Length / aDoubleCoverBytes;
            lpRet = new double[lnDoubleCount];

            if (aDoubleCoverBytes == 1)
            {
                if (anBufferType == typeof(System.Char))
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        lpRet[i] = BitConverter.ToChar(apBuffer, i);
                        lpRet[i] = lpRet[i] * K + B;
                    }

                }
                else
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        lpRet[i] = apBuffer[i];
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }


            }
            else if (aDoubleCoverBytes == 2)
            {
                if (anBufferType == typeof(System.Int16))
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        short sample = BitConverter.ToInt16(apBuffer, i * aDoubleCoverBytes);
                        lpRet[i] = sample;
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }
                else
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        System.UInt16 sample = BitConverter.ToUInt16(apBuffer, i * aDoubleCoverBytes);
                        lpRet[i] = sample;
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }

            }
            else if (aDoubleCoverBytes == 4)
            {
                if (anBufferType == typeof(System.Single))
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        float sample = BitConverter.ToSingle(apBuffer, i * aDoubleCoverBytes);
                        lpRet[i] = sample;
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }
                else if (anBufferType == typeof(System.Int32))
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        System.Int32 sample = BitConverter.ToInt32(apBuffer, i * aDoubleCoverBytes);
                        lpRet[i] = sample;
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }
                else if (anBufferType == typeof(System.UInt32))
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        System.UInt32 sample = BitConverter.ToUInt32(apBuffer, i * aDoubleCoverBytes);
                        lpRet[i] = sample;
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }
            }
            else if (aDoubleCoverBytes == 8)
            {
                if (anBufferType == typeof(System.Double))
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        Double sample = BitConverter.ToDouble(apBuffer, i * aDoubleCoverBytes);
                        lpRet[i] = sample;
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }
                else if (anBufferType == typeof(System.Int64))
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        System.Int64 sample = BitConverter.ToInt64(apBuffer, i * aDoubleCoverBytes);
                        lpRet[i] = sample;
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }
                else if (anBufferType == typeof(System.UInt64))
                {
                    for (int i = 0; i < lnDoubleCount; i++)
                    {
                        System.UInt64 sample = BitConverter.ToUInt64(apBuffer, i * aDoubleCoverBytes);
                        lpRet[i] = sample;
                        lpRet[i] = lpRet[i] * K + B;
                    }
                }
            }


            return lpRet;
        }

        int m_nErrorCount = 0;

        private void ReadBHNewConnection()
        {

            try
            {
                using (Dse.FixComm loFixComm = Dse.FixComm.New(this.m_oServerSetting.ServerIp,
                    "" + this.m_oServerSetting.ServerPort))
                {
                    try
                    {

                        Boolean lbShouldDoRead = true;
                        int lnTictLimit = 300;
                        int lnTictCount = 0;
                        int lnTictLast = 0;

                        String lstrkey = "";
                        SortedDictionary<string, SortedDictionary<string, List<int>>> loProcRequestParams
                            = new SortedDictionary<string, SortedDictionary<string, List<int>>>();
                        this.m_oCalculatedItems.Clear();
                        this.ToReadItems.Clear();
                        Dictionary<String, BH_REQUEST_KEY> loVibRequestParams = new Dictionary<String, BH_REQUEST_KEY>();
                        Dictionary<String, BH_REQUEST_KEY> loDynRequestParams = new Dictionary<String, BH_REQUEST_KEY>();
                        for (int i = 0; i < ServerSetting.TotalItems.Count; i++)
                        {
                            (ServerSetting.TotalItems[i]).LastUpdateTime = DateTime.Now;

                            if (ServerSetting.TotalItems[i].ItemType != 0)
                            {
                                this.CalculatedItems.Add(ServerSetting.TotalItems[i].Key, ServerSetting.TotalItems[i]);

                            }
                            else
                            {
                                lstrkey = ServerSetting.TotalItems[i].Company
                                    + ConstantValueHolder.SPLITER + ServerSetting.TotalItems[i].Factory
                                    + ConstantValueHolder.SPLITER + ServerSetting.TotalItems[i].Plant;

                                if (!loProcRequestParams.ContainsKey(lstrkey))
                                {
                                    SortedDictionary<string, List<int>> loTemp
                                         = new SortedDictionary<string, List<int>>();
                                    loProcRequestParams.Add(lstrkey, loTemp);
                                }

                                if (!loProcRequestParams[lstrkey].ContainsKey(ServerSetting.TotalItems[i].RemoteTageName))
                                {
                                    loProcRequestParams[lstrkey].Add(ServerSetting.TotalItems[i].RemoteTageName, new List<int>());
                                }
                                loProcRequestParams[lstrkey][ServerSetting.TotalItems[i].RemoteTageName].Add(i);
                                this.ToReadItems.Add(ServerSetting.TotalItems[i].Key, ServerSetting.TotalItems[i]);

                                if (ServerSetting.TotalItems[i].BHItemType == ItemSetting.BH_ITEM_TYPE.VIB)
                                {
                                    String lstrInnerKey = ServerSetting.TotalItems[i].Company + ":"
                                                     + ServerSetting.TotalItems[i].Factory + ":"
                                                     + ServerSetting.TotalItems[i].Plant;

                                    if (!loVibRequestParams.ContainsKey(lstrInnerKey))
                                    {
                                        BH_REQUEST_KEY loParam = new BH_REQUEST_KEY();
                                        loParam.Company = ServerSetting.TotalItems[i].Company;
                                        loParam.Factory = ServerSetting.TotalItems[i].Factory;
                                        loParam.Plant = ServerSetting.TotalItems[i].Plant;
                                        loParam.Items = new Dictionary<string, ItemSetting>();
                                        loVibRequestParams.Add(lstrInnerKey, loParam);
                                        loVibRequestParams[lstrInnerKey].RequestKey += ServerSetting.TotalItems[i].RemoteTageName;
                                    }
                                    else
                                    {
                                        loVibRequestParams[lstrInnerKey].RequestKey += "," + ServerSetting.TotalItems[i].RemoteTageName;
                                    }

                                    if (!loVibRequestParams[lstrInnerKey].Items.ContainsKey(ServerSetting.TotalItems[i].RemoteTageName))
                                    {
                                        loVibRequestParams[lstrInnerKey].Items[ServerSetting.TotalItems[i].RemoteTageName] = (ServerSetting.TotalItems[i]);
                                    }

                                }
                                else if (ServerSetting.TotalItems[i].BHItemType == ItemSetting.BH_ITEM_TYPE.DYN)
                                {
                                    String lstrInnerKey = ServerSetting.TotalItems[i].Company + ":"
                                                         + ServerSetting.TotalItems[i].Factory + ":"
                                                         + ServerSetting.TotalItems[i].Plant;

                                    if (!loDynRequestParams.ContainsKey(lstrInnerKey))
                                    {
                                        BH_REQUEST_KEY loParam = new BH_REQUEST_KEY();
                                        loParam.Company = ServerSetting.TotalItems[i].Company;
                                        loParam.Factory = ServerSetting.TotalItems[i].Factory;
                                        loParam.Plant = ServerSetting.TotalItems[i].Plant;
                                        loParam.Items = new Dictionary<string, ItemSetting>();
                                        loDynRequestParams.Add(lstrInnerKey, loParam);
                                        loDynRequestParams[lstrInnerKey].RequestKey += ServerSetting.TotalItems[i].RemoteTageName;
                                    }
                                    else
                                    {
                                        loDynRequestParams[lstrInnerKey].RequestKey += "," + ServerSetting.TotalItems[i].RemoteTageName;
                                    }

                                    if (!loDynRequestParams[lstrInnerKey].Items.ContainsKey(ServerSetting.TotalItems[i].RemoteTageName))
                                    {
                                        loDynRequestParams[lstrInnerKey].Items[ServerSetting.TotalItems[i].RemoteTageName] = (ServerSetting.TotalItems[i]);
                                    }
                                }
                            }

                        }

                        Dictionary<String, ItemSetting> loCalculatedRemoteItems = new Dictionary<String, ItemSetting>();

                        foreach (var Item in this.CalculatedItems)
                        {
                            String lstrComputeKey = Item.Value.Company + "." + Item.Value.Factory + "." + Item.Value.Plant + "." + Item.Value.RemoteTageName;
                            loCalculatedRemoteItems.Add(lstrComputeKey, Item.Value);
                        }

                        Dictionary<int, byte[]> loTest = new Dictionary<int, byte[]>();

                        while (!this.ShouldStop)
                        {
                            if (lbShouldDoRead)
                            {
                                lnTictLast = System.Environment.TickCount;

                                Boolean lbConnected = false;


                                try
                                {
                                    lbConnected = true;
                                }
                                catch (System.Exception ex)
                                {
                                    ThreadUiController.log("ConnectBHServer Failed: " + ex.Message, ThreadUiController.LOG_LEVEL.FATAL);
                                    Debug.Assert(false);
                                }

                                Boolean lbCheckUpdate = this.ServerSetting.CheckSourceDataUpdate;
                                Boolean lbCheckMiddleWareValid = this.ServerSetting.CheckSourceMiddlewareValid;



                                if (lbConnected)
                                {

                                    try
                                    {
                                        Dictionary<String, int> loBeInValid = new Dictionary<string, int>();

                                        //1.read single data
                                        foreach (KeyValuePair<string, SortedDictionary<string, List<int>>> lpValue in loProcRequestParams)
                                        {
                                            loFixComm.CreateHead(20026);
                                            string[] lpKeys = lpValue.Key.Split(ConstantValueHolder.SPLITER.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                                            String lstrCompany = (lpKeys[0]);
                                            String lstrFactory = (lpKeys[1]);
                                            String lstrPlant = (lpKeys[2]);

                                            loFixComm.SetItem(15004, lstrCompany);
                                            loFixComm.SetItem(15003, lstrFactory);
                                            loFixComm.SetItem(10013, lstrPlant);
                                            SortedDictionary<string, List<int>> loAllChannsInPlant = new SortedDictionary<string, List<int>>();

                                            String lstrInnerCompanyKey = lstrCompany.Trim() + "."
                                                            + lstrFactory.Trim() + "."
                                                            + lstrPlant.Trim();

                                            StringBuilder loSb = new StringBuilder();
                                            foreach (KeyValuePair<string, List<int>> loData in lpValue.Value)
                                            {
                                                loAllChannsInPlant.Add(loData.Key, loData.Value);
                                            }
                                            Boolean lbGet = false;
                                            while (loFixComm.More())
                                            {
                                                string lstrChann = loFixComm.Get(10014);
                                                float lfChannValue = (float)loFixComm.GetDouble(10020);
                                                string lstrTime = loFixComm.GetTime(10009).ToString();
                                                int lnStateValid = (int)loFixComm.GetLong(10162);
                                                int lnUpdated = (int)loFixComm.GetLong(16050);
                                                if (lnUpdated != 0)
                                                {
                                                    lnStateValid = lnUpdated;
                                                }

                                                loSb = new StringBuilder();
                                                loSb.Append(lstrInnerCompanyKey);
                                                loSb.Append(".");
                                                loSb.Append(lstrChann);
                                                String lstrKey = loSb.ToString();

                                                if (lpValue.Value.ContainsKey(lstrChann) && !loCalculatedRemoteItems.ContainsKey(lstrKey))
                                                {
                                                    if (!loBeInValid.ContainsKey(lstrKey))
                                                    {
                                                        if (lnStateValid != 1)
                                                        {
                                                            loBeInValid.Add(lstrKey, lnStateValid);
                                                        }
                                                    }

                                                    for (int i = 0; i < lpValue.Value[lstrChann].Count; i++)
                                                    {
                                                        int lnIndex = lpValue.Value[lstrChann][i];

                                                        this.m_oServerSetting.TotalItems[lnIndex].Value = lfChannValue;
                                                        if (lnStateValid != 1 && lbCheckMiddleWareValid)
                                                        {
                                                            this.m_oServerSetting.TotalItems[lnIndex].SourceStatus = Opc.Da.qualityBits.badWaitingForInitialData;
                                                            //this.m_oServerSetting.TotalItems[lnIndex].Quality = Opc.Da.Quality.Bad;

                                                        }
                                                        else
                                                        {

                                                            this.m_oServerSetting.TotalItems[lnIndex].SourceStatus = Opc.Da.qualityBits.good;
                                                            this.m_oServerSetting.TotalItems[lnIndex].Quality = Opc.Da.Quality.Good;
                                                        }

                                                        if (this.m_oServerSetting.TotalItems[lnIndex].LastUpdateTime >= this.m_oServerSetting.TotalItems[lnIndex].UpdateTime && ServerSetting.CheckSourceDataUpdate)
                                                        {
                                                            this.m_oServerSetting.TotalItems[lnIndex].SourceStatus = Opc.Da.qualityBits.badLastKnownValue;
                                                        }

                                                        this.m_oServerSetting.TotalItems[lnIndex].LastUpdateTime = this.m_oServerSetting.TotalItems[lnIndex].UpdateTime;
                                                        this.m_oServerSetting.TotalItems[lnIndex].UpdateTime = System.DateTime.Parse(lstrTime);

                                                        this.m_oServerSetting.TotalItems[lnIndex].UpdateCount++;
                                                    }//for (int i = 0; i < lpValue.Value[lstrChann].Count; i++)
                                                    loAllChannsInPlant.Remove(lstrChann);

                                                }//if (lpValue.Value.ContainsKey(lstrChann))
                                                lbGet = true;

                                            }//while (loFixComm.More() > 0)

                                            if (!lbGet)
                                            {
                                                Thread.Sleep(100);
                                            }

                                            foreach (KeyValuePair<string, List<int>> lpPair in loAllChannsInPlant)
                                            {
                                                for (int i = 0; i < lpPair.Value.Count; i++)
                                                {
                                                    int lnIndex = lpPair.Value[i];
                                                    this.m_oServerSetting.TotalItems[lnIndex].SourceStatus = Opc.Da.qualityBits.badCommFailure;
                                                    // this.m_oServerSetting.TotalItems[lnIndex].Quality = Opc.Da.Quality.Bad;
                                                }

                                            }
                                        }//foreach (KeyValuePair<string, SortedDictionary<string, List<int>>> lpValue in loChanns)

                                        //2.Read buffer item
                                        //2.1 vib     SERVICE_SERVICE_ON_GETWAVE                20007
                                        foreach (KeyValuePair<String, BH_REQUEST_KEY> loRequest in loVibRequestParams)
                                        {

                                            string lstrChanns = loRequest.Value.RequestKey;
                                            int lnChannNum = loRequest.Value.Items.Count;
                                            byte[] lpChanns = System.Text.Encoding.GetEncoding("GBK").GetBytes(lstrChanns);
                                            object lobjChanns = (object)lpChanns;
                                            int lnChannBufferLength = lpChanns.Length;

                                            int lnWaveLength = 16384;
                                            int lnFreqLines = 6400;
                                            loFixComm.CreateHead(20007);
                                            loFixComm.SetItem(15004, loRequest.Value.m_strCompany);
                                            loFixComm.SetItem(15003, loRequest.Value.m_strFactory);
                                            loFixComm.SetItem(10013, loRequest.Value.m_strPlant);
                                            loFixComm.SetItem(10023, lnWaveLength);
                                            loFixComm.SetItem(10025, lnFreqLines);
                                            loFixComm.Set(10016, lpChanns);
                                            loFixComm.SetItem(10017, lnChannBufferLength);
                                            loFixComm.SetItem(10018, lnChannNum);

                                            while (loFixComm.More())
                                            {
                                                string lstrChann = loFixComm.Get(10014);
                                                int lnBufferSize = loFixComm.GetInt(10023) * sizeof(Int16);
                                                byte[] loBuffer = (byte[])loFixComm.GetBuffer(10080);
                                                string lstrTime = loFixComm.GetTime(10009).ToString();
                                                if (loRequest.Value.Items.ContainsKey(lstrChann))
                                                {
                                                    //                                             double[] ldblData = ThreadBHCollector.convertByteArrayTodoubleArray(loBuffer,typeof(System.Int16),0.1,0);
                                                    loRequest.Value.Items[lstrChann].Buffer = (byte[])loBuffer.Clone();
                                                    //loRequest.Value.Items[lstrChann].LastUpdateTime = loRequest.Value.Items[lstrChann].UpdateTime;
                                                    loRequest.Value.Items[lstrChann].UpdateTime = System.DateTime.Parse(lstrTime);
                                                }
                                            }
                                        }
                                        //2.2 dyn     SERVICE_SERVICE_ON_GETRODSINKDATA       20016
                                        foreach (KeyValuePair<String, BH_REQUEST_KEY> loRequest in loDynRequestParams)
                                        {

                                            string lstrChanns = loRequest.Value.RequestKey;
                                            int lnChannNum = loRequest.Value.Items.Count;
                                            byte[] lpChanns = System.Text.Encoding.GetEncoding("GBK").GetBytes(lstrChanns);
                                            object lobjChanns = (object)lpChanns;
                                            int lnChannBufferLength = lpChanns.Length;

                                            int lnWaveLength = 16384;
                                            int lnFreqLines = 6400;
                                            loFixComm.CreateHead(20016);
                                            loFixComm.SetItem(15004, loRequest.Value.m_strCompany);
                                            loFixComm.SetItem(15003, loRequest.Value.m_strFactory);
                                            loFixComm.SetItem(10013, loRequest.Value.m_strPlant);
                                            loFixComm.SetItem(10023, lnWaveLength);
                                            loFixComm.SetItem(10025, lnFreqLines);
                                            loFixComm.Set(10016, lpChanns);
                                            loFixComm.SetItem(10017, lnChannBufferLength);
                                            loFixComm.SetItem(10018, lnChannNum);
                                            while (loFixComm.More())
                                            {
                                                string lstrChann = loFixComm.Get(10014);
                                                int lnBufferSize = loFixComm.GetInt(10023);
                                                byte[] loBuffer = (byte[])loFixComm.GetBuffer(10080);
                                                string lstrTime = loFixComm.GetTime(10009).ToString();
                                                if (loRequest.Value.Items.ContainsKey(lstrChann))
                                                {
                                                    loRequest.Value.Items[lstrChann].Buffer = (byte[])loBuffer.Clone();
                                                    //loRequest.Value.Items[lstrChann].LastUpdateTime = loRequest.Value.Items[lstrChann].UpdateTime;
                                                    loRequest.Value.Items[lstrChann].UpdateTime = System.DateTime.Parse(lstrTime);
                                                }
                                            }
                                        }


                                        //     ThreadUiController.log("0", ThreadUiController.LOG_LEVEL.FATAL);


                                        //3.calculate buffer data
                                        foreach (KeyValuePair<String, ItemSetting> lpCalculatedItemPair in this.CalculatedItems)
                                        {
                                            ItemSetting lpCalculatedItem = lpCalculatedItemPair.Value;

                                            if (null == lpCalculatedItem
                                                || lpCalculatedItem.ItemType == 0
                                                || String.IsNullOrEmpty(lpCalculatedItem.ScriptContent))
                                            {
                                                Debug.Assert(false);
                                                // ThreadUiController.log("1", ThreadUiController.LOG_LEVEL.FATAL);
                                                continue;
                                            }
                                            List<object> loArgs = new List<object>();
                                            System.DateTime loDatetime = System.DateTime.MinValue;

                                            Boolean lbAnyValueUpdated = false;

                                            Boolean lbIsServerValid = true;

                                            if (lpCalculatedItem.Vars != null && lpCalculatedItem.Vars.Count > 0)
                                            {
                                                foreach (string lstrVarKey in lpCalculatedItem.Vars)
                                                {
                                                    if (!this.ToReadItems.ContainsKey(lstrVarKey))
                                                    {
                                                        // Debug.Assert(false);
                                                        //    ThreadUiController.log("2", ThreadUiController.LOG_LEVEL.FATAL);
                                                        continue;
                                                    }
                                                    ItemSetting lpItemArg = this.ToReadItems[lstrVarKey];


                                                    if (null == lpItemArg)
                                                    {
                                                        continue;
                                                    }

                                                    if (lpItemArg.Quality != Opc.Da.Quality.Good)
                                                    {                                            // continue;
                                                        lbIsServerValid = false;
                                                    }

                                                    if (loDatetime < lpItemArg.UpdateTime)
                                                    {
                                                        loDatetime = lpItemArg.UpdateTime;
                                                    }

                                                    if (lpItemArg.LastUpdateTime < lpItemArg.UpdateTime)
                                                    {
                                                        lbAnyValueUpdated = true;
                                                    }

                                                    object loValue = lpItemArg.Value;
                                                    if (lpCalculatedItem.VariableTypes.ContainsKey(lstrVarKey))
                                                    {
                                                        if (lpCalculatedItem.VariableTypes[lstrVarKey] != ItemSetting.BH_ITEM_TYPE.PROC)
                                                        {
                                                            if (lpItemArg.Buffer != null)
                                                            {
                                                                double[] ldblData = ThreadBHCollector.convertByteArrayTodoubleArray(lpItemArg.Buffer, typeof(System.Int16), 0.1, 0);
                                                                loValue = ldblData;

                                                            }
                                                            else
                                                            {
                                                                loValue = new double[0];
                                                            }

                                                        }

                                                    }
                                                    loArgs.Add(loValue);
                                                }
                                            }
                                            else
                                            {
                                                lbAnyValueUpdated = true;
                                            }

                                            if ((!lbAnyValueUpdated) && ServerSetting.CheckSourceDataUpdate)
                                            {
                                                // ThreadUiController.log("4:" + lbAnyValueUpdated + ":" + lbIsServerValid + ":" + ServerSetting.CheckSourceDataUpdate, ThreadUiController.LOG_LEVEL.ERROR);
                                                lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                                                lpCalculatedItem.SourceStatus = Opc.Da.qualityBits.badLastKnownValue;
                                                lpCalculatedItem.BHQuality = Opc.Da.Quality.Bad;
                                                lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                                                continue;
                                            }

                                            if ((!lbIsServerValid) && ServerSetting.CheckSourceMiddlewareValid)
                                            {
                                                // ThreadUiController.log("4:" + lbAnyValueUpdated + ":" + lbIsServerValid + ":" + ServerSetting.CheckSourceDataUpdate, ThreadUiController.LOG_LEVEL.ERROR);
                                                lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                                                lpCalculatedItem.SourceStatus = Opc.Da.qualityBits.badWaitingForInitialData;
                                                lpCalculatedItem.BHQuality = Opc.Da.Quality.Bad;
                                                lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                                                continue;
                                            }


                                            string lstrScript = lpCalculatedItem.ScriptContent;
                                            object[] loArgObjs = loArgs.ToArray();
                                            String lstrError = "";
                                            List<System.CodeDom.Compiler.CompilerError> loErrors = null;
                                            object loRetValue = ScriptingInterface.CompilerRunner.Run(lstrScript, loArgObjs, ref lstrError, ref loErrors);
                                            // ThreadUiController.log("5", ThreadUiController.LOG_LEVEL.FATAL);

                                            if (loRetValue == null)
                                            {
                                                try
                                                {

                                                    if (loErrors != null)
                                                    {
                                                        foreach (var error in loErrors)
                                                        {

                                                            //     ThreadUiController.log("5.4:" + error.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                                                        }

                                                    }


                                                    // ThreadUiController.log("5.0:" + loArgs.Count, ThreadUiController.LOG_LEVEL.FATAL);

                                                    // ThreadUiController.log("5.0.1:" + lstrScript, ThreadUiController.LOG_LEVEL.FATAL);*/
                                                }
                                                catch (Exception e)
                                                {
                                                    ThreadUiController.log("5.1:" + loArgs.Count, ThreadUiController.LOG_LEVEL.FATAL);
                                                    ThreadUiController.log("5.2:" + e.StackTrace, ThreadUiController.LOG_LEVEL.FATAL);
                                                    ThreadUiController.log("5.3:" + e.Message, ThreadUiController.LOG_LEVEL.FATAL);
                                                    ScriptingInterface.CompilerRunner.clearSource();

                                                }
                                            }
                                            try
                                            {
                                                double ldblValue = 0.0;
                                                if (!double.TryParse(loRetValue.ToString(), out ldblValue) || double.IsNaN(ldblValue))
                                                {
                                                    try
                                                    {
                                                        ThreadUiController.log("Custom compute error :" + lstrError, ThreadUiController.LOG_LEVEL.FATAL);
                                                        this.m_nErrorCount++;
#if DEBUG
#else
                                                if (this.m_nErrorCount > 20)
                                                {
                                                    Thread.Sleep(10000);
                                                    ThreadUiController.ApplicationExit();
                                                }
#endif
                                                        loRetValue = 0.0;
                                                        lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                                                        lpCalculatedItem.SourceStatus = Opc.Da.Quality.Bad.QualityBits;
                                                        ScriptingInterface.CompilerRunner.clearSource();
                                                    }
                                                    catch (Exception e)
                                                    {
                                                        ThreadUiController.log("Read Data From BH Server Failed: " + e.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                                                        ScriptingInterface.CompilerRunner.clearSource();

                                                    }
                                                }
                                                else
                                                {
                                                    // ThreadUiController.log("6", ThreadUiController.LOG_LEVEL.FATAL);
                                                    loRetValue = ldblValue * lpCalculatedItem.K + lpCalculatedItem.B;
                                                    lpCalculatedItem.Quality = Opc.Da.Quality.Good;
                                                    lpCalculatedItem.SourceStatus = Opc.Da.Quality.Good.QualityBits;
                                                    lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                                                    lpCalculatedItem.UpdateTime = loDatetime;
                                                    // ThreadUiController.log("7", ThreadUiController.LOG_LEVEL.FATAL);

                                                }
                                                lpCalculatedItem.UpdateCount++;
                                            }
                                            catch (System.Exception ex)
                                            {
                                                Debug.WriteLine(ex.Message);
                                                ThreadUiController.log("8:", ThreadUiController.LOG_LEVEL.FATAL);
                                                ThreadUiController.log("Read Data From BH Server Failed: " + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                                                ScriptingInterface.CompilerRunner.clearSource();

                                                lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                                                lpCalculatedItem.SourceStatus = Opc.Da.qualityBits.badOutOfService;
                                                lpCalculatedItem.BHQuality = Opc.Da.Quality.Bad;
                                                lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                                                continue;
                                            }
                                            lpCalculatedItem.Value = loRetValue;
                                            // ThreadUiController.log("10:", ThreadUiController.LOG_LEVEL.FATAL);
                                        }// foreach (KeyValuePair<String, ItemSetting> lpCalculatedItemPair in this.CalculatedItems)
                                    }
                                    catch (System.Exception ex)
                                    {
                                        for (int i = 0; i < this.ServerSetting.TotalItems.Count; i++)
                                        {
                                            this.ServerSetting.TotalItems[i].SourceStatus = qualityBits.badNotConnected;
                                        }
                                        ThreadUiController.log("9:", ThreadUiController.LOG_LEVEL.FATAL);
                                        ThreadUiController.log("Read Data From BH Server Failed: " + ex.StackTrace, ThreadUiController.LOG_LEVEL.FATAL);
                                        ThreadUiController.log("Read Data From BH Server Failed: " + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                                        Debug.Assert(false);


                                    }
                                } // if (lbConnected)
                                else
                                {
                                    for (int i = 0; i < this.ServerSetting.TotalItems.Count; i++)
                                    {
                                        this.ServerSetting.TotalItems[i].SourceStatus = qualityBits.badNotConnected;
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
                                int lnShouldSleepCount = lnTictLimit - lnTictCount;
                                Thread.Sleep(lnTictLimit);
                                lbShouldDoRead = false;
                            }
                            else
                            {
                                lbShouldDoRead = true;
                            }

                            try
                            {
                                Thread.Sleep(this.m_oServerSetting.TimeInterval);
                            }
                            catch (Exception e)
                            {
                                ThreadUiController.log("ReadBH Failed: " + e.Message, ThreadUiController.LOG_LEVEL.FATAL);
                                Debug.Assert(false);
                            }


                        }// while (!this.ShouldStop)
                    }
                    catch (System.Exception ex)
                    {
                        ThreadUiController.log("ReadBH Failed: " + ex.Message, ThreadUiController.LOG_LEVEL.FATAL);
                        Debug.Assert(false);
                    }
                }
            }
            catch (System.Exception ex)
            {
                ThreadUiController.log("ReadBH Failed: " + ex.Message, ThreadUiController.LOG_LEVEL.FATAL);
                Debug.Assert(false);
            }

        }

        private void ReadBH()
        {
            try
            {
                Boolean lbShouldDoRead = true;
                int lnTictLimit = 300;
                int lnTictCount = 0;
                int lnTictLast = 0;

                String lstrkey = "";
                SortedDictionary<string, SortedDictionary<string, List<int>>> loProcRequestParams
                    = new SortedDictionary<string, SortedDictionary<string, List<int>>>();
                this.m_oCalculatedItems.Clear();
                this.ToReadItems.Clear();
                Dictionary<String, BH_REQUEST_KEY> loVibRequestParams = new Dictionary<String, BH_REQUEST_KEY>();
                Dictionary<String, BH_REQUEST_KEY> loDynRequestParams = new Dictionary<String, BH_REQUEST_KEY>();
                for (int i = 0; i < ServerSetting.TotalItems.Count; i++)
                {
                    (ServerSetting.TotalItems[i]).LastUpdateTime = DateTime.Now;

                    if (ServerSetting.TotalItems[i].ItemType != 0)
                    {
                        this.CalculatedItems.Add(ServerSetting.TotalItems[i].Key, ServerSetting.TotalItems[i]);

                    }
                    else
                    {
                        lstrkey = ServerSetting.TotalItems[i].Company
                            + ConstantValueHolder.SPLITER + ServerSetting.TotalItems[i].Factory
                            + ConstantValueHolder.SPLITER + ServerSetting.TotalItems[i].Plant;

                        if (!loProcRequestParams.ContainsKey(lstrkey))
                        {
                            SortedDictionary<string, List<int>> loTemp
                                 = new SortedDictionary<string, List<int>>();
                            loProcRequestParams.Add(lstrkey, loTemp);
                        }

                        if (!loProcRequestParams[lstrkey].ContainsKey(ServerSetting.TotalItems[i].RemoteTageName))
                        {
                            loProcRequestParams[lstrkey].Add(ServerSetting.TotalItems[i].RemoteTageName, new List<int>());
                        }
                        loProcRequestParams[lstrkey][ServerSetting.TotalItems[i].RemoteTageName].Add(i);
                        this.ToReadItems.Add(ServerSetting.TotalItems[i].Key, ServerSetting.TotalItems[i]);

                        if (ServerSetting.TotalItems[i].BHItemType == ItemSetting.BH_ITEM_TYPE.VIB)
                        {
                            String lstrInnerKey = ServerSetting.TotalItems[i].Company + ":"
                                             + ServerSetting.TotalItems[i].Factory + ":"
                                             + ServerSetting.TotalItems[i].Plant;

                            if (!loVibRequestParams.ContainsKey(lstrInnerKey))
                            {
                                BH_REQUEST_KEY loParam = new BH_REQUEST_KEY();
                                loParam.Company = ServerSetting.TotalItems[i].Company;
                                loParam.Factory = ServerSetting.TotalItems[i].Factory;
                                loParam.Plant = ServerSetting.TotalItems[i].Plant;
                                loParam.Items = new Dictionary<string, ItemSetting>();
                                loVibRequestParams.Add(lstrInnerKey, loParam);
                                loVibRequestParams[lstrInnerKey].RequestKey += ServerSetting.TotalItems[i].RemoteTageName;
                            }
                            else
                            {
                                loVibRequestParams[lstrInnerKey].RequestKey += "," + ServerSetting.TotalItems[i].RemoteTageName;
                            }

                            if (!loVibRequestParams[lstrInnerKey].Items.ContainsKey(ServerSetting.TotalItems[i].RemoteTageName))
                            {
                                loVibRequestParams[lstrInnerKey].Items[ServerSetting.TotalItems[i].RemoteTageName] = (ServerSetting.TotalItems[i]);
                            }

                        }
                        else if (ServerSetting.TotalItems[i].BHItemType == ItemSetting.BH_ITEM_TYPE.DYN)
                        {
                            String lstrInnerKey = ServerSetting.TotalItems[i].Company + ":"
                                                 + ServerSetting.TotalItems[i].Factory + ":"
                                                 + ServerSetting.TotalItems[i].Plant;

                            if (!loDynRequestParams.ContainsKey(lstrInnerKey))
                            {
                                BH_REQUEST_KEY loParam = new BH_REQUEST_KEY();
                                loParam.Company = ServerSetting.TotalItems[i].Company;
                                loParam.Factory = ServerSetting.TotalItems[i].Factory;
                                loParam.Plant = ServerSetting.TotalItems[i].Plant;
                                loParam.Items = new Dictionary<string, ItemSetting>();
                                loDynRequestParams.Add(lstrInnerKey, loParam);
                                loDynRequestParams[lstrInnerKey].RequestKey += ServerSetting.TotalItems[i].RemoteTageName;
                            }
                            else
                            {
                                loDynRequestParams[lstrInnerKey].RequestKey += "," + ServerSetting.TotalItems[i].RemoteTageName;
                            }

                            if (!loDynRequestParams[lstrInnerKey].Items.ContainsKey(ServerSetting.TotalItems[i].RemoteTageName))
                            {
                                loDynRequestParams[lstrInnerKey].Items[ServerSetting.TotalItems[i].RemoteTageName] = (ServerSetting.TotalItems[i]);
                            }
                        }
                    }

                }

                Dictionary<String, ItemSetting> loCalculatedRemoteItems = new Dictionary<String, ItemSetting>();

                foreach (var Item in this.CalculatedItems)
                {
                    String lstrComputeKey = Item.Value.Company + "." + Item.Value.Factory + "." + Item.Value.Plant + "." + Item.Value.RemoteTageName;
                    loCalculatedRemoteItems.Add(lstrComputeKey, Item.Value);
                }

                Dictionary<int, byte[]> loTest = new Dictionary<int, byte[]>();

                while (!this.ShouldStop)
                {
                    if (lbShouldDoRead)
                    {
                        lnTictLast = System.Environment.TickCount;

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

                        Boolean lbCheckUpdate = this.ServerSetting.CheckSourceDataUpdate;
                        Boolean lbCheckMiddleWareValid = this.ServerSetting.CheckSourceMiddlewareValid;



                        if (lbConnected)
                        {

                            try
                            {
                                Dictionary<String, int> loBeInValid = new Dictionary<string, int>();

                                //1.read single data
                                foreach (KeyValuePair<string, SortedDictionary<string, List<int>>> lpValue in loProcRequestParams)
                                {
                                    this.m_pFixComm.CreateHead(20026);
                                    string[] lpKeys = lpValue.Key.Split(ConstantValueHolder.SPLITER.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                                    String lstrCompany = (lpKeys[0]);
                                    String lstrFactory = (lpKeys[1]);
                                    String lstrPlant = (lpKeys[2]);

                                    this.m_pFixComm.SetItemString(15004, ref lstrCompany);
                                    this.m_pFixComm.SetItemString(15003, ref lstrFactory);
                                    this.m_pFixComm.SetItemString(10013, ref lstrPlant);
                                    SortedDictionary<string, List<int>> loAllChannsInPlant = new SortedDictionary<string, List<int>>();

                                    String lstrInnerCompanyKey = lstrCompany.Trim() + "."
                                                    + lstrFactory.Trim() + "."
                                                    + lstrPlant.Trim();

                                    StringBuilder loSb = new StringBuilder();
                                    foreach (KeyValuePair<string, List<int>> loData in lpValue.Value)
                                    {
                                        loAllChannsInPlant.Add(loData.Key, loData.Value);
                                    }
                                    Boolean lbGet = false;
                                    while (this.m_pFixComm.More() > 0)
                                    {
                                        string lstrChann = this.m_pFixComm.GetItem(10014);
                                        float lfChannValue = (float)this.m_pFixComm.GetDouble(10020);
                                        string lstrTime = this.m_pFixComm.GetTime(10009);
                                        int lnStateValid = this.m_pFixComm.GetLong(10162);
                                        int lnUpdated = this.m_pFixComm.GetLong(16050);
                                        if (lnUpdated != 0)
                                        {
                                            lnStateValid = lnUpdated;
                                        }

                                        loSb = new StringBuilder();
                                        loSb.Append(lstrInnerCompanyKey);
                                        loSb.Append(".");
                                        loSb.Append(lstrChann);
                                        String lstrKey = loSb.ToString();

                                        if (lpValue.Value.ContainsKey(lstrChann) && !loCalculatedRemoteItems.ContainsKey(lstrKey))
                                        {
                                            if (!loBeInValid.ContainsKey(lstrKey))
                                            {
                                                if (lnStateValid != 1)
                                                {
                                                    loBeInValid.Add(lstrKey, lnStateValid);
                                                }
                                            }

                                            for (int i = 0; i < lpValue.Value[lstrChann].Count; i++)
                                            {
                                                int lnIndex = lpValue.Value[lstrChann][i];

                                                this.m_oServerSetting.TotalItems[lnIndex].Value = lfChannValue;
                                                if (lnStateValid != 1 && lbCheckMiddleWareValid)
                                                {
                                                    this.m_oServerSetting.TotalItems[lnIndex].SourceStatus = Opc.Da.qualityBits.badWaitingForInitialData;
                                                    //this.m_oServerSetting.TotalItems[lnIndex].Quality = Opc.Da.Quality.Bad;

                                                }
                                                else
                                                {

                                                    this.m_oServerSetting.TotalItems[lnIndex].SourceStatus = Opc.Da.qualityBits.good;
                                                    this.m_oServerSetting.TotalItems[lnIndex].Quality = Opc.Da.Quality.Good;
                                                }

                                                if (this.m_oServerSetting.TotalItems[lnIndex].LastUpdateTime >= this.m_oServerSetting.TotalItems[lnIndex].UpdateTime && ServerSetting.CheckSourceDataUpdate)
                                                {
                                                    this.m_oServerSetting.TotalItems[lnIndex].SourceStatus = Opc.Da.qualityBits.badLastKnownValue;
                                                }

                                                this.m_oServerSetting.TotalItems[lnIndex].LastUpdateTime = this.m_oServerSetting.TotalItems[lnIndex].UpdateTime;
                                                this.m_oServerSetting.TotalItems[lnIndex].UpdateTime = System.DateTime.Parse(lstrTime);

                                                this.m_oServerSetting.TotalItems[lnIndex].UpdateCount++;
                                            }//for (int i = 0; i < lpValue.Value[lstrChann].Count; i++)
                                            loAllChannsInPlant.Remove(lstrChann);

                                        }//if (lpValue.Value.ContainsKey(lstrChann))
                                        lbGet = true;

                                    }//while (this.m_pFixComm.More() > 0)

                                    if (!lbGet)
                                    {
                                        Thread.Sleep(100);
                                    }

                                    foreach (KeyValuePair<string, List<int>> lpPair in loAllChannsInPlant)
                                    {
                                        for (int i = 0; i < lpPair.Value.Count; i++)
                                        {
                                            int lnIndex = lpPair.Value[i];
                                            this.m_oServerSetting.TotalItems[lnIndex].SourceStatus = Opc.Da.qualityBits.badCommFailure;
                                            // this.m_oServerSetting.TotalItems[lnIndex].Quality = Opc.Da.Quality.Bad;
                                        }

                                    }
                                }//foreach (KeyValuePair<string, SortedDictionary<string, List<int>>> lpValue in loChanns)

                                //2.Read buffer item
                                //2.1 vib     SERVICE_SERVICE_ON_GETWAVE                20007
                                foreach (KeyValuePair<String, BH_REQUEST_KEY> loRequest in loVibRequestParams)
                                {

                                    string lstrChanns = loRequest.Value.RequestKey;
                                    int lnChannNum = loRequest.Value.Items.Count;
                                    byte[] lpChanns = System.Text.Encoding.GetEncoding("GBK").GetBytes(lstrChanns);
                                    object lobjChanns = (object)lpChanns;
                                    int lnChannBufferLength = lpChanns.Length;

                                    int lnWaveLength = 16384;
                                    int lnFreqLines = 6400;
                                    this.m_pFixComm.CreateHead(20007);
                                    this.m_pFixComm.SetItemString(15004, ref loRequest.Value.m_strCompany);
                                    this.m_pFixComm.SetItemString(15003, ref loRequest.Value.m_strFactory);
                                    this.m_pFixComm.SetItemString(10013, ref loRequest.Value.m_strPlant);
                                    this.m_pFixComm.SetItem(10023, lnWaveLength);
                                    this.m_pFixComm.SetItem(10025, lnFreqLines);
                                    this.m_pFixComm.SetItemBuf(10016, lnChannBufferLength, ref lobjChanns);
                                    this.m_pFixComm.SetItem(10017, lnChannBufferLength);
                                    this.m_pFixComm.SetItem(10018, lnChannNum);

                                    while (this.m_pFixComm.More() > 0)
                                    {
                                        string lstrChann = this.m_pFixComm.GetItem(10014);
                                        int lnBufferSize = this.m_pFixComm.GetLong(10023) * sizeof(Int16);
                                        byte[] loBuffer = (byte[])this.m_pFixComm.GetItemBuf(10080, lnBufferSize);
                                        string lstrTime = this.m_pFixComm.GetTime(10009);
                                        if (loRequest.Value.Items.ContainsKey(lstrChann))
                                        {
                                            //                                             double[] ldblData = ThreadBHCollector.convertByteArrayTodoubleArray(loBuffer,typeof(System.Int16),0.1,0);
                                            loRequest.Value.Items[lstrChann].Buffer = (byte[])loBuffer.Clone();
                                            //loRequest.Value.Items[lstrChann].LastUpdateTime = loRequest.Value.Items[lstrChann].UpdateTime;
                                            loRequest.Value.Items[lstrChann].UpdateTime = System.DateTime.Parse(lstrTime);
                                        }
                                    }
                                }
                                //2.2 dyn     SERVICE_SERVICE_ON_GETRODSINKDATA       20016
                                foreach (KeyValuePair<String, BH_REQUEST_KEY> loRequest in loDynRequestParams)
                                {

                                    string lstrChanns = loRequest.Value.RequestKey;
                                    int lnChannNum = loRequest.Value.Items.Count;
                                    byte[] lpChanns = System.Text.Encoding.GetEncoding("GBK").GetBytes(lstrChanns);
                                    object lobjChanns = (object)lpChanns;
                                    int lnChannBufferLength = lpChanns.Length;

                                    int lnWaveLength = 16384;
                                    int lnFreqLines = 6400;
                                    this.m_pFixComm.CreateHead(20016);
                                    this.m_pFixComm.SetItemString(15004, ref loRequest.Value.m_strCompany);
                                    this.m_pFixComm.SetItemString(15003, ref loRequest.Value.m_strFactory);
                                    this.m_pFixComm.SetItemString(10013, ref loRequest.Value.m_strPlant);
                                    this.m_pFixComm.SetItem(10023, lnWaveLength);
                                    this.m_pFixComm.SetItem(10025, lnFreqLines);
                                    this.m_pFixComm.SetItemBuf(10016, lnChannBufferLength, ref lobjChanns);
                                    this.m_pFixComm.SetItem(10017, lnChannBufferLength);
                                    this.m_pFixComm.SetItem(10018, lnChannNum);
                                    while (this.m_pFixComm.More() > 0)
                                    {
                                        string lstrChann = this.m_pFixComm.GetItem(10014);
                                        int lnBufferSize = this.m_pFixComm.GetLong(10023);
                                        byte[] loBuffer = (byte[])this.m_pFixComm.GetItemBuf(10080, lnBufferSize);
                                        string lstrTime = this.m_pFixComm.GetTime(10009);
                                        if (loRequest.Value.Items.ContainsKey(lstrChann))
                                        {
                                            loRequest.Value.Items[lstrChann].Buffer = (byte[])loBuffer.Clone();
                                            //loRequest.Value.Items[lstrChann].LastUpdateTime = loRequest.Value.Items[lstrChann].UpdateTime;
                                            loRequest.Value.Items[lstrChann].UpdateTime = System.DateTime.Parse(lstrTime);
                                        }
                                    }
                                }


                                //     ThreadUiController.log("0", ThreadUiController.LOG_LEVEL.FATAL);


                                //3.calculate buffer data
                                foreach (KeyValuePair<String, ItemSetting> lpCalculatedItemPair in this.CalculatedItems)
                                {
                                    ItemSetting lpCalculatedItem = lpCalculatedItemPair.Value;

                                    if (null == lpCalculatedItem
                                        || lpCalculatedItem.ItemType == 0
                                        || String.IsNullOrEmpty(lpCalculatedItem.ScriptContent))
                                    {
                                        Debug.Assert(false);
                                        // ThreadUiController.log("1", ThreadUiController.LOG_LEVEL.FATAL);
                                        continue;
                                    }
                                    List<object> loArgs = new List<object>();
                                    System.DateTime loDatetime = System.DateTime.MinValue;

                                    Boolean lbAnyValueUpdated = false;

                                    Boolean lbIsServerValid = true;

                                    if (lpCalculatedItem.Vars != null && lpCalculatedItem.Vars.Count > 0)
                                    {
                                        foreach (string lstrVarKey in lpCalculatedItem.Vars)
                                        {
                                            if (!this.ToReadItems.ContainsKey(lstrVarKey))
                                            {
                                                // Debug.Assert(false);
                                                //    ThreadUiController.log("2", ThreadUiController.LOG_LEVEL.FATAL);
                                                continue;
                                            }
                                            ItemSetting lpItemArg = this.ToReadItems[lstrVarKey];


                                            if (null == lpItemArg)
                                            {
                                                continue;
                                            }

                                            if (lpItemArg.Quality != Opc.Da.Quality.Good)
                                            {                                            // continue;
                                                lbIsServerValid = false;
                                            }

                                            if (loDatetime < lpItemArg.UpdateTime)
                                            {
                                                loDatetime = lpItemArg.UpdateTime;
                                            }

                                            if (lpItemArg.LastUpdateTime < lpItemArg.UpdateTime)
                                            {
                                                lbAnyValueUpdated = true;
                                            }

                                            object loValue = lpItemArg.Value;
                                            if (lpCalculatedItem.VariableTypes.ContainsKey(lstrVarKey))
                                            {
                                                if (lpCalculatedItem.VariableTypes[lstrVarKey] != ItemSetting.BH_ITEM_TYPE.PROC)
                                                {
                                                    if (lpItemArg.Buffer != null)
                                                    {
                                                        double[] ldblData = ThreadBHCollector.convertByteArrayTodoubleArray(lpItemArg.Buffer, typeof(System.Int16), 0.1, 0);
                                                        loValue = ldblData;

                                                    }
                                                    else
                                                    {
                                                        loValue = new double[0];
                                                    }

                                                }

                                            }
                                            loArgs.Add(loValue);
                                        }
                                    }
                                    else
                                    {
                                        lbAnyValueUpdated = true;
                                    }

                                    if ((!lbAnyValueUpdated) && ServerSetting.CheckSourceDataUpdate)
                                    {
                                        // ThreadUiController.log("4:" + lbAnyValueUpdated + ":" + lbIsServerValid + ":" + ServerSetting.CheckSourceDataUpdate, ThreadUiController.LOG_LEVEL.ERROR);
                                        lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                                        lpCalculatedItem.SourceStatus = Opc.Da.qualityBits.badLastKnownValue;
                                        lpCalculatedItem.BHQuality = Opc.Da.Quality.Bad;
                                        lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                                        continue;
                                    }

                                    if ((!lbIsServerValid) && ServerSetting.CheckSourceMiddlewareValid)
                                    {
                                        // ThreadUiController.log("4:" + lbAnyValueUpdated + ":" + lbIsServerValid + ":" + ServerSetting.CheckSourceDataUpdate, ThreadUiController.LOG_LEVEL.ERROR);
                                        lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                                        lpCalculatedItem.SourceStatus = Opc.Da.qualityBits.badWaitingForInitialData;
                                        lpCalculatedItem.BHQuality = Opc.Da.Quality.Bad;
                                        lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                                        continue;
                                    }


                                    string lstrScript = lpCalculatedItem.ScriptContent;
                                    object[] loArgObjs = loArgs.ToArray();
                                    String lstrError = "";
                                    List<System.CodeDom.Compiler.CompilerError> loErrors = null;
                                    object loRetValue = ScriptingInterface.CompilerRunner.Run(lstrScript, loArgObjs, ref lstrError, ref loErrors);
                                    // ThreadUiController.log("5", ThreadUiController.LOG_LEVEL.FATAL);

                                    if (loRetValue == null)
                                    {
                                        try
                                        {

                                            if (loErrors != null)
                                            {
                                                foreach (var error in loErrors)
                                                {

                                                    //     ThreadUiController.log("5.4:" + error.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                                                }

                                            }


                                            // ThreadUiController.log("5.0:" + loArgs.Count, ThreadUiController.LOG_LEVEL.FATAL);

                                            // ThreadUiController.log("5.0.1:" + lstrScript, ThreadUiController.LOG_LEVEL.FATAL);*/
                                        }
                                        catch (Exception e)
                                        {
                                            ThreadUiController.log("5.1:" + loArgs.Count, ThreadUiController.LOG_LEVEL.FATAL);
                                            ThreadUiController.log("5.2:" + e.StackTrace, ThreadUiController.LOG_LEVEL.FATAL);
                                            ThreadUiController.log("5.3:" + e.Message, ThreadUiController.LOG_LEVEL.FATAL);
                                            ScriptingInterface.CompilerRunner.clearSource();

                                        }
                                    }
                                    try
                                    {
                                        double ldblValue = 0.0;
                                        if (!double.TryParse(loRetValue.ToString(), out ldblValue) || double.IsNaN(ldblValue))
                                        {
                                            try
                                            {
                                                ThreadUiController.log("Custom compute error :" + lstrError, ThreadUiController.LOG_LEVEL.FATAL);
                                                this.m_nErrorCount++;
#if DEBUG
#else
                                                if (this.m_nErrorCount > 20)
                                                {
                                                    Thread.Sleep(10000);
                                                    ThreadUiController.ApplicationExit();
                                                }
#endif
                                                loRetValue = 0.0;
                                                lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                                                lpCalculatedItem.SourceStatus = Opc.Da.Quality.Bad.QualityBits;
                                                ScriptingInterface.CompilerRunner.clearSource();
                                            }
                                            catch (Exception e)
                                            {
                                                ThreadUiController.log("Read Data From BH Server Failed: " + e.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                                                ScriptingInterface.CompilerRunner.clearSource();

                                            }
                                        }
                                        else
                                        {
                                            // ThreadUiController.log("6", ThreadUiController.LOG_LEVEL.FATAL);
                                            loRetValue = ldblValue * lpCalculatedItem.K + lpCalculatedItem.B;
                                            lpCalculatedItem.Quality = Opc.Da.Quality.Good;
                                            lpCalculatedItem.SourceStatus = Opc.Da.Quality.Good.QualityBits;
                                            lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                                            lpCalculatedItem.UpdateTime = loDatetime;
                                            // ThreadUiController.log("7", ThreadUiController.LOG_LEVEL.FATAL);

                                        }
                                        lpCalculatedItem.UpdateCount++;
                                    }
                                    catch (System.Exception ex)
                                    {
                                        Debug.WriteLine(ex.Message);
                                        ThreadUiController.log("8:", ThreadUiController.LOG_LEVEL.FATAL);
                                        ThreadUiController.log("Read Data From BH Server Failed: " + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                                        ScriptingInterface.CompilerRunner.clearSource();

                                        lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                                        lpCalculatedItem.SourceStatus = Opc.Da.qualityBits.badOutOfService;
                                        lpCalculatedItem.BHQuality = Opc.Da.Quality.Bad;
                                        lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                                        continue;
                                    }
                                    lpCalculatedItem.Value = loRetValue;
                                    // ThreadUiController.log("10:", ThreadUiController.LOG_LEVEL.FATAL);
                                }// foreach (KeyValuePair<String, ItemSetting> lpCalculatedItemPair in this.CalculatedItems)
                            }
                            catch (System.Exception ex)
                            {
                                for (int i = 0; i < this.ServerSetting.TotalItems.Count; i++)
                                {
                                    this.ServerSetting.TotalItems[i].SourceStatus = qualityBits.badNotConnected;
                                }
                                ThreadUiController.log("9:", ThreadUiController.LOG_LEVEL.FATAL);
                                ThreadUiController.log("Read Data From BH Server Failed: " + ex.StackTrace, ThreadUiController.LOG_LEVEL.FATAL);
                                ThreadUiController.log("Read Data From BH Server Failed: " + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                                Debug.Assert(false);


                            }
                        } // if (lbConnected)
                        else
                        {
                            for (int i = 0; i < this.ServerSetting.TotalItems.Count; i++)
                            {
                                this.ServerSetting.TotalItems[i].SourceStatus = qualityBits.badNotConnected;
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
                        int lnShouldSleepCount = lnTictLimit - lnTictCount;
                        Thread.Sleep(lnTictLimit);
                        lbShouldDoRead = false;
                    }
                    else
                    {
                        lbShouldDoRead = true;
                    }

                    try
                    {
                        Thread.Sleep(this.m_oServerSetting.TimeInterval);
                    }
                    catch (Exception e)
                    {
                        ThreadUiController.log("ReadBH Failed: " + e.Message, ThreadUiController.LOG_LEVEL.FATAL);
                        Debug.Assert(false);
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
                    value.QualitySpecified = false;
                    value.Timestamp = System.DateTime.Now;
                    value.TimestampSpecified = false;

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
                            this.ServerSetting.TotalItems[lnIndex].DstStatus = Opc.Da.qualityBits.bad;
                        }
                        else
                        {
                            this.ServerSetting.TotalItems[lnIndex].DstStatus = Opc.Da.qualityBits.good;
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
                int lnServerType = (int)this.m_oServerSetting.BHServerTpyeSrc;
                if (lnServerType == (int)DAQ.ServerSetting.BHServerType.NEW)
                {
                    this.m_pServerReadBH = new Thread(new ThreadStart(ReadBHNewConnection));
                }
                else
                {
                    this.m_pServerReadBH = new Thread(new ThreadStart(ReadBH));
                }
                    
                this.m_pServerReadBH.IsBackground = true;
                this.m_pServerReadBH.Name = "Read Data From BH";
                this.m_pServerReadBH.Start();
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log("this.m_pServerReadBH.Start() Failed : " + ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);

            }

            if (this.m_oServerSetting.DstServerMode == Enum.GetName(typeof(DAQ.ServerSetting.DestinationServerType),
                                                                 DAQ.ServerSetting.DestinationServerType.OPC_SERVER))
            {
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
            }
            else
            {
                this._Status = COLLECTOR_STATUS.STARTED;
            }


            //3.read Data,and fire CallBack
            while (!this.ShouldStop)
            {
                int lnTimeStart = System.Environment.TickCount;

                if (this.m_oServerSetting.DstServerMode == Enum.GetName(typeof(DAQ.ServerSetting.DestinationServerType),
                                                                 DAQ.ServerSetting.DestinationServerType.OPC_SERVER))
                {
                    if (!this.WriteOpc())
                    {
                        Debug.Assert(false);
                    }
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

        Dictionary<String, ItemSetting> m_oCalculatedItems = new Dictionary<String, ItemSetting>();
        public Dictionary<String, ItemSetting> CalculatedItems
        {
            get { return m_oCalculatedItems; }
            set { m_oCalculatedItems = value; }
        }

        Dictionary<String, ItemSetting> m_oAllReadItems = new Dictionary<String, ItemSetting>();
        public Dictionary<String, ItemSetting> ToReadItems
        {
            get { return m_oAllReadItems; }
            set { m_oAllReadItems = value; }
        }


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

        int m_nErrorCount = 0;

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

                this.CalculatedItems.Clear();
                this.ToReadItems.Clear();

                foreach (ItemSetting value in this.ServerSetting.TotalItems)
                {
                    if (value.ItemType != 0)
                    {
                        this.CalculatedItems.Add(value.Key, value);
                    }
                    else
                    {
                        this.ToReadItems.Add(value.Key, value);
                    }
                    String lstrSql = "select * from IP_AnalogDef where name = '" + value.TagName + "'";
                    OdbcDataAdapter command = new OdbcDataAdapter(lstrSql, connection);
                    DataSet ds = new DataSet();
                    command.Fill(ds, "ds");
                    Boolean lbGood = false;
                    if (ds.Tables.Count > 0)
                    {
                        if (ds.Tables[0].Rows.Count > 0)
                        {
                            value.Value = (float)ds.Tables[0].Rows[0]["IP_INPUT_VALUE"];
                            value.SourceStatus = qualityBits.good;
                            value.Quality = Opc.Da.Quality.Good;
                            value.UpdateTime = System.DateTime.Now;
                            value.UpdateCount++;
                            lbGood = true;
                        }

                    }
                    if (!lbGood)
                    {
                        value.SourceStatus = qualityBits.bad;
                        value.Quality = Opc.Da.Quality.Bad;
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
                    lnItemIndex++;
                }

                foreach (KeyValuePair<String, ItemSetting> lpCalculatedItemPair in this.CalculatedItems)
                {
                    ItemSetting lpCalculatedItem = lpCalculatedItemPair.Value;

                    if (null == lpCalculatedItem
                        || lpCalculatedItem.ItemType == 0
                        || String.IsNullOrEmpty(lpCalculatedItem.ScriptContent))
                    {
                        Debug.Assert(false);
                        continue;
                    }
                    List<object> loArgs = new List<object>();

                    Boolean lbAnyArgsUpdated = false;

                    foreach (string lstrVarKey in lpCalculatedItem.Vars)
                    {
                        if (!this.ToReadItems.ContainsKey(lstrVarKey))
                        {
                            // Debug.Assert(false);
                            continue;
                        }
                        ItemSetting lpItemArg = this.ToReadItems[lstrVarKey];
                        if (null == lpItemArg)
                        {
                            //Debug.Assert(false);
                            continue;
                        }
                        object loValue = lpItemArg.Value;
                        if (lpCalculatedItem.VariableTypes.ContainsKey(lstrVarKey))
                        {
                            if (lpCalculatedItem.VariableTypes[lstrVarKey] != ItemSetting.BH_ITEM_TYPE.PROC)
                            {
                                if (lpItemArg.Buffer != null)
                                {
                                    loValue = lpItemArg.Buffer.Clone();
                                }
                                else
                                {
                                    loValue = new double[0];
                                }

                            }

                        }
                        if (lpItemArg.LastUpdateTime < lpItemArg.UpdateTime)
                        {
                            lbAnyArgsUpdated = true;
                        }
                        loArgs.Add(loValue);
                    }

                    if (!lbAnyArgsUpdated)
                    {
                        lpCalculatedItem.Quality = Opc.Da.Quality.Bad;

                        lpCalculatedItem.SourceStatus = Opc.Da.qualityBits.badLastKnownValue;

                        lpCalculatedItem.BHQuality = Opc.Da.Quality.Bad;

                        lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;

                        continue;
                    }

                    string lstrScript = lpCalculatedItem.ScriptContent;
                    object[] loArgObjs = loArgs.ToArray();
                    String lstrError = "";
                    List<System.CodeDom.Compiler.CompilerError> loErrors = null;
                    object loRetValue = ScriptingInterface.CompilerRunner.Run(lstrScript, loArgObjs, ref lstrError, ref loErrors);
                    try
                    {
                        double ldblValue = 0.0;
                        if (!double.TryParse(loRetValue.ToString(), out ldblValue) || double.IsNaN(ldblValue))
                        {
                            ThreadUiController.log("Custom compute error :" + lstrError, ThreadUiController.LOG_LEVEL.FATAL);
                            this.m_nErrorCount++;
#if DEBUG
#else
                            if (this.m_nErrorCount > 20)
                            {
                                Thread.Sleep(10000);
                                ThreadUiController.ApplicationExit();
                            }
#endif

                            loRetValue = 0.0;
                            lpCalculatedItem.Quality = Opc.Da.Quality.Bad;
                            lpCalculatedItem.SourceStatus = Opc.Da.Quality.Bad.QualityBits;
                            ScriptingInterface.CompilerRunner.clearSource();

                        }
                        else
                        {
                            loRetValue = ldblValue * lpCalculatedItem.K + lpCalculatedItem.B;
                            lpCalculatedItem.Quality = Opc.Da.Quality.Good;
                            lpCalculatedItem.SourceStatus = Opc.Da.Quality.Good.QualityBits;
                            lpCalculatedItem.LastUpdateTime = lpCalculatedItem.UpdateTime;
                            lpCalculatedItem.UpdateTime = System.DateTime.Now;

                        }
                        lpCalculatedItem.UpdateCount++;
                    }
                    catch (System.Exception ex)
                    {
                        Debug.WriteLine(ex.Message);
                    }
                    lpCalculatedItem.Value = loRetValue;
                }// foreach (KeyValuePair<String, ItemSetting> lpCalculatedItemPair in this.CalculatedItems)

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
