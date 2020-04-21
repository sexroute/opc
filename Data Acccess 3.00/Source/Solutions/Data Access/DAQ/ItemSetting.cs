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
    }

    


    [Serializable]
    public class ItemSetting
    {
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

        public qualityBits OpcStatus
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

        public qualityBits BHStatus
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
    }
}
