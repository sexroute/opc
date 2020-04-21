/**************************************************************/
//项目：邮件发送类
//作者：changshidong 
//时间：2010年12月
//版本：ver 1.0.0.0
/**************************************************************/
#pragma once
#include <winsock2.h>
#include <assert.h>

#pragma comment(lib, "ws2_32.lib")

#pragma warning(push)
#pragma warning(disable:4786)

#include <vector>
#include <string>

#define BUFFER_SIZE 10240	  // 
#define DELAY_IN_MS 10			// 
#define MSG_SIZE_IN_MB 5

const char BOUNDARY_TEXT[] = "__MESSAGE__ID__54yg6f6h6y456345";

#ifdef EMAILSEND_EXPORT
#define _LIB_EXPORT __declspec(dllexport)
#else
#define _LIB_EXPORT __declspec(dllimport)
//#pragma comment(lib,"BHXZEmailtoSend.lib")
#endif // EMAILSEND_EXPORT;


enum CSmtpError
{
	CSMTP_NO_ERROR = 0,
	CSMTP_WSA_STARTUP = 100, // WSAGetLastError()
	CSMTP_WSA_VER,
	CSMTP_WSA_SEND,
	CSMTP_WSA_RECV,
	CSMTP_WSA_CONNECT,
	CSMTP_WSA_GETHOSTBY_NAME_ADDR,
	CSMTP_WSA_INVALID_SOCKET,
	CSMTP_WSA_HOSTNAME,
	CSMTP_BAD_IPV4_ADDR,
	CSMTP_UNDEF_MSG_HEADER = 200,
	CSMTP_UNDEF_MAILFROM,
	CSMTP_UNDEF_SUBJECT,
	CSMTP_UNDEF_RECIPENTS,
	CSMTP_UNDEF_LOGIN,
	CSMTP_UNDEF_PASSWORD,
	CSMTP_UNDEF_RECIPENT_MAIL,
	CSMTP_COMMAND_MAIL_FROM = 300,
	CSMTP_COMMAND_EHLO,
	CSMTP_COMMAND_AUTH_LOGIN,
	CSMTP_COMMAND_DATA,
	CSMTP_COMMAND_QUIT,
	CSMTP_COMMAND_RCPT_TO,
	CSMTP_MSG_BODY_ERROR,
	CSMTP_CONNECTION_CLOSED = 400, // by server
	CSMTP_SERVER_NOT_READY,       // remote server
	CSMTP_FILE_NOT_EXIST,
	CSMTP_MSG_TOO_BIG,
	CSMTP_BAD_LOGIN_PASS,
	CSMTP_UNDEF_XYZ_RESPOMSE,
	CSMTP_LACK_OF_MEMORY
};

enum CSmptXPriority
{
	XPRIORITY_HIGH = 2,
	XPRIORITY_NORMAL = 3,
	XPRIORITY_LOW = 4
};

class _LIB_EXPORT CBHXZEmailtoSend
{
public:
	CBHXZEmailtoSend();
	virtual ~CBHXZEmailtoSend();

public:
	//接收和信件处理相关函数
	bool AddRecipient(const char *email, const char *name=NULL);
	bool AddBCCRecipient(const char *email, const char *name=NULL);
	bool AddCCRecipient(const char *email, const char *name=NULL);    
	bool AddAttachment(const char *path);   
	const unsigned int GetBCCRecipientCount();    
	const unsigned int GetCCRecipientCount();
	const unsigned int GetRecipientCount();    
	const char* const GetLocalHostIP();
	const char* const GetLocalHostName();    
	const char* const GetMessageBody();    
	const char* const GetReplyTo();
	const char* const GetMailFrom();
	const char* const GetSenderName();
	const char* const GetSubject();    
	const char* const GetXMailer();
	CSmptXPriority GetXPriority();
	CSmtpError GetLastError();
	bool Send();
	void SetMessageBody(const char*);
	void SetSubject(const char*);
	void SetSenderName(const char*);
	void SetSenderMail(const char*);
	void SetReplyTo(const char*);
	void SetXMailer(const char*);
	void SetLogin(const char*);
	void SetPassword(const char*);
	void SetXPriority(CSmptXPriority);
	void SetSMTPServer(const char* server,const unsigned short port=0);

	//本类是一次性设置参数，执行发送，如果想分布进行
	//（比如先连接，登陆验证，发送内容，发送附件，关闭等）可再次封装

protected:
	CSmtpError m_oError;
	char* m_pcLocalHostName;
	char* m_pcMailFrom;
	char* m_pcNameFrom;
	char* m_pcSubject;
	char* m_pcMsgBody;
	char* m_pcXMailer;
	char* m_pcReplyTo;
	char* m_pcIPAddr;
	char* m_pcLogin;
	char* m_pcPassword;
	char* m_pcSMTPSrvName;
	unsigned short m_iSMTPSrvPort;
	CSmptXPriority m_iXPriority;
	char *SendBuf;
	char *RecvBuf;



	WSADATA wsaData;
	SOCKET hSocket;

	struct Recipent
	{
		std::string Name;
		std::string Mail;
	};

	std::vector<Recipent> Recipients;
	std::vector<Recipent> CCRecipients;
	std::vector<Recipent> BCCRecipients;
	std::vector<std::string> Attachments;

	bool ReceiveData();
	bool SendData();
	bool FormatHeader(char*);
	int SmtpXYZdigits();
	SOCKET ConnectRemoteServer(const char* server, const unsigned short port=NULL);

	friend char* GetErrorText(CSmtpError);
};
