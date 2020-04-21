/**@brief 程序中所有枚举类型和一些全局宏定义
  *GD_ 代表全局宏定义
  *GE_ 代表全局枚举定义
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

//与同步助手交互，计算分几次发送，因为最多一次可以发送100K，这里按照90K计算,1K=1024，所以最多可以发送92160字节
//因为波形数据为是2个字节，因该发送46080个数,2*46080
#define D_SENDDATA_BYTES   92160
#define D_SENDDATA_MAXNUMS 46080

/**中间上的历史数据每组波形点数以及默认向客户端发送的波形数据个数
  */
#define GD_MIDDLEWARE_WAVE_POINT    1024
#define GD_MIDDLEWARE_WAVE_POINT_RC 4096
#define GD_MIDDLEWARE_WAVE_POINT_WIND 10240

#define GD_FLOAT_SIZE  4

#define GD_CUSTOMPARAM_BUFFSIZE   50

///秒趋势，1分钟的保存记录条数
#define GE_SECONDTREND_PERMINUTE_SAVENUM   20

/*!400线*/
#define 	GD_400LINES    400

/*!800线*/
#define  	GD_800LINES    800

/*!1600线*/
#define 	GD_1600LINES   1600

/*!3200线*/
#define     GD_3200LINES   3200


///提纯轴心轨迹计算各个谐波所需要的参数
#define     GD_HIGHFCNUM   4   /*要提取的高次谐波的数目*/
#define     GD_LOWFCNUM    2   /*要提取的分频谐波的数目*/
#define     GD_HIGHFCTH    10   /*高次谐波的阈值，即超过这个阈值才提取该频率的谐波*/
#define     GD_LOWFCTH     5   /*分频谐波的阈值，即超过这个阈值才提取该频率的谐波*/

/** enumerate the character value type 枚举 */
enum CHARTYPE
{
	GE_ALLCHAR,        /*!通频特征*/
	GE_ONECHAR,        /*!一倍频特征*/
	GE_TWOCHAR,        /*!二倍频特征*/
	GE_THREECHAR,      /*!三倍频特征*/
	GE_HALFCHAR,       /*!一分频特征，即1/2倍频特征*/
    GE_RESCHAR,        /*!残振特征值*/
	GE_DCCHAR,         ///直流量
	GE_GAP,            ///间隙电压
	GE_PHASECHARONE,   ///一倍频相位
	GE_PHASECHARTWO,   ///二倍频相位
	GE_PHASECHARTHREE, ///三倍频相位
	GE_PHASECHARHALF,   ///分倍频相位
	GE_REV, // 转速
	GE_SAMPLEFREQ, // 采样频率
	GE_SAMPLENUM,  // 采样点数
};

enum SERVER_TYPE
{
	GE_SRV_TYPE_SET,          ///装置级中间件服务器
	GE_SRV_TYPE_COMPANY,      ///公司级中间件服务器
	GE_SRV_TYPE_GROUP         ///集团级中间件服务器
};

enum PVTYPE
{
	GE_PVTYPE_PV,             ///P-V图
	GE_PVTYPE_Pa,             ///P-a图
	GE_PVTYPE_Pt,              ///P-t图
	GE_PVTYPE_LOG_PV,         ///logp-logv图
};

#define GE_AXIALDISPLACE GE_PHASECHARTHREE

///设备类型
enum MACHINETYPE
{
	GE_MACHINETYPE_COMPR=0,    ///离心压缩机compressor
	GE_MACHINETYPE_FAN,        ///风机fan
	GE_MACHINETYPE_TURB,       ///汽轮机turbine
	GE_MACHINETYPE_PUMP,       ///离心泵pump
	GE_MACHINETYPE_COMPR1,     ///轴流式压缩机或轴流+离心压缩机
	GE_MACHINETYPE_OTHERS,     ///其他
	GE_MACHINETYPE_RC,         ///往复式压缩机 reciprocating compressor
	GE_MACHINETYPE_KEYPUMP,    ///关键机泵
	GE_MACHINETYPE_WINDPEQ,    ///风电设备
	GE_MACHINETYPE_SMOKESTEAM  ///烟汽轮机
};
/**通道（测点）类型的枚举
  */
