#ifdef BH_API_SMS_EXPORTS
#define BH_API_SMS extern "C" __declspec(dllexport)
#else
#define BH_API_SMS extern "C" __declspec(dllimport)
#endif

#ifndef SMS_H_EXPORT_
#define SMS_H_EXPORT_

#define GSM_7BIT                        0
#define GSM_8BIT                        4
#define GSM_UCS2                        8
#define GSM_REVERS                      16

struct SM_PARAM{
	char SCA[16];       // 短消息服务中心号码(SMSC地址)
	char TPA[16];       // 目标号码或回复号码(TP-DA或TP-RA)
	char TP_PID;        // 用户信息协议标识(TP-PID)
	char TP_DCS;        // 用户信息编码方式(TP-DCS)
	char TP_SCTS[16];   // 服务时间戳字符串(TP_SCTS), 接收时用到
	char TP_UD[140];    // 原始用户信息(编码前或解码后的TP-UD)
	char index;         // 短消息序号，在读取时用到
	SM_PARAM()
	{
		ResetData();
	
	}
	void ResetData()
	{
		ZeroMemory(SCA,16);
		ZeroMemory(TPA,16);

		this->ResetSMSContent();
	}

	void ResetSMSContent()
	{
		ZeroMemory(TP_SCTS,16);
		ZeroMemory(TP_UD,16);

		TP_PID = 0;
		TP_DCS = 0;
		index = 0;
	}
} ;



BH_API_SMS  HANDLE _stdcall OpenComm(int anPort, int nBaudRate = CBR_9600, int nParity = NOPARITY, int nByteSize = 8, int nStopBits = ONESTOPBIT);
BH_API_SMS  int _stdcall SendShortMessage(HANDLE Fcomm,const char * send_number,const char* send_msg) ;
BH_API_SMS  bool _stdcall DeleteAllMessage(HANDLE Fcomm);
BH_API_SMS  int	 _stdcall DetectFirstSMSPort(int anStartIndex=1,int anLength=256);
BH_API_SMS  bool _stdcall DeleteMessage(HANDLE Fcomm,int index);
BH_API_SMS  void _stdcall Message(HANDLE Fcomm);
BH_API_SMS  bool _stdcall CloseComm(HANDLE Fcomm);
BH_API_SMS  int _stdcall ReceiveMessage(HANDLE Fcomm,SM_PARAM *sm_param,int index);
BH_API_SMS  int _stdcall ReceiveAllMessage(HANDLE Fcomm,SM_PARAM *sm_param);
BH_API_SMS  int _stdcall ReceiveUnreadMessage(HANDLE Fcomm,SM_PARAM *sm_param);
BH_API_SMS  bool _stdcall SetSendModule(HANDLE Fcomm,int loopback);
BH_API_SMS  int _stdcall CheckNo();
BH_API_SMS  BOOL _stdcall GetCenterNumber(HANDLE Fcomm,char* strCenterNumber,int * anBufferSize);
BH_API_SMS  BOOL __stdcall SetCenterNumber(HANDLE Fcomm,const char* strCenterNumber);
BH_API_SMS  int _stdcall EncodePdu(HANDLE Fcomm,const SM_PARAM* pSrc, char* pDst);
BH_API_SMS  int _stdcall String2Bytes(HANDLE Fcomm,const char* pSrc, unsigned char* pDst, int nSrcLength);


class CHandleWatcher
{
	HANDLE m_hHandle;
public:
	CHandleWatcher()
	{
		this->m_hHandle = NULL;
	}

	CHandleWatcher(HANDLE  ahData)
	{
		this->m_hHandle = NULL;

		this->Attach(ahData);
	}

	CHandleWatcher & operator = (HANDLE  ahData)
	{
		this->m_hHandle = ahData;

		return (*this);
	}

	HANDLE GetHandle()
	{
		return this->m_hHandle;
	}

	void Attach(HANDLE  ahData)
	{
		ASSERT(this->m_hHandle == NULL || this->m_hHandle == INVALID_HANDLE_VALUE);

		this->m_hHandle = ahData;			
	}

	HANDLE Detach()
	{
		HANDLE lhTemp = this->m_hHandle;

		this->m_hHandle = NULL;

		return lhTemp;
	}

	~CHandleWatcher()
	{
		if (this->m_hHandle!=NULL && this->m_hHandle != INVALID_HANDLE_VALUE)
		{
			CloseComm(m_hHandle);
		}

		this->Detach();
	}
};
#endif