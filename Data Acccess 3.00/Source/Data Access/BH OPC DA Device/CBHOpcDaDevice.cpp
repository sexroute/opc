//============================================================================
// TITLE: CBHOpcDaDevice.cpp
//
// CONTENTS:
// 
// Simulates a simple I/O device.
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
//

#include "StdAfx.h"
#include "CBHOpcDaDevice.h"
#include "COpcDaCache.h"


//============================================================================
// Local Declarations



// UpdateThreadCtrl
static void WINAPI UpdateThreadCtrl(void* pDevice, bool bStopThread)
{
	if (!bStopThread)
	{
		((CBHOpcDaDevice*)pDevice)->Update();
	}
}

//============================================================================
// CBHOpcDaDevice

// Start
bool CBHOpcDaDevice::Start()
{
	// construct configuration file name.
	COpcString cFileName;
	MessageBox(NULL,_T("test"),NULL,MB_OK);

	cFileName += OpcDaGetModulePath();
	cFileName += _T("\\");
	cFileName += OpcDaGetModuleName();
	cFileName += _T(".device.xml");

	// load the xml file.
	COpcXmlDocument cConfigFile;

	if (!cConfigFile.Load(cFileName))
	{
		return false;
	}

	if (!Start(cConfigFile.GetRoot()))
	{
		return false;
	}

	return true;
}

// Start
bool CBHOpcDaDevice::Start(COpcXmlElement& cElement)
{
	// parse the xml document.
	if (!Read(cElement))
	{
		return false;
	}

	// add items to cache.
	if (!BuildAddressSpace())
	{
		return false;
	}
	
	// add items to BH cache
	if (this->IsRealSample() && !this->BuildBHItemAddress())
	{
		return false;
	}


	// start the simulation thread.
	if (!m_cThread.Start(UpdateThreadCtrl, this, INFINITE, THREAD_PRIORITY_TIME_CRITICAL))
	{
		return false;
	}    

	return true;
}

// Stop
void CBHOpcDaDevice::Stop()
{
	// stop simulation thread.
	m_cThread.Stop();

	// clear items from cache.
	ClearAddressSpace();
}

// Update
void CBHOpcDaDevice::Update()
{
	LONGLONG llEnd   = 0;
	LONGLONG llStart = 0;
	LONGLONG llFreq  = 0;

	QueryPerformanceFrequency((LARGE_INTEGER*)&llFreq);

	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	/*CoInitializeEx(NULL, COINIT_MULTITHREADED);*/

	LONGLONG uTicks = 0;

	while (!m_cThread.WaitingForStop())
	{
		if (this->IsRealSample())
		{
			COpcLock loPlantInfoLock(this->m_oPlantInfoLock);
			loPlantInfoLock.Lock();
			try
			{
				this->UpdateFromBHDevice();

			}catch(...)
			{
				ASSERT(FALSE);
			}			
			loPlantInfoLock.Unlock();
		}

		COpcLock cLock(*this);

		// update each group.
		OPC_POS pos = m_cItems.GetStartPosition();
		OpcXml::AnyType aoValue ;

		while (pos != NULL)
		{
			COpcString cItemID;
			CBHOpcDaDeviceItem* pItem = NULL;

			m_cItems.GetNextAssoc(pos, cItemID, pItem);

			if (this->IsRealSample())
			{
				if (cItemID.GetBuffer()!=NULL)
				{					
					CString lstrUniqueKey = cItemID.GetBuffer();
					COpcLock loPlantInfoLock(this->m_oPlantInfoLock);		

					BOOL lbFound = FALSE;

					loPlantInfoLock.Lock();
					try
					{
						G_CHANNEL_POOL::iterator lpItem = this->m_oTotalChannelInfoPool.find(lstrUniqueKey);

						if (   lpItem!= this->m_oTotalChannelInfoPool.end() 
							&& lpItem->second!=NULL)
						{
							CHANNEL_INFO & lRefChannInfo = *lpItem->second;
							aoValue = lRefChannInfo.m_cValue;

							lbFound = TRUE;
						}

					}catch(...)
					{
						ASSERT(FALSE);
					}

					loPlantInfoLock.Unlock();
					
					if (lbFound)
					{
						pItem->RealSample(this->IsRealSample());
						pItem->UpdateBHDevice(uTicks, MAX_SAMPLING_RATE,aoValue);

					}else
					{
						ASSERT(FALSE);
					}

				}

			}else
			{
				pItem->Update(uTicks, MAX_SAMPLING_RATE);
			}
			
		}

		cLock.Unlock();

		QueryPerformanceCounter((LARGE_INTEGER*)&llEnd);

		UINT uWaitTime = MAX_SAMPLING_RATE;

		if (llStart != 0)
		{
			double delay = (((double)(llEnd - llStart))/((double)llFreq))*1000 - MAX_SAMPLING_RATE;

			if (delay > 0)
			{
				uWaitTime = (delay < uWaitTime)?(uWaitTime - (UINT)delay):0;
			}
		}

		QueryPerformanceCounter((LARGE_INTEGER*)&llStart);

		{
			LONGLONG llEnd   = 0;
			LONGLONG llStart = 0;

			QueryPerformanceCounter((LARGE_INTEGER*)&llStart);

			Sleep(uWaitTime);

			QueryPerformanceCounter((LARGE_INTEGER*)&llEnd);

			double delay = (((double)(llEnd - llStart))/((double)llFreq))*1000;

			if (delay > uWaitTime)
			{
				delay = 0;
			}
		}

		uTicks++;
	}

	CoUninitialize();
}