enum CHANNTYPE
{
	GE_ALLPROC          = 0,        /*!所有过程量测点*/
	GE_VIBCHANN         = 1,        /*!径向振动测点.*/
	GE_AXIALCHANN       = 2,        /*!轴向振动测点.axial displacement*/
	GE_PRESSCHANN       = 3,        /*!压力测点.*/
	GE_TEMPCHANN        = 4,        /*!温度测点.*/
	GE_FLUXCHANN        = 5,        /*!流量测点.*/
	GE_OTHERCHANN       = 6,        /*!其它.*/
	GE_IMPACTCHANN      = 7,        ///撞击通道
	GE_CURRENTCHANN     = 8,        ///电流测点
	GE_DYNPRESSCHANN    = 11,       ///动态压力信号
	GE_RODSINKCHANN     = 12,       ///活塞杆下沉量信号
	GE_DYNSTRESSCHANN   = 13,       /* !动态应力测点*/
	GE_AXISLOCATIONCHANN= 100       /*!轴心位置*/
};


/*
 * 轴承类别
 */
enum BEARING_TYPE_EN
{
	GE_ROLLING_BEARING    = 1        , /// 滚动轴承"
	GE_SLIDING_BEARING_TILTING_PAD   , /// 可倾瓦滑动轴承
	GE_SLIDING_BEARING_ROUND_FLAPPER , /// 圆瓣式滑动轴承
};


/*
 * 齿轮类型
 */
enum GEAR_BOX_TYPE_EN
{
	GEAR_BOX_TYPE_COMMON = 0, /* 常规齿轮 */
	GEAR_BOX_TYPE_PLANETARY,  /* 行星齿轮 */
	GEAR_BOX_TYPE_NUM
};

/*
 * 行星齿轮驱动方式
 */
enum PLANETARY_GEAR_DRIVE_TYPE_EN
{
	GE_PLANETARY_GEAR_DRIVE_SUN    = 0, /// 太阳轮驱动
	GE_PLANETARY_GEAR_DRIVE_PLANET    , /// 行星轮驱动
	GE_PLANETARY_GEAR_DRIVE_GALAXY    , /// 银河系驱动
	GE_PLANETARY_GEAR_DRIVE_TYPE_NUM,   /// 驱动方式总数
};

/*
 * 轴承表类别
 */
enum BEARING_TABLE_TYPE_EN
{
	GE_SYSTEM_DEFAULT_BEARING_TABLE = 0,
	GE_USER_DEFINED_BEARING_TABLE,
	GE_INVALID_BEARING_TABLE = -1
};

#define GEAR_BOX_LEVEL_SUPPORTED   (5)

/*
 * 数据源
 */
enum GE_DATA_SOURCE_EN
{
	GE_DATA_SOURCE_ONLINE  = 0, // 在线采集设备/测点
	GE_DATA_SOURCE_OFFLINE = 1, // 离线巡检设备/测点
	GE_DATA_SOURCE_MIX     = 2, // 混合设备(既有离线巡测点, 又有在线采集测点), 设备专用,
};



///设备信息类型表中关键字定义
// GE_MI_
enum MACHINEINFOTYPE
{
	GE_MACHINETYPE                  = 1,         ///机器类型
	GE_DRIVERTYPE                   = 2,         ///机器的驱动类型
	GE_BEARINGTYPE                  = 3,         ///轴承类型
	GE_ROTORTYPE                    = 4,         ///转子类型
	GE_WORKINGREV                   = 5,         ///工作转速类型
	GE_CHANNTYPE                    = 6,         ///测点类型
	GE_SENSORTYPE                   = 7,         ///传感器类型
	GE_UNITTYPE                     = 8,         ///单位类型
	GE_VIBCHARTYPE                  = 9,
	GE_MI_GEARBOX_TYPE              = 10,       /// 齿轮箱类型
	GE_MI_MEASUREDIRECTION          = 11,       /// 测量方向
	GE_MI_PLANETARY_GEAR_DRIVE_TYPE = 12,       /// 行星齿轮驱动方式
	GE_MI_DATASOURCE                = 13,       /// 数据源, 类型为GE_DATA_SOURCE_EN
	GE_VIBCHARTYPE_A  = 100,    ///振动信号，采用加速度传感器，对应的特征值类型描述，个数12（0~11）
    GE_DYNCHARTYPE    = 111,    ///动态压力信号的特征值类型描述，个数10（0~9）
	GE_RODSINKCHARTYPE= 112,     ///下沉量信号的特征值类型描述,，个数10（0~9）
	GE_MI_WINDPUMPCHARTYPE = 113    /// 风电机泵信号的特征值类型描述
};


