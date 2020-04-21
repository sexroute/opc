using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace DAQ
{
    public partial class FormItemSettings : Form
    {
        public FormItemSettings()
        {
            InitializeComponent();

            this.CenterToParent();


        }

        ItemSetting m_oItem = new ItemSetting();
        public DAQ.ItemSetting Item
        {
            get { return m_oItem; }
            set { m_oItem = value; }
        }
        ServerSetting m_oServer = null;

        bool CheckItem()
        {
            if (this.textBoxTagName.Text == null || this.textBoxTagName.Text.Length == 0)
            {
                MessageBox.Show("TagName cannot be empty");

                return false;
            }

            if (this.textBoxCompany.Text == null || this.textBoxCompany.Text.Length == 0)
            {
                MessageBox.Show("Company cannot be empty");

                return false;
            }

            if (this.textBoxFactory.Text == null || this.textBoxFactory.Text.Length == 0)
            {
                MessageBox.Show("Factory cannot be empty");

                return false;
            }

            if (this.textBoxPlant.Text == null || this.textBoxPlant.Text.Length == 0)
            {
                MessageBox.Show("Plant cannot be empty");

                return false;
            }

            if (this.textBoxRemoteTagName.Text == null || this.textBoxRemoteTagName.Text.Length == 0)
            {
                MessageBox.Show("Remote Tagname cannot be empty");

                return false;
            }

            if (this.textBoxK.Text == null || this.textBoxK.Text.Length == 0 )
            {
                MessageBox.Show("K cannot be empty");

                return false;
            }

            double ldblK = 1.0;

            if (!double.TryParse(this.textBoxK.Text,out ldblK))
            {
                MessageBox.Show("K only can be number eg.1.2");

                return false;
            }


            double ldblB = 1.0;

            if (!double.TryParse(this.textBoxB.Text, out ldblB))
            {
                MessageBox.Show("B only can be number eg.2.0");

                return false;
            }

            if (this.textBoxRemoteTagName.Text == null || this.textBoxRemoteTagName.Text.Length == 0)
            {
                MessageBox.Show("Remote Tagname cannot be empty");

                return false;
            }

            double ldblThreshold = 1.0;

            if (!double.TryParse(this.textBoxThreshold.Text, out ldblThreshold))
            {
                MessageBox.Show("Threshold only can be number eg.2.0");

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

            if (this.checkBoxCheckTypeMore.Checked)
            {
                this.m_oItem.JudgeType = 0;
            }
            else
            {
                this.m_oItem.JudgeType = 1;
            }

            return true;
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.m_oItem = null;
            this.Close();           
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            if (this.CheckItem())
            {
                this.DialogResult = DialogResult.OK;
                this.Close();               
            }
        }

        private void SyncDataToUI()
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
        }

        private void FormItemSettings_Load(object sender, EventArgs e)
        {
            this.SyncDataToUI();
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void textBoxK_Validating(object sender, CancelEventArgs e)
        {
            this.NumberValidating(sender, e);
        }

        private void textBoxK_Validated(object sender, EventArgs e)
        {
            
        }

        private void NumberValidating(object sender, CancelEventArgs e)
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

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void checkBoxUsedAsJudge_CheckedChanged(object sender, EventArgs e)
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

        private void checkBoxCheckTypeMore_CheckedChanged(object sender, EventArgs e)
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

        private void checkBoxChecktypeLess_CheckedChanged(object sender, EventArgs e)
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

        private void textBoxTagName_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
