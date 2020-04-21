namespace DAQ
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusApplication = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.configToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItemApplicationSetting = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator10 = new System.Windows.Forms.ToolStripSeparator();
            this.ServerSettingtoolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.ServerTesttoolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.loadSettingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveSettingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.MenuItemForceUpdate = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemCheckMiddleWareValid = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemCheckAllValid = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.operateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.selectAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.revertSelectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.addToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ModifytoolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.startToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stopToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.关于AboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.AboutToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.listView1 = new System.Windows.Forms.ListView();
            this.TagName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.Value = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.Company = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.Factory = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.Plant = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.RemoteTagName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.UpdateTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SendTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.UpdateCount = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SourceStatus = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.DstStatus = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.contextMenuStrip2 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.selectAllToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.revertSelectToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.addToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.modifyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator7 = new System.Windows.Forms.ToolStripSeparator();
            this.startToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.stopToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.notifyIcon1 = new System.Windows.Forms.NotifyIcon(this.components);
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.showToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItemUseSendTimeStamp = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip.SuspendLayout();
            this.menuStrip.SuspendLayout();
            this.contextMenuStrip2.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.toolStripStatusApplication});
            this.statusStrip.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.HorizontalStackWithOverflow;
            this.statusStrip.Location = new System.Drawing.Point(0, 294);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(951, 22);
            this.statusStrip.TabIndex = 0;
            this.statusStrip.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(56, 17);
            this.toolStripStatusLabel1.Text = "00:00:00";
            // 
            // toolStripStatusApplication
            // 
            this.toolStripStatusApplication.Name = "toolStripStatusApplication";
            this.toolStripStatusApplication.Size = new System.Drawing.Size(90, 17);
            this.toolStripStatusApplication.Text = "停止(Stopped)";
            // 
            // menuStrip
            // 
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.configToolStripMenuItem,
            this.operateToolStripMenuItem,
            this.关于AboutToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(951, 25);
            this.menuStrip.TabIndex = 1;
            this.menuStrip.Text = "menuStrip";
            this.menuStrip.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.menuStrip_ItemClicked);
            // 
            // configToolStripMenuItem
            // 
            this.configToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItemApplicationSetting,
            this.toolStripSeparator10,
            this.ServerSettingtoolStripMenuItem2,
            this.ServerTesttoolStripMenuItem3,
            this.toolStripSeparator3,
            this.loadSettingToolStripMenuItem,
            this.saveSettingToolStripMenuItem,
            this.toolStripSeparator5,
            this.MenuItemForceUpdate,
            this.MenuItemCheckMiddleWareValid,
            this.MenuItemCheckAllValid,
            this.toolStripMenuItemUseSendTimeStamp,
            this.toolStripSeparator8,
            this.exitToolStripMenuItem1});
            this.configToolStripMenuItem.Name = "configToolStripMenuItem";
            this.configToolStripMenuItem.Size = new System.Drawing.Size(71, 21);
            this.configToolStripMenuItem.Text = "文件(&File)";
            // 
            // toolStripMenuItemApplicationSetting
            // 
            this.toolStripMenuItemApplicationSetting.Name = "toolStripMenuItemApplicationSetting";
            this.toolStripMenuItemApplicationSetting.Size = new System.Drawing.Size(307, 22);
            this.toolStripMenuItemApplicationSetting.Text = "应用设置(App Setting)";
            this.toolStripMenuItemApplicationSetting.Click += new System.EventHandler(this.toolStripMenuItemApplicationSetting_Click);
            // 
            // toolStripSeparator10
            // 
            this.toolStripSeparator10.Name = "toolStripSeparator10";
            this.toolStripSeparator10.Size = new System.Drawing.Size(304, 6);
            // 
            // ServerSettingtoolStripMenuItem2
            // 
            this.ServerSettingtoolStripMenuItem2.Name = "ServerSettingtoolStripMenuItem2";
            this.ServerSettingtoolStripMenuItem2.Size = new System.Drawing.Size(307, 22);
            this.ServerSettingtoolStripMenuItem2.Text = "服务器设置(Server Setting)";
            this.ServerSettingtoolStripMenuItem2.Click += new System.EventHandler(this.toolStripMenuItemServerSetting_Click);
            // 
            // ServerTesttoolStripMenuItem3
            // 
            this.ServerTesttoolStripMenuItem3.Name = "ServerTesttoolStripMenuItem3";
            this.ServerTesttoolStripMenuItem3.Size = new System.Drawing.Size(307, 22);
            this.ServerTesttoolStripMenuItem3.Text = "服务器测试(Server Test)";
            this.ServerTesttoolStripMenuItem3.Click += new System.EventHandler(this.toolStripMenuItem3_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(304, 6);
            // 
            // loadSettingToolStripMenuItem
            // 
            this.loadSettingToolStripMenuItem.Name = "loadSettingToolStripMenuItem";
            this.loadSettingToolStripMenuItem.Size = new System.Drawing.Size(307, 22);
            this.loadSettingToolStripMenuItem.Text = "加载配置(&Load Setting)";
            this.loadSettingToolStripMenuItem.Click += new System.EventHandler(this.loadSettingToolStripMenuItem_Click);
            // 
            // saveSettingToolStripMenuItem
            // 
            this.saveSettingToolStripMenuItem.Name = "saveSettingToolStripMenuItem";
            this.saveSettingToolStripMenuItem.Size = new System.Drawing.Size(307, 22);
            this.saveSettingToolStripMenuItem.Text = "保存配置(&Save Setting)";
            this.saveSettingToolStripMenuItem.Click += new System.EventHandler(this.saveSettingToolStripMenuItem_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(304, 6);
            // 
            // MenuItemForceUpdate
            // 
            this.MenuItemForceUpdate.Name = "MenuItemForceUpdate";
            this.MenuItemForceUpdate.Size = new System.Drawing.Size(307, 22);
            this.MenuItemForceUpdate.Text = "检查数据更新(Check Update)";
            this.MenuItemForceUpdate.MouseUp += new System.Windows.Forms.MouseEventHandler(this.MenuItemForceUpdate_MouseUp);
            // 
            // MenuItemCheckMiddleWareValid
            // 
            this.MenuItemCheckMiddleWareValid.Name = "MenuItemCheckMiddleWareValid";
            this.MenuItemCheckMiddleWareValid.Size = new System.Drawing.Size(307, 22);
            this.MenuItemCheckMiddleWareValid.Text = "检查中间件状态(Check Middleware valid)";
            this.MenuItemCheckMiddleWareValid.Click += new System.EventHandler(this.MenuItemCheckMiddleWareValid_Click);
            this.MenuItemCheckMiddleWareValid.MouseUp += new System.Windows.Forms.MouseEventHandler(this.toolStripMenuItemCheckMiddleWareValid_MouseUp);
            // 
            // MenuItemCheckAllValid
            // 
            this.MenuItemCheckAllValid.Name = "MenuItemCheckAllValid";
            this.MenuItemCheckAllValid.Size = new System.Drawing.Size(307, 22);
            this.MenuItemCheckAllValid.Text = "是否测点必须全有效(Check all Valid)";
            this.MenuItemCheckAllValid.Click += new System.EventHandler(this.toolStripMenuItemCheckAllValid_Click);
            this.MenuItemCheckAllValid.MouseUp += new System.Windows.Forms.MouseEventHandler(this.toolStripMenuItemCheckAllValid_MouseUp);
            // 
            // toolStripSeparator8
            // 
            this.toolStripSeparator8.Name = "toolStripSeparator8";
            this.toolStripSeparator8.Size = new System.Drawing.Size(304, 6);
            // 
            // exitToolStripMenuItem1
            // 
            this.exitToolStripMenuItem1.Name = "exitToolStripMenuItem1";
            this.exitToolStripMenuItem1.Size = new System.Drawing.Size(307, 22);
            this.exitToolStripMenuItem1.Text = "退出(&Exit)";
            this.exitToolStripMenuItem1.Click += new System.EventHandler(this.exitToolStripMenuItem1_Click);
            // 
            // operateToolStripMenuItem
            // 
            this.operateToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.selectAllToolStripMenuItem,
            this.revertSelectToolStripMenuItem,
            this.toolStripSeparator1,
            this.addToolStripMenuItem,
            this.deleteToolStripMenuItem,
            this.ModifytoolStripMenuItem1,
            this.toolStripSeparator2,
            this.startToolStripMenuItem,
            this.stopToolStripMenuItem});
            this.operateToolStripMenuItem.Name = "operateToolStripMenuItem";
            this.operateToolStripMenuItem.Size = new System.Drawing.Size(100, 21);
            this.operateToolStripMenuItem.Text = "操作(&Operate)";
            // 
            // selectAllToolStripMenuItem
            // 
            this.selectAllToolStripMenuItem.Name = "selectAllToolStripMenuItem";
            this.selectAllToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.selectAllToolStripMenuItem.Text = "全选(&Select All)";
            this.selectAllToolStripMenuItem.Click += new System.EventHandler(this.selectAllToolStripMenuItem_Click);
            // 
            // revertSelectToolStripMenuItem
            // 
            this.revertSelectToolStripMenuItem.Name = "revertSelectToolStripMenuItem";
            this.revertSelectToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.revertSelectToolStripMenuItem.Text = "反选(&Revert Select）";
            this.revertSelectToolStripMenuItem.Click += new System.EventHandler(this.revertSelectToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(188, 6);
            // 
            // addToolStripMenuItem
            // 
            this.addToolStripMenuItem.Name = "addToolStripMenuItem";
            this.addToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.addToolStripMenuItem.Text = "增加(&Add)";
            this.addToolStripMenuItem.Click += new System.EventHandler(this.addToolStripMenuItem_Click);
            // 
            // deleteToolStripMenuItem
            // 
            this.deleteToolStripMenuItem.Name = "deleteToolStripMenuItem";
            this.deleteToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.deleteToolStripMenuItem.Text = "删除(&Delete)";
            this.deleteToolStripMenuItem.Click += new System.EventHandler(this.dToolStripMenuItem_Click);
            // 
            // ModifytoolStripMenuItem1
            // 
            this.ModifytoolStripMenuItem1.Name = "ModifytoolStripMenuItem1";
            this.ModifytoolStripMenuItem1.Size = new System.Drawing.Size(191, 22);
            this.ModifytoolStripMenuItem1.Text = "修改(&Modify)";
            this.ModifytoolStripMenuItem1.Click += new System.EventHandler(this.ModifytoolStripMenuItem1_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(188, 6);
            // 
            // startToolStripMenuItem
            // 
            this.startToolStripMenuItem.Name = "startToolStripMenuItem";
            this.startToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.startToolStripMenuItem.Text = "启动(S&tart)";
            this.startToolStripMenuItem.Click += new System.EventHandler(this.startToolStripMenuItem_Click);
            // 
            // stopToolStripMenuItem
            // 
            this.stopToolStripMenuItem.Name = "stopToolStripMenuItem";
            this.stopToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.stopToolStripMenuItem.Text = "停止(Sto&p)";
            this.stopToolStripMenuItem.Click += new System.EventHandler(this.stopToolStripMenuItem_Click);
            // 
            // 关于AboutToolStripMenuItem
            // 
            this.关于AboutToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.AboutToolStripMenuItem1});
            this.关于AboutToolStripMenuItem.Name = "关于AboutToolStripMenuItem";
            this.关于AboutToolStripMenuItem.Size = new System.Drawing.Size(79, 21);
            this.关于AboutToolStripMenuItem.Text = "帮助(&Help)";
            // 
            // AboutToolStripMenuItem1
            // 
            this.AboutToolStripMenuItem1.Name = "AboutToolStripMenuItem1";
            this.AboutToolStripMenuItem1.Size = new System.Drawing.Size(143, 22);
            this.AboutToolStripMenuItem1.Text = "关于(&About)";
            this.AboutToolStripMenuItem1.Click += new System.EventHandler(this.AboutToolStripMenuItem1_Click_1);
            // 
            // listView1
            // 
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.TagName,
            this.Value,
            this.Company,
            this.Factory,
            this.Plant,
            this.RemoteTagName,
            this.UpdateTime,
            this.SendTime,
            this.UpdateCount,
            this.SourceStatus,
            this.DstStatus});
            this.listView1.ContextMenuStrip = this.contextMenuStrip2;
            this.listView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listView1.FullRowSelect = true;
            this.listView1.GridLines = true;
            this.listView1.HideSelection = false;
            this.listView1.Location = new System.Drawing.Point(0, 25);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(951, 269);
            this.listView1.TabIndex = 2;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.VirtualMode = true;
            this.listView1.CacheVirtualItems += new System.Windows.Forms.CacheVirtualItemsEventHandler(this.listView1_CacheVirtualItems);
            this.listView1.RetrieveVirtualItem += new System.Windows.Forms.RetrieveVirtualItemEventHandler(this.listView1_RetrieveVirtualItem);
            this.listView1.SearchForVirtualItem += new System.Windows.Forms.SearchForVirtualItemEventHandler(this.listView1_SearchForVirtualItem);
            this.listView1.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged);
            this.listView1.VirtualItemsSelectionRangeChanged += new System.Windows.Forms.ListViewVirtualItemsSelectionRangeChangedEventHandler(this.listView1_VirtualItemsSelectionRangeChanged);
            this.listView1.KeyDown += new System.Windows.Forms.KeyEventHandler(this.listView1_KeyDown);
            this.listView1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.listView1_MouseClick);
            this.listView1.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.listView1_MouseDoubleClick);
            // 
            // TagName
            // 
            this.TagName.Text = "位号(TagName)";
            this.TagName.Width = 149;
            // 
            // Value
            // 
            this.Value.DisplayIndex = 5;
            this.Value.Text = "值(Value)";
            this.Value.Width = 141;
            // 
            // Company
            // 
            this.Company.DisplayIndex = 1;
            this.Company.Text = "公司(Company)";
            this.Company.Width = 141;
            // 
            // Factory
            // 
            this.Factory.DisplayIndex = 2;
            this.Factory.Text = "分厂(Factory)";
            this.Factory.Width = 141;
            // 
            // Plant
            // 
            this.Plant.DisplayIndex = 3;
            this.Plant.Text = "设备(Plant)";
            this.Plant.Width = 141;
            // 
            // RemoteTagName
            // 
            this.RemoteTagName.DisplayIndex = 4;
            this.RemoteTagName.Text = "BH位号(BH TagName)";
            this.RemoteTagName.Width = 141;
            // 
            // UpdateTime
            // 
            this.UpdateTime.DisplayIndex = 7;
            this.UpdateTime.Text = "更新时间(UpdateTime)";
            this.UpdateTime.Width = 141;
            // 
            // SendTime
            // 
            this.SendTime.DisplayIndex = 6;
            this.SendTime.Text = "发送时间(SendTime)";
            this.SendTime.Width = 141;
            // 
            // UpdateCount
            // 
            this.UpdateCount.Text = "更新次数(Update Count)";
            this.UpdateCount.Width = 141;
            // 
            // SourceStatus
            // 
            this.SourceStatus.Text = "数据源状态(Source Status)";
            this.SourceStatus.Width = 141;
            // 
            // DstStatus
            // 
            this.DstStatus.Text = "目标状态(Dst Status)";
            this.DstStatus.Width = 141;
            // 
            // contextMenuStrip2
            // 
            this.contextMenuStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.selectAllToolStripMenuItem1,
            this.revertSelectToolStripMenuItem1,
            this.toolStripSeparator6,
            this.addToolStripMenuItem1,
            this.modifyToolStripMenuItem,
            this.deleteToolStripMenuItem1,
            this.toolStripSeparator7,
            this.startToolStripMenuItem1,
            this.stopToolStripMenuItem1});
            this.contextMenuStrip2.Name = "contextMenuStrip2";
            this.contextMenuStrip2.Size = new System.Drawing.Size(184, 170);
            // 
            // selectAllToolStripMenuItem1
            // 
            this.selectAllToolStripMenuItem1.Name = "selectAllToolStripMenuItem1";
            this.selectAllToolStripMenuItem1.Size = new System.Drawing.Size(183, 22);
            this.selectAllToolStripMenuItem1.Text = "全选(Select All)";
            this.selectAllToolStripMenuItem1.Click += new System.EventHandler(this.selectAllToolStripMenuItem1_Click);
            // 
            // revertSelectToolStripMenuItem1
            // 
            this.revertSelectToolStripMenuItem1.Name = "revertSelectToolStripMenuItem1";
            this.revertSelectToolStripMenuItem1.Size = new System.Drawing.Size(183, 22);
            this.revertSelectToolStripMenuItem1.Text = "反选(Revert Select)";
            this.revertSelectToolStripMenuItem1.Click += new System.EventHandler(this.revertSelectToolStripMenuItem1_Click);
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(180, 6);
            // 
            // addToolStripMenuItem1
            // 
            this.addToolStripMenuItem1.Name = "addToolStripMenuItem1";
            this.addToolStripMenuItem1.Size = new System.Drawing.Size(183, 22);
            this.addToolStripMenuItem1.Text = "增加(Add)";
            this.addToolStripMenuItem1.Click += new System.EventHandler(this.addToolStripMenuItem1_Click);
            // 
            // modifyToolStripMenuItem
            // 
            this.modifyToolStripMenuItem.Name = "modifyToolStripMenuItem";
            this.modifyToolStripMenuItem.Size = new System.Drawing.Size(183, 22);
            this.modifyToolStripMenuItem.Text = "修改(Modify)";
            this.modifyToolStripMenuItem.Click += new System.EventHandler(this.modifyToolStripMenuItem_Click);
            // 
            // deleteToolStripMenuItem1
            // 
            this.deleteToolStripMenuItem1.Name = "deleteToolStripMenuItem1";
            this.deleteToolStripMenuItem1.Size = new System.Drawing.Size(183, 22);
            this.deleteToolStripMenuItem1.Text = "删除(Delete)";
            this.deleteToolStripMenuItem1.Click += new System.EventHandler(this.deleteToolStripMenuItem1_Click);
            // 
            // toolStripSeparator7
            // 
            this.toolStripSeparator7.Name = "toolStripSeparator7";
            this.toolStripSeparator7.Size = new System.Drawing.Size(180, 6);
            // 
            // startToolStripMenuItem1
            // 
            this.startToolStripMenuItem1.Name = "startToolStripMenuItem1";
            this.startToolStripMenuItem1.Size = new System.Drawing.Size(183, 22);
            this.startToolStripMenuItem1.Text = "启动(Start)";
            this.startToolStripMenuItem1.Click += new System.EventHandler(this.startToolStripMenuItem1_Click);
            // 
            // stopToolStripMenuItem1
            // 
            this.stopToolStripMenuItem1.Name = "stopToolStripMenuItem1";
            this.stopToolStripMenuItem1.Size = new System.Drawing.Size(183, 22);
            this.stopToolStripMenuItem1.Text = "停止(Stop)";
            this.stopToolStripMenuItem1.Click += new System.EventHandler(this.stopToolStripMenuItem1_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // notifyIcon1
            // 
            this.notifyIcon1.BalloonTipIcon = System.Windows.Forms.ToolTipIcon.Info;
            this.notifyIcon1.ContextMenuStrip = this.contextMenuStrip1;
            this.notifyIcon1.Icon = ((System.Drawing.Icon)(resources.GetObject("notifyIcon1.Icon")));
            this.notifyIcon1.Text = "DAQ-OPC";
            this.notifyIcon1.Visible = true;
            this.notifyIcon1.BalloonTipClicked += new System.EventHandler(this.notifyIcon1_BalloonTipClicked);
            this.notifyIcon1.DoubleClick += new System.EventHandler(this.notifyIcon1_DoubleClick);
            this.notifyIcon1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.notifyIcon1_MouseDown);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.toolStripMenuItem2,
            this.toolStripSeparator4,
            this.showToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(140, 98);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(139, 22);
            this.toolStripMenuItem1.Text = "开始(Start)";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(139, 22);
            this.toolStripMenuItem2.Text = "停止(Stop)";
            this.toolStripMenuItem2.Click += new System.EventHandler(this.toolStripMenuItem2_Click_1);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(136, 6);
            // 
            // showToolStripMenuItem
            // 
            this.showToolStripMenuItem.Name = "showToolStripMenuItem";
            this.showToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.showToolStripMenuItem.Text = "显示(&Show)";
            this.showToolStripMenuItem.Click += new System.EventHandler(this.showToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.exitToolStripMenuItem.Text = "退出(&Exit)";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // toolStripMenuItemUseSendTimeStamp
            // 
            this.toolStripMenuItemUseSendTimeStamp.Name = "toolStripMenuItemUseSendTimeStamp";
            this.toolStripMenuItemUseSendTimeStamp.Size = new System.Drawing.Size(307, 22);
            this.toolStripMenuItemUseSendTimeStamp.Text = "使用发送时间戳(Use send time stamp)";
            this.toolStripMenuItemUseSendTimeStamp.MouseUp += new System.Windows.Forms.MouseEventHandler(this.toolStripMenuItem3_MouseUp);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(951, 316);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.statusStrip);
            this.Controls.Add(this.menuStrip);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip;
            this.Name = "FormMain";
            this.Text = "DAQ-数据处理器";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormMain_FormClosing);
            this.Load += new System.EventHandler(this.Main_Load);
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.contextMenuStrip2.ResumeLayout(false);
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem configToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadSettingToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveSettingToolStripMenuItem;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ToolStripMenuItem operateToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem selectAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem revertSelectToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem addToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ModifytoolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem startToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem stopToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ServerSettingtoolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem ServerTesttoolStripMenuItem3;
        private System.Windows.Forms.ColumnHeader TagName;
        private System.Windows.Forms.ColumnHeader Value;
        private System.Windows.Forms.ColumnHeader Company;
        private System.Windows.Forms.ColumnHeader Factory;
        private System.Windows.Forms.ColumnHeader Plant;
        private System.Windows.Forms.ColumnHeader RemoteTagName;
        private System.Windows.Forms.ColumnHeader UpdateTime;
        private System.Windows.Forms.ColumnHeader SendTime;
        private System.Windows.Forms.ColumnHeader UpdateCount;
        private System.Windows.Forms.ColumnHeader SourceStatus;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.NotifyIcon notifyIcon1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem showToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip2;
        private System.Windows.Forms.ToolStripMenuItem selectAllToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem revertSelectToolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator6;
        private System.Windows.Forms.ToolStripMenuItem addToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem modifyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator7;
        private System.Windows.Forms.ToolStripMenuItem startToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem stopToolStripMenuItem1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.ColumnHeader DstStatus;
        private System.Windows.Forms.ToolStripMenuItem MenuItemForceUpdate;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator8;
        private System.Windows.Forms.ToolStripMenuItem MenuItemCheckMiddleWareValid;
        private System.Windows.Forms.ToolStripMenuItem MenuItemCheckAllValid;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemApplicationSetting;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator10;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem 关于AboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem AboutToolStripMenuItem1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusApplication;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemUseSendTimeStamp;
    }
}