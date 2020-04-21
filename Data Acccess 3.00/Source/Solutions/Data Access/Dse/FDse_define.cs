using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Dse
{
    public static class FDse_define
    {

        public static class CHANNTYPE
        {
            public static int GE_ALLPROC = 0;
            public static int GE_VIBCHANN = 1;
            public static int GE_AXIALCHANN = 2;
            public static int GE_PRESSCHANN = 3;
            public static int GE_TEMPCHANN = 4;
            public static int GE_FLUXCHANN = 5;
            public static int GE_OTHERCHANN = 6;
            public static int GE_IMPACTCHANN = 7;
            public static int GE_CURRENTCHANN = 8;
            public static int GE_DYNPRESSCHANN = 11;
            public static int GE_RODSINKCHANN = 12;
            public static int GE_DYNSTRESSCHANN = 13;
            public static int GE_AXISLOCATIONCHANN = 100;
            public static int GE_LUBRICATION = 101;
        }

        public static class CHARTYPE
        {
            public static int GE_ALLCHAR = 0;           /*!通频特征*/
            public static int GE_ONECHAR = 1;           /*!一倍频特征*/
            public static int GE_TWOCHAR = 2;           /*!二倍频特征*/
            public static int GE_THREECHAR = 3;     /*!三倍频特征*/
            public static int GE_HALFCHAR = 4;      /*!一分频特征，即1/2倍频特征*/
            public static int GE_RESCHAR = 5;           /*!残振特征值*/
            public static int GE_DCCHAR = 6;            ///直流量
            public static int GE_GAP = 7;               ///间隙电压
            public static int GE_PHASECHARONE = 8;  ///一倍频相位
            public static int GE_PHASECHARTWO = 9;  ///二倍频相位
            public static int GE_PHASECHARTHREE = 10;   ///三倍频相位
            public static int GE_PHASECHARHALF = 11;   ///分倍频相位
            public static int GE_REV = 12;              // 转速
            public static int GE_SAMPLEFREQ = 13;       // 采样频率
            public static int GE_SAMPL = 14;        // 采样点数
        };

        public static class SERVER_TYPE
        {
            public static int GE_SRV_TYPE_SET = 0;          ///装置级中间件服务器
            public static int GE_SRV_TYPE_COMPANY = 1;      ///公司级中间件服务器
            public static int GE_SRV_TYPE_GROUP = 2;          ///集团级中间件服务器
        };

        public static class PVTYPE
        {
            public static int GE_PVTYPE_PV = 0;             ///P-V图
            public static int GE_PVTYPE_Pa = 1;             ///P-a图
            public static int GE_PVTYPE_Pt = 2;              ///P-t图
            public static int GE_PVTYPE_LOG_PV = 3;         ///logp-logv图
            public static int GE_PVTYPE_DP = 4;             ///压力变化率
        };

        public static int GE_AXIALDISPLACE = CHARTYPE.GE_PHASECHARTHREE;

        ///设备类型
        public static class MACHINETYPE
        {
            public static int GE_MACHINETYPE_COMPR = 0;    ///离心压缩机compressor
            public static int GE_MACHINETYPE_FAN = 1;        ///风机fan
            public static int GE_MACHINETYPE_TURB = 2;       ///汽轮机turbine
            public static int GE_MACHINETYPE_PUMP = 3;       ///离心泵pump
            public static int GE_MACHINETYPE_COMPR1 = 4;     ///轴流式压缩机或轴流+离心压缩机
            public static int GE_MACHINETYPE_OTHERS = 5;     ///其他
            public static int GE_MACHINETYPE_RC = 6;         ///往复式压缩机 reciprocating compressor
            public static int GE_MACHINETYPE_KEYPUMP = 7;    ///关键机泵
            public static int GE_MACHINETYPE_WINDPEQ = 8;    ///风电设备
            public static int GE_MACHINETYPE_SMOKESTEAM = 9;  ///烟汽轮机
            public static int GE_MACHINETYPE_DISEL = 10;       ///柴油机
            public static int GE_MACHINETYPE_ICE = 11;         ///内燃机/柴油机
            public static int GE_MACHINETYPE_ALL = 12;          ///总概貌图
        };


        /*
         * 轴承类别
         */
        public static class BEARING_TYPE_EN
        {
            public static int GE_ROLLING_BEARING = 1; /// 滚动轴承"
            public static int GE_SLIDING_BEARING_TILTING_PAD = 2; /// 可倾瓦滑动轴承
            public static int GE_SLIDING_BEARING_ROUND_FLAPPER = 3; /// 圆瓣式滑动轴承
        };


        /*
         * 齿轮类型
         */
        public static class GEAR_BOX_TYPE_EN
        {
            public static int GEAR_BOX_TYPE_COMMON = 0; /* 常规齿轮 */
            public static int GEAR_BOX_TYPE_PLANETARY = 1;  /* 行星齿轮 */
            public static int GEAR_BOX_TYPE_NUM = 2;
        };

        /*
         * 行星齿轮驱动方式
         */
        public static class PLANETARY_GEAR_DRIVE_TYPE_EN
        {
            public static int GE_PLANETARY_GEAR_DRIVE_SUN = 0; /// 太阳轮驱动
            public static int GE_PLANETARY_GEAR_DRIVE_PLANET = 1; /// 行星轮驱动
            public static int GE_PLANETARY_GEAR_DRIVE_GALAXY = 2; /// 银河系驱动
            public static int GE_PLANETARY_GEAR_DRIVE_TYPE_NUM = 3;   /// 驱动方式总数
        };

        /*
         * 轴承表类别
         */
        public static class BEARING_TABLE_TYPE_EN
        {
            public static int GE_SYSTEM_DEFAULT_BEARING_TABLE = 0;
            public static int GE_USER_DEFINED_BEARING_TABLE = 1;
            public static int GE_INVALID_BEARING_TABLE = -1;
        };


        /*
         * 数据源
         */
        public static class GE_DATA_SOURCE_EN
        {
            public static int GE_DATA_SOURCE_ONLINE = 0; // 在线采集设备/测点
            public static int GE_DATA_SOURCE_OFFLINE = 1; // 离线巡检设备/测点
            public static int GE_DATA_SOURCE_WIRELESS = 2; // 无线传感器采集测点;
        };



        ///设备信息类型表中关键字定义
        // GE_MI_
        public static class MACHINEINFOTYPE
        {
            public static int GE_MACHINETYPE = 1;         ///机器类型
            public static int GE_DRIVERTYPE = 2;         ///机器的驱动类型
            public static int GE_BEARINGTYPE = 3;         ///轴承类型
            public static int GE_ROTORTYPE = 4;         ///转子类型
            public static int GE_WORKINGREV = 5;         ///工作转速类型
            public static int GE_CHANNTYPE = 6;         ///测点类型
            public static int GE_SENSORTYPE = 7;         ///传感器类型
            public static int GE_UNITTYPE = 8;         ///单位类型
            public static int GE_VIBCHARTYPE = 9;
            public static int GE_MI_GEARBOX_TYPE = 10;       /// 齿轮箱类型
            public static int GE_MI_MEASUREDIRECTION = 11;       /// 测量方向
            public static int GE_MI_PLANETARY_GEAR_DRIVE_TYPE = 12;       /// 行星齿轮驱动方式
            public static int GE_MI_DATASOURCE = 13;       /// 数据源; 类型为GE_DATA_SOURCE_EN
            public static int GE_VIBCHARTYPE_A = 100;    ///振动信号，采用加速度传感器，对应的特征值类型描述，个数12（0~11）
            public static int GE_DYNCHARTYPE = 111;    ///动态压力信号的特征值类型描述，个数10（0~9）
            public static int GE_RODSINKCHARTYPE = 112;     ///下沉量信号的特征值类型描述;，个数10（0~9）
            public static int GE_MI_WINDPUMPCHARTYPE = 113;    /// 风电机泵信号的特征值类型描述
        };


        public static class SENSORTYPE
        {
            public static int GE_SENSORTYPE_VOTEX = 1;      //电涡流传感器
            public static int GE_SENSORTYPE_ACCELERATE = 2; //加速度传感器
            public static int GE_SENSORTYPE_SPEED = 3;      //速度传感器
            public static int GE_SENSORTYPE_PRESSOR = 11;   //压力传感器
            public static int GE_SENSORTYPE_FLUX = 12;      //流量传感器
            public static int GE_SENSORTYPE_TEMP = 13;      //温度传感器
            public static int GE_SENSORTYPE_IMPACT = 14;    //撞击传感器
            public static int GE_SENSORTYPE_OTHER = 10;    //其它
        };

        ///启停车类型
        public static class E_SUD_TYPE
        {
            public static int GE_SUD_UNKNOWN = 0;      ///未知
            public static int GE_SUD_START = 1;       ///开车
            public static int GE_SUD_STOP = 2;       ///停车
        };

        /**历史趋势类型枚举
         */
        public static class TRENDTYPE
        {
            public static int GE_FIVEMINUTETREND = 0;   /*!五分钟趋势*/
            public static int GE_HALFHOURTREND = 1;     /*!三十分钟趋势*/
            public static int GE_HOURTREND = 2;         /*!小时趋势*/
            public static int GE_DAYTREND = 3;          /*!天趋势*/
            public static int GE_MONTHTREND = 4;        /*!月趋势*/
            public static int GE_QUARTERTREND = 5;      /*!季度趋势*/
            public static int GE_YEARTREND = 6;          /*!年趋势*/
            public static int GE_WEEKTREND = 7;          /*!周趋势*/
                                                         //public static  int GE_ONEMINUTETREND;    /*!一分钟趋势*/
                                                         //public static  int GE_TENMINUTETREND;    /*!十分钟时趋势*/
        };

        ///测点通道的大类。是振动，过程量，动态测点
        public static class E_TBL_CHANNTYPE
        {
            public static int E_TBL_CHANNTYPE_VIB = 0;         ///振动通道。“VIB”
            public static int E_TBL_CHANNTYPE_PROC = 1;          ///过程量通道。“PROC”
            public static int E_TBL_CHANNTYPE_DYN = 2;            ///动态测点通道。“DYN”
        };

        public static class E_TREND_TBL_TYPE
        {
            public static int GE_TREND_TBLTYPE_UNKNOWN = 0;     ///未知表类型
            public static int GE_TREND_TBLTYPE_SECOND = 1;      ///秒趋势表类型;理论上1秒一条记录
            public static int GE_TREND_TBLTYPE_HOUR = 2;          ///小时趋势表类型;理论上1分钟一条记录
            public static int GE_TREND_TBLTYPE_DAY = 3;           ///天趋势表类型，理论上20分钟一条记录
            public static int GE_TREND_TBLTYPE_MONTH = 4;         ///月趋势表类型，理论上3小时一条记录
        };

        /**@brief 用户级别枚举
         *       分厂级操作工只能察看所在分厂的设备运行状况;
         *       分厂级工程师可以察看所在分厂的设备运行状况，并且可以添加设备和修改参数，但是只限制在所在的分厂范围
         *       分厂级管理员可以操作所在分厂范围内的所有业务，添加删除用户和修改等级
         *       全厂级操作工察看全厂的设备运行状况;
         *       全厂级工程师可以察看所在全厂的设备运行状况，并且可以添加设备和修改参数
         *       全厂级管理员可以操作全厂范围内的所有业务，添加删除用户和修改等级
         */
        public static class USERLEVEL
        {
            public static int GE_LOCAL_OPERATOR = 1;  /*!分厂级操作工*/
            public static int GE_LOCAL_ENGINEER = 2;    /*!分厂级工程师*/
            public static int GE_LOCAL_ADMIN = 3;       /*!分厂级管理员*/
            public static int GE_WHOLE_OPERATOR = 4;    /*!全厂级浏览*/
            public static int GE_WHOLE_ENGINEER = 5;    /*!全厂级工程师*/
            public static int GE_WHOLE_ADMIN = 6;       /*!全厂级管理员*/
            public static int GE_WHOLE_EXPERT = 7;      /*!全厂级专家*/
            public static int GE_GROUP_OPERATOR = 8;    /*!集团级浏览*/
            public static int GE_GROUP_ENGINEER = 9;    /*!集团级工程师*/
            public static int GE_GROUP_ADMIN = 10;       /*!集团级管理员*/
            public static int GE_GROUP_EXPERT = 11;      /*!集团级专家*/
            public static int GE_EXPERT = 12;            /*!专家*/
            public static int GE_ADMIN = 13;             /*!管理人员*/
        };

        //风电机泵自定义特征值类型
        public static class E_KEYPUMPWIND_USERCHARTYPE
        {
            public static int GE_USER_AFREQ1 = 0;      ///速度功率谱0.5X倍频
            public static int GE_USER_AFREQ2 = 1;        ///速度功率谱5X倍频
            public static int GE_VF_ONEX = 2;            ///速度功率谱1X倍频
            public static int GE_VF_TWO = 3;             ///速度功率谱2X倍频
            public static int GE_VF_THREE = 4;           ///速度功率谱3X倍频
            public static int GE_VF_FOUR = 5;            ///速度功率谱4X倍频
            public static int GE_VF_BLADE = 6;           ///速度功率谱叶片通过频率
            public static int GE_USER_AENVFREQ1 = 7;     ///啮合频率
            public static int GE_USER_AENVFREQ2 = 8;     ///输出轴转频
            public static int GE_ENVSPECCF1 = 9;         ///内圈特征频率
            public static int GE_ENVSPECCF2 = 10;         ///外圈特征频率
            public static int GE_ENVSPECCF3 = 11;         ///保持架特征频率
            public static int GE_ENVSPECCF4 = 12;         ///滚动体特征频率
            public static int GE_GEARBOXSHAFTCF1 = 13;    ///齿轮箱I轴转频
            public static int GE_GEARBOXSHAFTCF2 = 14;    ///齿轮箱I轴转频
            public static int GE_GEARBOXSHAFTCF3 = 15;    ///齿轮箱I轴转频
            public static int GE_GEARBOXSHAFTCF4 = 16;     ///齿轮箱I轴转频
        };

    }
}
