namespace DAQ
{
    partial class FunctionItemSetting
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
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.lblScriptHeader = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.txtBoxVar = new System.Windows.Forms.ComboBox();
            this.listViewVar = new System.Windows.Forms.ListView();
            this.VarName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.VarPath = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.VarType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.deleteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.BinayTypeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnSelectVariable = new System.Windows.Forms.Button();
            this.label11 = new System.Windows.Forms.Label();
            this.btnValid = new System.Windows.Forms.Button();
            this.lblScriptTail = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownStartIndex)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(623, 602);
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click_1);
            // 
            // buttonCancel
            // 
            this.buttonCancel.Location = new System.Drawing.Point(697, 602);
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click_1);
            // 
            // groupBox2
            // 
            this.groupBox2.Size = new System.Drawing.Size(386, 167);
            // 
            // numericUpDownStartIndex
            // 
            this.numericUpDownStartIndex.Maximum = new decimal(new int[] {
            999,
            0,
            0,
            0});
            // 
            // textBoxPlant
            // 
            this.textBoxPlant.TextChanged += new System.EventHandler(this.textBoxPlant_TextChanged);
            // 
            // textBoxFactory
            // 
            this.textBoxFactory.TextChanged += new System.EventHandler(this.textBoxFactory_TextChanged);
            // 
            // textBoxCompany
            // 
            this.textBoxCompany.TextChanged += new System.EventHandler(this.textBoxCompany_TextChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Size = new System.Drawing.Size(386, 175);
            // 
            // groupBox4
            // 
            this.groupBox4.Location = new System.Drawing.Point(13, 467);
            this.groupBox4.Size = new System.Drawing.Size(385, 98);
            // 
            // checkBoxUsedAsJudge
            // 
            this.checkBoxUsedAsJudge.Size = new System.Drawing.Size(252, 16);
            this.checkBoxUsedAsJudge.Text = "启停车判断(SUD Judge: ）              ";
            // 
            // textBoxThreshold
            // 
            this.textBoxThreshold.Text = "0";
            // 
            // checkBoxCheckTypeMore
            // 
            this.checkBoxCheckTypeMore.Checked = true;
            this.checkBoxCheckTypeMore.CheckState = System.Windows.Forms.CheckState.Checked;
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.btnClear);
            this.groupBox5.Controls.Add(this.groupBox7);
            this.groupBox5.Controls.Add(this.groupBox6);
            this.groupBox5.Location = new System.Drawing.Point(420, 19);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(391, 551);
            this.groupBox5.TabIndex = 28;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "公式设置(Function Setting)";
            // 
            // btnClear
            // 
            this.btnClear.Enabled = false;
            this.btnClear.Location = new System.Drawing.Point(203, 219);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(173, 23);
            this.btnClear.TabIndex = 4;
            this.btnClear.Text = "清除(Clear)";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // groupBox7
            // 
            this.groupBox7.Controls.Add(this.lblScriptHeader);
            this.groupBox7.Controls.Add(this.richTextBox1);
            this.groupBox7.Location = new System.Drawing.Point(6, 259);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Size = new System.Drawing.Size(379, 290);
            this.groupBox7.TabIndex = 4;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "函数编写(Function Content Setting)";
            // 
            // lblScriptHeader
            // 
            this.lblScriptHeader.AutoSize = true;
            this.lblScriptHeader.Location = new System.Drawing.Point(6, 18);
            this.lblScriptHeader.Name = "lblScriptHeader";
            this.lblScriptHeader.Size = new System.Drawing.Size(107, 12);
            this.lblScriptHeader.TabIndex = 1;
            this.lblScriptHeader.Text = "                 ";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Enabled = false;
            this.richTextBox1.Location = new System.Drawing.Point(3, 34);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(373, 258);
            this.richTextBox1.TabIndex = 0;
            this.richTextBox1.Text = "";
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.txtBoxVar);
            this.groupBox6.Controls.Add(this.listViewVar);
            this.groupBox6.Controls.Add(this.btnSelectVariable);
            this.groupBox6.Location = new System.Drawing.Point(9, 17);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(373, 236);
            this.groupBox6.TabIndex = 3;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "变量定义(Variable Define)";
            // 
            // txtBoxVar
            // 
            this.txtBoxVar.CausesValidation = false;
            this.txtBoxVar.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.txtBoxVar.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.txtBoxVar.FormattingEnabled = true;
            this.txtBoxVar.Location = new System.Drawing.Point(5, 19);
            this.txtBoxVar.Name = "txtBoxVar";
            this.txtBoxVar.Size = new System.Drawing.Size(281, 20);
            this.txtBoxVar.TabIndex = 3;
            // 
            // listViewVar
            // 
            this.listViewVar.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.VarName,
            this.VarPath,
            this.VarType});
            this.listViewVar.ContextMenuStrip = this.contextMenuStrip1;
            this.listViewVar.Enabled = false;
            this.listViewVar.Location = new System.Drawing.Point(5, 47);
            this.listViewVar.Name = "listViewVar";
            this.listViewVar.Size = new System.Drawing.Size(361, 148);
            this.listViewVar.TabIndex = 2;
            this.listViewVar.UseCompatibleStateImageBehavior = false;
            this.listViewVar.View = System.Windows.Forms.View.Details;
            this.listViewVar.AfterLabelEdit += new System.Windows.Forms.LabelEditEventHandler(this.listViewVar_AfterLabelEdit);
            this.listViewVar.DoubleClick += new System.EventHandler(this.listViewVar_DoubleClick);
            // 
            // VarName
            // 
            this.VarName.Text = "变量名(var Name)";
            this.VarName.Width = 171;
            // 
            // VarPath
            // 
            this.VarPath.Text = "变量路径(path)";
            this.VarPath.Width = 127;
            // 
            // VarType
            // 
            this.VarType.Text = "类型(Type)";
            this.VarType.Width = 153;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.deleteToolStripMenuItem,
            this.BinayTypeToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.ShowCheckMargin = true;
            this.contextMenuStrip1.ShowImageMargin = false;
            this.contextMenuStrip1.Size = new System.Drawing.Size(191, 48);
            this.contextMenuStrip1.Opening += new System.ComponentModel.CancelEventHandler(this.contextMenuStrip1_Opening);
            // 
            // deleteToolStripMenuItem
            // 
            this.deleteToolStripMenuItem.Name = "deleteToolStripMenuItem";
            this.deleteToolStripMenuItem.Size = new System.Drawing.Size(190, 22);
            this.deleteToolStripMenuItem.Text = "Delete";
            this.deleteToolStripMenuItem.Click += new System.EventHandler(this.deleteToolStripMenuItem_Click);
            // 
            // BinayTypeToolStripMenuItem
            // 
            this.BinayTypeToolStripMenuItem.Name = "BinayTypeToolStripMenuItem";
            this.BinayTypeToolStripMenuItem.Size = new System.Drawing.Size(190, 22);
            this.BinayTypeToolStripMenuItem.Text = "Use as Binary Array";
            this.BinayTypeToolStripMenuItem.Click += new System.EventHandler(this.CheckedMenuItem_Click);
            // 
            // btnSelectVariable
            // 
            this.btnSelectVariable.Enabled = false;
            this.btnSelectVariable.Location = new System.Drawing.Point(292, 18);
            this.btnSelectVariable.Name = "btnSelectVariable";
            this.btnSelectVariable.Size = new System.Drawing.Size(75, 23);
            this.btnSelectVariable.TabIndex = 1;
            this.btnSelectVariable.Text = "增加(Add)";
            this.btnSelectVariable.UseVisualStyleBackColor = true;
            this.btnSelectVariable.Click += new System.EventHandler(this.btnSelectVariable_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(1, 12);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(0, 12);
            this.label11.TabIndex = 0;
            // 
            // btnValid
            // 
            this.btnValid.Enabled = false;
            this.btnValid.Location = new System.Drawing.Point(623, 576);
            this.btnValid.Name = "btnValid";
            this.btnValid.Size = new System.Drawing.Size(179, 23);
            this.btnValid.TabIndex = 1;
            this.btnValid.Text = "验证(Valid)";
            this.btnValid.UseVisualStyleBackColor = true;
            this.btnValid.Click += new System.EventHandler(this.btnValid_Click_1);
            // 
            // lblScriptTail
            // 
            this.lblScriptTail.AutoSize = true;
            this.lblScriptTail.Location = new System.Drawing.Point(427, 573);
            this.lblScriptTail.Name = "lblScriptTail";
            this.lblScriptTail.Size = new System.Drawing.Size(119, 12);
            this.lblScriptTail.TabIndex = 2;
            this.lblScriptTail.Text = "                   ";
            // 
            // FunctionItemSetting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(837, 637);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.btnValid);
            this.Controls.Add(this.lblScriptTail);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Location = new System.Drawing.Point(0, 0);
            this.Name = "FunctionItemSetting";
            this.Text = "Scriptlet Variable Function Setting";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FunctionItemSetting_FormClosing);
            this.Load += new System.EventHandler(this.FunctionItemSetting_Load);
            this.Controls.SetChildIndex(this.lblScriptTail, 0);
            this.Controls.SetChildIndex(this.buttonCancel, 0);
            this.Controls.SetChildIndex(this.buttonOK, 0);
            this.Controls.SetChildIndex(this.btnValid, 0);
            this.Controls.SetChildIndex(this.groupBox5, 0);
            this.Controls.SetChildIndex(this.groupBox4, 0);
            this.Controls.SetChildIndex(this.groupBox1, 0);
            this.Controls.SetChildIndex(this.groupBox2, 0);
            this.Controls.SetChildIndex(this.groupBox3, 0);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownStartIndex)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox7.ResumeLayout(false);
            this.groupBox7.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.Button btnSelectVariable;
        private System.Windows.Forms.ListView listViewVar;
        private System.Windows.Forms.GroupBox groupBox7;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem;
        private System.Windows.Forms.Button btnValid;
        private System.Windows.Forms.ColumnHeader VarName;
        private System.Windows.Forms.Label lblScriptHeader;
        private System.Windows.Forms.Label lblScriptTail;
        private System.Windows.Forms.ColumnHeader VarType;
        private System.Windows.Forms.ToolStripMenuItem BinayTypeToolStripMenuItem;
        private System.Windows.Forms.ComboBox txtBoxVar;
        private System.Windows.Forms.ColumnHeader VarPath;
    }
}