/**�ֶ���
  *
  */
#ifndef   __FIXDEF_FIELD_DEFINE__
#define	  __FIXDEF_FIELD_DEFINE__

///�������������������ֶκ꣭������������������///

#define FIELD_SYSTEM_SUCCESS   1
#define FIELD_SYSTEM_FAILURE   0

///�������������������ֶ��룭������������������///

/**ͨƵ����ֵ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_OVERALLCHAR          10000

/**1��Ƶ����ֵ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_ONECHAR              10001

/**2��Ƶ����ֵ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_TWOCHAR              10002

/**3��Ƶ����ֵ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_THREECHAR            10003

/**1/2��Ƶ����ֵ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_HALFCHAR             10004

/**����������ֵ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_PROCESS              10005


/**��������ֵ
*���ͣ�float
*/
#define     FIELD_SERVICE_TREND_VALUE                10006

/**��λ������ֵ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_AXISDISPLACE         10007

/**����ֵ���͵�ö��,
  *���ͣ�����.
  *ֵ��Χ��ͨƵ����ֵΪ0��1��Ƶ����ֵΪ1��2��Ƶ����ֵΪ2��3��Ƶ����ֵΪ3��1/2��Ƶ����ֵΪ4
  */
#define     FIELD_SERVICE_TREND_CHARTYPE             10008

/**����ʱ��
  *����:�ַ���
  */
#define     FIELD_SERVICE_TIME                       10009

/*!�������,�����й�������㣬�����񶯲�㣬������ĳһ���������
  *���ͣ�int
  *ֵ��Χ��0-5
  *       GE_ALLPROC:���й��������;
  *	      GE_VIBCHANN:�񶯲��;
  *       GE_AXISCHANN:��λ�Ʋ��;
  *       GE_PRESSCHANN:ѹ�����;
  *       GE_TEMPCHANN:�¶Ȳ��;
  *       GE_FLUXCHANN:�������;
  *       GE_ONTHERCHANN:����.
  */
#define    FIELD_SERVICE_CHANNTYPE                   10010

/**��ȡ�������ݵ�Ƶ�����ݸ���
  *���ͣ�int
  */
#define     FIELD_SERVICE_FREQWAVE_NUM               10011

/**װ��ID�����ַ����ַ�������:83
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_SETID                      10012

/**����ID���Ǹ�5λ�ַ����ַ�������:83C102
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_PLANTID                    10013

/**���һ����λ�ַ����ַ���.��:1H
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_CHANN1                     10014

/**��������λ�ַ����ַ���.��:1H
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_CHANN2                     10015

/**��������ϣ��м��ԡ�,���ֿ�
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_CHANN_BUFF                 10016

/**����ַ���Buff�ĳ��ȣ����ַ��ĸ�����
  *���ͣ�int
  */
#define     FIELD_SERVICE_CHANN_BUFFSIZE             10017

/**������
  *���ͣ�int
  */
#define     FIELD_SERVICE_CHANN_NUM                  10018


/**����ID2���Ǹ�5λ�ַ����ַ�������:83C102
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_PLANTID2                    10019

/**���һ����ֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_CHANN1VALUE                10020

/**��������ֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_CHANN2VALUE                10021

/**ϸ���׵���������
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ZOOMSPECTRUM               10022

/**���ʵʱ������һ���������ݵĸ���
  *���ͣ�int
  */
#define     FIELD_SERVICE_TIMEWAVE_NUM               10023

/**Ƶ�׵�df��һ�������ͬһʱ�̵�Ƶ��df��һ��
  *���ͣ�float
  */
#define     FIELD_SERVICE_FREQWAVE_DF                10024

/**ϸ���׵ķ�������
  *���ͣ�int
  */
#define     FIELD_SERVICE_ZOOM_LINES                 10025

/**ϸ���׵���ʼƵ��
  *���ͣ�float
  */
#define     FIELD_SERVICE_ZOOM_STARTFREQ             10026

/**ϸ���׵���ֹƵ��
  *���ͣ�int
  */
#define     FIELD_SERVICE_ZOOM_STOPFREQ              10027


/**һ������λ�õ�ˮƽ���ID����λ�ַ����ַ���.��:1V
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_CHANNID_HOR                10028

/**һ������λ�õĴ�ֱ���ID����λ�ַ����ַ���.��:1H
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_CHANNID_VER                10029

/**���Ĺ켣�Ĳ������ݣ���ֱ���������ݡ�
  *���ͣ�float����
  */
