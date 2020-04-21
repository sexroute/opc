/**@brief ����������ö�����ͺ�һЩȫ�ֺ궨��
  *GD_ ����ȫ�ֺ궨��
  *GE_ ����ȫ��ö�ٶ���
  *@author Marble
  */

#if!defined  AFX_DSE_DEFINE_MIDDLEWAVE_MARBLE_
#define AFX_DSE_DEFINE_MIDDLEWAVE_MARBLE_


/*! the maxim number of one vibrate channel acquire data.
#define  GD_DAQPOINTNUM        5120 */
/*! the maxim number of vibrate channel
#define  GD_VIBCHANNNUM        16 */
/** the maxim number of axis displace channal
#define  GD_AXISCHANNNUM       4 */
/** the maxim number of technics channal
#define  GD_TECHNICSCHANNNUM   8*/
/** the maxim number of plant
#define  GD_TECHNICSCHANNNUM   8*/

//��ͬ�����ֽ���������ּ��η��ͣ���Ϊ���һ�ο��Է���100K�����ﰴ��90K����,1K=1024�����������Է���92160�ֽ�
//��Ϊ��������Ϊ��2���ֽڣ���÷���46080����,2*46080
#define D_SENDDATA_BYTES   92160
#define D_SENDDATA_MAXNUMS 46080

/**�м��ϵ���ʷ����ÿ�鲨�ε����Լ�Ĭ����ͻ��˷��͵Ĳ������ݸ���
  */
#define GD_MIDDLEWARE_WAVE_POINT    1024
#define GD_MIDDLEWARE_WAVE_POINT_RC 4096
#define GD_MIDDLEWARE_WAVE_POINT_WIND 10240

#define GD_FLOAT_SIZE  4

#define GD_CUSTOMPARAM_BUFFSIZE   50

///�����ƣ�1���ӵı����¼����
#define GE_SECONDTREND_PERMINUTE_SAVENUM   20

/*!400��*/
#define 	GD_400LINES    400

/*!800��*/
#define  	GD_800LINES    800

/*!1600��*/
#define 	GD_1600LINES   1600

/*!3200��*/
#define     GD_3200LINES   3200


///�ᴿ���Ĺ켣�������г������Ҫ�Ĳ���
#define     GD_HIGHFCNUM   4   /*Ҫ��ȡ�ĸߴ�г������Ŀ*/
#define     GD_LOWFCNUM    2   /*Ҫ��ȡ�ķ�Ƶг������Ŀ*/
#define     GD_HIGHFCTH    10   /*�ߴ�г������ֵ�������������ֵ����ȡ��Ƶ�ʵ�г��*/
#define     GD_LOWFCTH     5   /*��Ƶг������ֵ�������������ֵ����ȡ��Ƶ�ʵ�г��*/

/** enumerate the character value type ö�� */
enum CHARTYPE
{
	GE_ALLCHAR,        /*!ͨƵ����*/
	GE_ONECHAR,        /*!һ��Ƶ����*/
	GE_TWOCHAR,        /*!����Ƶ����*/
	GE_THREECHAR,      /*!����Ƶ����*/
	GE_HALFCHAR,       /*!һ��Ƶ��������1/2��Ƶ����*/
    GE_RESCHAR,        /*!��������ֵ*/
	GE_DCCHAR,         ///ֱ����
	GE_GAP,            ///��϶��ѹ
	GE_PHASECHARONE,   ///һ��Ƶ��λ
	GE_PHASECHARTWO,   ///����Ƶ��λ
	GE_PHASECHARTHREE, ///����Ƶ��λ
	GE_PHASECHARHALF,   ///�ֱ�Ƶ��λ
	GE_REV, // ת��
	GE_SAMPLEFREQ, // ����Ƶ��
	GE_SAMPLENUM,  // ��������
};

enum SERVER_TYPE
{
	GE_SRV_TYPE_SET,          ///װ�ü��м��������
	GE_SRV_TYPE_COMPANY,      ///��˾���м��������
	GE_SRV_TYPE_GROUP         ///���ż��м��������
};

