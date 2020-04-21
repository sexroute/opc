// dcomse.h : main header file for the dcomse DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CdcomseApp
// See dcomse.cpp for the implementation of this class
//

class CdcomseApp : public CWinApp
{
public:
	CdcomseApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