#define     FIELD_SERVICE_AXESTRACK_WAVE_VER         10030

/**���Ĺ켣�Ĳ������ݣ�ˮƽ���������ݡ�
  *���ͣ�float����
  */
#define     FIELD_SERVICE_AXESTRACK_WAVE_HOR         10031

/**���Ĺ켣��һ���Ĳ������ݸ���
  *���ͣ�int
  */
#define     FIELD_SERVICE_AXESTRACK_WAVENUM          10032

/**����λ�õĴ�ֱ����ֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_AXESLOCATION_VER           10033

/**����λ�õ�ˮƽ����ֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_AXESLOCATION_HOR           10034

/**����ת��.
  *���ͣ�float
  */
#define     FIELD_SERVICE_REV                        10035

/**����ת��2.
  *���ͣ�float
  */
#define     FIELD_SERVICE_REV2                       10036

/**���һ��λ
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_CHANN1_UNIT                10037

/**������λ.��:MPa
  *���ͣ��ַ���
  */
#define     FIELD_SERVICE_CHANN2_UNIT                10038

/**��������б��
  *���ͣ�int
  */
#define     FIELD_SERVICE_CHANN1_LIST                10041

/**���������״̬��ע��0��ʾû�б�����1��ʾ���ڱ���״̬
  *���ͣ�int
  */
#define     FIELD_SERVICE_CHANN1_STATUS              10042

/**������λֵ
 *���ͣ�float
 */
#define     FIELD_SERVICE_TREND_PHASE                10043

/**����1X��λֵ
*���ͣ�float
*/
#define     FIELD_SERVICE_TREND_ONEPHASE             10044

/**����2X��λֵ
*���ͣ�float
*/
#define     FIELD_SERVICE_TREND_TWOPHASE             10045

/**ֱ����
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_DC2                  10046

/**��϶��ѹ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_GAP2                 10047


/**��������ֵ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_RESCHAR              10048

/**ֱ����
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_DC                   10049

/**��϶��ѹ
  *���ͣ�float
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_TREND_GAP                   10050

/**�������ͨ���࣬������Ҫ���Ͷ�Σ��Ƕ෢�͵����һ����Ҫ�������ʶ��Ϊ1�����������Ϊ0
  */
#define     FIELD_SERVICE_SEND_END                   10051

/**�Ƿ���Ҫͨ����Ϣ
  *���ͣ�int
  */
#define     FIELD_SERVICE_IFCHANN               10052

/**����ֵ�ṹ��
  *���ͣ�����ֵ�ṹ��
  *ֵ��Χ��FIELD_SERVICE_TREND_CHARVALUE
  */
#define     FIELD_SERVICE_CHARVALUE_S           10053

/**����ֵ�ṹ��2
  *���ͣ�����ֵ�ṹ��
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_CHARVALUE_S2          10054

/**����ֵ�ṹ���buffer
*���ͣ�ָ�룬ָ��n������ֵ�ṹ���buffer
*/
#define     FIELD_SERVICE_CHARVALUE_SBUFF       10055

/**��������ֵ��buffer
*���ͣ�ָ�룬ָ��n����������������ֵ��buffer
*/
#define     FIELD_SERVICE_TREND_VALUE_BUFF      10056

/**�¼�ID
  *���ͣ�����
  */
#define     FIELD_SYSTEM_EVENT_ID                10057

/**���͵�buffer
*���ͣ�ָ�룬ָ��n���������������͵�buffer
*/
#define     FIELD_SERVICE_TYPE_BUFF              10058


/**������Ϣ
*���ͣ�int
*/
#define     FIELD_SERVICE_LEN                    10059
/**�¼�����
  *����:int
  */
#define     FIELD_SYSTEM_EVENT_TYPE              10060

/**��־ID
  *���ͣ�����
  */
#define     FIELD_SYSTEM_ID                      10061

/**���һ��Ӧ��ʵʱ��������
  *���ͣ�float����
  */
#define     FIELD_SERVICE_TIMEWAVE1                  10080

/**������Ӧ��ʵʱ��������
  *���ͣ�float����
  */
#define     FIELD_SERVICE_TIMEWAVE2                  10081

/**���һ��Ӧ��ʵʱ����Ƶ�����ݣ������ǲ������ݵ�һ��
  *���ͣ�float����
  */
#define     FIELD_SERVICE_FREQWAVE1                  10082

/**������Ӧ��ʵʱ����Ƶ������
  *���ͣ�float����
  */
#define     FIELD_SERVICE_FREQWAVE2                  10083