enum PVTYPE
{
	GE_PVTYPE_PV,             ///P-Vͼ
	GE_PVTYPE_Pa,             ///P-aͼ
	GE_PVTYPE_Pt,              ///P-tͼ
	GE_PVTYPE_LOG_PV,         ///logp-logvͼ
};

#define GE_AXIALDISPLACE GE_PHASECHARTHREE

///�豸����
enum MACHINETYPE
{
	GE_MACHINETYPE_COMPR=0,    ///����ѹ����compressor
	GE_MACHINETYPE_FAN,        ///���fan
	GE_MACHINETYPE_TURB,       ///���ֻ�turbine
	GE_MACHINETYPE_PUMP,       ///���ı�pump
	GE_MACHINETYPE_COMPR1,     ///����ʽѹ����������+����ѹ����
	GE_MACHINETYPE_OTHERS,     ///����
	GE_MACHINETYPE_RC,         ///����ʽѹ���� reciprocating compressor
	GE_MACHINETYPE_KEYPUMP,    ///�ؼ�����
	GE_MACHINETYPE_WINDPEQ,    ///����豸
	GE_MACHINETYPE_SMOKESTEAM  ///�����ֻ�
};
/**ͨ������㣩���͵�ö��
  */
enum CHANNTYPE
{
	GE_ALLPROC          = 0,        /*!���й��������*/
	GE_VIBCHANN         = 1,        /*!�����񶯲��.*/
	GE_AXIALCHANN       = 2,        /*!�����񶯲��.axial displacement*/
	GE_PRESSCHANN       = 3,        /*!ѹ�����.*/
	GE_TEMPCHANN        = 4,        /*!�¶Ȳ��.*/
	GE_FLUXCHANN        = 5,        /*!�������.*/
	GE_OTHERCHANN       = 6,        /*!����.*/
	GE_IMPACTCHANN      = 7,        ///ײ��ͨ��
	GE_CURRENTCHANN     = 8,        ///�������
	GE_DYNPRESSCHANN    = 11,       ///��̬ѹ���ź�
	GE_RODSINKCHANN     = 12,       ///�������³����ź�
	GE_DYNSTRESSCHANN   = 13,       /* !��̬Ӧ�����*/
	GE_AXISLOCATIONCHANN= 100       /*!����λ��*/
};


/*
 * ������
 */
enum BEARING_TYPE_EN
{
	GE_ROLLING_BEARING    = 1        , /// �������"
	GE_SLIDING_BEARING_TILTING_PAD   , /// �����߻������
	GE_SLIDING_BEARING_ROUND_FLAPPER , /// Բ��ʽ�������
};


/*
 * ��������
 */
enum GEAR_BOX_TYPE_EN
{
	GEAR_BOX_TYPE_COMMON = 0, /* ������� */
	GEAR_BOX_TYPE_PLANETARY,  /* ���ǳ��� */
	GEAR_BOX_TYPE_NUM
};

/*
 * ���ǳ���������ʽ
 */
enum PLANETARY_GEAR_DRIVE_TYPE_EN
{
	GE_PLANETARY_GEAR_DRIVE_SUN    = 0, /// ̫��������
	GE_PLANETARY_GEAR_DRIVE_PLANET    , /// ����������
	GE_PLANETARY_GEAR_DRIVE_GALAXY    , /// ����ϵ����
	GE_PLANETARY_GEAR_DRIVE_TYPE_NUM,   /// ������ʽ����
};

/*
 * ��б����
 */
enum BEARING_TABLE_TYPE_EN
{
	GE_SYSTEM_DEFAULT_BEARING_TABLE = 0,
	GE_USER_DEFINED_BEARING_TABLE,
	GE_INVALID_BEARING_TABLE = -1
};

#define GEAR_BOX_LEVEL_SUPPORTED   (5)

/*
 * ����Դ
 */
enum GE_DATA_SOURCE_EN
{
	GE_DATA_SOURCE_ONLINE  = 0, // ���߲ɼ��豸/���
	GE_DATA_SOURCE_OFFLINE = 1, // ����Ѳ���豸/���
	GE_DATA_SOURCE_MIX     = 2, // ����豸(��������Ѳ���, �������߲ɼ����), �豸ר��,
};



