namespace SimpleClient
{
	partial class Form1
	{
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		/// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows フォーム デザイナで生成されたコード

		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		private void InitializeComponent()
		{
			this.txtNode = new System.Windows.Forms.TextBox();
			this.cmbServerList = new System.Windows.Forms.ComboBox();
			this.btnConnect = new System.Windows.Forms.Button();
			this.btnListRefresh = new System.Windows.Forms.Button();
			this.btnDisconnect = new System.Windows.Forms.Button();
			this.txtTag1 = new System.Windows.Forms.TextBox();
			this.txtTag2 = new System.Windows.Forms.TextBox();
			this.txtTag3 = new System.Windows.Forms.TextBox();
			this.txtTag5 = new System.Windows.Forms.TextBox();
			this.txtTag4 = new System.Windows.Forms.TextBox();
			this.txtVal5 = new System.Windows.Forms.TextBox();
			this.txtVal4 = new System.Windows.Forms.TextBox();
			this.txtVal3 = new System.Windows.Forms.TextBox();
			this.txtVal2 = new System.Windows.Forms.TextBox();
			this.txtVal1 = new System.Windows.Forms.TextBox();
			this.btnRead = new System.Windows.Forms.Button();
			this.btnWrite = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// txtNode
			// 
			this.txtNode.Location = new System.Drawing.Point(49, 10);
			this.txtNode.Name = "txtNode";
			this.txtNode.Size = new System.Drawing.Size(150, 19);
			this.txtNode.TabIndex = 0;
			this.txtNode.Text = "localhost";
			// 
			// cmbServerList
			// 
			this.cmbServerList.FormattingEnabled = true;
			this.cmbServerList.Location = new System.Drawing.Point(13, 35);
			this.cmbServerList.Name = "cmbServerList";
			this.cmbServerList.Size = new System.Drawing.Size(186, 20);
			this.cmbServerList.TabIndex = 1;
			this.cmbServerList.Text = "Takebishi.Dxp";
			// 
			// btnConnect
			// 
			this.btnConnect.Location = new System.Drawing.Point(206, 35);
			this.btnConnect.Name = "btnConnect";
			this.btnConnect.Size = new System.Drawing.Size(75, 22);
			this.btnConnect.TabIndex = 2;
			this.btnConnect.Text = "Connect";
			this.btnConnect.UseVisualStyleBackColor = true;
			this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
			// 
			// btnListRefresh
			// 
			this.btnListRefresh.Location = new System.Drawing.Point(206, 8);
			this.btnListRefresh.Name = "btnListRefresh";
			this.btnListRefresh.Size = new System.Drawing.Size(75, 23);
			this.btnListRefresh.TabIndex = 3;
			this.btnListRefresh.Text = "Refresh";
			this.btnListRefresh.UseVisualStyleBackColor = true;
			this.btnListRefresh.Click += new System.EventHandler(this.btnListRefresh_Click);
			// 
			// btnDisconnect
			// 
			this.btnDisconnect.Location = new System.Drawing.Point(205, 202);
			this.btnDisconnect.Name = "btnDisconnect";
			this.btnDisconnect.Size = new System.Drawing.Size(75, 29);
			this.btnDisconnect.TabIndex = 4;
			this.btnDisconnect.Text = "Disconnect";
			this.btnDisconnect.UseVisualStyleBackColor = true;
			this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
			// 
			// txtTag1
			// 
			this.txtTag1.Location = new System.Drawing.Point(13, 77);
			this.txtTag1.Name = "txtTag1";
			this.txtTag1.Size = new System.Drawing.Size(101, 19);
			this.txtTag1.TabIndex = 5;
			this.txtTag1.Text = "Device1.D0";
			// 
			// txtTag2
			// 
			this.txtTag2.Location = new System.Drawing.Point(12, 102);
			this.txtTag2.Name = "txtTag2";
			this.txtTag2.Size = new System.Drawing.Size(101, 19);
			this.txtTag2.TabIndex = 6;
			this.txtTag2.Text = "Device1.D1";
			// 
			// txtTag3
			// 
			this.txtTag3.Location = new System.Drawing.Point(13, 127);
			this.txtTag3.Name = "txtTag3";
			this.txtTag3.Size = new System.Drawing.Size(101, 19);
			this.txtTag3.TabIndex = 7;
			this.txtTag3.Text = "Device1.D2";
			// 
			// txtTag5
			// 
			this.txtTag5.Location = new System.Drawing.Point(12, 177);
			this.txtTag5.Name = "txtTag5";
			this.txtTag5.Size = new System.Drawing.Size(101, 19);
			this.txtTag5.TabIndex = 9;
			this.txtTag5.Text = "Device1.D4";
			// 
			// txtTag4
			// 
			this.txtTag4.Location = new System.Drawing.Point(13, 152);
			this.txtTag4.Name = "txtTag4";
			this.txtTag4.Size = new System.Drawing.Size(101, 19);
			this.txtTag4.TabIndex = 8;
			this.txtTag4.Text = "Device1.D3";
			// 
			// txtVal5
			// 
			this.txtVal5.Location = new System.Drawing.Point(119, 177);
			this.txtVal5.Name = "txtVal5";
			this.txtVal5.Size = new System.Drawing.Size(108, 19);
			this.txtVal5.TabIndex = 14;
			// 
			// txtVal4
			// 
			this.txtVal4.Location = new System.Drawing.Point(120, 152);
			this.txtVal4.Name = "txtVal4";
			this.txtVal4.Size = new System.Drawing.Size(108, 19);
			this.txtVal4.TabIndex = 13;
			// 
			// txtVal3
			// 
			this.txtVal3.Location = new System.Drawing.Point(120, 127);
			this.txtVal3.Name = "txtVal3";
			this.txtVal3.Size = new System.Drawing.Size(108, 19);
			this.txtVal3.TabIndex = 12;
			// 
			// txtVal2
			// 
			this.txtVal2.Location = new System.Drawing.Point(119, 102);
			this.txtVal2.Name = "txtVal2";
			this.txtVal2.Size = new System.Drawing.Size(108, 19);
			this.txtVal2.TabIndex = 11;
			// 
			// txtVal1
			// 
			this.txtVal1.Location = new System.Drawing.Point(120, 77);
			this.txtVal1.Name = "txtVal1";
			this.txtVal1.Size = new System.Drawing.Size(108, 19);
			this.txtVal1.TabIndex = 10;
			// 
			// btnRead
			// 
			this.btnRead.Location = new System.Drawing.Point(234, 77);
			this.btnRead.Name = "btnRead";
			this.btnRead.Size = new System.Drawing.Size(48, 52);
			this.btnRead.TabIndex = 15;
			this.btnRead.Text = "Read";
			this.btnRead.UseVisualStyleBackColor = true;
			this.btnRead.Click += new System.EventHandler(this.btnRead_Click);
			// 
			// btnWrite
			// 
			this.btnWrite.Location = new System.Drawing.Point(234, 144);
			this.btnWrite.Name = "btnWrite";
			this.btnWrite.Size = new System.Drawing.Size(47, 52);
			this.btnWrite.TabIndex = 16;
			this.btnWrite.Text = "Write";
			this.btnWrite.UseVisualStyleBackColor = true;
			this.btnWrite.Click += new System.EventHandler(this.btnWrite_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(12, 13);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(31, 12);
			this.label1.TabIndex = 17;
			this.label1.Text = "Node";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(30, 62);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(57, 12);
			this.label2.TabIndex = 18;
			this.label2.Text = "Tag Name";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(156, 62);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(34, 12);
			this.label3.TabIndex = 19;
			this.label3.Text = "Value";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(292, 240);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.btnWrite);
			this.Controls.Add(this.btnRead);
			this.Controls.Add(this.txtVal5);
			this.Controls.Add(this.txtVal4);
			this.Controls.Add(this.txtVal3);
			this.Controls.Add(this.txtVal2);
			this.Controls.Add(this.txtVal1);
			this.Controls.Add(this.txtTag5);
			this.Controls.Add(this.txtTag4);
			this.Controls.Add(this.txtTag3);
			this.Controls.Add(this.txtTag2);
			this.Controls.Add(this.txtTag1);
			this.Controls.Add(this.btnDisconnect);
			this.Controls.Add(this.btnListRefresh);
			this.Controls.Add(this.btnConnect);
			this.Controls.Add(this.cmbServerList);
			this.Controls.Add(this.txtNode);
			this.Name = "Form1";
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox txtNode;
		private System.Windows.Forms.ComboBox cmbServerList;
		private System.Windows.Forms.Button btnConnect;
		private System.Windows.Forms.Button btnListRefresh;
		private System.Windows.Forms.Button btnDisconnect;
		private System.Windows.Forms.TextBox txtTag1;
		private System.Windows.Forms.TextBox txtTag2;
		private System.Windows.Forms.TextBox txtTag3;
		private System.Windows.Forms.TextBox txtTag5;
		private System.Windows.Forms.TextBox txtTag4;
		private System.Windows.Forms.TextBox txtVal5;
		private System.Windows.Forms.TextBox txtVal4;
		private System.Windows.Forms.TextBox txtVal3;
		private System.Windows.Forms.TextBox txtVal2;
		private System.Windows.Forms.TextBox txtVal1;
		private System.Windows.Forms.Button btnRead;
		private System.Windows.Forms.Button btnWrite;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
	}
}