/**��������ѹ������ֽ�����ʾ��
  *���ͣ�long
  */
#define     FIELD_SERVICE_ZIPWAVE_BYTESNUM           10084

/**��������ѹ������ֽ�����ʾ��1
*���ͣ�long
*/
#define     FIELD_SERVICE_ZIPWAVE_BYTESNUM1          10085

/**��ʾ΢��
  *���ͣ�int
  */
#define    FIELD_SERVICE_MICROSECOND                 10086

/**����ת��3.
*���ͣ�float
*/
#define     FIELD_SERVICE_REV3                       10087

/**����ת��4.
*���ͣ�float
*/
#define     FIELD_SERVICE_REV4                       10088


/**����ת��5.
*���ͣ�float
*/
#define     FIELD_SERVICE_REV5                       10089

/**�豸��.
*���ͣ�int
*/
#define     FIELD_SERVICE_PLANT_NUM                  10090

/**�����豸��.
*���ͣ�int
*/
#define     FIELD_SERVICE_ALARM_PLANTNUM             10091

/**�����豸��.
*���ͣ�int
*/
#define     FIELD_SERVICE_RUN_PLANTNUM               10092

/**ͣ���豸��.
*���ͣ�int
*/
#define     FIELD_SERVICE_STOP_PLANTNUM              10093

/**����ID.
*���ͣ�string
*/
#define     FIELD_SERVICE_ALARMID                    10094

/**��ʼ����.
*���ͣ�int
*/
#define     FIELD_SERVICE_STARTINDEX                 10095

/**��������
*���ͣ�int
*/
#define     FIELD_SERVICE_ENDINDEX                   10096

/*�������׸׺�
*���ͣ�int
*/
#define     FIELD_SERVICE_CYLINDERNO                 10097

/*�ǶȲ���1
*���ͣ�float
*/
#define     FIELD_SERVICE_ANGLEPARAM1                 10098

/*�ǶȲ���2
*���ͣ�float
*/
#define     FIELD_SERVICE_ANGLEPARAM2                 10099

/*�ǶȲ���3
*���ͣ�float
*/
#define     FIELD_SERVICE_ANGLEPARAM3                 10100

/*�ǶȲ���4
*���ͣ�float
*/
#define     FIELD_SERVICE_ANGLEPARAM4                 10101

/**������2��ϣ��м��ԡ�,���ֿ�
*���ͣ��ַ���
*/
#define     FIELD_SERVICE_CHANN_BUFF2                 10102

/**���2�ַ���Buff�ĳ��ȣ����ַ��ĸ�����
*���ͣ�int
*/
#define     FIELD_SERVICE_CHANN_BUFFSIZE2             10103

/**���2����
*���ͣ�int
*/
#define     FIELD_SERVICE_CHANN_NUM2                 10104

/**������3��ϣ��м��ԡ�,���ֿ�
*���ͣ��ַ���
*/
#define     FIELD_SERVICE_CHANN_BUFF3                 10105

/**���3�ַ���Buff�ĳ��ȣ����ַ��ĸ�����
*���ͣ�int
*/
#define     FIELD_SERVICE_CHANN_BUFFSIZE3             10106

/**���3����
*���ͣ�int
*/
#define     FIELD_SERVICE_CHANN_NUM3                  10107

/**��ֱ���ζ�Ӧ��Ƶ��
*���ͣ�double
*/
#define     FIELD_SERVICE_VERFREQ                     10108

/**��ֱ���ζ�Ӧ�ķ�ֵ
*���ͣ�double
*/
#define     FIELD_SERVICE_VERAMP                      10109

/**��ֱ���ζ�Ӧ����λ
*���ͣ�double
*/
#define     FIELD_SERVICE_VERPHASE                     10110

/**ˮƽ���ζ�Ӧ��Ƶ��
*���ͣ�double
*/
#define     FIELD_SERVICE_HORFREQ                     10111

/**ˮƽ���ζ�Ӧ�ķ�ֵ
*���ͣ�double
*/
#define     FIELD_SERVICE_HORAMP                      10112

/**ˮƽ���ζ�Ӧ����λ
*���ͣ�double
*/
#define     FIELD_SERVICE_HORPHASE                     10113

/**��������
*���ͣ�float
*/
#define     FIELD_SERVICE_ALARM_LOW                     10114

/**��������
*���ͣ�float
*/
#define     FIELD_SERVICE_ALARM_HIGH                    10115