///�豸��Ϣ���ͱ��йؼ��ֶ���
// GE_MI_
enum MACHINEINFOTYPE
{
	GE_MACHINETYPE                  = 1,         ///��������
	GE_DRIVERTYPE                   = 2,         ///��������������
	GE_BEARINGTYPE                  = 3,         ///�������
	GE_ROTORTYPE                    = 4,         ///ת������
	GE_WORKINGREV                   = 5,         ///����ת������
	GE_CHANNTYPE                    = 6,         ///�������
	GE_SENSORTYPE                   = 7,         ///����������
	GE_UNITTYPE                     = 8,         ///��λ����
	GE_VIBCHARTYPE                  = 9,
	GE_MI_GEARBOX_TYPE              = 10,       /// ����������
	GE_MI_MEASUREDIRECTION          = 11,       /// ��������
	GE_MI_PLANETARY_GEAR_DRIVE_TYPE = 12,       /// ���ǳ���������ʽ
	GE_MI_DATASOURCE                = 13,       /// ����Դ, ����ΪGE_DATA_SOURCE_EN
	GE_VIBCHARTYPE_A  = 100,    ///���źţ����ü��ٶȴ���������Ӧ������ֵ��������������12��0~11��
    GE_DYNCHARTYPE    = 111,    ///��̬ѹ���źŵ�����ֵ��������������10��0~9��
	GE_RODSINKCHARTYPE= 112,     ///�³����źŵ�����ֵ��������,������10��0~9��
	GE_MI_WINDPUMPCHARTYPE = 113    /// �������źŵ�����ֵ��������
};


enum SENSORTYPE
{
	GE_SENSORTYPE_VOTEX=1,      //������������
	GE_SENSORTYPE_ACCELERATE=2, //���ٶȴ�����
	GE_SENSORTYPE_SPEED=3,      //�ٶȴ�����
	GE_SENSORTYPE_PRESSOR=11,   //ѹ��������
	GE_SENSORTYPE_FLUX=12,      //����������
	GE_SENSORTYPE_TEMP=13,      //�¶ȴ�����
	GE_SENSORTYPE_IMPACT=14,    //ײ��������
	GE_SENSORTYPE_OTHER=10      //����
};

///��ͣ������
enum E_SUD_TYPE
{
	GE_SUD_UNKNOWN=0,      ///δ֪
	GE_SUD_START=1,       ///����
	GE_SUD_STOP=2        ///ͣ��
};

/**��ʷ��������ö��
  */
enum TRENDTYPE
{
    GE_FIVEMINUTETREND,   /*!���������*/
	GE_HALFHOURTREND,     /*!��ʮ��������*/
	GE_HOURTREND,         /*!Сʱ����*/
	GE_DAYTREND,          /*!������*/
	GE_MONTHTREND,        /*!������*/
	GE_QUARTERTREND,      /*!��������*/
	GE_YEARTREND,          /*!������*/
	GE_WEEKTREND           /*!������*/
//	GE_ONEMINUTETREND,    /*!һ��������*/
//	GE_TENMINUTETREND,    /*!ʮ����ʱ����*/
};

///���ͨ���Ĵ��ࡣ���񶯣�����������̬���
enum E_TBL_CHANNTYPE
{
	E_TBL_CHANNTYPE_VIB=0,         ///��ͨ������VIB��
	E_TBL_CHANNTYPE_PROC,          ///������ͨ������PROC��
	E_TBL_CHANNTYPE_DYN            ///��̬���ͨ������DYN��
};

enum E_TREND_TBL_TYPE
{
	GE_TREND_TBLTYPE_UNKNOWN=0,     ///δ֪������
	GE_TREND_TBLTYPE_SECOND=1,      ///�����Ʊ�����,������1��һ����¼
	GE_TREND_TBLTYPE_HOUR,          ///Сʱ���Ʊ�����,������1����һ����¼
	GE_TREND_TBLTYPE_DAY,           ///�����Ʊ����ͣ�������20����һ����¼
	GE_TREND_TBLTYPE_MONTH          ///�����Ʊ����ͣ�������3Сʱһ����¼
};

