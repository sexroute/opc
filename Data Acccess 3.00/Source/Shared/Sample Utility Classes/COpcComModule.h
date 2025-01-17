//==============================================================================
// TITLE: COpcComModule.h
//
// CONTENTS:
// 
// A class that manages startup and shutdown of a ComModule.
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
// 2002/09/03 RSA   First release.
//

#ifndef _COpcComModule_H_
#define _COpcComModule_H_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "OpcDefs.h"
#include "COpcString.h"
#include "COpcMap.h"
#include "COpcCriticalSection.h"
#include "COpcClassFactory.h"
#include "COpcXmlElement.h"

//==============================================================================
// CLASS:   COpcComModule
// PURPOSE: Manages initialization and registration of a COM ComModule.

class OPCUTILS_API COpcComModule
{
    OPC_CLASS_NEW_DELETE()

public:

    //==========================================================================
    // Public Operators

    // Constructor
    COpcComModule(
        const COpcString&          cVendorName,
        const COpcString&          cApplicationName,
        const COpcString&          cApplicationDescription,
        const GUID&                cAppID,
        const TOpcClassTableEntry* pClasses,
        const TClassCategories*    pCategories
    );

    // Destructor
    ~COpcComModule();

    //==========================================================================
    // Public Methods

    // ExitProcess
    static void ExitProcess(DWORD dwExitCode);

    // WinMain
    virtual DWORD WinMain(
        HINSTANCE hInstance,  
        LPTSTR    lpCmdLine
    );   

    // ServiceMain
    void ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);

    // EventHandler
    void EventHandler(DWORD fdwControl);

    // RegisterFromFiles
    HRESULT RegisterFromFiles(HINSTANCE hModule);

	// GetConfigParam
	bool GetConfigParam(const COpcString& cName, COpcString& cValue);

protected:

    //==========================================================================
    // Protected Methods

    // RegisterServer
    HRESULT RegisterServer(bool bService);

    // UnregisterServer
    HRESULT UnregisterServer();
    
    // Run
    void Run();

	// GetClassesFromFiles
	TOpcClassTableEntry* GetClassesFromFiles(
		HINSTANCE                  hModule,
		const TOpcClassTableEntry* pClasses,
		COpcString&                cVendorName,
		COpcString&                cApplicationName,
		COpcString&                cApplicationDescription,
		GUID&                      cAppID
	);

	// GetClassesFromRegistry
	TOpcClassTableEntry* GetClassesFromRegistry(
		const TOpcClassTableEntry* pClasses);

	// FreeClassTable
	void FreeClassTable(TOpcClassTableEntry* ppClassesFromFile);

	// InsertSelfRegInfo
	HRESULT InsertSelfRegInfo(
		COpcXmlElement&            cRoot,
		const TOpcClassTableEntry* pClasses
	);

    //==========================================================================
    // Protected Members

    HINSTANCE             m_hModule;

    COpcString            m_cVendorName;
    COpcString            m_cApplicationName;
    COpcString            m_cApplicationDescription;
    GUID                  m_cAppID;

	TOpcClassTableEntry*  m_pClasses;
    TClassCategories*     m_pCategories;
    bool                  m_bRegFromFile;
	bool                  m_bEveryone;
	COpcStringMap         m_cParameters;

	bool                  m_bWrapper;
	TOpcClassTableEntry*  m_pWrappedClasses;
    
    DWORD                 m_dwThread;
    SERVICE_STATUS        m_cServiceStatus;
    SERVICE_STATUS_HANDLE m_hServiceStatus;
};


//==============================================================================
// FUNCTION: OpcWinMain
// PURPOSE:  The main entry point for the executable.

extern COpcComModule& OpcGetModule();

//==============================================================================
// FUNCTION: OpcWinMain
// PURPOSE:  The main entry point for the executable.

OPCUTILS_API DWORD OpcWinMain(
    COpcComModule* pModule,
    HINSTANCE      hInstance,  
    LPTSTR         lpCmdLine
);

//==============================================================================
// MACRO:   OPC_DECLARE_APPLICATION
// PURPOSE: Declares the vendor name, the application name and the description.

