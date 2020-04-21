
// ACI.h: 
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACI_H__A2573801_5B07_11D3_B19A_0080C7E591A2__INCLUDED_)
#define AFX_ACI_H__A2573801_5B07_11D3_B19A_0080C7E591A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifndef __ACI__
#define __ACI__
//#define _MAKE_ACI_LIB

#ifndef SHIFT_F4
#define SHIFT_F4 343
#endif

#ifndef F4
#define F4 318
#endif

#ifndef BREAK_KEY
#define BREAK_KEY  27
#endif

#ifndef ESC
#define ESC  27
#endif

#ifndef QUIT_KEY
#define QUIT_KEY  343
#endif

#include  <winsock2.h>
#include <wsipx.h>
#include <io.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#define WIN_SOCK_VER  0X0202   //win socket �汾��
#define MAX_LISTEN_Q    256    //�������д�С





/*    socket ����ѡ��                     */

#define MAX_LOGICAL_LINK   1              //����߼�������
#define MAX_AUTH_TIME      30L            //��Կ������ʱ(��)



#define LO_SVR           0x00000001           //�����
#define LO_SRV           LO_SVR     
#define LO_CLNT          0x00000002           //�ͻ���
#define LO_BLOCK         0x00000004           //������ʽ
#define LO_NBLOCK        0x00000008           //��������ʽ

#define LO_TCP           0x00000010           //TCP����
#define LO_UDP           0x00000020           //UDP����
#define LO_RAW           0x00000040           //raw����
#define LO_IPX           0x00000080           //IPX����
#define LO_SPX           0x00000100           //SPX����

#define _LO_PARENT       0x00000200           //�����ӣ��ڲ�ʹ��
#define _LO_ROUTE        0x00000400           //·�����ӣ��ڲ�ʹ��
#define LO_LOCAL_ROUTE   0x00000800           //·�����ӣ��ڲ�ʹ��

#define LO_LL            0x00001000           //���ػ�·
#define LO_SLIP          0x00002000           //SLIP����
#define LO_PPP           0x00004000           //PPP����
#define LO_SM            0x00008000           //����modem


/*io��������SLIP��ʹ�ú궨��*/
//#define IOS_MAX_ROW_SIZE    4096            //SLIP����󳤶�
//AK47//#define IOS_MAX_ROW_SIZE    4096            //SLIP����󳤶�
#define IOS_MAX_ROW_SIZE    102400            //SLIP����󳤶�


#define MAX_ROW_SIZE        IOS_MAX_ROW_SIZE 
#define MAX_PACK_SIZE       IOS_MAX_ROW_SIZE
#define MAX_RCVPACK_SIZE    IOS_MAX_ROW_SIZE
#define MAX_SNDPACK_SIZE    IOS_MAX_ROW_SIZE

#define IOS_INC_BUF_SIZE    128            //������������(�ֽ�)
#define IOS_MAX_BUF_SIZE    5L*1024L       //���������
#define IOS_ITERM_SIZE      IOS_INC_BUF_SIZE 



/*���ͽ���״̬����*/
#define RS_FREE          0                 //����
#define RS_WRITING	 1
#define RS_WRITED	 2
#define RS_SNDING	 3
#define RS_SNDED	 4
#define RS_RCVING	 5
#define RS_RCVED	 6
#define RS_READING	 7
#define RS_READED	 8
#define RS_TIMEOUT       -1                 //��ʱ

/*SLIP����������ת�������*/

#define SLIPSE         '\xC0'          //SLIP��������
#define SLIPSS         SLIPSE
#define SLIPESC        '\xDB'          //SLIP��ת���

#undef max
#undef min
#undef MAX
#undef MIN
#define max(a,b)    ((a)>(b)?(a):(b))
#define min(a,b)    ((a)>(b)?(b):(a))
#define MAX(a,b)    ((a)>(b)?(a):(b))
#define MIN(a,b)    ((a)>(b)?(b):(a))

#define MIN_LINK_DELAY 2   //seconds
#define MAX_TRY_COUNT 10