//========================================================================
// IOpcDaDevice

// BuildAddressSpace
bool CBHOpcDaDevice::BuildAddressSpace()
{
	COpcLock cLock(*this);

	// items to address space.
	OPC_POS pos = m_cItemList.GetHeadPosition();

	while (pos != NULL)
	{
		COpcString cItemID = m_cItemList.GetNext(pos);

		CBHOpcDaDeviceItem* pItem = NULL;

		if (m_cItems.Lookup(cItemID, pItem))
		{
			if (!pItem->BuildAddressSpace())
			{
				return false;
			}
		}
	}

	return true;
}

// ClearAddressSpace
void CBHOpcDaDevice::ClearAddressSpace()
{
	COpcLock cLock(*this);

	// items to address space.
	OPC_POS pos = m_cItemList.GetHeadPosition();

	while (pos != NULL)
	{
		COpcString cItemID = m_cItemList.GetNext(pos);

		CBHOpcDaDeviceItem* pItem = NULL;

		if (m_cItems.Lookup(cItemID, pItem))
		{
			pItem->ClearAddressSpace();
		}
	}
}

// ParseItemID
CBHOpcDaDeviceItem* CBHOpcDaDevice::ParseItemID(const COpcString& cItemID, COpcString& cItemPath)
{
	cItemPath   = (LPCWSTR)NULL;

	COpcString cRootID = cItemID;

	int iIndex = cRootID.Find(CPX_DATABASE_ROOT);

	if (iIndex != -1)
	{
		cItemPath = cRootID.SubStr(iIndex+_tcslen(CPX_DATABASE_ROOT)+1);
		cRootID   = cRootID.SubStr(0, iIndex-1);
	}

	CBHOpcDaDeviceItem* pItem = NULL;

	if (!m_cItems.Lookup(cRootID, pItem))
	{
		return NULL;
	}

	return pItem;
}

// IsKnownItem
bool CBHOpcDaDevice::IsKnownItem(const COpcString& cItemID)
{
	COpcLock cLock(*this);

	COpcString cItemPath;
	return (ParseItemID(cItemID, cItemPath) != NULL);
}

// GetAvailableProperties
HRESULT CBHOpcDaDevice::GetAvailableProperties(
	const COpcString&   cItemID, 
	bool                bReturnValues,
	COpcDaPropertyList& cProperties
	)
{
	COpcLock cLock(*this);

	COpcString cItemPath;
	CBHOpcDaDeviceItem* pItem = ParseItemID(cItemID, cItemPath);

	if (pItem == NULL)
	{
		return OPC_E_UNKNOWNITEMID;
	}

	return pItem->GetAvailableProperties(cItemPath, bReturnValues, cProperties);
}

// GetAvailableProperties
HRESULT CBHOpcDaDevice::GetAvailableProperties(
	const COpcString&      cItemID, 
	const COpcList<DWORD>& cIDs,
	bool                   bReturnValues,
	COpcDaPropertyList&    cProperties
	)
{
	COpcLock cLock(*this);

	COpcString cItemPath;
	CBHOpcDaDeviceItem* pItem = ParseItemID(cItemID, cItemPath);

	if (pItem == NULL)
	{
		return OPC_E_UNKNOWNITEMID;
	}

	return pItem->GetAvailableProperties(cItemPath, cIDs, bReturnValues, cProperties);
}

// Read
HRESULT CBHOpcDaDevice::Read(
							 const COpcString& cItemID, 
							 DWORD             dwPropertyID,
							 VARIANT&          cValue, 
							 FILETIME*         pftTimestamp,
							 WORD*             pwQuality
							 )
{
	COpcLock cLock(*this);

	COpcString cItemPath;
	CBHOpcDaDeviceItem* pItem = ParseItemID(cItemID, cItemPath);

	if (pItem == NULL)
	{
		return OPC_E_UNKNOWNITEMID;
	}

	// read value.
	return pItem->Read(cItemPath, dwPropertyID, cValue, pftTimestamp, pwQuality);
}

// Write
HRESULT CBHOpcDaDevice::Write(
							  const COpcString& cItemID, 
							  DWORD             dwPropertyID,
							  const VARIANT&    cValue, 
							  FILETIME*         pftTimestamp,
							  WORD*             pwQuality
							  )
{
	COpcLock cLock(*this);

	COpcString cItemPath;
	CBHOpcDaDeviceItem* pItem = ParseItemID(cItemID, cItemPath);

	if (pItem == NULL)
	{
		return OPC_E_UNKNOWNITEMID;
	}

	// write value.
	return pItem->Write(cItemPath, false, dwPropertyID, cValue, pftTimestamp, pwQuality);
}

// GetDeviceItem
CBHOpcDaDeviceItem* CBHOpcDaDevice::GetDeviceItem(const COpcString& cItemID)
{
	COpcLock cLock(*this);

	CBHOpcDaDeviceItem* pItem = NULL;

	if (!m_cItems.Lookup(cItemID, pItem))
	{
		return NULL;
	}

	return pItem;
}

//========================================================================
// IOpcXmlSerialize

// Init
void CBHOpcDaDevice::Init()
{
	this->IsRealSample(FALSE);
	m_cItems.RemoveAll();
	m_cItemList.RemoveAll();
	m_cBranches.RemoveAll();
}