#define OPC_DECLARE_APPLICATION(xVendor, xName, xDescription) \
static const LPCTSTR g_tsVendorName             = _T(#xVendor); \
static const LPCTSTR g_tsApplicationName        = _T(#xName); \
static const LPCTSTR g_tsApplicationDescription = _T(xDescription); 

//==============================================================================
// MACRO:   OPC_IMPLEMENT_LOCAL_SERVER
// PURPOSE: Declares required functions for a local COM server module.

#define OPC_IMPLEMENT_LOCAL_SERVER(l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
static const GUID g_cAppID = {l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }; \
static COpcComModule* g_pModule = NULL; \
COpcComModule& OpcGetModule() { return *g_pModule; }

//==============================================================================
// MACRO:   OPC_START_LOCAL_SERVER
// PURPOSE: Starts the main execution loop for an EXE COM server.

#define OPC_START_LOCAL_SERVER(xInstance, xCmdLine) \
{ \
    g_pModule = new COpcComModule( \
		g_tsVendorName, \
		g_tsApplicationName, \
		g_tsApplicationDescription, \
		g_cAppID, \
		g_pClassTable, \
		g_pCategoryTable); \
\
    DWORD dwResult = OpcWinMain(g_pModule, xInstance, xCmdLine); \
\
    delete g_pModule; \
	g_pModule = NULL; \
\
    return dwResult; \
}

//==============================================================================
// MACRO:   OPC_START_LOCAL_SERVER_EX
// PURPOSE: Starts the main execution loop for an EXE COM server that uses configuration files.

#define OPC_START_LOCAL_SERVER_EX(xInstance, xCmdLine) \
{ \
    COpcComModule* pModule = new COpcComModule( \
		g_tsVendorName, \
		g_tsApplicationName, \
		g_tsApplicationDescription, \
		g_cAppID, \
		g_pClassTable, \
		g_pCategoryTable); \
\
    pModule->RegisterFromFiles(xInstance); \
\
    DWORD dwResult = OpcWinMain(pModule, xInstance, xCmdLine); \
\
    delete pModule; \
    return dwResult; \
}

//==============================================================================
// MACRO:   OPC_START_INPROC_SERVER
// PURPOSE: Intializes a DLL COM server.

#define OPC_START_INPROC_SERVER(xService, xInstance, xReason) \
{ \
    if (xReason == DLL_PROCESS_ATTACH) g_hModule = xInstance; \
} 

//==============================================================================
// MACRO:   OPC_IMPLEMENT_INPROC_SERVER
// PURPOSE: Declares required functions for an in process COM server module.

#define OPC_IMPLEMENT_INPROC_SERVER() \
STDAPI DllCanUnloadNow(void) { return S_FALSE; } \
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) { return OpcGetClassObject(rclsid, riid, ppv, g_pClassTable); } \
\
STDAPI DllRegisterServer(void) \
{ \
	return OpcRegisterServer( \
		g_hModule, \
		g_tsVendorName, \
		NULL, \
		NULL, \
		GUID_NULL, \
		false, \
		g_pClassTable, \
		g_pCategoryTable); \
} \
\
STDAPI DllUnregisterServer(void) \
{ \
	return OpcUnregisterServer( \
		g_hModule, \
		g_tsVendorName, \
		NULL, \
		GUID_NULL, \
		g_pClassTable, \
		g_pCategoryTable); \
}

//==============================================================================
// MACRO:   OPCREG_CONFIG_FILE_SUFFIX
// PURPOSE: Declares the suffix used by COM server configuration files. 

#define OPCREG_CONFIG_FILE_SUFFIX _T(".config.xml")

//==============================================================================
// FUNCTION: OpcExtractSelfRegInfo
// PURPOSE:  Removes the self registration information from an XML document.

OPCUTILS_API HRESULT OpcExtractSelfRegInfo(IXMLDOMElement* ipRoot, IXMLDOMElement** ippInfo);

//==============================================================================
// FUNCTION: OpcInsertSelfRegInfo
// PURPOSE:  Inserts the self registration information into an XML document.

OPCUTILS_API HRESULT OpcInsertSelfRegInfo(IXMLDOMElement* ipRoot, IXMLDOMElement* ipInfo);

//==============================================================================
// FUNCTION: OpcGetModuleName
// PURPOSE:  Returns the name of the current executable.

OPCUTILS_API COpcString OpcGetModuleName();

//==============================================================================
// FUNCTION: OpcGetModulePath
// PURPOSE:  Returns the full file path of the current executable.

OPCUTILS_API COpcString OpcGetModulePath();

//==============================================================================
// STRUCTURE: OpcVersionInfo
// PURPOSE:   Stores information extracted from the version info resource.

// OpcVersionInfo
struct OPCUTILS_API OpcVersionInfo
{
	COpcString cFileDescription;
	WORD       wMajorVersion;
	WORD       wMinorVersion;
	WORD       wBuildNumber;
	WORD       wRevisionNumber;

	// Constructor
	OpcVersionInfo()
	{
		wMajorVersion = 0;
		wMinorVersion = 0;
		wBuildNumber = 0;
		wRevisionNumber = 0;
	}

	// Copy Constructor
	OpcVersionInfo(const OpcVersionInfo& cInfo)
	{
		cFileDescription = cInfo.cFileDescription;
		wMajorVersion    = cInfo.wMajorVersion;
		wMinorVersion    = cInfo.wMinorVersion;
		wBuildNumber     = cInfo.wBuildNumber;
		wRevisionNumber  = cInfo.wRevisionNumber;
	}
};

//==============================================================================
// FUNCTION: OpcGetModuleVersion
// PURPOSE:  Looks up the version resource block for the current executable.

OPCUTILS_API bool OpcGetModuleVersion(OpcVersionInfo& cInfo);

#endif // _COpcComModule_H_