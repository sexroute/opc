//============================================================================
// TITLE: COpcDaServer.cpp
//
// CONTENTS:
// 
// Implements an OPC Data Access server.
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
// 2002/11/16 RSA   Second release.
// 2003/03/09 RSA   Made autogenerated group names more user friendly.
// 2003/03/21 RSA   Fixed incorrect loop in LookupItemIDs().
// 2003/04/08 RSA   Added check to prevent item ids from being returned for basic properties.
// 2003/05/06 RSA   Fixed return code problem in Browse().
// 2003/05/13 RSA   Added support for 2.0 only servers.
// 2003/06/25 RSA   Fetch server information for the resource block now.
// 2003/07/30 TK    Corrected problem with group counter.

#include "StdAfx.h"
#include "COpcDaServer.h"
#include "COpcDaCache.h"

//============================================================================
// COpcDaServer

// Constructor
COpcDaServer::COpcDaServer()
{
}

// Destructor
COpcDaServer::~COpcDaServer()
{
	OPC_ASSERT(m_cGroups.GetCount() == 0);
}

// FinalConstruct
HRESULT COpcDaServer::FinalConstruct()
{
	COpcLock cLock(*this);

    // register callback interface.
    RegisterInterface(IID_IOPCShutdown);

	m_cBrowsePath.Empty();

    // initialize status.
    memset(&m_cStatus, 0, sizeof(m_cStatus));

    m_cStatus.ftStartTime      = OpcUtcNow();
    m_cStatus.ftCurrentTime    = OpcUtcNow();
    m_cStatus.ftLastUpdateTime = OpcMinDate();
    m_cStatus.dwServerState    = OPC_STATUS_RUNNING;
    m_cStatus.dwGroupCount     = 0;
    m_cStatus.dwBandWidth      = -1;

	OpcDaVersionInfo cVersionInfo;
	::GetCache().GetVersionInfo(cVersionInfo);

	m_cStatus.szVendorInfo  = OpcStrDup((LPCWSTR)cVersionInfo.cFileDescription);
	m_cStatus.wMajorVersion = cVersionInfo.wMajorVersion;
	m_cStatus.wMinorVersion = cVersionInfo.wMinorVersion;
	m_cStatus.wBuildNumber  = cVersionInfo.wBuildNumber;

	// add the revision number - if possible.
	if (cVersionInfo.wBuildNumber < 0x0100 && cVersionInfo.wRevisionNumber > 0 && cVersionInfo.wRevisionNumber < 100)
	{
		m_cStatus.wBuildNumber *= 100;
		m_cStatus.wBuildNumber += cVersionInfo.wRevisionNumber;
	}

	m_uCounter = 0;

    return S_OK;
}

// FinalRelease
bool COpcDaServer::FinalRelease()
{
	COpcLock cLock(*this);

	// delete groups.
    OPC_POS pos = m_cGroups.GetStartPosition();

    while (pos != NULL)
    {
        COpcString cName;
        COpcDaGroup* pGroup = NULL;
        m_cGroups.GetNextAssoc(pos, cName, pGroup);

        pGroup->Delete();
    }

    m_cGroups.RemoveAll();

    // unregister callback interface.
    UnregisterInterface(IID_IOPCShutdown);

	OpcFree(m_cStatus.szVendorInfo);

	// delete server.
	return true;
}

// SetLastUpdateTime
void COpcDaServer::SetLastUpdateTime()
{
	COpcLock cLock(*this);
	m_cStatus.ftLastUpdateTime = OpcUtcNow();
}

// SetGroupName
HRESULT COpcDaServer::SetGroupName(const COpcString& cOldName, const COpcString& cNewName)
{
	COpcLock cLock(*this);

	// lookup existing group.
	COpcDaGroup* pGroup = NULL;

	if (cNewName.IsEmpty() || !m_cGroups.Lookup(cOldName, pGroup))
	{
		return E_INVALIDARG;
	}

	// check that new name is unique among all groups.
	if (m_cGroups.Lookup(cNewName))
	{
		return OPC_E_DUPLICATENAME;
	}

	// update group table.
	m_cGroups.RemoveKey(cOldName);
	m_cGroups[cNewName] = pGroup;

	return S_OK;
}

