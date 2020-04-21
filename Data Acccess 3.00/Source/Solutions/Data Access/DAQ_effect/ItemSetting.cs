using System;
using System.Collections.Generic;
using System.Text;
using Opc.Da;

namespace DAQ
{
    public enum COLLECTOR_STATUS
    {
        STOPPED = 1,
        STARTING = 2,
        STARTED = 3,
        TRANSFER_FAILED = 4,
        STOPPING = 5,
        ERROR_RETRYING = 6
    }


    [Serializable]
    public class ItemSetting
    {
        public enum BH_ITEM_TYPE
        {
            PROC = 0,
            VIB = 1,
            DYN = 2,
        };

        public enum BH_TRANSFER_MODE
        {
            READ_WRITE = 0,
            READ = 1,
            WRITE = 2,
        }

        public BH_TRANSFER_MODE m_nTransferMode = BH_TRANSFER_MODE.READ_WRITE;
        public DAQ.ItemSetting.BH_TRANSFER_MODE TransferMode
        {
            get { return m_nTransferMode; }
            set { m_nTransferMode = value; }
        }

        List<string> m_oVariable = new List<string>();
        public List<string> Vars
        {
            get { return m_oVariable; }
            set { m_oVariable = value; }
        }

        private List<String> m_oVarNames = new List<string>();
        public System.Collections.Generic.List<System.String> VarNames
        {
            get { return m_oVarNames; }
            set { m_oVarNames = value; }
        }
        Dictionary<string, BH_ITEM_TYPE> m_oVariableTypes = new Dictionary<string, BH_ITEM_TYPE>();
        public Dictionary<string, BH_ITEM_TYPE> VariableTypes
        {
            get { return m_oVariableTypes; }
            set { m_oVariableTypes = value; }
        }
        string m_strScriptContent_header = "";
        public string ScriptContent_header
        {
            get { return m_strScriptContent_header; }
            set { m_strScriptContent_header = value; }
        }

        string m_strScriptContent_tail = "";
        public string ScriptContent_tail
        {
            get { return m_strScriptContent_tail; }
            set { m_strScriptContent_tail = value; }
        }

        string m_strScriptBody = "";
        public string ScriptContent_Body
        {
            get { return m_strScriptBody; }
            set { m_strScriptBody = value; }
        }

        public string m_strScriptContent = "";
    
        public string ScriptContent
        {
            get {       return m_strScriptContent_header 
                              //  + "\r\n" 
                                + m_strScriptBody 
                              //  +"\r\n"
                                + m_strScriptContent_tail; }

            set { m_strScriptContent = value; }
        }

        int m_nTag = 0;
        public int Tag
        {
            get { return m_nTag; }
            set { m_nTag = value; }
        }
        int m_nItemType = 0;
        public int ItemType
        {
            get { return m_nItemType; }
            set { m_nItemType = value; }
        }

        object m_oValue = new object();
        public object Value
        {
            get { return m_oValue; }
            set { m_oValue = value; }
        }
        string m_strUpdateTime = DateTime.Now.ToString();

        public string strUpdateTime
        {
            get { return m_strUpdateTime; }
            set { if (null != value) { m_strUpdateTime = value.Trim(); } }
        }
        DateTime m_oUpdateTime = DateTime.Now;
        public System.DateTime UpdateTime
        {
            get { return m_oUpdateTime; }
            set { m_oUpdateTime = value; }                   

        }

        DateTime m_oLastUpdateTime = DateTime.MinValue;
        public System.DateTime LastUpdateTime
        {
            get { return m_oLastUpdateTime; }
            set { m_oLastUpdateTime = value; }
        }

        DateTime m_oSendTime = DateTime.Now;
        public System.DateTime SendTime
        {
            get { return m_oSendTime; }
            set { m_oSendTime = value; }
        }

        int m_nUpdateCount = 0;
        public int UpdateCount
        {
            get { return m_nUpdateCount; }
            set { m_nUpdateCount = value; }
        }

        public qualityBits SourceStatus
        {
            get 
            { 
                return this.m_oQuality.QualityBits; 
            }
            set 
            {
                qualityBits lnStatus = value;
                this.m_oQuality.SetCode((short)lnStatus);
            }
        }

        public qualityBits DstStatus
        {
            get
            {
                return this.m_oBHQuality.QualityBits;
            }
            set
            {
                qualityBits lnStatus = value;
                this.m_oBHQuality.SetCode((short)lnStatus);
            }
        }

        String m_strTagName = "";
        public System.String TagName
        {
            get { return m_strTagName; }
            set { if (null != value) { m_strTagName = value.Trim(); } }
        }
        String m_strCompany = "";
        public System.String Company
        {
            get { return m_strCompany; }
            set { if (null != value) { m_strCompany = value.Trim(); } }
        }
        String m_strFactory ="";
        public System.String Factory
        {
            get { return m_strFactory; }
            set { if (null != value) { m_strFactory = value.Trim(); } }
        }
        String m_strPlant ="";
        public System.String Plant
        {
            get { return m_strPlant; }
            set { if (null != value) { m_strPlant = value.Trim(); } }
        }
        String m_strRemoteTageName = "";
        public System.String RemoteTageName
        {
            get { return m_strRemoteTageName; }
            set { if (null != value) { m_strRemoteTageName = value.Trim(); } }

        }

        int m_nStartIndex = 0;
        public int StartIndex
        {
            get { return m_nStartIndex; }
            set { m_nStartIndex = value; }
        }

        String m_strStatusReason = "";
        public System.String StatusReason
        {

            get { return m_strStatusReason; }
            set { if (null != value) { m_strStatusReason = value.Trim(); } }

        }

        Quality m_oQuality = new Quality(qualityBits.badNotConnected);
        public Quality Quality
        {
            get { return   m_oQuality; }
            set { m_oQuality = value; }
        }

        Quality m_oBHQuality = new Quality(qualityBits.badNotConnected);

        public Quality BHQuality
        {
            get { return m_oBHQuality; }
            set { m_oBHQuality = value; }
        }

        double m_dblK = 1.0;
        public double K
        {
            get { return m_dblK; }
            set { m_dblK = value; }
        }
        double m_dblB = 0.0;
        public double B
        {
            get { return m_dblB; }
            set { m_dblB = value; }
        }

        Boolean m_bUsedAsJudgeRunStopStatus = false;
        public System.Boolean UsedAsJudgeRunStopStatus
        {
            get { return m_bUsedAsJudgeRunStopStatus; }
            set { m_bUsedAsJudgeRunStopStatus = value; }
        }

        double m_dblJudgeThreshold = 0.0;
        public double DblJudgeThreshold
        {
            get { return m_dblJudgeThreshold; }
            set { m_dblJudgeThreshold = value; }
        }

        int m_nJudgeType = 0;
        public int JudgeType
        {
            get { return m_nJudgeType; }
            set { m_nJudgeType = value; }
        }

       
        public string Key
        {
            get {
                String lstrKey = this.Company + "." + this.Factory + "." + this.Plant + "." + this.TagName;
                return lstrKey;
            }           
        }

        public BH_ITEM_TYPE m_nBHItemType = BH_ITEM_TYPE.PROC;
        public DAQ.ItemSetting.BH_ITEM_TYPE BHItemType
        {
            get { return m_nBHItemType; }
            set { m_nBHItemType = value; }
        }


        public byte[] m_oBuffer = new byte[0];
        public byte[] Buffer
        {
            get { return m_oBuffer; }
            set { m_oBuffer = value; }
        }

       
    }
}
