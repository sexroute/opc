//============================================================================
// TITLE: ReadItemsDlg.cs
//
// CONTENTS:
// 
// A dialog used select items for a read request and then display the results.
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
// 2003/06/11 RSA   Initial implementation.

using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using Opc;
using Opc.Da;

namespace Opc.Da.SampleClient
{
	/// <summary>
	/// A dialog used select items for a read request and then display the results.
	/// </summary>
	public class ReadItemsDlg : System.Windows.Forms.Form
	{
		private Opc.Da.SampleClient.BrowseTreeCtrl BrowseCTRL;
		private Opc.Da.SampleClient.ItemListEditCtrl ItemsCTRL;
		private Opc.Da.SampleClient.ResultListViewCtrl ResultsCTRL;
		private System.Windows.Forms.Panel ButtonsPN;
		private System.Windows.Forms.Button BackBTN;
		private System.Windows.Forms.Button NextBTN;
		private System.Windows.Forms.Button DoneBTN;
		private System.Windows.Forms.Panel LeftPN;
		private System.Windows.Forms.Panel RightPN;
		private Opc.Da.SampleClient.SubscriptionsTreeCtrl SubscriptionCTRL;
		private System.Windows.Forms.Splitter SplitterV;
		private System.Windows.Forms.Button CancelBTN;
		private System.Windows.Forms.Button OptionsBTN;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public ReadItemsDlg()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			ItemsCTRL.IsReadItem = true;