// CreateGroup
HRESULT COpcDaServer::CreateGroup(const COpcString& cName, COpcDaGroup** ppGroup)
{
	COpcLock cLock(*this);

	// validate arguments.
	if (ppGroup == NULL)
	{
		return E_INVALIDARG;
	}

    // check that name is unique.
    if (!cName.IsEmpty())
    {        
	    if (m_cGroups.Lookup(cName))
	    {
		    return OPC_E_DUPLICATENAME;
	    }
    }

    // create unique name.
    COpcString cUniqueName = cName;

    if (cUniqueName.IsEmpty())
    {
		TCHAR tsName[MAX_PATH+1];

	    do
	    {
			_stprintf(tsName, _T("Group%03d"), ++m_uCounter);
	    }
		while (m_cGroups.Lookup(tsName));
        
		cUniqueName = tsName;
    }

	// create group.
	*ppGroup = CreateGroup(*this, cUniqueName);

	// update group table.
	m_cGroups[cUniqueName] = *ppGroup;
    m_cStatus.dwGroupCount++;

	((IOPCItemMgt*)(*ppGroup))->AddRef();

	return S_OK;
}

// CloneGroup
HRESULT COpcDaServer::CloneGroup(
	const COpcString& cName, 
	const COpcString& cCloneName, 
	COpcDaGroup**     ppClone)

{
	COpcLock cLock(*this);

	// validate arguments.
	COpcDaGroup* pGroup = NULL;

	if (ppClone == NULL || !m_cGroups.Lookup(cName, pGroup))
	{
		return E_INVALIDARG;
	}

	*ppClone = NULL;

	// create new group.
	COpcDaGroup* pClone = NULL;

	HRESULT hResult = CreateGroup(cCloneName, &pClone);

	if (FAILED(hResult))
	{
		return hResult;
	}

	TRY
	{
		hResult = pClone->Initialize(*pGroup);

		if (FAILED(hResult))
		{
			THROW();
		}

		*ppClone = pClone;
	}
	CATCH
	{
		if (pClone != NULL)
		{
			DeleteGroup(cCloneName);
			((IOPCItemMgt*)pClone)->Release();
		}
	}

    return hResult;
}

// DeleteGroup
HRESULT COpcDaServer::DeleteGroup(const COpcString& cName)
{
	COpcLock cLock(*this);

	// find group.
	COpcDaGroup* pGroup = NULL;

	if (!m_cGroups.Lookup(cName, pGroup))
	{
		return E_FAIL;
	}

	// update group table.
	m_cGroups.RemoveKey(cName);
    m_cStatus.dwGroupCount--;
    
	((IOPCItemMgt*)pGroup)->Release();

	return S_OK;
}

//============================================================================
// IOPCServer

// AddGroup
HRESULT COpcDaServer::AddGroup(
    LPCWSTR    szName,
    BOOL       bActive,
    DWORD      dwRequestedUpdateRate,
    OPCHANDLE  hClientGroup,
    LONG*      pTimeBias,
    FLOAT*     pPercentDeadband,
    DWORD      dwLCID,
    OPCHANDLE* phServerGroup,
    DWORD*     pRevisedUpdateRate,
    REFIID     riid,
    LPUNKNOWN* ppUnk
)
{
    COpcLock cLock(*this);

    COpcDaGroup* pGroup = NULL;

	// create instance of group object.
	HRESULT hResult = CreateGroup(szName, &pGroup);

	if (FAILED(hResult))
	{
		return hResult;
	}

    TRY
    {
        // check arguments.
        if (phServerGroup == NULL || pRevisedUpdateRate == NULL || ppUnk == NULL)
        {
            THROW_(hResult, E_INVALIDARG);
        }

		*phServerGroup      = NULL;
		*pRevisedUpdateRate = 0;
		*ppUnk              = NULL;

        // look up local timezone if timezone not specified.
        LONG lTimeBias = 0;

        if (pTimeBias == NULL)
        {
            TIME_ZONE_INFORMATION cZoneInfo;
            GetTimeZoneInformation(&cZoneInfo);    
            lTimeBias = cZoneInfo.Bias;
        }
        else
        {
            lTimeBias = *pTimeBias;
        } 

        // set group initial state.
        hResult = pGroup->SetState(
            &dwRequestedUpdateRate,
            pRevisedUpdateRate,
            &bActive,
            &lTimeBias,
            pPercentDeadband,
            &dwLCID,
            &hClientGroup);

        if (FAILED(hResult))
        {
            THROW();         
        }

        // check for revised rate.
        bool bRevised = (hResult == OPC_S_UNSUPPORTEDRATE);

        // query for requested interface.
        hResult = ((IOPCItemMgt*)pGroup)->QueryInterface(riid, (void**)ppUnk);

        if (FAILED(hResult))
        {
            THROW();         
        }

        *phServerGroup = (OPCHANDLE)pGroup;

		((IOPCItemMgt*)pGroup)->Release();

        // set the result code to indicate the rate was revised.
        if (bRevised) hResult = OPC_S_UNSUPPORTEDRATE;
    }
    CATCH
    {
        if (pGroup != NULL)
		{
			DeleteGroup(szName);
			((IOPCItemMgt*)pGroup)->Release();
		}
    }

    return hResult;
}