/**@brief �û�����ö��
  *       �ֳ���������ֻ�ܲ쿴���ڷֳ����豸����״����
  *       �ֳ�������ʦ���Բ쿴���ڷֳ����豸����״�������ҿ�������豸���޸Ĳ���������ֻ���������ڵķֳ���Χ
  *       �ֳ�������Ա���Բ������ڷֳ���Χ�ڵ�����ҵ�����ɾ���û����޸ĵȼ�
  *       ȫ�����������쿴ȫ�����豸����״����
  *       ȫ��������ʦ���Բ쿴����ȫ�����豸����״�������ҿ�������豸���޸Ĳ���
  *       ȫ��������Ա���Բ���ȫ����Χ�ڵ�����ҵ�����ɾ���û����޸ĵȼ�
  */
enum USERLEVEL
{
	GE_LOCAL_OPERATOR=1,  /*!�ֳ���������*/
	GE_LOCAL_ENGINEER,    /*!�ֳ�������ʦ*/
	GE_LOCAL_ADMIN,       /*!�ֳ�������Ա*/
	GE_WHOLE_OPERATOR,    /*!ȫ�������*/
	GE_WHOLE_ENGINEER,    /*!ȫ��������ʦ*/
	GE_WHOLE_ADMIN,       /*!ȫ��������Ա*/
	GE_WHOLE_EXPERT,      /*!ȫ����ר��*/
	GE_GROUP_OPERATOR,    /*!���ż����*/
	GE_GROUP_ENGINEER,    /*!���ż�����ʦ*/
	GE_GROUP_ADMIN,       /*!���ż�����Ա*/
	GE_GROUP_EXPERT,      /*!���ż�ר��*/
	GE_EXPERT,            /*!ר��*/
	GE_ADMIN              /*!������Ա*/
};

//�������Զ�������ֵ����
enum E_KEYPUMPWIND_USERCHARTYPE
{
	GE_USER_AFREQ1=0,      ///�ٶȹ�����0.5X��Ƶ
    GE_USER_AFREQ2,        ///�ٶȹ�����5X��Ƶ
	GE_VF_ONEX,            ///�ٶȹ�����1X��Ƶ
	GE_VF_TWO,             ///�ٶȹ�����2X��Ƶ
	GE_VF_THREE,           ///�ٶȹ�����3X��Ƶ
	GE_VF_FOUR,            ///�ٶȹ�����4X��Ƶ
	GE_VF_BLADE,           ///�ٶȹ�����ҶƬͨ��Ƶ��
	GE_USER_AENVFREQ1,     ///����Ƶ��
	GE_USER_AENVFREQ2,     ///�����תƵ
	GE_ENVSPECCF1,         ///��Ȧ����Ƶ��
	GE_ENVSPECCF2,         ///��Ȧ����Ƶ��
	GE_ENVSPECCF3,         ///���ּ�����Ƶ��
	GE_ENVSPECCF4,         ///����������Ƶ��
	GE_GEARBOXSHAFTCF1,    ///������I��תƵ
    GE_GEARBOXSHAFTCF2,    ///������I��תƵ
	GE_GEARBOXSHAFTCF3,    ///������I��תƵ
	GE_GEARBOXSHAFTCF4     ///������I��תƵ
};