/**���Ĺ켣Բ��X����
*���ͣ�float
*/
#define     FIELD_SERVICE_AXIS_COORX                    10116

/**���Ĺ켣Բ��Y����
*���ͣ�float
*/
#define     FIELD_SERVICE_AXIS_COORY                    10117

/**������Բˮƽ��뾶
*���ͣ�float
*/
#define     FIELD_SERVICE_HOR_RADIUS                    10118

/**������Բ��ֱ��뾶
*���ͣ�float
*/
#define     FIELD_SERVICE_VER_RADIUS                    10119


/******************ֻ�ж�ȡ��ʷ������Ҫ���ֶ���**************************************/

/**��ȡ��ʷ����ʱ�����һ��ID
  *���ͣ�string
  */
#define     FIELD_SERVICE_OFF_CHANN1                 11000

/**��ȡ��ʷ����ʱ��������ID
  *���ͣ�string
  */
#define     FIELD_SERVICE_OFF_CHANN2                 11001

/**��ȡ��ʷ����ʱ��ʱ��ֵ
  *���ͣ�DateTime
  */
#define     FIELD_SERVICE_OFF_TIME                   11002


/**��ȡ��ʷ����ʱ��ʱ��ֵ2
  *���ͣ�DateTime
  */
#define     FIELD_SERVICE_OFF_TIME2                  11003

/**��ȡ��ʷ����ʱ�����һ��IDֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_OFF_CHANN1VALUE            11004

/**��ȡ��ʷ����ʱ��������IDֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_OFF_CHANN2VALUE            11005


/**�������͵�ö��.
  *���ͣ�����.
  *ֵ��Χ��Сʱ0����1����2����3����4.
  */
#define     FIELD_SERVICE_OFF_TRENDTYPE              11009

/**��ѯ��¼ʱ�����ʼ����ʱ��
  *���ͣ�ʱ��
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_OFF_TIMESTART              11010

/**��ѯ��¼ʱ�����ֹ����ʱ��
  *���ͣ�ʱ��
  *ֵ��Χ��
  */
#define     FIELD_SERVICE_OFF_TIMEEND                11011

/**��ȡ��ʷ����ʱһ����Ӧ���Ƶ��IDֵ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_OFF_FREQWAVE               11012

/**��ȡ��ʷ����ʱһ����Ӧ��Ĳ������ݸ���
  *���ͣ�int
  */
#define     FIELD_SERVICE_OFF_WAVE_NUM               11013

/**��ȡ��ʷ����ʱһ����Ӧ���Ƶ��DF��IDֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_OFF_FREQWAVE_DF            11014

/**��ȡ��ʷ����ʱһ����Ӧ��Ĳ�������
*���ͣ�float����
*/
#define     FIELD_SERVICE_OFF_WAVE                   11015

/*!�������,�����й�������㣬�����񶯲�㣬������ĳһ���������
  *���ͣ�int
  *ֵ��Χ��0-10
  */
#define    FIELD_SERVICE_OFF_CHANNTYPE               11016

/**��ȡ��ʷ����ʱһ����Ӧ���Ƶ�����ݸ���
  *���ͣ�int
  */
#define     FIELD_SERVICE_OFF_FREQWAVE_NUM           11017

/**��ȡ��Ӧ�Ĳ�������ʱҪ���Ƶ�׷�������
  *���ͣ�int
  *ֵ��Χ��400��800��1600...
  */
#define     FIELD_SERVICE_OFF_FREQANALYSIS_LINES     11018

/**����Ƶ�׷�����ʵ������
  *���ͣ�int
  *ֵ��Χ��400��800��1600...
  */
#define     FIELD_SERVICE_OFF_FACT_ANALYSISLINES     11019

/*!��ͣ����¼�ķ�ֵ
  *���ͣ�float
  */
#define    FIELD_SERVICE_OFF_AMP                     11020

/*!��ͣ����¼����λ
  *���ͣ�float
  */
#define    FIELD_SERVICE_OFF_PHASE                   11021


/**��ȡ��ʷ����ʱ�����һ����λֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_OFF_CHANN1PHASE            11022

/**��ȡ��ʷ����ʱ����������λֵ
  *���ͣ�float
  */
#define     FIELD_SERVICE_OFF_CHANN2PHASE            11023

/**��ȡ������Ϣʱʹ�ã����޽ṹ��
  *���ͣ��ṹ��
  */
#define     FIELD_SERVICE_THRESHOLD                  11024

/**��ȡ�������޽ṹ��Buff
  *���ͣ��ṹ��Buff
  */
