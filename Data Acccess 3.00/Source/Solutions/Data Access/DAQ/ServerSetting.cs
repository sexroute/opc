using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
namespace DAQ
{
    [Serializable]
    public class ServerSetting
    {
         public enum ServerType
        {
            WebService = 0,
            BHServer = 1
        }

        public enum ETransferSource
        {
            OPC_SERVER = 0,
            BH_SERVER = 1,
            ASPEN_SERVER = 2,
        }

        String m_strMachine = "";
        public System.String Machine
        {
            get { return m_strMachine; }
            set { m_strMachine = value; }
        }
        String m_strProgID = "";
        public System.String ProgID
        {
            get { return m_strProgID; }
            set { m_strProgID = value; }
        }
        String m_strRemoteUrl = "";
        public System.String RemoteUrl
        {
            get { return m_strRemoteUrl; }
            set { m_strRemoteUrl = value; }
        }
        System.Collections.Generic.List<ItemSetting> m_oTotalItems = new System.Collections.Generic.List<ItemSetting>();

        public System.Collections.Generic.List<ItemSetting> TotalItems
        {
            get { return m_oTotalItems; }
            set { m_oTotalItems = value; }
        }

        int m_nTimeInterval = 1000;
        public int TimeInterval
        {
            get { return m_nTimeInterval; }
            set { m_nTimeInterval = value; }
        }

        String m_strServerMode = Enum.GetName(typeof(ServerType), ServerType.WebService);
	    public System.String ServerMode
	    {
		    get { return m_strServerMode; }
		    set { m_strServerMode = value; }
	    }

        String m_strServerIp = "127.0.0.1";
        public System.String ServerIp
        {
            get { return m_strServerIp; }
            set { m_strServerIp = value; }
        }

        int m_nServerPort = 7001;
        public int ServerPort
        {
            get { return m_nServerPort; }
            set { m_nServerPort = value; }
        }

        ETransferSource m_nTransferSource = ETransferSource.OPC_SERVER;
        public DAQ.ServerSetting.ETransferSource TransferSource
        {
            get { return m_nTransferSource; }
            set { m_nTransferSource = value; }
        }
    }
}
