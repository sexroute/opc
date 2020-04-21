#include "stdafx.h"
#include "export.h"
#define MAX_NAMELEN 100

CALLBACK_EXPORT_API bool __stdcall login(const char * username, const char * password, const char * domain)
{
	USES_CONVERSION;

	if (NULL == username || NULL == password )
	{
		return false;
	}

	char cUserName[1000] = { 0 };
	char cPassword[1000] = { 0 };


	int lncUserName = strlen(username);
	int lncPassword = strlen(password);

	if (lncUserName > MAX_NAMELEN - 1)
	{
		lncUserName = MAX_NAMELEN - 1;
	}

	if (lncPassword > MAX_NAMELEN - 1)
	{
		lncPassword = MAX_NAMELEN - 1;
	}
	strncpy_s(cUserName, username, lncUserName);
	strncpy_s(cPassword, password, lncPassword);

	HRESULT hr;

	CString lstrUser = A2T(cUserName);
	CString lstrPassword = A2T(cPassword);
	SEC_WINNT_AUTH_IDENTITY_W m_oWINNT_AuthIdentity;

	SecureZeroMemory(&m_oWINNT_AuthIdentity, sizeof(m_oWINNT_AuthIdentity));
	WCHAR * lpUser = T2W(lstrUser.GetBuffer(0));
	WCHAR * lpPassword = T2W(lstrPassword.GetBuffer(0));
	m_oWINNT_AuthIdentity.User = (USHORT *)lpUser; ////Äã»ú×ÓµÄÕÊºÅ
	m_oWINNT_AuthIdentity.UserLength = wcslen(lpUser);
	m_oWINNT_AuthIdentity.Domain = NULL;
	m_oWINNT_AuthIdentity.DomainLength = 0;
	m_oWINNT_AuthIdentity.Password = (USHORT *)lpPassword; ////ÃÜÂë
	m_oWINNT_AuthIdentity.PasswordLength = wcslen(lpPassword);
	m_oWINNT_AuthIdentity.Flags = SEC_WINNT_AUTH_IDENTITY_UNICODE;

	SOLE_AUTHENTICATION_INFO authInfo[2];
	SecureZeroMemory(&authInfo, sizeof(SOLE_AUTHENTICATION_INFO) * 2);



	// NTLM Settings   
	authInfo[0].dwAuthnSvc = RPC_C_AUTHN_WINNT;
	authInfo[0].dwAuthzSvc = RPC_C_AUTHZ_NONE;
	authInfo[0].pAuthInfo = &m_oWINNT_AuthIdentity;

	// Kerberos Settings   
	authInfo[1].dwAuthnSvc = RPC_C_AUTHN_GSS_KERBEROS;
	authInfo[1].dwAuthzSvc = RPC_C_AUTHZ_NONE;
	authInfo[1].pAuthInfo = &m_oWINNT_AuthIdentity;

	SOLE_AUTHENTICATION_LIST    authentlist;
	authentlist.cAuthInfo = 1;
	authentlist.aAuthInfo = authInfo;


	hr = CoInitializeSecurity(
		NULL,                       // security descriptor
		-1,                          // use this simple setting
		NULL,                        // use this simple setting
		NULL,                        // reserved
		RPC_C_AUTHN_LEVEL_NONE,   // authentication level  
		RPC_C_IMP_LEVEL_IMPERSONATE, // impersonation level
		&authentlist,                        // use this simple setting
		EOAC_NONE,                   // no special capabilities
		NULL);                          // reserved


	//ASSERT(SUCCEEDED(hr));

	CString lstrLog;
	lstrLog.Format(_T("%x\r\n"), hr);
	//AfxMessageBox(lstrLog, MB_OK);
	OutputDebugString(lstrLog);

	if (SUCCEEDED(hr))
	{
		return true;
	}

	return false;
}
