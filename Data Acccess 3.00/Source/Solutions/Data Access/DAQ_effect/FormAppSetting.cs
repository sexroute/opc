using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace DAQ
{
    public partial class FormAppSetting : Form
    {
        public FormAppSetting()
        {
            InitializeComponent();
        }

        String m_StrTitleName = "";
        public System.String TitleName
        {
            get { return m_StrTitleName; }
            set { m_StrTitleName = value; }
        }
        private void buttonOK_Click(object sender, EventArgs e)
        {
            this.TitleName = this.textBoxTitleName.Text;
            this.Close();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void AppSetting_Load(object sender, EventArgs e)
        {
            this.textBoxTitleName.Text = this.TitleName;
            this.CenterToParent();
        }
    }
}
