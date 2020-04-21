using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using EricZhao.UiThread;

namespace DAQ
{
    public partial class FormError : Form
    {
        public FormError()
        {
            InitializeComponent();
        }

        private void listView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (null==this.m_oFormParent)
            {
                return;
            }
            ListViewItem lpItem = listView1.GetItemAt(e.X, e.Y);
            if (null!= lpItem)
            {
                System.CodeDom.Compiler.CompilerError lpError = (System.CodeDom.Compiler.CompilerError)lpItem.Tag;
                this.m_oFormParent.Show();
                this.m_oFormParent.BringToFront();
                this.m_oFormParent.HighLightErrorLine(lpError);
              
            }
        }
        public FunctionItemSetting m_oFormParent = null;
        private void FormError_Load(object sender, EventArgs e)
        {
            this.CenterToParent();
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void FormError_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.Hide();
            e.Cancel = true;
        }
    }
}