#define     FIELD_SERVICE_THRESHOLD_BUFF             11025

/**��ֵ����ID
  *���ͣ�int
  */
#define     FIELD_SERVICE_THRESHOLD_ID               11026

/**ѧϰ����BUFF
  *���ͣ��ṹ��
  */
#define     FIELD_SERVICE_LEARNPARAM_BUFF            11027

/**��������
  ���ͣ�int
  */
#define     FIELD_SERVICE_ALARM_TYPE                 11028

/*!��Ӧ�����ת��
  *���ͣ�int
  */
#define    FIELD_SERVICE_OFF_REV                     11030

/*!��Ӧ�����ת��2
  *���ͣ�int
  */
#define    FIELD_SERVICE_OFF_REV2                    11031

/*ת��BUFF
  *���ͣ��ṹ��
  */
#define     FIELD_SERVICE_REV_BUFF                   11032

/* ����
  *���ͣ�float
  */
#define    FIELD_SERVICE_OFF_DATA                    11033





/****************���ܳ�����ʵʱ���ݵ��ֶ���***********/

/**���������񶯲��һ��Ƶ����λ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_ONEVIBPHASE        14000

/**���������񶯲���ʵʱ��������
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_VIBWAVE            14001

/**���͵�ʵʱ�������ݵ��������������񶯲����Ŀ
  *���ͣ�int
  */
#define     FIELD_SERVICE_ON_SEND_VIBCHANNNUM        14002

/**����ʵʱ�������ݵĲɼ���������һ�鲨�εĸ���
  *���ͣ�int
  */
#define     FIELD_SERVICE_ON_SEND_WAVEPOINTNUM       14003

/**���͵���λ�����ݸ���������λ�Ʋ����Ŀ
  *���ͣ�int
  */
#define     FIELD_SERVICE_ON_SEND_AXISCHANNNUM       14004

/**���͵Ĺ��������ݸ������������������Ŀ
  *���ͣ�int
  */
#define     FIELD_SERVICE_ON_SEND_PROCCHANNNUM       14005

/**���͵�������λ������
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_AXISLOCATION       14006

/**�������й�������������״̬
  *���ͣ�����״̬�ṹ�����顣
  */
#define     FIELD_SERVICE_ON_SEND_ALLPROCSTATE       14007

/**���������񶯲�������״̬���Ƕ�ͨƵ���������жϣ�
  *���ͣ�����״̬�ṹ������
  */
#define     FIELD_SERVICE_ON_SEND_ALLVIBSTATE        14008

/**����������λ�ò�������״̬
  *���ͣ�����״̬�ṹ�����顣
  */
#define     FIELD_SERVICE_ON_SEND_AXISLOCATIONSTATE  14009

/**�������л����ת��
  *���ͣ�int
  */
#define     FIELD_SERVICE_ON_SEND_REV                14010

/**�����
  *����:string
  */
#define     FIELD_SERVICE_ON_SEND_PLANTID            14011

/**��������ʵʱ�񶯲��ͨƵ����ֵ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_ALLCHARVALUE       14012

/**��������ʵʱ�񶯲�����Ƶ����ֵ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_TWOCHARVALUE       14013

/**��������ʵʱ�񶯲������ƵƵ����ֵ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_THREECHARVALUE     14014

/**��������ʵʱ�񶯲��һ��ƵƵ����ֵ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_HALFCHARVALUE      14015

/**��������ʵʱ�񶯲��һ��Ƶ����ֵ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_ONECHARVALUE       14016

/**��������ʵʱ�񶯲����λ������ֵ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_AXISDISPLACE       14017

/**�������й�������ֵֵ
  *���ͣ�float����
  */
#define     FIELD_SERVICE_ON_SEND_ALLPROCVALUE       14018

/**��������ʵʱ����ʱ����ʼ����
  *���ͣ�int
  */
#define     FIELD_SERVICE_ON_SEND_STARTID            14019

/**���м���ϵõ�ָ��������͵�����ʵʱ����
  *���ͣ�int
  */
#define     FIELD_SERVICE_ON_SEND_CHANNTYPE          14020

/**����Ƶ��
  *���ͣ�int
  */
#define    FIELD_SERVICE_SAMPLE_FREQ                 14021

/**��������
*���ͣ�int
*/
#define    FIELD_SERVICE_SAMPLE_NUM                  14022

/**��ͣ��״̬��־λ��
  *���ͣ�int
  */