#define E_RW_PACK_TOO_SMALL  -1000          //��̫С
#define E_RW_PACK_TOO_LONG   -1010          //��̫��
#define E_IOS_ROW_TOO_MORE  -1001

#define E_RW_RS_NO_FREE      -2000
#define E_RW_RS_READ         -2010

#define E_USER_ABORT         -3000          //�û��ж�

#define E_NO_CARRIER         -4000

#define E_TIMEOUT            -5000          //��ʱ
#define E_REQUEST_TIMEOUT    -5010          //Ӧ��ʱ

#define E_USER_NAME          -6000          //
#define E_USER_PASS          -6010          //
#define E_SERVICE_DENY       -6020          //�ܾ�����
#define E_NOT_SERVICE_TIME   -6030          //�Ƿ���ʱ��
#define E_SERVER_BUSY        -6040          //�����æ

#define E_CRC                -7000          //CRCЧ���
#define E_PACK_SERIAL_NO     -7010	    //�Ƿ������

#define E_NO_MORE_PORT	     -9000
#define E_NO_MORE_MEMORY     -9010




#define MAX_CARRY_TIME 10
#define MAX_COM_LINE   256

typedef enum enuCOMLINKSTAT {
	L_NULL=-1,
        A_NO_ACTION=0,
		L_DEAD,
		L_OPENED,
		L_SETUP,
		L_ESTABLISHED,
		L_AUTHENTICATED,
		L_SUCCESS,
		L_NLP,
		L_CLOSING,
		L_TERMINATED,
		A_TFLUSH,
		A_TCLOSE,
		A_TDELAY1,
		A_TDELAY2,
		L_FAIL,
		L_TIMEOUT,
} COMLINKSTAT;

typedef int (* COMFUNC)(const char *,int ,char *,int *);


#define IOS_BUF_DYNAMIC   0x000000001     
#define IOS_BUF_UNLIMIT	  0x000000004

#define IOS_BUF_MEM_BASIC 0x00000010
#define IOS_BUF_MEM_EXT   0x00000020
#define IOS_BUF_SWAP_FILE 0x00000040

typedef struct tagRELINKSVRINFO
{
	int port;
	unsigned int protocol;
	int svrno;
	char addr[4][30];
} RELINKSVRINFO;

typedef struct tagSVRINFO
{
	
	char ipaddr[16];	//���10����ip��ַ��������,��117.1.1.1,XXXUNIX,XXXPC etc
	int tcpsocket;	//TCP�˿�-�����ֽ���
	int spxsocket;	//SPX�˿�-�����ֽ���
	char network[16];//���κ�
	char node[16];	   	   
	unsigned long sendcount;
	unsigned long receivecount;
	unsigned long routercount;
	unsigned long begin_time;
	int linkables;
	int routerlinks;
	int activelinks;
	int clientlinks;
	unsigned long memused;
	char localname[20];
} SVRINFO;

/*·����Ϣ*/
typedef struct tagACIROUTEINFO
{
    char name[20];    //·������
    char addr[40];    //��ַ:net,node,port/spx or ipaddr,port/tcp
    int active;       //0-noactive,1-active
	int isroute;
    long lasttime;    //last ping time
    struct tagACIROUTEINFO *pnext;
} ACIROUTEINFO;

/*�����������õ�������ַ*/
typedef struct tagACIHOSTADDR 
{
    char addr[40];    //��ַ:192.168.0.254,��00000000��1234567890AC��
    struct tagACIHOSTADDR *pnext;
} ACIHOSTADDR;


/* IO������  */
typedef struct tagIOSITERM
{
	char buf[IOS_ITERM_SIZE];
	struct tagIOSITERM * pnext;
} IOSITERM;




typedef struct tagIOS
{
	IOSITERM *f,*r,*p;
	int nr,nf,np;
	int type;
	unsigned long size;
}  IOS;

typedef struct tagIOSPOOL
{
	int nowlink;
	IOS pool[MAX_LOGICAL_LINK];
}  IOSPOOL;