// Clear
void CBHOpcDaDevice::Clear()
{
	OPC_POS pos = NULL;

	// clear all items.
	pos = m_cItems.GetStartPosition();

	while (pos != NULL)
	{
		COpcString cItemID;
		CBHOpcDaDeviceItem* pItem = NULL;
		m_cItems.GetNextAssoc(pos, cItemID, pItem);

		delete pItem;
	}

	m_cItems.RemoveAll();
	m_cItemList.RemoveAll();

	// clear all branches.
	pos = m_cBranches.GetStartPosition();

	while (pos != NULL)
	{
		COpcString cItemID;
		COpcStringList* pBranch = NULL;
		m_cBranches.GetNextAssoc(pos, cItemID, pBranch);

		delete pBranch;
	}

	m_cBranches.RemoveAll();

	// clear dictionaries.
	pos = m_cDictionaries.GetStartPosition();

	while (pos != NULL)
	{
		COpcString cDictionaryID;
		COpcDaTypeDictionary* pDictionary = NULL;
		m_cDictionaries.GetNextAssoc(pos, cDictionaryID, pDictionary);

		delete pDictionary;
	}

	m_cDictionaries.RemoveAll();

	Init();
}

// Read
bool CBHOpcDaDevice::Read(COpcXmlElement& cElement)
{
	COpcLock cLock(*this);

	// read top level items.
	COpcXmlElementList cItems;

	UINT uCount = cElement.GetChildren(cItems);

	for (UINT ii = 0; ii < uCount; ii++)
	{
		Read((LPTSTR)NULL, cItems[ii]);
	}

	return true;
}

// Read
bool CBHOpcDaDevice::Read(const COpcString& cElementPath, COpcXmlElement& cElement)
{
	// read element name.
	COpcString cElementName;

	READ_ATTRIBUTE(TAG_ELEMENT_NAME, cElementName);

	if (cElementName.IsEmpty())
	{
		return false;
	}

	// index element by path
	COpcStringList* pBranch = NULL;

	if (!m_cBranches.Lookup(cElementPath, pBranch))
	{
		m_cBranches[cElementPath] = pBranch = new COpcStringList();
	}

	pBranch->AddTail(cElementName);

	// build item id.
	COpcString cItemID;

	cItemID += cElementPath;
	cItemID += (cElementPath.IsEmpty())?_T(""):TAG_SEPARATOR;
	cItemID += cElementName;

	// check if current element is an item.
	COpcXmlElement cItem = cElement.GetChild(TAG_ITEM);

	if (cItem != NULL)
	{
		// check for duplicate item ids.
		if (m_cItems.Lookup(cItemID))
		{
			return false;
		}

		CBHOpcDaDeviceItem* pItem = new CBHOpcDaDeviceItem(cItemID);

		// initialize item.
		if (!pItem->Read(cItem))
		{
			delete pItem;
			return false;
		}

		// index item by item id.
		m_cItems[cItemID] = pItem;
		m_cItemList.AddTail(cItemID);
	}

	// read child elements.
	COpcXmlElement cChildren = cElement.GetChild(TAG_CHILD_ELEMENTS);

	if (cChildren != NULL)
	{
		COpcXmlElementList cItems;

		UINT uCount = cChildren.GetChildren(cItems);

		for (UINT ii = 0; ii < uCount; ii++)
		{
			Read(cItemID, cItems[ii]);
		}
	}

	return true;
}

// Write
bool CBHOpcDaDevice::Write(COpcXmlElement& cElement)
{
	OPC_ASSERT(false);  

	// not implemented.

	return false;
}

CBHOpcDaDevice::SERVER_TYPE CBHOpcDaDevice::ServerType() const
{
	return m_nServerType;
}

void CBHOpcDaDevice::ServerType( SERVER_TYPE val )
{
	m_nServerType = val;
}

CString CBHOpcDaDevice::ServerAddress() const
{
	return m_strServerAddress;
}

void CBHOpcDaDevice::ServerAddress( CString val )
{
	m_strServerAddress = val;
}

bool CBHOpcDaDevice::GenerateServerSetting( COpcXmlDocument& cFile )
{
	bool lbRet = false;
	
	switch (this->ServerType())
	{
	case CBHOpcDaDevice::ON_LINE:
		lbRet = this->GenerateOnlineSettingFile(cFile);
		break;
	case CBHOpcDaDevice::OFF_LINE:
		lbRet = this->GenerateOfflineSettingFile(cFile);
		break;
	default:
		lbRet = false;
	}
	this->IsRealSample(lbRet);
	return lbRet;
}

HINSTANCE g_HDll = NULL;

HINSTANCE CreateInstanceFromDll( LPCTSTR lpDllName, REFCLSID rclsid, REFIID riid, LPVOID * ppv )
{
	(*ppv) = NULL;

	HINSTANCE hDll = g_HDll;
	
	if (NULL == hDll)
	{
		g_HDll = LoadLibrary( lpDllName );

		hDll = g_HDll;
	}

	if ( NULL == hDll )
	{
		return NULL;
	}

	typedef HRESULT (__stdcall *GETCLASS_PROC)(REFCLSID,REFIID,LPVOID*);

	GETCLASS_PROC procGetClassObject = (GETCLASS_PROC)GetProcAddress( hDll, "DllGetClassObject" ); 

	if( procGetClassObject )
	{
		IClassFactory* pFactory = NULL;

		HRESULT hr = procGetClassObject(rclsid, IID_IClassFactory, reinterpret_cast<LPVOID*>(&pFactory));
		if( pFactory )
		{
			hr = pFactory->CreateInstance( NULL, riid, ppv);

			pFactory->Release();
			pFactory = NULL;

			if( NULL == *ppv )
			{
				FreeLibrary( hDll );
				return NULL;
			}
		}
		else
		{
			FreeLibrary( hDll );
			return NULL;
		}
	}
	else
	{
		FreeLibrary( hDll );
		return NULL;
	}

	return hDll;	
}

