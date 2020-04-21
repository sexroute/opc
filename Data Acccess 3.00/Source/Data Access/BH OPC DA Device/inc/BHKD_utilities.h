/**@brief
  *GD_ ����ȫ�ֺ궨��
  *GE_ ����ȫ��ö�ٶ���
  *@author Marble
  */

#ifndef _BHKD_G_UTILITIES_H_MARBLE_
#define _BHKD_G_UTILITIES_H_MARBLE_
#include <string>
using namespace std;
///ȫ�ֵ�ö�ٶ���ͺ궨��
#include "DSE_Define.h"

extern CString g_strMainDbName;
extern int g_iDbType;
//void SwichDbName(CCustomDB *pDB_,CString sDbName_);

#ifdef _EXTBHKD
#define _BHKD_EXT_	__declspec(dllexport)
#else	
#define _BHKD_EXT_	__declspec(dllimport)
#endif

namespace BHKD
{

#define DataIsMiddle(a,low,high)  ( ((a)>(low)) && ((a)<(high)) )

#define KD_DeletePoint(pt)          { if(NULL != (pt)) { delete [] (pt); (pt)=NULL;} }


//ÿ��ͨ���жϱ���������ֵ������Ŀ
#define D_BHKD_ALARM_CHARTYPE_NUM 10
	//���������ֶκ궨��
#define D_BHKD_AT_FAST            0x01000000       //���
#define D_BHKD_AT_SLOW            0x02000000       //����
#define D_BHKD_AT_TREND           0x04000000       //����
#define D_BHKD_AT_REGULAR         0x08000000       //���汨��

#define D_BHKD_AT_LOCATION        0x00010000       //����λ�ñ���
#define D_BHKD_AT_TEMP            0x00020000       //�¶�
#define D_BHKD_AT_PRESS           0x00040000       //ѹ��
#define D_BHKD_AT_FLUX            0x00080000       //����
#define D_BHKD_AT_OTHERPROC       0x00100000       //�������͹�����
#define D_BHKD_AT_RADIALVIB       0x00200000       //������
#define D_BHKD_AT_AXISVIB         0x00400000       //������
#define D_BHKD_AT_DYN             0x00800000       //��̬�ź�ͨ����ͨ��������11~20


#define D_BHKD_AT_PHASEONE        0x00000100       //1X��λ
#define D_BHKD_AT_PHASETWO        0x00000200       //2X��λ
#define D_BHKD_AT_PHASETHREE      0x00000400       //3X��λ
#define D_BHKD_AT_PHASEHALF       0x00000800       //1/2X��λ
#define D_BHKD_AT_TRENDHOUR       0x00001000       //Сʱ���Ʊ���
#define D_BHKD_AT_TRENDDAY        0x00002000       //�����Ʊ���
#define D_BHKD_AT_TRENDMONTH      0x00004000       //�����Ʊ���
#define D_BHKD_AT_TRENDSEASON     0x00008000       //�������Ʊ���

#define D_BHKD_AT_CHARONE         0x00000100       //1X����ֵ
#define D_BHKD_AT_CHARTWO         0x00000200       //2X����ֵ
#define D_BHKD_AT_CHARTHREE       0x00000400       //3X����ֵ
#define D_BHKD_AT_CHARHALF        0x00000800       //1/2X����ֵ
#define D_BHKD_AT_CHARRES         0x00001000       //��������ֵ
#define D_BHKD_AT_CHARALL         0x00002000       //ͨƵ����ֵ
#define D_BHKD_AT_DC              0x00010000       //ֱ����
#define D_BHKD_AT_GAP             0x00020000       //��϶��ѹ
#define D_BHKD_AT_AXISDISPLACE    0x00004000       //��λ�Ʊ���
#define D_BHKD_AT_REGHIGH         0x00008000       //������ޱ���
#define D_BHKD_AT_REGLOW          0x00000000       //������ޱ���

#define D_BHKD_AT_TRENDSLOWASC    0x00000001       //���ƻ�������
#define D_BHKD_AT_TRENDFASTASC    0x00000002       //���ƽϿ�����
#define D_BHKD_AT_TRENDSLOWDSC    0x00000004       //���ƻ�������
#define D_BHKD_AT_TRENDFASTDSC    0x00000008       //���ƽϿ콵��

#define D_BHKD_AT_CUSTOM          0x10000000       //�Զ��屨��
#define D_BHKD_AT_CUSTOMLOW       0x20000000       //�Զ�����ޱ���
#define D_BHKD_AT_CUSTOMHIGH      0x20008000       //�Զ�����ޱ���

//�����ֶεĳ���
const int D_BHKD_COMPANYNAME_LEN =   100;  ///��˾������
const int D_BHKD_FACTORYNAME_LEN =   100;  ///�ֳ�������
const int D_BHKD_SETID_LEN       =   20;   ///�м��������ID����
const int D_BHKD_PLANTID_LEN     =   50;   ///�豸ID����
const int D_BHKD_PLANTNO_LEN     =   10;   ///�豸NO����
const int D_BHKD_CHANNID_LEN     =   50;   ///ͨ��ID����
const int D_BHKD_CHANNNO_LEN     =   10;   ///ͨ��NO����
const int D_BHKD_CHANNALIAS_LEN  =   100;  ///ͨ����������
const int D_BHKD_IP_LEN          =   30;   ///IP����

