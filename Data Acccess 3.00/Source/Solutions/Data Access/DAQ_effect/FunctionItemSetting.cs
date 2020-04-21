using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;
using EricZhao.UiThread;
using EricZhao;

namespace DAQ
{
    public partial class FunctionItemSetting : FormItemSettings
    {
        const int var_name_column_index = 0;
        const int var_path_column_index = 1;
        const int var_type_column_index = 2;
       
        public FunctionItemSetting()
        {
            InitializeComponent();
        }

        private void btnValid_Click(object sender, EventArgs e)
        {

        }



        public new bool UpdateUiToItemData()
        {
            if (this.textBoxTagName.Text == null || this.textBoxTagName.Text.Length == 0)
            {
                MessageBox.Show("测点名不能为空(TagName cannot be empty)");

                return false;
            }

            if (this.textBoxCompany.Text == null || this.textBoxCompany.Text.Length == 0)
            {
                MessageBox.Show("公司名不能为空\r\nCompany cannot be empty");

                return false;
            }

            if (this.textBoxFactory.Text == null || this.textBoxFactory.Text.Length == 0)
            {
                MessageBox.Show("分厂名不能为空\r\nFactory cannot be empty");

                return false;
            }

            if (this.textBoxPlant.Text == null || this.textBoxPlant.Text.Length == 0)
            {
                MessageBox.Show("设备名不能为空\r\nPlant cannot be empty");

                return false;
            }

            if (this.textBoxRemoteTagName.Text == null || this.textBoxRemoteTagName.Text.Length == 0)
            {
                MessageBox.Show("远程测点名不能为空\r\nRemote Tagname cannot be empty");

                return false;
            }

            if (this.textBoxK.Text == null || this.textBoxK.Text.Length == 0)
            {
                MessageBox.Show("K不能为空(cannot be empty)");

                return false;
            }

            double ldblK = 1.0;

            if (!double.TryParse(this.textBoxK.Text, out ldblK))
            {
                MessageBox.Show("K只能是数字(only can be number eg.1.2)");

                return false;
            }


            double ldblB = 1.0;

            if (!double.TryParse(this.textBoxB.Text, out ldblB))
            {
                MessageBox.Show("B只能是数字(only can be number eg.2.0)");

                return false;
            }

            if (this.textBoxRemoteTagName.Text == null || this.textBoxRemoteTagName.Text.Length == 0)
            {
                MessageBox.Show("远程测点名不能为空(Remote Tagname cannot be empty)");

                return false;
            }

            double ldblThreshold = 1.0;

            if (!double.TryParse(this.textBoxThreshold.Text, out ldblThreshold))
            {
                MessageBox.Show("阈值必须是数字(Threshold only can be number eg.2.0)");

                return false;
            }

            List<string> loArgsNames = new List<string>();
            List<string> loArgsKeys = new List<string>();
            Dictionary<string, ItemSetting.BH_ITEM_TYPE> loTypes = new Dictionary<string, ItemSetting.BH_ITEM_TYPE>();
            if (this.listViewVar.Items.Count==0)
            {
              //  MessageBox.Show("必须定义变量(Must Define Variable)");

              //   return false;
            }
            else
            {
                for (int i = 0; i < this.listViewVar.Items.Count;i++ )
                {
                    string lstrKey =(string) this.listViewVar.Items[i].Tag;
                    loArgsKeys.Add(lstrKey);

                    String lstrVarName = this.listViewVar.Items[i].Text;
                    loArgsNames.Add(lstrVarName);

                    ItemSetting.BH_ITEM_TYPE lnType = (ItemSetting.BH_ITEM_TYPE)Enum.Parse(typeof(ItemSetting.BH_ITEM_TYPE)
                                                    , this.listViewVar.Items[i].SubItems[var_type_column_index].Text);

                    loTypes.Add(lstrKey, lnType);
                }
            }

            if (this.richTextBox1.Text.Length ==0)
            {
                MessageBox.Show("必须输入计算脚本(Must Write Script)");
                return false;
            }

            this.m_oItem.TagName = this.textBoxTagName.Text;

            this.m_oItem.Company = this.textBoxCompany.Text;

            this.m_oItem.Factory = this.textBoxFactory.Text;

            this.m_oItem.Plant = this.textBoxPlant.Text;

            this.m_oItem.RemoteTageName = this.textBoxRemoteTagName.Text;

            this.m_oItem.StartIndex = (int)this.numericUpDownStartIndex.Value;

            this.m_oItem.K = ldblK;

            this.m_oItem.B = ldblB;

            this.m_oItem.BHItemType = ItemSetting.BH_ITEM_TYPE.PROC;

            this.m_oItem.UsedAsJudgeRunStopStatus = this.checkBoxUsedAsJudge.Checked;
            this.m_oItem.DblJudgeThreshold = ldblThreshold;

            this.m_oItem.Vars = loArgsKeys;
            this.m_oItem.VarNames = loArgsNames;

            this.m_oItem.ScriptContent_header = this.lblScriptHeader.Text;
            this.m_oItem.ScriptContent_tail = this.lblScriptTail.Text;            
            this.m_oItem.ScriptContent_Body = this.richTextBox1.Text;

            this.m_oItem.VariableTypes = loTypes;

            if (this.checkBoxCheckTypeMore.Checked)
            {
                this.m_oItem.JudgeType = 0;
            }
            else
            {
                this.m_oItem.JudgeType = 1;
            }

            this.m_oItem.ItemType = 1;

            return true;
        }

