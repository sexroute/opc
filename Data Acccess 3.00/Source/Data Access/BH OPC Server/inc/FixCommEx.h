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
	EN_FIXCOMM_TYPE_ACE  = 0,  ///��ʾʹ�õ��ǻ���ACE����м��ƽ̨��ͨѶ��
	EN_FIXCOMM_TYPE_MFC  = 1   ///��ʾ�ɰ��м������Ҫ��MFC�Ŀ��Window��APIд��
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
	//ȡ�ÿ���ʱ��
	double GetIdleDuration();
	
public:
	//���ӿ�ʼʱ��
	double m_dtStarted;
	//�ַ���
	CString		m_strIP;
	//HANDLE		m_e;

public:
	/**
	 * Interface Wrapper
	 */
    // ���ӷ�����/Զ�̷�����
	BOOL    Link       ( const char *pszDest, const char *pszDept  ); 
	
	///�ر�
	BOOL Close();
	
	// HEAD
	void    CreateHead ( int nFunc          , int nWidth=-1);

	CString GetLastErrMsg  ();  // ȡ��ϵͳ������Ϣ
	
	// MORE
	bool    More();

	long    GetCount     ();  // ȡ�����ؼ�¼��
		
	// GET
	double  GetDouble    ( int nFixCode , int         nRow=-1  );
	long    GetLong      ( int nFixCode , int         nRow=-1  );
	CString Get		     ( int nFixCode , int         nRow=-1  );
	CString GetItem      ( int nFixCode , int         nRow=-1  );

	COleDateTime GetTime ( int nFixCode , int         nRow=-1  );
		
	bool    GetItemBuf   ( int nFixCode, char *pBuf, int nSize );
	
	// SET
	bool    SetItem      ( int nFixCode , double      dValue   ); // ����ĳ�����򸡵������� -- ������
	BOOL    SetItem      ( int nFixCode , long        nValue   ); // ����ĳ��������������   -- ����
	BOOL    SetItem      ( int nFixCode , int         nValue   );
	BOOL    SetItem      ( int nFixCode , const char  *pszData ); // ����ĳ�������ַ������� -- �ַ���
	bool    SetItem      ( int nFixCode , COleDateTime tValue  );

	bool    SetItemBuf   ( int nFixCode, char *pBuf, int nSize );
	
	// ����ͨѶ��ʱ����	
	void    SetTimeOut( long nMaxSec ); 
    ///�õ����ӵ������м�����ǻ���MFC���м��
	EN_FIXCOMM_TYPE GetFixCommType();
private:
	EN_FIXCOMM_TYPE m_enFixCommType;
	//�м������
	void  * m_pFixComm;
	//״̬
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
