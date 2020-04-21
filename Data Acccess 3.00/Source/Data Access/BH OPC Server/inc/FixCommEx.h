#ifndef __BH_FIXCOMMEX__HH__
#define __BH_FIXCOMMEX__HH__
#include "DLLDEF.h"
#ifdef _DEBUG
#pragma comment(lib,"FixCommAd.lib")
#else
#pragma comment(lib,"FixCommA.lib")
#endif
#pragma comment(lib,"PluginSystem.lib")

enum EN_FIXCOMM_TYPE
{
	EN_FIXCOMM_TYPE_ACE  = 0,  ///表示使用的是基于ACE库的中间件平台的通讯库
	EN_FIXCOMM_TYPE_MFC  = 1   ///表示旧版中间件，主要用MFC的库和Window的API写的
};

class _APP_LIB_ CFixCommEx 
{
public:
	CFixCommEx(bool idle=true, EN_FIXCOMM_TYPE fixCommType_ = EN_FIXCOMM_TYPE_MFC);
	~CFixCommEx();
public:
	void SetBusy();
	void SetIdle();
	bool IsIdle();
	//取得空闲时间
	double GetIdleDuration();
	
public:
	//连接开始时间
	double m_dtStarted;
	//字符串
	CString		m_strIP;
	//HANDLE		m_e;

public:
	/**
	 * Interface Wrapper
	 */
    // 连接服务器/远程服务器
	BOOL    Link       ( const char *pszDest, const char *pszDept  ); 
	
	///关闭
	BOOL Close();
	
	// HEAD
	void    CreateHead ( int nFunc          , int nWidth=-1);

	CString GetLastErrMsg  ();  // 取出系统出错信息
	
	// MORE
	bool    More();

	long    GetCount     ();  // 取出返回记录数
		
	// GET
	double  GetDouble    ( int nFixCode , int         nRow=-1  );
	long    GetLong      ( int nFixCode , int         nRow=-1  );
	CString Get		     ( int nFixCode , int         nRow=-1  );
	CString GetItem      ( int nFixCode , int         nRow=-1  );

	COleDateTime GetTime ( int nFixCode , int         nRow=-1  );
		
	bool    GetItemBuf   ( int nFixCode, char *pBuf, int nSize );
	
	// SET
	bool    SetItem      ( int nFixCode , double      dValue   ); // 设置某请求域浮点性数据 -- 浮点性
	BOOL    SetItem      ( int nFixCode , long        nValue   ); // 设置某请求域整性数据   -- 整性
	BOOL    SetItem      ( int nFixCode , int         nValue   );
	BOOL    SetItem      ( int nFixCode , const char  *pszData ); // 设置某请求域字符串数据 -- 字符串
	bool    SetItem      ( int nFixCode , COleDateTime tValue  );

	bool    SetItemBuf   ( int nFixCode, char *pBuf, int nSize );
	
	// 设置通讯超时秒数	
	void    SetTimeOut( long nMaxSec ); 
    ///得到链接的是新中间件还是基于MFC的中间件
	EN_FIXCOMM_TYPE GetFixCommType();
private:
	EN_FIXCOMM_TYPE m_enFixCommType;
	//中间件连接
	void  * m_pFixComm;
	//状态
	bool m_bIdle;
};

class _APP_LIB_ CFixCommExLock{
public:
	CFixCommExLock(CFixCommEx* pFixComm);
	~CFixCommExLock();
public:
	CFixCommEx* m_pFixComm;
	CString		m_strPlant;
};

#endif//__BH_FIXCOMMEX__HH__
