using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Data.Odbc;
using System.Diagnostics;


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
            //Source
            this.textBoxMachine.Text = this.ServerSetting.Machine;
            this.textBoxProgID.Text = this.ServerSetting.ProgID;           
            this.numericUpDownInterval.Value = this.ServerSetting.TimeInterval;
            this.textBoxServerIP.Text = this.ServerSetting.ServerIp;
            this.numericUpDownPort.Value = this.ServerSetting.ServerPort;
            this.textBoxUsername.Text = this.ServerSetting.OpcUserName;
            this.textBoxPassword.Text = this.ServerSetting.OpcPassword;
            
            this.comBoxServerType.Items.Clear();
            this.comBoxServerType.Items.AddRange(Enum.GetNames(typeof(DAQ.ServerSetting.SourceServerType)));

            if(this.ServerSetting.OpcAsyncRead)
            {
                this.checkBoxAsyncRead.Checked = true;
            }
            else
            {
                this.checkBoxAsyncRead.Checked = false;
            }

            for (int i = 0; i < this.comBoxServerType.Items.Count; i++)
            {
                if (i == (int)this.ServerSetting.TransferSource)
                {
                    this.comBoxServerType.SelectedIndex = i;
                    break;
                }
            }

            if (this.comBoxServerType.SelectedIndex == -1)
            {
                this.comBoxServerType.SelectedIndex = 0;
                
            }

            //bh server Type src

            this.comboBoxBHServerTypeSrc.Items.Clear();
            this.comboBoxBHServerTypeSrc.Items.AddRange(Enum.GetNames(typeof(DAQ.ServerSetting.BHServerType)));

            for (int i = 0; i < this.comboBoxBHServerTypeSrc.Items.Count; i++)
            {
                if (i == (int)this.ServerSetting.BHServerTpyeSrc)
                {
                    this.comboBoxBHServerTypeSrc.SelectedIndex = i;
                    break;
                }
            }

            if (this.comboBoxBHServerTypeSrc.SelectedIndex == -1)
            {
                this.comboBoxBHServerTypeSrc.SelectedIndex = (int)DAQ.ServerSetting.BHServerType.OLD;
                
            }

            //bh server Type dst

            this.comboBoxBHServerTypeDst.Items.Clear();
            this.comboBoxBHServerTypeDst.Items.AddRange(Enum.GetNames(typeof(DAQ.ServerSetting.BHServerType)));

            for (int i = 0; i < this.comboBoxBHServerTypeDst.Items.Count; i++)
            {
                if (i == (int)this.ServerSetting.BHServerTpyeDst)
                {
                    this.comboBoxBHServerTypeDst.SelectedIndex = i;
                    break;
                }
            }

            if (this.comboBoxBHServerTypeDst.SelectedIndex == -1)
            {
                this.comboBoxBHServerTypeDst.SelectedIndex = (int)DAQ.ServerSetting.BHServerType.OLD;

            }

            //fix select
            

            //dst
            this.textBoxUrlServiceUrl.Text = this.ServerSetting.RemoteUrl;
            this.textBoxMachineDst.Text = this.ServerSetting.DstMachine;
            this.textBoxProgIDDst.Text = this.ServerSetting.DstProgID;
            this.textBoxServerIPDst.Text = this.ServerSetting.DstServerIp;
            this.numericUpDownPortDst.Value = this.ServerSetting.DstServerPort;


            this.comBoxServerTypeDst.Items.Clear();
            this.comBoxServerTypeDst.Items.AddRange(Enum.GetNames(typeof(DAQ.ServerSetting.DestinationServerType)));

            for (int i = 0; i < this.comBoxServerTypeDst.Items.Count; i++)
            {
                if (this.comBoxServerTypeDst.Items[i].ToString() == this.ServerSetting.DstServerMode)
                {
                    this.comBoxServerTypeDst.SelectedIndex = i;
                    break;
                }
            }

            if (this.comBoxServerTypeDst.SelectedIndex == -1)
            {
                this.comBoxServerTypeDst.SelectedIndex = 0;
            }

            //fix select
         //   this.comBoxServerTypeDst.SelectedIndex = 1;
          //  this.comBoxServerTypeDst.Enabled = false;
                     
        }

        public void SyncUItoData()
        {
            //source
            this.ServerSetting.Machine = this.textBoxMachine.Text ;
            this.ServerSetting.ProgID = this.textBoxProgID.Text;
            this.ServerSetting.TimeInterval = (int)this.numericUpDownInterval.Value;
            this.ServerSetting.ServerIp = this.textBoxServerIP.Text;
            this.ServerSetting.ServerPort = (int)this.numericUpDownPort.Value;

            ServerSetting.SourceServerType lnSelectedSource = (ServerSetting.SourceServerType)(this.comBoxServerType.SelectedIndex);
            this.ServerSetting.TransferSource = lnSelectedSource;

            ServerSetting.BHServerType lnSelectedBHServerTypeSource = (ServerSetting.BHServerType)(this.comboBoxBHServerTypeSrc.SelectedIndex);
            this.ServerSetting.BHServerTpyeSrc = lnSelectedBHServerTypeSource;
            
            
            //destination
            this.ServerSetting.DstServerMode = this.comBoxServerTypeDst.Items[this.comBoxServerTypeDst.SelectedIndex].ToString();
            this.ServerSetting.DstMachine = this.textBoxMachineDst.Text;
            this.ServerSetting.DstProgID = this.textBoxProgIDDst.Text;
            this.ServerSetting.RemoteUrl = this.textBoxUrlServiceUrl.Text;
            this.ServerSetting.DstServerIp = this.textBoxServerIPDst.Text;
            this.ServerSetting.DstServerPort = (int)this.numericUpDownPortDst.Value;

            ServerSetting.BHServerType lnSelectedBHServerTypeDst = (ServerSetting.BHServerType)(this.comboBoxBHServerTypeDst.SelectedIndex);
            this.ServerSetting.BHServerTpyeDst = lnSelectedBHServerTypeDst;

            this.ServerSetting.OpcPassword = this.textBoxPassword.Text.Trim();
            this.ServerSetting.OpcUserName = this.textBoxUsername.Text.Trim();

        }

        ServerSetting m_oServerSetting = new ServerSetting();

        public DAQ.ServerSetting ServerSetting
        {
            get { return m_oServerSetting; }
            set { m_oServerSetting = value; }
        }



        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void FormServerSetting_Load(object sender, EventArgs e)
        {
            this.InitUI();
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
        private Boolean TestFixCom(Boolean abDst)
        {
            bool lbSucceed = false;

            try
            {
               

                int lnServerType = (int)DAQ.ServerSetting.BHServerType.OLD;

                if (abDst)
                {
                    lnServerType = this.comboBoxBHServerTypeDst.SelectedIndex;
                }
                else
                {
                    lnServerType = this.comboBoxBHServerTypeSrc.SelectedIndex;
                }

                String lstrMiddleWareIP = this.textBoxServerIP.Text;
                String lstrMiddleWarePort = this.numericUpDownPort.Value + "";

                if(abDst)
                {
                    lstrMiddleWareIP = this.textBoxServerIPDst.Text;
                    lstrMiddleWarePort = this.numericUpDownPortDst.Value + "";
                }

                if (lnServerType == (int)DAQ.ServerSetting.BHServerType.OLD)
                {
                    CBHFixComLib.ICBHFixComImp loFixComm = null;

                    loFixComm =  new CBHFixComLib.CBHFixComImp();

                    loFixComm.SetCommType(lnServerType);


                    String lstrConnstr = string.Format("{0},{1}/TCP",
                                            this.textBoxServerIP.Text,
                                            this.numericUpDownPort.Value + "");



                    if (abDst)
                    {
                        lstrConnstr = string.Format("{0},{1}/TCP",
                                            this.textBoxServerIPDst.Text,
                                            this.numericUpDownPortDst.Value + "");
                    }

                    String lstrDept = "";

                    if (loFixComm.Link(ref lstrConnstr, ref lstrDept) > 0)
                    {
                        lbSucceed = true;
                    }
                }
                else
                {
                  
                    using (Dse.FixComm loFixCommx = Dse.FixComm.New(lstrMiddleWareIP, "" + lstrMiddleWarePort))
                    {
                        lbSucceed = true;
                    }
                }

              
            }
            catch (System.Exception ex)
            {
                MessageBox.Show("Error:"+ex.Message);
                lbSucceed = false;
            }

            return lbSucceed;
        }
 

        private void comBoxServerType_SelectedIndexChanged(object sender, EventArgs e)
        {
            ServerSetting.SourceServerType lnSelectedSource = (ServerSetting.SourceServerType)(this.comBoxServerType.SelectedIndex );
            switch (lnSelectedSource)
            {
                case ServerSetting.SourceServerType.BH_SERVER:
                    this.textBoxMachine.Enabled = false;
                    this.textBoxProgID.Enabled = false;
                    this.textBoxPassword.Enabled = false;
                    this.textBoxUsername.Enabled = false;                  
                    this.textBoxServerIP.Enabled = true;
                    this.numericUpDownPort.Enabled = true;
                    
                    this.buttonBHTest.Enabled = true;
                    this.btnAspen.Enabled = false;
                    this.buttonOpcTest.Enabled = false;
                    this.comboBoxBHServerTypeSrc.Enabled = true;
                    break;
                case ServerSetting.SourceServerType.OPC_SERVER:
                    this.textBoxMachine.Enabled = true;
                    this.textBoxProgID.Enabled = true;
                    this.textBoxServerIP.Enabled = false;
                    this.numericUpDownPort.Enabled = false;
                    this.comboBoxBHServerTypeSrc.Enabled = false;
                    this.textBoxPassword.Enabled = true;
                    this.textBoxUsername.Enabled = true;

                    this.buttonBHTest.Enabled = false;
                    this.btnAspen.Enabled = false;
                    this.buttonOpcTest.Enabled = true;
                    break;
                case ServerSetting.SourceServerType.ASPEN_SERVER:
                    this.textBoxMachine.Enabled = false;
                    this.textBoxProgID.Enabled = true;
                    this.textBoxServerIP.Enabled = false;
                    this.numericUpDownPort.Enabled = false;
                    this.comboBoxBHServerTypeSrc.Enabled = false;

                    this.buttonBHTest.Enabled = false;
                    this.btnAspen.Enabled = true;
                    this.buttonOpcTest.Enabled = false;
                    break;
                default:
                    Debug.Assert(false);
                    this.textBoxMachine.Enabled = false;
                    this.textBoxProgID.Enabled = false;
                    this.textBoxServerIP.Enabled = true;
                    this.numericUpDownPort.Enabled = true;
                    this.comboBoxBHServerTypeSrc.Enabled = false;

                    this.buttonBHTest.Enabled = true;
                    this.btnAspen.Enabled = false;
                    this.buttonOpcTest.Enabled = false;
                    break;
            }
        }


        private void buttonBHTest_Click(object sender, EventArgs e)
        {
            bool lbSucceed = false;

            if (this.comBoxServerType.SelectedIndex == (int)DAQ.ServerSetting.SourceServerType.BH_SERVER)
            {
                lbSucceed = this.TestFixCom(false);
            }
            else
            {
                lbSucceed = this.TestWebService();
            }

            if (lbSucceed)
            {
                MessageBox.Show(this, "成功(Succeed)");
            }
            else
            {
                MessageBox.Show(this, "链接失败(Connection failed)");
            }
        }

        private void buttonCancel_Click_1(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnAspen_Click_1(object sender, EventArgs e)
        {
            AspenTest loAspen = new AspenTest();
            loAspen.IP = this.textBoxMachine.Text;
            loAspen.ShowDialog(this);
        }

        private void buttonOpcTest_Click_1(object sender, EventArgs e)
        {
            FormServerTest loTest = new FormServerTest();

            loTest.Text = "Source Opc Server Test";

            loTest.textBoxProID.Text = this.textBoxProgID.Text;

            loTest.textBoxServerIP.Text = this.textBoxMachine.Text;

            loTest.OpcUserName = this.textBoxUsername.Text;

            loTest.OpcPassword = this.textBoxPassword.Text;

            loTest.OpcAsyncRead = this.checkBoxAsyncRead.Checked;

            loTest.ShowDialog(this);
        }

        private void buttonOK_Click_1(object sender, EventArgs e)
        {
            this.SyncUItoData();
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void comBoxServerTypeDst_SelectedIndexChanged(object sender, EventArgs e)
        {
            ServerSetting.DestinationServerType lnSelectedSource = (ServerSetting.DestinationServerType)(this.comBoxServerTypeDst.SelectedIndex);
            switch (lnSelectedSource)
            {
                case ServerSetting.DestinationServerType.BHServer:
                    this.textBoxMachineDst.Enabled = false;
                    this.textBoxProgIDDst.Enabled = false;
                    this.textBoxServerIPDst.Enabled = true;
                    this.numericUpDownPortDst.Enabled = true;
                    this.textBoxUrlServiceUrl.Enabled = false;
                    this.comboBoxBHServerTypeDst.Enabled = true;
                    this.btnBHDst.Enabled = true;
                    this.btnOpcDst.Enabled = false;
                    break;
                case ServerSetting.DestinationServerType.OPC_SERVER:
                    this.textBoxMachineDst.Enabled = true;
                    this.textBoxProgIDDst.Enabled = true;
                    this.textBoxServerIPDst.Enabled = false;
                    this.numericUpDownPortDst.Enabled = false;
                    this.textBoxUrlServiceUrl.Enabled = false;
                    this.comboBoxBHServerTypeDst.Enabled = false;
                    this.btnBHDst.Enabled = false;
                    this.btnOpcDst.Enabled = true;
                    break;
                case ServerSetting.DestinationServerType.WebService:
                    this.textBoxMachineDst.Enabled = false;
                    this.textBoxProgIDDst.Enabled = true;
                    this.textBoxServerIPDst.Enabled = false;
                    this.numericUpDownPortDst.Enabled = false;
                    this.textBoxUrlServiceUrl.Enabled = true;
                    this.comboBoxBHServerTypeDst.Enabled = false;
                    this.btnBHDst.Enabled = false;
                    this.btnOpcDst.Enabled = false;
                    break;
                default:
                    Debug.Assert(false);
                    this.textBoxMachineDst.Enabled = false;
                    this.textBoxProgIDDst.Enabled = false;
                    this.textBoxServerIPDst.Enabled = true;
                    this.numericUpDownPortDst.Enabled = true;
                    this.textBoxUrlServiceUrl.Enabled = false;
                    this.comboBoxBHServerTypeDst.Enabled = false;
                    this.btnBHDst.Enabled = true;
                    this.btnOpcDst.Enabled = false;
                    break;
            }
        }

        private void btnBHDst_Click(object sender, EventArgs e)
        {
            bool lbSucceed = false;

            if (this.comBoxServerTypeDst.SelectedIndex == (int)DAQ.ServerSetting.DestinationServerType.BHServer)
            {
                lbSucceed = this.TestFixCom(true);
            }
            else
            {
                lbSucceed = this.TestWebService();
            }

            if (lbSucceed)
            {
                MessageBox.Show(this, "成功(Succeed)");
            }
            else
            {
                MessageBox.Show(this, "连接失败(Connection failed)");
            }
        }

        private void btnOpcDst_Click(object sender, EventArgs e)
        {
            FormServerTest loTest = new FormServerTest();

            loTest.Text = "Destination Opc Server Test";

            loTest.textBoxProID.Text = this.textBoxProgID.Text;

            loTest.textBoxServerIP.Text = this.textBoxMachine.Text;

            loTest.ShowDialog(this);
        }

        private void SourceSetting_Enter(object sender, EventArgs e)
        {

        }

        private void checkBoxAsyncRead_CheckedChanged(object sender, EventArgs e)
        {
            this.m_oServerSetting.OpcAsyncRead = this.checkBoxAsyncRead.Checked;
        }
    }
}
