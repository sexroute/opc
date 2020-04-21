//============================================================================
// TITLE: Simple Client.h
//
// CONTENTS:
// 
// A very simple client program that illustrates how to get data from a server. 
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
// 2004/01/05 RSA   Initial implementation.

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <objbase.h>
#include <olectl.h>
#include <comcat.h>
#include <atlconv.h>
#include <atlcomcli.h>
#include "opcda.h"
#include "opcda_i.c"

class Callback : public IOPCDataCallback
{
public:

	Callback() 
	{
		m_ulRefs = 1;
	}

	//==========================================================================
	// IUnknown

	// QueryInterface
	STDMETHODIMP QueryInterface(REFIID iid, LPVOID* ppInterface) 
	{
		if (ppInterface == NULL)
		{
			return E_INVALIDARG;
		}

		if (iid == IID_IUnknown)
		{
			*ppInterface = dynamic_cast<IUnknown*>(this);
			AddRef();
			return S_OK;
		}

		if (iid == IID_IOPCDataCallback)
		{
			*ppInterface = dynamic_cast<IOPCDataCallback*>(this);
			AddRef();
			return S_OK; 
		}

		return E_NOINTERFACE;
	}

	// AddRef
	STDMETHODIMP_(ULONG) AddRef()
	{
		return InterlockedIncrement((LONG*)&m_ulRefs); 
	}

	// Release
	STDMETHODIMP_(ULONG) Release()
	{
		ULONG ulRefs = InterlockedDecrement((LONG*)&m_ulRefs); 

		if (ulRefs == 0) 
		{ 
			delete this; 
			return 0; 
		} 

		return ulRefs; 
	}

	//==========================================================================
	// IOPCDataCallback

	// OnDataChange
	STDMETHODIMP OnDataChange(
		DWORD       dwTransid, 
		OPCHANDLE   hGroup, 
		HRESULT     hrMasterquality,
		HRESULT     hrMastererror,
		DWORD       dwCount, 
		OPCHANDLE * phClientItems, 
		VARIANT   * pvValues, 
		WORD      * pwQualities,
		FILETIME  * pftTimeStamps,
		HRESULT   * pErrors
		)
	{
		USES_CONVERSION;

		for (DWORD ii = 0; ii < dwCount; ii++)
		{
			VARIANT vValue;
			VariantInit(&vValue);

			if (SUCCEEDED(VariantChangeType(&vValue, &(pvValues[ii]), NULL, VT_BSTR)))
			{
				_tprintf(_T("Handle = '%d', Value = '%s'\r\n"), phClientItems[ii], OLE2T(vValue.bstrVal));
				VariantClear(&vValue);
			}
		}

		return S_OK;
	}

	// OnReadComplete
	STDMETHODIMP OnReadComplete(
		DWORD       dwTransid, 
		OPCHANDLE   hGroup, 
		HRESULT     hrMasterquality,
		HRESULT     hrMastererror,
		DWORD       dwCount, 
		OPCHANDLE * phClientItems, 
		VARIANT   * pvValues, 
		WORD      * pwQualities,
		FILETIME  * pftTimeStamps,
		HRESULT   * pErrors
		)
	{
		return S_OK;
	}

	// OnWriteComplete
	STDMETHODIMP OnWriteComplete(
		DWORD       dwTransid, 
		OPCHANDLE   hGroup, 
		HRESULT     hrMastererr, 
		DWORD       dwCount, 
		OPCHANDLE * pClienthandles, 
		HRESULT   * pErrors
		)
	{
		return S_OK;
	}


	// OnCancelComplete
	STDMETHODIMP OnCancelComplete(
		DWORD       dwTransid, 
		OPCHANDLE   hGroup
		)
	{
		return S_OK;
	}

private:

	ULONG m_ulRefs;
};