#define IOSIsBufFrozen(a)	(((a)->type)&IOS_BUF_FROZEN)
#define IOSIsBufDynamic(a)	(((a)->type)&IOS_BUF_DYNAMIC)
#define IOSIsBufUnlimit(a)	(((a)->type)&IOS_BUF_UNLIMIT)
#define IOSIsBufMemBasic(a)	(((a)->type)&IOS_BUF_MEM_BASIC)
#define IOSIsBufMemExt(a)	(((a)->type)&IOS_BUF_MEM_EXT)
#define IOSIsBufSwapFile(a)	(((a)->type)&IOS_BUF_SWAP_FILE)




#define MAX_USER_STR_LEN 128
typedef struct tagSysWord
{
	int t_count;
	char  is_rcv_cx;
} _Sys_Word;

/*������Ϣ*/
typedef struct tagINNERLINKINFO
{
	char remote[20];                       //���������
	   char routename[20];
       char linkkey[9];                        //���Ч����Կ
       int  idx;                             //�ڲ�������
       struct sockaddr_in localaddr;           //���ص�ַ�ṹ
	   struct sockaddr_in raddr;               
       SOCKADDR_IPX ipxaddr;                   //ipx��ַ�ṹ
	   SOCKADDR_IPX ripxaddr;                   
       short h;                                //SOCKET ���
       int port;                             //�˿�-�����ֽ���
       char addr[16];                          //���10����ip��ַ��������,��117.1.1.1,XXXUNIX,XXXPC etc
       char network[16];                       //���κ�
	   unsigned long sndcount;
	   unsigned long rcvcount;
       unsigned long routercount;
       long begin_clock;
	   
	   
       unsigned long type;                    //��������TCP/UDP,BLOCK/NON_BLOCK,SERVER/CLIENT
       int status;                           //����״̬
       int action;                           //�²�����
       long last_rw_clock;                     //ǰ�ζ�дʱ��,�����һ�ν��������д�ɹ�ʱ��
       unsigned long option;                  //����ѡ��
       int relink;                           //�����Ӵ���
	   union tagWord{
		   char userstr[MAX_USER_STR_LEN];
		   _Sys_Word s_w;
	   } k_w;
	   int isfrozen;
	   int isappown;
	   int isnew;
} _INNERLINKINFO;

typedef struct tagLINKINFO
{
	char network[16];                       //���κ�
	char addr[16];                          //���10����ip��ַ��������,��117.1.1.1,XXXUNIX,XXXPC etc
	int  port;
	char remotenetwork[16]; 
	   char remoteaddr[16];
	   int  remoteport;
	   unsigned long sendcount;
	   unsigned long receivecount;
       unsigned long begin_clock;
	   int idx;
	   char userstr[MAX_USER_STR_LEN];
} LINKINFO;

typedef struct tagACI
{
	_INNERLINKINFO linfo;	
	IOSPOOL rpool;
	IOSPOOL spool;
	IOSPOOL spool0;
	struct tagACI *pNext;
	struct tagACI *pPrevious;
	struct tagACI *pPeer;
	RELINKSVRINFO  *relinksvrinfo;
	
} ACI ;


typedef struct tagLinkTable
{
	ACI *link[MAX_COM_LINE];
	DWORD linkno[MAX_COM_LINE];
    ACIROUTEINFO *route;
} ACILINKTABLE;


#define ACIIsSvr(a)  ((((a)->linfo.type)&LO_SVR)==LO_SVR)
#define ACIIsSrv     ACIIsSvr
#define ACIIsClnt(a) ((((a)->linfo.type)&LO_CLNT)==LO_CLNT)
#define ACIIsTCP(a)  ((((a)->linfo.type)&LO_TCP)==LO_TCP)
#define ACIIsUDP(a)  ((((a)->linfo.type)&LO_UDP)==LO_UDP)
#define ACIIsIPX(a)  ((((a)->linfo.type)&LO_IPX)==LO_IPX)

