//============================================================================
// TITLE: MainForm.cs
//
// CONTENTS:
// 
// The main application window for the OPC .NET API Sample Client sample client.
//
// (c) Copyright 2003 The OPC Foundation
// ALL RIGHTS RESERVED.
//
// DISCLAIMER:
//  This code is provided by the OPC Foundation solely to assist in 
//  understanding and use of the appropriate OPC Specification(s) and may be 
//  used as set forth in the License Grant section of the OPC Specification.
//  This code is provided as-is and without warranty or support of any sort
//  and is subject to the Warranty and Liability Disclaimers which appear
//  in the printed OPC Specification.
//
// MODIFICATION LOG:
//
// Date       By    Notes
// ---------- ---   -----
// 2003/03/26 RSA   Initial implementation.

using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.IO;
using System.Net;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Security;
using System.Security.Permissions;
using System.Xml;
using System.Reflection;
using System.Threading;
using Opc;
using Opc.Da;
using Opc.Cpx;
using Opc.Dx;
using Opc.SampleClient;

namespace Opc.Da.SampleClient
{
	/// <summary>
	/// The main application window for the OPC .NET API sample client.
	/// </summary>
	public class MainForm : System.Windows.Forms.Form
	{
		private System.Windows.Forms.MainMenu MainMenu;
		private System.Windows.Forms.MenuItem FileMI;
		private System.Windows.Forms.ToolBar ToolBar;
		private System.Windows.Forms.ToolBarButton LoadBTN;
		private System.Windows.Forms.Panel BottomPN;
		private System.Windows.Forms.RichTextBox OutputCTRL;
		private System.Windows.Forms.Splitter SplitterH;
		private System.Windows.Forms.Splitter SplitterV;
		private System.Windows.Forms.Panel LeftPN;
		private System.Windows.Forms.Panel RightPN;
		private Opc.SampleClient.SelectServerCtrl SelectServerCTRL;
		private Opc.SampleClient.SelectServerCtrl SelectTargetCTRL;
		private Opc.Da.SampleClient.SubscriptionsTreeCtrl SubscriptionCTRL;
		private Opc.Da.SampleClient.ServerStatusCtrl StatusCTRL;
		private Opc.Da.SampleClient.UpdatesListViewCtrl UpdatesCTRL;
		private System.Windows.Forms.MenuItem LoadMI;
		private System.Windows.Forms.MenuItem SaveMI;
		private System.Windows.Forms.MenuItem ExitMI;
		private System.Windows.Forms.MenuItem SeparatorF1;
		private System.Windows.Forms.MenuItem ServerMI;
		private System.Windows.Forms.MenuItem ConnectMI;
		private System.Windows.Forms.MenuItem DisconnecMI;
		private System.Windows.Forms.MenuItem ViewStatusMI;
		private System.Windows.Forms.MenuItem BrowseMI;
		private System.Windows.Forms.MenuItem ReadMI;
		private System.Windows.Forms.MenuItem WriteMI;
		private System.Windows.Forms.MenuItem SeparatorS1;
		private System.Windows.Forms.MenuItem SeparatorS2;
		private System.Windows.Forms.MenuItem HelpMI;
		private System.Windows.Forms.MenuItem AboutMI;
		private System.Windows.Forms.ImageList ToolBarImageList;
		private System.Windows.Forms.ToolBarButton SaveBTN;
		private System.Windows.Forms.ToolBarButton SeparatorT1;
		private System.Windows.Forms.ToolBarButton ConnectBTN;
		private System.Windows.Forms.ToolBarButton DisconnectBTN;
		private System.Windows.Forms.ToolBarButton ViewStatusBTN;
		private System.Windows.Forms.ToolBarButton BrowseBTN;
		private System.Windows.Forms.ToolBarButton SeparatorT2;
		private System.Windows.Forms.ToolBarButton ReadBTN;
		private System.Windows.Forms.ToolBarButton WriteBTN;
		private System.Windows.Forms.ToolBarButton SeparatorT3;
		private System.Windows.Forms.ToolBarButton AboutBTN;
		private System.Windows.Forms.MenuItem OutputMI;
		private System.Windows.Forms.MenuItem OutputClearMI;
		private System.Windows.Forms.MenuItem OptionsMI;
		private System.Windows.Forms.MenuItem ProxyServerMI;
		private System.Windows.Forms.MenuItem ClearHistoryMI;
		private System.Windows.Forms.MenuItem menuItem1;
		private System.Windows.Forms.MenuItem TestMI;
		private System.ComponentModel.IContainer components;
		
		[STAThread]
		static void Main() 
		{
			try
			{				
				SecurityPermission permission = new SecurityPermission(SecurityPermissionFlag.UnmanagedCode);
				
				if (!SecurityManager.IsGranted(permission))
				{
					string msg = "";

					msg += "This application requires permission to access unmanaged code ";
					msg += "in order to connect to COM-DA servers directly.\r\n\r\n";
					msg += "Connections to XML-DA servers will not be affected.";

					MessageBox.Show(msg, "OPC .NET API Sample Data Access Client");
				}

				Application.Run(new MainForm());
			}
			catch (Exception e)
			{
				MessageBox.Show("An unexpected exception occurred. Application exiting.\r\n\r\n" + e.Message, "OPC .NET API Sample Data Access Client");
			}
		}

		public MainForm()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();
 
			// connect the updates control to the subscriptions control.
			SubscriptionCTRL.SubscriptionModified += new SubscriptionModifiedCallback(UpdatesCTRL.OnSubscriptionModified);