// GetErrorString
HRESULT COpcDaServer::GetErrorString( 
    HRESULT dwError,
    LCID    dwLocale,
    LPWSTR* ppString
)
{  
    return COpcCommon::GetErrorString(OPC_MESSAGE_MODULE_NAME_DA, dwError, dwLocale, ppString);
}

// GetGroupByName
HRESULT COpcDaServer::GetGroupByName(
    LPCWSTR    szName,
    REFIID     riid,
    LPUNKNOWN* ppUnk
)
{
    COpcLock cLock(*this);

    COpcDaGroup* pGroup = NULL;

    if (!m_cGroups.Lookup(szName, pGroup))
    {
        return E_INVALIDARG;
    }

    return ((IOPCItemMgt*)pGroup)->QueryInterface(riid, (void**)ppUnk);
}

// GetStatus
HRESULT COpcDaServer::GetStatus( 
    OPCSERVERSTATUS** ppServerStatus
)
{
    COpcLock cLock(*this);

    *ppServerStatus  = (OPCSERVERSTATUS*)OpcAlloc(sizeof(OPCSERVERSTATUS));

	(*ppServerStatus)->ftStartTime      = m_cStatus.ftStartTime;
    (*ppServerStatus)->ftCurrentTime    = OpcUtcNow();
	(*ppServerStatus)->ftLastUpdateTime = m_cStatus.ftLastUpdateTime;
	(*ppServerStatus)->dwServerState    = ::GetCache().GetState();
	(*ppServerStatus)->dwGroupCount     = m_cStatus.dwGroupCount;
	(*ppServerStatus)->dwBandWidth      = m_cStatus.dwBandWidth;
    (*ppServerStatus)->szVendorInfo     = OpcStrDup(m_cStatus.szVendorInfo);
	(*ppServerStatus)->wMajorVersion    = m_cStatus.wMajorVersion;
	(*ppServerStatus)->wMinorVersion    = m_cStatus.wMinorVersion;
	(*ppServerStatus)->wBuildNumber     = m_cStatus.wBuildNumber;

    return S_OK;
}

// RemoveGroup
HRESULT COpcDaServer::RemoveGroup(
    OPCHANDLE hServerGroup,
    BOOL      bForce
)
{
    COpcLock cLock(*this);

    // lookup group by server handle.
    OPC_POS pos = m_cGroups.GetStartPosition();

    while (pos != NULL)
    {
        COpcString cName;
        COpcDaGroup* pGroup = NULL;
        m_cGroups.GetNextAssoc(pos, cName, pGroup);

        if (pGroup->GetHandle() == hServerGroup)
        {
            m_cGroups.RemoveKey(cName);
                        
            // releases the server's reference to the group.
            if (!pGroup->Delete() && !bForce)
            {
                return OPC_S_INUSE;
            }

			m_cStatus.dwGroupCount--;

            return S_OK;
        }
    }

    return E_FAIL;
}

// CreateGroupEnumerator
HRESULT COpcDaServer::CreateGroupEnumerator(
    OPCENUMSCOPE dwScope, 
    REFIID       riid, 
    LPUNKNOWN*   ppUnk
)
{
    COpcLock cLock(*this);

    // check the group scope.
    switch (dwScope)
    {
        case OPC_ENUM_PUBLIC_CONNECTIONS:
        case OPC_ENUM_PUBLIC:
        {
            IUnknown* ipEnum = NULL;

            if (riid == IID_IEnumString)
            {
                ipEnum = new COpcEnumString();
            }
            else
            {
                ipEnum = new COpcEnumUnknown();
            }

            // return requested interface.
            HRESULT hResult = ipEnum->QueryInterface(riid, (void**)ppUnk);

            ipEnum->Release();

            if (FAILED(hResult))
            {
                return hResult;
            }

            return S_FALSE;
        }
    }

    // get total number of groups.
    UINT uCount = m_cGroups.GetCount();

    // create group name enumerator.
    if (riid == IID_IEnumString)
    {
        COpcEnumString* ipEnum = NULL;

        // populate string enumerator.
        if (uCount > 0)
        {
            LPWSTR* wszNames = OpcArrayAlloc(LPWSTR, uCount);

            UINT ii = 0;
            OPC_POS pos = m_cGroups.GetStartPosition();

            while (pos != NULL)
            {
                COpcString cName;
                m_cGroups.GetNextAssoc(pos, cName);

                wszNames[ii++] = OpcStrDup((LPCWSTR)cName);
            }

            ipEnum = new COpcEnumString(uCount, wszNames);
        }

        // create empty enumerator.
        if (ipEnum == NULL)
        {
            ipEnum = new COpcEnumString();
        }

        // return requested interface.
        HRESULT hResult = ipEnum->QueryInterface(riid, (void**)ppUnk);

        ipEnum->Release();

        if (FAILED(hResult))
        {
            return hResult;
        }

        return (uCount > 0)?S_OK:S_FALSE;
    }

    // create group interface enumerator.
    if (riid == IID_IEnumUnknown)
    {
        COpcEnumUnknown* ipEnum = NULL;

        // populate string enumerator.
        if (uCount > 0)
        {
            IUnknown** ppGroups = OpcArrayAlloc(IUnknown*, uCount);

            UINT ii = 0;
            OPC_POS pos = m_cGroups.GetStartPosition();

            while (pos != NULL)
            {
                COpcString cName;
                COpcDaGroup* pGroup = NULL;
                m_cGroups.GetNextAssoc(pos, cName, pGroup);

                ((IOPCItemMgt*)pGroup)->QueryInterface(IID_IUnknown, (void**)&(ppGroups[ii++]));
            }

            ipEnum = new COpcEnumUnknown(uCount, ppGroups);
        }

        // create empty enumerator.
        if (ipEnum == NULL)
        {
            ipEnum = new COpcEnumUnknown();
        }

        // return requested interface.
        HRESULT hResult = ipEnum->QueryInterface(riid, (void**)ppUnk);

        ipEnum->Release();

        if (FAILED(hResult))
        {
            return hResult;
        }

        return (uCount > 0)?S_OK:S_FALSE;
    }

    // requested interface not supported.
    return E_NOINTERFACE;
}

