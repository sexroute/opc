namespace DAQ
{
    partial class FormServerSetting
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormServerSetting));
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.comBoxServerType = new System.Windows.Forms.ComboBox();
            this.label9 = new System.Windows.Forms.Label();
            this.SourceSetting = new System.Windows.Forms.GroupBox();
            this.numericUpDownInterval = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.btnAspen = new System.Windows.Forms.Button();
            this.buttonBHTest = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.comboBoxBHServerTypeSrc = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.numericUpDownPort = new System.Windows.Forms.NumericUpDown();
            this.label7 = new System.Windows.Forms.Label();
            this.textBoxServerIP = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.buttonOpcTest = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.checkBoxAsyncRead = new System.Windows.Forms.CheckBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.textBoxPassword = new System.Windows.Forms.TextBox();
            this.labelPassword = new System.Windows.Forms.Label();
            this.textBoxUsername = new System.Windows.Forms.TextBox();
            this.labelUsername = new System.Windows.Forms.Label();
            this.textBoxProgID = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxMachine = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.buttonOK = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnBHDst = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.comboBoxBHServerTypeDst = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.numericUpDownPortDst = new System.Windows.Forms.NumericUpDown();
            this.label8 = new System.Windows.Forms.Label();
            this.textBoxServerIPDst = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.textBoxUrlServiceUrl = new System.Windows.Forms.TextBox();
            this.btnOpcDst = new System.Windows.Forms.Button();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.textBoxProgIDDst = new System.Windows.Forms.TextBox();
            this.label14 = new System.Windows.Forms.Label();
            this.textBoxMachineDst = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.comBoxServerTypeDst = new System.Windows.Forms.ComboBox();
            this.label16 = new System.Windows.Forms.Label();
            this.groupBox3.SuspendLayout();
            this.SourceSetting.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownInterval)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPort)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPortDst)).BeginInit();
            this.groupBox6.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.comBoxServerType);
            this.groupBox3.Controls.Add(this.label9);
            this.groupBox3.Location = new System.Drawing.Point(12, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(302, 54);
            this.groupBox3.TabIndex = 7;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "源类型（Source Type）";
            // 
            // comBoxServerType
            // 
            this.comBoxServerType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comBoxServerType.FormattingEnabled = true;
            this.comBoxServerType.Items.AddRange(new object[] {
            "OPC Server",
            "BH Server",
            "Aspen Server"});
            this.comBoxServerType.Location = new System.Drawing.Point(88, 23);
            this.comBoxServerType.Name = "comBoxServerType";
            this.comBoxServerType.Size = new System.Drawing.Size(208, 20);
            this.comBoxServerType.TabIndex = 1;
            this.comBoxServerType.SelectedIndexChanged += new System.EventHandler(this.comBoxServerType_SelectedIndexChanged);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(13, 26);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(71, 12);
            this.label9.TabIndex = 0;
            this.label9.Text = "源(Source):";
            // 
            // SourceSetting
            // 
            this.SourceSetting.Controls.Add(this.numericUpDownInterval);
            this.SourceSetting.Controls.Add(this.label4);
            this.SourceSetting.Controls.Add(this.btnAspen);
            this.SourceSetting.Controls.Add(this.buttonBHTest);
            this.SourceSetting.Controls.Add(this.groupBox2);
            this.SourceSetting.Controls.Add(this.buttonOpcTest);
            this.SourceSetting.Controls.Add(this.groupBox4);
            this.SourceSetting.Location = new System.Drawing.Point(13, 73);
            this.SourceSetting.Name = "SourceSetting";
            this.SourceSetting.Size = new System.Drawing.Size(301, 473);
            this.SourceSetting.TabIndex = 8;
            this.SourceSetting.TabStop = false;
            this.SourceSetting.Text = "源设置(Source Setting)";
            this.SourceSetting.Enter += new System.EventHandler(this.SourceSetting_Enter);
            // 
            // numericUpDownInterval
            // 
            this.numericUpDownInterval.Location = new System.Drawing.Point(156, 399);
            this.numericUpDownInterval.Maximum = new decimal(new int[] {
            -727379969,
            232,
            0,
            0});
            this.numericUpDownInterval.Name = "numericUpDownInterval";
            this.numericUpDownInterval.Size = new System.Drawing.Size(134, 21);
            this.numericUpDownInterval.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(36, 403);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(125, 12);
            this.label4.TabIndex = 3;
            this.label4.Text = "间隔(Interval)(ms): ";
            // 
            // btnAspen
            // 
            this.btnAspen.Location = new System.Drawing.Point(200, 435);
            this.btnAspen.Name = "btnAspen";
            this.btnAspen.Size = new System.Drawing.Size(90, 23);
            this.btnAspen.TabIndex = 16;
            this.btnAspen.Text = "&ASPEN Test";
            this.btnAspen.UseVisualStyleBackColor = true;
            this.btnAspen.Click += new System.EventHandler(this.btnAspen_Click_1);
            // 
            // buttonBHTest
            // 
            this.buttonBHTest.Location = new System.Drawing.Point(20, 435);
            this.buttonBHTest.Name = "buttonBHTest";
            this.buttonBHTest.Size = new System.Drawing.Size(90, 23);
            this.buttonBHTest.TabIndex = 15;
            this.buttonBHTest.Text = "&BH Test";
            this.buttonBHTest.UseVisualStyleBackColor = true;
            this.buttonBHTest.Click += new System.EventHandler(this.buttonBHTest_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.comboBoxBHServerTypeSrc);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.numericUpDownPort);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.textBoxServerIP);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Location = new System.Drawing.Point(14, 227);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(276, 166);
            this.groupBox2.TabIndex = 12;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "BH5000/WebSerivce 服务设置(Server Setting)";
            // 
            // comboBoxBHServerTypeSrc
            // 
            this.comboBoxBHServerTypeSrc.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxBHServerTypeSrc.FormattingEnabled = true;
            this.comboBoxBHServerTypeSrc.Location = new System.Drawing.Point(35, 136);
            this.comboBoxBHServerTypeSrc.Name = "comboBoxBHServerTypeSrc";
            this.comboBoxBHServerTypeSrc.Size = new System.Drawing.Size(233, 20);
            this.comboBoxBHServerTypeSrc.TabIndex = 16;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(19, 119);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(125, 12);
            this.label5.TabIndex = 15;
            this.label5.Text = "服务器(Server) Type:";
            // 
            // numericUpDownPort
            // 
            this.numericUpDownPort.Location = new System.Drawing.Point(35, 88);
            this.numericUpDownPort.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.numericUpDownPort.Name = "numericUpDownPort";
            this.numericUpDownPort.Size = new System.Drawing.Size(233, 21);
            this.numericUpDownPort.TabIndex = 12;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(17, 74);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(71, 12);
            this.label7.TabIndex = 8;
            this.label7.Text = "端口(Port):";
            // 
            // textBoxServerIP
            // 
            this.textBoxServerIP.Location = new System.Drawing.Point(35, 45);
            this.textBoxServerIP.Name = "textBoxServerIP";
            this.textBoxServerIP.Size = new System.Drawing.Size(233, 21);
            this.textBoxServerIP.TabIndex = 7;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(17, 29);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(113, 12);
            this.label6.TabIndex = 6;
            this.label6.Text = "服务器(Server) IP:";
            // 
            // buttonOpcTest
            // 
            this.buttonOpcTest.Location = new System.Drawing.Point(110, 435);
            this.buttonOpcTest.Name = "buttonOpcTest";
            this.buttonOpcTest.Size = new System.Drawing.Size(90, 23);
            this.buttonOpcTest.TabIndex = 11;
            this.buttonOpcTest.Text = "&OPC Test";
            this.buttonOpcTest.UseVisualStyleBackColor = true;
            this.buttonOpcTest.Click += new System.EventHandler(this.buttonOpcTest_Click_1);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.checkBoxAsyncRead);
            this.groupBox4.Controls.Add(this.label13);
            this.groupBox4.Controls.Add(this.label17);
            this.groupBox4.Controls.Add(this.textBoxPassword);
            this.groupBox4.Controls.Add(this.labelPassword);
            this.groupBox4.Controls.Add(this.textBoxUsername);
            this.groupBox4.Controls.Add(this.labelUsername);
            this.groupBox4.Controls.Add(this.textBoxProgID);
            this.groupBox4.Controls.Add(this.label2);
            this.groupBox4.Controls.Add(this.textBoxMachine);
            this.groupBox4.Controls.Add(this.label1);
            this.groupBox4.Location = new System.Drawing.Point(11, 22);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(276, 199);
            this.groupBox4.TabIndex = 10;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Opc/ASPEN 设置(setting)";
            // 
            // checkBoxAsyncRead
            // 
            this.checkBoxAsyncRead.AutoSize = true;
            this.checkBoxAsyncRead.Location = new System.Drawing.Point(109, 83);
            this.checkBoxAsyncRead.Name = "checkBoxAsyncRead";
            this.checkBoxAsyncRead.Size = new System.Drawing.Size(138, 16);
            this.checkBoxAsyncRead.TabIndex = 10;
            this.checkBoxAsyncRead.Text = "异步读(Async Read) ";
            this.checkBoxAsyncRead.UseVisualStyleBackColor = true;
            this.checkBoxAsyncRead.CheckedChanged += new System.EventHandler(this.checkBoxAsyncRead_CheckedChanged);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(13, 175);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(245, 12);
            this.label13.TabIndex = 9;
            this.label13.Text = "Need restart when user password modified";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(13, 157);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(179, 12);
            this.label17.TabIndex = 7;
            this.label17.Text = "注:修改用户名密码保存后需重启";
            // 
            // textBoxPassword
            // 
            this.textBoxPassword.Location = new System.Drawing.Point(109, 133);
            this.textBoxPassword.Name = "textBoxPassword";
            this.textBoxPassword.Size = new System.Drawing.Size(161, 21);
            this.textBoxPassword.TabIndex = 6;
            this.textBoxPassword.UseSystemPasswordChar = true;
            // 
            // labelPassword
            // 
            this.labelPassword.AutoSize = true;
            this.labelPassword.Location = new System.Drawing.Point(8, 136);
            this.labelPassword.Name = "labelPassword";
            this.labelPassword.Size = new System.Drawing.Size(101, 12);
            this.labelPassword.TabIndex = 5;
            this.labelPassword.Text = "密码(Password): ";
            // 
            // textBoxUsername
            // 
            this.textBoxUsername.Location = new System.Drawing.Point(109, 106);
            this.textBoxUsername.Name = "textBoxUsername";
            this.textBoxUsername.Size = new System.Drawing.Size(161, 21);
            this.textBoxUsername.TabIndex = 4;
            // 
            // labelUsername
            // 
            this.labelUsername.AutoSize = true;
            this.labelUsername.Location = new System.Drawing.Point(8, 109);
            this.labelUsername.Name = "labelUsername";
            this.labelUsername.Size = new System.Drawing.Size(101, 12);
            this.labelUsername.TabIndex = 3;
            this.labelUsername.Text = "用户(Username): ";
            // 
            // textBoxProgID
            // 
            this.textBoxProgID.Location = new System.Drawing.Point(109, 53);
            this.textBoxProgID.Name = "textBoxProgID";
            this.textBoxProgID.Size = new System.Drawing.Size(161, 21);
            this.textBoxProgID.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(11, 57);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(89, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "ProgID/Field: ";
            // 
            // textBoxMachine
            // 
            this.textBoxMachine.Location = new System.Drawing.Point(109, 25);
            this.textBoxMachine.Name = "textBoxMachine";
            this.textBoxMachine.Size = new System.Drawing.Size(161, 21);
            this.textBoxMachine.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(95, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "服务器(Server):";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // buttonCancel
            // 
            this.buttonCancel.Location = new System.Drawing.Point(542, 552);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(90, 23);
            this.buttonCancel.TabIndex = 14;
            this.buttonCancel.Text = "取消(&Cancel)";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click_1);
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(452, 552);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(90, 23);
            this.buttonOK.TabIndex = 13;
            this.buttonOK.Text = "确认(&OK)";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click_1);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnBHDst);
            this.groupBox1.Controls.Add(this.groupBox5);
            this.groupBox1.Controls.Add(this.btnOpcDst);
            this.groupBox1.Controls.Add(this.groupBox6);
            this.groupBox1.Location = new System.Drawing.Point(345, 73);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(301, 473);
            this.groupBox1.TabIndex = 18;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "目标设置(Destination Setting)";
            // 
            // btnBHDst
            // 
            this.btnBHDst.Location = new System.Drawing.Point(110, 444);
            this.btnBHDst.Name = "btnBHDst";
            this.btnBHDst.Size = new System.Drawing.Size(90, 23);
            this.btnBHDst.TabIndex = 15;
            this.btnBHDst.Text = "&BH Test";
            this.btnBHDst.UseVisualStyleBackColor = true;
            this.btnBHDst.Click += new System.EventHandler(this.btnBHDst_Click);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.comboBoxBHServerTypeDst);
            this.groupBox5.Controls.Add(this.label3);
            this.groupBox5.Controls.Add(this.numericUpDownPortDst);
            this.groupBox5.Controls.Add(this.label8);
            this.groupBox5.Controls.Add(this.textBoxServerIPDst);
            this.groupBox5.Controls.Add(this.label10);
            this.groupBox5.Controls.Add(this.label12);
            this.groupBox5.Controls.Add(this.textBoxUrlServiceUrl);
            this.groupBox5.Location = new System.Drawing.Point(14, 227);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(276, 211);
            this.groupBox5.TabIndex = 12;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "BH5000/WebSerivce 服务设置(Setting)";
            // 
            // comboBoxBHServerTypeDst
            // 
            this.comboBoxBHServerTypeDst.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxBHServerTypeDst.FormattingEnabled = true;
            this.comboBoxBHServerTypeDst.Location = new System.Drawing.Point(35, 182);
            this.comboBoxBHServerTypeDst.Name = "comboBoxBHServerTypeDst";
            this.comboBoxBHServerTypeDst.Size = new System.Drawing.Size(233, 20);
            this.comboBoxBHServerTypeDst.TabIndex = 14;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(19, 165);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(125, 12);
            this.label3.TabIndex = 13;
            this.label3.Text = "服务器(Server) Type:";
            // 
            // numericUpDownPortDst
            // 
            this.numericUpDownPortDst.Location = new System.Drawing.Point(35, 91);
            this.numericUpDownPortDst.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.numericUpDownPortDst.Name = "numericUpDownPortDst";
            this.numericUpDownPortDst.Size = new System.Drawing.Size(233, 21);
            this.numericUpDownPortDst.TabIndex = 12;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(17, 77);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(71, 12);
            this.label8.TabIndex = 8;
            this.label8.Text = "端口(Port):";
            // 
            // textBoxServerIPDst
            // 
            this.textBoxServerIPDst.Location = new System.Drawing.Point(35, 48);
            this.textBoxServerIPDst.Name = "textBoxServerIPDst";
            this.textBoxServerIPDst.Size = new System.Drawing.Size(233, 21);
            this.textBoxServerIPDst.TabIndex = 7;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(17, 32);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(113, 12);
            this.label10.TabIndex = 6;
            this.label10.Text = "服务器(Server) IP:";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(17, 119);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(131, 12);
            this.label12.TabIndex = 1;
            this.label12.Text = "WebService 地址(URL):";
            // 
            // textBoxUrlServiceUrl
            // 
            this.textBoxUrlServiceUrl.Location = new System.Drawing.Point(35, 138);
            this.textBoxUrlServiceUrl.Name = "textBoxUrlServiceUrl";
            this.textBoxUrlServiceUrl.Size = new System.Drawing.Size(233, 21);
            this.textBoxUrlServiceUrl.TabIndex = 3;
            // 
            // btnOpcDst
            // 
            this.btnOpcDst.Location = new System.Drawing.Point(200, 444);
            this.btnOpcDst.Name = "btnOpcDst";
            this.btnOpcDst.Size = new System.Drawing.Size(90, 23);
            this.btnOpcDst.TabIndex = 11;
            this.btnOpcDst.Text = "&OPC Test";
            this.btnOpcDst.UseVisualStyleBackColor = true;
            this.btnOpcDst.Click += new System.EventHandler(this.btnOpcDst_Click);
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.textBoxProgIDDst);
            this.groupBox6.Controls.Add(this.label14);
            this.groupBox6.Controls.Add(this.textBoxMachineDst);
            this.groupBox6.Controls.Add(this.label15);
            this.groupBox6.Location = new System.Drawing.Point(14, 22);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(273, 199);
            this.groupBox6.TabIndex = 10;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Opc/ASPEN 设置(Setting)";
            // 
            // textBoxProgIDDst
            // 
            this.textBoxProgIDDst.Location = new System.Drawing.Point(111, 52);
            this.textBoxProgIDDst.Name = "textBoxProgIDDst";
            this.textBoxProgIDDst.Size = new System.Drawing.Size(157, 21);
            this.textBoxProgIDDst.TabIndex = 2;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(11, 55);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(89, 12);
            this.label14.TabIndex = 2;
            this.label14.Text = "ProgID/Field: ";
            // 
            // textBoxMachineDst
            // 
            this.textBoxMachineDst.Location = new System.Drawing.Point(111, 25);
            this.textBoxMachineDst.Name = "textBoxMachineDst";
            this.textBoxMachineDst.Size = new System.Drawing.Size(157, 21);
            this.textBoxMachineDst.TabIndex = 1;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(10, 28);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(95, 12);
            this.label15.TabIndex = 0;
            this.label15.Text = "服务器(Server):";
            this.label15.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // groupBox7
            // 
            this.groupBox7.Controls.Add(this.comBoxServerTypeDst);
            this.groupBox7.Controls.Add(this.label16);
            this.groupBox7.Location = new System.Drawing.Point(344, 12);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Size = new System.Drawing.Size(302, 54);
            this.groupBox7.TabIndex = 17;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "目标类型(Destination Type)";
            // 
            // comBoxServerTypeDst
            // 
            this.comBoxServerTypeDst.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comBoxServerTypeDst.FormattingEnabled = true;
            this.comBoxServerTypeDst.Items.AddRange(new object[] {
            "OPC Server",
            "BH Server",
            "Aspen Server"});
            this.comBoxServerTypeDst.Location = new System.Drawing.Point(90, 23);
            this.comBoxServerTypeDst.Name = "comBoxServerTypeDst";
            this.comBoxServerTypeDst.Size = new System.Drawing.Size(204, 20);
            this.comBoxServerTypeDst.TabIndex = 1;
            this.comBoxServerTypeDst.SelectedIndexChanged += new System.EventHandler(this.comBoxServerTypeDst_SelectedIndexChanged);
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(13, 26);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(71, 12);
            this.label16.TabIndex = 0;
            this.label16.Text = "目标(Dst) :";
            // 
            // FormServerSetting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(661, 587);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.SourceSetting);
            this.Controls.Add(this.groupBox7);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonOK);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormServerSetting";
            this.Text = "Server Setting";
            this.Load += new System.EventHandler(this.FormServerSetting_Load);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.SourceSetting.ResumeLayout(false);
            this.SourceSetting.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownInterval)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPort)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPortDst)).EndInit();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.groupBox7.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.GroupBox groupBox3;
        public System.Windows.Forms.Label label9;
        public System.Windows.Forms.ComboBox comBoxServerType;
        private System.Windows.Forms.GroupBox SourceSetting;
        public System.Windows.Forms.Button btnAspen;
        public System.Windows.Forms.Button buttonBHTest;
        public System.Windows.Forms.GroupBox groupBox2;
        public System.Windows.Forms.NumericUpDown numericUpDownPort;
        public System.Windows.Forms.Label label7;
        public System.Windows.Forms.TextBox textBoxServerIP;
        public System.Windows.Forms.Label label6;
        public System.Windows.Forms.Button buttonOpcTest;
        public System.Windows.Forms.Button buttonCancel;
        public System.Windows.Forms.Button buttonOK;
        public System.Windows.Forms.GroupBox groupBox4;
        public System.Windows.Forms.TextBox textBoxProgID;
        public System.Windows.Forms.Label label2;
        public System.Windows.Forms.TextBox textBoxMachine;
        public System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox1;
        public System.Windows.Forms.Button btnBHDst;
        public System.Windows.Forms.GroupBox groupBox5;
        public System.Windows.Forms.NumericUpDown numericUpDownPortDst;
        public System.Windows.Forms.Label label8;
        public System.Windows.Forms.TextBox textBoxServerIPDst;
        public System.Windows.Forms.Label label10;
        public System.Windows.Forms.Label label12;
        public System.Windows.Forms.TextBox textBoxUrlServiceUrl;
        public System.Windows.Forms.Button btnOpcDst;
        public System.Windows.Forms.GroupBox groupBox6;
        public System.Windows.Forms.TextBox textBoxProgIDDst;
        public System.Windows.Forms.Label label14;
        public System.Windows.Forms.TextBox textBoxMachineDst;
        public System.Windows.Forms.Label label15;
        public System.Windows.Forms.GroupBox groupBox7;
        public System.Windows.Forms.ComboBox comBoxServerTypeDst;
        public System.Windows.Forms.Label label16;
        public System.Windows.Forms.NumericUpDown numericUpDownInterval;
        public System.Windows.Forms.Label label4;
        public System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboBoxBHServerTypeDst;
        private System.Windows.Forms.ComboBox comboBoxBHServerTypeSrc;
        public System.Windows.Forms.Label label5;
        public System.Windows.Forms.Label labelUsername;
        public System.Windows.Forms.TextBox textBoxUsername;
        public System.Windows.Forms.Label labelPassword;
        public System.Windows.Forms.TextBox textBoxPassword;
        public System.Windows.Forms.Label label17;
        public System.Windows.Forms.Label label13;
        private System.Windows.Forms.CheckBox checkBoxAsyncRead;
    }
}