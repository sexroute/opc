//==============================================================================
// TITLE: XxxDaServer.cpp
//
// CONTENTS:
// 
// Implements the required COM server functions.
//
// (c) Copyright 2002-2003 The OPC Foundation
// ALL RIGHTS RESERVED.
//
// DISCLAIMER:
//  This code is provided by the OPC Foundation solely to assist in 
//  understanding and use of the appropriate OPC Specification(s) and may be 
//  used as set forth in the License Grant section of the OPC Specification.
//  This code is provided as-is and without warranty or support of any sort
//  and is subject to the Warranty and Liability Disclaimers which appear
//  in the printed OPC Specification.
//
// MODIFICATION LOG:
//
// Date       By    Notes
// ---------- ---   -----
// 2002/11/16 RSA   First release.
//

#include "StdAfx.h"
#include "CBHOpcDaServer.h"

#pragma warning(disable:4192)

//================================================================================
// COM Module Declarations

OPC_DECLARE_APPLICATION(DAQGateWay, BHOpcDaServer, "BH OPC SERVER")

OPC_BEGIN_CLASS_TABLE()
    OPC_CLASS_TABLE_ENTRY(CBHOpcDaServer, BHOpcDaServer, 1, "BH OPC SERVER")
OPC_END_CLASS_TABLE()

OPC_BEGIN_CATEGORY_TABLE()
    OPC_CATEGORY_TABLE_ENTRY(BHOpcDaServer, CATID_OPCDAServer20, OPC_CATEGORY_DESCRIPTION_DA20_T)
    OPC_CATEGORY_TABLE_ENTRY(BHOpcDaServer, CATID_OPCDAServer30, OPC_CATEGORY_DESCRIPTION_DA30_T)
OPC_END_CATEGORY_TABLE()

#ifndef _USRDLL

// {0DAEAF56-F441-4323-921B-FAD29C60EE40}
//OPC_IMPLEMENT_LOCAL_SERVER(0xdaeaf56, 0xf441, 0x4323, 0x92, 0x1b, 0xfa, 0xd2, 0x9c, 0x60, 0xee, 0x40);
// {B4F944B5-E833-4d8d-B027-F3D8888F74FA}
OPC_IMPLEMENT_LOCAL_SERVER(0xb4f944b5, 0xe833, 0x4d8d, 0xb0, 0x27, 0xf3, 0xd8, 0x88, 0x8f, 0x74, 0xfa);

//================================================================================
// WinMain

extern "C" int WINAPI _tWinMain(
    HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
    LPTSTR    lpCmdLine, 
    int       nShowCmd
)
{
	//MessageBox(NULL,_T("test"),NULL,MB_OK);

	HRESULT hResult = CoInitializeEx(NULL, COINIT_MULTITHREADED);

	COpcSecurity cSecurity;

	 hResult = cSecurity.InitializeFromThreadToken();

	if (FAILED(hResult))
	{
		return hResult;
	}

	hResult = CoInitializeSecurity(
		cSecurity,
		-1,
		NULL,
		NULL,
		RPC_C_AUTHN_LEVEL_PKT,
		RPC_C_IMP_LEVEL_IMPERSONATE,
		NULL,
		EOAC_NONE,
		NULL);

	bool lbShuldInternalInitialize = false;

	if (lpCmdLine==NULL )
	{
		lbShuldInternalInitialize = true;
	}
	else
	{
		CString lstrCmd = lpCmdLine;

		if (lstrCmd.GetLength()==0)
		{
			lbShuldInternalInitialize = true;
		}
	}
	
	if (lbShuldInternalInitialize)
	{
		InternalInitialize();
	}

    OPC_START_LOCAL_SERVER_EX(hInstance, lpCmdLine);

    return 0;
}

#else

OPC_IMPLEMENT_INPROC_SERVER();

//==============================================================================
// DllMain

extern "C"
BOOL WINAPI DllMain( 
    HINSTANCE hModule, 
    DWORD     dwReason, 
    LPVOID    lpReserved)
{

	OPC_START_INPROC_SERVER(hModule, dwReason);
    return TRUE;
}

#endif // _USRDLL