//============================================================================
// IOPCItemIO

// Read
HRESULT COpcDaServer::Read(
    DWORD       dwCount, 
    LPCWSTR   * pszItemIDs,
    DWORD     * pdwMaxAge,
    VARIANT  ** ppvValues,
    WORD     ** ppwQualities,
    FILETIME ** ppftTimeStamps,
    HRESULT  ** ppErrors
)
{
    COpcLock cLock(*this);

    // check arguments.
    if (
          pszItemIDs     == NULL || 
          pdwMaxAge      == NULL ||
          ppvValues      == NULL || 
          ppwQualities   == NULL ||
          ppftTimeStamps == NULL || 
          ppErrors       == NULL
       )
    {
        return E_INVALIDARG;
    }

    // initialize return values.
    *ppvValues      = NULL;
    *ppwQualities   = NULL;
    *ppftTimeStamps = NULL;
    *ppErrors       = NULL;

    // check for trival case.
    if (dwCount == 0)
    {
        return E_INVALIDARG;
    }

    // allocate and initialize returned arrays.
    *ppvValues      = OpcArrayAlloc(VARIANT, dwCount);
    *ppwQualities   = OpcArrayAlloc(WORD, dwCount);
    *ppftTimeStamps = OpcArrayAlloc(FILETIME, dwCount);
    *ppErrors       = OpcArrayAlloc(HRESULT, dwCount);

    memset(*ppvValues, 0, dwCount*sizeof(VARIANT));
    memset(*ppwQualities, 0, dwCount*sizeof(WORD));
    memset(*ppftTimeStamps, 0, dwCount*sizeof(FILETIME));
    memset(*ppErrors, 0, dwCount*sizeof(HRESULT));

    // read items from cache.
    bool bError = false;

    for (DWORD ii = 0; ii < dwCount; ii++)
    {
        (*ppErrors)[ii] = ::GetCache().Read(
            pszItemIDs[ii],
            GetLocaleID(),
            VT_EMPTY,
            pdwMaxAge[ii],
            (*ppvValues)[ii],
            (*ppftTimeStamps)[ii],
            (*ppwQualities)[ii]
        );

        if (FAILED((*ppErrors)[ii]))
        {
            bError = true;
        }
    }

    return (bError)?S_FALSE:S_OK;  
}

// WriteVQT
HRESULT COpcDaServer::WriteVQT (
    DWORD         dwCount, 
    LPCWSTR    *  pszItemIDs,
    OPCITEMVQT *  pItemVQT,
    HRESULT    ** ppErrors
)
{
    COpcLock cLock(*this);

    // check arguments.
    if (
          pszItemIDs == NULL || 
          pItemVQT   == NULL || 
          ppErrors   == NULL
       )
    {
        return E_INVALIDARG;
    }

    // initialize return values.
    *ppErrors = NULL;

    // check for trival case.
    if (dwCount == NULL)
    {
        return E_INVALIDARG;
    }

    // allocate and initialize returned arrays.
    *ppErrors = OpcArrayAlloc(HRESULT, dwCount);

    memset(*ppErrors, 0, dwCount*sizeof(HRESULT));

    // write items in cache.
    bool bError = false;

    for (DWORD ii = 0; ii < dwCount; ii++)
    {
        (*ppErrors)[ii] = ::GetCache().Write(
            pszItemIDs[ii],
            GetLocaleID(),
            pItemVQT[ii].vDataValue,
            (pItemVQT[ii].bTimeStampSpecified)?&(pItemVQT[ii].ftTimeStamp):NULL,
            (pItemVQT[ii].bQualitySpecified)?&(pItemVQT[ii].wQuality):NULL
        );

        if (FAILED((*ppErrors)[ii]))
        {
            bError = true;
        }
    }

    return (bError)?S_FALSE:S_OK;  
}


