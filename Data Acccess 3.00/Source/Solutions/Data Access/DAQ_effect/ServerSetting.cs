using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
namespace DAQ
{
    [Serializable]
    public class ServerSetting
    {
        String m_strTitleName = "";
        public System.String TitleName
        {
            get { return m_strTitleName; }
            set { m_strTitleName = value; }
        }


        public enum DestinationServerType
        {
            WebService = 0,
            BHServer = 1,
            OPC_SERVER = 2,
        }

         public enum BHServerType
         {
            NEW = 0,
            OLD = 1,
        }

        public enum SourceServerType
        {
            OPC_SERVER = 0,
            BH_SERVER = 1,
            ASPEN_SERVER = 2,
        }
        Boolean m_bCheckSourceDataUpdate = false;
        public System.Boolean CheckSourceDataUpdate
        {
            get { return m_bCheckSourceDataUpdate; }
            set { m_bCheckSourceDataUpdate = value; }
        }



        Boolean m_bCheckSourceMiddlewareValid = false;
        public System.Boolean CheckSourceMiddlewareValid
        {
            get { return m_bCheckSourceMiddlewareValid; }
            set { m_bCheckSourceMiddlewareValid = value; }
        }

        Boolean m_bUseSendTimeStamp = false;
        public System.Boolean UseSendTimeStamp
        {
            get { return m_bUseSendTimeStamp; }
            set { m_bUseSendTimeStamp = value; }
        }
        Boolean m_bCheckAllValid = false;
        public System.Boolean CheckAllValid
        {
            get { return m_bCheckAllValid; }
            set { m_bCheckAllValid = value; }
        }
        String m_strDstMachine = "";
        public System.String DstMachine
        {
            get { return m_strDstMachine; }
            set { m_strDstMachine = value; }
        }
        String m_strDstProgID = "";
        public System.String DstProgID
        {
            get { return m_strDstProgID; }
            set { m_strDstProgID = value; }
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


        String m_strServerMode = Enum.GetName(typeof(DestinationServerType), DestinationServerType.WebService);
	    public System.String DstServerMode
	    {
		    get { return m_strServerMode; }
		    set { m_strServerMode = value; }
	    }

        BHServerType m_strBHServerTpyeSrc = BHServerType.OLD;
        public BHServerType BHServerTpyeSrc
        {
            get { return m_strBHServerTpyeSrc; }
            set { m_strBHServerTpyeSrc = value; }
        }

        BHServerType m_strBHServerTpyeDst = BHServerType.OLD;
        public BHServerType BHServerTpyeDst
        {
            get { return m_strBHServerTpyeDst; }
            set { m_strBHServerTpyeDst = value; }
        }

        int m_nHandleLimitCount = 1000;
        public int HandleLimitCount
        {
            get { return m_nHandleLimitCount; }
            set { m_nHandleLimitCount = value; }
        }

        String m_strDstServerIp = "127.0.0.1";
        public System.String DstServerIp
        {
            get { return m_strDstServerIp; }
            set { m_strDstServerIp = value; }
        }

        int m_nDstServerPort = 7001;
        public int DstServerPort
        {
            get { return m_nDstServerPort; }
            set { m_nDstServerPort = value; }
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

        SourceServerType m_nTransferSource = SourceServerType.OPC_SERVER;
        public DAQ.ServerSetting.SourceServerType TransferSource
        {
            get { return m_nTransferSource; }
            set { m_nTransferSource = value; }
        }

        private String m_strOpcUserName = "";
        public System.String OpcUserName
        {
            get { return m_strOpcUserName; }
            set { m_strOpcUserName = value; }
        }

        private Boolean m_bOpcAsyncRead = false;
        public System.Boolean OpcAsyncRead
        {
            get { return m_bOpcAsyncRead; }
            set { m_bOpcAsyncRead = value; }
        }
        private String m_strOpcPassword = "";
        public System.String OpcPassword
        {
            get { return m_strOpcPassword; }
            set { m_strOpcPassword = value; }
        }
    }
}