/*!���ݿ��ֶεĳ������壬���޸ļ�¼ʱ��ʹ��*/
const char gc_cCenterMw_IP[]={"IP"};
const char gc_cCenterMw_Port[]={"PORT"};
const char gc_cSend_Interval[]={"SEND_INTERVAL"};
const char gc_cIf_Send[]={"IF_SEND"};
const char gc_cSud_Send_Interval[]={"SUD_SEND_INTERVAL"};
const char gc_cAlarm_Send_Interval[]={"ALARM_SEND_INTERVAL"};
const char gc_cTm_IP[]={"TM_IP"};
const char gc_cTm_Port[]={"TM_PORT"};
const char gc_cChannNo[]={"CHANNNO"};
const char gc_cChannID[]={"CHANNID"};
const char gc_cChannIDA[]={"CHANNID_ALIAS"};
const char gc_cSetID[]={"SETID"};
const char gc_cPlantID[]={"PLANTID"};
const char gc_cPlantNo[]={"PLANTNO"};
const char gc_cCylinderNo[]={"CYLINDERNO"};
const char gc_cRecipComprParam[]={"RECIPCOMPRPARAM"};
const char gc_cVibChann_Num[]={"VIBCHANN_NUM"};
const char gc_cDynChann_Num[]={"DYNCHANN_NUM"};
const char gc_cCylinder_Num[]={"CYLINDER_NUM"};
const char gc_cAxisChann_Num[]={"AXISCHANN_NUM"};
const char gc_cProcChann_Num[]={"PROCCHANN_NUM"};
const char gc_cFluxChann_Num[]={"FLUXCHANN_NUM"};
const char gc_cTempChann_Num[]={"TEMPCHANN_NUM"};
const char gc_cPressChann_Num[]={"PRESSCHANN_NUM"};
const char gc_cOtherChann_Num[]={"OTHERCHANN_NUM"};
const char gc_cMachine_Type[]={"MACHINE_TYPE"};
const char gc_cCritSpeed_1st[]={"CRITSPEED_1ST"};//һ���ٽ�ת��
const char gc_cCritSpeed_2nd[]={"CRITSPEED_2ND"};//�����ٽ�ת��
const char gc_cGraphBuff[]={"GRAPHBUFF"};
const char gc_cGraphBuffBytes[]={"GRAPHBUFFBYTES"};//���Ƹ�òͼ���ֽ���
const char gc_cManuFacturer[]={"MANUFACTURER"};//���쳧��
const char gc_cFirstRun_T[]={"FIRSTRUN_T"};//�״�Ͷ��ʱ��
const char gc_cVersion[]={"VERSION"}; //�汾��
const char gc_cType[]={"TYPE"};
const char gc_cCoor_X[]={"COOR_X"};
const char gc_cCoor_Y[]={"COOR_Y"};
const char gc_cDC_X[]={"DC_X"};
const char gc_cDC_Y[]={"DC_Y"};
const char gc_cGap_X[]={"GAP_X"};
const char gc_cGap_Y[]={"GAP_Y"};

const char gc_cDriver_Type[]={"DRIVER_TYPE"};
const char gc_cConn_Type[]={"CONN_TYPE"};
const char gc_cBear_Type[]={"BEAR_TYPE"};
const char gc_cRotate_Type[]={"ROTATE_TYPE"};
const char gc_cSeal_Type[]={"SEAL_TYPE"};

///�豸�����ڵ�һ�ٽ�ת�ٻ��ǵڶ��ٽ�ת��
const char gc_cRev_Type[]={"REV_TYPE"};
const char gc_cSampleFreq[]={"SAMPLE_FREQ"};
const char gc_cSampleNum[]={"SAMPLE_NUM"};
const char gc_cSensitivity[]={"SENSITIVITY"};
const char gc_cSensitivity1[]={"SENSITIVITY1"};
const char gc_cAlarmLow[]={"ALARM_LOW"};
const char gc_cAlarmHigh[]={"ALARM_HIGH"};
//const char gc_cCheckAlarm[]={"CHECK_ALARM"};
const char gc_cAlarmParam[]={"ALARM_PARAM"};
const char gc_cGapVoltage[]={"GAPVOLTAGE"};
const char gc_cAngle[]="ANGLE";
const char gc_cKeyIF[]={"KEY_IF"};
const char gc_cRev[]={"REV"};
const char gc_cRev2[]={"REV2"};
const char gc_cRev3[]={"REV3"};
const char gc_cRev4[]={"REV4"};
const char gc_cRev5[]={"REV5"};
const char gc_cGraphType[]={"GRAPH_TYPE"};
const char gc_cList[]={"LIST"};
const char gc_cUnit[]={"UNIT"};
const char gc_cSensorType[]={"SENSOR_TYPE"};
///���ת�������豸��һת�ٻ��ǵڶ�ת��
const char gc_cRevType[]={"REVTYPE"};
const char gc_cFactory_Name[]={"FACTORY_NAME"};
const char gc_cFactory_Alias[]={"FACTORY_ALIAS"};
const char gc_cCompany[]={"COMPANY"};
const char gc_cCompanyAlias[]={"COMPANY_ALIAS"};
const char gc_cGroup[]={"GROUP"};
const char gc_cUserName[]={"USERNAME"};
const char gc_cPassWord[]={"PASSWORD"};
const char gc_cRefreshTime[]={"REFRESHTIME"};
const char gc_cUserLevel[]={"USERLEVEL"};
const char gc_cBrowseSet[]={"BROWSESET"};
const char gc_cDaq_IP[]={"DAQ_IP"};