//=============================================================================
// IOPCBrowseServerAddressSpace

// QueryOrganization
HRESULT COpcDaServer::QueryOrganization(OPCNAMESPACETYPE* pNameSpaceType)
{
    // invalid arguments.
    if (pNameSpaceType == NULL)
    {
        return E_INVALIDARG;
    }

    *pNameSpaceType = OPC_NS_HIERARCHIAL;
    return S_OK;
}

// ChangeBrowsePosition
HRESULT COpcDaServer::ChangeBrowsePosition(
    OPCBROWSEDIRECTION dwBrowseDirection,  
    LPCWSTR            szString
)
{
    COpcLock cLock(*this);

    switch (dwBrowseDirection)
    {
        case OPC_BROWSE_UP:
        {
            // not allowed to browse up from root.
            if (m_cBrowsePath.IsEmpty())
            {
                return E_FAIL;
            }

            // get new browse position.
            COpcString cBrowsePath;

            if (!::GetCache().BrowseUp(m_cBrowsePath, cBrowsePath))
            {
				// reset position to root on error (i.e. bad browse position).
				m_cBrowsePath.Empty();
                return E_FAIL;
            }
           
            m_cBrowsePath = cBrowsePath;
            return S_OK;
        }

        case OPC_BROWSE_DOWN:
        {
            // nothing to do - ignore.
            if (szString == NULL || wcslen(szString) == 0)
            {
                return E_INVALIDARG;
            }

            // get new browse position.
            COpcString cBrowsePath;

            if (!::GetCache().BrowseDown(m_cBrowsePath, szString, cBrowsePath))
            {
                return E_INVALIDARG;
            }

            m_cBrowsePath = cBrowsePath;
            return S_OK;
        }

        case OPC_BROWSE_TO:
        {
            // check for browse to root.
            if (szString == NULL || wcslen(szString) == 0)
            {
                m_cBrowsePath = OPC_EMPTY_STRING;
                return S_OK;
            }

            // get new browse position.
            COpcString cBrowsePath;

            if (!::GetCache().BrowseTo(szString, cBrowsePath))
            {
                return E_INVALIDARG;
            }

            m_cBrowsePath = cBrowsePath;
            return S_OK;
        }
    }

    return E_INVALIDARG;
}

// BrowseOPCItemIDs
HRESULT COpcDaServer::BrowseOPCItemIDs(
    OPCBROWSETYPE   dwBrowseFilterType,
    LPCWSTR         szFilterCriteria,  
    VARTYPE         vtDataTypeFilter,     
    DWORD           dwAccessRightsFilter,
    LPENUMSTRING*   ppIEnumString
)
{
    HRESULT hResult = S_OK;
	
	// validate browse filters.
	if (dwBrowseFilterType < OPC_BRANCH || dwBrowseFilterType > OPC_FLAT)
	{
		return E_INVALIDARG;
	}

	// validate access rights.
	if ((dwAccessRightsFilter & 0xFFFFFFFC) != 0)
	{
		return E_INVALIDARG;
	}

    // query for the complete set of possible elements.
    COpcStringList cNodes;
    
    bool bResult = ::GetCache().Browse(
        m_cBrowsePath, 
        dwBrowseFilterType, 
        szFilterCriteria,
        vtDataTypeFilter,
        dwAccessRightsFilter,
        cNodes);
    
    if (!bResult)
    {
        return E_FAIL;
    }

    // allocate enumerator.
    COpcEnumString* pEnum = NULL;

    UINT uCount = cNodes.GetCount();
    
    if (uCount == 0)
    {
        pEnum = new COpcEnumString();
    }
    else
    {
        LPWSTR* pNodes = OpcArrayAlloc(LPWSTR, uCount);
        memset(pNodes, 0, uCount*sizeof(LPWSTR));

        OPC_POS pos = cNodes.GetHeadPosition();

        for (UINT ii = 0; pos != NULL; ii++)
        {
            COpcString cElement = cNodes.GetNext(pos);
            pNodes[ii] = OpcStrDup((LPCWSTR)cElement);
        }

        pEnum = new COpcEnumString(uCount, pNodes);
    }

    // query for the desired interface.
    hResult = pEnum->QueryInterface(IID_IEnumString, (void**)ppIEnumString);
    
    pEnum->Release();

    if (FAILED(hResult))
    {
        return hResult;
    }

    return (uCount > 0)?S_OK:S_FALSE;
}

