using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Newtonsoft;
using System.IO;
using EricZhao.UiThread;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Net;
using System.Threading;
using EricZhao;

namespace DAQ
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();


        }
        private ListViewItem[] m_oCache;           //array to cache items for the virtual list
        public ListViewItem[] Cache
        {
            get { return m_oCache; }
            set { m_oCache = value; }
        }
        private int m_nFirstItem = 0;              //stores the index of the first item in the cache
        int m_nPointLimit = 1000;

        public int PointLimit
        {
            get { return m_nPointLimit; }
            set { m_nPointLimit = value; }
        }

        private void LoadSetting()
        {
            try
            {
                byte[] loBuffer = null;

                FileStream loFileStream = new FileStream("setting.json", FileMode.OpenOrCreate);

                try
                {
                    loBuffer = new byte[loFileStream.Length];

                    loFileStream.Read(loBuffer, 0, (int)loFileStream.Length);

                    String lstrServerSetting = Encoding.UTF8.GetString(loBuffer);

                    Object loObj = Newtonsoft.Json.JsonConvert.DeserializeObject(lstrServerSetting, typeof(ServerSetting));

                    ServerSetting loSetting = (ServerSetting)loObj;

                    if (null != loSetting)
                    {
                        this.m_oServerSetting = loSetting;

                        for (int i = 0; i < this.m_oServerSetting.TotalItems.Count; i++)
                        {
                            this.m_oServerSetting.TotalItems[i].SourceStatus = Opc.Da.qualityBits.badNotConnected;
                            this.m_oServerSetting.TotalItems[i].DstStatus = Opc.Da.qualityBits.badNotConnected;
                            this.m_oServerSetting.TotalItems[i].Value = 0;
                            this.m_oServerSetting.TotalItems[i].UpdateCount = 0;
                        }

                        if (String.IsNullOrEmpty(this.m_oServerSetting.TitleName))
                        {
                            this.m_oServerSetting.TitleName = this.Text;
                        }
                        this.Text = this.m_oServerSetting.TitleName;
                        this.notifyIcon1.Text = this.m_oServerSetting.TitleName;
                    }

                    //explicit chek
                    if (loSetting.CheckSourceDataUpdate)
                    {
                        this.MenuItemForceUpdate.Checked = true;
                    }
                    else
                    {
                        this.MenuItemForceUpdate.Checked = false;
                    }

                    if (loSetting.CheckSourceMiddlewareValid)
                    {
                        this.MenuItemCheckMiddleWareValid.Checked = true;
                    }
                    else
                    {
                        this.MenuItemCheckMiddleWareValid.Checked = false;
                    }

                    if (loSetting.CheckAllValid)
                    {
                        this.MenuItemCheckAllValid.Checked = true;
                    }
                    else
                    {
                        this.MenuItemCheckAllValid.Checked = false;
                    }

                    if (loSetting.UseSendTimeStamp)
                    {
                        this.toolStripMenuItemUseSendTimeStamp.Checked = true;

                    }
                    else
                    {
                        this.toolStripMenuItemUseSendTimeStamp.Checked = false;
                    }

                   
                }
                catch (Exception e2)
                {
                    Debug.Assert(false);
                    ThreadUiController.log(e2.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                }


                loFileStream.Close();

                loFileStream.Dispose();

                this.EmptyCache();

                this.UpdateUI();
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
            }
        }
        private void SaveSetting()
        {
            try
            {
                String lstrServerSetting = Newtonsoft.Json.JsonConvert.SerializeObject
                                          (this.m_oServerSetting,
                                            Newtonsoft.Json.Formatting.Indented);

                FileStream loFileStream = new FileStream("./setting.json", FileMode.OpenOrCreate | FileMode.Truncate);

                try
                {
                    byte[] loBuffer = Encoding.UTF8.GetBytes(lstrServerSetting);

                    loFileStream.Write(loBuffer, 0, loBuffer.Length);

                    loFileStream.Flush();
                }
                catch (System.Exception e2)
                {
                    Debug.Assert(false);
                    ThreadUiController.log(e2.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                }
                loFileStream.Close();

                loFileStream.Dispose();
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
            }
        }
        private void loadSettingToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.LoadSetting();
        }

        private int GetFirstSelectedItem()
        {
            if (this.listView1.SelectedIndices.Count > 0)
            {
                return this.listView1.SelectedIndices[0];
            }
            else
            {
                return -1;
            }
        }

        private void DeleteSelected()
        {
            DialogResult lpResult = MessageBox.Show("确认删除(Sure to Delete)?", "请确认(Please Confirm)", MessageBoxButtons.OKCancel);

            if (lpResult == DialogResult.OK)
            {
                this.StopCollector();
                this.EmptyCache();
                this.listView1.BeginUpdate();


                for (int lnIndex = 0; lnIndex < this.listView1.SelectedIndices.Count; lnIndex++)
                {
                    int lnItemToDelete = this.listView1.SelectedIndices[lnIndex] - lnIndex;
                    this.m_oServerSetting.TotalItems.RemoveAt(lnItemToDelete);

                }
                this.listView1.EndUpdate();

                this.EmptyCache();
                this.UpdateUI();
                this.listView1.SelectedIndices.Clear();
            }
        }

        private void dToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.DeleteSelected();
        }

        private void toolStripMenuItemServerSetting_Click(object sender, EventArgs e)
        {
            FormServerSetting loSetting = new FormServerSetting();

            loSetting.ServerSetting.Machine = this.m_oServerSetting.Machine;
            loSetting.ServerSetting.ProgID = this.m_oServerSetting.ProgID;
            loSetting.ServerSetting.RemoteUrl = this.m_oServerSetting.RemoteUrl;
            loSetting.ServerSetting.TimeInterval = this.m_oServerSetting.TimeInterval;
            loSetting.ServerSetting.ServerPort = this.m_oServerSetting.ServerPort;
            loSetting.ServerSetting.ServerIp = this.m_oServerSetting.ServerIp;
            loSetting.ServerSetting.TransferSource = this.m_oServerSetting.TransferSource;


            loSetting.ServerSetting.DstMachine = this.m_oServerSetting.DstMachine;
            loSetting.ServerSetting.DstProgID = this.m_oServerSetting.DstProgID;
            loSetting.ServerSetting.DstServerIp = this.m_oServerSetting.DstServerIp;
            loSetting.ServerSetting.DstServerMode = this.m_oServerSetting.DstServerMode;
            loSetting.ServerSetting.DstServerPort = this.m_oServerSetting.DstServerPort;
            loSetting.ServerSetting.DstServerMode = this.m_oServerSetting.DstServerMode;
            loSetting.ServerSetting.BHServerTpyeDst = this.m_oServerSetting.BHServerTpyeDst;
            loSetting.ServerSetting.BHServerTpyeSrc = this.m_oServerSetting.BHServerTpyeSrc;
            loSetting.ServerSetting.OpcPassword = this.m_oServerSetting.OpcPassword;
            loSetting.ServerSetting.OpcUserName = this.m_oServerSetting.OpcUserName;
            loSetting.ServerSetting.OpcAsyncRead = this.m_oServerSetting.OpcAsyncRead;

            DialogResult loResult = loSetting.ShowDialog(this);

            if (loResult == DialogResult.OK)
            {
                this.m_oServerSetting.Machine = loSetting.ServerSetting.Machine;
                this.m_oServerSetting.ProgID = loSetting.ServerSetting.ProgID;
                this.m_oServerSetting.TimeInterval = loSetting.ServerSetting.TimeInterval;
                this.m_oServerSetting.ServerPort = loSetting.ServerSetting.ServerPort;
                this.m_oServerSetting.ServerIp = loSetting.ServerSetting.ServerIp;
                this.m_oServerSetting.TransferSource = loSetting.ServerSetting.TransferSource;


                this.m_oServerSetting.DstMachine = loSetting.ServerSetting.DstMachine;
                this.m_oServerSetting.DstProgID = loSetting.ServerSetting.DstProgID;
                this.m_oServerSetting.RemoteUrl = loSetting.ServerSetting.RemoteUrl;
                this.m_oServerSetting.TimeInterval = loSetting.ServerSetting.TimeInterval;
                this.m_oServerSetting.DstServerPort = loSetting.ServerSetting.DstServerPort;
                this.m_oServerSetting.DstServerMode = loSetting.ServerSetting.DstServerMode;
                this.m_oServerSetting.DstServerIp = loSetting.ServerSetting.DstServerIp;
                this.m_oServerSetting.BHServerTpyeDst = loSetting.ServerSetting.BHServerTpyeDst;
                this.m_oServerSetting.BHServerTpyeSrc = loSetting.ServerSetting.BHServerTpyeSrc;

                this.m_oServerSetting.OpcPassword = loSetting.ServerSetting.OpcPassword;
                this.m_oServerSetting.OpcUserName = loSetting.ServerSetting.OpcUserName;
                this.m_oServerSetting.OpcAsyncRead = loSetting.ServerSetting.OpcAsyncRead;
            }
        }

        public void MainThreadUiFeed(ThreadUiController.CallerParameter args)
        {
            try
            {
                ThreadUiController.Feed();
            }
            catch (System.Exception ex)
            {

            }
        }

        private void Main_Load(object sender, EventArgs e)
        {
            EricZhao.UiThread.ThreadUiController.InitLog();

            EricZhao.UiThread.ThreadUiController.log("Application Started", ThreadUiController.LOG_LEVEL.FATAL);

            this.CenterToParent();

            EricZhao.UiThread.ListViewHelper.EnableDoubleBuffer(this.listView1);

            this.CollectorStatus = COLLECTOR_STATUS.STOPPED;

            this.LoadSetting();

            this.toolStripStatusLabel1.Alignment = ToolStripItemAlignment.Right;

            this.ToggleUI(null);

            if (this.m_oServerSetting.TotalItems.Count > 0)
            {
                this.StartCollector();
            }
        }

        ServerSetting m_oServerSetting = new ServerSetting();

        private void UpdateUI()
        {
            try
            {
                this.listView1.VirtualListSize = this.m_oServerSetting.TotalItems.Count;
                this.listView1.Refresh();
            }
            catch (System.Exception ex)
            {

            }
        }

        private void SetListViewItemColor(ListViewItem apItem, ItemSetting apItemModel)
        {
            if (null == apItem || null == apItemModel)
            {
                return;
            }

            try
            {
                if (apItemModel.DstStatus == Opc.Da.qualityBits.badLastKnownValue)
                {


                    if (this.CollectorStatus == COLLECTOR_STATUS.STARTED)
                    {
                        apItem.BackColor = Color.Orange;
                        apItem.ForeColor = Color.White;
                    }
                    else if (this.CollectorStatus == COLLECTOR_STATUS.STARTING)
                    {
                        apItem.BackColor = Color.White;
                        apItem.ForeColor = Color.Black;
                    }
                    else
                    {
                        apItem.BackColor = Color.White;
                        apItem.ForeColor = Color.Black;
                    }

                    return;

                }
                Opc.Da.qualityBits lnComputedQuality = apItemModel.SourceStatus & apItemModel.DstStatus;

                if (apItem != null && apItemModel != null)
                {
                    switch (lnComputedQuality)
                    {
                        case Opc.Da.qualityBits.good:

                            if (this.CollectorStatus == COLLECTOR_STATUS.STARTED)
                            {
                                this.toolStripStatusApplication.Text = "启动完成(connect successfully)";
                                if (apItemModel.ItemType == 0)
                                {
                                    apItem.BackColor = Color.Green;
                                }
                                else
                                {
                                    apItem.BackColor = Color.BlueViolet;
                                }

                                apItem.ForeColor = Color.White;
                            }
                            else if (this.CollectorStatus == COLLECTOR_STATUS.STARTING)
                            {
                                this.toolStripStatusApplication.Text = "启动中(starting) ...";
                                apItem.BackColor = Color.Orange;
                                apItem.ForeColor = Color.Black;
                            }

                            else
                            {
                                this.toolStripStatusApplication.Text = "停止(stopped)";
                                apItem.BackColor = Color.White;
                                apItem.ForeColor = Color.Black;
                            }

                            break;

                        case Opc.Da.qualityBits.bad:
                        case Opc.Da.qualityBits.badNotConnected:

                            if (this.CollectorStatus == COLLECTOR_STATUS.STARTED)
                            {
                                this.toolStripStatusApplication.Text = "启动完成(connect successfully)";
                                apItem.BackColor = Color.Orange;
                                apItem.ForeColor = Color.White;
                            }
                            else if (this.CollectorStatus == COLLECTOR_STATUS.STARTING)
                            {
                                this.toolStripStatusApplication.Text = "启动中(starting) ...";
                                apItem.BackColor = Color.Orange;
                                apItem.ForeColor = Color.Black;
                            }
                            else if (this.CollectorStatus == COLLECTOR_STATUS.ERROR_RETRYING)
                            {
                                apItem.BackColor = Color.Gray;
                                apItem.ForeColor = Color.White;
                                this.toolStripStatusApplication.Text = "连接失败重试中(connect failed retrying) ...";
                            }
                            else
                            {
                                apItem.BackColor = Color.White;
                                apItem.ForeColor = Color.Black;
                            }

                            break;
                        case Opc.Da.qualityBits.badLastKnownValue:

                            if (this.CollectorStatus == COLLECTOR_STATUS.STARTED)
                            {
                                this.toolStripStatusApplication.Text = "启动完成(connect successfully)";
                                apItem.BackColor = Color.Orange;
                                apItem.ForeColor = Color.White;
                            }
                            else if (this.CollectorStatus == COLLECTOR_STATUS.STARTING)
                            {
                                this.toolStripStatusApplication.Text = "启动中(starting) ...";
                                apItem.BackColor = Color.White;
                                apItem.ForeColor = Color.Black;
                            }
                            else
                            {
                                apItem.BackColor = Color.White;
                                apItem.ForeColor = Color.Black;
                            }

                            break;

                        default:
                            if (this.CollectorStatus == COLLECTOR_STATUS.STARTED)
                            {
                                this.toolStripStatusApplication.Text = "启动完成(connect successfully)";
                                apItem.BackColor = Color.DarkRed;
                                apItem.ForeColor = Color.White;

                            }
                            else if (this.CollectorStatus == COLLECTOR_STATUS.STARTING)
                            {
                                this.toolStripStatusApplication.Text = "启动中(starting) ...";
                                apItem.BackColor = Color.Orange;
                                apItem.ForeColor = Color.Black;
                            }
                            else
                            {
                                this.toolStripStatusApplication.Text = "停止(stopped)";
                                apItem.BackColor = Color.White;
                                apItem.ForeColor = Color.Black;
                            }

                            break;
                    }
                }
            }
            catch (System.Exception ex)
            {
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }
        }

        private ListViewItem MakeUpItem(int anIndex)
        {
            try
            {
                if (anIndex < m_oServerSetting.TotalItems.Count)
                {
                    ItemSetting loItem = (ItemSetting)this.m_oServerSetting.TotalItems[anIndex];

                    ListViewItem aoTreeItem = new ListViewItem(loItem.TagName);
                    aoTreeItem.Name = loItem.TagName;

                    if (loItem.Value is int
                        ||
                        loItem.Value is Boolean
                        ||
                        loItem.Value is bool
                        ||
                         loItem.Value is short
                        ||
                         loItem.Value is float
                        ||
                        loItem.Value is double
                        ||
                        loItem.Value is string)
                    {
                        aoTreeItem.SubItems.Add(loItem.Value.ToString());
                    }
                    else
                    {
                        aoTreeItem.SubItems.Add("0");
                    }



                    aoTreeItem.SubItems.Add(loItem.Company);
                    aoTreeItem.SubItems.Add(loItem.Factory);
                    aoTreeItem.SubItems.Add(loItem.Plant);
                    aoTreeItem.SubItems.Add(loItem.RemoteTageName);
                    aoTreeItem.SubItems.Add(loItem.UpdateTime.ToString());
                    aoTreeItem.SubItems.Add(loItem.SendTime.ToString());
                    aoTreeItem.SubItems.Add(loItem.UpdateCount.ToString());
                    aoTreeItem.SubItems.Add(Enum.GetName(typeof(DAQ.ServerSetting.SourceServerType),
                                                this.m_oServerSetting.TransferSource)
                                                + ":" + loItem.Quality.QualityBits.ToString());
                    aoTreeItem.SubItems.Add(this.m_oServerSetting.DstServerMode + ":" + loItem.BHQuality.ToString());
                    this.SetListViewItemColor(aoTreeItem, loItem);
                    return aoTreeItem;
                }

                return null;
            }
            catch (System.Exception ex)
            {
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                return null;
            }

        }

        private void EmptyCache()
        {

            this.Cache = null;
        }

        private void AddItem()
        {
            Boolean lbShouldDoAddItem = false;

            if (this.CollectorStatus != COLLECTOR_STATUS.STOPPED)
            {
                DialogResult lpResult = MessageBox.Show(" 确认增加测点?,将会导致采集停止.(Sure to Add item? this will cause collector stopping.)",
                                         "请确认(Please Confirm)",
                                          MessageBoxButtons.OKCancel);
                if (lpResult == DialogResult.OK)
                {
                    this.StopCollector();

                    lbShouldDoAddItem = true;
                }
            }
            else
            {
                lbShouldDoAddItem = true;
            }

            if (lbShouldDoAddItem)
            {



                DialogResult lpResult = MessageBox.Show("请点击确认,增加普通测点，点击否增加计算测点.\r\nPress Yes to Add Normal Item, Press NO to Add Scriptlet Item",
                                                       "确认增加普通测点么 Are you going to add Normal item?",
                                                        MessageBoxButtons.YesNo);

                Boolean lbAddScriptItem = false;
                if (lpResult == DialogResult.No)
                {
                    lbAddScriptItem = true;
                }


                if (!lbAddScriptItem)
                {
                    FormItemSettings loFormSetting = new FormItemSettings();

                    System.Windows.Forms.DialogResult loDiaglogResult = loFormSetting.ShowDialog(this);

                    if (DialogResult.OK == loDiaglogResult)
                    {
                        m_oServerSetting.TotalItems.Add(loFormSetting.Item);

                        for (int i = 0; i < m_oServerSetting.TotalItems.Count; i++)
                        {
                            if (m_oServerSetting.TotalItems[i].Company == loFormSetting.Item.Company
                                &&
                                m_oServerSetting.TotalItems[i].Factory == loFormSetting.Item.Factory
                                &&
                                m_oServerSetting.TotalItems[i].Plant == loFormSetting.Item.Plant)
                            {
                                m_oServerSetting.TotalItems[i].StartIndex = loFormSetting.Item.StartIndex;
                            }
                        }

                        this.EmptyCache();

                        this.UpdateUI();
                    }
                }
                else
                {
                    FunctionItemSetting loFormSetting = new FunctionItemSetting();

                    loFormSetting.AllItems = this.m_oServerSetting.TotalItems;
                    System.Windows.Forms.DialogResult loDiaglogResult = loFormSetting.ShowDialog(this);

                    if (DialogResult.OK == loDiaglogResult)
                    {
                        m_oServerSetting.TotalItems.Add(loFormSetting.Item);

                        for (int i = 0; i < m_oServerSetting.TotalItems.Count; i++)
                        {
                            if (m_oServerSetting.TotalItems[i].Company == loFormSetting.Item.Company
                                &&
                                m_oServerSetting.TotalItems[i].Factory == loFormSetting.Item.Factory
                                &&
                                m_oServerSetting.TotalItems[i].Plant == loFormSetting.Item.Plant)
                            {
                                m_oServerSetting.TotalItems[i].StartIndex = loFormSetting.Item.StartIndex;
                            }
                        }

                        this.EmptyCache();

                        this.UpdateUI();
                    }
                }

            }

        }

        private void addToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.AddItem();
        }


        Boolean m_bDataChanged = false;
        public System.Boolean DataChanged
        {
            get { return m_bDataChanged; }
            set { m_bDataChanged = value; }
        }
        private void listView1_RetrieveVirtualItem(object sender, RetrieveVirtualItemEventArgs e)
        {
            Boolean lbShuoldMakeNewItem = false;
            try
            {
                if (this.Cache != null && e.ItemIndex >= m_nFirstItem
                    && e.ItemIndex < m_nFirstItem + this.Cache.Length
                    )
                {
                    //A cache hit, so get the ListViewItem from the cache instead of making a new one.
                    e.Item = m_oCache[e.ItemIndex - m_nFirstItem];


                }
                else
                {
                    lbShuoldMakeNewItem = true;
                }

            }
            catch (System.Exception ex)
            {
                lbShuoldMakeNewItem = true;
            }

            try
            {
                if (lbShuoldMakeNewItem)
                {
                    //A cache miss, so create a new ListViewItem and pass it back.
                    int x = e.ItemIndex;

                    if (x < this.m_oServerSetting.TotalItems.Count)
                    {
                        ListViewItem loItem = MakeUpItem(x);

                        if (null != loItem)
                        {
                            e.Item = loItem;
                        }
                        else
                        {
                            e.Item = new ListViewItem();
                        }

                    }
                    else
                    {
                        e.Item = new ListViewItem();
                    }

                    this.DataChanged = false;
                }
            }
            catch (Exception e1)
            {
                e.Item = new ListViewItem();
            }
        }

        private void listView1_VirtualItemsSelectionRangeChanged(object sender, ListViewVirtualItemsSelectionRangeChangedEventArgs e)
        {

        }

        private void listView1_CacheVirtualItems(object sender, CacheVirtualItemsEventArgs e)
        {
            try
            {
                if (this.Cache != null
                   && e.StartIndex >= m_nFirstItem
                   && e.EndIndex <= m_nFirstItem + this.Cache.Length)
                {
                    return;
                }

                this.m_nFirstItem = e.StartIndex;
                int length = e.EndIndex - e.StartIndex + 1; //indexes are inclusive

                this.Cache = new ListViewItem[length];

                int lnItemIndex = 0;

                for (int i = 0; i < length; i++)
                {
                    lnItemIndex = (i + m_nFirstItem);

                    if (lnItemIndex >= this.m_oServerSetting.TotalItems.Count)
                    {
                        continue;
                    }

                    ListViewItem loItem = MakeUpItem(lnItemIndex);

                    if (null != loItem && this.Cache != null)
                    {
                        m_oCache[i] = loItem;
                    }
                }
            }
            catch (System.Exception ex)
            {

            }
        }

        private void listView1_SearchForVirtualItem(object sender, SearchForVirtualItemEventArgs e)
        {
            try
            {
                double x = 0;
                if (Double.TryParse(e.Text, out x)) //check if this is a valid search
                {
                    x = Math.Sqrt(x);
                    x = Math.Round(x);
                    e.Index = (int)x;

                }
            }
            catch (System.Exception ex)
            {

            }
        }

        private void testToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.listView1.VirtualListSize += 1;
        }

        Random m_oRandom = new Random();
        public System.Random Random
        {
            get { return m_oRandom; }
            set { m_oRandom = value; }
        }
        private DateTime m_oDateTimeStartedTime = DateTime.Now;
        private void timer1_Tick(object sender, EventArgs e)
        {
            TimeSpan loOffset = DateTime.Now - this.m_oDateTimeStartedTime;

            this.toolStripStatusLabel1.Text = loOffset.ToString();
        }

        private void testToolStripMenuItem_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void MenuItemAutoRefresh_CheckStateChanged(object sender, EventArgs e)
        {


        }

        private void saveSettingToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.SaveSetting();
        }

        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            FormServerTest loTest = new FormServerTest();

            loTest.OpcPassword = this.m_oServerSetting.OpcPassword;
            loTest.OpcUserName = this.m_oServerSetting.OpcUserName;
            loTest.OpcAsyncRead = this.m_oServerSetting.OpcAsyncRead;
            loTest.textBoxProID.Text = this.m_oServerSetting.ProgID;
            loTest.textBoxServerIP.Text = this.m_oServerSetting.Machine;

            loTest.ShowDialog(this);
        }

        ThreadOpcCollector m_oCollector = null;
        public DAQ.ThreadOpcCollector m_oOpcCollector
        {
            get { return m_oCollector; }
            set { m_oCollector = value; }
        }

        ThreadBHCollector m_oBHCollector = null;
        public DAQ.ThreadBHCollector BHCollector
        {
            get { return m_oBHCollector; }
            set { m_oBHCollector = value; }
        }

        ThreadAspenCollector m_oAspenCollector = null;
        public DAQ.ThreadAspenCollector AspenCollector
        {
            get { return m_oAspenCollector; }
            set { m_oAspenCollector = value; }
        }
        public void MainThreadUiOperatorForWriteBack(ThreadUiController.CallerParameter args)
        {
            this.Cache = null;
            this.UpdateUI();
            this.ToggleUI(null);
        }

        public void MainThreadUiOperator(ThreadUiController.CallerParameter args)
        {
            this.Cache = null;
            this.UpdateUI();
            this.ToggleUI(null);

        }

        public void ThreadToggleUI(ThreadUiController.CallerParameter args)
        {
            this.UpdateUI();

        }

        int m_nUploadThreadLimit = 1;
        int m_nUploadThradCount = 0;

        public CBHFixComLib.ICBHFixComImp GetFixComm(int anType/* 0 离线, 1在线*/)
        {
            CBHFixComLib.ICBHFixComImp loFixComm = new CBHFixComLib.CBHFixComImp();

            loFixComm.SetCommType(anType);

            return loFixComm;
        }

        public static void checkHealth(int HandleLimitCount)
        {
            // lock(this)
            {
                System.Diagnostics.Process p = System.Diagnostics.Process.GetCurrentProcess();

                if (p.HandleCount > HandleLimitCount)
                {
                    ThreadUiController.log("Handle limit reached:" + p.HandleCount + ">" + HandleLimitCount + ",QUIT", ThreadUiController.LOG_LEVEL.FATAL);
                    MiniDump.TerminateProcess(Process.GetCurrentProcess().Handle, 1);
                }
            }

        }

        public void UploadStatus()
        {
            if (this.m_oServerSetting.TransferSource == ServerSetting.SourceServerType.BH_SERVER)
            {
                //Debug.WriteLine("test");
                //  return;
            }
            if (this.m_oServerSetting.DstServerMode == Enum.GetName(typeof(DAQ.ServerSetting.DestinationServerType),
                                                                 DAQ.ServerSetting.DestinationServerType.BHServer))
            {
                if (this.m_nUploadThradCount < 1)
                {

                    if (this.m_oServerSetting.TotalItems.Count > 0)
                    {
                        System.Collections.Generic.List<ItemSetting> loDatas
                            = new System.Collections.Generic.List<ItemSetting>();

                        loDatas.AddRange(this.m_oServerSetting.TotalItems);

                        Thread lpUploadThread = null;
                        //设置连接类型 0:ACE(离线) 1:MFC(在线)
                        int lnServerType = (int)this.m_oServerSetting.BHServerTpyeDst;
                        if (lnServerType == 0)
                        {
                            lpUploadThread = new Thread(new ParameterizedThreadStart(UploadStatusBHNewFixCommServerThreadProc));
                        }
                        else
                        {
                            lpUploadThread = new Thread(new ParameterizedThreadStart(UploadStatusBHServerThreadProc));
                        }

                        lpUploadThread.Name = "uploadThread";
                        lpUploadThread.IsBackground = true;
                        lpUploadThread.Start(loDatas);
                        m_nUploadThradCount++;
                    }
                }
            }
            else if (this.m_oServerSetting.DstServerMode == Enum.GetName(typeof(DAQ.ServerSetting.DestinationServerType),
                                                                 DAQ.ServerSetting.DestinationServerType.WebService))
            {
                if (this.m_nUploadThradCount < m_nUploadThreadLimit)
                {

                    if (this.m_oServerSetting.TotalItems.Count > 0)
                    {
                        System.Collections.Generic.List<ItemSetting> loDatas
                            = new System.Collections.Generic.List<ItemSetting>();

                        loDatas.AddRange(this.m_oServerSetting.TotalItems);

                        Thread lpUploadThread = new Thread(new ParameterizedThreadStart(UploadStatusWebServiceThreadProc));
                        lpUploadThread.Name = "uploadThread";
                        lpUploadThread.IsBackground = true;
                        lpUploadThread.Start(loDatas);
                        m_nUploadThradCount++;
                    }
                }
            }

        }

        CBHFixComLib.ICBHFixComImp m_oFixComm = null;



        public void UploadStatusBHServerThreadProc(Object obj)
        {
            //初始化
            try
            {
                System.Collections.Generic.List<ItemSetting> loDatas
              = (System.Collections.Generic.List<ItemSetting>)obj;


                //设置连接类型 0:ACE(离线) 1:MFC(在线)

                int lnServerType = (int)this.m_oServerSetting.BHServerTpyeDst;
                String lstrConnstr = string.Format("{0},{1}/TCP", this.m_oServerSetting.DstServerIp, this.m_oServerSetting.DstServerPort + "");
                String lstrDept = "";
                if(null == this.m_oFixComm)
                {
                    this.m_oFixComm = new  CBHFixComLib.CBHFixComImp();
                }
                m_oFixComm.SetCommType(lnServerType);

                Boolean lbUseSendTimeStamp = this.m_oServerSetting.UseSendTimeStamp;

                String lstrDateTimeNow = DateTime.Now.ToString();

                if (loDatas != null
                    && loDatas.Count > 0
                    && lstrConnstr != null
                    && lstrConnstr.Length > 0)
                {
                    int lnRet = m_oFixComm.Link(ref lstrConnstr, ref lstrDept);

                    if (lnRet <= 0)
                    {
                        checkHealth(this.m_oServerSetting.HandleLimitCount);

                        ServerSetting loSetting = new ServerSetting();
                        loSetting.TotalItems = loDatas;
                        for (int i = 0; i < loDatas.Count; i++)
                        {
                            loSetting.TotalItems[i].DstStatus = Opc.Da.qualityBits.badCommFailure;
                        }

                        CollectorDataEventArgs args = new CollectorDataEventArgs(loSetting);
                        this.OnWriteBHDataChanged(this, args);

                    }
                    else
                    {
                        loDatas.Clear();
                        System.Collections.Generic.List<int> loArray = new System.Collections.Generic.List<int>();
                        loDatas.AddRange(this.m_oServerSetting.TotalItems);

                        for (int i = 0; i < loDatas.Count; i++)
                        {
                            int lnStatus = (int)(loDatas[i].SourceStatus & Opc.Da.qualityBits.good);


                            if ((lnStatus != 0xc0))
                            {
                                // loArray.Add(i);
                            }

                            loDatas[i].strUpdateTime = loDatas[i].UpdateTime.ToString();
                        }

                        for (int i = 0; i < loArray.Count; i++)
                        {
                            //loDatas.RemoveAt(loArray[i]);
                        }
                        String lstrkey = "";
                        SortedDictionary<string, System.Collections.Generic.List<ItemSetting>> loChanns
                            = new SortedDictionary<string, System.Collections.Generic.List<ItemSetting>>();
                        Dictionary<string, List<int>> loIndexs = new Dictionary<string, List<int>>();
                        for (int i = 0; i < loDatas.Count; i++)
                        {
                            lstrkey = loDatas[i].Company + ConstantValueHolder.SPLITER
                                                         + loDatas[i].Factory
                                                         + ConstantValueHolder.SPLITER
                                                         + loDatas[i].Plant;
                            if (loDatas[i].BHItemType != ItemSetting.BH_ITEM_TYPE.PROC
                                || loDatas[i].TransferMode == ItemSetting.BH_TRANSFER_MODE.READ)
                            {
                                loDatas[i].DstStatus = Opc.Da.qualityBits.good;
                                continue;
                            }



                            if (loDatas[i].Quality == Opc.Da.Quality.Bad)
                            {
                                loDatas[i].DstStatus = Opc.Da.qualityBits.bad;
                                if (this.m_oServerSetting.CheckAllValid)
                                {
                                    continue;
                                }

                            }

                            if ((loDatas[i].LastUpdateTime >= loDatas[i].UpdateTime || loDatas[i].LastUpdateTime.Year <= 2000) && this.m_oServerSetting.CheckSourceDataUpdate)
                            {
                                loDatas[i].SourceStatus = Opc.Da.qualityBits.badLastKnownValue;
                                continue;

                            }
                            else if ((loDatas[i].SourceStatus == Opc.Da.qualityBits.badWaitingForInitialData) && this.m_oServerSetting.CheckSourceMiddlewareValid)
                            {
                                loDatas[i].SourceStatus = Opc.Da.qualityBits.badWaitingForInitialData;
                                continue;
                            }
                            else
                            {
                                loDatas[i].DstStatus = Opc.Da.qualityBits.good;
                            }


                            if (!loChanns.ContainsKey(lstrkey))
                            {
                                System.Collections.Generic.List<ItemSetting> loTemp
                                     = new System.Collections.Generic.List<ItemSetting>();
                                loChanns.Add(lstrkey, loTemp);
                            }

                            loChanns[lstrkey].Add(loDatas[i]);
                            string lstrKeyChann = lstrkey + loDatas[i].TagName + loDatas[i].RemoteTageName;
                            if (!loIndexs.ContainsKey(lstrKeyChann))
                            {
                                loIndexs.Add(lstrKeyChann, new List<int>());
                            }
                            loIndexs[lstrKeyChann].Add(i);
                        }

                        foreach (KeyValuePair<string, System.Collections.Generic.List<ItemSetting>> lpValue in loChanns)
                        {
                            if (lpValue.Value[0].SourceStatus == Opc.Da.qualityBits.badNotConnected
                                ||
                                lpValue.Value[0].DstStatus == Opc.Da.qualityBits.badNotConnected)
                            {
                                if (this.m_oServerSetting.CheckAllValid)
                                {
                                    continue;
                                }
                            }
                            m_oFixComm.CreateHead(24003);
                            String lstrCompany = (lpValue.Value[0].Company);
                            String lstrFactory = (lpValue.Value[0].Factory);
                            String lstrPlant = (lpValue.Value[0].Plant);

                            m_oFixComm.SetItemString(15004, ref lstrCompany);
                            m_oFixComm.SetItemString(15003, ref lstrFactory);
                            m_oFixComm.SetItemString(10013, ref lstrPlant);

                            m_oFixComm.SetItem(14019, lpValue.Value[0].StartIndex);
                            m_oFixComm.SetItem(14005, lpValue.Value.Count);
                            m_oFixComm.SetItem(14020, 0);


                            string lstrDatetime = lpValue.Value[0].UpdateTime.ToString();
                            if (lbUseSendTimeStamp)
                            {
                                lstrDatetime = lstrDateTimeNow;
                            }
                            m_oFixComm.SetItemString(10009, ref lstrDatetime);

                            System.IO.MemoryStream loStream = new System.IO.MemoryStream();
                            System.IO.BinaryWriter loWriter = new System.IO.BinaryWriter(loStream);

                            //过程量做启停车判断
                            int lbJudgeStartOrStop = 0;
                            int lnJudgeStartCount = 0;
                            int lnJudgeTotalCount = 0;

                            for (int i = 0; i < lpValue.Value.Count; i++)
                            {
                                object loValue = lpValue.Value[i].Value;
                                float lfValue = 0;
                                if (!float.TryParse(loValue.ToString(), out lfValue))
                                {
                                    //Debug.Assert(false);
                                    lfValue = 0;
                                }
                                float PRECISION = 0.000001f;
                                if (Math.Abs(lfValue) <= PRECISION)
                                {
                                    String lstrData = String.Format("More:{6} Point :{0} | value:{1} | index:{2} | company:{3} | factory:{4} | plant:{5} | status:{7}",
                                                      lpValue.Value[i].TagName,
                                                      lpValue.Value[i].Value,
                                                      lpValue.Value[i].StartIndex,
                                                      lpValue.Value[i].Company,
                                                      lpValue.Value[i].Factory,
                                                      lpValue.Value[i].Plant,
                                                      lnRet,
                                                      lbJudgeStartOrStop);
                                    //  ThreadUiController.log(lstrData, ThreadUiController.LOG_LEVEL.FATAL);

                                    //continue;
                                }
                                loWriter.Write(lfValue);

                                ItemSetting lpSettingItem = lpValue.Value[i];

                                if (lpSettingItem.UsedAsJudgeRunStopStatus && lpSettingItem.SourceStatus == Opc.Da.qualityBits.good)
                                {
                                    lnJudgeTotalCount++;

                                    if (lpSettingItem.JudgeType <= 0) //more is started
                                    {
                                        if (lfValue > lpSettingItem.DblJudgeThreshold)
                                        {
                                            lnJudgeStartCount++;
                                        }
                                    }
                                    else
                                    {
                                        if (lfValue < lpSettingItem.DblJudgeThreshold)
                                        {
                                            lnJudgeStartCount++;
                                        }

                                    }
                                }
                            }

                            if (lnJudgeTotalCount > 0)
                            {
                                if (lnJudgeStartCount > (lnJudgeTotalCount - lnJudgeStartCount))
                                {
                                    lbJudgeStartOrStop = 1;//start
                                }
                                else if (lnJudgeStartCount < (lnJudgeTotalCount - lnJudgeStartCount))
                                {
                                    lbJudgeStartOrStop = 2;//stop
                                }
                            }


                            byte[] lpBuffer = loStream.ToArray();
                            object lpParam = (object)lpBuffer;
                            m_oFixComm.SetItemBuf(14018, lpBuffer.Length, ref lpParam);


                            m_oFixComm.SetItem(15020, lbJudgeStartOrStop);

                            lnRet = m_oFixComm.More();

                            if (lbJudgeStartOrStop == 2)
                            {
                                StringBuilder loSb = new StringBuilder();

                                for (int i = 0; i < lpValue.Value.Count; i++)
                                {
                                    String lstrData = String.Format("More:{6} Point :{0} | value:{1} | index:{2} | company:{3} | factory:{4} | plant:{5} | status:{7}",
                                                      lpValue.Value[i].TagName,
                                                      lpValue.Value[i].Value,
                                                      lpValue.Value[i].StartIndex,
                                                      lpValue.Value[i].Company,
                                                      lpValue.Value[i].Factory,
                                                      lpValue.Value[i].Plant,
                                                      lnRet,
                                                      lbJudgeStartOrStop);
                                    Debug.WriteLine(lstrData);

                                    loSb.AppendLine(lstrData);

                                }

                                ThreadUiController.log(loSb.ToString(), ThreadUiController.LOG_LEVEL.DEBUG);
                            }

                            if (lnRet <= 0)
                            {
                                StringBuilder loSb = new StringBuilder();
                                for (int i = 0; i < lpValue.Value.Count; i++)
                                {
                                    String lstrData = String.Format("More:{6} Point :{0} | value:{1} | index:{2} | company:{3} | factory:{4} | plant:{5} | status:{7}",
                                                      lpValue.Value[i].TagName,
                                                      lpValue.Value[i].Value,
                                                      lpValue.Value[i].StartIndex,
                                                      lpValue.Value[i].Company,
                                                      lpValue.Value[i].Factory,
                                                      lpValue.Value[i].Plant,
                                                      lnRet,
                                                      lbJudgeStartOrStop);
                                    Debug.WriteLine(lstrData);
                                    loSb.AppendLine(lstrData);
                                }
                                ThreadUiController.log(loSb.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                            }
                            else
                            {
                                ThreadUiController.InvokeControlCustomMethod3(this,
                                new ThreadUiController.MethodCallCaller(this.MainThreadUiFeed), null);
                            }

                            if (lnRet > 0)
                            {
                            }

                            // Debug.WriteLine("******************************************** end ********************************************");


                            for (int i = 0; i < lpValue.Value.Count; i++)
                            {
                                String lstrKey = lpValue.Key + lpValue.Value[i].TagName + lpValue.Value[i].RemoteTageName;
                                List<int> loIndex = loIndexs[lstrKey];

                                for (int j = 0; j < loIndex.Count; j++)
                                {
                                    int lnIndex = loIndex[j];
                                    if (lnRet < 0)
                                    {
                                        loDatas[lnIndex].DstStatus = Opc.Da.qualityBits.badOutOfService;
                                        Debug.WriteLine(String.Format("failed to send to 24003 "));
                                    }
                                    else
                                    {
                                        loDatas[lnIndex].DstStatus = Opc.Da.qualityBits.good;
                                        loDatas[lnIndex].SendTime = System.DateTime.Now;
                                    }

                                    // Debug.WriteLine(String.Format("Name:{0}| Index:{1}", lstrKey, lnIndex));
                                }//for (int j = 0; j < loIndex.Count; j++)
                            }//for (int i = 0; i < lpValue.Value.Count; i++)
                        }//foreach (KeyValuePair<string, System.Collections.Generic.List<ItemSetting>> lpValue in loChanns)


                        ServerSetting loSettingWriteBack = new ServerSetting();
                        loSettingWriteBack.TotalItems = loDatas;
                        CollectorDataEventArgs argsWriteBack = new CollectorDataEventArgs(loSettingWriteBack);
                        this.OnWriteBHDataChanged(this, argsWriteBack);
                    }
                }
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(String.Format("failed to send to 24003 error:") + ex.Message);
            }

            m_nUploadThradCount--;

        }

        public void UploadStatusBHNewFixCommServerThreadProc(Object obj)
        {
            try
            {
                using (Dse.FixComm loFixComm = Dse.FixComm.New(this.m_oServerSetting.DstServerIp, "" + this.m_oServerSetting.DstServerPort))
                {
                    //初始化
                    try
                    {
                        System.Collections.Generic.List<ItemSetting> loDatas
                      = (System.Collections.Generic.List<ItemSetting>)obj;


                        //设置连接类型 0:ACE(离线) 1:MFC(在线)

                        int lnServerType = (int)this.m_oServerSetting.BHServerTpyeDst;
                        String lstrConnstr = string.Format("{0},{1}/TCP", this.m_oServerSetting.DstServerIp, this.m_oServerSetting.DstServerPort + "");
                        String lstrDept = "";


                        Boolean lbUseSendTimeStamp = this.m_oServerSetting.UseSendTimeStamp;

                        String lstrDateTimeNow = DateTime.Now.ToString();

                        if (loDatas != null
                            && loDatas.Count > 0
                            && lstrConnstr != null
                            && lstrConnstr.Length > 0)
                        {
                            Boolean lnRet = true;

                            if (!lnRet)
                            {
                                checkHealth(this.m_oServerSetting.HandleLimitCount);

                                ServerSetting loSetting = new ServerSetting();
                                loSetting.TotalItems = loDatas;
                                for (int i = 0; i < loDatas.Count; i++)
                                {
                                    loSetting.TotalItems[i].DstStatus = Opc.Da.qualityBits.badCommFailure;
                                }

                                CollectorDataEventArgs args = new CollectorDataEventArgs(loSetting);
                                this.OnWriteBHDataChanged(this, args);

                            }
                            else
                            {
                                loDatas.Clear();
                                System.Collections.Generic.List<int> loArray = new System.Collections.Generic.List<int>();
                                loDatas.AddRange(this.m_oServerSetting.TotalItems);

                                for (int i = 0; i < loDatas.Count; i++)
                                {
                                    int lnStatus = (int)(loDatas[i].SourceStatus & Opc.Da.qualityBits.good);


                                    if ((lnStatus != 0xc0))
                                    {
                                        // loArray.Add(i);
                                    }

                                    loDatas[i].strUpdateTime = loDatas[i].UpdateTime.ToString();
                                }

                                for (int i = 0; i < loArray.Count; i++)
                                {
                                    //loDatas.RemoveAt(loArray[i]);
                                }
                                String lstrkey = "";
                                SortedDictionary<string, System.Collections.Generic.List<ItemSetting>> loChanns
                                    = new SortedDictionary<string, System.Collections.Generic.List<ItemSetting>>();
                                Dictionary<string, List<int>> loIndexs = new Dictionary<string, List<int>>();
                                for (int i = 0; i < loDatas.Count; i++)
                                {
                                    lstrkey = loDatas[i].Company + ConstantValueHolder.SPLITER
                                                                 + loDatas[i].Factory
                                                                 + ConstantValueHolder.SPLITER
                                                                 + loDatas[i].Plant;
                                    if (loDatas[i].BHItemType != ItemSetting.BH_ITEM_TYPE.PROC
                                        || loDatas[i].TransferMode == ItemSetting.BH_TRANSFER_MODE.READ)
                                    {
                                        loDatas[i].DstStatus = Opc.Da.qualityBits.good;
                                        continue;
                                    }



                                    if (loDatas[i].Quality == Opc.Da.Quality.Bad)
                                    {
                                        loDatas[i].DstStatus = Opc.Da.qualityBits.bad;
                                        if (this.m_oServerSetting.CheckAllValid)
                                        {
                                            continue;
                                        }

                                    }

                                    if ((loDatas[i].LastUpdateTime >= loDatas[i].UpdateTime || loDatas[i].LastUpdateTime.Year <= 2000) && this.m_oServerSetting.CheckSourceDataUpdate)
                                    {
                                        loDatas[i].SourceStatus = Opc.Da.qualityBits.badLastKnownValue;
                                        continue;

                                    }
                                    else if ((loDatas[i].SourceStatus == Opc.Da.qualityBits.badWaitingForInitialData) && this.m_oServerSetting.CheckSourceMiddlewareValid)
                                    {
                                        loDatas[i].SourceStatus = Opc.Da.qualityBits.badWaitingForInitialData;
                                        continue;
                                    }
                                    else
                                    {
                                        loDatas[i].DstStatus = Opc.Da.qualityBits.good;
                                    }


                                    if (!loChanns.ContainsKey(lstrkey))
                                    {
                                        System.Collections.Generic.List<ItemSetting> loTemp
                                             = new System.Collections.Generic.List<ItemSetting>();
                                        loChanns.Add(lstrkey, loTemp);
                                    }

                                    loChanns[lstrkey].Add(loDatas[i]);
                                    string lstrKeyChann = lstrkey + loDatas[i].TagName + loDatas[i].RemoteTageName;
                                    if (!loIndexs.ContainsKey(lstrKeyChann))
                                    {
                                        loIndexs.Add(lstrKeyChann, new List<int>());
                                    }
                                    loIndexs[lstrKeyChann].Add(i);
                                }

                                foreach (KeyValuePair<string, System.Collections.Generic.List<ItemSetting>> lpValue in loChanns)
                                {
                                    if (lpValue.Value[0].SourceStatus == Opc.Da.qualityBits.badNotConnected
                                        ||
                                        lpValue.Value[0].DstStatus == Opc.Da.qualityBits.badNotConnected)
                                    {
                                        if (this.m_oServerSetting.CheckAllValid)
                                        {
                                            continue;
                                        }
                                    }
                                    loFixComm.CreateHead(24003);
                                    String lstrCompany = (lpValue.Value[0].Company);
                                    String lstrFactory = (lpValue.Value[0].Factory);
                                    String lstrPlant = (lpValue.Value[0].Plant);

                                    loFixComm.Set(15004, lstrCompany);
                                    loFixComm.Set(15003, lstrFactory);
                                    loFixComm.Set(10013, lstrPlant);

                                    loFixComm.SetItem(14019, lpValue.Value[0].StartIndex);
                                    loFixComm.SetItem(14005, lpValue.Value.Count);
                                    loFixComm.SetItem(14020, 0);
                                    loFixComm.SetItem(10010, 0);


                                    string lstrDatetime = lpValue.Value[0].UpdateTime.ToString();
                                    if (lbUseSendTimeStamp)
                                    {
                                        lstrDatetime = lstrDateTimeNow;
                                    }
                                    loFixComm.SetItem(10009, lstrDatetime);

                                    System.IO.MemoryStream loStream = new System.IO.MemoryStream();
                                    System.IO.BinaryWriter loWriter = new System.IO.BinaryWriter(loStream);

                                    //过程量做启停车判断
                                    int lbJudgeStartOrStop = 0;
                                    int lnJudgeStartCount = 0;
                                    int lnJudgeTotalCount = 0;

                                    for (int i = 0; i < lpValue.Value.Count; i++)
                                    {
                                        object loValue = lpValue.Value[i].Value;
                                        float lfValue = 0;
                                        if (!float.TryParse(loValue.ToString(), out lfValue))
                                        {
                                            //Debug.Assert(false);
                                            lfValue = 0;
                                        }
                                        float PRECISION = 0.000001f;
                                        if (Math.Abs(lfValue) <= PRECISION)
                                        {
                                            String lstrData = String.Format("More:{6} Point :{0} | value:{1} | index:{2} | company:{3} | factory:{4} | plant:{5} | status:{7}",
                                                              lpValue.Value[i].TagName,
                                                              lpValue.Value[i].Value,
                                                              lpValue.Value[i].StartIndex,
                                                              lpValue.Value[i].Company,
                                                              lpValue.Value[i].Factory,
                                                              lpValue.Value[i].Plant,
                                                              lnRet,
                                                              lbJudgeStartOrStop);
                                            //  ThreadUiController.log(lstrData, ThreadUiController.LOG_LEVEL.FATAL);

                                            //continue;
                                        }
                                        loWriter.Write(lfValue);

                                        ItemSetting lpSettingItem = lpValue.Value[i];

                                        if (lpSettingItem.UsedAsJudgeRunStopStatus && lpSettingItem.SourceStatus == Opc.Da.qualityBits.good)
                                        {
                                            lnJudgeTotalCount++;

                                            if (lpSettingItem.JudgeType <= 0) //more is started
                                            {
                                                if (lfValue > lpSettingItem.DblJudgeThreshold)
                                                {
                                                    lnJudgeStartCount++;
                                                }
                                            }
                                            else
                                            {
                                                if (lfValue < lpSettingItem.DblJudgeThreshold)
                                                {
                                                    lnJudgeStartCount++;
                                                }

                                            }
                                        }
                                    }

                                    if (lnJudgeTotalCount > 0)
                                    {
                                        if (lnJudgeStartCount > (lnJudgeTotalCount - lnJudgeStartCount))
                                        {
                                            lbJudgeStartOrStop = 1;//start
                                        }
                                        else if (lnJudgeStartCount < (lnJudgeTotalCount - lnJudgeStartCount))
                                        {
                                            lbJudgeStartOrStop = 2;//stop
                                        }
                                    }


                                    byte[] lpBuffer = loStream.ToArray();
                                    object lpParam = (object)lpBuffer;
                                    loFixComm.SetItem(14018, lpBuffer);
                                    loFixComm.SetItem(15020, lbJudgeStartOrStop);

                                    lnRet = loFixComm.More();

                                    if (lbJudgeStartOrStop == 2)
                                    {
                                        StringBuilder loSb = new StringBuilder();

                                        for (int i = 0; i < lpValue.Value.Count; i++)
                                        {
                                            String lstrData = String.Format("More:{6} Point :{0} | value:{1} | index:{2} | company:{3} | factory:{4} | plant:{5} | status:{7}",
                                                              lpValue.Value[i].TagName,
                                                              lpValue.Value[i].Value,
                                                              lpValue.Value[i].StartIndex,
                                                              lpValue.Value[i].Company,
                                                              lpValue.Value[i].Factory,
                                                              lpValue.Value[i].Plant,
                                                              lnRet,
                                                              lbJudgeStartOrStop);
                                            Debug.WriteLine(lstrData);

                                            loSb.AppendLine(lstrData);

                                        }

                                        ThreadUiController.log(loSb.ToString(), ThreadUiController.LOG_LEVEL.DEBUG);
                                    }

                                    if (!lnRet)
                                    {
                                        StringBuilder loSb = new StringBuilder();
                                        for (int i = 0; i < lpValue.Value.Count; i++)
                                        {
                                            String lstrData = String.Format("More:{6} Point :{0} | value:{1} | index:{2} | company:{3} | factory:{4} | plant:{5} | status:{7}",
                                                              lpValue.Value[i].TagName,
                                                              lpValue.Value[i].Value,
                                                              lpValue.Value[i].StartIndex,
                                                              lpValue.Value[i].Company,
                                                              lpValue.Value[i].Factory,
                                                              lpValue.Value[i].Plant,
                                                              lnRet,
                                                              lbJudgeStartOrStop);
                                            Debug.WriteLine(lstrData);
                                            loSb.AppendLine(lstrData);
                                        }
                                        ThreadUiController.log(loSb.ToString(), ThreadUiController.LOG_LEVEL.FATAL);

                                    }
                                    else
                                    {
                                        ThreadUiController.InvokeControlCustomMethod3(this,
                                        new ThreadUiController.MethodCallCaller(this.MainThreadUiFeed), null);
                                    }


                                    // Debug.WriteLine("******************************************** end ********************************************");


                                    for (int i = 0; i < lpValue.Value.Count; i++)
                                    {
                                        String lstrKey = lpValue.Key + lpValue.Value[i].TagName + lpValue.Value[i].RemoteTageName;
                                        List<int> loIndex = loIndexs[lstrKey];

                                        for (int j = 0; j < loIndex.Count; j++)
                                        {
                                            int lnIndex = loIndex[j];
                                            if (!lnRet)
                                            {
                                                loDatas[lnIndex].DstStatus = Opc.Da.qualityBits.badOutOfService;
                                                Debug.WriteLine(String.Format("failed to send to 24003 "));
                                            }
                                            else
                                            {
                                                loDatas[lnIndex].DstStatus = Opc.Da.qualityBits.good;
                                                loDatas[lnIndex].SendTime = System.DateTime.Now;
                                            }

                                            // Debug.WriteLine(String.Format("Name:{0}| Index:{1}", lstrKey, lnIndex));
                                        }//for (int j = 0; j < loIndex.Count; j++)
                                    }//for (int i = 0; i < lpValue.Value.Count; i++)
                                }//foreach (KeyValuePair<string, System.Collections.Generic.List<ItemSetting>> lpValue in loChanns)


                                ServerSetting loSettingWriteBack = new ServerSetting();
                                loSettingWriteBack.TotalItems = loDatas;
                                CollectorDataEventArgs argsWriteBack = new CollectorDataEventArgs(loSettingWriteBack);
                                this.OnWriteBHDataChanged(this, argsWriteBack);
                            }
                        }
                    }
                    catch (System.Exception ex)
                    {
                        Debug.Assert(false);
                        Debug.WriteLine(String.Format("failed to send to 24003 error:") + ex.Message);
                    }
                }
            }
            catch (System.Exception ex)
            {
             //   Debug.Assert(false);
                Debug.WriteLine(String.Format("failed to send to 24003 error:") + ex.Message);
            }

            m_nUploadThradCount--;

        }

        public void UploadStatusWebServiceThreadProc(Object obj)
        {
            try
            {
                System.Collections.Generic.List<ItemSetting> loDatas

                    = (System.Collections.Generic.List<ItemSetting>)obj;


                string lstrurl = this.m_oServerSetting.RemoteUrl;

                Boolean lbSucceed = false;

                Boolean lbUseSendTimeStamp = this.m_oServerSetting.UseSendTimeStamp;

                String lstrDateTimeNow = DateTime.Now.ToString();

                if (loDatas != null
                   && loDatas.Count > 0
                   && lstrurl != null
                   && lstrurl.Length > 0)
                {
                    loDatas.Clear();

                    loDatas.AddRange(this.m_oServerSetting.TotalItems);

                    System.Collections.Generic.List<ItemSetting> loDataToSend = new System.Collections.Generic.List<ItemSetting>();

                    int lnGoodPointCount = 0;
                    for (int i = 0; i < loDatas.Count; i++)
                    {
                        Opc.Da.qualityBits lnStatus = (loDatas[i].SourceStatus & Opc.Da.qualityBits.good);

                        if (loDatas[i].SourceStatus != Opc.Da.qualityBits.badNotConnected)
                        {
                            lnGoodPointCount++;
                        }


                        if ((lnStatus != Opc.Da.qualityBits.good))
                        {
                            // loArray.Add(i);
                        }

                        if (loDatas[i].TransferMode == ItemSetting.BH_TRANSFER_MODE.READ)
                        {
                            continue;
                        }


                        if (lbUseSendTimeStamp)
                        {
                            loDatas[i].strUpdateTime = lstrDateTimeNow;
                        }
                        else
                        {
                            loDatas[i].strUpdateTime = loDatas[i].UpdateTime.ToString();
                        }


                        loDataToSend.Add(loDatas[i]);
                    }

                    if (lnGoodPointCount <= 0)
                    {
                        return;
                    }


                    String lstrServerSetting = null;

                    try
                    {
                        lstrServerSetting = Newtonsoft.Json.JsonConvert.SerializeObject
                                   (loDataToSend,
                                    Newtonsoft.Json.Formatting.Indented);
                    }
                    catch (System.Exception ex1)
                    {
                        Debug.Assert(false);
                        ThreadUiController.log(ex1.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
                    }


                    if (lstrServerSetting != null)
                    {
                        try
                        {
                            WebClient client = new WebClient();
                            string postString = String.Format("param={0}", lstrServerSetting);
                            byte[] postData = Encoding.UTF8.GetBytes(postString);
                            client.Headers.Add("Content-Type", "application/x-www-form-urlencoded");
                            byte[] responseData = client.UploadData(lstrurl, "POST", postData);
                            lbSucceed = true;
                        }
                        catch (System.Exception ex)
                        {
                            lbSucceed = false;

                        }

                        if (lbSucceed)
                        {
                            ThreadUiController.InvokeControlCustomMethod3(this,
 new ThreadUiController.MethodCallCaller(this.MainThreadUiFeed), null);
                        }
                    }

                }

                for (int i = 0; i < loDatas.Count; i++)
                {
                    if (lbSucceed)
                    {
                        loDatas[i].DstStatus = Opc.Da.qualityBits.good;
                        loDatas[i].SendTime = System.DateTime.Now;
                    }
                    else
                    {
                        loDatas[i].DstStatus = Opc.Da.qualityBits.badNotConnected;
                    }
                }
                ServerSetting lpSetting = new ServerSetting();
                lpSetting.TotalItems = loDatas;
                CollectorDataEventArgs args = new CollectorDataEventArgs(lpSetting);
                this.OnWriteBHDataChanged(this, args);
            }
            catch (System.Exception ex)
            {
                // Debug.Assert(false);
                Debug.WriteLine(ex.ToString());
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            m_nUploadThradCount--;
        }



        private void OnWriteBHDataChanged(object sender, CollectorDataEventArgs e)
        {
            lock (this)
            {
                this.m_oServerSetting.TotalItems.Clear();
                this.m_oServerSetting.TotalItems.AddRange(e.Setting.TotalItems.ToArray());
                this.EmptyCache();
            }

            ThreadUiController.InvokeControlCustomMethod3(this,
                                new ThreadUiController.MethodCallCaller(this.MainThreadUiOperatorForWriteBack), null);
        }

        private void OnCollectorDataChanged(object sender, CollectorDataEventArgs e)
        {
            lock (this)
            {
                this.m_oServerSetting.TotalItems.Clear();
                this.m_oServerSetting.TotalItems.AddRange(e.Setting.TotalItems.ToArray());
                this.EmptyCache();
            }
            ThreadUiController.InvokeControlCustomMethod3(this,
                            new ThreadUiController.MethodCallCaller(this.MainThreadUiOperator), null);

            try
            {
                UploadStatus();
            }
            catch (Exception e1)
            {
                ThreadUiController.log(e1.Message, ThreadUiController.LOG_LEVEL.FATAL);
            }

        }

        COLLECTOR_STATUS m_nCollectorStatus = COLLECTOR_STATUS.STOPPED;
        public DAQ.COLLECTOR_STATUS CollectorStatus
        {
            get { return m_nCollectorStatus; }
            set { m_nCollectorStatus = value; }
        }
        private void OnCollectorStatusChanged(object sender, CollectorStatusEventArgs e)
        {
            this.CollectorStatus = e.Status;
            ThreadUiController.InvokeControlCustomMethod3(this,
                new ThreadUiController.MethodCallCaller(this.MainThreadUiOperator), null);

        }

        private void StopCollector()
        {
            if (this.m_oServerSetting.TransferSource == ServerSetting.SourceServerType.BH_SERVER)
            {
                this.StopBHCollector();
            }
            else if (this.m_oServerSetting.TransferSource == ServerSetting.SourceServerType.OPC_SERVER)
            {
                this.StopOpcCollector();
            }
            else if (this.m_oServerSetting.TransferSource == ServerSetting.SourceServerType.ASPEN_SERVER)
            {
                this.StopAspenCollector();
            }

            for (int i = 0; i < this.m_oServerSetting.TotalItems.Count; i++)
            {
                this.m_oServerSetting.TotalItems[i].SourceStatus = (Opc.Da.qualityBits.badNotConnected);
                this.m_oServerSetting.TotalItems[i].DstStatus = (Opc.Da.qualityBits.badNotConnected);
            }

            this.Cache = null;
            this.Refresh();
            this.ToggleUI(null);
        }

        private void StartCollector()
        {
            if (this.m_oServerSetting.TotalItems != null && this.m_oServerSetting.TotalItems.Count > 0)
            {
                if (this.m_oServerSetting.TransferSource == ServerSetting.SourceServerType.BH_SERVER)
                {
                    this.StartBHCollector();
                }
                else if (this.m_oServerSetting.TransferSource == ServerSetting.SourceServerType.OPC_SERVER)
                {
                    this.StartOpcCollector();
                }
                else if (this.m_oServerSetting.TransferSource == ServerSetting.SourceServerType.ASPEN_SERVER)
                {
                    this.StartAspenCollector();
                }

                this.UpdateUI();
            }

        }
        private void StopBHCollector()
        {
            if (null != this.BHCollector)
            {
                try
                {
                    this.BHCollector.Stop();
                    this.m_nUploadThradCount = 0;
                }
                catch (System.Exception ex)
                {
                    Debug.Assert(false);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                }

                this.BHCollector = null;
            }

            //    this.m_oDateTimeStartedTime = DateTime.Now;
            this.timer1.Enabled = false;
        }

        private void StopAspenCollector()
        {
            if (null != this.m_oAspenCollector)
            {
                try
                {
                    this.m_oAspenCollector.Stop();
                    this.m_nUploadThradCount = 0;
                }
                catch (System.Exception ex)
                {
                    Debug.Assert(false);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                }

                this.m_oOpcCollector = null;
            }

            //    this.m_oDateTimeStartedTime = DateTime.Now;
            this.timer1.Enabled = false;
        }

        private void StopOpcCollector()
        {
            if (null != this.m_oOpcCollector)
            {
                try
                {
                    this.m_oOpcCollector.Stop();
                    this.m_nUploadThradCount = 0;
                }
                catch (System.Exception ex)
                {
                    Debug.Assert(false);
                    ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.ERROR);
                }

                this.m_oOpcCollector = null;
            }

            //    this.m_oDateTimeStartedTime = DateTime.Now;
            this.timer1.Enabled = false;
        }

        private void StartBHCollector()
        {
            //1.stop previous
            this.StopBHCollector();

            //2.set the data
            try
            {
                this.BHCollector = new DAQ.ThreadBHCollector();
                this.BHCollector.ServerSetting.Machine = this.m_oServerSetting.Machine;
                this.BHCollector.ServerSetting.ProgID = this.m_oServerSetting.ProgID;
                this.BHCollector.ServerSetting.RemoteUrl = this.m_oServerSetting.RemoteUrl;
                this.BHCollector.ServerSetting.TotalItems.AddRange(this.m_oServerSetting.TotalItems.ToArray());
                this.BHCollector.ServerSetting.TimeInterval = this.m_oServerSetting.TimeInterval;
                this.BHCollector.ServerSetting.ServerIp = this.m_oServerSetting.ServerIp;
                this.BHCollector.ServerSetting.ServerPort = this.m_oServerSetting.ServerPort;
                this.BHCollector.ServerSetting.TransferSource = this.m_oServerSetting.TransferSource;
                this.BHCollector.ServerSetting.DstMachine = this.m_oServerSetting.DstMachine;
                this.BHCollector.ServerSetting.DstProgID = this.m_oServerSetting.DstProgID;
                this.BHCollector.ServerSetting.DstServerIp = this.m_oServerSetting.DstServerIp;
                this.BHCollector.ServerSetting.DstServerMode = this.m_oServerSetting.DstServerMode;
                this.BHCollector.ServerSetting.DstServerPort = this.m_oServerSetting.DstServerPort;
                this.BHCollector.ServerSetting.BHServerTpyeDst = this.m_oServerSetting.BHServerTpyeDst;
                this.BHCollector.ServerSetting.BHServerTpyeSrc = this.m_oServerSetting.BHServerTpyeSrc;
                this.BHCollector.ServerSetting.CheckSourceDataUpdate = this.MenuItemForceUpdate.Checked;
                this.BHCollector.ServerSetting.HandleLimitCount = this.m_oServerSetting.HandleLimitCount;
                this.BHCollector.ServerSetting.CheckSourceMiddlewareValid = this.MenuItemCheckMiddleWareValid.Checked;
                this.BHCollector.ServerSetting.CheckAllValid = this.MenuItemCheckAllValid.Checked;
                //3.attach the event
                this.BHCollector.OnCollectorStatusChanged += this.OnCollectorStatusChanged;
                this.BHCollector.OnDataChanged += this.OnCollectorDataChanged;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            //4.start Collector
            try
            {
                this.BHCollector.Start();
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            this.m_oDateTimeStartedTime = DateTime.Now;
            this.timer1.Enabled = true;
        }

        private void StartAspenCollector()
        {
            //1.stop previous
            this.StopAspenCollector();

            //2.set the data
            try
            {
                this.m_oAspenCollector = new DAQ.ThreadAspenCollector();
                this.m_oAspenCollector.ServerSetting.Machine = this.m_oServerSetting.Machine;
                this.m_oAspenCollector.ServerSetting.ProgID = this.m_oServerSetting.ProgID;
                this.m_oAspenCollector.ServerSetting.RemoteUrl = this.m_oServerSetting.RemoteUrl;
                this.m_oAspenCollector.ServerSetting.TotalItems.AddRange(this.m_oServerSetting.TotalItems.ToArray());
                this.m_oAspenCollector.ServerSetting.TimeInterval = this.m_oServerSetting.TimeInterval;

                this.m_oAspenCollector.ServerSetting.DstMachine = this.m_oServerSetting.DstMachine;
                this.m_oAspenCollector.ServerSetting.DstProgID = this.m_oServerSetting.DstProgID;
                this.m_oAspenCollector.ServerSetting.DstServerIp = this.m_oServerSetting.DstServerIp;
                this.m_oAspenCollector.ServerSetting.DstServerMode = this.m_oServerSetting.DstServerMode;
                this.m_oAspenCollector.ServerSetting.DstServerPort = this.m_oServerSetting.DstServerPort;
                this.m_oAspenCollector.ServerSetting.BHServerTpyeDst = this.m_oServerSetting.BHServerTpyeDst;
                this.m_oAspenCollector.ServerSetting.BHServerTpyeSrc = this.m_oServerSetting.BHServerTpyeSrc;
                this.m_oAspenCollector.ServerSetting.CheckSourceDataUpdate = this.MenuItemForceUpdate.Checked;
                this.m_oAspenCollector.ServerSetting.CheckSourceMiddlewareValid = this.MenuItemCheckMiddleWareValid.Checked;
                this.m_oAspenCollector.ServerSetting.CheckAllValid = this.MenuItemCheckAllValid.Checked;
                //                 //3.attach the event
                this.m_oAspenCollector.OnCollectorStatusChanged += this.OnCollectorStatusChanged;
                this.m_oAspenCollector.OnDataChanged += this.OnCollectorDataChanged;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            //4.start Collector
            try
            {
                this.m_oAspenCollector.Start();
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            this.m_oDateTimeStartedTime = DateTime.Now;
            this.timer1.Enabled = true;
        }

        private void StartOpcCollector()
        {
            //1.stop previous
            this.StopOpcCollector();

            //2.set the data
            try
            {
                this.m_oOpcCollector = new DAQ.ThreadOpcCollector();
                this.m_oOpcCollector.ServerSetting.Machine = this.m_oServerSetting.Machine;
                this.m_oOpcCollector.ServerSetting.ProgID = this.m_oServerSetting.ProgID;
                this.m_oOpcCollector.ServerSetting.RemoteUrl = this.m_oServerSetting.RemoteUrl;
                this.m_oOpcCollector.ServerSetting.TotalItems.AddRange(this.m_oServerSetting.TotalItems.ToArray());
                this.m_oOpcCollector.ServerSetting.TimeInterval = this.m_oServerSetting.TimeInterval;


                this.m_oOpcCollector.ServerSetting.DstMachine = this.m_oServerSetting.DstMachine;
                this.m_oOpcCollector.ServerSetting.DstProgID = this.m_oServerSetting.DstProgID;
                this.m_oOpcCollector.ServerSetting.DstServerIp = this.m_oServerSetting.DstServerIp;
                this.m_oOpcCollector.ServerSetting.DstServerMode = this.m_oServerSetting.DstServerMode;
                this.m_oOpcCollector.ServerSetting.DstServerPort = this.m_oServerSetting.DstServerPort;
                this.m_oOpcCollector.ServerSetting.BHServerTpyeDst = this.m_oServerSetting.BHServerTpyeDst;
                this.m_oOpcCollector.ServerSetting.BHServerTpyeSrc = this.m_oServerSetting.BHServerTpyeSrc;
                this.m_oOpcCollector.ServerSetting.CheckSourceDataUpdate = this.MenuItemForceUpdate.Checked;
                this.m_oOpcCollector.ServerSetting.CheckSourceMiddlewareValid = this.MenuItemCheckMiddleWareValid.Checked;
                this.m_oOpcCollector.ServerSetting.OpcUserName = this.m_oServerSetting.OpcUserName;
                this.m_oOpcCollector.ServerSetting.OpcPassword = this.m_oServerSetting.OpcPassword;
                this.m_oOpcCollector.ServerSetting.CheckAllValid = this.m_oServerSetting.CheckAllValid;
                this.m_oOpcCollector.ServerSetting.OpcAsyncRead = this.m_oServerSetting.OpcAsyncRead;
                //                 //3.attach the event
                this.m_oOpcCollector.OnCollectorStatusChanged += this.OnCollectorStatusChanged;
                this.m_oOpcCollector.OnDataChanged += this.OnCollectorDataChanged;
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            //4.start Collector
            try
            {
                this.m_oOpcCollector.Start();
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                ThreadUiController.log(ex.ToString(), ThreadUiController.LOG_LEVEL.FATAL);
            }

            this.m_oDateTimeStartedTime = DateTime.Now;
            this.timer1.Enabled = true;
        }

        private void ToggleUI(ThreadUiController.CallerParameter args)
        {
            if (this.CollectorStatus == COLLECTOR_STATUS.STOPPED)
            {
                this.EnableButton();
            }
            else
            {
                this.DisableButton();
            }
        }

        private void DisableButton()
        {
            this.addToolStripMenuItem.Enabled = false;
            this.deleteToolStripMenuItem.Enabled = false;
            this.ModifytoolStripMenuItem1.Enabled = false;
            this.ServerSettingtoolStripMenuItem2.Enabled = false;
            this.ServerTesttoolStripMenuItem3.Enabled = false;

            this.addToolStripMenuItem1.Enabled = false;
            this.deleteToolStripMenuItem1.Enabled = false;
            this.modifyToolStripMenuItem.Enabled = false;
            this.loadSettingToolStripMenuItem.Enabled = false;
            //  this.saveSettingToolStripMenuItem.Enabled = false;

        }

        private void EnableButton()
        {
            this.addToolStripMenuItem.Enabled = true;
            this.deleteToolStripMenuItem.Enabled = true;
            this.ModifytoolStripMenuItem1.Enabled = true;
            this.ServerSettingtoolStripMenuItem2.Enabled = true;
            this.ServerTesttoolStripMenuItem3.Enabled = true;

            this.addToolStripMenuItem1.Enabled = true;
            this.deleteToolStripMenuItem1.Enabled = true;
            this.modifyToolStripMenuItem.Enabled = true;

            this.loadSettingToolStripMenuItem.Enabled = true;
            this.saveSettingToolStripMenuItem.Enabled = true;
        }

        private void startToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.StartCollector();
        }

        private void stopToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.StopCollector();

            this.CollectorStatus = COLLECTOR_STATUS.STOPPED;
            this.toolStripStatusApplication.Text = "停止(stopped)";

            this.EmptyCache();

            this.UpdateUI();

        }

        private void listView1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private ItemSetting GetListViewItemLinkedRoute(ListViewItem apItem)
        {
            if (apItem != null)
            {
                int lnIndex = apItem.Index;

                ItemSetting lpItem = this.m_oServerSetting.TotalItems[lnIndex];

                return lpItem;
            }
            return null;
        }

        private void ModifyData(ListViewItem apItem)
        {
            Boolean lbCanModify = true;
            ItemSetting lpItem = this.GetListViewItemLinkedRoute(apItem);

            if (lpItem != null && this.CollectorStatus != COLLECTOR_STATUS.STOPPED)
            {
                DialogResult lpResult = MessageBox.Show("修改链接将导致采集停止,确认要继续么\r\nModify Link will cause the collecting to stop, Sure to Continue ?", "请确认(Please Confirm)", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning, MessageBoxDefaultButton.Button2);

                if (lpResult == DialogResult.OK)
                {
                    this.StopCollector();

                    lbCanModify = true;
                }
                else
                {
                    lbCanModify = false;
                }
            }
            if (lbCanModify)
            {
                if (lpItem.ItemType == 0)
                {
                    FormItemSettings loItemSetting = new FormItemSettings();

                    loItemSetting.Item = lpItem;

                    DialogResult loResult = loItemSetting.ShowDialog(this);

                    if (loResult == DialogResult.OK)
                    {
                        lpItem.TagName = loItemSetting.Item.TagName;
                        lpItem.Company = loItemSetting.Item.Company;
                        lpItem.Factory = loItemSetting.Item.Factory;
                        lpItem.Plant = loItemSetting.Item.Plant;
                        lpItem.RemoteTageName = loItemSetting.Item.RemoteTageName;
                        lpItem.StartIndex = loItemSetting.Item.StartIndex;
                        lpItem.Vars = loItemSetting.Item.Vars;
                        lpItem.ScriptContent_Body = loItemSetting.Item.ScriptContent_Body;
                        lpItem.ScriptContent_header = loItemSetting.Item.ScriptContent_header;
                        lpItem.ScriptContent_tail = loItemSetting.Item.ScriptContent_tail;
                        for (int i = 0; i < m_oServerSetting.TotalItems.Count; i++)
                        {
                            if (m_oServerSetting.TotalItems[i].Company == loItemSetting.Item.Company
                                &&
                                m_oServerSetting.TotalItems[i].Factory == loItemSetting.Item.Factory
                                &&
                                m_oServerSetting.TotalItems[i].Plant == loItemSetting.Item.Plant)
                            {
                                m_oServerSetting.TotalItems[i].StartIndex = loItemSetting.Item.StartIndex;
                            }
                        }
                        this.EmptyCache();
                        this.UpdateUI();
                    }
                }
                else
                {
                    FunctionItemSetting loItemSetting = new FunctionItemSetting();

                    loItemSetting.AllItems = this.m_oServerSetting.TotalItems;

                    loItemSetting.Item = lpItem;

                    DialogResult loResult = loItemSetting.ShowDialog(this);

                    if (loResult == DialogResult.OK)
                    {

                        lpItem.TagName = loItemSetting.Item.TagName;
                        lpItem.Company = loItemSetting.Item.Company;
                        lpItem.Factory = loItemSetting.Item.Factory;
                        lpItem.Plant = loItemSetting.Item.Plant;
                        lpItem.RemoteTageName = loItemSetting.Item.RemoteTageName;
                        lpItem.StartIndex = loItemSetting.Item.StartIndex;
                        for (int i = 0; i < m_oServerSetting.TotalItems.Count; i++)
                        {
                            if (m_oServerSetting.TotalItems[i].Company == loItemSetting.Item.Company
                                &&
                                m_oServerSetting.TotalItems[i].Factory == loItemSetting.Item.Factory
                                &&
                                m_oServerSetting.TotalItems[i].Plant == loItemSetting.Item.Plant)
                            {
                                m_oServerSetting.TotalItems[i].StartIndex = loItemSetting.Item.StartIndex;
                            }
                        }
                        this.EmptyCache();
                        this.UpdateUI();
                    }
                }

            }
        }

        private void listView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            ListViewItem lpItem = listView1.GetItemAt(e.X, e.Y);

            if (lpItem != null)
            {
                Debug.WriteLine("test");
                this.ModifyData(lpItem);
            }
            else
            {
                Debug.WriteLine("None");
            }
        }

        private void FormMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                e.Cancel = true;
                this.Hide();
            }
            catch (System.Exception ex)
            {

            }
        }

        [DllImport("user32.dll", EntryPoint = "SetForegroundWindow")]
        public static extern bool SetForegroundWindow(IntPtr hWnd);

        private void ShowMainWindow()
        {
            this.Visible = true;
            this.WindowState = FormWindowState.Normal;
            SetForegroundWindow(this.Handle);
        }

        private void notifyIcon1_BalloonTipClicked(object sender, EventArgs e)
        {
            this.ShowMainWindow();
        }

        private void notifyIcon1_DoubleClick(object sender, EventArgs e)
        {
            this.ShowMainWindow();
        }

        private void notifyIcon1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                if (this.Visible)
                {
                    this.Visible = false;
                }
                else
                {
                    this.ShowMainWindow();
                }
            }
        }

        private void Quit()
        {

            try
            {
                this.StopCollector();
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.Message);
            }
            try
            {
                try
                {
                    Application.ExitThread();
                }
                catch (System.Exception ex1)
                {
                    Debug.Assert(false);
                    Debug.WriteLine(ex1.Message);
                }
                System.Environment.Exit(0);
            }
            catch (System.Exception ex)
            {
                Debug.Assert(false);
                Debug.WriteLine(ex.Message);
            }
        }


        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Quit();
        }

        private void showToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Show();
            this.WindowState = FormWindowState.Normal;
            SetForegroundWindow(this.Handle);
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            try
            {
                this.StartCollector();
            }
            catch (System.Exception ex)
            {

            }
        }

        private void toolStripMenuItem2_Click_1(object sender, EventArgs e)
        {
            try
            {
                this.StopCollector();
            }
            catch (System.Exception ex)
            {

            }
        }

        private void exitToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.Quit();
        }

        private void SelectAll()
        {
            for (int i = 0; i < this.listView1.Items.Count; i++)
            {
                ListViewItem lpItem = this.listView1.Items[i];
                lpItem.Selected = true;
            }
        }

        private void RevertSelectAll()
        {
            for (int i = 0; i < this.listView1.Items.Count; i++)
            {
                ListViewItem lpItem = this.listView1.Items[i];
                lpItem.Selected = !lpItem.Selected;
            }
        }

        private void selectAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.SelectAll();
        }

        private void revertSelectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.RevertSelectAll();
        }

        private void listView1_KeyDown(object sender, KeyEventArgs e)
        {
            if ((Control.ModifierKeys & Keys.Control) != 0 && (e.KeyCode == Keys.A))
            {
                this.SelectAll();
            }
            else
            {
                if (e.KeyCode == Keys.Insert)
                {
                    this.AddItem();
                }
                else if (e.KeyCode == Keys.Delete)
                {
                    this.DeleteSelected();
                }
                else if (e.KeyCode == Keys.E || e.KeyCode == Keys.Enter)
                {

                }
                else if (e.KeyCode == Keys.Escape)
                {
                    this.Close();
                }
                else if (e.KeyCode == Keys.R)
                {

                }
                else if (e.KeyCode == Keys.Q)
                {

                }
            }
        }

        private void selectAllToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.SelectAll();
        }

        private void revertSelectToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.RevertSelectAll();
        }

        private void addToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.AddItem();
        }

        private void modifyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int lnSelectedIndex = this.GetFirstSelectedItem();
            if (lnSelectedIndex > 0)
            {
                ListViewItem lpItem = this.listView1.Items[lnSelectedIndex];

                this.ModifyData(lpItem);
            }
        }

        private void ModifytoolStripMenuItem1_Click(object sender, EventArgs e)
        {
            int lnSelectedIndex = this.GetFirstSelectedItem();
            if (lnSelectedIndex > 0)
            {
                ListViewItem lpItem = this.listView1.Items[lnSelectedIndex];

                this.ModifyData(lpItem);
            }
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void deleteToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.DeleteSelected();
        }

        private void startToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.StartCollector();
        }

        private void stopToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.StopCollector();

            this.CollectorStatus = COLLECTOR_STATUS.STOPPED;

            this.EmptyCache();

            this.UpdateUI();
        }



        private void MenuItemForceUpdate_MouseUp(object sender, MouseEventArgs e)
        {
            this.MenuItemForceUpdate.Checked = !this.MenuItemForceUpdate.Checked;
            this.m_oServerSetting.CheckSourceDataUpdate = this.MenuItemForceUpdate.Checked;
            if (this.m_oBHCollector != null)
            {

                this.m_oBHCollector.ServerSetting.CheckSourceDataUpdate = this.MenuItemForceUpdate.Checked;
            }

            if (this.m_oAspenCollector != null)
            {
                this.m_oAspenCollector.ServerSetting.CheckSourceDataUpdate = this.MenuItemForceUpdate.Checked;
            }
            if (this.m_oCollector != null)
            {
                this.m_oCollector.ServerSetting.CheckSourceDataUpdate = this.MenuItemForceUpdate.Checked;

            }

        }

        private void menuStrip_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void toolStripMenuItemCheckMiddleWareValid_MouseUp(object sender, MouseEventArgs e)
        {
            this.MenuItemCheckMiddleWareValid.Checked = !this.MenuItemCheckMiddleWareValid.Checked;
            this.m_oServerSetting.CheckSourceMiddlewareValid = this.MenuItemCheckMiddleWareValid.Checked;
            if (this.m_oBHCollector != null)
            {

                this.m_oBHCollector.ServerSetting.CheckSourceMiddlewareValid = this.MenuItemCheckMiddleWareValid.Checked;
            }

            if (this.m_oAspenCollector != null)
            {
                this.m_oAspenCollector.ServerSetting.CheckSourceMiddlewareValid = this.MenuItemCheckMiddleWareValid.Checked;
            }
            if (this.m_oCollector != null)
            {
                this.m_oCollector.ServerSetting.CheckSourceMiddlewareValid = this.MenuItemCheckMiddleWareValid.Checked;

            }

        }

        private void toolStripMenuItemCheckAllValid_Click(object sender, EventArgs e)
        {

        }

        private void MenuItemCheckMiddleWareValid_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItemCheckAllValid_MouseUp(object sender, MouseEventArgs e)
        {
            this.MenuItemCheckAllValid.Checked = !this.MenuItemCheckAllValid.Checked;
            this.m_oServerSetting.CheckAllValid = this.MenuItemCheckAllValid.Checked;
            if (this.m_oBHCollector != null)
            {

                this.m_oBHCollector.ServerSetting.CheckAllValid = this.MenuItemCheckAllValid.Checked;
            }

            if (this.m_oAspenCollector != null)
            {
                this.m_oAspenCollector.ServerSetting.CheckAllValid = this.MenuItemCheckAllValid.Checked;
            }
            if (this.m_oCollector != null)
            {
                this.m_oCollector.ServerSetting.CheckAllValid = this.MenuItemCheckAllValid.Checked;

            }
        }

        private void toolStripMenuItemApplicationSetting_Click(object sender, EventArgs e)
        {
            FormAppSetting loAppSetting = new FormAppSetting();
            loAppSetting.TitleName = this.m_oServerSetting.TitleName;
            System.Windows.Forms.DialogResult loResult = loAppSetting.ShowDialog(this);
            if (loResult == DialogResult.OK && !(String.IsNullOrEmpty(loAppSetting.TitleName)))
            {
                this.m_oServerSetting.TitleName = loAppSetting.TitleName;
                this.Text = this.m_oServerSetting.TitleName;
                this.notifyIcon1.Text = this.m_oServerSetting.TitleName;
                //  this.SaveSetting();
            }

        }



        private void AboutToolStripMenuItem1_Click_1(object sender, EventArgs e)
        {
            FormAbout about = new FormAbout();
            about.ShowDialog(this);

        }

        private void toolStripMenuItem3_MouseUp(object sender, MouseEventArgs e)
        {
            this.toolStripMenuItemUseSendTimeStamp.Checked = !this.toolStripMenuItemUseSendTimeStamp.Checked;
            this.m_oServerSetting.UseSendTimeStamp = this.toolStripMenuItemUseSendTimeStamp.Checked;
            if (this.m_oBHCollector != null)
            {

                this.m_oBHCollector.ServerSetting.UseSendTimeStamp = this.toolStripMenuItemUseSendTimeStamp.Checked;
            }

            if (this.m_oAspenCollector != null)
            {
                this.m_oAspenCollector.ServerSetting.UseSendTimeStamp = this.toolStripMenuItemUseSendTimeStamp.Checked;
            }
            if (this.m_oCollector != null)
            {
                this.m_oCollector.ServerSetting.UseSendTimeStamp = this.toolStripMenuItemUseSendTimeStamp.Checked;
            }
        }
    }
}