#define ACIIsSPX(a)  ((((a)->linfo.type)&LO_SPX)==LO_SPX)
#define ACIIsPPP(a)  ((((a)->linfo.type)&LO_PPP)==LO_PPP)
#define ACIIsSLIP(a)  ((((a)->linfo.type)&LO_SLIP)==LO_SLIP)
#define ACIIsBLOCK(a)  ((((a)->linfo.type)&LO_BLOCK)==LO_BLOCK)
#define ACIIsNBLOCK(a)  ((((a)->linfo.type)&LO_NBLOCK)==LO_NBLOCK)
#define ACIIsRAW(a)  ((((a)->linfo.type)&LO_RAW)==LO_RAW)
#define ACIIsParent(a)  ((((a)->linfo.type)&_LO_PARENT)==_LO_PARENT)
#define ACIIsRoute(a)  ((((a)->linfo.type)&_LO_ROUTE)==_LO_ROUTE)
#define ACIIsLocalRoute(a)  ((((a)->linfo.type)&LO_LOCAL_ROUTE)==LO_LOCAL_ROUTE)
#define ACIIsChild(a)  (!ACIIsParent(a))



#define      DTO_DEBUG        0x00000001
#define      DTO_CRYPT        0x00000002
#define      DTO_PACK         0x00000004
#define      DTO_CRC          0x00000008
#define ACIIsDTOCRYPT(a)  ((((a)->linfo.option)&DTO_CRYPT)==DTO_CRYPT)
#define ACIIsDTOPACK(a)  ((((a)->linfo.option)&DTO_PACK)==DTO_PACK)
#define ACIIsDTOCRC(a)  ((((a)->linfo.option)&DTO_CRC)==DTO_CRC)


extern   int  ACIErrno;
extern   char ACIErrlist[];
#define  ACIDebug(status)      (status? ACISetOpt(NULL,DTO_DEBUG):ACIUnSetOpt(NULL,DTO_DEBUG))
AFX_API_EXPORT  void  ACIFrozen(ACI *pACI);
AFX_API_EXPORT  void  ACIUnFrozen(ACI *pACI);
AFX_API_EXPORT  void  ACIAppOwn(ACI *pACI);
AFX_API_EXPORT  void  ACIAppUnOwn(ACI *pACI);

AFX_API_EXPORT  void ACISetIdx(ACI *pACI,int idx);
AFX_API_EXPORT	void SBegin(void );
AFX_API_EXPORT	void SSEnd(void );
AFX_API_EXPORT  int SSpaceleft(void );
AFX_API_EXPORT  void SFree( IOSITERM *p);
AFX_API_EXPORT  int SFpIsSet( IOS *ios);
AFX_API_EXPORT  int SPpIsSet( IOS *ios);
AFX_API_EXPORT  void SResetp( IOS *ios);
AFX_API_EXPORT  int SPutnc( IOS *ios,char *buf,int len);
AFX_API_EXPORT  void SBackword( IOS *ios, IOSITERM *iterm,int nsav,long nsavsize);
AFX_API_EXPORT  int SGetnc( IOS *ios,char *buf,int len);
AFX_API_EXPORT  int SPeeknc( IOS *ios,char *buf,int len);
AFX_API_EXPORT  void SIgnorenc( IOS *ios,int len);
AFX_API_EXPORT  void SClearBuf( IOS *ios);
AFX_API_EXPORT  void SSetBuf( IOS *ios,char *buf,int size,int dtopt);
AFX_API_EXPORT  int SSlipUnPack( IOS *ios,char *bufout,int outlen);
AFX_API_EXPORT  int SSlipPack( IOS *ios,const char *bufin,int inlen);
AFX_API_EXPORT  unsigned long SIterms(void);





AFX_API_EXPORT void ACIInstallErrProc( int (*eproc)(ACI *pACI,int stat),int relink);
AFX_API_EXPORT void ACISetPackFunc(ACI *pACI,COMFUNC func);
AFX_API_EXPORT void ACISetUnPackFunc(ACI *pACI,COMFUNC func);
AFX_API_EXPORT void ACISetEnCodeFunc(ACI *pACI,COMFUNC func);
AFX_API_EXPORT void ACISetUnCodeFunc(ACI *pACI,COMFUNC func);
AFX_API_EXPORT void ACISetCRCFunc(ACI *pACI,COMFUNC func);
AFX_API_EXPORT void ACISetTranFunc(ACI *pACI,COMFUNC func);