enum SENSORTYPE
{
	GE_SENSORTYPE_VOTEX=1,      //电涡流传感器
	GE_SENSORTYPE_ACCELERATE=2, //加速度传感器
	GE_SENSORTYPE_SPEED=3,      //速度传感器
	GE_SENSORTYPE_PRESSOR=11,   //压力传感器
	GE_SENSORTYPE_FLUX=12,      //流量传感器
	GE_SENSORTYPE_TEMP=13,      //温度传感器
	GE_SENSORTYPE_IMPACT=14,    //撞击传感器
	GE_SENSORTYPE_OTHER=10      //其它
};

///启停车类型
enum E_SUD_TYPE
{
	GE_SUD_UNKNOWN=0,      ///未知
	GE_SUD_START=1,       ///开车
	GE_SUD_STOP=2        ///停车
};

/**历史趋势类型枚举
  */
enum TRENDTYPE
{
    GE_FIVEMINUTETREND,   /*!五分钟趋势*/
	GE_HALFHOURTREND,     /*!三十分钟趋势*/
	GE_HOURTREND,         /*!小时趋势*/
	GE_DAYTREND,          /*!天趋势*/
	GE_MONTHTREND,        /*!月趋势*/
	GE_QUARTERTREND,      /*!季度趋势*/
	GE_YEARTREND,          /*!年趋势*/
	GE_WEEKTREND           /*!周趋势*/
//	GE_ONEMINUTETREND,    /*!一分钟趋势*/
//	GE_TENMINUTETREND,    /*!十分钟时趋势*/
};

///测点通道的大类。是振动，过程量，动态测点
enum E_TBL_CHANNTYPE
{
	E_TBL_CHANNTYPE_VIB=0,         ///振动通道。“VIB”
	E_TBL_CHANNTYPE_PROC,          ///过程量通道。“PROC”
	E_TBL_CHANNTYPE_DYN            ///动态测点通道。“DYN”
};

enum E_TREND_TBL_TYPE
{
	GE_TREND_TBLTYPE_UNKNOWN=0,     ///未知表类型
	GE_TREND_TBLTYPE_SECOND=1,      ///秒趋势表类型,理论上1秒一条记录
	GE_TREND_TBLTYPE_HOUR,          ///小时趋势表类型,理论上1分钟一条记录
	GE_TREND_TBLTYPE_DAY,           ///天趋势表类型，理论上20分钟一条记录
	GE_TREND_TBLTYPE_MONTH          ///月趋势表类型，理论上3小时一条记录
};

/**@brief 用户级别枚举
  *       分厂级操作工只能察看所在分厂的设备运行状况；
  *       分厂级工程师可以察看所在分厂的设备运行状况，并且可以添加设备和修改参数，但是只限制在所在的分厂范围
  *       分厂级管理员可以操作所在分厂范围内的所有业务，添加删除用户和修改等级
  *       全厂级操作工察看全厂的设备运行状况；
  *       全厂级工程师可以察看所在全厂的设备运行状况，并且可以添加设备和修改参数
  *       全厂级管理员可以操作全厂范围内的所有业务，添加删除用户和修改等级
  */
enum USERLEVEL
{
	GE_LOCAL_OPERATOR=1,  /*!分厂级操作工*/
	GE_LOCAL_ENGINEER,    /*!分厂级工程师*/
	GE_LOCAL_ADMIN,       /*!分厂级管理员*/
	GE_WHOLE_OPERATOR,    /*!全厂级浏览*/
	GE_WHOLE_ENGINEER,    /*!全厂级工程师*/
	GE_WHOLE_ADMIN,       /*!全厂级管理员*/
	GE_WHOLE_EXPERT,      /*!全厂级专家*/
	GE_GROUP_OPERATOR,    /*!集团级浏览*/
	GE_GROUP_ENGINEER,    /*!集团级工程师*/
	GE_GROUP_ADMIN,       /*!集团级管理员*/
	GE_GROUP_EXPERT,      /*!集团级专家*/
	GE_EXPERT,            /*!专家*/
	GE_ADMIN              /*!管理人员*/
};

