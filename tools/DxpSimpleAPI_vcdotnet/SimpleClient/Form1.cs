using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;

using System.Text;
using System.Windows.Forms;

using OpcRcw.Da;

namespace SimpleClient
{
	public partial class Form1 : Form
	{
		// OPCサーバーアクセスインスタンス
		DxpSimpleAPI.DxpSimpleClass opc = new DxpSimpleAPI.DxpSimpleClass();
		string[] sItemIDArray = new string[5];

		public Form1()
		{
			InitializeComponent();
		}

		// ロード時サーバーリストを更新する
		private void Form1_Load(object sender, EventArgs e)
		{
			//btnListRefresh_Click(sender, e);
			btnRead.Enabled = false;
			btnWrite.Enabled = false;
			btnConnect.Enabled = true;
			btnDisconnect.Enabled = false;
		}

		// 接続
		private void btnConnect_Click(object sender, EventArgs e)
		{
			if (opc.Connect(txtNode.Text, cmbServerList.Text))
			{
				btnRead.Enabled = true;
				btnWrite.Enabled = true;
				btnListRefresh.Enabled = false;
				btnDisconnect.Enabled = true;
				btnConnect.Enabled = false;

				sItemIDArray[0] = txtTag1.Text;
				sItemIDArray[1] = txtTag2.Text;
				sItemIDArray[2] = txtTag3.Text;
				sItemIDArray[3] = txtTag4.Text;
				sItemIDArray[4] = txtTag5.Text;
				txtTag1.ReadOnly = true;
				txtTag2.ReadOnly = true;
				txtTag3.ReadOnly = true;
				txtTag4.ReadOnly = true;
				txtTag5.ReadOnly = true;
			}
		}

		// 接続解除
		private void btnDisconnect_Click(object sender, EventArgs e)
		{
			if (opc.Disconnect())
			{
				btnRead.Enabled = false;
				btnWrite.Enabled = false;
				btnConnect.Enabled = true;
				btnListRefresh.Enabled = true;
				btnDisconnect.Enabled = false;

				txtTag1.ReadOnly = false;
				txtTag2.ReadOnly = false;
				txtTag3.ReadOnly = false;
				txtTag4.ReadOnly = false;
				txtTag5.ReadOnly = false;
			}
		}

		private string ReadValCopy(object oVal, int n, int nError)
		{
			if (nError != 0)
				return "Read Error";
			
			if (oVal is Array)
			{
				String sBufGet = "";
				Array ary = (Array)oVal;
				for (int j = 0; j < ary.Length; j++)
				{
					sBufGet = sBufGet + ary.GetValue(j) + ",";	//05/03/10 Change value to string
				}
				return sBufGet;
			}
			else
			{
				return oVal.ToString();
			}
		}

		object[] oValue = new object[5];
		private void btnRead_Click(object sender, EventArgs e)
		{
			try
			{
				object[] oValueArray;
				short[] wQualityArray;
				OpcRcw.Da.FILETIME[] fTimeArray;
				int[] nErrorArray;

				if (opc.Read(sItemIDArray, out oValueArray, out wQualityArray, out fTimeArray, out nErrorArray) == true)
				{
					txtVal1.Text = ReadValCopy(oValueArray[0], 0, nErrorArray[0]);
					txtVal2.Text = ReadValCopy(oValueArray[1], 1, nErrorArray[1]);
					txtVal3.Text = ReadValCopy(oValueArray[2], 2, nErrorArray[2]);
					txtVal4.Text = ReadValCopy(oValueArray[3], 3, nErrorArray[3]);
					txtVal5.Text = ReadValCopy(oValueArray[4], 4, nErrorArray[4]);
					oValue = oValueArray;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.ToString());
			}
		}

		private object WriteValCopy(string sText, int n)
		{
			if (oValue[n] is Array)
			{
				string[] sBufPut = sText.Split(',');
				Array ary = (Array)oValue[n];
				object[] oAry = new object[ary.Length];
				for (int j = 0; j < ary.Length; j++)
				{
					if (j >= sBufPut.Length)
						break;
					try
					{
						if (oValue[n] is UInt16)
						{
							oAry[j] = UInt16.Parse(sBufPut[j]);
						}
						else if (oValue[n] is UInt32)
						{
							oAry[j] = UInt32.Parse(sBufPut[j]);
						}
						else
						{
							oAry[j] = (object)sBufPut[j];
						}
					}
					catch
					{
						MessageBox.Show("Error");
					}
				}
				return  oAry;
			}
			else
			{
				return sText;
			}
		}

		private void btnWrite_Click(object sender, EventArgs e)
		{
			try
			{
				int[] nErrorArray;

				oValue[0] = WriteValCopy(txtVal1.Text, 0);
				oValue[1] = WriteValCopy(txtVal2.Text, 1);
				oValue[2] = WriteValCopy(txtVal3.Text, 2);
				oValue[3] = WriteValCopy(txtVal4.Text, 3);
				oValue[4] = WriteValCopy(txtVal5.Text, 4);

				opc.Write(sItemIDArray, oValue, out nErrorArray);
				if (nErrorArray[0] != 0) txtVal1.Text = "Write Error";
				if (nErrorArray[1] != 0) txtVal2.Text = "Write Error";
				if (nErrorArray[2] != 0) txtVal3.Text = "Write Error";
				if (nErrorArray[3] != 0) txtVal4.Text = "Write Error";
				if (nErrorArray[4] != 0) txtVal5.Text = "Write Error";
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.ToString());
			}
		}

		// ノードに対するサーバーリストのリフレッシュ
		private void btnListRefresh_Click(object sender, EventArgs e)
		{
			cmbServerList.Items.Clear();
			string[] ServerNameArray;
			opc.EnumServerList(txtNode.Text, out ServerNameArray);

			for (int a = 0; a < ServerNameArray.Length; a++)
			{
				cmbServerList.Items.Add(ServerNameArray[a]);
			}
			cmbServerList.SelectedIndex = 0;
		}
	}
}