			BrowseCTRL.ItemPicked += new ItemPicked_EventHandler(OnItemPicked);
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
            this.BrowseCTRL = new Opc.Da.SampleClient.BrowseTreeCtrl();
            this.ItemsCTRL = new Opc.Da.SampleClient.ItemListEditCtrl();
            this.LeftPN = new System.Windows.Forms.Panel();
            this.SubscriptionCTRL = new Opc.Da.SampleClient.SubscriptionsTreeCtrl();
            this.RightPN = new System.Windows.Forms.Panel();
            this.ResultsCTRL = new Opc.Da.SampleClient.ResultListViewCtrl();
            this.ButtonsPN = new System.Windows.Forms.Panel();
            this.OptionsBTN = new System.Windows.Forms.Button();
            this.CancelBTN = new System.Windows.Forms.Button();
            this.BackBTN = new System.Windows.Forms.Button();
            this.NextBTN = new System.Windows.Forms.Button();
            this.DoneBTN = new System.Windows.Forms.Button();
            this.SplitterV = new System.Windows.Forms.Splitter();
            this.LeftPN.SuspendLayout();
            this.RightPN.SuspendLayout();
            this.ButtonsPN.SuspendLayout();
            this.SuspendLayout();
            // 
            // BrowseCTRL
            // 
            this.BrowseCTRL.Dock = System.Windows.Forms.DockStyle.Fill;
            this.BrowseCTRL.Location = new System.Drawing.Point(4, 4);
            this.BrowseCTRL.Name = "BrowseCTRL";
            this.BrowseCTRL.Size = new System.Drawing.Size(296, 293);
            this.BrowseCTRL.TabIndex = 1;
            // 
            // ItemsCTRL
            // 
            this.ItemsCTRL.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ItemsCTRL.Location = new System.Drawing.Point(0, 4);
            this.ItemsCTRL.Name = "ItemsCTRL";
            this.ItemsCTRL.Size = new System.Drawing.Size(483, 293);
            this.ItemsCTRL.TabIndex = 2;
            // 
            // LeftPN
            // 
            this.LeftPN.Controls.Add(this.SubscriptionCTRL);
            this.LeftPN.Controls.Add(this.BrowseCTRL);
            this.LeftPN.Dock = System.Windows.Forms.DockStyle.Left;
            this.LeftPN.Location = new System.Drawing.Point(0, 0);
            this.LeftPN.Name = "LeftPN";
            this.LeftPN.Padding = new System.Windows.Forms.Padding(4, 4, 0, 0);
            this.LeftPN.Size = new System.Drawing.Size(300, 297);
            this.LeftPN.TabIndex = 6;
            // 
            // SubscriptionCTRL
            // 
            this.SubscriptionCTRL.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SubscriptionCTRL.Location = new System.Drawing.Point(4, 4);
            this.SubscriptionCTRL.Name = "SubscriptionCTRL";
            this.SubscriptionCTRL.Size = new System.Drawing.Size(296, 293);
            this.SubscriptionCTRL.TabIndex = 7;
            // 
            // RightPN
            // 
            this.RightPN.Controls.Add(this.ResultsCTRL);
            this.RightPN.Controls.Add(this.ItemsCTRL);
            this.RightPN.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RightPN.Location = new System.Drawing.Point(305, 0);
            this.RightPN.Name = "RightPN";
            this.RightPN.Padding = new System.Windows.Forms.Padding(0, 4, 4, 0);
            this.RightPN.Size = new System.Drawing.Size(487, 297);
            this.RightPN.TabIndex = 8;
            // 
            // ResultsCTRL
            // 
            this.ResultsCTRL.AllowDrop = true;
            this.ResultsCTRL.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ResultsCTRL.Location = new System.Drawing.Point(0, 4);
            this.ResultsCTRL.Name = "ResultsCTRL";
            this.ResultsCTRL.Size = new System.Drawing.Size(483, 293);
            this.ResultsCTRL.TabIndex = 0;
            // 
            // ButtonsPN
            // 
            this.ButtonsPN.Controls.Add(this.OptionsBTN);
            this.ButtonsPN.Controls.Add(this.CancelBTN);
            this.ButtonsPN.Controls.Add(this.BackBTN);
            this.ButtonsPN.Controls.Add(this.NextBTN);
            this.ButtonsPN.Controls.Add(this.DoneBTN);
            this.ButtonsPN.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.ButtonsPN.Location = new System.Drawing.Point(0, 297);
            this.ButtonsPN.Name = "ButtonsPN";
            this.ButtonsPN.Size = new System.Drawing.Size(792, 39);
            this.ButtonsPN.TabIndex = 0;
            // 
            // OptionsBTN
            // 
            this.OptionsBTN.Location = new System.Drawing.Point(6, 9);
            this.OptionsBTN.Name = "OptionsBTN";
            this.OptionsBTN.Size = new System.Drawing.Size(90, 24);
            this.OptionsBTN.TabIndex = 6;
            this.OptionsBTN.Text = "Options...";
            this.OptionsBTN.Click += new System.EventHandler(this.OptionsBTN_Click);
            // 
            // CancelBTN
            // 
            this.CancelBTN.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.CancelBTN.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.CancelBTN.Location = new System.Drawing.Point(696, 9);
            this.CancelBTN.Name = "CancelBTN";
            this.CancelBTN.Size = new System.Drawing.Size(90, 24);
            this.CancelBTN.TabIndex = 5;
            this.CancelBTN.Text = "Cancel";
            this.CancelBTN.Click += new System.EventHandler(this.DoneBTN_Click);
            // 
            // BackBTN
            // 
            this.BackBTN.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.BackBTN.Location = new System.Drawing.Point(504, 9);
            this.BackBTN.Name = "BackBTN";
            this.BackBTN.Size = new System.Drawing.Size(90, 24);
            this.BackBTN.TabIndex = 3;
            this.BackBTN.Text = "< Back";
            this.BackBTN.Click += new System.EventHandler(this.BackBTN_Click);
            // 
            // NextBTN
            // 
            this.NextBTN.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.NextBTN.Location = new System.Drawing.Point(600, 9);
            this.NextBTN.Name = "NextBTN";
            this.NextBTN.Size = new System.Drawing.Size(90, 24);
            this.NextBTN.TabIndex = 2;
            this.NextBTN.Text = "Next >";
            this.NextBTN.Click += new System.EventHandler(this.NextBTN_Click);
            // 
            // DoneBTN
            // 
            this.DoneBTN.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.DoneBTN.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.DoneBTN.Location = new System.Drawing.Point(696, 9);
            this.DoneBTN.Name = "DoneBTN";
            this.DoneBTN.Size = new System.Drawing.Size(90, 24);
            this.DoneBTN.TabIndex = 0;
            this.DoneBTN.Text = "Done";
            this.DoneBTN.Click += new System.EventHandler(this.DoneBTN_Click);
            // 
            // SplitterV
            // 
            this.SplitterV.Location = new System.Drawing.Point(300, 0);
            this.SplitterV.Name = "SplitterV";
            this.SplitterV.Size = new System.Drawing.Size(5, 297);
            this.SplitterV.TabIndex = 9;
            this.SplitterV.TabStop = false;
            // 
            // ReadItemsDlg
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
            this.ClientSize = new System.Drawing.Size(792, 336);
            this.Controls.Add(this.RightPN);
            this.Controls.Add(this.SplitterV);
            this.Controls.Add(this.LeftPN);
            this.Controls.Add(this.ButtonsPN);
            this.Name = "ReadItemsDlg";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Read Items";
            this.LeftPN.ResumeLayout(false);
            this.RightPN.ResumeLayout(false);
            this.ButtonsPN.ResumeLayout(false);
            this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// The server used to process read request.
		/// </summary>
		private Opc.Da.Server m_server = null;

		/// <summary>
		/// The subscription used to process read request.
		/// </summary>
		private Subscription m_subscription = null;
		
		/// <summary>
		/// Whether to use asynchronous read operations. 
		/// </summary>
		private bool m_synchronous = true;

		/// <summary>
		/// The set of values returned from the server.
		/// </summary>
		private ItemValueResult[] m_values = null;
		