//风电机泵自定义特征值类型
enum E_KEYPUMPWIND_USERCHARTYPE
{
	GE_USER_AFREQ1=0,      ///速度功率谱0.5X倍频
    GE_USER_AFREQ2,        ///速度功率谱5X倍频
	GE_VF_ONEX,            ///速度功率谱1X倍频
	GE_VF_TWO,             ///速度功率谱2X倍频
	GE_VF_THREE,           ///速度功率谱3X倍频
	GE_VF_FOUR,            ///速度功率谱4X倍频
	GE_VF_BLADE,           ///速度功率谱叶片通过频率
	GE_USER_AENVFREQ1,     ///啮合频率
	GE_USER_AENVFREQ2,     ///输出轴转频
	GE_ENVSPECCF1,         ///内圈特征频率
	GE_ENVSPECCF2,         ///外圈特征频率
	GE_ENVSPECCF3,         ///保持架特征频率
	GE_ENVSPECCF4,         ///滚动体特征频率
	GE_GEARBOXSHAFTCF1,    ///齿轮箱I轴转频
    GE_GEARBOXSHAFTCF2,    ///齿轮箱I轴转频
	GE_GEARBOXSHAFTCF3,    ///齿轮箱I轴转频
	GE_GEARBOXSHAFTCF4     ///齿轮箱I轴转频
};

/*!数据库字段的常量定义，在修改记录时候使用*/
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
const char gc_cCritSpeed_1st[]={"CRITSPEED_1ST"};//一阶临界转速
const char gc_cCritSpeed_2nd[]={"CRITSPEED_2ND"};//二阶临界转速
const char gc_cGraphBuff[]={"GRAPHBUFF"};
const char gc_cGraphBuffBytes[]={"GRAPHBUFFBYTES"};//自制概貌图的字节数
const char gc_cManuFacturer[]={"MANUFACTURER"};//制造厂商
const char gc_cFirstRun_T[]={"FIRSTRUN_T"};//首次投运时间
const char gc_cVersion[]={"VERSION"}; //版本号
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

///设备工作在第一临界转速还是第二临界转速
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
///测点转速属于设备第一转速还是第二转速
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
const char gc_cRes[]={"RES"};//残振
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