			// register for trace/debug output from the updates control.
			UpdatesCTRL.UpdateEvent += new UpdateEvent_EventHandler(OnUpdateEvent);	
			
#if (DEBUG)

			// initialize the set of known servers.
			URL[] knownURLs = new URL[] 
			{
				new URL("opcda://localhost/OPCSample.OpcDaServer"),
				new URL("opcda://localhost/OPCSample.OpcDa30Server"),
				new URL("opcda://localhost/OPCSample.OpcDa20Server"),
				new URL("http://localhost/Source/XmlDaSampleServer/Service.asmx"),
			};

#else
			// initialize the set of known servers.
			URL[] knownURLs = new URL[] 
			{
				new URL("http://opcfoundation.org/XmlDaSampleServer/Service.asmx"),
				new URL("http://localhost/XmlDaSampleServer/Service.asmx"),
			};
#endif
			
			SelectServerCTRL.Initialize(knownURLs, 0, Opc.Specification.COM_DA_20);
			SelectTargetCTRL.Initialize(knownURLs, 0, Opc.Specification.COM_DA_20);
			
			LoadSettings();
			
			// register for server connected callbacks.
			SelectServerCTRL.ConnectServer += new ConnectServer_EventHandler(OnConnect); 
			SelectTargetCTRL.ConnectServer += new ConnectServer_EventHandler(OnConnectTarget); 
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if(components != null)
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.MainMenu = new System.Windows.Forms.MainMenu(this.components);
            this.FileMI = new System.Windows.Forms.MenuItem();
            this.LoadMI = new System.Windows.Forms.MenuItem();
            this.SaveMI = new System.Windows.Forms.MenuItem();
            this.SeparatorF1 = new System.Windows.Forms.MenuItem();
            this.ExitMI = new System.Windows.Forms.MenuItem();
            this.ServerMI = new System.Windows.Forms.MenuItem();
            this.ConnectMI = new System.Windows.Forms.MenuItem();
            this.DisconnecMI = new System.Windows.Forms.MenuItem();
            this.SeparatorS1 = new System.Windows.Forms.MenuItem();
            this.ViewStatusMI = new System.Windows.Forms.MenuItem();
            this.BrowseMI = new System.Windows.Forms.MenuItem();
            this.SeparatorS2 = new System.Windows.Forms.MenuItem();
            this.ReadMI = new System.Windows.Forms.MenuItem();
            this.WriteMI = new System.Windows.Forms.MenuItem();
            this.menuItem1 = new System.Windows.Forms.MenuItem();
            this.TestMI = new System.Windows.Forms.MenuItem();
            this.OutputMI = new System.Windows.Forms.MenuItem();
            this.OutputClearMI = new System.Windows.Forms.MenuItem();
            this.OptionsMI = new System.Windows.Forms.MenuItem();
            this.ProxyServerMI = new System.Windows.Forms.MenuItem();
            this.ClearHistoryMI = new System.Windows.Forms.MenuItem();
            this.HelpMI = new System.Windows.Forms.MenuItem();
            this.AboutMI = new System.Windows.Forms.MenuItem();
            this.ToolBar = new System.Windows.Forms.ToolBar();
            this.LoadBTN = new System.Windows.Forms.ToolBarButton();
            this.SaveBTN = new System.Windows.Forms.ToolBarButton();
            this.SeparatorT1 = new System.Windows.Forms.ToolBarButton();
            this.ConnectBTN = new System.Windows.Forms.ToolBarButton();
            this.DisconnectBTN = new System.Windows.Forms.ToolBarButton();
            this.ViewStatusBTN = new System.Windows.Forms.ToolBarButton();
            this.BrowseBTN = new System.Windows.Forms.ToolBarButton();
            this.SeparatorT2 = new System.Windows.Forms.ToolBarButton();
            this.ReadBTN = new System.Windows.Forms.ToolBarButton();
            this.WriteBTN = new System.Windows.Forms.ToolBarButton();
            this.SeparatorT3 = new System.Windows.Forms.ToolBarButton();
            this.AboutBTN = new System.Windows.Forms.ToolBarButton();
            this.ToolBarImageList = new System.Windows.Forms.ImageList(this.components);
            this.BottomPN = new System.Windows.Forms.Panel();
            this.OutputCTRL = new System.Windows.Forms.RichTextBox();
            this.SplitterH = new System.Windows.Forms.Splitter();
            this.SplitterV = new System.Windows.Forms.Splitter();
            this.LeftPN = new System.Windows.Forms.Panel();
            this.RightPN = new System.Windows.Forms.Panel();
            this.UpdatesCTRL = new Opc.Da.SampleClient.UpdatesListViewCtrl();
            this.SubscriptionCTRL = new Opc.Da.SampleClient.SubscriptionsTreeCtrl();
            this.StatusCTRL = new Opc.Da.SampleClient.ServerStatusCtrl();
            this.SelectTargetCTRL = new Opc.SampleClient.SelectServerCtrl();
            this.SelectServerCTRL = new Opc.SampleClient.SelectServerCtrl();
            this.BottomPN.SuspendLayout();
            this.LeftPN.SuspendLayout();
            this.RightPN.SuspendLayout();
            this.SuspendLayout();
            // 
            // MainMenu
            // 
            this.MainMenu.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.FileMI,
            this.ServerMI,
            this.OutputMI,
            this.OptionsMI,
            this.HelpMI});
            // 
            // FileMI
            // 
            this.FileMI.Index = 0;
            this.FileMI.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.LoadMI,
            this.SaveMI,
            this.SeparatorF1,
            this.ExitMI});
            this.FileMI.Text = "&File";
            // 
            // LoadMI
            // 
            this.LoadMI.Index = 0;
            this.LoadMI.Text = "&Load";
            this.LoadMI.Click += new System.EventHandler(this.LoadMI_Click);
            // 
            // SaveMI
            // 
            this.SaveMI.Index = 1;
            this.SaveMI.Text = "&Save";
            this.SaveMI.Click += new System.EventHandler(this.SaveMI_Click);
            // 
            // SeparatorF1
            // 
            this.SeparatorF1.Index = 2;
            this.SeparatorF1.Text = "-";
            // 
            // ExitMI
            // 
            this.ExitMI.Index = 3;
            this.ExitMI.Text = "&Exit";
            this.ExitMI.Click += new System.EventHandler(this.ExitMI_Click);
            // 
            // ServerMI
            // 
            this.ServerMI.Index = 1;
            this.ServerMI.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.ConnectMI,
            this.DisconnecMI,
            this.SeparatorS1,
            this.ViewStatusMI,
            this.BrowseMI,
            this.SeparatorS2,
            this.ReadMI,
            this.WriteMI,
            this.menuItem1,
            this.TestMI});
            this.ServerMI.Text = "&Server";
            // 
            // ConnectMI
            // 
            this.ConnectMI.Index = 0;
            this.ConnectMI.Text = "&Connect";
            this.ConnectMI.Click += new System.EventHandler(this.ConnectMI_Click);
            // 
            // DisconnecMI
            // 
            this.DisconnecMI.Index = 1;
            this.DisconnecMI.Text = "&Disconnect";
            this.DisconnecMI.Click += new System.EventHandler(this.DisconnectMI_Click);
            // 
            // SeparatorS1
            // 
            this.SeparatorS1.Index = 2;
            this.SeparatorS1.Text = "-";
            // 
            // ViewStatusMI
            // 
            this.ViewStatusMI.Index = 3;
            this.ViewStatusMI.Text = "&View Status";
            this.ViewStatusMI.Click += new System.EventHandler(this.ViewStatusMI_Click);
            // 
            // BrowseMI
            // 
            this.BrowseMI.Index = 4;
            this.BrowseMI.Text = "&Browse...";
            this.BrowseMI.Click += new System.EventHandler(this.BrowseMI_Click);
            // 
            // SeparatorS2
            // 
            this.SeparatorS2.Index = 5;
            this.SeparatorS2.Text = "-";
            // 
            // ReadMI
            // 
            this.ReadMI.Index = 6;
            this.ReadMI.Text = "&Read...";
            this.ReadMI.Click += new System.EventHandler(this.ReadMI_Click);
            // 
            // WriteMI
            // 
            this.WriteMI.Index = 7;
            this.WriteMI.Text = "&Write...";
            this.WriteMI.Click += new System.EventHandler(this.WriteMI_Click);
            // 
            // menuItem1
            // 
            this.menuItem1.Index = 8;
            this.menuItem1.Text = "-";
            // 
            // TestMI
            // 
            this.TestMI.Index = 9;
            this.TestMI.Text = "Test";
            this.TestMI.Click += new System.EventHandler(this.TestMI_Click);
            // 
            // OutputMI
            // 
            this.OutputMI.Index = 2;
            this.OutputMI.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.OutputClearMI});
            this.OutputMI.Text = "&Output";
            // 
            // OutputClearMI
            // 
            this.OutputClearMI.Index = 0;
            this.OutputClearMI.Text = "&Clear";
            this.OutputClearMI.Click += new System.EventHandler(this.OutputClearMI_Click);
            // 
            // OptionsMI
            // 
            this.OptionsMI.Index = 3;
            this.OptionsMI.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.ProxyServerMI,
            this.ClearHistoryMI});
            this.OptionsMI.Text = "O&ptions";
            // 
            // ProxyServerMI
            // 
            this.ProxyServerMI.Index = 0;
            this.ProxyServerMI.Text = "&Proxy Server....";
            this.ProxyServerMI.Click += new System.EventHandler(this.ProxyServerMI_Click);
            // 
            // ClearHistoryMI
            // 
            this.ClearHistoryMI.Index = 1;
            this.ClearHistoryMI.Text = "&Clear History";
            this.ClearHistoryMI.Click += new System.EventHandler(this.ClearHistoryMI_Click);
            // 
            // HelpMI
            // 
            this.HelpMI.Index = 4;
            this.HelpMI.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.AboutMI});
            this.HelpMI.Text = "&Help";
            // 
            // AboutMI
            // 
            this.AboutMI.Index = 0;
            this.AboutMI.Text = "&About...";
            this.AboutMI.Click += new System.EventHandler(this.AboutMI_Click);
            // 
            // ToolBar
            // 
            this.ToolBar.Appearance = System.Windows.Forms.ToolBarAppearance.Flat;
            this.ToolBar.Buttons.AddRange(new System.Windows.Forms.ToolBarButton[] {
            this.LoadBTN,
            this.SaveBTN,
            this.SeparatorT1,
            this.ConnectBTN,
            this.DisconnectBTN,
            this.ViewStatusBTN,
            this.BrowseBTN,
            this.SeparatorT2,
            this.ReadBTN,
            this.WriteBTN,
            this.SeparatorT3,
            this.AboutBTN});
            this.ToolBar.ButtonSize = new System.Drawing.Size(16, 16);
            this.ToolBar.DropDownArrows = true;
            this.ToolBar.ImageList = this.ToolBarImageList;
            this.ToolBar.Location = new System.Drawing.Point(3, 0);
            this.ToolBar.Name = "ToolBar";
            this.ToolBar.ShowToolTips = true;
            this.ToolBar.Size = new System.Drawing.Size(1010, 30);
            this.ToolBar.TabIndex = 0;
            this.ToolBar.ButtonClick += new System.Windows.Forms.ToolBarButtonClickEventHandler(this.ToolBar_ButtonClick);
            // 
            // LoadBTN
            // 
            this.LoadBTN.ImageIndex = 2;
            this.LoadBTN.Name = "LoadBTN";
            this.LoadBTN.ToolTipText = "Load Configuration";
            // 
            // SaveBTN
            // 
            this.SaveBTN.ImageIndex = 3;
            this.SaveBTN.Name = "SaveBTN";
            this.SaveBTN.ToolTipText = "Save Configuration";
            // 
            // SeparatorT1
            // 
            this.SeparatorT1.Name = "SeparatorT1";
            this.SeparatorT1.Style = System.Windows.Forms.ToolBarButtonStyle.Separator;
            // 
            // ConnectBTN
            // 
            this.ConnectBTN.ImageIndex = 0;
            this.ConnectBTN.Name = "ConnectBTN";
            this.ConnectBTN.ToolTipText = "Connect to Server";
            // 
            // DisconnectBTN
            // 
            this.DisconnectBTN.ImageIndex = 1;
            this.DisconnectBTN.Name = "DisconnectBTN";
            this.DisconnectBTN.ToolTipText = "Disconnect from Server";
            // 
            // ViewStatusBTN
            // 
            this.ViewStatusBTN.ImageIndex = 4;
            this.ViewStatusBTN.Name = "ViewStatusBTN";
            this.ViewStatusBTN.ToolTipText = "View Server Status";
            // 
            // BrowseBTN
            // 
            this.BrowseBTN.ImageIndex = 6;
            this.BrowseBTN.Name = "BrowseBTN";
            this.BrowseBTN.ToolTipText = "Browse Address Space";
            // 
            // SeparatorT2
            // 
            this.SeparatorT2.Name = "SeparatorT2";
            this.SeparatorT2.Style = System.Windows.Forms.ToolBarButtonStyle.Separator;
            // 
            // ReadBTN
            // 
            this.ReadBTN.ImageIndex = 7;
            this.ReadBTN.Name = "ReadBTN";
            this.ReadBTN.ToolTipText = "Read Items";
            // 
            // WriteBTN
            // 
            this.WriteBTN.ImageIndex = 8;
            this.WriteBTN.Name = "WriteBTN";
            this.WriteBTN.ToolTipText = "Write Items";
            // 
            // SeparatorT3
            // 
            this.SeparatorT3.Name = "SeparatorT3";
            this.SeparatorT3.Style = System.Windows.Forms.ToolBarButtonStyle.Separator;
            // 
            // AboutBTN
            // 
            this.AboutBTN.ImageIndex = 13;
            this.AboutBTN.Name = "AboutBTN";
            this.AboutBTN.ToolTipText = "About";
            // 
            // ToolBarImageList
            // 
            this.ToolBarImageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("ToolBarImageList.ImageStream")));
            this.ToolBarImageList.TransparentColor = System.Drawing.Color.Teal;
            this.ToolBarImageList.Images.SetKeyName(0, "");
            this.ToolBarImageList.Images.SetKeyName(1, "");
            this.ToolBarImageList.Images.SetKeyName(2, "");
            this.ToolBarImageList.Images.SetKeyName(3, "");
            this.ToolBarImageList.Images.SetKeyName(4, "");
            this.ToolBarImageList.Images.SetKeyName(5, "");
            this.ToolBarImageList.Images.SetKeyName(6, "");
            this.ToolBarImageList.Images.SetKeyName(7, "");
            this.ToolBarImageList.Images.SetKeyName(8, "");
            this.ToolBarImageList.Images.SetKeyName(9, "");
            this.ToolBarImageList.Images.SetKeyName(10, "");
            this.ToolBarImageList.Images.SetKeyName(11, "");
            this.ToolBarImageList.Images.SetKeyName(12, "");
            this.ToolBarImageList.Images.SetKeyName(13, "");
            // 
            // BottomPN
            // 
            this.BottomPN.Controls.Add(this.OutputCTRL);
            this.BottomPN.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.BottomPN.Location = new System.Drawing.Point(3, 567);
            this.BottomPN.Name = "BottomPN";
            this.BottomPN.Size = new System.Drawing.Size(1010, 108);
            this.BottomPN.TabIndex = 3;
            // 
            // OutputCTRL
            // 
            this.OutputCTRL.Dock = System.Windows.Forms.DockStyle.Fill;
            this.OutputCTRL.Location = new System.Drawing.Point(0, 0);
            this.OutputCTRL.Name = "OutputCTRL";
            this.OutputCTRL.Size = new System.Drawing.Size(1010, 108);
            this.OutputCTRL.TabIndex = 0;
            this.OutputCTRL.Text = "";
            // 
            // SplitterH
            // 
            this.SplitterH.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.SplitterH.Location = new System.Drawing.Point(3, 564);
            this.SplitterH.Name = "SplitterH";
            this.SplitterH.Size = new System.Drawing.Size(1010, 3);
            this.SplitterH.TabIndex = 4;
            this.SplitterH.TabStop = false;
            // 
            // SplitterV
            // 
            this.SplitterV.Location = new System.Drawing.Point(319, 78);
            this.SplitterV.Name = "SplitterV";
            this.SplitterV.Size = new System.Drawing.Size(4, 486);
            this.SplitterV.TabIndex = 5;
            this.SplitterV.TabStop = false;
            // 
            // LeftPN
            // 
            this.LeftPN.Controls.Add(this.SubscriptionCTRL);
            this.LeftPN.Dock = System.Windows.Forms.DockStyle.Left;
            this.LeftPN.Location = new System.Drawing.Point(3, 78);
            this.LeftPN.Name = "LeftPN";
            this.LeftPN.Padding = new System.Windows.Forms.Padding(0, 3, 0, 0);
            this.LeftPN.Size = new System.Drawing.Size(316, 486);
            this.LeftPN.TabIndex = 6;
            // 
            // RightPN
            // 
            this.RightPN.Controls.Add(this.UpdatesCTRL);
            this.RightPN.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RightPN.Location = new System.Drawing.Point(323, 78);
            this.RightPN.Name = "RightPN";
            this.RightPN.Padding = new System.Windows.Forms.Padding(0, 3, 0, 0);
            this.RightPN.Size = new System.Drawing.Size(690, 486);
            this.RightPN.TabIndex = 7;
            // 
            // UpdatesCTRL
            // 
            this.UpdatesCTRL.AllowDrop = true;
            this.UpdatesCTRL.Dock = System.Windows.Forms.DockStyle.Fill;
            this.UpdatesCTRL.Location = new System.Drawing.Point(0, 3);
            this.UpdatesCTRL.Name = "UpdatesCTRL";
            this.UpdatesCTRL.Size = new System.Drawing.Size(690, 483);
            this.UpdatesCTRL.TabIndex = 0;
            // 
            // SubscriptionCTRL
            // 
            this.SubscriptionCTRL.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SubscriptionCTRL.Location = new System.Drawing.Point(0, 3);
            this.SubscriptionCTRL.Name = "SubscriptionCTRL";
            this.SubscriptionCTRL.Size = new System.Drawing.Size(316, 483);
            this.SubscriptionCTRL.TabIndex = 0;
            // 
            // StatusCTRL
            // 
            this.StatusCTRL.Location = new System.Drawing.Point(3, 675);
            this.StatusCTRL.Name = "StatusCTRL";
            this.StatusCTRL.Size = new System.Drawing.Size(1010, 17);
            this.StatusCTRL.TabIndex = 8;
            // 
            // SelectTargetCTRL
            // 
            this.SelectTargetCTRL.Dock = System.Windows.Forms.DockStyle.Top;
            this.SelectTargetCTRL.Label = "Target";
            this.SelectTargetCTRL.Location = new System.Drawing.Point(3, 54);
            this.SelectTargetCTRL.Name = "SelectTargetCTRL";
            this.SelectTargetCTRL.Padding = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.SelectTargetCTRL.Size = new System.Drawing.Size(1010, 24);
            this.SelectTargetCTRL.TabIndex = 0;
            this.SelectTargetCTRL.Visible = false;
            this.SelectTargetCTRL.Load += new System.EventHandler(this.SelectTargetCTRL_Load);
            // 
            // SelectServerCTRL
            // 
            this.SelectServerCTRL.Dock = System.Windows.Forms.DockStyle.Top;
            this.SelectServerCTRL.Label = "Server";
            this.SelectServerCTRL.Location = new System.Drawing.Point(3, 30);
            this.SelectServerCTRL.Name = "SelectServerCTRL";
            this.SelectServerCTRL.Padding = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.SelectServerCTRL.Size = new System.Drawing.Size(1010, 24);
            this.SelectServerCTRL.TabIndex = 0;
            this.SelectServerCTRL.Load += new System.EventHandler(this.SelectServerCTRL_Load);
            // 
            // MainForm
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
            this.ClientSize = new System.Drawing.Size(1016, 692);
            this.Controls.Add(this.RightPN);
            this.Controls.Add(this.SplitterV);
            this.Controls.Add(this.LeftPN);
            this.Controls.Add(this.SplitterH);
            this.Controls.Add(this.BottomPN);
            this.Controls.Add(this.StatusCTRL);
            this.Controls.Add(this.SelectTargetCTRL);
            this.Controls.Add(this.SelectServerCTRL);
            this.Controls.Add(this.ToolBar);
            this.Menu = this.MainMenu;
            this.Name = "MainForm";
            this.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.Text = "OPC .NET API Sample Data Access Client";
            this.BottomPN.ResumeLayout(false);
            this.LeftPN.ResumeLayout(false);
            this.RightPN.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

		}
		#endregion

		/// <summary>
		/// A class that stores the user's application settings.
		/// </summary>
		[Serializable]
		public class UserAppData
		{
			public URL[]  KnownUrls   = null;
			public int    SelectedURL = -1;
			public string ProxyServer = null;
		}

		/// <summary>
		/// A class that DX configuration.
		/// </summary>
		[Serializable]
		public class DXConfiguration
		{
			public Opc.Da.Server  Target        = null;
			public DXConnection[] DXConnections = null;
		}

		/// <summary>
		/// The application configuration file path.
		/// </summary>
		private string ConfigFilePath
		{
			get { return Application.StartupPath + "\\Opc.Da.SampleClient.config"; }
		}

		/// <summary>
		/// The default web proxy for the application - uses IE settings if null.
		/// </summary>
		private WebProxy m_proxy = null;

		/// <summary>
		/// The currently active server object.
		/// </summary>
		private Opc.Da.Server m_server = null;

		/// <summary>
		/// The path of the current configuration file.
		/// </summary>
		private string m_configFile = null;

		/// <summary>
		/// The DX target server. 
		/// </summary>
		private Opc.Da.Server m_target = null;

		/// <summary>
		/// The DX connections to the target server. 
		/// </summary>
		private DXConnection[] m_connections = null;

		/// <summary>
		/// Called by the update control when something happens.
		/// </summary>
		private void OnUpdateEvent(object subscriptionHandle, object args)
		{
			if (InvokeRequired)
			{
				BeginInvoke(new UpdateEvent_EventHandler(OnUpdateEvent), new object[] { subscriptionHandle, args });
				return;
			}

			if (typeof(string).IsInstanceOfType(args))
			{
				if (m_server != null)
				{
					foreach (Subscription subscription in m_server.Subscriptions)
					{
						if (subscription.ClientHandle.Equals(subscriptionHandle))
						{
							OutputCTRL.Text += String.Format("{0}\t{1}\r\n", subscription.Name, (string)args);
							return;
						}
					}
				}
			}
		}

		/// <summary>
		/// Called to connect to a server.
		/// </summary>
		public void OnConnect(Opc.Server server)
		{
			// disconnect from the current server.
			OnDisconnect();

			// create a default file name for the server.
			m_configFile = server.Name + ".config";

			// load server object from config file if it exists. 
			if (File.Exists(m_configFile))
			{
				if (OnLoad(false, server.Url)) return;
			}

			// use the specified server object directly.
			ComplexTypeCache.Server = m_server = (Opc.Da.Server)server;

			// connect with an empty configuration.
			OnConnect();	
		}
		
		/// <summary>
		/// Called to connect to a server.
		/// </summary>
		public void OnConnect()
		{
			Cursor = Cursors.WaitCursor;
			
			try
			{	
				NetworkCredential credentials = null;

				do
				{
					try
					{
						m_server.Connect(new ConnectData(credentials, m_proxy));
						break;
					}
					catch (Exception e)
					{
						MessageBox.Show(e.Message);
					}

					credentials = new NetworkCredentialsDlg().ShowDialog(credentials);
				}
				while (credentials != null);
	
				// select all filters by default.
				m_server.SetResultFilters((int)ResultFilter.All);

				// initialize controls.
				StatusCTRL.Start(m_server);
				UpdatesCTRL.Initialize(m_server);
				SubscriptionCTRL.Initialize(m_server);
				SelectServerCTRL.OnConnect(m_server);

				// register for shutdown events.
				m_server.ServerShutdown += new ServerShutdownEventHandler(Server_ServerShutdown);

				// save settings.
				SaveSettings();
			}
			catch (Exception e)
			{
				MessageBox.Show(e.Message);
				ComplexTypeCache.Server = m_server = null;
			}

			Cursor = Cursors.Default;
		}

		/// <summary>
		/// Called to connect to a target.
		/// </summary>
		public void OnConnectTarget(Opc.Server server)
		{
			if (m_target != null)
			{
				m_target.Disconnect();
				m_target.Dispose();
				m_target = null;
			}

			// use the specified server object directly.
			m_target = (Opc.Da.Server)server;

			Cursor = Cursors.WaitCursor;
			
			try
			{	
				NetworkCredential credentials = null;

				do
				{
					try
					{
						m_target.Connect(new ConnectData(credentials, m_proxy));
						break;
					}
					catch (Exception e)
					{
						MessageBox.Show(e.Message);
					}

					credentials = new NetworkCredentialsDlg().ShowDialog(credentials);
				}
				while (credentials != null);
	
				// select all filters by default.
				m_target.SetResultFilters((int)ResultFilter.All);

				// initialize controls.
				SelectTargetCTRL.OnConnect(m_target);
			}
			catch (Exception e)
			{
				MessageBox.Show(e.Message);
				m_target = null;
			}

			Cursor = Cursors.Default;
		}

		/// <summary>
		/// Called to disconnect from a server.
		/// </summary>
		public void OnDisconnect()
		{
			// disconnect server.
			if (m_server != null)
			{
				try	  { m_server.Disconnect(); }
				catch {}

				m_server.Dispose();
				ComplexTypeCache.Server = m_server = null;
			}

			// initialize controls.
			SubscriptionCTRL.Initialize(m_server);
			UpdatesCTRL.Initialize(m_server);
			StatusCTRL.Start(m_server);
			OutputCTRL.Text = "";
		}

		/// <summary>
		/// Displays the about dialog for the application.
		/// </summary>
		private void OnAbout()
		{
			new AboutDlg(Text).ShowDialog();
		}

		/// <summary>
		/// Saves the configuration for the current server.
		/// </summary>
		private void OnSave()
		{
			Stream stream = null;

			try
			{
				Cursor = Cursors.WaitCursor;

				// ensure a valid server object exists.
				if (m_server == null) throw new NotConnectedException();

				// create the configuartion file.
				stream = new FileStream(m_configFile, FileMode.Create, FileAccess.Write, FileShare.None);

				// serialize the server object.
				new BinaryFormatter().Serialize(stream, m_server);
			}
			catch (Exception e)
			{
				MessageBox.Show(e.Message);
			}
			finally
			{
				// close the stream.
				if (stream != null) stream.Close();

				Cursor = Cursors.Default;
			}
		}

		/// <summary>
		/// Loads the configuration for the current server.
		/// </summary>
		private bool OnLoad(bool prompt, Opc.URL url)
		{
			Stream stream = null;

			try
			{				
				Cursor = Cursors.WaitCursor;

				// prompt user to select a configuration file.
				if (prompt)
				{
					OpenFileDialog dialog = new OpenFileDialog();

					dialog.CheckFileExists = true;
					dialog.CheckPathExists = true;
					dialog.DefaultExt      = ".config";
					dialog.Filter          = "Config Files (*.config)|*.config|All Files (*.*)|*.*";
					dialog.Multiselect     = false;
					dialog.ValidateNames   = true;
					dialog.Title           = "Open Server Configuration File";
					dialog.FileName        = m_configFile;

					if (dialog.ShowDialog() != DialogResult.OK)
					{
						return false;
					}			

					// save the new config file name.
					m_configFile = dialog.FileName;
				}

				// disconnect from current server.
				OnDisconnect();

				// open configuration file.
				stream = new FileStream(m_configFile, FileMode.Open, FileAccess.Read, FileShare.Read);
				
				// deserialize the server object.
				ComplexTypeCache.Server = m_server = (Opc.Da.Server)new BinaryFormatter().Deserialize(stream);

				// overrided default url.
				if (url != null)
				{
					m_server.Url = url;
				}

				// connect to new server.
				OnConnect();

				// load DX configuration.
				LoadDXConfiguration();

				// load succeeded.
				return true;
			}
			catch (Exception e)
			{
				if (prompt) MessageBox.Show(e.Message);
				return false;
			}
			finally
			{
				// close the stream.
				if (stream != null) stream.Close();

				Cursor = Cursors.Default;
			}
		}

		/// <summary>
		/// Saves the current DXConfiguration
		/// </summary>
		private void SaveDXConfiguration()
		{
			Stream stream = null;

			try
			{
				Cursor = Cursors.WaitCursor;

				string configFile = m_server.Name + ".dxconfig";

				// create the configuartion file.
				stream = new FileStream(configFile, FileMode.Create, FileAccess.Write, FileShare.None);

				// populate the user settings object.
				DXConfiguration configuration = new DXConfiguration();

				configuration.Target        = m_target;
				configuration.DXConnections = m_connections;

				// serialize the user settings object.
				new BinaryFormatter().Serialize(stream, configuration);
			}
			catch
			{
				// ignore errors.
			}
			finally
			{
				// close the stream.
				if (stream != null) stream.Close();
				Cursor = Cursors.Default;
			}
		}

		/// <summary>
		/// Loads the configuration for the current server.
		/// </summary>
		private bool LoadDXConfiguration()
		{
			Stream stream = null;

			try
			{				
				Cursor = Cursors.WaitCursor;

				string configFile = m_server.Name + ".dxconfig";

				// open configuration file.
				stream = new FileStream(configFile, FileMode.Open, FileAccess.Read, FileShare.Read);
				
				// deserialize the server object.
				DXConfiguration configuration = (DXConfiguration)new BinaryFormatter().Deserialize(stream);

				// overrided the current settings.
				if (configuration != null)
				{					
					configuration.Target.Connect();

					m_target      = configuration.Target;
					m_connections = configuration.DXConnections;

					SelectTargetCTRL.Initialize(new URL[] { m_target.Url }, 0, Opc.Specification.COM_DA_30);
				}

				// load succeeded.
				return true;
			}
			catch (Exception)
			{
				// ignore errors.
				return false;
			}
			finally
			{
				// close the stream.
				if (stream != null) stream.Close();

				Cursor = Cursors.Default;
			}
		}

		/// <summary>
		/// Saves the user's application settings.
		/// </summary>
		private void SaveSettings()
		{
			Stream stream = null;

			try
			{
				Cursor = Cursors.WaitCursor;

				// create the configuartion file.
				stream = new FileStream(ConfigFilePath, FileMode.Create, FileAccess.Write, FileShare.None);

				// populate the user settings object.
				UserAppData settings = new UserAppData();

				settings.KnownUrls = SelectServerCTRL.GetKnownURLs(out settings.SelectedURL);

				if (m_proxy != null)
				{
					settings.ProxyServer = m_proxy.Address.ToString();
				}

				// serialize the user settings object.
				new BinaryFormatter().Serialize(stream, settings);
			}
			catch
			{
				// ignore errors.
			}
			finally
			{
				// close the stream.
				if (stream != null) stream.Close();
				Cursor = Cursors.Default;
			}
		}

		/// <summary>
		/// Loads the user's application settings.
		/// </summary>
		private void LoadSettings()
		{
			Stream stream = null;

			try
			{				
				Cursor = Cursors.WaitCursor;
				
				// open configuration file.
				stream = new FileStream(ConfigFilePath, FileMode.Open, FileAccess.Read, FileShare.Read);
				
				// deserialize the server object.
				UserAppData settings = (UserAppData)new BinaryFormatter().Deserialize(stream);

				// overrided the current settings.
				if (settings != null)
				{					
					// known urls.
					SelectServerCTRL.Initialize(settings.KnownUrls, settings.SelectedURL, Opc.Specification.COM_DA_30);

					// proxy server.
					if (settings.ProxyServer != null)
					{
						m_proxy = new WebProxy(settings.ProxyServer);
					}
				}
			}
			catch
			{
				// ignore errors.
			}
			finally
			{
				// close the stream.
				if (stream != null) stream.Close();
				Cursor = Cursors.Default;
			}
		}

		/// <summary>
		/// Called when a tool bar button is clicked.
		/// </summary>
		private void ToolBar_ButtonClick(object sender, System.Windows.Forms.ToolBarButtonClickEventArgs e)
		{
			if (e.Button == LoadBTN)       { OnLoad(true, null);            return; }	
			if (e.Button == SaveBTN)       { OnSave();                      return; }	
			if (e.Button == ConnectBTN)    { OnConnect();                   return; }	
			if (e.Button == DisconnectBTN) { OnDisconnect();                return; }	
			if (e.Button == ViewStatusBTN) { ViewStatusMI_Click(sender, e); return; }	
			if (e.Button == BrowseBTN)     { BrowseMI_Click(sender, e);     return; }	
			if (e.Button == ReadBTN)       { ReadMI_Click(sender, e);       return; }	
			if (e.Button == WriteBTN)      { WriteMI_Click(sender, e);      return; }	
			if (e.Button == AboutBTN)      { OnAbout();                     return; }	
		}

		/// <summary>
		/// Called when the File | Load menu item is clicked.
		/// </summary>
		private void LoadMI_Click(object sender, System.EventArgs e)
		{
			OnLoad(true, null); 
		}

		/// <summary>
		/// Called when the File | Save menu item is clicked.
		/// </summary>
		private void SaveMI_Click(object sender, System.EventArgs e)
		{
			OnSave();
		}

		/// <summary>
		/// Called when the File | Exit menu item is clicked.
		/// </summary>
		private void ExitMI_Click(object sender, System.EventArgs e)
		{
			OnDisconnect();
			Close();
		}

		/// <summary>
		/// Called when the Server | Connect menu item is clicked.
		/// </summary>
		private void ConnectMI_Click(object sender, System.EventArgs e)
		{
			OnConnect();
		}

		/// <summary>
		/// Called when the Server | Disconnect menu item is clicked.
		/// </summary>
		private void DisconnectMI_Click(object sender, System.EventArgs e)
		{
			OnDisconnect();
		}

		/// <summary>
		/// Called when the Server | Browse menu item is clicked.
		/// </summary>
		private void ViewStatusMI_Click(object sender, System.EventArgs e)
		{
			if (m_server != null) new ServerStatusDlg().ShowDialog(m_server);
		}

		/// <summary>
		/// Called when the Server | Browse menu item is clicked.
		/// </summary>
		private void BrowseMI_Click(object sender, System.EventArgs e)
		{
			if (m_server != null) new BrowseItemsDlg().Initialize(m_server);
		}

		/// <summary>
		/// Called when the Server | Read menu item is clicked.
		/// </summary>
		private void ReadMI_Click(object sender, System.EventArgs e)
		{
			if (m_server != null) new ReadItemsDlg().ShowDialog(m_server);	
		}

		/// <summary>
		/// Called when the Server | Write menu item is clicked.
		/// </summary>
		private void WriteMI_Click(object sender, System.EventArgs e)
		{
			if (m_server != null) new WriteItemsDlg().ShowDialog(m_server);	
		}

		/// <summary>
		/// Called when the Help | About menu item is clicked.
		/// </summary>
		private void AboutMI_Click(object sender, System.EventArgs e)
		{
			OnAbout();
		}

		/// <summary>
		/// Called when the Output | Clear menu item is clicked.
		/// </summary>
		private void OutputClearMI_Click(object sender, System.EventArgs e)
		{
			OutputCTRL.Text = "";
		}

		/// <summary>
		/// Handles changes to the proxy server settings.
		/// </summary>
		private void ProxyServerMI_Click(object sender, System.EventArgs e)
		{
			WebProxy proxy = new ProxyServerDlg().ShowDialog(m_proxy);

			if (proxy != m_proxy)
			{
				m_proxy = proxy;
				SaveSettings();
			}
		}

		/// <summary>
		/// Clears the URL history in the drop down menu.
		/// </summary>
		private void ClearHistoryMI_Click(object sender, System.EventArgs e)
		{
			SelectServerCTRL.Initialize(null, 0, Opc.Specification.COM_DA_30);
			SaveSettings();
		}

		/// <summary>
		/// Called when the server sends a shutdown event.
		/// </summary>
		private void Server_ServerShutdown(string reason)
		{
			if (this.InvokeRequired)
			{
				BeginInvoke(new ServerShutdownEventHandler(Server_ServerShutdown), new object[] { reason });
				return;
			}

			MessageBox.Show(reason, "Server Shutdown");
			OnDisconnect();
		}

		private void TestMI_Click(object sender, System.EventArgs e)
		{ 
			try
			{
				Opc.Da.Server server = (Opc.Da.Server)m_server;

				Item[] items = new Item[100];

				for (int ii = 0; ii < items.Length; ii++)
				{
					items[ii] = new Item();

					items[ii].ItemName     = "Static/ArrayTypes/Object[]";
					items[ii].ItemPath     = "DA30";
					items[ii].ClientHandle = ii;
				}

				Opc.Da.SubscriptionState state = new Opc.Da.SubscriptionState();

				state.Active     = true;
				state.UpdateRate = 1000;

				ISubscription subscription = server.CreateSubscription(state);
				Thread.Sleep(100);

				ItemResult[] results = subscription.AddItems(items);
				Thread.Sleep(100);

				for (int ii = 0; ii < 100000; ii++)
				{
					server.GetStatus();

					//ItemValueResult[] values = server.Read(items);
					//ItemPropertyCollection[] properties = server.GetProperties(items, null, true);

					//if (properties != null) {}
				}	
					
				subscription.RemoveItems(results);
				Thread.Sleep(100);
					
				server.CancelSubscription(subscription);
				Thread.Sleep(100);
			}
			catch (Exception exception)
			{
				MessageBox.Show(exception.Message);
			}
		}

        private void SelectServerCTRL_Load(object sender, EventArgs e)
        {

        }

        private void SelectTargetCTRL_Load(object sender, EventArgs e)
        {

        }
	}
}