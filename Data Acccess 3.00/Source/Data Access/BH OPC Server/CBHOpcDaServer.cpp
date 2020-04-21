//==============================================================================
// TITLE: CXxxDaServer.cpp
//
// CONTENTS:
// 
// The implements the OPC remote server activator.
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
#include "CBHOpcDaCache.h"
#include "CBHOpcDaServer.h"

//==============================================================================
// Static Data

static COpcCriticalSection g_cLock;
static UINT                g_uRefs   = 0;
static CBHOpcDaCache*        g_pCache  = NULL;
static CBHOpcDaDevice*       g_pDevice = NULL;

//==============================================================================
// Static Functions

// GetCache
COpcDaCache& GetCache()
{
    return *g_pCache;
}

// GetDevice
IOpcDaDevice* GetDevice(const COpcString& cItemID)
{
    return (IOpcDaDevice*)g_pDevice;
}

bool IsValidateUser()
{
	return true;
}

//初始化设备信息，测点列表
bool InternalInitialize()
{
	bool lbRet = true;
	TRY
	{        
		g_pDevice = new CBHOpcDaDevice();

		g_pCache = new CBHOpcDaCache(*g_pDevice);

		if (IsValidateUser())
		{
			if (!g_pCache->Start())
			{
				THROW_(lbRet, false);
			}

		}else
		{
			if (!g_pCache->StartSample())
			{
				THROW_(lbRet, false);
			}
		}
	}
	CATCH
	{
		if (g_pCache != NULL)
		{
			g_pCache->Stop();
			delete g_pCache;
			g_pCache = NULL;
		}

		if (g_pDevice != NULL)
		{
			delete g_pDevice;
			g_pDevice = NULL;
		}
	}

	return lbRet;
}
// Initialize
static bool Initialize()
{
    COpcLock cLock(g_cLock);
    
    g_uRefs++;
    
	if (g_uRefs > 1)
    {
        return true;
    }

    bool bResult = true;

	if (!g_pDevice)
	{
		bResult = InternalInitialize();
	}

    return bResult;
}

// Uninitialize
static void Uninitialize()
{
    COpcLock cLock(g_cLock);

    g_uRefs--;
    
    if (g_uRefs == 0)
    {
		if (g_pCache != NULL)
		{
			g_pCache->Stop();
			delete g_pCache;
			g_pCache = NULL;
		}
	
		if (g_pDevice != NULL)
		{
			delete g_pDevice;
			g_pDevice = NULL;
		}

        cLock.Unlock();
        COpcComModule::ExitProcess(S_OK);
    }
}

//==============================================================================
// CXxxDaServer

// FinalConstruct
HRESULT CBHOpcDaServer::FinalConstruct()
{
    if (!Initialize())
    {
        return E_FAIL;
    }

    return COpcDaServer::FinalConstruct();
}

// FinalRelease
bool CBHOpcDaServer::FinalRelease()
{
    COpcDaServer::FinalRelease();
    Uninitialize();
	return true;
}