#define    FIELD_SERVICE_SUD_STATUS                  14023

/**��ͣ������,��ͣ������ E_SUD_TYPE
*���ͣ�int
*/
#define    FIELD_SERVICE_SUD_TYPE                    14024

/**���������񶯲�����Ƶ����λ
*���ͣ�float����
*/
#define    FIELD_SERVICE_ON_SEND_TWOVIBPHASE        14025

/**���������񶯲������Ƶ����λ
*���ͣ�����������
*/
#define   FIELD_SERVICE_ON_SEND_THREEVIBPHASE       14026

/**���������񶯲��ֱ�Ƶ����λ
*���ͣ�float����
*/
#define   FIELD_SERVICE_ON_SEND_HALFVIBPHASE        14027

/**���������񶯲�����ֵ
*���ͣ�float����
*/
#define   FIELD_SERVICE_ON_SEND_RESCHARVALUE        14028

/**����״̬��־λ
*���ͣ�int
*/
#define    FIELD_SERVICE_ALARM_STATUS               14029

/**���͵Ķ�̬���ݸ���������̬�����Ŀ
*���ͣ�int
*/
#define     FIELD_SERVICE_ON_SEND_DYNCHANNNUM       14030

/**�������ж�̬��������״̬
*���ͣ�����״̬�ṹ�����顣
*/
#define     FIELD_SERVICE_ON_SEND_ALLDYNSTATE        14031

/**--------------ϵͳ�����ܵ����ֶ���--------------**/

/**�û���
  *���ͣ�string
  */
#define     FIELD_SYSTEM_USEID                        15000

/**�û�����
  *���ͣ�string
  *ֵ��Χ��
  */
#define     FIELD_SYSTEM_PASSWORD                     15001

/**װ�ú�
  *���ͣ�string
  */
#define     FIELD_SYSTEM_SET                          15002

/**�ֳ���
  *���ͣ�string
  */
#define     FIELD_SYSTEM_FACTORY                      15003

/**��˾��
  *���ͣ�string
  */
#define     FIELD_SYSTEM_COMPANY                      15004

/**����λ��
  *���ͣ�string
  */
#define     FIELD_SYSTEM_PLANT                        15005

/**������
  *���ͣ�string
  */
#define     FIELD_SYSTEM_GROUP                        15006

/**���λ������
  *���ͣ�string
  */
#define     FIELD_SYSTEM_AXISLOCATION                 15007

/**�������ͱ�ʾ��
  *���ͣ�����
  */
#define     FIELD_SYSTEM_TYPE                         15008

/**�����
  *���ͣ�string
  */
#define     FIELD_SYSTEM_CHANN                        15009

/**�������
  *���ͣ�int
  *ֵ��Χ��1�����񶯲�㣬2������λ�ƣ�3����ѹ����4�����¶ȣ�5����������
  */
#define     FIELD_SYSTEM_CHANN_TYPE                   15010

/**�񶯲����Ŀ
  *���ͣ�int
  */
#define     FIELD_SYSTEM_VIBCHANN_NUM                 15011

/**��λ�Ʋ����Ŀ
  *���ͣ�int
  */
#define     FIELD_SYSTEM_AXISCHANN_NUM                15012

/**���������Ŀ
  *���ͣ�int
  */
#define     FIELD_SYSTEM_FLUXCHANN_NUM                15013

/**ѹ�������Ŀ
  *���ͣ�int
  */
#define     FIELD_SYSTEM_PRESSCHANN_NUM               15014

/**�¶Ȳ����Ŀ
  *���ͣ�int
  */
#define     FIELD_SYSTEM_TEMPCHANN_NUM                15015

/**���������Ŀ
  *���ͣ�int
  */
#define     FIELD_SYSTEM_OTHERCHANN_NUM               15016

/**��ֱ�������
  *���ͣ�string
  */
#define     FIELD_SYSTEM_CHANN_VER                    15017

/**ˮƽ�������
  *���ͣ�string
  */
#define     FIELD_SYSTEM_CHANN_HOR                    15018

/**����ָ���������߷���������Ӧ�ĺ궨��
  *����:int
  */
#define     FIELD_SYSTEM_ANALYSISLINES                15019


/**����ĳ�ֲ���ʱ�ķ���״̬�������޸�����󷵻�״̬�Ƿ��޸�
  *���ͣ�int
  */
#define     FIELD_SYSTEM_STATUS                       15020

/**����ĳ����Ҫ�ַ����Ĳ��������磺�޸�����ʱ��������
  *���ͣ�string
  */