const char gc_cID[]={"ID"};
const char gc_cEventID[]={"EVENT_ID"};
const char gc_cAll[]={"ALL"};
const char gc_cOne[]={"ONE"};
const char gc_cTwo[]={"TWO"};
const char gc_cThree[]={"THREE"};
const char gc_cHalf[]={"HALF"};
const char gc_cRes[]={"RES"};//����
const char gc_cTime[]={"DATETIME"};
const char gc_cMicroSecond[]={"MICROSECOND"};
const char gc_cWave[]={"WAVE"};
const char gc_cChannType[]={"CHANN_TYPE"};
const char gc_cProcValue[]={"PROCVALUE"};
const char gc_cTrendType[]={"TREND_TYPE"};
const char gc_cSynFlag[]={"SYN_FLAG"};
const char gc_cName[]={"NAME"};

const char gc_cPhaseHalf[]={"HALFPHASE"};
const char gc_cPhaseOne[]={"ONEPHASE"};
const char gc_cPhaseTwo[]={"TWOPHASE"};
const char gc_cPhaseThree[]={"THREEPHASE"};
const char gc_cDC[]={"DC"};
const char gc_cGap[]={"GAP"};
const char gc_cDot[]={","};

const char gc_cEventTable[]={"EVENT_RECORD"};
const char gc_cEvent_Time[]={"EVENT_TIME"};
const char gc_cEvent_Content[]={"EVENT_CONTENT"};
const char gc_cDefault_Status[]={"DEFAULT_STATUS"};
const char gc_cResult_Feedback[]={"RESULT_FEEDBACK"};

//const char gc_cDatetime_Start[]={"DATETIME_START"};
const char gc_cStart_T[]={"START_T"};
const char gc_cEnd_T[]={"END_T"};
const char gc_cStop_Flag[]={"STOP_FLAG"};
const char gc_cVerChann[]={"VERCHANN"};
const char gc_cHorChann[]={"HORCHANN"};
const char gc_cLocation[]={"LOCATION"};
const char gc_cLocationType[]={"LOCATION_TYPE"};
const char gc_cAxis_Dia[]={"AXIS_DIA"};
const char gc_cRotate_Direction[]={"ROTATE_DIRECTION"};

const char gc_cData[]={"DATA"};
const char gc_cData_Len[]={"DATA_LEN"};
const char gc_cThreshold[]={"THRESHOLD"};
const char gc_cThreshold_ID[]={"THRESHOLD_ID"};

//��ֵ�ĸ���,������ֵ�ṹ��ĳߴ�
const char gc_cThreshold_Len[]={"THRESHOLD_LEN"};
const char gc_cThreshold_ID_New[]={"THRESHOLD_ID_NEW"};
const char gc_cThreshold_Type[]={"THRESHOLD_TYPE"};
//ѧϰ�����ṹ��ĸ��������ǽṹ��ĳߴ�
const char gc_cLearnParam_Len[]={"LEARN_PARAM_LEN"};
const char gc_cLearnParam[]={"LEARN_PARAM"};
const char gc_cAlarm_Type[]={"ALARM_TYPE"};