int _tmain(int argc, _TCHAR* argv[])
{
	USES_CONVERSION;

	// initialize COM.
	if (FAILED(CoInitializeEx(NULL, COINIT_MULTITHREADED)))
	{
		_tprintf(_T("CoInitializeEx failed.\r\n"));
		return -1;
	}

	// check arguments.
	if (argc < 2 || argc > 3)
	{
		_tprintf(_T("Usage: ProgID [HostName]\r\n"));
		return -1;
	}

	// fetch command line parameters.
	LPTSTR szProgID = argv[1];
	LPTSTR szHostName = NULL;

	if (argc > 2)
	{
		szHostName = argv[2];
	}

	// lookup CLSID from ProgID.
	CLSID cClsid = GUID_NULL;

	if (FAILED(CLSIDFromProgID(T2OLE(szProgID), &cClsid)))
	{
		if (UuidFromString((BYTE*)szProgID, &cClsid) != RPC_S_OK)
		{
			_tprintf(_T("Could not resolve Prog ID/CLSID: '%s'\r\n"), szProgID);
			return -1;
		}
	}

	// initialize server security info.
	COSERVERINFO cInfo; 
	memset(&cInfo, 0, sizeof(cInfo));

	cInfo.pwszName    = T2OLE(szHostName);
	cInfo.pAuthInfo   = NULL;
	cInfo.dwReserved1 = NULL;
	cInfo.dwReserved2 = NULL;

	// setup requested interfaces.
	MULTI_QI cResults;
	memset(&cResults, 0, sizeof(cResults));

	cResults.pIID = &IID_IOPCServer;
	cResults.pItf = NULL;
	cResults.hr   = S_OK;

	// call create instance.
	HRESULT hResult = CoCreateInstanceEx(
		cClsid,
		NULL,
		CLSCTX_SERVER,
		&cInfo,
		1,
		&cResults);

	if (FAILED(hResult))
	{
		_tprintf(_T("CoCreateInstanceEx failed 0x%08X.\r\n"),hResult);
		return hResult;
	}

	_tprintf(_T("CoCreateInstanceEx succeed.\r\n"));

	// check that interface is supported.
	if (FAILED(cResults.hr))
	{
		_tprintf(_T("QueryInterface failed.\r\n"));
		return hResult;
	}

	_tprintf(_T("QueryInterface succeed.\r\n"));

	IOPCServer* ipServer = (IOPCServer*)cResults.pItf;

	OPCHANDLE hGroup = NULL;
	DWORD dwRevisedUpdateRate = 0;

	IOPCItemMgt* ipGroup = NULL;

	// add group to server.
	hResult = ipServer->AddGroup(
		L"",
		TRUE,
		1000, // 1 second update rate.
		NULL,
		NULL,
		NULL,
		LOCALE_SYSTEM_DEFAULT,
		&hGroup,
		&dwRevisedUpdateRate,
		IID_IOPCItemMgt,
		(IUnknown**)&ipGroup
		);

	if (FAILED(hResult))
	{
		ipServer->Release();

		_tprintf(_T("AddGroup failed.\r\n"));
		return hResult;
	}

	_tprintf(_T("AddGroup succeed.\r\n"));

	// set up connection point.
	IConnectionPointContainer* ipCPC = NULL;

	hResult = ipGroup->QueryInterface(IID_IConnectionPointContainer, (void**)&ipCPC);

	if (FAILED(hResult))
	{
		ipGroup->Release();
		ipServer->RemoveGroup(hGroup, FALSE);
		ipServer->Release();

		_tprintf(_T("QueryInterface for IConnectionPointContainer failed.\r\n"));
		return hResult;
	}

	_tprintf(_T("QueryInterface for IConnectionPointContainer succeed.\r\n"));

	IConnectionPoint* ipCP = NULL;

	hResult = ipCPC->FindConnectionPoint(IID_IOPCDataCallback, &ipCP);

	if (FAILED(hResult))
	{
		_tprintf(_T("FindConnectionPoint failed 0x%08X.\r\n"),hResult);
	}



	/*
	hResult = ipCPC->FindConnectionPoint(IID_IOPCDataCallback, &ipCP);

	if (FAILED(hResult))
	{
	ipCPC->Release();
	ipGroup->Release();
	ipServer->RemoveGroup(hGroup, FALSE);
	ipServer->Release();

	_tprintf(_T("FindConnectionPoint failed 0x%08X.\r\n"),hResult);
	return hResult;
	}

	_tprintf(_T("FindConnectionPoint succeed 0x%08X.\r\n"),hResult);

	ipCPC->Release();*/


	// create the callback object.
	bool lbShouldCallBack = false;
	Callback* ipCallback = new Callback();
	DWORD dwAdvise = NULL;

	hResult = ipCP->Advise(ipCallback, &dwAdvise);

	if (FAILED(hResult))
	{
		_tprintf(_T("Advise failed 0x%08X.\r\n"),hResult);
	}


	/*
	hResult = ipCP->Advise(ipCallback, &dwAdvise);


	if (FAILED(hResult))
	{
	ipCP->Release();
	ipCallback->Release();
	ipGroup->Release();
	ipServer->RemoveGroup(hGroup, FALSE);
	ipServer->Release();

	_tprintf(_T("Advise failed 0x%08X.\r\n"),hResult);
	//return hResult;
	}else
	{
	_tprintf(_T("Advise scucceed 0x%08X.\r\n"),hResult);
	lbShouldCallBack = true;
	}
	*/



	// add items.
	DWORD          dwCount  = 2;
	OPCITEMDEF*    pItems   = (OPCITEMDEF*)CoTaskMemAlloc(dwCount*sizeof(OPCITEMDEF));
	OPCITEMRESULT* pResults = NULL;
	HRESULT*       pErrors  = NULL;

	memset(pItems, 0, sizeof(OPCITEMDEF)*dwCount);

	pItems[0].szItemID            = T2OLE(_T("FCC1.LIC_2410.PV"));
	pItems[0].szAccessPath        = NULL;
	pItems[0].bActive             = TRUE;
	pItems[0].hClient             = 1;
	pItems[0].vtRequestedDataType = VT_EMPTY;
	pItems[0].dwBlobSize          = 0;
	pItems[0].pBlob               = NULL;

	pItems[1].szItemID            = T2OLE(_T("FCC1.LIC_2410.PV"));
	pItems[1].szAccessPath        = NULL;
	pItems[1].bActive             = TRUE;
	pItems[1].hClient             = 2;
	pItems[1].vtRequestedDataType = VT_EMPTY;
	pItems[1].dwBlobSize          = 0;
	pItems[1].pBlob               = NULL;

	// add items to group on server.
	hResult = ipGroup->AddItems(dwCount, pItems, &pResults, &pErrors);
	if (FAILED(hResult))
	{
		CoTaskMemFree(pItems);

		if(lbShouldCallBack)
		{
			ipCP->Unadvise(dwAdvise);

		}

		ipCP->Release();

		if (lbShouldCallBack)
		{
			ipCallback->Release();
		}

		ipGroup->Release();
		ipServer->RemoveGroup(hGroup, FALSE);
		ipServer->Release();

		_tprintf(_T("AddItems failed.0x%08X.\r\n"),hResult);
		return hResult;
	}

	_tprintf(_T("AddItems result.0x%08X.\r\n"),hResult);

	if (hResult == S_FALSE)
	{
		for (DWORD ii = 0; ii < dwCount; ii++)
		{
			_tprintf(_T("AddItem '%s' result: [0x%08X]\r\n"), OLE2T(pItems[ii].szItemID), pErrors[ii]);
		}
		if (lbShouldCallBack)
		{
			ipCP->Unadvise(dwAdvise);
		}

		ipCP->Release();

		if (lbShouldCallBack)
		{
			ipCallback->Release();
		}


		ipGroup->Release();
		ipServer->RemoveGroup(hGroup, FALSE);
		ipServer->Release();

		_tprintf(_T("AddItems was not completely successful.\r\n"));
		return hResult;
	}



	// sleep waiting for callbacks.
	if (lbShouldCallBack)
	{
		Sleep(10000);
	}
	else
	{
		_tprintf(_T("Begin to Query IOPCSyncIO.\r\n"));

		IOPCSyncIO* pIOPCSyncIO = NULL; 

		HRESULT lhrRet = ipGroup->QueryInterface(__uuidof(pIOPCSyncIO), (void**) &pIOPCSyncIO);	

		OPCHANDLE lhServer = pResults->hServer;

		if (pIOPCSyncIO!= NULL)
		{
			_tprintf(_T("Query IOPCSyncIO Succeed.\r\n"));

			OPCITEMSTATE* pValue = NULL;
			HRESULT* pErrors = NULL;

			HRESULT hr = pIOPCSyncIO->Read(OPC_DS_DEVICE, 2, &lhServer, &pValue, &pErrors); 

			_tprintf(_T("Begin to Read.\r\n"));

			if (FAILED(hr)) 
			{				
				_tprintf(_T("Read was failed 0x%08X 0x%08X.\r\n"),hr,*pErrors);

			}else
			{
				_tprintf(_T("Read was succeed 0x%08X 0x%08X.\r\n"),hr,*pErrors);
			}

			if (NULL == pValue)
			{
				_tprintf(_T("Read was failed 0x%08X 0x%08X.\r\n"),hr,*pErrors);
			}

			VARIANT  varValue = pValue[0].vDataValue;
			_tprintf(_T("value: %8f. pValue->wQuality:0x%08X\r\n"),varValue.fltVal,pValue->wQuality&0xC0);
			CoTaskMemFree(pErrors); 
			pErrors = NULL; 

			CoTaskMemFree(pValue); 
			pValue = NULL; 

			// release the reference to the IOPCSyncIO interface: 
			pIOPCSyncIO->Release(); 

		}else
		{
			_tprintf(_T("failed to get IOPCSyncIO 0x%08X \r\n"),lhrRet);
		}

		CComQIPtr<IOPCAsyncIO> loSp = ipGroup;

		if (NULL!=loSp)
		{
			_tprintf(_T("Get IOPCAsyncIO succeed \r\n"));
			
		}

		CComQIPtr<IDataObject> loSpData = ipGroup;

		if (NULL!=loSp)
		{
			_tprintf(_T("Get IDataObject succeed \r\n"));

		
		}
	}


	// must always free the blob that the server may return.
	for (DWORD ii = 0; ii < dwCount; ii++)
	{
		if (pResults[ii].dwBlobSize > 0)
		{
			CoTaskMemFree(pResults[ii].pBlob);
		}
	}

	// free other memory.
	CoTaskMemFree(pItems);
	CoTaskMemFree(pResults);
	CoTaskMemFree(pErrors);

	// cleanup.
	if (lbShouldCallBack)
	{
		ipCP->Unadvise(dwAdvise);
	}

	ipCP->Release();

	if (lbShouldCallBack)
	{
		ipCallback->Release();
	}


	ipGroup->Release();
	ipServer->RemoveGroup(hGroup, FALSE);
	ipServer->Release();

	// uninitialize com.
	CoUninitialize();
	return 0;
}