CString GetTaskManagerPath()
{
	CString strPath;
	LPTSTR lpModule = strPath.GetBuffer(MAX_PATH);
	GetModuleFileName(NULL, lpModule, MAX_PATH-1);
	LPTSTR lpPos = _tcsrchr(lpModule, _T('\\'));
	if (lpPos != NULL)
	{
		*(lpPos + 1) = _T('\0');
	}
	strPath.ReleaseBuffer();

	strPath+= TAG_CBHFIXCOM;

	return strPath;			
}



BOOL CBHOpcDaDevice::GetCommunication( CComPtr<ICBHFixComImp> & arefFixCom,
									   CBHOpcDaDevice::SERVER_TYPE anType )
{

	arefFixCom.CoCreateInstance(CLSID_CBHFixComImp);

	if (NULL == arefFixCom)
	{
			CreateInstanceFromDll(  GetTaskManagerPath(),
									CLSID_CBHFixComImp,
									IID_ICBHFixComImp, 
									reinterpret_cast<LPVOID*>(&arefFixCom));

	}

	if (NULL == arefFixCom)
	{
		ASSERT(FALSE);

		return FALSE;
	}

	arefFixCom->SetCommType(anType);

	return TRUE;
}


void CBHOpcDaDevice::GenerateHierarchy(COpcXmlDocument& cFile)
{


	if (CBHOpcDaDevice::GenerateRealSampleFile(cFile,
											   this->ServerAddress(),
											   this->ServerType(),
											   this->UserName(),
											   this->Password()))
	{
		return;
	}
	


	//1.generate xml file
	cFile.Init();

	COpcXmlElement  loRoot;

	cFile.New(COpcString(_T("Server")),COpcString(_T("Test")));

	loRoot	= cFile.GetRoot();

	if (loRoot == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	CString lstrGroup	=	_T("中国石油");
	CString lstrCompany =	_T("大庆石化");
	CString lstrFactory =	_T("化肥厂");
	CString lstrPlant	=	_T("102J");
	CString lstrChann   =   _T("1H");
	CString lstrChann2  =   _T("1V");
	CString lstrSet     =   _T("默认装置");

	COpcXmlElement lpOrgRoot = loRoot.AddChild(COpcString(TAG_BROWSE_ELEMENT));
	COpcXmlElement cElement = lpOrgRoot;
	cElement.SetAttribute(TAG_ELEMENT_NAME,lstrGroup.GetBuffer(0));
	
	COpcXmlElement loCompanysRoot = lpOrgRoot.AddChild(COpcString(TAG_CHILD_ELEMENTS));
	COpcXmlElement loCompany = loCompanysRoot.AddChild(COpcString(TAG_BROWSE_ELEMENT));
	cElement = loCompany;
	cElement.SetAttribute(TAG_ELEMENT_NAME,lstrCompany.GetBuffer(0));


	COpcXmlElement loFactorysRoot = loCompany.AddChild(COpcString(TAG_CHILD_ELEMENTS));
	COpcXmlElement loFactory = loFactorysRoot.AddChild(COpcString(TAG_BROWSE_ELEMENT));
	cElement = loFactory;
	cElement.SetAttribute(TAG_ELEMENT_NAME,lstrFactory.GetBuffer(0));

	COpcXmlElement loSetsRoot = loFactory.AddChild(COpcString(TAG_CHILD_ELEMENTS));
	COpcXmlElement loSet = loSetsRoot.AddChild(COpcString(TAG_BROWSE_ELEMENT));
	cElement = loSet;
	cElement.SetAttribute(TAG_ELEMENT_NAME,lstrSet.GetBuffer(0));


	COpcXmlElement loPlantsRoot = loSet.AddChild(COpcString(TAG_CHILD_ELEMENTS));
	COpcXmlElement loPlant = loPlantsRoot.AddChild(COpcString(TAG_BROWSE_ELEMENT));
	cElement = loPlant;
	cElement.SetAttribute(TAG_ELEMENT_NAME,lstrPlant.GetBuffer(0));



	COpcXmlElement loItemsRoot = loPlant.AddChild(COpcString(TAG_CHILD_ELEMENTS));
	COpcXmlElement loChannel = loItemsRoot.AppendChild(COpcString(TAG_BROWSE_ELEMENT));
	cElement = loChannel;
	cElement.SetAttribute(TAG_ELEMENT_NAME,(lstrChann).GetBuffer(0));	
	COpcXmlElement loFeatureRoot = loChannel.AddChild(COpcString(TAG_ITEM));
	
	COpcXmlElement loValue = loFeatureRoot.AddChild(COpcString(_T("Value")));
	loValue.SetAttribute(_T("xsi:type"),_T("xsd:float"));
	loValue.SetAttribute(TAG_PERIOD,_T("16000"));
	loValue.SetAttribute(TAG_SAMPLING_RATE,_T("1000"));
	loValue.SetAttribute(TAG_MAX_VALUE,_T("200"));
	loValue.SetAttribute(TAG_MIN_VALUE,_T("0"));
	loValue.SetValue(COpcString(_T("0")));


	loChannel = loItemsRoot.AppendChild(COpcString(TAG_BROWSE_ELEMENT));
	cElement = loChannel;
	cElement.SetAttribute(TAG_ELEMENT_NAME,(lstrChann2).GetBuffer(0));	
	loFeatureRoot = loChannel.AddChild(COpcString(TAG_ITEM));


	loValue = loFeatureRoot.AddChild(COpcString(_T("Value")));
	loValue.SetAttribute(_T("xsi:type"),_T("xsd:float"));
	loValue.SetAttribute(TAG_PERIOD,_T("16000"));
	loValue.SetAttribute(TAG_SAMPLING_RATE,_T("1000"));
	loValue.SetAttribute(TAG_MAX_VALUE,_T("200"));
	loValue.SetAttribute(TAG_MIN_VALUE,_T("0"));
	loValue.SetValue(COpcString(_T("0")));

	
/*
	//2.generate memory structure
	PLANT_INFO & lrefPlant	= this->m_oPlantInfoPool[lstrGroup+lstrCompany+lstrFactory+lstrSet+lstrPlant];
	lrefPlant.m_strGroup	= lstrGroup;	
	lrefPlant.m_strCompany  = lstrCompany;
	lrefPlant.m_strFactory	= lstrFactory;
	lrefPlant.m_strSet		= lstrSet;
	lrefPlant.m_strPlant	= lstrPlant;
	
	CHANNEL_INFO * lrefChannInfo = &lrefPlant.m_oChannel_Info[lstrChann];
	lrefChannInfo->m_strGroup	= lstrGroup;
	lrefChannInfo->m_strCompany	= lstrCompany;
	lrefChannInfo->m_strFactory	= lstrFactory;
	lrefChannInfo->m_strPlant	= lstrPlant;
	lrefChannInfo->m_strSet		= lstrSet;
	lrefChannInfo->m_strChannel  = lstrChann;
	
	CString lstrUniqueKey =  lstrGroup
							+TAG_SEPARATOR
							+lstrCompany
							+TAG_SEPARATOR
							+lstrFactory
							+TAG_SEPARATOR
							+lstrPlant
							+TAG_SEPARATOR
							+lstrChann;

	this->m_oTotalChannelInfoPool[lstrUniqueKey] = lrefChannInfo;

	lrefChannInfo = &lrefPlant.m_oChannel_Info[lstrChann2];
	lrefChannInfo->m_strGroup	= lstrGroup;
	lrefChannInfo->m_strCompany	= lstrCompany;
	lrefChannInfo->m_strFactory	= lstrFactory;
	lrefChannInfo->m_strPlant	= lstrPlant;
	lrefChannInfo->m_strSet		= lstrSet;
	lrefChannInfo->m_strChannel  = lstrChann2;

	 lstrUniqueKey =  lstrGroup
		+TAG_SEPARATOR
		+lstrCompany
		+TAG_SEPARATOR
		+lstrFactory
		+TAG_SEPARATOR
		+lstrPlant
		+TAG_SEPARATOR
		+lstrChann2;

	this->m_oTotalChannelInfoPool[lstrUniqueKey] = lrefChannInfo;*/

	
}


bool CBHOpcDaDevice::GenerateOnlineSettingFile( COpcXmlDocument& cFile )
{
	CComPtr<ICBHFixComImp> loFixCom;
	
		try
		{
		
			//1.link to Server
			if (!this->GetCommunication(loFixCom,this->ServerType()))
			{
				ASSERT(FALSE);
				return FALSE;
			}

			if (!this->Link(*loFixCom,this->ServerAddress()))
			{
				ASSERT(FALSE);
				return FALSE;
			}

			
				
			//2.get all plants
			
		
			//3.enumerate channels
			COpcLock cLock(this->m_oPlantInfoLock);
			cLock.Lock();
			this->GenerateHierarchy(cFile);
			cLock.Unlock();
		
			//4.generate online setting file
		
		}catch(...)
		{
			//WRITE_FATAL_LOG;
		}
	

	return true;
}

bool CBHOpcDaDevice::GenerateOfflineSettingFile( COpcXmlDocument& cFile )
{
	return false;
}

BOOL CBHOpcDaDevice::Link( ICBHFixComImp & arefFixCom, CString & astrAddress )
{
	BOOL lbLinked = FALSE;	
	lbLinked = arefFixCom.Link(&CComBSTR(astrAddress),&CComBSTR(_T("")));
	return lbLinked;
}

int ConvertCStringToVairantArray(CString & arefSrc,CComVariant & arefVariant)
{
	USES_CONVERSION;

	CHAR * lpSrc = T2A(arefSrc);
	int lnBytesCount = strlen(lpSrc);
	if (0 == lnBytesCount)
	{
		ASSERT(FALSE);
		return lnBytesCount;
	}

	arefVariant.Clear();

	SAFEARRAYBOUND loBounds;
	loBounds.cElements = lnBytesCount;
	loBounds.lLbound = 0;

	LPSAFEARRAY lpsaValues = NULL;
	CHAR * lpDataBuffer = NULL;
	arefVariant.vt = VT_ARRAY | VT_UI1;

	lpsaValues = SafeArrayCreate(VT_UI1, 1, &loBounds);
	arefVariant.parray = lpsaValues;

	if(arefVariant.parray != NULL)
	{
		SafeArrayAccessData(arefVariant.parray,(void **)&lpDataBuffer);
		memcpy(lpDataBuffer,lpSrc,lnBytesCount);
		SafeArrayUnaccessData(arefVariant.parray);
		
	}else
	{
		ASSERT(FALSE);
		return 0;
	}

	return lnBytesCount;
}

BOOL CBHOpcDaDevice::UpdateFromBHDevice()
{

	if (this->m_oFixComUpdater == NULL)
	{
		if (!this->GetCommunication(m_oFixComUpdater,this->ServerType()))
		{
			ASSERT(FALSE);
			return FALSE;
		}
	}

	if (NULL == m_oFixComUpdater)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (!this->Link(*m_oFixComUpdater,this->ServerAddress()))
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if(TRUE)
	{
		for (PLANT_POOL::iterator lpPlant = this->m_oPlantInfoPool.begin();
			lpPlant != this->m_oPlantInfoPool.end();
			lpPlant++)
		{

			PLANT_INFO & lrefPlant = lpPlant->second;

			CComVariant loBuffer;
			int lnBufferLength = ConvertCStringToVairantArray(lrefPlant.m_strPlant,loBuffer);


			if (lnBufferLength>0)
			{
				m_oFixComUpdater->CreateHead(SERVICE_SERVICE_ON_MONITORALARMSTAT);
				m_oFixComUpdater->SetItemString(FIELD_SYSTEM_COMPANY,&CComBSTR(lrefPlant.m_strCompany));
				m_oFixComUpdater->SetItemString(FIELD_SYSTEM_FACTORY,&CComBSTR(lrefPlant.m_strFactory));
				m_oFixComUpdater->SetItemString(FIELD_SERVICE_PLANTID,&CComBSTR(lrefPlant.m_strPlant));

				while (m_oFixComUpdater->More()>0)
				{
					CString lstrChannel = (m_oFixComUpdater->GetItem(FIELD_SERVICE_CHANN1).GetBSTR());
					CHANNEL_POOL::iterator lpItChann = lrefPlant.m_oChannel_Info.find(lstrChannel);
					if ( lpItChann!= lrefPlant.m_oChannel_Info.end())
					{
						CHANNEL_INFO & lrefChannInfo = lpItChann->second;
						lrefChannInfo.m_cValue.floatValue = (float)m_oFixComUpdater->GetDouble(FIELD_SERVICE_CHANN1VALUE);
						lrefChannInfo.m_cValue.eType = OpcXml::XML_FLOAT;
					}
				}//while (loFixComm->More()>0)

			}//if (lnBufferLength>0)

		}//for (PLANT_POOL::iterator lpPlant = this->m_oPlantInfo.begin();
	}
	return TRUE;
}

BOOL CBHOpcDaDevice::IsRealSample() const
{
	return m_bRealSample;
}

void CBHOpcDaDevice::IsRealSample( BOOL val )
{
	m_bRealSample = val;
}

INT GetSplitStrArray(const CString& strData,
					 const CString& strSplitFlag,
					 CStringArray &array,
					 BOOL SequenceAsOne)
{
	CString sData = strData;

	CString sSplitFlag = strSplitFlag;

	int lnSplitFlagLength = strSplitFlag.GetLength();

	if (sData.Right(1) != sSplitFlag) sData +=sSplitFlag;

	CString sTemp;

	int pos =-1;

	while ((pos=sData.Find(sSplitFlag,0)) != -1)
	{
		sTemp = sData.Left(pos);

		if (!SequenceAsOne)
		{
			array.Add(sTemp);
		}
		else
		{
			if (!sTemp.IsEmpty() && sTemp !="") ////连续的分隔符视为单个处理
			{
				array.Add(sTemp);
			}
		}
		sData = sData.Right(sData.GetLength() - pos - lnSplitFlagLength);
	}

	return array.GetSize();
}

bool CBHOpcDaDevice::BuildBHItemAddress()
{

	COpcLock cLock(*this);

	// update each group.
	OPC_POS pos = m_cItems.GetStartPosition();
	OpcXml::AnyType aoValue ;
	CString lstrItemUniqueId;
	CString lstrSplitFlag = TAG_SEPARATOR;

	//2.generate memory structure
	while (pos != NULL)
	{
		COpcString cItemID;
		CBHOpcDaDeviceItem* pItem = NULL;

		m_cItems.GetNextAssoc(pos, cItemID, pItem);

		lstrItemUniqueId = cItemID.GetBuffer();
		CStringArray loArray;		
		GetSplitStrArray(lstrItemUniqueId,lstrSplitFlag,loArray,TRUE);

		if (loArray.GetCount()<6)
		{
			ASSERT(FALSE);
			continue;
		}

		CString lstrGroup   = loArray.GetAt(0);
		CString lstrCompany = loArray.GetAt(1);
		CString lstrFactory = loArray.GetAt(2);
		CString lstrSet		= loArray.GetAt(3);
		CString lstrPlant   = loArray.GetAt(4);
		CString lstrChann   = loArray.GetAt(5);

		PLANT_INFO & lrefPlant	= this->m_oPlantInfoPool[lstrGroup+lstrCompany+lstrFactory+lstrSet+lstrPlant];
		lrefPlant.m_strGroup	= lstrGroup;	
		lrefPlant.m_strCompany  = lstrCompany;
		lrefPlant.m_strFactory	= lstrFactory;
		lrefPlant.m_strSet		= lstrSet;
		lrefPlant.m_strPlant	= lstrPlant;

		CHANNEL_INFO * lrefChannInfo = &lrefPlant.m_oChannel_Info[lstrChann];
		lrefChannInfo->m_strGroup	= lstrGroup;
		lrefChannInfo->m_strCompany	= lstrCompany;
		lrefChannInfo->m_strFactory	= lstrFactory;
		lrefChannInfo->m_strPlant	= lstrPlant;
		lrefChannInfo->m_strSet		= lstrSet;
		lrefChannInfo->m_strChannel  = lstrChann;

		CString lstrUniqueKey =  lstrGroup
			+TAG_SEPARATOR
			+lstrCompany
			+TAG_SEPARATOR
			+lstrFactory
			+TAG_SEPARATOR
			+lstrSet
			+TAG_SEPARATOR
			+lstrPlant
			+TAG_SEPARATOR
			+lstrChann;

		this->m_oTotalChannelInfoPool[lstrUniqueKey] = lrefChannInfo;
	}

	cLock.Unlock();

	return true;
}

BOOL CBHOpcDaDevice::GenerateRealSampleFile( COpcXmlDocument& cFile, 
											 CString & astrFileAddress, 
											 int  anType,
											 CString & astrUserName,
											 CString & astrPassword)
{
	cFile.Init();
	//0. check xml tree
	COpcXmlElement  loRoot;

	cFile.New(COpcString(_T("Server")),COpcString(_T("Test")));
	loRoot	= cFile.GetRoot();

	if (loRoot == NULL)
	{
		OutputDebugString(_T("COpcXmlElement  loRoot failed  is null\r\n"));
		ASSERT(FALSE);
		return FALSE;
	}


	//1.create fixcom
	CComPtr<ICBHFixComImp> arefFixCom;
	arefFixCom.CoCreateInstance(CLSID_CBHFixComImp);

	if (NULL == arefFixCom)
	{
		CreateInstanceFromDll(  GetTaskManagerPath(),
			CLSID_CBHFixComImp,
			IID_ICBHFixComImp, 
			reinterpret_cast<LPVOID*>(&arefFixCom));

	}

	if (NULL == arefFixCom)
	{
		OutputDebugString(_T("fixcomm CoCreateInstance failed  is null\r\n"));
		ASSERT(FALSE);

		return FALSE;
	}
	//2. set comm type
	arefFixCom->SetCommType(anType);
	
	//3. link to server
	if (arefFixCom->Link(&CComBSTR(astrFileAddress),&CComBSTR(_T("")))<0)
	{
		OutputDebugString(_T("arefFixCom->Link failed\r\n"));
		ASSERT(FALSE);
		return FALSE;
	}
	
	//4.Enumerate all channels
	
	//4.1 get all factorys
	arefFixCom->CreateHead(SERVICE_SYSTEM_GETCOMPANYTOFUSER);
	arefFixCom->SetItemString(FIELD_SYSTEM_USEID, &CComBSTR(astrUserName));
	arefFixCom->SetItemString(FIELD_SYSTEM_PASSWORD, &CComBSTR(astrPassword));
	
	std::vector<PLANT_INFO> loFactorys;
	std::vector<PLANT_INFO> loPlants;
	std::vector<CHANNEL_INFO> loChanns;
	
	while(arefFixCom->More()>0)
	{
		PLANT_INFO loFactory;
		loFactory.m_strGroup = (TCHAR *)arefFixCom->GetItem(FIELD_SYSTEM_GROUP);
		loFactory.m_strCompany = (TCHAR *)arefFixCom->GetItem(FIELD_SYSTEM_COMPANY);
		loFactory.m_strFactory = (TCHAR *)arefFixCom->GetItem(FIELD_SYSTEM_FACTORY);
		loFactorys.push_back(loFactory);
	}

	if (loFactorys.size()<=0)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	//4.2 get all plants
	BOOL lsSupportBatchPlantGet  = FALSE;
	//4.2.1 try 25210 (4.2.1 )
	//4.2.2 use 25210 to get all plants
	
	if (!lsSupportBatchPlantGet)
	{
		for (int i=0;i<loFactorys.size();i++)
		{
			arefFixCom->CreateHead(SERVICE_SYSTEM_GETPLANTIPOFSUBCORP);
			arefFixCom->SetItemString(FIELD_SYSTEM_COMPANY, &CComBSTR(loFactorys[i].m_strCompany));
			arefFixCom->SetItemString(FIELD_SYSTEM_FACTORY, &CComBSTR(loFactorys[i].m_strFactory));

			while(arefFixCom->More()>0)
			{
				PLANT_INFO loPlant;
				loPlant.m_strGroup = (TCHAR *)arefFixCom->GetItem(FIELD_SYSTEM_GROUP);
				loPlant.m_strCompany = (TCHAR *)arefFixCom->GetItem(FIELD_SYSTEM_COMPANY);
				loPlant.m_strFactory = (TCHAR *)arefFixCom->GetItem(FIELD_SYSTEM_FACTORY);	
				loPlant.m_strPlant = (TCHAR *)arefFixCom->GetItem(FIELD_SYSTEM_PLANT);
				loPlant.m_strSet =   (TCHAR *)arefFixCom->GetItem(FIELD_SYSTEM_SET);
				if (loPlant.m_strSet.GetLength()==0)
				{
					loPlant.m_strSet = TAG_DEFAULT_SET_NAME;
				}
				if (loPlant.m_strGroup.GetLength() == 0)
				{
					loPlant.m_strGroup = TAG_DEFAULT_GROUP_NAME;
				}
				loPlants.push_back(loPlant);
			}
		}
	}

	if (loPlants.size()<=0)
	{
		ASSERT(FALSE);
		return FALSE;
	}
	typedef std::map<CString,COpcXmlElement *> XMLMap;
	XMLMap loXmlNodes;
	
	//4.3 get all channel
	CString lstrKey ;
	for (int i =0;i<loPlants.size();i++)
	{
		PLANT_INFO & loPlant = loPlants[i];

		arefFixCom->CreateHead(SERVICE_SERVICE_ON_MONITORALARMSTAT);
		arefFixCom->SetItemString(FIELD_SYSTEM_COMPANY,&CComBSTR(loPlant.m_strCompany));
		arefFixCom->SetItemString(FIELD_SYSTEM_FACTORY,&CComBSTR(loPlant.m_strFactory));
		arefFixCom->SetItemString(FIELD_SERVICE_PLANTID,&CComBSTR(loPlant.m_strPlant));
	
		while (arefFixCom->More()>0)
		{
			CString lstrChannel = (TCHAR *)arefFixCom->GetItem(FIELD_SERVICE_CHANN1);
			
			//group
			lstrKey = loPlant.m_strGroup;			
			COpcXmlElement ** lppXmlNodeGroup = &loXmlNodes[lstrKey];			
			if (NULL == *lppXmlNodeGroup)
			{
				COpcXmlElement loTemp =  loRoot.AppendChild(TAG_BROWSE_ELEMENT);
				loTemp.SetAttribute(TAG_ELEMENT_NAME,loPlant.m_strGroup.GetBuffer(0));
				*lppXmlNodeGroup = new COpcXmlElement(loTemp.AddChild(COpcString(TAG_CHILD_ELEMENTS)));
			}
			
			//company
			lstrKey = loPlant.m_strGroup+loPlant.m_strCompany;
			COpcXmlElement ** lppXmlNodeCompany = &loXmlNodes[lstrKey];
			if (NULL == *lppXmlNodeCompany)
			{
				COpcXmlElement loTemp = (**lppXmlNodeGroup).AppendChild(TAG_BROWSE_ELEMENT);
				loTemp.SetAttribute(TAG_ELEMENT_NAME,loPlant.m_strCompany.GetBuffer(0));
				*lppXmlNodeCompany = new COpcXmlElement(loTemp.AddChild(COpcString(TAG_CHILD_ELEMENTS)));
			}

			//factory
			lstrKey = loPlant.m_strGroup+loPlant.m_strCompany+loPlant.m_strFactory;
			COpcXmlElement ** lppXmlNodeFactory = &loXmlNodes[lstrKey];
			if (NULL == *lppXmlNodeFactory)
			{
				COpcXmlElement loTemp  = (**lppXmlNodeCompany).AppendChild(TAG_BROWSE_ELEMENT);
				loTemp.SetAttribute(TAG_ELEMENT_NAME,loPlant.m_strFactory.GetBuffer(0));
				*lppXmlNodeFactory = new COpcXmlElement(loTemp.AddChild(COpcString(TAG_CHILD_ELEMENTS)));
			}

			//set
			lstrKey = loPlant.m_strGroup+loPlant.m_strCompany+loPlant.m_strFactory+loPlant.m_strSet;
			COpcXmlElement ** lppXmlNodeSet = &loXmlNodes[lstrKey];
			if (NULL == *lppXmlNodeSet)
			{
				COpcXmlElement loTemp = (**lppXmlNodeFactory).AppendChild(TAG_BROWSE_ELEMENT);
				loTemp.SetAttribute(TAG_ELEMENT_NAME,loPlant.m_strSet.GetBuffer(0));
				*lppXmlNodeSet = new COpcXmlElement(loTemp.AddChild(COpcString(TAG_CHILD_ELEMENTS)));
			}


			//plant
			lstrKey = loPlant.m_strGroup+loPlant.m_strCompany+loPlant.m_strFactory+loPlant.m_strSet+loPlant.m_strPlant;
			COpcXmlElement ** lppXmlNodePlant = &loXmlNodes[lstrKey];
			if (NULL == *lppXmlNodePlant)
			{
				COpcXmlElement loTemp = (**lppXmlNodeSet).AppendChild(TAG_BROWSE_ELEMENT);
				loTemp.SetAttribute(TAG_ELEMENT_NAME,loPlant.m_strPlant.GetBuffer(0));
				*lppXmlNodePlant = new COpcXmlElement(loTemp.AddChild(COpcString(TAG_CHILD_ELEMENTS)));
			}

			//channel
			 COpcXmlElement loChannel = (**lppXmlNodePlant).AppendChild(COpcString(TAG_BROWSE_ELEMENT));
			 loChannel.SetAttribute(TAG_ELEMENT_NAME,(lstrChannel).GetBuffer(0));	
			 COpcXmlElement loFeatureRoot = loChannel.AddChild(COpcString(TAG_ITEM));
			 COpcXmlElement loValue = loFeatureRoot.AddChild(COpcString(_T("Value")));
			 loValue.SetAttribute(_T("xsi:type"),_T("xsd:float"));
			 loValue.SetAttribute(TAG_PERIOD,_T("16000"));
			 loValue.SetAttribute(TAG_SAMPLING_RATE,_T("1000"));
			 loValue.SetAttribute(TAG_MAX_VALUE,_T("200"));
			 loValue.SetAttribute(TAG_MIN_VALUE,_T("0"));
			 loValue.SetValue(COpcString(_T("0")));
		}
	}

	if (loXmlNodes.size()<=0)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	for (XMLMap::iterator lpIt = loXmlNodes.begin();
		lpIt!=loXmlNodes.end();
		lpIt++)
	{
		delete lpIt->second;
	}



	return TRUE;
}