	typedef float DATATYPE_CHAR;
	typedef short DATATYPE_WAVE;
	typedef DATATYPE_WAVE * PDATATYPE_WAVE;
	typedef unsigned int   DATATYPE_ALARMSTATE;
	typedef int DATATYPE_INT;

	//ÿ��ͨ�������ж����� 10�� �궨��"BHKD_ALARMCHAR_NUM" �������ö�ٵ���Ŀ
	enum E_ALARM_CHARTYPE
	{
		E_TH_ALLCHAR=0,
		E_TH_ONECHAR,
		E_TH_TWOCHAR,
		E_TH_THREECHAR,
		E_TH_HALFCHAR,
		E_TH_RESCHAR,
		E_TH_ONEPHASE,
		E_TH_TWOPHASE,
		E_TH_THREEPHASE,
		E_TH_HALFPHASE
	};
	//�����жϷ�ʽ����ͨ����ͨ����ͨ������
	enum E_ALARMCHECK_TYPE
	{
		E_ALARMCHECK_LOWPASS=0,
		E_ALARMCHECK_HIGHPASS,
		E_ALARMCHECK_BANDPASS,
		E_ALARMCHECK_BANDSTOP
	};

	///��������ѧϰ������
    enum E_TRIG_TH_LEARN_TYPE
	{
		E_TRIG_TH_TIME=0,   ///��ʱ����
		E_TRIG_TH_ALARM,    ///��������
        E_TRIG_TH_RESTART,  ///ϵͳ��������
		E_TRIG_TH_SUD,       ///��ͣ������
		E_TRIG_TH_PARAMCHANGED ///��ֵѧϰ�����ı�
	};

	///�Զ��������Ϣ���ö��
	//��������
	enum E_CUSTOMPARAM_DATATYPE
	{
		E_CUSTOMPARAM_TIMEDOMAIN = 1,// ʱ��
		E_CUSTOMPARAM_FREQDOMAIN,  // Ƶ��
		E_CUSTOMPARAM_MAXDOMAIN    // MAXֵ
	};
    //��λ����
	enum E_CUSTOMPARAM_UNITTYPE
	{
		E_CUSTOMPARAM_TIME=1,//ʱ��
        E_CUSTOMPARAM_PERIOD,//����
        E_CUSTOMPARAM_POINT, //����
		E_CUSTOMPARAM_FREQ,  //Ƶ��
		E_CUSTOMPARAM_ORDER  //�״�
	};
	//�źŷ�����ʽ
	enum E_CUSTOMPARAM_SIGANATYPE
	{
		E_CUSTOMPARAM_TIMEWAVE=1,   //ʱ����
		E_CUSTOMPARAM_PEAKSPEC,     //��ֵ��
		E_CUSTOMPARAM_PEAKPEAKSPEC, //���ֵ��
		E_CUSTOMPARAM_POWERSPEC,     //������
		E_CUSTOMPARAM_WRAPPERSPEC    //������
	};
	//����ֵ����
	enum E_CUSTOMPARAM_CHARTYPE
	{
		E_CUSTOMPARAM_PEAKVALUE=1,   //��ֵ
		E_CUSTOMPARAM_PEAKPEAKVALUE, //���ֵ
		E_CUSTOMPARAM_RMSVALUE,      //��Чֵ
		E_CUSTOMPARAM_ENERGYVALUE,   //����ֵ
		E_CUSTOMPARAM_MAXVALUE       //���ֵ
	};
	// Ԥ����ʽ
	enum E_CUSTOMPARAM_PREPROCTYPE
	{
		E_CUSTOMPARAM_PREPROC_INT = 0, // ����
		E_CUSTOMPARAM_PREPROC_DIFF,    // ΢��
		E_CUSTOMPARAM_PREPROC_NUM

	};


