using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using EricZhao;
namespace DAQ
{
    static class Program
    {
      
       
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        //[MTAThread]
        static void Main()
        {
            int lnRet = ComComponent.CoInitializeEx((IntPtr)null, ComComponent.COINIT.COINIT_MULTITHREADED);
            String lstrUserName = "";
            String lstrPassword = "";

            loadOpcUserNamePassword(ref lstrUserName, ref lstrPassword);
            if(!(String.IsNullOrEmpty(lstrUserName))&&!(String.IsNullOrEmpty(lstrPassword)))
            {
                ComComponent.login(lstrUserName, lstrPassword, "");
            }
            Boolean lbRet =  MiniDump.IsAlreadyInstanceStart();

                  // MessageBox.Show(lbRet + "");
            if (lbRet)
            {
                MiniDump.ExitProcess(3);
            }
           
            MiniDump.RegistUnhandledExceptionHandler();
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            try
            {
                Application.Run(new FormMain());
            }catch(Exception e)
            {

            }
            
        }

        static void loadOpcUserNamePassword(ref String astrUserName,ref String astrPassword)
        {

            try
            {
                byte[] loBuffer = null;

                FileStream loFileStream = new FileStream("setting.json", FileMode.OpenOrCreate);

                try
                {
                    loBuffer = new byte[loFileStream.Length];

                    loFileStream.Read(loBuffer, 0, (int)loFileStream.Length);

                    String lstrServerSetting = Encoding.UTF8.GetString(loBuffer);

                    Object loObj = Newtonsoft.Json.JsonConvert.DeserializeObject(lstrServerSetting, typeof(ServerSetting));

                    ServerSetting loSetting = (ServerSetting)loObj;

                    astrUserName = loSetting.OpcUserName;

                    astrPassword = loSetting.OpcPassword;
                }
                catch (Exception e2)
                {

                }

                loFileStream.Close();

                loFileStream.Dispose();


            }
            catch(Exception e)
            {

            }
 
        }
    }
}
