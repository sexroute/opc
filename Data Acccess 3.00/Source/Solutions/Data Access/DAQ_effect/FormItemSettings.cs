using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace DAQ
{
    public partial class FormItemSettings : Form
    {


        public FormItemSettings()
        {
            InitializeComponent();

            this.CenterToParent();


        }

       public ItemSetting m_oItem = new ItemSetting();
        public DAQ.ItemSetting Item
        {
            get { return m_oItem; }
            set { m_oItem = value; }
        }
        public ServerSetting m_oServer = null;

        public bool UpdateUiToItemData()
        {
            if (this.textBoxTagName.Text == null || this.textBoxTagName.Text.Length == 0)
            {
                MessageBox.Show("测点名不能为空(TagName cannot be empty)");

                return false;
            }

            if (this.textBoxCompany.Text == null || this.textBoxCompany.Text.Length == 0)
            {
                MessageBox.Show("公司名不能为空(Company cannot be empty)");

                return false;
            }

            if (this.textBoxFactory.Text == null || this.textBoxFactory.Text.Length == 0)
            {
                MessageBox.Show("分厂名不能为空(Factory cannot be empty)");

                return false;
            }

            if (this.textBoxPlant.Text == null || this.textBoxPlant.Text.Length == 0)
            {
                MessageBox.Show("设备名不能为空(Plant cannot be empty)");

                return false;
            }

            if (this.textBoxRemoteTagName.Text == null || this.textBoxRemoteTagName.Text.Length == 0)
            {
                MessageBox.Show("远程测点名不能为空(Remote Tagname cannot be empty)");

                return false;
            }

            if (this.textBoxK.Text == null || this.textBoxK.Text.Length == 0 )
            {
                MessageBox.Show("K不能为空(cannot be empty)");

                return false;
            }

            double ldblK = 1.0;

            if (!double.TryParse(this.textBoxK.Text,out ldblK))
            {
                MessageBox.Show("K 必须是数字(only can be number eg.1.2)");

                return false;
            }


            double ldblB = 1.0;

            if (!double.TryParse(this.textBoxB.Text, out ldblB))
            {
                MessageBox.Show("B 必须是数字(only can be number eg.2.0)");

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

            this.m_oItem.TagName = this.textBoxTagName.Text;

            this.m_oItem.Company = this.textBoxCompany.Text;

            this.m_oItem.Factory = this.textBoxFactory.Text;

            this.m_oItem.Plant = this.textBoxPlant.Text;

            this.m_oItem.RemoteTageName = this.textBoxRemoteTagName.Text;

            this.m_oItem.StartIndex = (int)this.numericUpDownStartIndex.Value;

            this.m_oItem.K = ldblK;

            this.m_oItem.B = ldblB;

            this.m_oItem.UsedAsJudgeRunStopStatus = this.checkBoxUsedAsJudge.Checked;
            this.m_oItem.DblJudgeThreshold = ldblThreshold;

            if (this.checkBoxIsVib.Checked)
            {
                this.m_oItem.BHItemType = ItemSetting.BH_ITEM_TYPE.VIB;
            }

            if (this.checkBoxIsDyn.Checked)
            {
                this.m_oItem.BHItemType = ItemSetting.BH_ITEM_TYPE.DYN;
            }

            if (this.checkBoxIsProc.Checked)
            {
                this.m_oItem.BHItemType = ItemSetting.BH_ITEM_TYPE.PROC;
            }

            if (this.checkBoxCheckTypeMore.Checked)
            {
                this.m_oItem.JudgeType = 0;
            }
            else
            {
                this.m_oItem.JudgeType = 1;
            }

            if (this.checkBoxModeRead.Checked)
            {
                this.m_oItem.TransferMode = ItemSetting.BH_TRANSFER_MODE.READ;
            }else if (this.checkBoxModeWrite.Checked)
            {
                this.m_oItem.TransferMode = ItemSetting.BH_TRANSFER_MODE.WRITE;
            }
            else if (this.checkBoxModeReadWrite.Checked)
            {
                this.m_oItem.TransferMode = ItemSetting.BH_TRANSFER_MODE.READ_WRITE;
            }

            return true;
        }

        public void buttonCancel_Click(object sender, EventArgs e)
        {
            this.m_oItem = null;
            this.Close();           
        }

        public void buttonOK_Click(object sender, EventArgs e)
        {
            if (this.UpdateUiToItemData())
            {
                this.DialogResult = DialogResult.OK;
                this.Close();               
            }
        }

        public void SyncDataToUI()
        {
            this.textBoxTagName.Text = this.m_oItem.TagName;

            this.textBoxCompany.Text = this.m_oItem.Company ;

            this.textBoxFactory.Text = this.m_oItem.Factory ;

            this.textBoxPlant.Text = this.m_oItem.Plant  ;

            this.textBoxRemoteTagName.Text = this.m_oItem.RemoteTageName;

            this.numericUpDownStartIndex.Value = this.m_oItem.StartIndex;

            this.textBoxK.Text = this.m_oItem.K+"";
            this.textBoxB.Text = this.m_oItem.B+"";
            
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

            this.checkBoxUsedAsJudge_CheckedChanged(null, null);

            if (this.m_oItem.BHItemType == ItemSetting.BH_ITEM_TYPE.PROC)
            {
                this.checkBoxIsProc.Checked = true;
            }
            else if (this.m_oItem.BHItemType == ItemSetting.BH_ITEM_TYPE.DYN)
            {
                this.checkBoxIsDyn.Checked = true;
            }
            else if (this.m_oItem.BHItemType == ItemSetting.BH_ITEM_TYPE.VIB)
            {
                this.checkBoxIsVib.Checked = true;
            }
            else
            {
                Debug.Assert(false);
            }

            switch (this.m_oItem.TransferMode)
            {
                case ItemSetting.BH_TRANSFER_MODE.READ_WRITE:
                    this.checkBoxModeReadWrite.Checked = true;
                    break;
                case ItemSetting.BH_TRANSFER_MODE.READ:
                    this.checkBoxModeRead.Checked = true;
                    break;
                case ItemSetting.BH_TRANSFER_MODE.WRITE:
                    this.checkBoxModeWrite.Checked = true;
                    break;
            }
        }

        public void FormItemSettings_Load(object sender, EventArgs e)
        {
            this.SyncDataToUI();
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        public void textBoxK_Validating(object sender, CancelEventArgs e)
        {
            this.NumberValidating(sender, e);
        }

        public void textBoxK_Validated(object sender, EventArgs e)
        {
            
        }

        public void NumberValidating(object sender, CancelEventArgs e)
        {

            TextBox tb = (TextBox)sender;
            double ldblValue = 0;
            if (double.TryParse(tb.Text,out ldblValue))
            {
                e.Cancel = false;
            }
            else
            {
                e.Cancel = true;
            }
        }

        public void label10_Click(object sender, EventArgs e)
        {

        }

        public void checkBoxUsedAsJudge_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxUsedAsJudge.Checked)
            {
                this.textBoxThreshold.Enabled = true;
                this.checkBoxCheckTypeMore.Enabled = true;
                this.checkBoxChecktypeLess.Enabled = true;
                this.labelJudgeType.Enabled = true;
                this.labelThreshold.Enabled = true; 
            }
            else
            {
                this.textBoxThreshold.Enabled = false;
                this.checkBoxCheckTypeMore.Enabled = false;
                this.checkBoxChecktypeLess.Enabled = false;
                this.labelJudgeType.Enabled = false;
                this.labelThreshold.Enabled = false; 
            }
        }

        public void checkBoxCheckTypeMore_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxCheckTypeMore.Checked)
            {
                this.checkBoxChecktypeLess.Checked = false;
            }
            else
            {
                this.checkBoxChecktypeLess.Checked = true;
            }
        }

        public void checkBoxChecktypeLess_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxChecktypeLess.Checked)
            {
                this.checkBoxCheckTypeMore.Checked = false;
            }
            else
            {
                this.checkBoxCheckTypeMore.Checked = true;
            }
        }

        public void textBoxTagName_TextChanged(object sender, EventArgs e)
        {

        }

        private void checkBoxIsArray_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxIsVib.Checked)
            {
                this.checkBoxIsDyn.Checked = false;
                this.checkBoxIsProc.Checked = false;
            }

            //this.checkBoxIsVib.Checked = true;
        }

        private void checkBoxIsDyn_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxIsDyn.Checked)
            {
                this.checkBoxIsVib.Checked = false;
                this.checkBoxIsProc.Checked = false;
            }

            //this.checkBoxIsDyn.Checked = true;
        }

        private void checkBoxIsProc_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxIsProc.Checked)
            {
                this.checkBoxIsDyn.Checked = false;
                this.checkBoxIsVib.Checked = false;
            }

            //this.checkBoxIsProc.Checked = true;
        }

        private void checkBoxModeRead_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxModeRead.Checked)
            {
                this.checkBoxModeReadWrite.Checked = false;
                this.checkBoxModeWrite.Checked = false;
            }
        }

        private void checkBoxModeWrite_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxModeWrite.Checked)
            {
                this.checkBoxModeReadWrite.Checked = false;
                this.checkBoxModeRead.Checked = false;
            }
        }

        private void checkBoxModeReadWrite_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBoxModeReadWrite.Checked)
            {
                this.checkBoxModeRead.Checked = false;
                this.checkBoxModeWrite.Checked = false;
            }
        }


    }
}