#define     FIELD_SYSTEM_RESERVE_STRING               15021

/**�ͻ��˲쿴ʵʱ����ʱ�ĸ���ʱ�������
  *���ͣ�int
  */
#define     FIELD_SYSTEM_REFRESHTIME                  15022

/**��������
  *����:float
  */
#define     FIELD_SYSTEM_ALARM_HIGH                   15023

/**��������
  *����:float
  */
#define     FIELD_SYSTEM_ALARM_LOW                    15024

/**@brief �û�����
  *type: int
  *value range:����DSE_Define.h�й����û��ȼ���ö��
  */
#define     FIELD_SYSTEM_USER_LEVEL                   15025


/**@brief �û�ID�����޸������û��ȼ���������û�ʱʹ��
  *type: string
  */
#define     FIELD_SYSTEM_MODIFY_USER                  15026

/**@brief ״̬����
  *type: string
  */
#define     FIELD_SYSTEM_STATUS_DISCRIPTION           15027

/**@brief �ж��Ƿ����װ��
  *type:int
  */
#define     FIELD_SYSTEM_BROWSE_SET                   15028

/**@brief ��������
  *type:int
  */
#define     FIELD_SYSTEM_SAMPLE_NUM                   15029

/**@brief ����Ƶ��
  *type:int
  */
#define     FIELD_SYSTEM_SAMPLE_FREQ                  15030

/**@brief �����ն�IP
  *type:string
  */
#define     FIELD_SYSTEM_DAQIP                        15031

/**������
  *type��string
  */
#define    FIELD_SYSTEM_CHANN_ALIAS                   15032

/**@brief ����ת��
  *type:int
  */
#define     FIELD_SYSTEM_PLANT_REV                    15033

/**��òͼ����
  *type:int
  */
#define     FIELD_SYSTEM_PLANT_GRAPHTYPE              15034


/**�ֳ���2
  *���ͣ�string
  */
#define     FIELD_SYSTEM_FACTORY2                      15035

/**��˾��2
  *���ͣ�string
  */
#define     FIELD_SYSTEM_COMPANY2                      15036

/**��������2
  *����:float
  */
#define     FIELD_SYSTEM_ALARM_HIGH2                   15037

/**��������2
  *����:float
  */
#define     FIELD_SYSTEM_ALARM_LOW2                    15038

/**����������
  *���ͣ�int
  *ֵ��Χ����ö�ٶ���
  */
#define     FIELD_SYSTEM_SENSOR_TYPE                   15039

/**�����òͼBUFF
  *���ͣ�BUFF
  */
#define    FIELD_SYSTEM_PLANT_GRAPHTYPE_BUFF          15040

/**�����òͼBUFF��С
  *���ͣ�int
  */
#define    FIELD_SYSTEM_PLANT_GRAPHTYPE_BUFFSIZE      15041

/**���2����
*type��string
*/
#define    FIELD_SYSTEM_CHANN2_ALIAS                   15042

/**��������3
*����:float
*/
#define     FIELD_SYSTEM_ALARM_HIGH3                   15043

/**��������3
*����:float
*/
#define     FIELD_SYSTEM_ALARM_LOW3                    15044

/**����ֵ�ṹ��
  *���ͣ�����ֵ�ṹ��
  *ֵ��Χ������ʵ��������������������񶯲�������ֵ�ṹ�廹�Ƕ�̬��������ֵ�ṹ��
  */
#define     FIELD_SYSTEM_CHARVALUE_S                  15045


/**���ż��м��������IP
*���ͣ�string
*/
#define   FIELD_SYSTEM_GROUP_MW_IP                    15136

/**���ż��м���������˿�
*���ͣ�int
*/
#define   FIELD_SYSTEM_GROUP_MW_PORT                  15137

/**��˾���м��������IP
  *���ͣ�string
  */
#define   FIELD_SYSTEM_COMPANY_MW_IP                  15138

/**��˾���м���������˿�
  *���ͣ�int
  */
#define   FIELD_SYSTEM_COMPANY_MW_PORT                15139

/**�м��������IP
  *���ͣ�string
  */
#define   FIELD_SYSTEM_MW_IP                          15140

/**�м���������˿�
  *���ͣ�int
  */
#define   FIELD_SYSTEM_MW_PORT                        15141

/**�������ݵ�������ĵ�ʱ����
  *���ͣ�int
  */
#define   FIELD_SYSTEM_SENDC_INTERVAL                 15142