const char gc_cCompanyTable[]={"company"};
const char gc_cFactoryTable[]={"factory"};
const char gc_cSetTable[]={"settable"};
const char gc_cChannTable[]={"channel"};
const char gc_cMachineTable[]={"machine"};
const char gc_cUserTable[]={"DSE_USER"};
const char gc_cPlantAxisTable[]={"PLANT_AXIS"};
const char gc_cDB_ID[]={"DB_ID"};
const char gc_cDB_Name[]={"DB_NAME"};
const char gc_cParent_ID[]={"PARENT_ID"};
const char gc_cChild_Flag[]={"CHILD_FLAG"};
//�豸��Ϣ���Ͳ���
const char gc_cMachInfoTypeTable[]={"machineinfotype"};
const char gc_cInfoType[]={"INFOTYPE"};
const char gc_cComment[]={"COMMENT"};
const char gc_cIndex[]={"INDEX"};
const char gc_cInfoTypeDetail[]={"INFOTYPEDETAIL"};
const char gc_cPeriod_Start_Index[]={"PERIOD_START_INDEX"};
const char gc_cPeriod_End_Index[]={"PERIOD_END_INDEX"};
/*
 * �Զ��������Ϣ
 */
const char gc_cTempletID[]={"TEMPLET_ID"};
const char gc_cAlarm_TempletID[]={"ALARM_TEMPLET_ID"};
const char gc_cParam_Comment[]={"PARAM_COMMENT"};
const char gc_cData_Type[] = {"DATA_TYPE"};
const char gc_cUnit_Type[] = {"UNIT_TYPE"};
const char gc_cSignal_Ana_Type[]={"SIGNAL_ANA_TYPE"};
const char gc_cSeg_Start_NO[]={"SEG_START_NO"};
const char gc_cSeg_Num[]={"SEG_NUM"};
const char gc_cData_Start_Value[]={"DATA_START_VALUE"};
const char gc_cData_End_Value[]={"DATA_END_VALUE"};
const char gc_cChar_Type[]={"CHAR_TYPE"};
const char gc_cSegName[]={"SEG_NAME"};
// Ԥ�������ͣ���ͷ֣�΢��
const char gc_cPreProc_Type[] = {"PREPROC_TYPE"};
// �����׿�ʼ����ֵ
const char gc_cBand_Start_Value[]   = {"BAND_START_VALUE"};
const char gc_cBand_End_Value[]     = {"BAND_END_VALUE"};
const char gc_cAlarm_Param_Comment[]={"ALARM_PARAM_COMMENT"};
const char gc_cJudge_Type[]={"JUDGE_TYPE"};
const char gc_cAlarm_Start_SegNO[]={"ALARM_START_SEGNO"};
const char gc_cIF_Alarm[]={"IF_ALARM"};
const char gc_cAlarm_Group[]={"ALARM_GROUP"};
const char gc_cAlarm_LTH[]={"ALARM_LTH"};
const char gc_cAlarm_HTH[]={"ALARM_HTH"};