//阈值的个数,并非阈值结构体的尺寸
const char gc_cThreshold_Len[]={"THRESHOLD_LEN"};
const char gc_cThreshold_ID_New[]={"THRESHOLD_ID_NEW"};
const char gc_cThreshold_Type[]={"THRESHOLD_TYPE"};
//学习参数结构体的个数，并非结构体的尺寸
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
//设备信息类型参数
const char gc_cMachInfoTypeTable[]={"machineinfotype"};
const char gc_cInfoType[]={"INFOTYPE"};
const char gc_cComment[]={"COMMENT"};
const char gc_cIndex[]={"INDEX"};
const char gc_cInfoTypeDetail[]={"INFOTYPEDETAIL"};
const char gc_cPeriod_Start_Index[]={"PERIOD_START_INDEX"};
const char gc_cPeriod_End_Index[]={"PERIOD_END_INDEX"};
/*
 * 自定义参数信息
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
// 预处理类型，如和分，微分
const char gc_cPreProc_Type[] = {"PREPROC_TYPE"};
// 包络谱开始结束值
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
// 自定义模板的TEMPLET_ID
const char gc_cTemplateID_SINK[]      = {"SYS_SINK_TEMPLATE"};
const char gc_cTemplateID_SINK_Desc[] = {"活塞杆柱状图沉降模板"};
const char gc_cTemplateID_VIB[]       = {"SYS_VIB_TEMPLATE"};
const char gc_cTemplateID_VIB_Desc[]  = {"振动监测柱状图模板"};
// 测点表增加测量方向
const char gc_Mesurement_Direction[]   = {"MEASURE_DIRECTION"};
// 部位表/位置表
const char gc_cSection_Table[]         = {"sections"};    // 部位表
const char gc_cLocation_Table[]        = {"locations"};   // 位置表
const char gc_cBearing_Table[]         = {"bearings"};    // 轴承表
const char gc_cCustom_Bearing_Table[]  = {"custom_bearings"}; // 自定义轴承表
const char gc_cGear_Box_Table[]        = {"gear_boxes"};  // 齿轮箱表
const char gc_cSection_IDX[]           = {"SECTION_IDX"};     // 部位索引
const char gc_cSection_Name[]          = {"SECTION_NAME"};    // 部位描述
const char gc_cLocation_IDX[]          = {"LOCATION_IDX"};    // 位置索引
const char gc_cLocation_Name[]         = {"LOCATION_NAME"};   // 位置描述
const char gc_cShaft_Number[]          = {"SHAFT_NUMBER"} ;   // 轴号
const char gc_cBearingTbl_Type[]       = {"BEARING_TABLE"};   // 轴承表类别
// 轴承表
const char gc_cBearing_IDX[]      = {"BEARING_IDX"};      // 轴承索引
const char gc_cBearing_Type[]     = {"BEARING_TYPE"};     // 轴承类型: 滑动轴承, 滚动轴承
const char gc_cBearing_Name[]     = {"BEARING_NAME"};     // 轴承名称
const char gc_cBearing_Code[]     = {"BEARING_CODE"};     // 轴承代码(预留)
const char gc_cRows_Num[]         = {"ROWS_NUM"};         // 滚珠排数
const char gc_cElements_Num[]     = {"ELEMENTS_NUM"};     // 滚珠数
const char gc_cPith_Diameter[]    = {"PITCH_DIAMETER"};   // 节径
const char gc_cElement_Diameter[] = {"ELEMENT_DIAMETER"}; // 滚珠直径
const char gc_cContact_Angle[]    = {"CONTACT_ANGLE"};    // 压力角
const char gc_cHousing_Diameter[] = {"HOUSING_DIAMETER"}; // 外壳直径
const char gc_cBore_Diameter[]    = {"BORE_DIAMETER"};    // 内径
// 齿轮箱
const char gc_cGearBox_IDX      [] = {"GEAR_BOX_IDX"};    // 齿轮箱索引
const char gc_cGearBox_Name     [] = {"GEAR_BOX_NAME"};   // 齿轮箱描述
const char gc_cGearBox_Level    [] = {"GEAR_BOX_LEVEL"};  // 齿轮箱级数
const char gc_cGearBox_Type     [] = {"GEAR_BOX_TYPE"};   // 齿轮箱类别: 常规齿轮,行星齿轮
const char gc_cPlanet_Num       [] = {"PLANET_NUM"};      // 行星轮个数
const char gc_cGear_Num_Sun     [] = {"Z_SUN"};           // 太阳轮齿数
const char gc_cGear_Num_Planet  [] = {"Z_PLANET"};        // 行星轮齿数
const char gc_cGear_Num_Galaxy  [] = {"Z_GALAXY"};        // 银河系齿数
const char gc_cGear_Num_12      [] = {"Z12"};             // 齿数12
const char gc_cGear_Num_21      [] = {"Z21"};             // 齿数21
const char gc_cGear_Num_22      [] = {"Z22"};             // 齿数22
const char gc_cGear_Num_31      [] = {"Z31"};             // 齿数31
const char gc_cGear_Num_32      [] = {"Z32"};             // 齿数32
const char gc_cGear_Num_41      [] = {"Z41"};             // 齿数41
const char gc_cGear_Num_42      [] = {"Z42"};             // 齿数42
const char gc_cGear_Num_51      [] = {"Z51"};             // 齿数51
const char gc_cGear_Num_52      [] = {"Z52"};             // 齿数52
const char gc_cGear_Num_61      [] = {"Z61"};             // 齿数61

// 同步标识
const char gc_cIs_Sync  []         = {"IS_SYNC"};         // 同步标识

const char gc_cData_Source[]       = {"DATA_SOURCE"};     // 数据源, 测点表中使用
const char gc_cDateTime[]          = {"DATETIME"};
const char gc_cCustom_Param[]      = {"CUSTOM_PARAM"};

#define gc_cOfflineTable_Prefix    "TREND_OFFLINE"
#define gc_cTimeFormat             "%Y-%m-%d %H:%M:%S"

#endif //AFX_DSE_DEFINE_MIDDLEWAVE_MARBLE_
