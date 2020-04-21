using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Reflection;
using System.Text;
using System.Windows.Forms;

namespace DAQ
{
    public partial class FormAbout : Form
    {
        public FormAbout()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void FormAbout_Load(object sender, EventArgs e)
        {
            this.CenterToParent();
            var versionInfo = FileVersionInfo.GetVersionInfo(Assembly.GetEntryAssembly().Location);
                this.labelCopyright.Text = versionInfo.LegalCopyright;
                this.labelVersion.Text = versionInfo.ProductVersion;
            this.labelAuthor.Text = versionInfo.CompanyName;
           


        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