	//����ѧϰ����
	class CThresholdLearnParam
	{
	public:
		CThresholdLearnParam();
		float _fParam1;      //����ϵ��
		float _fParam2;      //�Ŵ�ϵ��
		float _fParam3;
		float _fParam4;
		float _fParam5;
		CThresholdLearnParam& operator=(const CThresholdLearnParam& thLParam_);
	};
	//���޽��
	class CThreshold
	{
	public:
		float _fThreshold1;
		float _fThreshold2;
		float _fThreshold3;
		float _fThreshold4;
		float _fThreshold5;
		bool _bThreshhold1;
		CThreshold & operator=(const CThreshold& th_);
	};
	//���Ʊ����ж�ʹ�ò���
	class CTrendCheckParam
	{
	public:
		CTrendCheckParam();
		float _fParam1;
		float _fParam2;
		float _fParam3;
		float _fParam4;
		float _fParam5;
		CTrendCheckParam& operator=(const CTrendCheckParam& tParam_);
	};

	//����λ���жϱ�������ز���
	class CAxisAlarmParam
	{
	public:
		CAxisAlarmParam();
		~CAxisAlarmParam();
		//������ֵѧϰ����
		CThresholdLearnParam _thLearnParamS;
		//�����ֵѧϰ����
		CThresholdLearnParam _thLearnParamF;
		//���Ʊ����жϲ���
		CTrendCheckParam _trendCheckParam;
		//�Ƿ��黺��
		bool _bCheckS;
		//�Ƿ�����
		bool _bCheckF;
		//�Ƿ������Ʊ���
		bool _bCheckTrend;
		CAxisAlarmParam& operator=(const CAxisAlarmParam& aParam_);
	};

	//ͨ���жϱ�������ز���
	class CChannAlarmParam
	{
	public:
		CChannAlarmParam();
		///�Ƿ��жϸ������ͱ�������ز���
		bool _bRegular;
		//�Ƿ��ж�����ֵ���Ʊ���
		bool _bCharTrend;
		//�Ƿ��ж���λ���Ʊ���
		bool _bPhaseTrend;
		//�Ƿ��ж�����ֵ���䱨��
		bool _bCharSlow;
		//�Ƿ��ж�����ֵ��䱨��
		bool _bCharFast;
		//�Ƿ��ж���λ���䱨��
		bool _bPhaseSlow;
		//�Ƿ��ж���λ��䱨��
		bool _bPhaseFast;
		//��������ѧϰ����
		CThresholdLearnParam _pThLearnParamS[D_BHKD_ALARM_CHARTYPE_NUM];
		//�������ѧϰ����
		CThresholdLearnParam _pThLearnParamF[D_BHKD_ALARM_CHARTYPE_NUM];//���������ʽ���ܣ���ʾ�ĸ��Ƕ�
		CTrendCheckParam _pTrendParam[D_BHKD_ALARM_CHARTYPE_NUM];
		//�����жϱ�������ز���
		float _fAlarmLL;///����ǵ�ֵ����ʱ����ʾ�����ޣ�2ֵ�Ǳ�ʾԲ�ĵ�Xֵ
		float _fAlarmLH;///����ǵ�ֵ����ʱ����ʾ���ޣ�2ֵ�Ǳ�ʾԲ�ĵ�Yֵ
		float _fAlarmHL;///����ǵ�ֵ����ʱ����ʾ���ޣ�2ֵ�Ǳ�ʾ�뾶������
		float _fAlarmHH;///����ǵ�ֵ����ʱ����ʾ�����ޣ�2ֵ�Ǳ�ʾ�뾶������

		float _fAlarm1; ///Ԥ��
		float _fAlarm2; ///Ԥ��
		float _fAlarm3; ///Ԥ��
		int   _iResv1;   ///Ԥ��

		int   _iRegJudgeType;//��ʾ�ǵ�ͨ����ͨ����ͨ������
	    int _iRegAlarmSingleOrMulti;//��ʾ��������ֵ�жϱ�������2������ֵ�жϱ�����1��ʾ������2��ʾ2��
		///���汨�����õ�����ֵ���ͣ�����ǵ�ֵ����E_ALARM_CHARTYPEö�ٱ�ʾ������ֵ���ͣ������2����������D_BHKD_AT_CHARONE��ʽ����������õ���
		int  _iRegCharType;
		CChannAlarmParam& operator=(const CChannAlarmParam& chAlarmParam_);
	};
	///�����Ϣ�ṹ��
	class S_ChannInfo
	{
	public:
		char _cChannID[D_BHKD_CHANNID_LEN];     //ID of Channel
		char _cChannNo[D_BHKD_CHANNNO_LEN];     //No of Channel
		int _iID;               //ID
		char _cCompany[D_BHKD_COMPANYNAME_LEN];    //
		char _cFactory[D_BHKD_FACTORYNAME_LEN];
		char _cPlantNo[D_BHKD_PLANTNO_LEN];     //No of Plant
		char _cChannAlias[D_BHKD_CHANNALIAS_LEN];  //alias of channel
        int _iChannType;        //the type of channel.For example:vibration ,process
		int _iSensorType;       //the type of sensor.For example: votex,acceleration et al
		int _iRevType;          //��������Ǹ�ת��
		int _iList;             //list number of channel in graph
		char _cUnit[20];        //unit of channel signal
		float _fSensitivity;      //Sensitivity of sensor;
		bool _bKeyIF;            //�Ƿ���ڼ���
		float _fGapVoltage;      //��϶��ѹ
		int _iInfoType;         //��Ϣ��������
		float _fSensitivity1;  //������1
		int  _iCylinderNo;      // ��λ����(���ױ��)
		CChannAlarmParam _chAlarmParam;//��������
		char _cTempID[20];           //�Զ������ģ��ID
		char _cAlarmTempID[20];      //�Զ����������ģ��ID
		int   _iLocationIdx;       // λ������
		int   _iMeassureDirection; // ��������
		int   _iDataSource;        // ����Դ
	public:
		S_ChannInfo();
		S_ChannInfo& operator=(const S_ChannInfo& chInfo_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ��豸��ϸ��Ϣ
		bool GetChannInfo(CCustomDB *pDB_);
		//��ָ�������������еõ��豸��ϸ��Ϣ
		bool GetChannInfo(CSimADO *pDB_);
		//����ͨ����Ϣ��ָ������
		bool SetChannInfo(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
	};

	///�Զ��������Ϣ
	class CCustomParamInfo
	{
	public:
		CCustomParamInfo();
		~CCustomParamInfo();
	public:
		E_CUSTOMPARAM_DATATYPE		_eDataType;
		E_CUSTOMPARAM_UNITTYPE		_eUnitType;
        E_CUSTOMPARAM_SIGANATYPE	_eSigAnaType;
		E_CUSTOMPARAM_CHARTYPE		_eCharType;
		char	_cCompany[D_BHKD_COMPANYNAME_LEN];
		char	_cFactory[D_BHKD_FACTORYNAME_LEN];
		char	_cSetID[D_BHKD_SETID_LEN];
		char	_cTempletID[20];
		char	_cSegName[100];
        int     _iID;
		int     _iSegNum;
		int     _iSegStartNo;
		int     _iPreProcType;        //Ԥ��������
		float   _fDataStartValue;
		float   _fDataEndValue;
		float   _fBandStartValue;
		float   _fBandEndValue;
	public:
		CCustomParamInfo& operator=(const CCustomParamInfo& customParamInfo_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ��Զ��������ϸ��Ϣ
		bool GetCustomParamInfo(CCustomDB *pDB_);
		//��ָ�������������еõ��Զ��������ϸ��Ϣ
		bool GetCustomParamInfo(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
	};

    ///�Զ��屨��������Ϣ
	class CCustomAlarmParamInfo
	{
	public:
		CCustomAlarmParamInfo();
		~CCustomAlarmParamInfo();
	public:
		char	_cCompany[D_BHKD_COMPANYNAME_LEN];
		char	_cFactory[D_BHKD_FACTORYNAME_LEN];
		char	_cSetID[D_BHKD_SETID_LEN];
		char	_cAlarmTempletID[20];
		char	_cSegName[100];
		int     _iID;
		int     _iSegStartNo;
		int     _iSegNum;
		int     _iJudgeType;
		int     _iAlarmType;
		int     _iIF_Alarm;
		int     _iAlarmGroup;
		float   _fAlarmLTH;
		float   _fAlarmHTH;
	public:
		CCustomAlarmParamInfo& operator=(const CCustomAlarmParamInfo & customAlarmParamInfo_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ��Զ��屨��������ϸ��Ϣ
		bool GetCustomAlarmParamInfo(CCustomDB *pDB_);
		//��ָ�������������еõ��Զ��屨��������ϸ��Ϣ
		bool GetCustomAlarmParamInfo(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
	};

    ///���λ����Ϣ
	class CChannLocations
	{
	public:
		CChannLocations();
		~CChannLocations();
	public:
		char	_cCompany[D_BHKD_COMPANYNAME_LEN];
		char	_cFactory[D_BHKD_FACTORYNAME_LEN];
		char	_cSetID[D_BHKD_SETID_LEN];
		char    _cPlantNo[D_BHKD_PLANTNO_LEN];
		char    _cLocationName[100];
		char    _cComment[100];
		int     _iLocationIDX;
		int     _iSectionIDX;
		int     _iBearingTblType;
		int     _iBearingIDX;
		int     _iShaftNumber;
	public:
		CChannLocations& operator=(const CChannLocations &channLocations_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ����λ����Ϣ
		bool GetChannLocations(CCustomDB *pDB_);
		//��ָ�������������еõ����λ����Ϣ
		bool GetChannLocations(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
	};

	///��㲿λ��Ϣ
	class CChannSections
	{
	public:
		CChannSections();
		~CChannSections();
	public:
		char	_cCompany[D_BHKD_COMPANYNAME_LEN];
		char	_cFactory[D_BHKD_FACTORYNAME_LEN];
		char	_cSetID[D_BHKD_SETID_LEN];
		char    _cPlantNo[D_BHKD_PLANTNO_LEN];
		char    _cSectionName[100];
		char    _cComment[100];
		int     _iSectionIDX;
		int     _iGearBoxIDX;
	public:
		CChannSections& operator=(const CChannSections &channSections_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ���㲿λ��Ϣ
		bool GetChannSections(CCustomDB *pDB_);
		//��ָ�������������еõ���㲿λ��Ϣ
		bool GetChannSections(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
	};

    ///��в�����Ϣ
	class CBearingParamInfo
	{
	public:
		CBearingParamInfo();
		~CBearingParamInfo();
	public:
		char    _cBearingName[100];
		char    _cComment[100];
	    float	_fPitchDiameter;
		float	_fElementDiameter;
		float	_fContactAngle;
		float	_fHousingDiameter;
		float	_fBoreDiameter;
		int		_iBearingIDX;
		int		_iBearingType;
		int		_iRowsNum;
		int		_iElementsNum;
		int		_iBearingCode;
	public:
		CBearingParamInfo& operator=(const CBearingParamInfo &bearingParamInfo_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ���в�����ϸ��Ϣ
		bool GetBearingParamInfo(CCustomDB *pDB_);
		//��ָ�������������еõ���в�����ϸ��Ϣ
		bool GetBearingParamInfo(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
	};

	///�����������Ϣ
	class CGearBoxParamInfo
	{
	public:CGearBoxParamInfo();
		   ~CGearBoxParamInfo();
	public:
		char	_cCompany[D_BHKD_COMPANYNAME_LEN];
		char	_cFactory[D_BHKD_FACTORYNAME_LEN];
		char	_cSetID[D_BHKD_SETID_LEN];
		char    _cPlantNo[D_BHKD_PLANTNO_LEN];
		char    _cGearBoxName[100];
		char    _cComment[100];
		int     _iGearBoxIDX;
		int		_iGearBoxLevel;
		int     _iGearBoxType;
		int		_iDriverType;
		int		_iPlanetNum;
		int		_iGearNumSun;
		int		_iGearNumPlanet;
		int		_iGearNumGalaxy;
		int		_iIsSync;
		int     _iGearNumZ12;
		int     _iGearNumZ21;
		int     _iGearNumZ22;
		int     _iGearNumZ31;
		int     _iGearNumZ32;
		int     _iGearNumZ41;
		int     _iGearNumZ42;
		int     _iGearNumZ51;
		int     _iGearNumZ52;
		int     _iGearNumZ61;
	public:
		CGearBoxParamInfo& operator=(const CGearBoxParamInfo &gearBoxParamInfo_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ������������ϸ��Ϣ
		bool GetGearBoxParamInfo(CCustomDB *pDB_);
		//��ָ�������������еõ������������ϸ��Ϣ
		bool GetGearBoxParamInfo(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
	};


	///����λ��ͨ����Ϣ
	class CAxisChannInfo
	{
	public:
		CAxisChannInfo();
		virtual ~CAxisChannInfo();
		int _iID;               //ID
		char _cCompany[D_BHKD_COMPANYNAME_LEN];
		char _cFactory[D_BHKD_FACTORYNAME_LEN];
		char _cPlantNo[D_BHKD_PLANTNO_LEN];     //No of Plant
		char _cVerChann[D_BHKD_CHANNNO_LEN];
		char _cHorChann[D_BHKD_CHANNNO_LEN];
		int _iLocationType;
		int _iRotateDirection;//��ת����,0��ʱ��,1˳ʱ��
		float _fAxisDia;//��Ӧ����ֱ��
		char _cLocation[D_BHKD_CHANNALIAS_LEN];
		CAxisAlarmParam _axisAlarmParam;
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ�����ͨ����ϸ��Ϣ
		bool GetAxisChannInfo(CCustomDB *pDB_);
		//��ָ�������������еõ�����ͨ����ϸ��Ϣ
		bool GetAxisChannInfo(CSimADO *pDB_);
		//�����������ӵ���Ϣ
		bool SetAxisChannInfo(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
		virtual CAxisChannInfo& operator=(const CAxisChannInfo& aChannInfo_);
	};

	//����λ�����ݽṹ��
	class S_AxisData
	{
	public:
		S_AxisData();
		S_AxisData& operator=(const S_AxisData& axisData_);
		float _fRev;
		float _fCoorX;
		float _fCoorY;
		float _fVerDC;
		float _fVerGap;
		float _fHorDC;
		float _fHorGap;
		bool  _bCalc;             ///�ж��Ƿ��Ѿ����������λ�õ�ֵ
#ifdef _BHKD_SERVER_SIDE_
		bool CalcAxisLocation(int iLocationType_,int iRotateDirection_,float fAxisDia_,float fSensitivityVer_,float fSensitivitypHor_);
#endif//_BHKD_SERVER_SIDE_
	};

    ///����ѹ���������豸�ṹ��
	class S_PlantInfoParam
	{//���ȵ�λ�����ף������λΪ�����ף��ܹ��ʾ���ǧ�ߣ�ѹ��MPa
	public:
		float _fConnRodLength;///���˳���
		float _fCrankShaftDia;////����뾶
		float _fPistonDia;    ///����ֱ��
		float _fTotalPower;   ///�ܹ���
		float _fNomPi;        ///�������ѹ��
		float _fNomPo;        ///�������ѹ��
		float _fClv;          ///��϶��clearance���ݻ�
		float _fRes1;         ///������ֱ��
		float _fRes2;         ///����������
		int _iRes1;
	public:
		S_PlantInfoParam();
		S_PlantInfoParam& operator=(const S_PlantInfoParam& sPlantInfoParam_);
	};

	///�׵ĸ����ṹ��
	class S_RecipComprParam
	{
	public:
		S_PlantInfoParam _sPlantInfoParam[10];
	public:
		S_RecipComprParam();
		S_RecipComprParam& operator=(const S_RecipComprParam& sRecipComprParam_);
	};

	///�豸��Ϣ�ṹ��
	class S_PlantInfo
	{
	public:
		S_PlantInfo();
		~S_PlantInfo();
		char _cCompany[D_BHKD_COMPANYNAME_LEN];       //
		char _cFactory[D_BHKD_FACTORYNAME_LEN];       //
		char _cManufacturer[100];  //���쳧��
		char _cSetID[D_BHKD_SETID_LEN];          //װ����
		char _cPlantID[D_BHKD_PLANTID_LEN];      //�豸��
		char _cPlantNo[D_BHKD_PLANTNO_LEN];      //�豸�ţ�Ӣ���������
		int _iVibChannNum;         //�񶯲����Ŀ
		int _iSmpFreq;             //����Ƶ��
		int _iSmpNum;              //��������
		int _iProcChannNum;        //�����������Ŀ
		int _piRev[5];            //�ת��1~5
		int _iGraphType;           //��òͼ����
		int _iMachineType;         //�豸����
		int _iDriverType;          //����������
		int _iConnType;            //�������ͣ���������ͣ�
		int _iBearingType;         //�������
		int _iRotorType;           //ת������
		int _iSealType;            //�ܷ�����
		int _iWorkRevType;         //����ת������,�Ǵ���һ���ٽ�ת�ٸ���
		int _iCritSpeed1st;        //һ���ٽ�ת��
		int _iCritSpeed2nd;        //�����ٽ�ת��
        COleDateTime _firstRunT;   //�״�Ͷ��ʱ��

		int _iCylinderNum;          //���׸���
		int _iDynChannNum;         //��̬����ͨ������Ŀ
		int _iGraphBuffBytes;      //���Ƹ�òͼ���ֽ���
		BYTE *_pGraphBuff;         //���Ƹ�òͼ��BUFFָ��
		float _fVersion;           //�汾��Ϣ
		int   _iDataSource;         //����Դ
    ///�����һЩ��е�����ṹ�塣9������������1������.Ŀǰ������ʽѹ������
		S_RecipComprParam _sRecipComprParam; ///�׵ĸ����ṹ��
	public:
		S_PlantInfo& operator=(const S_PlantInfo& sPlantInfo_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ��豸��ϸ��Ϣ
		bool GetPlantInfo(CCustomDB *pDB_);
		//��ָ�������������еõ��豸��ϸ��Ϣ
		bool GetPlantInfo(CSimADO *pDB_);
		//�����������ӵ���Ϣ
		bool SetPlantInfo(CSimADO *pDB_);

#endif//_BHKD_SERVER_SIDE_
	};

	//�м����������Ϣ
	class S_SetInfo
	{
	public:
	    int _iID;
		char _cCompany[D_BHKD_COMPANYNAME_LEN];       //
		char _cFactory[D_BHKD_FACTORYNAME_LEN];       //
		char _cSetID[D_BHKD_SETID_LEN];
		char _cIP[D_BHKD_IP_LEN];
		int _iPort;
		int _iSendInterval;
		int _iIfSend;
		int _iSudSendInterval;
		int _iAlarmSendInterval;
		char _cTmIP[D_BHKD_IP_LEN];
		int _iTmPort;
		char _cParentID[D_BHKD_SETID_LEN];
		int _iChildFlag;
	public:
		S_SetInfo();
		S_SetInfo& operator=(const S_SetInfo& sSetInfo_);
#ifdef _BHKD_SERVER_SIDE_
		//��ָ�������������еõ��豸��ϸ��Ϣ
		bool GetSetInfo(CCustomDB *pDB_);
		//��ָ�������������еõ��豸��ϸ��Ϣ
		bool GetSetInfo(CSimADO *pDB_);
#endif//_BHKD_SERVER_SIDE_
	};

	///�񶯲������ֵ�ṹ��
	class _BHKD_EXT_ S_VibCharValue
	{
	public:
		S_VibCharValue();
		~S_VibCharValue();
		DATATYPE_CHAR _fCharAll;    //ͨƵ����ֵ
		DATATYPE_CHAR _fCharHalf;   //1/2��Ƶ����ֵ
		DATATYPE_CHAR _fCharOne;    //1��Ƶ����ֵ
		DATATYPE_CHAR _fCharTwo;    //2��Ƶ����ֵ
		DATATYPE_CHAR _fCharThree;  //3��Ƶ����ֵ
		DATATYPE_CHAR _fCharRes;    //��������ֵ
		DATATYPE_CHAR _fDC;         //ֱ����
		DATATYPE_CHAR _fGap;        //��϶ֵ
		DATATYPE_CHAR _fPhaseHalf;  //1/2��Ƶ��λ
		DATATYPE_CHAR _fPhaseOne;   //1��Ƶ��λ
		DATATYPE_CHAR _fPhaseTwo;   //2��Ƶ��λ
		DATATYPE_CHAR _fPhaseThree; //3��Ƶ��λ
		DATATYPE_INT  _iSmpFreq;    //����Ƶ��
		DATATYPE_INT  _iSmpNum;     //��������
		DATATYPE_INT  _iRev;        //ת��

	public:
		S_VibCharValue& operator=(const S_VibCharValue& vibValue_);
		///�õ�ָ�����͵�����ֵ
		DATATYPE_CHAR GetSpecTypeData(int iCharType_=GE_ALLCHAR);
		void SetSpecTypeData(float fData_,int iCharType_=GE_ALLCHAR);
	};

	//Ϊ���ݽ����ϰ汾���ɵ�����ֵ�ṹ��
	class _BHKD_EXT_ S_OldVibCharValue
	{
	public:
		S_OldVibCharValue();
		~S_OldVibCharValue();
		DATATYPE_CHAR _fCharAll;    //ͨƵ����ֵ
		DATATYPE_CHAR _fCharHalf;   //1/2��Ƶ����ֵ
		DATATYPE_CHAR _fCharOne;    //1��Ƶ����ֵ
		DATATYPE_CHAR _fCharTwo;    //2��Ƶ����ֵ
		DATATYPE_CHAR _fCharThree;  //3��Ƶ����ֵ
		DATATYPE_CHAR _fCharRes;    //��������ֵ
		DATATYPE_CHAR _fDC;         //ֱ����
		DATATYPE_CHAR _fGap;        //��϶ֵ
		DATATYPE_CHAR _fPhaseHalf;  //1/2��Ƶ��λ
		DATATYPE_CHAR _fPhaseOne;   //1��Ƶ��λ
		DATATYPE_CHAR _fPhaseTwo;   //2��Ƶ��λ
		DATATYPE_CHAR _fPhaseThree; //3��Ƶ��λ

	public:
		S_OldVibCharValue& operator=(const S_OldVibCharValue& vibValue_);
		///�õ�ָ�����͵�����ֵ
		DATATYPE_CHAR GetSpecTypeData(int iCharType_=GE_ALLCHAR);
		void SetSpecTypeData(float fData_,int iCharType_=GE_ALLCHAR);
	};

	///��̬ͨ��������ֵ���ݽṹ��
	class _BHKD_EXT_  S_DynCharValue
	{
	public:
		S_DynCharValue();
		~S_DynCharValue();
		DATATYPE_CHAR _fCharValue0;
		DATATYPE_CHAR _fCharValue1;
		DATATYPE_CHAR _fCharValue2;
		DATATYPE_CHAR _fCharValue3;
		DATATYPE_CHAR _fCharValue4;
		DATATYPE_CHAR _fCharValue5;
		DATATYPE_CHAR _fCharValue6;
		DATATYPE_CHAR _fCharValue7;
		DATATYPE_CHAR _fCharValue8;
		DATATYPE_CHAR _fCharValue9;
		DATATYPE_CHAR _fCharValue10;
		DATATYPE_CHAR _fCharValue11;
		DATATYPE_INT  _iSmpFreq;
		DATATYPE_INT  _iSmpNum;
		DATATYPE_INT  _iRev;
    public:
		S_DynCharValue& operator=(const S_DynCharValue& dynValue_);
		DATATYPE_CHAR GetSpecTypeData(int iCharType_=0);
		void SetSpecTypeData(const float &fData_,int iCharType_=0);
	};

    //Ϊ���ݽ����ϰ汾���ɵ�����ֵ�ṹ��
	class _BHKD_EXT_  S_OldDynCharValue
	{
	public:
		S_OldDynCharValue();
		~S_OldDynCharValue();
		DATATYPE_CHAR _fCharValue0;
		DATATYPE_CHAR _fCharValue1;
		DATATYPE_CHAR _fCharValue2;
		DATATYPE_CHAR _fCharValue3;
		DATATYPE_CHAR _fCharValue4;
		DATATYPE_CHAR _fCharValue5;
		DATATYPE_CHAR _fCharValue6;
		DATATYPE_CHAR _fCharValue7;
		DATATYPE_CHAR _fCharValue8;
		DATATYPE_CHAR _fCharValue9;
		DATATYPE_CHAR _fCharValue10;
		DATATYPE_CHAR _fCharValue11;
	public:
		S_OldDynCharValue& operator=(const S_OldDynCharValue& dynValue_);
		DATATYPE_CHAR GetSpecTypeData(int iCharType_=0);
		void SetSpecTypeData(const float &fData_,int iCharType_=0);
	};

    ///����״̬��ʶ
	struct S_AlarmState
	{
       S_AlarmState()
	   {
		   _iFastState=0;
		   _iSlowState=0;
		   _iTrendState=0;
		   _iRegState=0;
	   }
	   unsigned int _iFastState;//��䱨��״̬
	   unsigned int _iSlowState;//���䱨��״̬
	   unsigned int _iTrendState;//���Ʊ���״̬
	   unsigned int _iRegState;//���汨��״̬
	};

    ///�豸����ͳ����Ŀ�ṹ��
	struct S_PlantNumStatics
	{
		S_PlantNumStatics()
		{
			_iPlantNum      = 0;
			_iAlarmPlantNum = 0;
			_iRunPlantNum   = 0;
			_iStopPlantNum  = 0;
		}
		S_PlantNumStatics& operator=(const S_PlantNumStatics& plantNumStatics_);
		S_PlantNumStatics& operator+(const S_PlantNumStatics& plantNumStatics_);
		int _iPlantNum;//�豸��Ŀ
		int _iAlarmPlantNum;//�����豸��Ŀ
		int _iRunPlantNum;//�����豸��Ŀ
		int _iStopPlantNum;//ͣ���豸��Ŀ
	};

    ///���汨����־��Ϣ�ṹ��
	struct S_AlarmlogInfo
	{
		int _iAlarmID;//�����¼�ID
		int _iAlarmType;//��������
		int _cChannType;//ͨ������
		string _sName;//�������
		COleDateTime _tStart;//������ʼʱ��
		COleDateTime _tEnd ;//��������ʱ��
	};

	///�Զ���������ݽṹ�壬����Ϊ50
	struct S_CustomParamData
	{
		float pfCustomParom[GD_CUSTOMPARAM_BUFFSIZE];
	};

	///����������Ƶ�ʽṹ��
	struct S_GearBoxCharFreq
	{
		float fEnvFreq1;//����Ƶ��
		float fEnvFreq2;//�����תƵ
		float fShaftCF1;//������I��תƵ
		float fShaftCF2;//���������תƵ
		float fShaftCF3;//���������תƵ
		float fShaftCF4;//���������תƵ
	};
}

// Copy_if was dropped from the standard library by accident.
// Bjarne Stroustrup. The C++ Programming Language (3rd edition). 1997. ISBN: 0-201-88954-4. Chapter 18.12.1: 'Prefer algorithms to loops.
// Scott Meyers. Effective STL. ISBN: 0-201-74962-9. Item 43: 'Prefer algorithm calls over hand-written loops'
// richelbilderbeek
template<typename In, typename Out, typename Pred>
Out copy_if(In first, In last, Out res, Pred Pr)
{
  while (first != last)
  {
    if (Pr(*first))
      *res++ = *first;
    ++first;
  }
  return res;
}

#endif //_BHKD_G_UTILITIES_H_MARBLE_
