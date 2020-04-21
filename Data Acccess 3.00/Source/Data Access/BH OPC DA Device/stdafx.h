//============================================================================
// TITLE: StdAfx.h
//
// CONTENTS:
// 
// This file standard precompiled include files.
//
// (c) Copyright 2003 The OPC Foundation
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
// 2003/09/09 RSA   First release.
//
#define _CRTDBG_MAP_ALLOC
#ifndef _StdAfx_H
#define _StdAfx_H
#define WINVER 0x0501
#define _WIN32_WINNT WINVER
#if _MSC_VER >1600  //VS2010
#pragma comment (lib,"legacy_stdio_definitions.lib") //FOR VS2015 
#endif

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#ifndef AFX_IMPORT_DATA
#define AFX_IMPORT_DATA __declspec(dllimport)
#endif
// Insert your headers here
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <afxwin.h>
#include <afxext.h>
#include <afxole.h>
#include <afxodlgs.h>
#include <afxrich.h>
#include <afxhtml.h>
#include <afxcview.h>
#include <afxwinappex.h>
#include <afxframewndex.h>
#include <afxmdiframewndex.h>

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


#include "FixDef.h"
#include "FixDef_Daq.h"
#include "FixDef_Field.h"

//#include <CBHFixCom_i.h>

#define TAG_XML           _T("XML")
#define TAG_NAME          _T("Name")
#define TAG_SEPARATOR     _T("/")
#define TAG_PROPERTY_ID   _T("PropertyID")
#define TAG_PERIOD        _T("Period")
#define TAG_SAMPLING_RATE _T("SamplingRate")
#define TAG_MAX_VALUE     _T("MaxValue")
#define TAG_MIN_VALUE     _T("MinValue")
#define TAG_WAVEFORM      _T("Waveform")
#define TAG_DICTIONARY    _T("Dictionary")

#define MAX_SAMPLING_RATE 2000

#define TAG_SEPARATOR      _T("/")
#define TAG_BROWSE_ELEMENT _T("BrowseElement")
#define TAG_ELEMENT_NAME   _T("ElementName")
#define TAG_ITEM           _T("Item")
#define TAG_CHILD_ELEMENTS _T("Children")

#define TAG_CBHFIXCOM _T("CBHFixCom.dll")
#define TAG_DEFAULT_SET_NAME _T("Default Set")
#define TAG_DEFAULT_GROUP_NAME _T("Default Group")

#ifdef _DEBUG
#import "debug\CBHFixCom.dll" no_namespace
#else
#import "release\CBHFixCom.dll" no_namespace
#endif
#endif // _StdAfx_H