// GetItemID
HRESULT COpcDaServer::GetItemID(
    LPWSTR  wszItemName,
    LPWSTR* pszItemID
)
{
    // check for invalid arguments
    if (pszItemID == NULL)
    {
        return E_INVALIDARG;
    }
        
    *pszItemID = NULL;

    // handle request for root item id.
    if (m_cBrowsePath.IsEmpty())
    {
        if (wszItemName == NULL || wcslen(wszItemName) == 0)
        {
            *pszItemID = OpcStrDup(L"");
            return S_OK;
        }
    }

    // lookup item id.
    COpcString cItemID;

    if (!::GetCache().GetItemID(m_cBrowsePath, wszItemName, cItemID))
    {
        return E_INVALIDARG;
    }

    // copy item id.
    *pszItemID = OpcStrDup((LPCWSTR)cItemID);
    return S_OK;
}

// BrowseAccessPaths
HRESULT COpcDaServer::BrowseAccessPaths(
    LPCWSTR       szItemID,  
    LPENUMSTRING* ppIEnumString
)
{
    if (ppIEnumString == NULL)
    {
        return E_INVALIDARG;
    }

    // access paths not implemented.
    *ppIEnumString = NULL;
    return E_NOTIMPL;
}

//============================================================================
// IOPCItemProperties

// QueryAvailableProperties
HRESULT COpcDaServer::QueryAvailableProperties( 
    LPWSTR     szItemID,
    DWORD    * pdwCount,
    DWORD   ** ppPropertyIDs,
    LPWSTR  ** ppDescriptions,
    VARTYPE ** ppvtDataTypes
)
{
    COpcLock cLock(*this);

    // check arguements.
    if (
          szItemID       == NULL || 
          pdwCount       == NULL || 
          ppPropertyIDs  == NULL || 
          ppDescriptions == NULL || 
          ppvtDataTypes  == NULL
       )
    {
        return E_INVALIDARG;
    }

    *pdwCount       = 0;
    *ppPropertyIDs  = NULL;
    *ppDescriptions = NULL;
    *ppvtDataTypes  = NULL;

    // check if item exists,
    if (!::GetCache().ItemExists(szItemID))
    {
        return OPC_E_INVALIDITEMID;
    }
    
    // get the property list for the item.
	COpcDaPropertyList cProperties;

	HRESULT hResult = ::GetCache().GetItemProperties(szItemID, false, cProperties);

    if (FAILED(hResult))
    {
        return hResult;
    }

	// allocate arrays returned to caller.
	COpcDaProperty::Copy(cProperties, *pdwCount, *ppPropertyIDs, *ppDescriptions, *ppvtDataTypes);

	// free the memory allocated for the item properties.
	COpcDaProperty::Free(cProperties);

    // request complete.
    return S_OK;
}

// GetItemProperties
HRESULT COpcDaServer::GetItemProperties( 
    LPWSTR     szItemID,
    DWORD      dwCount,
    DWORD    * pdwPropertyIDs,
    VARIANT ** ppvData,
    HRESULT ** ppErrors
)
{
    COpcLock cLock(*this);

    // check arguements.
    if (
          szItemID       == NULL || 
          ppvData        == NULL || 
          ppErrors       == NULL
       )
    {
        return E_INVALIDARG;
    }

    *ppvData  = NULL;
    *ppErrors = NULL;

    // nothing to do.
    if (dwCount == 0)
    {
        return E_INVALIDARG;
    }

    // check if item exists,
    if (!::GetCache().ItemExists(szItemID))
    {
        return OPC_E_INVALIDITEMID;
    }
    
    // get the property list for the item.
	COpcList<DWORD> cIDs;
	
	for (DWORD ii = 0; ii < dwCount; ii++) 
	{ 
		cIDs.AddTail(pdwPropertyIDs[ii]); 
	}

	COpcDaPropertyList cProperties;

	HRESULT hResult = ::GetCache().GetItemProperties(szItemID, cIDs, true, cProperties);

    if (FAILED(hResult))
    {
        return hResult;
    }

	// allocate arrays returned to caller.
	COpcDaProperty::Copy(cProperties, dwCount, *ppvData, *ppErrors);

	// free the memory allocated for the item properties.
	COpcDaProperty::Free(cProperties);

    // check for error status.
    bool bError = false;

    for (DWORD ii = 0; ii < dwCount; ii++)
    {
        if (FAILED((*ppErrors)[ii]))
        {
            bError = true;
			break;
        }
    }
	
    // request complete.
    return (bError)?S_FALSE:S_OK;
}

