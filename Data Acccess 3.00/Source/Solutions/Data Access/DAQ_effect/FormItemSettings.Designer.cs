namespace DAQ
{
    partial class FormItemSettings
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormItemSettings));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBoxTagName = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonOK = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.numericUpDownStartIndex = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxPlant = new System.Windows.Forms.TextBox();
            this.textBoxFactory = new System.Windows.Forms.TextBox();
            this.textBoxCompany = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.Company = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.checkBoxModeReadWrite = new System.Windows.Forms.CheckBox();
            this.checkBoxModeWrite = new System.Windows.Forms.CheckBox();
            this.checkBoxModeRead = new System.Windows.Forms.CheckBox();
            this.label11 = new System.Windows.Forms.Label();
            this.checkBoxIsProc = new System.Windows.Forms.CheckBox();
            this.checkBoxIsDyn = new System.Windows.Forms.CheckBox();
            this.checkBoxIsVib = new System.Windows.Forms.CheckBox();
            this.label10 = new System.Windows.Forms.Label();
            this.checkBoxChecktypeLess = new System.Windows.Forms.CheckBox();
            this.checkBoxCheckTypeMore = new System.Windows.Forms.CheckBox();
            this.labelJudgeType = new System.Windows.Forms.Label();
            this.textBoxThreshold = new System.Windows.Forms.TextBox();
            this.labelThreshold = new System.Windows.Forms.Label();
            this.checkBoxUsedAsJudge = new System.Windows.Forms.CheckBox();
            this.textBoxRemoteTagName = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.label9 = new System.Windows.Forms.Label();
            this.textBoxB = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.textBoxK = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownStartIndex)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBoxTagName);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(386, 73);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "设置(OPC/ASPEN Item Setting)";
            // 
            // textBoxTagName
            // 
            this.textBoxTagName.Location = new System.Drawing.Point(161, 29);
            this.textBoxTagName.Name = "textBoxTagName";
            this.textBoxTagName.Size = new System.Drawing.Size(186, 21);
            this.textBoxTagName.TabIndex = 2;
            this.textBoxTagName.TextChanged += new System.EventHandler(this.textBoxTagName_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 33);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(149, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "OPC/ASPEN TAGNAME(位号):";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 12);
            this.label1.TabIndex = 0;
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(173, 595);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(75, 23);
            this.buttonOK.TabIndex = 1;
            this.buttonOK.Text = "确认(&OK)";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.Location = new System.Drawing.Point(254, 595);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(105, 23);
            this.buttonCancel.TabIndex = 2;
            this.buttonCancel.Text = "取消(&Cancel)";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.numericUpDownStartIndex);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.textBoxPlant);
            this.groupBox2.Controls.Add(this.textBoxFactory);
            this.groupBox2.Controls.Add(this.textBoxCompany);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.Company);
            this.groupBox2.Location = new System.Drawing.Point(12, 91);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(385, 178);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "BH 设备设置(Plant Setting)";
            // 
            // numericUpDownStartIndex
            // 
            this.numericUpDownStartIndex.Location = new System.Drawing.Point(161, 136);
            this.numericUpDownStartIndex.Maximum = new decimal(new int[] {
            9999,
            0,
            0,
            0});
            this.numericUpDownStartIndex.Name = "numericUpDownStartIndex";
            this.numericUpDownStartIndex.Size = new System.Drawing.Size(186, 21);
            this.numericUpDownStartIndex.TabIndex = 25;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 138);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(137, 12);
            this.label3.TabIndex = 24;
            this.label3.Text = "起始索引(Start Index):";
            // 
            // textBoxPlant
            // 
            this.textBoxPlant.Location = new System.Drawing.Point(161, 99);
            this.textBoxPlant.Name = "textBoxPlant";
            this.textBoxPlant.Size = new System.Drawing.Size(186, 21);
            this.textBoxPlant.TabIndex = 21;
            // 
            // textBoxFactory
            // 
            this.textBoxFactory.Location = new System.Drawing.Point(161, 62);
            this.textBoxFactory.Name = "textBoxFactory";
            this.textBoxFactory.Size = new System.Drawing.Size(186, 21);
            this.textBoxFactory.TabIndex = 20;
            // 
            // textBoxCompany
            // 
            this.textBoxCompany.Location = new System.Drawing.Point(161, 22);
            this.textBoxCompany.Name = "textBoxCompany";
            this.textBoxCompany.Size = new System.Drawing.Size(186, 21);
            this.textBoxCompany.TabIndex = 19;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(62, 102);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(77, 12);
            this.label5.TabIndex = 18;
            this.label5.Text = "设备(Plant):";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(50, 65);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(89, 12);
            this.label4.TabIndex = 17;
            this.label4.Text = "分厂(Factory):";
            // 
            // Company
            // 
            this.Company.AutoSize = true;
            this.Company.Location = new System.Drawing.Point(50, 25);
            this.Company.Name = "Company";
            this.Company.Size = new System.Drawing.Size(89, 12);
            this.Company.TabIndex = 16;
            this.Company.Text = "公司(Company):";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.checkBoxModeReadWrite);
            this.groupBox3.Controls.Add(this.checkBoxModeWrite);
            this.groupBox3.Controls.Add(this.checkBoxModeRead);
            this.groupBox3.Controls.Add(this.label11);
            this.groupBox3.Controls.Add(this.checkBoxIsProc);
            this.groupBox3.Controls.Add(this.checkBoxIsDyn);
            this.groupBox3.Controls.Add(this.checkBoxIsVib);
            this.groupBox3.Controls.Add(this.label10);
            this.groupBox3.Controls.Add(this.checkBoxChecktypeLess);
            this.groupBox3.Controls.Add(this.checkBoxCheckTypeMore);
            this.groupBox3.Controls.Add(this.labelJudgeType);
            this.groupBox3.Controls.Add(this.textBoxThreshold);
            this.groupBox3.Controls.Add(this.labelThreshold);
            this.groupBox3.Controls.Add(this.checkBoxUsedAsJudge);
            this.groupBox3.Controls.Add(this.textBoxRemoteTagName);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Location = new System.Drawing.Point(12, 275);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(385, 213);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "BH 测试设置(Item Setting)";
            // 
            // checkBoxModeReadWrite
            // 
            this.checkBoxModeReadWrite.AutoSize = true;
            this.checkBoxModeReadWrite.Location = new System.Drawing.Point(233, 191);
            this.checkBoxModeReadWrite.Name = "checkBoxModeReadWrite";
            this.checkBoxModeReadWrite.Size = new System.Drawing.Size(120, 16);
            this.checkBoxModeReadWrite.TabIndex = 40;
            this.checkBoxModeReadWrite.Text = "读写(Read/Write)";
            this.checkBoxModeReadWrite.UseVisualStyleBackColor = true;
            this.checkBoxModeReadWrite.CheckedChanged += new System.EventHandler(this.checkBoxModeReadWrite_CheckedChanged);
            // 
            // checkBoxModeWrite
            // 
            this.checkBoxModeWrite.AutoSize = true;
            this.checkBoxModeWrite.Location = new System.Drawing.Point(65, 191);
            this.checkBoxModeWrite.Name = "checkBoxModeWrite";
            this.checkBoxModeWrite.Size = new System.Drawing.Size(78, 16);
            this.checkBoxModeWrite.TabIndex = 39;
            this.checkBoxModeWrite.Text = "写(Write)";
            this.checkBoxModeWrite.UseVisualStyleBackColor = true;
            this.checkBoxModeWrite.Visible = false;
            this.checkBoxModeWrite.CheckedChanged += new System.EventHandler(this.checkBoxModeWrite_CheckedChanged);
            // 
            // checkBoxModeRead
            // 
            this.checkBoxModeRead.AutoSize = true;
            this.checkBoxModeRead.Location = new System.Drawing.Point(150, 191);
            this.checkBoxModeRead.Name = "checkBoxModeRead";
            this.checkBoxModeRead.Size = new System.Drawing.Size(72, 16);
            this.checkBoxModeRead.TabIndex = 38;
            this.checkBoxModeRead.Text = "读(Read)";
            this.checkBoxModeRead.UseVisualStyleBackColor = true;
            this.checkBoxModeRead.CheckedChanged += new System.EventHandler(this.checkBoxModeRead_CheckedChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(26, 176);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(155, 12);
            this.label11.TabIndex = 37;
            this.label11.Text = "通信模式(Transfer Mode) :";
            // 
            // checkBoxIsProc
            // 
            this.checkBoxIsProc.AutoSize = true;
            this.checkBoxIsProc.Location = new System.Drawing.Point(186, 154);
            this.checkBoxIsProc.Name = "checkBoxIsProc";
            this.checkBoxIsProc.Size = new System.Drawing.Size(96, 16);
            this.checkBoxIsProc.TabIndex = 36;
            this.checkBoxIsProc.Text = "工艺量(Proc)";
            this.checkBoxIsProc.UseVisualStyleBackColor = true;
            this.checkBoxIsProc.CheckedChanged += new System.EventHandler(this.checkBoxIsProc_CheckedChanged);
            // 
            // checkBoxIsDyn
            // 
            this.checkBoxIsDyn.AutoSize = true;
            this.checkBoxIsDyn.Location = new System.Drawing.Point(269, 134);
            this.checkBoxIsDyn.Name = "checkBoxIsDyn";
            this.checkBoxIsDyn.Size = new System.Drawing.Size(78, 16);
            this.checkBoxIsDyn.TabIndex = 35;
            this.checkBoxIsDyn.Text = "动态(DYN)";
            this.checkBoxIsDyn.UseVisualStyleBackColor = true;
            this.checkBoxIsDyn.CheckedChanged += new System.EventHandler(this.checkBoxIsDyn_CheckedChanged);
            // 
            // checkBoxIsVib
            // 
            this.checkBoxIsVib.AutoSize = true;
            this.checkBoxIsVib.Location = new System.Drawing.Point(186, 133);
            this.checkBoxIsVib.Name = "checkBoxIsVib";
            this.checkBoxIsVib.Size = new System.Drawing.Size(78, 16);
            this.checkBoxIsVib.TabIndex = 34;
            this.checkBoxIsVib.Text = "振动(VIB)";
            this.checkBoxIsVib.UseVisualStyleBackColor = true;
            this.checkBoxIsVib.CheckedChanged += new System.EventHandler(this.checkBoxIsArray_CheckedChanged);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(38, 136);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(113, 12);
            this.label10.TabIndex = 33;
            this.label10.Text = "BH测点类型(Type) :";
            // 
            // checkBoxChecktypeLess
            // 
            this.checkBoxChecktypeLess.AutoSize = true;
            this.checkBoxChecktypeLess.Location = new System.Drawing.Point(269, 111);
            this.checkBoxChecktypeLess.Name = "checkBoxChecktypeLess";
            this.checkBoxChecktypeLess.Size = new System.Drawing.Size(84, 16);
            this.checkBoxChecktypeLess.TabIndex = 32;
            this.checkBoxChecktypeLess.Text = "少于(Less)";
            this.checkBoxChecktypeLess.UseVisualStyleBackColor = true;
            this.checkBoxChecktypeLess.CheckedChanged += new System.EventHandler(this.checkBoxChecktypeLess_CheckedChanged);
            // 
            // checkBoxCheckTypeMore
            // 
            this.checkBoxCheckTypeMore.AutoSize = true;
            this.checkBoxCheckTypeMore.Location = new System.Drawing.Point(186, 111);
            this.checkBoxCheckTypeMore.Name = "checkBoxCheckTypeMore";
            this.checkBoxCheckTypeMore.Size = new System.Drawing.Size(84, 16);
            this.checkBoxCheckTypeMore.TabIndex = 31;
            this.checkBoxCheckTypeMore.Text = "高于(More)";
            this.checkBoxCheckTypeMore.UseVisualStyleBackColor = true;
            this.checkBoxCheckTypeMore.CheckedChanged += new System.EventHandler(this.checkBoxCheckTypeMore_CheckedChanged);
            // 
            // labelJudgeType
            // 
            this.labelJudgeType.AutoSize = true;
            this.labelJudgeType.Location = new System.Drawing.Point(26, 111);
            this.labelJudgeType.Name = "labelJudgeType";
            this.labelJudgeType.Size = new System.Drawing.Size(131, 12);
            this.labelJudgeType.TabIndex = 30;
            this.labelJudgeType.Text = "判断类型(Judge Type):";
            // 
            // textBoxThreshold
            // 
            this.textBoxThreshold.Enabled = false;
            this.textBoxThreshold.Location = new System.Drawing.Point(158, 80);
            this.textBoxThreshold.Name = "textBoxThreshold";
            this.textBoxThreshold.Size = new System.Drawing.Size(189, 21);
            this.textBoxThreshold.TabIndex = 29;
            this.textBoxThreshold.Text = "1";
            // 
            // labelThreshold
            // 
            this.labelThreshold.AutoSize = true;
            this.labelThreshold.Location = new System.Drawing.Point(33, 83);
            this.labelThreshold.Name = "labelThreshold";
            this.labelThreshold.Size = new System.Drawing.Size(101, 12);
            this.labelThreshold.TabIndex = 28;
            this.labelThreshold.Text = "阈值(Threshold):";
            // 
            // checkBoxUsedAsJudge
            // 
            this.checkBoxUsedAsJudge.AutoSize = true;
            this.checkBoxUsedAsJudge.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.checkBoxUsedAsJudge.Location = new System.Drawing.Point(30, 56);
            this.checkBoxUsedAsJudge.Name = "checkBoxUsedAsJudge";
            this.checkBoxUsedAsJudge.Size = new System.Drawing.Size(210, 16);
            this.checkBoxUsedAsJudge.TabIndex = 27;
            this.checkBoxUsedAsJudge.Text = "启停车判断(SUD Judge: ）       ";
            this.checkBoxUsedAsJudge.UseVisualStyleBackColor = true;
            this.checkBoxUsedAsJudge.CheckedChanged += new System.EventHandler(this.checkBoxUsedAsJudge_CheckedChanged);
            // 
            // textBoxRemoteTagName
            // 
            this.textBoxRemoteTagName.Location = new System.Drawing.Point(161, 20);
            this.textBoxRemoteTagName.Name = "textBoxRemoteTagName";
            this.textBoxRemoteTagName.Size = new System.Drawing.Size(186, 21);
            this.textBoxRemoteTagName.TabIndex = 25;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(29, 26);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(107, 12);
            this.label6.TabIndex = 24;
            this.label6.Text = "BH 位号(Tagname):";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.label9);
            this.groupBox4.Controls.Add(this.textBoxB);
            this.groupBox4.Controls.Add(this.label8);
            this.groupBox4.Controls.Add(this.textBoxK);
            this.groupBox4.Controls.Add(this.label7);
            this.groupBox4.Location = new System.Drawing.Point(12, 494);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(385, 95);
            this.groupBox4.TabIndex = 26;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "BH Item 测点系数(Trans)";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(159, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(89, 12);
            this.label9.TabIndex = 28;
            this.label9.Text = "Item =K*Item+B";
            // 
            // textBoxB
            // 
            this.textBoxB.Location = new System.Drawing.Point(161, 62);
            this.textBoxB.Name = "textBoxB";
            this.textBoxB.Size = new System.Drawing.Size(186, 21);
            this.textBoxB.TabIndex = 27;
            this.textBoxB.Text = "0";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(88, 65);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(17, 12);
            this.label8.TabIndex = 26;
            this.label8.Text = "B:";
            // 
            // textBoxK
            // 
            this.textBoxK.Location = new System.Drawing.Point(161, 35);
            this.textBoxK.Name = "textBoxK";
            this.textBoxK.Size = new System.Drawing.Size(186, 21);
            this.textBoxK.TabIndex = 25;
            this.textBoxK.Text = "1";
            this.textBoxK.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxK_Validating);
            this.textBoxK.Validated += new System.EventHandler(this.textBoxK_Validated);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(88, 37);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(17, 12);
            this.label7.TabIndex = 24;
            this.label7.Text = "K:";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // FormItemSettings
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(411, 625);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonOK);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormItemSettings";
            this.Text = "设置(Settings)";
            this.Load += new System.EventHandler(this.FormItemSettings_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownStartIndex)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.GroupBox groupBox1;
        public System.Windows.Forms.Label label2;
        public System.Windows.Forms.Label label1;
        public System.Windows.Forms.TextBox textBoxTagName;
        public System.Windows.Forms.Button buttonOK;
        public System.Windows.Forms.Button buttonCancel;
        public System.Windows.Forms.GroupBox groupBox2;
        public System.Windows.Forms.NumericUpDown numericUpDownStartIndex;
        public System.Windows.Forms.Label label3;
        public System.Windows.Forms.TextBox textBoxPlant;
        public System.Windows.Forms.TextBox textBoxFactory;
        public System.Windows.Forms.TextBox textBoxCompany;
        public System.Windows.Forms.Label label5;
        public System.Windows.Forms.Label label4;
        public System.Windows.Forms.Label Company;
        public System.Windows.Forms.GroupBox groupBox3;
        public System.Windows.Forms.TextBox textBoxRemoteTagName;
        public System.Windows.Forms.Label label6;
        public System.Windows.Forms.GroupBox groupBox4;
        public System.Windows.Forms.TextBox textBoxK;
        public System.Windows.Forms.Label label7;
        public System.Windows.Forms.TextBox textBoxB;
        public System.Windows.Forms.Label label8;
        public System.Windows.Forms.Label label9;
        public System.Windows.Forms.CheckBox checkBoxUsedAsJudge;
        public System.Windows.Forms.Label labelThreshold;
        public System.Windows.Forms.TextBox textBoxThreshold;
        public System.Windows.Forms.Label labelJudgeType;
        public System.Windows.Forms.CheckBox checkBoxChecktypeLess;
        public System.Windows.Forms.CheckBox checkBoxCheckTypeMore;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.CheckBox checkBoxIsVib;
        private System.Windows.Forms.CheckBox checkBoxIsDyn;
        private System.Windows.Forms.CheckBox checkBoxIsProc;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.CheckBox checkBoxModeRead;
        private System.Windows.Forms.CheckBox checkBoxModeWrite;
        private System.Windows.Forms.CheckBox checkBoxModeReadWrite;
    }
}