const char gc_cTemplet_Table[]           = {"templet"};
const char gc_cCustom_Param_Table[]      = {"customparam"};
const char gc_cAlarm_Templet_Table[]     = {"alarmtemplet"};
const char gc_cAlarm_Param_Table[]       = {"alarmparam"};
const char gc_cChann_Alarm_Param_Table[] = {"channelalarmparam"};
// �Զ���ģ���TEMPLET_ID
const char gc_cTemplateID_SINK[]      = {"SYS_SINK_TEMPLATE"};
const char gc_cTemplateID_SINK_Desc[] = {"��������״ͼ����ģ��"};
const char gc_cTemplateID_VIB[]       = {"SYS_VIB_TEMPLATE"};
const char gc_cTemplateID_VIB_Desc[]  = {"�񶯼����״ͼģ��"};
// �������Ӳ�������
const char gc_Mesurement_Direction[]   = {"MEASURE_DIRECTION"};
// ��λ��/λ�ñ�
const char gc_cSection_Table[]         = {"sections"};    // ��λ��
const char gc_cLocation_Table[]        = {"locations"};   // λ�ñ�
const char gc_cBearing_Table[]         = {"bearings"};    // ��б�
const char gc_cCustom_Bearing_Table[]  = {"custom_bearings"}; // �Զ�����б�
const char gc_cGear_Box_Table[]        = {"gear_boxes"};  // �������
const char gc_cSection_IDX[]           = {"SECTION_IDX"};     // ��λ����
const char gc_cSection_Name[]          = {"SECTION_NAME"};    // ��λ����
const char gc_cLocation_IDX[]          = {"LOCATION_IDX"};    // λ������
const char gc_cLocation_Name[]         = {"LOCATION_NAME"};   // λ������
const char gc_cShaft_Number[]          = {"SHAFT_NUMBER"} ;   // ���
const char gc_cBearingTbl_Type[]       = {"BEARING_TABLE"};   // ��б����
// ��б�
const char gc_cBearing_IDX[]      = {"BEARING_IDX"};      // �������
const char gc_cBearing_Type[]     = {"BEARING_TYPE"};     // �������: �������, �������
const char gc_cBearing_Name[]     = {"BEARING_NAME"};     // �������
const char gc_cBearing_Code[]     = {"BEARING_CODE"};     // ��д���(Ԥ��)
const char gc_cRows_Num[]         = {"ROWS_NUM"};         // ��������
const char gc_cElements_Num[]     = {"ELEMENTS_NUM"};     // ������
const char gc_cPith_Diameter[]    = {"PITCH_DIAMETER"};   // �ھ�
const char gc_cElement_Diameter[] = {"ELEMENT_DIAMETER"}; // ����ֱ��
const char gc_cContact_Angle[]    = {"CONTACT_ANGLE"};    // ѹ����
const char gc_cHousing_Diameter[] = {"HOUSING_DIAMETER"}; // ���ֱ��
const char gc_cBore_Diameter[]    = {"BORE_DIAMETER"};    // �ھ�
// ������
const char gc_cGearBox_IDX      [] = {"GEAR_BOX_IDX"};    // ����������
const char gc_cGearBox_Name     [] = {"GEAR_BOX_NAME"};   // ����������
const char gc_cGearBox_Level    [] = {"GEAR_BOX_LEVEL"};  // �����伶��
const char gc_cGearBox_Type     [] = {"GEAR_BOX_TYPE"};   // ���������: �������,���ǳ���
const char gc_cPlanet_Num       [] = {"PLANET_NUM"};      // �����ָ���
const char gc_cGear_Num_Sun     [] = {"Z_SUN"};           // ̫���ֳ���
const char gc_cGear_Num_Planet  [] = {"Z_PLANET"};        // �����ֳ���
const char gc_cGear_Num_Galaxy  [] = {"Z_GALAXY"};        // ����ϵ����
const char gc_cGear_Num_12      [] = {"Z12"};             // ����12
const char gc_cGear_Num_21      [] = {"Z21"};             // ����21
const char gc_cGear_Num_22      [] = {"Z22"};             // ����22
const char gc_cGear_Num_31      [] = {"Z31"};             // ����31
const char gc_cGear_Num_32      [] = {"Z32"};             // ����32
const char gc_cGear_Num_41      [] = {"Z41"};             // ����41
const char gc_cGear_Num_42      [] = {"Z42"};             // ����42
const char gc_cGear_Num_51      [] = {"Z51"};             // ����51
const char gc_cGear_Num_52      [] = {"Z52"};             // ����52
const char gc_cGear_Num_61      [] = {"Z61"};             // ����61

// ͬ����ʶ
const char gc_cIs_Sync  []         = {"IS_SYNC"};         // ͬ����ʶ

const char gc_cData_Source[]       = {"DATA_SOURCE"};     // ����Դ, ������ʹ��
const char gc_cDateTime[]          = {"DATETIME"};
const char gc_cCustom_Param[]      = {"CUSTOM_PARAM"};

#define gc_cOfflineTable_Prefix    "TREND_OFFLINE"
#define gc_cTimeFormat             "%Y-%m-%d %H:%M:%S"

#endif //AFX_DSE_DEFINE_MIDDLEWAVE_MARBLE_