		/// <summary>
		/// Prompts the use to select items for the read request.
		/// </summary>
		public ItemValueResult[] ShowDialog(Opc.Da.Server server)
		{
			if (server == null) throw new ArgumentNullException("server");

			m_server       = server;
			m_subscription = null;

			BackBTN.Enabled          = false;
			NextBTN.Enabled          = true;
			CancelBTN.Visible        = true;
			DoneBTN.Visible          = false;
			BrowseCTRL.Visible       = true;
			SubscriptionCTRL.Visible = false;
			ItemsCTRL.Visible        = true;
			ResultsCTRL.Visible      = false;

			BrowseCTRL.ShowSingleServer(m_server, null);
			ItemsCTRL.Initialize((Item)null);

			ShowDialog();

			// ensure server connection in the browse control are closed.
			BrowseCTRL.Clear();

			return m_values;
		}

		/// <summary>
		/// Prompts the use to select items for the read request.
		/// </summary>
		public ItemValueResult[] ShowDialog(Subscription subscription, bool synchronous)
		{
			if (subscription == null) throw new ArgumentNullException("subscription");

			m_server       = subscription.Server;
			m_subscription = subscription;
			m_synchronous  = synchronous;

			BackBTN.Enabled          = false;
			NextBTN.Enabled          = true;
			CancelBTN.Visible        = true;
			DoneBTN.Visible          = false;
			OptionsBTN.Visible       = true;
			BrowseCTRL.Visible       = false;
			SubscriptionCTRL.Visible = true;
			ItemsCTRL.Visible        = true;
			ResultsCTRL.Visible      = false;

			SubscriptionCTRL.Initialize(m_subscription);
			ItemsCTRL.Initialize(null, m_subscription.Items);

			ShowDialog();

			return m_values;
		}

		/// <summary>
		/// Executes a  read request for the current set if items.
		/// </summary>
		public void DoRead()
		{
			try
			{	
				// read from server.
				Item[] items = ItemsCTRL.GetItems();

				ItemValueResult[] results  = null;

				if (m_subscription != null)
				{
					if (m_synchronous)
					{
						results = m_subscription.Read(items);
					}
					else
					{
						results = new AsyncRequestDlg().ShowDialog(m_subscription, items);

						if (results == null)
						{
							return;
						}
					}
				}
				else
				{
					// add dummy client handles to test that they get returned properly.
					foreach(Item item in items) { item.ClientHandle = item.ItemName; }

					results = m_server.Read(items);
				}

				// save results.
				m_values = results;

				BackBTN.Enabled     = true;
				NextBTN.Enabled     = false;
				CancelBTN.Visible   = false;
				DoneBTN.Visible     = true;
				OptionsBTN.Visible  = false;
				ItemsCTRL.Visible   = false;
				ResultsCTRL.Visible = true;

				// display results.
				ResultsCTRL.Initialize(m_server, (m_subscription != null)?m_subscription.Locale:m_server.Locale, results);
			}
			catch (Exception e)
			{
				MessageBox.Show(e.Message);
			}
		}

		/// <summary>
		/// Discards any results from a read request.
		/// </summary>
		public void UndoRead()
		{
			// clear the previously read results.
			m_values = null;
			
			BackBTN.Enabled     = false;
			NextBTN.Enabled     = true;
			CancelBTN.Visible   = true;
			DoneBTN.Visible     = false;
			OptionsBTN.Visible  = true;
			ItemsCTRL.Visible   = true;
			ResultsCTRL.Visible = false;
		}
		
		/// <summary>
		/// Called when a server is picked in the browse control.
		/// </summary>
		private void OnItemPicked(ItemIdentifier itemID)
		{
			ItemsCTRL.AddItem(new Item(itemID));
		}

		/// <summary>
		/// Called when the back button is clicked.
		/// </summary>
		private void BackBTN_Click(object sender, System.EventArgs e)
		{
			UndoRead();
		}

		/// <summary>
		/// Called when the next button is clicked.
		/// </summary>
		private void NextBTN_Click(object sender, System.EventArgs e)
		{
			DoRead();
		}

		/// <summary>
		/// Called when the close button is clicked.
		/// </summary>
		private void DoneBTN_Click(object sender, System.EventArgs e)
		{
			if (sender == CancelBTN)
			{
				m_values = null;
			}

			DialogResult = DialogResult.Cancel;
			Close();
		}

		/// <summary>
		/// Updates the result filters used for the request.
		/// </summary>
		private void OptionsBTN_Click(object sender, System.EventArgs e)
		{
			if (m_subscription != null)
			{
				new OptionsEditDlg().ShowDialog(m_subscription);
			}
			else
			{
				new OptionsEditDlg().ShowDialog(m_server);
			}
		}
	}
}