// LookupItemIDs
HRESULT COpcDaServer::LookupItemIDs( 
    LPWSTR     szItemID,
    DWORD      dwCount,
    DWORD    * pdwPropertyIDs,
    LPWSTR  ** ppszNewItemIDs,
    HRESULT ** ppErrors
)
{
    COpcLock cLock(*this);

    // check arguements.
    if (
          szItemID       == NULL || 
          ppszNewItemIDs == NULL || 
          ppErrors       == NULL
       )
    {
        return E_INVALIDARG;
    }

    *ppszNewItemIDs = NULL;
    *ppErrors       = NULL;

    // nothing to do.
    if (dwCount == 0)
    {
        return E_INVALIDARG;
    }   
    
    // check if item exists,
    if (!::GetCache().ItemExists(szItemID))
    {
        return OPC_E_INVALIDITEMID;
    }
    
	// get the property list for the item.
	COpcList<DWORD> cIDs;
	
	for (DWORD ii = 0; ii < dwCount; ii++) 
	{ 
		cIDs.AddTail(pdwPropertyIDs[ii]); 
	}

	COpcDaPropertyList cProperties;

	HRESULT hResult = ::GetCache().GetItemProperties(szItemID, cIDs, false, cProperties);

    if (FAILED(hResult))
    {
        return hResult;
    }

	// allocate arrays returned to caller.
	COpcDaProperty::Copy(cProperties, dwCount, *ppszNewItemIDs, *ppErrors);

	// free the memory allocated for the item properties.
	COpcDaProperty::Free(cProperties);

    // check for error status (may need to substitute error codes to pass the CTT).
    bool bError = false;

    for (DWORD ii = 0; ii < dwCount; ii++)
    {
		if (pdwPropertyIDs[ii] <= OPC_PROPERTY_EU_INFO)
		{
			// basic properties must never has an associated item id.
			OPC_ASSERT((*ppszNewItemIDs)[ii] == NULL);

			// this DA 2 function requires an error code in this case.
			(*ppErrors)[ii] = OPC_E_INVALID_PID;
		}

        if (FAILED((*ppErrors)[ii]))
        {
            bError = true;
        }
    }

    // request complete.
    return (bError)?S_FALSE:S_OK;
}

//=============================================================================
// IOPCBrowse

// GetProperties
HRESULT COpcDaServer::GetProperties( 
    DWORD		        dwItemCount,
    LPWSTR*             pszItemIDs,
    BOOL		        bReturnPropertyValues,
    DWORD		        dwPropertyCount,
    DWORD*              pdwPropertyIDs,
    OPCITEMPROPERTIES** ppItemProperties 
)
{
    COpcLock cLock(*this);

    // check arguments.
    if (
          pszItemIDs       == NULL || 
          ppItemProperties == NULL
       )
    {
        return E_INVALIDARG;
    }

    // initialize return values.
    *ppItemProperties = NULL;

    // check for trival case.
    if (dwItemCount == NULL)
    {
        return E_INVALIDARG;
    }

	// initialize list of requeted properties.
	COpcList<DWORD> cIDs;
	
	for (DWORD ii = 0; ii < dwPropertyCount; ii++) 
	{ 
		cIDs.AddTail(pdwPropertyIDs[ii]); 
	}

    // allocate and initialize returned arrays.
    *ppItemProperties = OpcArrayAlloc(OPCITEMPROPERTIES, dwItemCount);
    memset(*ppItemProperties , 0, dwItemCount*sizeof(OPCITEMPROPERTIES));

    // create property lists.
    bool bError = false;
	HRESULT hResult = S_OK;

    for (DWORD ii = 0; ii < dwItemCount; ii++)
    {
		// fetch available properties for the item.
		COpcDaPropertyList cProperties;

		if (dwPropertyCount == 0)
		{	
			hResult = ::GetCache().GetItemProperties(
				pszItemIDs[ii], 
				(bReturnPropertyValues)?true:false, 
				cProperties);
		}
		else
		{
			hResult = ::GetCache().GetItemProperties(
				pszItemIDs[ii], 
				cIDs, 
				(bReturnPropertyValues)?true:false, 
				cProperties);
		}

		// check for item level error.
		if (FAILED(hResult))
		{
			(*ppItemProperties)[ii].hrErrorID = hResult;

			hResult = S_OK;
			bError  = true;
			continue;
		}
        
		// initalize property structure.
		(*ppItemProperties)[ii].hrErrorID       = S_OK;
		(*ppItemProperties)[ii].dwNumProperties = 0;
		(*ppItemProperties)[ii].pItemProperties = NULL;

		// copy result into returned structure.
		COpcDaProperty::Copy(
			cProperties, 
			(bReturnPropertyValues)?true:false, 
			(*ppItemProperties)[ii].dwNumProperties,
			(*ppItemProperties)[ii].pItemProperties
		);

		// set item level error if property level error exists.		
		OPCITEMPROPERTY* pProperties = (*ppItemProperties)[ii].pItemProperties;

		for (DWORD jj = 0; jj < cProperties.GetSize(); jj++)
		{
			if (FAILED(pProperties[jj].hrErrorID))
			{
				(*ppItemProperties)[ii].hrErrorID = S_FALSE;
				bError = true;
				break;
			}
		}

		// free the memory allocated for the item properties.
		COpcDaProperty::Free(cProperties);
    }

    return (bError)?S_FALSE:S_OK;
}

