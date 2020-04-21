//============================================================================
// TITLE: StdAfx.h
//
// CONTENTS:
// 
// This file standard precompiled include files.
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
#define _CRTDBG_MAP_ALLOC
#ifndef _StdAfx_H
#define _StdAfx_H
#define WINVER 0x0501
#define _WIN32_WINNT 0x0501
#define _WIN32_WINNT 0x0501
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// Insert your headers here
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers


#if _MSC_VER >1600  //VS2010
#pragma comment (lib,"legacy_stdio_definitions.lib") //FOR VS2015 
#endif

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>        // MFC support for Internet Explorer 4 Common Controls
#include <afxcmn.h>            // MFC support for Windows Common Controls

//#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <objbase.h>
#include <olectl.h>
#include <comcat.h>

#include <map>
#include <vector>
#include "OpcUtils.h"
#include "opcda.h"
#include "opcerror.h"

#include <CBHFixCom_i.c>
//#include <CBHFixCom_i.h>

#ifdef _DEBUG
#import "debug\CBHFixCom.dll" no_namespace
#else
#import "release\CBHFixCom.dll" no_namespace
#endif

#endif // _StdAfx_H
