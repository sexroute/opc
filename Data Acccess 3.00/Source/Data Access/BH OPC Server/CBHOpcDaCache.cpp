//==============================================================================
// TITLE: CXxxDaCache.cpp
//
// CONTENTS:
// 
// A concrete instance of a OPC Data Server cache.
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

//==============================================================================
// Local Declarations

// Start
bool CBHOpcDaCache::StartSample()
{
	COpcLock cLock(*this);

	bool bResult = true;

	TRY
	{
		// check if server is running.
		if (GetState() != OPC_STATUS_SUSPENDED)
		{
			THROW_(bResult, false);
		}

		// start the update thread.
		if (!COpcDaCache::Start())
		{
			SetState(OPC_STATUS_FAILED);
			GOTOFINALLY();
		}

		// construct configuration file name.
		COpcString cFileName;

		cFileName += OpcDaGetModulePath();
		cFileName += _T("\\");
		cFileName += OpcDaGetModuleName();
		cFileName += _T(".config.xml");

		// load the configuration file.
		if (!COpcDaCache::Load(cFileName))
		{
			SetState(OPC_STATUS_NOCONFIG);
			GOTOFINALLY();
		}

		// startup complete.
		SetState(OPC_STATUS_RUNNING);
	}
	CATCH_FINALLY
	{
	}

	return bResult;
}

// Stop
void CBHOpcDaCache::Stop()
{
	COpcLock cLock(*this);

	// stop device.
	m_oDevice.Stop();

	// stop update thread.
	COpcDaCache::Stop();

	// place in suspended state.
	SetState(OPC_STATUS_SUSPENDED);
}

// Load
bool CBHOpcDaCache::Load(COpcXmlElement& cRoot)
{
	COpcLock cLock(*this);

	// initialize device.
	if (!m_oDevice.Start(cRoot))
	{
		return false;
	}

	return true;
}


bool CBHOpcDaCache::Start()
{
	COpcLock cLock(*this);

	bool bResult = true;

	TRY
	{
		// check if server is running.
		if (GetState() != OPC_STATUS_SUSPENDED)
		{
			THROW_(bResult, false);
		}

		// start the update thread.
		if (!COpcDaCache::Start())
		{
			SetState(OPC_STATUS_FAILED);
			GOTOFINALLY();
		}

		// construct configuration file name.
		COpcString cFileName;

		cFileName += OpcDaGetModulePath();
		cFileName += _T("\\");
		cFileName += OpcDaGetModuleName();
		cFileName += _T(".realData.xml");

		//generate data
		if (!this->GenerateConfig(cFileName))
		{
			ASSERT(FALSE);
			THROW_(bResult, false);
		}

		// load the configuration file.
		if (!COpcDaCache::Load(cFileName))
		{
			SetState(OPC_STATUS_NOCONFIG);
			GOTOFINALLY();
		}

		// startup complete.
		SetState(OPC_STATUS_RUNNING);
	}
	CATCH_FINALLY
	{
	}

	return bResult;
}

#import "MSXML3.dll" named_guids

_bstr_t Format(MSXML2::IXMLDOMDocumentPtr doc)
{
	MSXML2::IMXWriterPtr writer;
	writer.CreateInstance(__uuidof(MSXML2::MXXMLWriter));
	writer->indent = VARIANT_TRUE;

	MSXML2::ISAXXMLReaderPtr reader;
	reader.CreateInstance(__uuidof(MSXML2::SAXXMLReader));

	MSXML2::ISAXContentHandlerPtr handler = writer;

	reader->putContentHandler(handler);
	reader->parse(doc.GetInterfacePtr());

	return writer->output;
}


bool CBHOpcDaCache::GenerateConfig(COpcString & arefStrFileName)
{

	//1. Read IniFile Setting
	COpcString cFileName;

	cFileName += OpcDaGetModulePath();
	cFileName += _T("\\");
	cFileName += OpcDaGetModuleName();
	cFileName += _T(".ini");


	CString lstrIP;
	CBHOpcDaDevice::SERVER_TYPE lnServerType = CBHOpcDaDevice::ON_LINE ;//0 : online 1: offline 
	int lnPort = 7001;

	//ip
	std::vector<TCHAR> loBuffer(1024);
	::GetPrivateProfileString(	_T("System"),
								_T("ip"),
								_T(""),
								&loBuffer.front(),
								loBuffer.size(),
								cFileName);
	 lstrIP= &loBuffer.front();

	 lstrIP = lstrIP.Trim();

	 if (lstrIP.GetLength()==0)
	 {
		 ASSERT(FALSE);
		 return false;
	 }

	//port
	 lnPort = ::GetPrivateProfileInt( _T("System"),
									  _T("port"),
									  7001,
									  cFileName);
								

	 if( lnPort<=0 || lnPort >=65534)
	 {
		 ASSERT(FALSE);
		 return false;
	 }

	//type
	lnServerType = (CBHOpcDaDevice::SERVER_TYPE)::GetPrivateProfileInt(	 _T("System"),
																		 _T("type"),
																		 CBHOpcDaDevice::ON_LINE,
																		 cFileName);


	//username
	CString lstrUserName;
	::GetPrivateProfileString(	_T("System"),
											_T("username"),
											_T(""),
											lstrUserName.GetBuffer(1024),
											1024,
											cFileName);

	lstrUserName.ReleaseBuffer();
	//password
	//username
	CString password;
	::GetPrivateProfileString(	_T("System"),
								_T("password"),
								_T(""),
								password.GetBuffer(1024),
								1024,
								cFileName);

	password.ReleaseBuffer();


	if (lnServerType>= CBHOpcDaDevice::SERVER_TYPE_MAX_VALUE)
	{
		ASSERT(FALSE);
		lnServerType = CBHOpcDaDevice::ON_LINE;
	}

	CString lstrAddress;
	lstrAddress.Format(_T("%s,%d/TCP"),lstrIP,lnPort);

	this->m_oDevice.ServerType(lnServerType);
	this->m_oDevice.ServerAddress(lstrAddress.GetBuffer(0));
	this->m_oDevice.UserName(lstrUserName);
	this->m_oDevice.Password(password);

	
	//2.generate File
	//2.1 generate file by device
	COpcXmlDocument cConfigFile;
	if (this->m_oDevice.GenerateServerSetting(cConfigFile)<=0)
	{
		ASSERT(FALSE);
		return false;
	}

	COpcXmlElement loRootElement = cConfigFile.GetRoot();
	if (!loRootElement)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	//2.2 append vendor info,for web publish


	//2.3 format doc
	CComBSTR loXmlFormatted = Format((IXMLDOMDocument*)cConfigFile).GetBSTR();
	COpcXmlDocument cFormattedConfigFile;
	cFormattedConfigFile.LoadXml(loXmlFormatted.m_str);

	//3.save file
	if (cFormattedConfigFile.Save(arefStrFileName)<=0)
	{
		ASSERT(FALSE);
		return false;
	}

	return true;
}