AFX_API_EXPORT void ACIClearSndBuf(ACI *pACI);
AFX_API_EXPORT void ACIClearRcvBuf(ACI *pACI);
AFX_API_EXPORT void ACIClearBuf(ACI *pACI);

AFX_API_EXPORT char *SPXGetNetWork(ACI *pACI,char *netstr);
#define ACIGetNetWork      SPXGetNetWork

AFX_API_EXPORT char *SPXGetNetNode(ACI *pACI,char *netnode);
#define ACIGetNetNode SPXGetNetNode

AFX_API_EXPORT char *GetIPAddr( char *ipaddr);
#define ACIGetIPAddr GetIPAddr

#define  ACIGetPort(a)  ((a)->linfo.port)

AFX_API_EXPORT   char *SPXGetRemoteNetWork(ACI *pACIchild,char *netstr);
#define  ACIGetRemoteNetWork SPXGetRemoteNetWork

AFX_API_EXPORT   char *SPXGetRemoteNetNode(ACI *pACIchild,char *netnode);
#define ACIGetRemoteNetNode SPXGetRemoteNetNode

AFX_API_EXPORT   char *GetRemoteIPAddr(ACI *pACIchild,char *ipaddr);
#define ACIGetRemoteIPAddr GetRemoteIPAddr

AFX_API_EXPORT   int GetRemotePort(ACI *pACIchild);
#define ACIGetRemotePort GetRemotePort

AFX_API_EXPORT   int  ACIGetActiveLinks(void);
AFX_API_EXPORT   int  ACIGetClientLinks(void);

AFX_API_EXPORT   char  *ACIGetSvrLink(ACI *pACI,char *bufout);
AFX_API_EXPORT   char  *ACIGetClntLink(ACI *pACIchild,char *bufout);


AFX_API_EXPORT   void ACITimeOut(u_long time);
AFX_API_EXPORT   void ACISetAuthTimeOut(unsigned long t);//�趨�ͻ������ӳ�ʱ����

AFX_API_EXPORT   int ACIInit(void );
AFX_API_EXPORT   long ACIVersion(void );
AFX_API_EXPORT   char  *ACIGetLastErrStr(void);
AFX_API_EXPORT   char  *ACIGetUserStr(ACI *pACI,char *strout);
AFX_API_EXPORT   void ACISetUserStr(ACI *pACI,const char *strin);
AFX_API_EXPORT   void ACIAppendUserStr(ACI *pACI,const char *strin);

AFX_API_EXPORT   int ACIGetLastErr(void);
AFX_API_EXPORT   void  ACISetOpt(ACI *pACI,int option);
AFX_API_EXPORT   void  ACIUnSetOpt(ACI *pACI,int option);
AFX_API_EXPORT   int ACIPing(char *server,int timeout); //time:second

AFX_API_EXPORT   int  RandNo(int svrno);
AFX_API_EXPORT HANDLE ACIGetMute(void);
AFX_API_EXPORT void   ACIInitEntry(unsigned long entry,int max_links,const char *local_name,ACIROUTEINFO *router_table);
AFX_API_EXPORT unsigned long ACIGetEntry(void);
AFX_API_EXPORT void   ACIGetSvrInfo(SVRINFO *svrinfo);
AFX_API_EXPORT void ACISetEntry(unsigned long entry);
AFX_API_EXPORT void ACIReSetEntry(void);
AFX_API_EXPORT void ACIDeleteEntry(unsigned long entry);

AFX_API_EXPORT   ACI *ACIOpen(const char *linkstr,unsigned int option);
AFX_API_EXPORT   ACI *ACIOpenRemote(const char *linkstr,unsigned int option,const char *remotename);
AFX_API_EXPORT   ACI *ACIReOpen(ACI *pACI);
AFX_API_EXPORT   int ACIRun(void);
AFX_API_EXPORT   int ACIGetLinkables(void);
AFX_API_EXPORT   ACIHOSTADDR *ACIGetHostAddrByName(const char *hostname,unsigned int addrtype);

