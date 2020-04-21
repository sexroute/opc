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
namespace DAQ
{
    public partial class FormServerTest : Form
    {
        public FormServerTest()
        {
            InitializeComponent();

            this.CenterToParent();
        }
        private void DoTest()
        {
            Opc.IDiscovery m_discovery = new OpcCom.ServerEnumerator();

            Opc.Server[] servers = m_discovery.GetAvailableServers(Specification.COM_DA_20, this.textBoxServerIP.Text, null);

            Opc.Da.Server lpTargetServer = null;

            foreach (Opc.Da.Server server in servers)
            {

                if (server.Name.CompareTo(this.textBoxProID.Text) == 0)
                {
                    lpTargetServer = server;
                    this.richTextBox1.Text += server.Name + " Matched\r\n";
                }
                else 
                if (server.Name.CompareTo(this.textBoxServerIP.Text+"."+this.textBoxProID.Text) == 0)
                {
                    lpTargetServer = server;

                    this.richTextBox1.Text += server.Name + " Matched\r\n";
                }
                else
                {

                    this.richTextBox1.Text += server.Name + "\r\n";
                }


            }

            foreach (Opc.Da.Server server in servers)
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
                MessageBox.Show("no matched server found, server founded listed");

                return;
            }

            try
            {
                lpTargetServer.Connect();
            }
            catch (System.Exception ex)
            {

            }

            string[] itemName = {this.textBoxItemID.Text };

            Item[] items = new Item[itemName.Length];//定义数据项，即item

            for (int i = 0; i < items.Length; i++)//item初始化赋值
            {
                items[i] = new Item();//创建一个项Item对象。
                items[i].ClientHandle = Guid.NewGuid().ToString();//客户端给该数据项分配的句柄。
                items[i].ItemPath = null; //该数据项在服务器中的路径。
                items[i].ItemName = itemName[i]; //该数据项在服务器中的名字。
            }


            Opc.Da.SubscriptionState state = new Opc.Da.SubscriptionState();//组（订阅者）状态，相当于OPC规范中组的参数
            state.Name = "test";//组名
            state.ServerHandle = null;//服务器给该组分配的句柄。
            state.ClientHandle = Guid.NewGuid().ToString();//客户端给该组分配的句柄。
            state.Active = true;//激活该组。
            state.UpdateRate = 100;//刷新频率为1秒。
            state.Deadband = 0;// 死区值，设为0时，服务器端该组内任何数据变化都通知组。
            state.Locale = null;//不设置地区值。
            //添加组
            Opc.Da.Subscription subscription = (Opc.Da.Subscription)lpTargetServer.CreateSubscription(state);//创建组

            //添加Item
            subscription.AddItems(items);

            ItemValueResult[] values = subscription.Read(subscription.Items);

            foreach (ItemValueResult value in values)
            {
                String lstrData = String.Format("同步读：ITEM:{0},value:{1},quality:{2}", value.ItemName, value.Value, value.Quality);
                this.textBoxResult.Text = lstrData;
                Console.WriteLine(lstrData);
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
                MessageBox.Show("Failed to connect server, reason : \r\n" + ex.ToString());
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
    }
}