/**�Ƿ������ݵ��������
  *���ͣ�int
  */
#define   FIELD_SYSTEM_SENDC_IF                       15143


/**�ֳ�����
  *���ͣ�string
  */
#define   FIELD_SYSTEM_SUBCORP_ALIAS                  15144

/**װ�ü��м��ID
  *���ͣ�string
  */
#define   FIELD_SYSTEM_MW_ID                          15145


/**װ�ü��м���豸��Ϣ
  *���ͣ��ṹ������
  */
#define   FIELD_SYSTEM_SETSVR_PLANTINFO              15146

/**װ�ü��м���豸�Ĳ����Ϣ
  *���ͣ��ṹ������
  */
#define   FIELD_SYSTEM_SETSVR_CHANNINFO              15147

/**������ʷ��ͣ�����ݵ�������ĵ�ʱ����
*���ͣ�int
*/
#define   FIELD_SYSTEM_SUD_SENDC_INTERVAL            15148

/**������ʷ�������ݵ�������ĵ�ʱ����
*���ͣ�int
*/
#define   FIELD_SYSTEM_ALARM_SENDC_INTERVAL           15149

/**װ�ü��м������Ϣ
*���ͣ��ṹ��
*/
#define   FIELD_SYSTEM_SETSVR_SETINFO                 15150

/**�汾��Ϣ
*���ͣ�������
*/
#define   FIELD_SYSTEM_VERSION                        15151

/**�Զ������ģ��ID
*���ͣ�string
*/
#define FIELD_SYSTEM_TEMPID                          15152

/**��������
*���ͣ�int
*/
#define  FIELD_SYSTEM_DATA                           15153

/**��������
*���ͣ�int
*/
#define  FIELD_SYSTEM_UNIT                           15154

/**�źŷ�����ʽ
*���ͣ�int
*/
#define  FIELD_SYSTEM_SIGNAL_TYPE                    15155

/**�źŷ�����ʽ
*���ͣ�int
*/
#define  FIELD_SYSTEM_SEG_STARTNO                    15156

/**����
*���ͣ�int
*/
#define  FIELD_SYSTEM_SEG_NUM                        15157

/**������ʼֵ
*���ͣ�float
*/
#define FIELD_SYSTEM_START_VALUE                     15158

/**���ݽ���ֵ
*���ͣ�float
*/
#define  FIELD_SYSTEM_END_VALUE                      15159

/**����ֵ����
*���ͣ�int
*/
#define   FIELD_SYSTEM_CHAR_TYPE                     15160

/**�Զ��屨��ģ��ID
*���ͣ�string
*/
#define   FIELD_SYSTEM_ALARM_TEMPID                  15161

/**�Զ��屨������
*���ͣ�string
*/
#define   FIELD_SERVICE_ALARM_DISCRIPTION            15162

/**�Ƿ񱨾�
*���ͣ�int
*/
#define   FIELD_SYSTEM_IF_ALARM                      15163

/**������
*���ͣ�int
*/
#define  FIELD_SYSTEM_ALARM_GROUP                    15164

/**���������Զ�������ķֶ�����
*���ͣ�string
*/
#define  FIELD_SYSTEM_SEG_NAME                       15165

/**����Ƶ����ʼֵ
*���ͣ�float
*/
#define FIELD_SYSTEM_BAND_STARTVALUE                  15166

/**����Ƶ������ֵ
*���ͣ�float
*/
#define  FIELD_SYSTEM_BAND_ENDVALUE                   15167

/**����Z12�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ12                      15168

/**����Z21�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ21                      15169

/**����Z22�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ22                      15170

/**����Z31�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ31                      15171

/**����Z32�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ32                      15172

/**����Z41�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ41                      15173

/**����Z42�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ42                      15174

/**����Z51�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ51                      15175

/**����Z52�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ52                      15176

/**����Z61�ĳ���
*���ͣ�int
*/
#define  FIELD_SYSTEM_GEARNUMZ61                      15177

/** ����Դ
*���ͣ�int(GE_DATA_SOURCE_EN)
*/
#define  FIELD_SYSTEM_DATASOURCE                      15178

/**--------------ר��ϵͳ���ܵ����ֶ���--------------**/

/**��ʵ����ID
*���ͣ�string
*/
#define     FIELD_SERVICE_EX_RULEID                   16000

/**��ʵ����ID��Ӧ��ֵ
*���ͣ�int
*/
#define     FIELD_SERVICE_EX_IDVALUE                  16001

//////-----------------------------------/////////////
#endif