// Browse
HRESULT COpcDaServer::Browse(
	LPWSTR	           szItemName,
	LPWSTR*	           pszContinuationPoint,
	DWORD              dwMaxElementsReturned,
	OPCBROWSEFILTER    dwFilter,
	LPWSTR             szElementNameFilter,
	LPWSTR             szVendorFilter,
	BOOL               bReturnAllProperties,
	BOOL               bReturnPropertyValues,
	DWORD              dwPropertyCount,
	DWORD*             pdwPropertyIDs,
	BOOL*              pbMoreElements,
	DWORD*	           pdwCount,
	OPCBROWSEELEMENT** ppBrowseElements
)
{
    COpcLock cLock(*this);

    // check arguments.
    if (
          pbMoreElements   == NULL || 
          pdwCount         == NULL ||
          ppBrowseElements == NULL
       )
    {
        return E_INVALIDARG;
    }

	// validate browse filters.
	if (dwFilter < OPC_BROWSE_FILTER_ALL || dwFilter > OPC_BROWSE_FILTER_ITEMS)
	{
		return E_INVALIDARG;
	}

    // initialize return values.
    *pbMoreElements   = FALSE;
    *pdwCount         = 0;
    *ppBrowseElements = NULL;

    // parse continuation point.
    DWORD dwStartIndex = 0;

    if (pszContinuationPoint != NULL)
    {
        COpcString cContinuationPoint = *pszContinuationPoint;

        if (!cContinuationPoint.IsEmpty())
        {
            if (!OpcXml::Read(*pszContinuationPoint, dwStartIndex))
            {
                return OPC_E_INVALIDCONTINUATIONPOINT;
            }
        }

        *pszContinuationPoint = OpcStrDup(L"");
    }

    // browse address space.
    HRESULT hResult = ::GetCache().Browse(
        szItemName,
        dwMaxElementsReturned,
        dwFilter,
        szElementNameFilter,
        szVendorFilter,
        &dwStartIndex,
        pdwCount,
        ppBrowseElements
    );

    if (FAILED(hResult))
    {
        return hResult;
    }

    // set continuation point.
    if (pszContinuationPoint != NULL && dwStartIndex != 0)
    {
        COpcString cContinuationPoint;

        if (!OpcXml::Write(dwStartIndex, cContinuationPoint))
        {
            return OPC_E_INVALIDCONTINUATIONPOINT;
        }

        *pszContinuationPoint = OpcStrDup((LPCWSTR)cContinuationPoint);
    }

    // get properties.
    bool bError = false;

    if (bReturnAllProperties || dwPropertyCount > 0)
    {
        // create item id array.
        LPWSTR* szItemIDs = OpcArrayAlloc(LPWSTR, *pdwCount);

        for (DWORD ii = 0; ii < *pdwCount; ii++)
        {
            szItemIDs[ii] = (*ppBrowseElements)[ii].szItemID;
        }

        // read properties.
        OPCITEMPROPERTIES* pProperties = NULL;

        hResult = GetProperties(
            *pdwCount,
            szItemIDs,
            bReturnPropertyValues,
            dwPropertyCount,
            pdwPropertyIDs,
            &pProperties
        );

        OpcFree(szItemIDs);

        // copy results into browse element structures.
        for (ii = 0; ii < *pdwCount; ii++)
        {
			// check for branches with no properties.
			if (((*ppBrowseElements)[ii].dwFlagValue & OPC_BROWSE_ISITEM) == 0)
			{
				continue;
			}

			// check for general failure.
            if (FAILED(hResult))
            {
				(*ppBrowseElements)[ii].ItemProperties.hrErrorID = hResult;
                bError = true;
                continue;
            }

			// tranfer memory to returned structure.
            (*ppBrowseElements)[ii].ItemProperties = pProperties[ii];
			
			// check for item level error.
			if (pProperties[ii].hrErrorID == S_FALSE || FAILED(pProperties[ii].hrErrorID))
			{
				bError = true;
			}
        }

		// free array - contained memory has been stored in the browze elements.
        OpcFree(pProperties);
    }

    return (bError)?S_FALSE:S_OK;
}