        private void buttonOK_Click_1(object sender, EventArgs e)
        {
            if (this.UpdateUiToItemData())
            {
                this.DialogResult = DialogResult.OK;
                this.Close();
            }
        }

        private void buttonCancel_Click_1(object sender, EventArgs e)
        {
            this.m_oItem = null;
            this.Close(); 
        }
        List<ItemSetting> m_oAllItems = new List<ItemSetting>();
        public List<ItemSetting> AllItems
        {
            get { return m_oAllItems; }
            set { m_oAllItems = value; }
        }
        Dictionary<String, ItemSetting> m_oAllItemsMap = new Dictionary<String, ItemSetting>();
        public Dictionary<String, ItemSetting> AllItemsMap
        {
            get { return m_oAllItemsMap; }
            set { m_oAllItemsMap = value; }
        }

        private void FunctionItemSetting_Load(object sender, EventArgs e)
        {
            this.CenterToParent();
            this.listViewVar.LabelEdit = true;
            this.SyncDataToUI();
        }



        public void SyncDataToUI()
        {
            
            this.textBoxTagName.Text = this.m_oItem.TagName;

            this.textBoxCompany.Text = this.m_oItem.Company;

            this.textBoxFactory.Text = this.m_oItem.Factory;

            this.textBoxPlant.Text = this.m_oItem.Plant;

            this.textBoxRemoteTagName.Text = this.m_oItem.RemoteTageName;

            this.numericUpDownStartIndex.Value = this.m_oItem.StartIndex;

            this.numericUpDownStartIndex.Enabled = true;

            this.textBoxK.Text = this.m_oItem.K + "";
            this.textBoxB.Text = this.m_oItem.B + "";

            if (this.m_oItem.UsedAsJudgeRunStopStatus)
            {
                this.checkBoxUsedAsJudge.Checked = true;
            }
            else
            {
                this.checkBoxUsedAsJudge.Checked = false;
            }

            this.textBoxThreshold.Text = this.m_oItem.DblJudgeThreshold + "";

            if (this.m_oItem.JudgeType <= 0)
            {
                this.checkBoxCheckTypeMore.Checked = true;
                this.checkBoxChecktypeLess.Checked = false;
            }
            else
            {
                this.checkBoxCheckTypeMore.Checked = false;
                this.checkBoxChecktypeLess.Checked = true;
            }

            foreach (ItemSetting lpItem in this.AllItems)
            {
                if (lpItem.ItemType==0)
                {
                    this.AllItemsMap.Add(lpItem.Key, lpItem);
                    String lstrValue = lpItem.TagName + "(Path:" + lpItem.Key + ")";
                    this.txtBoxVar.Items.Add(lstrValue);
                }
            }

            this.checkBoxUsedAsJudge_CheckedChanged(null, null);

            foreach (string lpKey in this.m_oItem.Vars)
            {
                if (!this.AllItemsMap.ContainsKey(lpKey))
                {
                    Debug.Assert(false);
                    continue;
                }

                ItemSetting lpItem = this.AllItemsMap[lpKey];
                ListViewItem lpViewItem = new ListViewItem();
                lpViewItem.Text = lpItem.TagName;
                lpViewItem.Tag = lpItem.Key;
                this.listViewVar.Items.Add(lpViewItem);

                ListViewItem.ListViewSubItem loSubItem1 = new ListViewItem.ListViewSubItem();
                loSubItem1.Text = lpItem.Key;
                loSubItem1.Tag = lpItem;
                lpViewItem.SubItems.Add(loSubItem1);

                ListViewItem.ListViewSubItem loSubItem = new ListViewItem.ListViewSubItem();
                if (this.m_oItem.VariableTypes.ContainsKey(lpKey))
                {                  
                   ItemSetting.BH_ITEM_TYPE lnType = this.m_oItem.VariableTypes[lpKey];
                   loSubItem.Text = Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), lnType);                    
                }
                else
                {
                    loSubItem.Text = Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), lpItem.BHItemType);
                }

                loSubItem.Tag = lpItem;
                lpViewItem.SubItems.Add(loSubItem);
            }

            if(this.m_oItem.VarNames!= null)
            {
                int lnItemIndex = 0;
                foreach (string lpName in this.m_oItem.VarNames)
                {
                    if(lnItemIndex>= this.listViewVar.Items.Count)
                    {
                        break;
                    }
                    this.listViewVar.Items[lnItemIndex].Text = lpName;
                        lnItemIndex++;
                }
            }

                if (string.IsNullOrEmpty(this.m_oItem.ScriptContent_Body))
            {
                this.richTextBox1.Text = this.ParseOldScriptToContent(this.m_oItem.m_strScriptContent);
            }
            else
            {
                this.richTextBox1.Text = this.m_oItem.ScriptContent_Body;
            }
            this.ReGenerateHeader();

            foreach(ColumnHeader col in this.listViewVar.Columns)
            {
                col.Width = -2;
            }
        }

        private string ParseOldScriptToContent(string astrScriptContent)
        {
            string lstrReturnContent = "";
            if (!string.IsNullOrEmpty(astrScriptContent))
            {
                int lnStartIndex = astrScriptContent.IndexOf("{");
                int lnEndIndex = astrScriptContent.LastIndexOf("}");
                if ((lnStartIndex>=0) && (lnEndIndex>=0) && (lnEndIndex> lnStartIndex))
                {
                    lstrReturnContent = astrScriptContent.Substring(lnStartIndex + 1, (lnEndIndex - lnStartIndex)-1);
                }
            }

            return lstrReturnContent;
        }

        private void CheckedMenuItem_Click(object sender, EventArgs e)
        {
            this.listViewVar.BeginUpdate();

            for (int lnIndex = 0; lnIndex < this.listViewVar.SelectedIndices.Count; lnIndex++)
            {
                int lnItemToDelete = this.listViewVar.SelectedIndices[lnIndex] - lnIndex;
                ItemSetting lpItem = 
                    (ItemSetting)this.listViewVar.Items[lnItemToDelete].SubItems[var_type_column_index].Tag;

                if (this.BinayTypeToolStripMenuItem.Checked)
                {
                    this.listViewVar.Items[lnItemToDelete].SubItems[var_type_column_index].Text = Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), ItemSetting.BH_ITEM_TYPE.PROC);
                    this.BinayTypeToolStripMenuItem.Checked = false;
                }
                else
                {
                    this.listViewVar.Items[lnItemToDelete].SubItems[var_type_column_index].Text = Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), lpItem.BHItemType);
                    this.BinayTypeToolStripMenuItem.Checked = true;
                }

            }

            this.listViewVar.EndUpdate();
            this.ReGenerateHeader();
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.listViewVar.BeginUpdate();


            for (int lnIndex = 0; lnIndex < this.listViewVar.SelectedIndices.Count; lnIndex++)
            {
                int lnItemToDelete = this.listViewVar.SelectedIndices[lnIndex] - lnIndex;
                this.listViewVar.Items.RemoveAt(lnItemToDelete);

            }

            this.listViewVar.EndUpdate();
            this.ReGenerateHeader();
        }

        private void btnSelectVariable_Click(object sender, EventArgs e)
        {
            String lstrTag = this.txtBoxVar.Text;
            int lnIndex = lstrTag.IndexOf("(Path:");
            if(lnIndex>0)
            {
                lstrTag = lstrTag.Substring(0, lnIndex);
            }
            String lstrKey = this.textBoxCompany.Text + "." + this.textBoxFactory.Text + "." + this.textBoxPlant.Text + "." + lstrTag;

            if (lnIndex>0 && ((this.txtBoxVar.Text.Length-lnIndex)>6))
            {
                lstrKey = this.txtBoxVar.Text.Substring(lnIndex+6);
                lnIndex= lstrKey.IndexOf(")");
                if(lnIndex>0)
                {
                    lstrKey = lstrKey.Substring(0, lnIndex);
                }
            }

            if (this.AllItemsMap.ContainsKey(lstrKey))
            {
                ItemSetting lpItem = this.AllItemsMap[lstrKey];
                ListViewItem lpViewItem = new ListViewItem();
                lpViewItem.Text = this.txtBoxVar.Text;
                lpViewItem.Tag = lstrKey;

                ListViewItem.ListViewSubItem loSubItem1 = new ListViewItem.ListViewSubItem();
                loSubItem1.Text = lstrKey;
                loSubItem1.Tag = lpItem;
                lpViewItem.SubItems.Add(loSubItem1);

                ListViewItem.ListViewSubItem loSubItem = new ListViewItem.ListViewSubItem();

                loSubItem.Text = Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), lpItem.BHItemType);
                loSubItem.Tag = lpItem;
                lpViewItem.SubItems.Add(loSubItem);
                this.listViewVar.Items.Add(lpViewItem);
                this.listViewVar.Refresh();
            }
            else
            {
                MessageBox.Show("变量不在测点列表中(Var Dose Not Exist in Points list)");
            }
            this.ReGenerateHeader();
        }

        private void ToggleVariableSettingcontrols(Boolean abEnable)
        {
            this.txtBoxVar.Enabled = abEnable;
            this.btnClear.Enabled = abEnable;
            this.listViewVar.Enabled = abEnable;
            this.btnSelectVariable.Enabled = abEnable;
            this.btnValid.Enabled = abEnable;
            this.richTextBox1.Enabled = abEnable;
        }

        private void EnableVariable()
        {
            if (String.IsNullOrEmpty(this.textBoxPlant.Text)
                ||String.IsNullOrEmpty(this.textBoxFactory.Text)
                ||String.IsNullOrEmpty(this.textBoxCompany.Text))
            {
                this.ToggleVariableSettingcontrols(false);
                return;
            }
            this.ToggleVariableSettingcontrols(true);
        }

        private void textBoxCompany_TextChanged(object sender, EventArgs e)
        {
            this.EnableVariable();
        }

        private void textBoxFactory_TextChanged(object sender, EventArgs e)
        {
            this.EnableVariable();

        }

        private void textBoxPlant_TextChanged(object sender, EventArgs e)
        {
            this.EnableVariable();

        }

        private void ReGenerateHeader()
        {
            string lstrHeader = "";
            string lstrTail = "}";
            for (int i = 0; i < this.listViewVar.Items.Count;i++ )
            {
                ListViewItem lpItem = this.listViewVar.Items[i];
                if (string.IsNullOrEmpty(lstrHeader))
                {
                   
                    if (lpItem.SubItems[2].Text ==
                        Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), ItemSetting.BH_ITEM_TYPE.PROC))
                    {
                        lstrHeader += "double " +"a_"+ this.listViewVar.Items[i].Text;
                    }
                    else
                    {
                        lstrHeader += "double[] " + "a_" + this.listViewVar.Items[i].Text;
                    }
                   
                }
                else
                {
                    if (lpItem.SubItems[2].Text ==
     Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), ItemSetting.BH_ITEM_TYPE.PROC))
                    {
                        lstrHeader += ",double " + "a_" + this.listViewVar.Items[i].Text;
                    }
                    else
                    {
                        lstrHeader += ",double[] " + "a_" + this.listViewVar.Items[i].Text;
                    }
                }
            }
            this.m_oItem.ScriptContent_header = "(" + lstrHeader + "){";
            this.m_oItem.ScriptContent_tail = lstrTail;
            this.lblScriptHeader.Text = this.m_oItem.ScriptContent_header;
            this.lblScriptTail.Text = this.m_oItem.ScriptContent_tail;

            
        }

        FormError m_oErrorForm = null;



        public void HighLightErrorLine(System.CodeDom.Compiler.CompilerError apError)
        {
            if (null == apError)
            {
                return;
            }
            int anLineNumber = apError.Line;
            anLineNumber = anLineNumber - 1;
            if (anLineNumber < 0 || anLineNumber>this.richTextBox1.Lines.Length)
            {
                return;
            }

            int lnStart = this.richTextBox1.GetFirstCharIndexFromLine(anLineNumber);
            lnStart += apError.Column-2;
            string lstrCurrentlinetext = richTextBox1.Lines[anLineNumber];
            int lnCurrentLineLength = lstrCurrentlinetext.Length-lnStart;
            this.richTextBox1.Select(lnStart,1);
            this.richTextBox1.ScrollToCaret();
            this.richTextBox1.Focus();
            
        }

        private void btnValid_Click_1(object sender, EventArgs e)
        {
            if (this.m_oErrorForm!=null)
            {
                this.m_oErrorForm.listView1.Items.Clear();
                this.m_oErrorForm.Hide();
            }
            int lnArgs = this.listViewVar.Items.Count;
            object[] loArgs = new object[lnArgs];

            int sampleRate = 1024;
            double[] buffer = new double[sampleRate];
            double amplitude = 0.25 * short.MaxValue;
            double frequency = 100;
            for (int n = 0; n < buffer.Length; n++)
            {
                buffer[n] = (short)(amplitude * Math.Sin((2 * Math.PI * n * frequency) / sampleRate));                
            }

            for (int i = 0; i < loArgs.Length; i++)
            {
               /* loArgs[i] = 1;*/
                ListViewItem lpItem = this.listViewVar.Items[i];
                if (lpItem.SubItems[var_type_column_index].Text != Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), ItemSetting.BH_ITEM_TYPE.PROC))
                {
                    loArgs[i] = buffer;
                }
                else
                {
                    loArgs[i] = (double)1;
                }
            }
            String lstrError = "";
            ScriptingInterface.CompilerRunner.clearSource();
            List<System.CodeDom.Compiler.CompilerError> loErrors = new List<System.CodeDom.Compiler.CompilerError>();
            object  loObj = ScriptingInterface.CompilerRunner.Run(this.lblScriptHeader.Text + "\r\n"+ this.richTextBox1.Text + this.lblScriptTail.Text, 
                                                                    loArgs,
                                                                    ref lstrError,ref loErrors);
 
            ScriptingInterface.CompilerRunner.clearSource();
            if (loObj == null)
            {
               // 

                if (loErrors!=null)
                {
                    if (null == this.m_oErrorForm)
                    {
                        this.m_oErrorForm = new FormError();
                    }
                    this.m_oErrorForm.listView1.Items.Clear();
                    this.m_oErrorForm.m_oFormParent = this;
                    for (int i=0;i<loErrors.Count;i++)
                    {
                        System.Windows.Forms.ListViewItem lpItem = this.m_oErrorForm.listView1.Items.Add(loErrors[i].ErrorNumber);
                         lpItem.SubItems.Add(loErrors[i].ErrorText);
                         lpItem.SubItems.Add(loErrors[i].Line+"") ;
                         lpItem.Tag = loErrors[i];
                         
                    }

                    this.m_oErrorForm.Show();
                    this.m_oErrorForm.BringToFront();
                }else
                {
                    MessageBox.Show(lstrError,"错误(Error)");
                }

            }
            else
            {
                MessageBox.Show(loObj.ToString(), "成功(Succeed)");
            }
           
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < this.listViewVar.Items.Count;i++ )
            {
                this.listViewVar.Items[i].Remove();
            }

            this.listViewVar.Clear();
            this.ReGenerateHeader();
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {
            for (int lnIndex = 0; lnIndex < this.listViewVar.SelectedIndices.Count; lnIndex++)
            {
                int lnItemToDelete = this.listViewVar.SelectedIndices[lnIndex] - lnIndex;
                if (this.listViewVar.Items[lnItemToDelete].SubItems[var_type_column_index].Text ==
                    Enum.GetName(typeof(ItemSetting.BH_ITEM_TYPE), ItemSetting.BH_ITEM_TYPE.PROC))
                {
                    ToolStripMenuItem loItem = (ToolStripMenuItem)this.contextMenuStrip1.Items["BinayTypeToolStripMenuItem"];
                    loItem.Checked = false;
                }
                else
                {
                    ToolStripMenuItem loItem = (ToolStripMenuItem)this.contextMenuStrip1.Items["BinayTypeToolStripMenuItem"];
                    loItem.Checked = true;

                }

                ItemSetting lpItem = (ItemSetting)this.listViewVar.Items[lnItemToDelete].SubItems[2].Tag;
                if (lpItem.BHItemType == ItemSetting.BH_ITEM_TYPE.PROC)
                {
                    ToolStripMenuItem loItem = (ToolStripMenuItem)this.contextMenuStrip1.Items["BinayTypeToolStripMenuItem"];
                    loItem.Checked = false;
                    loItem.Enabled = false;
                }
                else
                {
                    ToolStripMenuItem loItem = (ToolStripMenuItem)this.contextMenuStrip1.Items["BinayTypeToolStripMenuItem"];
                    loItem.Enabled = true;

                }
            }
            
        }

        private void FunctionItemSetting_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (this.m_oErrorForm!=null)
            {
                this.m_oErrorForm.Close();
                this.m_oErrorForm.Dispose();
                this.m_oErrorForm = null;
            }
        }

        private void listViewVar_DoubleClick(object sender, EventArgs e)
        {
            if (this.listViewVar.SelectedItems.Count == 1)
            {
                this.listViewVar.SelectedItems[0].BeginEdit();
                this.ReGenerateHeader();
            }
        }

        private void listViewVar_AfterLabelEdit(object sender, LabelEditEventArgs e)
        {
            if (e.Label == null) { return; }
            var trimmed = e.Label.Trim();
            listViewVar.SelectedItems[0].Text = trimmed;
            this.ReGenerateHeader();
        }
    }
}
