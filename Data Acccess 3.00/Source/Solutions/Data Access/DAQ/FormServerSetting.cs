using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Data.Odbc;


namespace DAQ
{
    public partial class FormServerSetting : Form
    {
        public FormServerSetting()
        {
            InitializeComponent();

            this.CenterToParent();
        }

        public void InitUI()
        {
            this.textBoxMachine.Text = this.ServerSetting.Machine;
            this.textBoxProgID.Text = this.ServerSetting.ProgID;
            this.textBoxUrlServiceUrl.Text = this.ServerSetting.RemoteUrl;
            this.numericUpDownInterval.Value = this.ServerSetting.TimeInterval;
            this.textBoxServerIP.Text = this.ServerSetting.ServerIp;
            this.numericUpDownPort.Value = this.ServerSetting.ServerPort;


            this.comboBoxServerMode.Items.Clear();
            this.comboBoxServerMode.Items.AddRange(Enum.GetNames(typeof(DAQ.ServerSetting.ServerType)));

            for (int i = 0; i < this.comboBoxServerMode.Items.Count;i++ )
            {
                if (this.comboBoxServerMode.Items[i].ToString() == this.ServerSetting.ServerMode)
                {
                    this.comboBoxServerMode.SelectedIndex = i;
                    break;
                }
            }

            if (this.comboBoxServerMode.SelectedIndex == -1)
            {
                this.comboBoxServerMode.SelectedIndex = 0;
                
            }
           this.comboBoxServerMode.Enabled = false;
            switch (this.ServerSetting.TransferSource)
            {
                case ServerSetting.ETransferSource.BH_SERVER:
                    this.comboBoxServerMode.SelectedIndex = (int)DAQ.ServerSetting.ServerType.BHServer;
                    this.comboBoxServerMode.Enabled = false;
                    break;
                case ServerSetting.ETransferSource.OPC_SERVER:
                    this.comboBoxServerMode.Enabled = true;
                    break;
                case ServerSetting.ETransferSource.ASPEN_SERVER:
                    this.comboBoxServerMode.Enabled = true;
                    break;
                default:
                    this.comboBoxServerMode.Enabled = true;
                    break;
            }

            this.comBoxServerType.SelectedIndex =(int)( this.ServerSetting.TransferSource);
 
            this.ToggleTextStatus();            
        }

        public void SyncUItoData()
        {
            this.ServerSetting.Machine = this.textBoxMachine.Text ;
            this.ServerSetting.ProgID = this.textBoxProgID.Text;
            this.ServerSetting.RemoteUrl = this.textBoxUrlServiceUrl.Text ;
            this.ServerSetting.TimeInterval = (int)this.numericUpDownInterval.Value;
            this.ServerSetting.ServerIp = this.textBoxServerIP.Text;
            this.ServerSetting.ServerMode = this.comboBoxServerMode.Items[this.comboBoxServerMode.SelectedIndex].ToString();
            this.ServerSetting.ServerPort = (int)this.numericUpDownPort.Value;
            ServerSetting.ETransferSource lnSelectedSource = (ServerSetting.ETransferSource)(this.comBoxServerType.SelectedIndex );
            this.ServerSetting.TransferSource = lnSelectedSource;

        }

        ServerSetting m_oServerSetting = new ServerSetting();

        public DAQ.ServerSetting ServerSetting
        {
            get { return m_oServerSetting; }
            set { m_oServerSetting = value; }
        }


        private void buttonOK_Click(object sender, EventArgs e)
        {
            this.SyncUItoData();
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonTest_Click(object sender, EventArgs e)
        {
            FormServerTest loTest = new FormServerTest();

            loTest.textBoxProID.Text = this.textBoxProgID.Text;

            loTest.textBoxServerIP.Text = this.textBoxMachine.Text;   

            loTest.ShowDialog(this);

           
        }

        private void FormServerSetting_Load(object sender, EventArgs e)
        {
            this.InitUI();
        }

        private void ToggleTextStatus()
        {
            if (this.comboBoxServerMode.SelectedItem.ToString()
            == Enum.GetName(typeof(DAQ.ServerSetting.ServerType), DAQ.ServerSetting.ServerType.WebService))
            {
                this.textBoxServerIP.Enabled = false;
                this.numericUpDownPort.Enabled = false;
                this.textBoxUrlServiceUrl.Enabled = true;
            }
            else
            {
                this.textBoxServerIP.Enabled = true;
                this.numericUpDownPort.Enabled = true;
                this.textBoxUrlServiceUrl.Enabled = false;

            }
        }
        private void comboBoxServerMode_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.ToggleTextStatus();
        }


        private Boolean TestWebService()
        {
            bool lbSucceed = false;

            try
            {
                WebClient client = new WebClient();
                string postString = String.Format("param={0}", "");
                byte[] postData = Encoding.UTF8.GetBytes(postString);
                client.Headers.Add("Content-Type", "application/x-www-form-urlencoded");
                byte[] responseData = client.UploadData(this.textBoxUrlServiceUrl.Text, "POST", postData);
                lbSucceed = true;
            }
            catch (System.Exception ex)
            {
                lbSucceed = false;
            }

            return lbSucceed;
        }
        private Boolean TestFixCom()
        {
            bool lbSucceed = false;

            try
            {
                CBHFixComLib.ICBHFixComImp loFixComm = new CBHFixComLib.CBHFixComImp();

                loFixComm.SetCommType(1);

                String lstrConnstr = string.Format("{0},{1}/TCP",
                                        this.textBoxServerIP.Text,
                                        this.numericUpDownPort.Value + "");
                String lstrDept = "";

                if (loFixComm.Link(ref lstrConnstr, ref lstrDept) > 0)
                {
                    lbSucceed = true;
                }
            }
            catch (System.Exception ex)
            {
                lbSucceed = false;
            }

            return lbSucceed;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            bool lbSucceed = false;

            if (this.comboBoxServerMode.SelectedIndex == (int)DAQ.ServerSetting.ServerType.BHServer )
            {
                lbSucceed = this.TestFixCom();
            }
            else
            {
                lbSucceed = this.TestWebService();
            }

            if (lbSucceed)
            {
                MessageBox.Show(this, "Succeed");
            }
            else
            {
                MessageBox.Show(this, "Connection failed");
            }

        }

        private void comBoxServerType_SelectedIndexChanged(object sender, EventArgs e)
        {
            ServerSetting.ETransferSource lnSelectedSource = (ServerSetting.ETransferSource)(this.comBoxServerType.SelectedIndex );
            switch (lnSelectedSource)
            {
                case ServerSetting.ETransferSource.BH_SERVER:
                    this.comboBoxServerMode.SelectedIndex = (int)DAQ.ServerSetting.ServerType.BHServer;
                    this.comboBoxServerMode.Enabled = false;
                    this.textBoxProgID.Enabled = true;
                    break;
                case ServerSetting.ETransferSource.OPC_SERVER:
                    this.comboBoxServerMode.Enabled = true;
                    this.textBoxProgID.Enabled = true;
                    break;
                case ServerSetting.ETransferSource.ASPEN_SERVER:
                    this.comboBoxServerMode.Enabled = true;
                    this.textBoxProgID.Enabled = false;
                    break;
                default:
                    this.comboBoxServerMode.Enabled = true;
                    break;
            }
        }

        private void btnAspen_Click(object sender, EventArgs e)
        {
            AspenTest loAspen = new AspenTest();
            loAspen.IP = this.textBoxMachine.Text;
            loAspen.ShowDialog(this);
        }
    }
}