#define  ACIGetLines   ACIGetLinkables

AFX_API_EXPORT   ACI *ACIFindChild(ACI *pACI,int whichchild);
AFX_API_EXPORT   ACI *ACIFindChild(ACI *pFather,ACI *pChild);
AFX_API_EXPORT   ACI *ACIFindChildOld(ACI *pFather,int whichchild);

AFX_API_EXPORT   ACI *ACIFindNewChild(ACI *pACI);
AFX_API_EXPORT   ACI *ACIFindClnt(void);
AFX_API_EXPORT   void ACIGetLinkInfo(ACI *pACI,LINKINFO *linfo);
AFX_API_EXPORT  int ACIWrite(ACI *pACI, const char *s,int len);
AFX_API_EXPORT  int ACIWriteBuf(ACI *pACI,const char *s,int len);
AFX_API_EXPORT  int ACIWriteMore(ACI *pACI,const char *bin,int len);
AFX_API_EXPORT  int ACIWriteCX(ACI *pACI);
AFX_API_EXPORT  void ACIFlush(ACI *pACI);

AFX_API_EXPORT  int ACIRead(ACI *pACI, char *s,int len);
AFX_API_EXPORT  BOOL ACIIsDead(ACI *pACI);

AFX_API_EXPORT  int ACIReadMore(ACI *pACI,char *bin,int len);



AFX_API_EXPORT  int ACIGetFile(ACI *pACI,char *rfname,char *lfname);
AFX_API_EXPORT  int ACIPutFile(ACI *pACI,char *lfname,char *rfname);
AFX_API_EXPORT  int ACILoop(ACI *pACI,int timeout);
AFX_API_EXPORT  void  ACISetSndBuf(ACI *pACI,char *buf,int size,int dtoption);
AFX_API_EXPORT  void  ACISetRcvBuf(ACI *pACI,char *buf,int size,int dtoption);

AFX_API_EXPORT  void ACIClose(ACI *pACI);
AFX_API_EXPORT	void ACIExit(void );

AFX_API_EXPORT	unsigned long ACISndCount(void);
AFX_API_EXPORT  unsigned long ACIRcvCount(void);


AFX_API_EXPORT	void  ACIAddRoute(const char *routename,const char *addr);
AFX_API_EXPORT	void  ACIDeleteRoute(const char *routename);
AFX_API_EXPORT	void  ACIDeleteAllRoute(void);
AFX_API_EXPORT	void  ACILinkRemote(ACI *pACI,const char *remotename);
AFX_API_EXPORT  void  ACISetLocalName(const char *name);
AFX_API_EXPORT  char  *ACIGetLocalName(void);


AFX_API_EXPORT  ACIROUTEINFO * ACIGetRoute(const ACIROUTEINFO *routeinfo);
#define ACIGetRouteName(a)   ((a)?((a)->name):(""))
#define ACIGetRouteAddrEx(a)   ((a)?((a)->addr):(""))
#define ACIGetRemote(a)   ((a)->linfo.remote)
AFX_API_EXPORT  unsigned long ACIRouterCount(void);
#define ACIRouteCount ACIRouterCount
AFX_API_EXPORT  int ACIRouterLinks(void);
#define ACIRouteLinks ACIRouterLinks
AFX_API_EXPORT  unsigned long ACIMemUsed();



AFX_API_EXPORT void ACIAddValidRemoteAddr(const char *addr);
AFX_API_EXPORT int ACIIsValidRemoteAddr(const char *addr);
AFX_API_EXPORT void ACIDeleteValidRemoteAddr(const char *addr);
AFX_API_EXPORT void ACIDeleteAllValidRemoteAddr(void);
AFX_API_EXPORT int  ACIIsReady(ACI *pACI);
AFX_API_EXPORT int	ACISetFunc( int nType, void *pFunc );


#endif

#endif // !defined(AFX_ACI_H__A2573801_5B07_11D3_B19A_0080C7E591A2__INCLUDED_)
