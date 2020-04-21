//============================================================================
// TITLE: COpcDaDevice.h
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

#ifndef _COpcDaDevice_H_
#define _COpcDaDevice_H_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "COpcThread.h"
#include "CBHOpcDaDeviceItem.h"
#include "COpcDaCache.h"
#include "COpcDaTypeDictionary.h"

//============================================================================
// CLASS:   COpcDaDevice
// PURPOSE: Simulates an I/O device.
typedef struct _FEATURE_INFO
{
	CString m_strGroup;
	CString m_strCompany;
	CString m_strFactory;
	CString m_strSet;
	CString m_strPlant;
	CString m_strChannel;
	CString m_strFeatureInfo;

}FEATURE_INFO;


typedef struct _CHANNEL_INFO
{
	CString m_strGroup;
	CString m_strCompany;
	CString m_strFactory;
	CString m_strSet;
	CString m_strPlant;
	CString m_strChannel;
	OpcXml::AnyType m_cValue;
	FEATURE_INFO m_oFeature_Info;
} CHANNEL_INFO,*P_CHANNEL_INFO;

typedef std::map<CString,CHANNEL_INFO> CHANNEL_POOL;
typedef std::map<CString,P_CHANNEL_INFO> G_CHANNEL_POOL;

typedef struct _PLANT_INFO
{
	CString m_strGroup;
	CString m_strCompany;
	CString m_strFactory;
	CString m_strSet;
	CString m_strPlant;
	CHANNEL_POOL m_oChannel_Info;
} PLANT_INFO,*P_PLANT_INFO;

typedef std::map<CString,PLANT_INFO> PLANT_POOL;




class CBHOpcDaDevice : 
	public IOpcXmlSerialize, 
	public IOpcDaDevice,
    public COpcSynchObject
{
    OPC_CLASS_NEW_DELETE()

public:

	enum SERVER_TYPE
	{
		OFF_LINE  = 0,  //offline
		ON_LINE   = 1,  //online 
		SERVER_TYPE_MAX_VALUE = 2,   //maxValue
	};
    //========================================================================
    // Public Operators

    // Constructor
    CBHOpcDaDevice() { Init(); }

    // Destructor
    ~CBHOpcDaDevice() { Clear(); }

    //========================================================================
    // Public Methods

    // Start
    bool Start();
    bool Start(COpcXmlElement& cElement);

    // Stop
    void Stop();

	// Update
	void Update();

    //========================================================================
    // IOpcDaDevice

	// BuildAddressSpace
	virtual bool BuildAddressSpace();

	// ClearAddressSpace
	virtual void ClearAddressSpace();

	// IsKnownItem
	virtual bool IsKnownItem(const COpcString& cItemID);

	// GetAvailableProperties
    virtual HRESULT GetAvailableProperties(
        const COpcString&   cItemID, 
		bool                bReturnValues,
		COpcDaPropertyList& cProperties);

	// GetAvailableProperties
    virtual HRESULT GetAvailableProperties(
        const COpcString&      cItemID, 
		const COpcList<DWORD>& cIDs,
		bool                   bReturnValues,
		COpcDaPropertyList&    cProperties);

	// Read
	virtual HRESULT Read(
        const COpcString& cItemID, 
        DWORD             dwPropertyID,
        VARIANT&          cValue, 
        FILETIME*         pftTimestamp = NULL,
        WORD*             pwQuality = NULL);

	// Write
	virtual HRESULT Write(
        const COpcString& cItemID, 
        DWORD             dwPropertyID,
        const VARIANT&    cValue, 
        FILETIME*         pftTimestamp = NULL,
        WORD*             pwQuality = NULL);

    //========================================================================
    // IOpcXmlSerialize
    
    // Init
    virtual void Init();

    // Clear
    virtual void Clear();

    // Read
    virtual bool Read(COpcXmlElement& cElement);

    // Write
    virtual bool Write(COpcXmlElement& cElement);

	// Server Type
	virtual CBHOpcDaDevice::SERVER_TYPE ServerType() const;
	virtual void ServerType(CBHOpcDaDevice::SERVER_TYPE val);

	// Server Ip
	virtual CString ServerAddress() const;
	virtual void ServerAddress(CString val);

	//GenerateServerSetting
	virtual bool GenerateServerSetting(COpcXmlDocument& cFile);

	virtual BOOL GetCommunication(  CComPtr<ICBHFixComImp> & arefFixCom,
									CBHOpcDaDevice::SERVER_TYPE anType);

	virtual BOOL Link(  ICBHFixComImp & arefFixCom,
						CString & astrAddress);

	virtual BOOL IsRealSample() const;
	virtual void IsRealSample(BOOL val);


	CString UserName() const { return m_strUserName; }
	void UserName(CString val) { m_strUserName = val; }

	CString Password() const { return m_strPassword; }
	void Password(CString val) { m_strPassword = val; }

protected:

    //========================================================================
    // Protected Methods

	// GetDeviceItem
	CBHOpcDaDeviceItem* GetDeviceItem(const COpcString& cItemID);

private:

    //========================================================================
    // Private Methods

	// Read
	bool Read(const COpcString& cElementPath, COpcXmlElement& cElement);
	
	// ParseItemID
	CBHOpcDaDeviceItem* ParseItemID(const COpcString& cItemID, COpcString& cItemPath);

	//generate online setting file
	bool GenerateOnlineSettingFile(COpcXmlDocument& cFile);

	//generate offline setting file
	bool GenerateOfflineSettingFile(COpcXmlDocument& cFile);

	void GenerateHierarchy(COpcXmlDocument& cFile);
	
	static BOOL GenerateRealSampleFile( COpcXmlDocument& cFile, 
										CString & astrFileAddress, 
										int  anType,
										CString & astrUserName,
										CString & astrPassword);
	

	BOOL UpdateFromBHDevice();

	//generate BH ItemBuffer
	bool BuildBHItemAddress();

/*
	bool GetAllChannels(ICBHFixComImp & arefFixComm,);
*/

    //========================================================================
    // Private Members

	CBHOpcDaDeviceItemMap               m_cItems;
	COpcStringList                      m_cItemList;
	COpcMap<COpcString,COpcStringList*> m_cBranches;
	COpcThread                          m_cThread;
	COpcDaTypeDictionaryMap             m_cDictionaries;
	SERVER_TYPE							m_nServerType;
	CString								m_strServerAddress;
	PLANT_POOL							m_oPlantInfoPool;
	G_CHANNEL_POOL						m_oTotalChannelInfoPool;
	COpcCriticalSection					m_oPlantInfoLock;
	BOOL								m_bRealSample;
	CComPtr<ICBHFixComImp>				m_oFixComUpdater;
	CString								m_strUserName;
	CString								m_strPassword;


};

HINSTANCE CreateInstanceFromDll( LPCTSTR lpDllName, REFCLSID rclsid, REFIID riid, LPVOID * ppv );



	
#endif // _COpcDaDevice_H_
