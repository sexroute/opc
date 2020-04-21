using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;

using System.Text;
using System.Windows.Forms;
using Opc;
using OpcCom;
using Opc.Da;
using System.Diagnostics;
using EricZhao.UiThread;

namespace DAQ
{
    public partial class FormServerTest : Form
    {
        private String m_StrOpcUserName="";
        public System.String OpcUserName
        {
            get { return m_StrOpcUserName; }
            set { m_StrOpcUserName = value; }
        }
        private String m_StrOpcPassword="";
        public System.String OpcPassword
        {
            get { return m_StrOpcPassword; }
            set { m_StrOpcPassword = value; }
        }

        private Boolean m_bOpcAsyncRead = false;
        public System.Boolean OpcAsyncRead
        {
            get { return m_bOpcAsyncRead; }
            set { m_bOpcAsyncRead = value; }
        }
        public FormServerTest()
        {
            InitializeComponent();

            this.CenterToParent();
        }

        Opc.Da.Subscription m_oSubscription = null;
        public Opc.Da.Subscription Subscription
        {
            get { return m_oSubscription; }
            set { m_oSubscription = value; }
        }
        private void OnDataChange(object subscriptionHandle, object requestHandle, ItemValueResult[] values)
        {
            if(this.Subscription==null)
            {
                return;
            }          

            foreach (ItemValueResult value in values)
            {

                String lstrData = String.Format("异步读：ITEM:{0},value:{1},quality:{2},info:{3}", value.ItemName, value.Value, value.Quality, value.DiagnosticInfo);
                ThreadUiController.SetControlText(this.textBoxResult, lstrData);
                Console.WriteLine(lstrData);
            }
        }
        private void DoTest()
        {
            Opc.IDiscovery m_discovery = new OpcCom.ServerEnumerator();

            Opc.Server[] servers = null;

            Opc.Server[] servers2 = null;

            Opc.Server[] servers3 = null;

            Opc.ConnectData mConnectData = null;

            if((!String.IsNullOrEmpty(this.OpcUserName))&& (!String.IsNullOrEmpty(this.OpcPassword)))
            {
                System.Net.NetworkCredential mCredentials = new System.Net.NetworkCredential();
                mCredentials.UserName = this.OpcUserName;
                mCredentials.Password = this.OpcPassword;
                mConnectData = new Opc.ConnectData(mCredentials);
            }

            try
            {
               
                
                servers = m_discovery.GetAvailableServers(
                                                           Specification.COM_DA_10,
                                                           this.textBoxServerIP.Text,
                                                           mConnectData);
     
            }
            catch (Exception e)
            {

                MessageBox.Show(e.Message);
            }

            if (true)
            {
                try
                {

                    servers2 = m_discovery.GetAvailableServers(
                                                               Specification.COM_DA_20,
                                                              this.textBoxServerIP.Text,
                                                               mConnectData);
 
                }
                catch (Exception e)
                {

                    MessageBox.Show(e.Message);
                }
            }

            if (true)
            {
                try
                {

                    servers3 = m_discovery.GetAvailableServers(
                                                               Specification.COM_DA_30,
                                                              this.textBoxServerIP.Text,
                                                               mConnectData);

                }
                catch (Exception e)
                {

                    MessageBox.Show(e.Message);
                }
            }

            Opc.Da.Server lpTargetServer = null;

            Dictionary<Opc.Server, String> loServers = new Dictionary<Opc.Server, String>();

            if (servers!=null)
            {
                foreach (Opc.Da.Server server in servers)
                {
                    loServers.Add(server, "COM_DA_10");
                }
            }

            if(servers2!=null)
            {
                foreach (Opc.Da.Server server in servers2)
                {
                    loServers.Add(server, "COM_DA_20");
                }               
            }

            if (servers3 != null)
            {
                foreach (Opc.Da.Server server in servers3)
                {
                    loServers.Add(server, "COM_DA_30");
                }
            }

            foreach (Opc.Da.Server server in loServers.Keys)
            {
                String lstrType = loServers[server];
                if (server.Name.CompareTo(this.textBoxProID.Text) == 0)
                {
                    lpTargetServer = server;
                    this.richTextBox1.Text += "Server Name:"+server.Name + " Matched, Server type:" + lstrType + "\r\n";
                }
                else
                    if (server.Name.CompareTo(this.textBoxServerIP.Text + "." + this.textBoxProID.Text) == 0)
                    {
                        lpTargetServer = server;

                        this.richTextBox1.Text += "Server Name:" + server.Name + " Matched, Server type:" + lstrType + "\r\n";
                }
                    else
                    {

                        this.richTextBox1.Text += "Server Name:" + server.Name + ", Server type:" + lstrType + "\r\n";
                }


            }

            foreach (Opc.Da.Server server in loServers.Keys)
            {

                if (server.Name.CompareTo(this.textBoxProID.Text) == 0)
                {
                    lpTargetServer = server;

                    break;
                }

                if (server.Name.CompareTo(this.textBoxServerIP.Text + "." + this.textBoxProID.Text) == 0)
                {
                    lpTargetServer = server;

                    break;
                }

            }

            if (lpTargetServer == null)
            {
                MessageBox.Show("没有找到匹配的服务器(no matched server found, server founded listed)");

                return;
            }

            try
            {
                lpTargetServer.Connect(mConnectData);
            }
            catch (System.Exception ex)
            {
                MessageBox.Show("服务器连接失败(opc server connection failed)\r\n"+ex.Message);
            }

            string[] itemName = { this.textBoxItemID.Text };

            Item[] items = new Item[itemName.Length];//定义数据项，即item

            for (int i = 0; i < items.Length; i++)//item初始化赋值
            {
                items[i] = new Item();//创建一个项Item对象。
                items[i].ClientHandle = Guid.NewGuid().ToString();//客户端给该数据项分配的句柄。
                items[i].ItemPath = null; //该数据项在服务器中的路径。
                items[i].ItemName = itemName[i]; //该数据项在服务器中的名字。
                items[i].Active = true;
                items[i].SamplingRate = 1000;

            }


            Opc.Da.SubscriptionState state = new Opc.Da.SubscriptionState();//组（订阅者）状态，相当于OPC规范中组的参数
            state.Name =  "test";//组名
            state.ServerHandle = null;//服务器给该组分配的句柄。
            state.ClientHandle = Guid.NewGuid().ToString();//客户端给该组分配的句柄。
            state.Active = true;//激活该组。
            state.UpdateRate = 1000;//刷新频率为1秒。
            state.Deadband = 0;// 死区值，设为0时，服务器端该组内任何数据变化都通知组。
            state.Locale = null;//不设置地区值。
           

            //添加组
            Opc.Da.Subscription subscription = (Opc.Da.Subscription)lpTargetServer.CreateSubscription(state);//创建组

            //添加Item
            subscription.AddItems(items);

            if(this.OpcAsyncRead)
            {
                subscription.DataChanged += new Opc.Da.DataChangedEventHandler(OnDataChange);
                this.Subscription = subscription;
            }
            else
            {
                ItemValueResult[] values = subscription.Read(subscription.Items);

                foreach (ItemValueResult value in values)
                {

                    String lstrData = String.Format("同步读：ITEM:{0},value:{1},quality:{2},info:{3}", value.ItemName, value.Value, value.Quality, value.DiagnosticInfo);
                    this.textBoxResult.Text = lstrData;
                    Console.WriteLine(lstrData);
                }
            }

        }
        private void button1_Click(object sender, EventArgs e)
        {

            try
            {
                this.DoTest();
            }
            catch (System.Exception ex)
            {
                MessageBox.Show("无法连接远程服务器Failed to connect server, reason : \r\n" + ex.ToString());
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("not supported yet");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void FormServerTest_Load(object sender, EventArgs e)
        {

        }

        private void FormServerTest_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                if(this.Subscription!=null)
                {
                    this.Subscription.Dispose();
                    this.Subscription = null;
                }
            }catch(Exception e2)
            {

            }

        }
    }
}
