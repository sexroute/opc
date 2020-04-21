// FixComm.h: interface for the CFixComm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIXCOMM_H__5FD3A646_FDB8_477E_8BA4_7E5CD9FCB9A5__INCLUDED_)
#define AFX_FIXCOMM_H__5FD3A646_FDB8_477E_8BA4_7E5CD9FCB9A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "aci.h"
#include "fixcode.h"
#include "fixdef.h"
#include <afxtempl.h>
//	#include <string>
//	using namespace std;

#define	ERROR_LINK	      -301
#define MESSAGE_LINKERR   "�����쳣"

#define	ERROR_RELINK	  -302
#define MESSAGE_RELINKERR   "���������쳣"

#define	ERROR_CONNECT	   -300
#define CONNECT_ERR        "ͨѶ����"
#define ERROR_RECSIZE      -303
#define ERROR_RECSIZE_MSG  "�������������"
#define ERROR_RECNO        -304
#define ERROR_RECNO_MSG    "�������ݵļ�¼�쳣"
#define ERROR_NUM          -305
#define ERROR_NUM_MSG      "�������������ȷ"

#define ERROR_SENDDOWN     -306
#define MESSAGE_SENDDOWN   "��������ʱ�����ж�"

#define ERROR_SEND         -307
#define MESSAGE_SEND       "��������ʧ��"

#define	ERROR_READTIMEOUT	-308
#define	MESSAGE_READTIMEOUT	"�ȴ����ݳ�ʱ"

#define	ERROR_UNCOMPRESS	-309
#define	MESSAGE_UNCOMPRESS	"��ѹ������ʧ��"

#define	ERROR_UNCOMPRESS_LEN	-310
#define	MESSAGE_UNCOMPRESS_LEN	"��ѹ�����ݳ��Ȳ���"


typedef struct BufInfo
{
	char			  *m_pSendBuf					;	// ���͵����� 
	long			   m_nSendSize					;	// ���͵����ݴ�С
	long			   m_nSendFixID					;	// ���͵�FIXID	
}BufInfo;

typedef CTypedPtrArray <CPtrArray, BufInfo * >  CBufInfo;

class CAnswer{
public:
  CStringArray arValue ;
  CDWordArray  arCode  ;
  CAnswer(){}
  virtual    ~CAnswer(){
	   arValue.RemoveAll();
	   arCode .RemoveAll();
  }
};
typedef CTypedPtrArray <CPtrArray, CAnswer  * >  CAnswerArray;
class AFX_EXT_CLASS CFixComm 
{
public:
	void CancelRead();
	BOOL IsDead();
	void FreeBufInfo();
	void SetCompressLevel(int level);
	BOOL SetItem( int nFixCode , COleDateTime        tValue   );
	COleDateTime GetTime( int nFixCode , int         nRow=-1  );
	bool GetItemBuf( int nFixCode, char *pBuf, int nSize );
	bool	GetDebugState();
	void	SetDebugState(bool bDebug);
	bool	GetAllItem(CDWordArray &arID,CStringArray &arValue,int nRow=-1);
	bool	HaveItem( int nFixCode, int  nRow=-1  );
	bool	AnalyReq();
	void	SetRouteID( long nRouteID );
	long	GetRouteID();
	BOOL	More();
	void	SetErrMsg( const char *pszMsg);

//	BOOL	setString( int FixCode, const string &value);
//	string	getString( int FixCode , int nRow=-1);

	CString GetUser();
	CString	GetDestBranch();
	CString	GetBranch();
	CString	GetNode();
	CString	GetLY();

	CString GetRetNote();
	long	GetRetCode();
	long	GetFunc();
	BOOL	Init();
	void	CreateEndMak();
	void	SetIsSvr( BOOL bSvr );
    ACI		*GetAci();
	
    //=========================================================
	//  ��׼��ͷ���ú���
	//=========================================================
	void    SetVersion ( const char *pszVersion );  // ���ð汾��
	void    SetDestDept ( const char *pszDestDept );  // ����Ŀ��Ӫҵ�����(��Ӧ��·��ʹ��)
	void    SetBranch    ( const char *pszDept     );  // ���ò���Ӫҵ��
	void    SetQuestWay( const char *pszWay     );  // ����ί�з�ʽ 
	void    SetUser    ( const char *pszUser    );  // ���ù�Ա��
	void    SetNode    ( const char *pszNode    );  // ���ò�������
  
    //=============================================================
	//   �������̺���      < ��Ҫ���ڿͻ��˱�� >
	//=============================================================
	BOOL    Link       ( const char *pszDest, const char *pszDept  );  // ���ӷ�����/Զ�̷�����
	CString GetLastErrMsg                                        ();  // ȡ��ϵͳ������Ϣ
	long    GetCode                                              ();  // ȡ��ϵͳ�����룬����ͨѶ���� ҵ�����. ���������㡣
	void    CreateHead ( int nFunc          , int nWidth=-1       );  // �����������룬�������(��ѡ��������÷���ʱ�����ж������)
    virtual BOOL    Close                                                ();  // �ر��������������
	long    GetCount                                             ();  // ȡ�����ؼ�¼��
	int     Read                                   (ACI *pAci=NULL);  // ��ȡ����
	int     Write                                  (ACI *pAci=NULL);  // ��������
	BOOL    Empty                                                ();  // ��ս������ݻ���
	void    SetTimeOut ( long nMaxSec                             );  // ����ͨѶ��ʱ����	

     
    //=============================================================
	//   �������̺���      < ֻ���ڷ���˱�� >
	//=============================================================
	BOOL   SetAci          ( ACI *pAci );
	BOOL   CreateAnswer    ( int nFunc , int nWidth =-1);
	BOOL   CreateAnswerMul ( int nFunc , int nWidth =-1);
    BOOL   CreateNextAnswer();

    //=============================================================
	//   �������������� / ��ȡ���������
	//=============================================================
	double	GetDouble   ( int nFixCode , int         nRow=-1  );
	long	GetLong    ( int nFixCode , int         nRow=-1  );
	CString Get		   ( int nFixCode , int         nRow=-1  );
	CString GetItem    ( int nFixCode , int         nRow=-1  ); // ����FIX����ȡ����Ӧ�Ľ����
                                                                // ȡ�����ݺ��� , ���nRow=-1,���ص�ǰ�н������

	BOOL    SetItem    ( int nFixCode , double      dValue   ); // ����ĳ�����򸡵������� -- ������
	BOOL    SetItem    ( int nFixCode , long        nValue   ); // ����ĳ��������������   -- ����
	BOOL    SetItem    ( int nFixCode , int         nValue   );
	BOOL    SetItem    ( int nFixCode , const char *pszData  ); // ����ĳ�������ַ������� -- �ַ���

	CFixComm();
	virtual    ~CFixComm()   ;
	
	CAnswerArray       m_arAnswer					;	// �������ݻ���
	CAnswer            m_Query						;	// �������ݻ���
	char 		      *m_pData                      ;	// ������
	long			   m_nDataSize					;
	CString            m_sSvr                       ;
	CStringArray	   m_arDebugData				;

	//## ##############################################################
	//##
	//##�� ����һЩ������ �� ��ʱ�Ľ������
	//##
	//## ����ֻ���ļ�����������	
	//## һ������²��Ƽ����������� 
	//##					     2002.07.04

    CBufInfo          m_arBufInfo;                  ;   // �����ݼ�,����3�ֶ�����
	char			  *m_pSendBuf					;	// ���͵����� 
	long			   m_nSendSize					;	// ���͵����ݴ�С
	long			   m_nSendFixID					;	// ���͵�FIXID	
	bool			   SetItemBuf( int nFixCode, char *pBuf, int nSize );
	//## ###############################################################

protected:	
	CString m_sHead                                 ;  // ��׼���ݰ�ͷ
    int    ReadAnswer ( ACI *pAci, CAnswer *pAnswer ,int nMaxSec=0           );  // ��������               
	ACI                       *m_pAci               ;  // ͨѶָ��
	BOOL                        m_bMulti            ;  // ���ڷ����ָ�����������Ƿ����
	int							m_nAnswerNo         ;  // ���ڷ����ָ�����з������ݵ����
	BOOL                        m_bSvr              ;
	int							m_nTimeOut			;
	bool						m_bDebug			;
	
protected:
    char			m_cFieldSplit                ; // ��ָ���
	char			m_cSubFieldSplit             ; // ����ָ���
    BOOL			m_bMutil                     ; // ϵͳ�ڲ�ʹ���Ƿ��Ƕ��з���
	CString			m_sErrMsg                    ; // ���󷵻���
	long			m_nCount                     ; // ϵͳ���ؼ�¼����	
	int				m_nNo                        ; // ���ؼ�¼ʱ����¼��
	long			m_nMaxSec                    ; // ���ʱ 
	long			m_nFunc                      ; // ϵͳ�����ܺ�
	long			m_nErrCode                   ; // ϵͳ����ֵ
	int				m_nWidth                     ;
    CString			m_sVersion                   ; // �汾��  
    int				m_nStatus                    ; //
	long			m_nRouteID					 ; // Ӧ��·��ID��ʶ
	long			m_nLastRouteID				 ; // 
    CString			m_sDest , m_sRemote          ; // ֱ�����ӵ�IP/SPX��ַ
	CString			m_sUser , m_sNode  ,m_sLY  ; // ��Ա�š�������ַ��ί����Դ��
	CString			m_sBranch , m_sDestBranch        ; // ��Ա����Ӫҵ����š�Ŀ��Ӫҵ�����(����·�ɵ����)��    
	CStringArray	m_arSvrList					 ; // �������б�
	int				m_nSvrIndex					 ;
    int             m_nCompressLevel;
    char            *m_pData1                  ;//����ѹ��ǰ����
    char            *m_pData2                  ;//����ѹ��������
    char			m_cBodySplit               ;// ���ķָ���,�ָ���ͷ������
private:
//	bool            bInReadAnswer;				//���ڿ����˳���ȡ
//	bool			bCancelRead;				//���ڿ����˳���ȡ
};

#endif // !defined(AFX_FIXCOMM_H__5FD3A646_FDB8_477E_8BA4_7E5CD9FCB9A5__INCLUDED_)
