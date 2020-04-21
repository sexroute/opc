//==============================================================================
// TITLE: CXxxDaCache.h
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

#ifndef _COpcDaEngine_H_
#define _COpcDaEngine_H_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "COpcDaCache.h"
#include "CBHOpcDaDevice.h"

//==============================================================================
// CLASS:   COpcDaCache
// PURPOSE: A concrete instance of a OPC Data Server cache.

class CBHOpcDaCache : public COpcDaCache
{
    OPC_CLASS_NEW_DELETE()

public:

    //==========================================================================
    // Public Operators

    // Constructor
	CBHOpcDaCache(CBHOpcDaDevice& cDevice) : m_oDevice(cDevice) {}

    // Destructor 
	~CBHOpcDaCache() {}

	//=========================================================================
    // Public Methods

	// Start
	virtual bool Start();
	virtual bool StartSample();
	virtual bool GenerateConfig(COpcString & arefStrFileName);


	
	// Stop
	virtual void Stop();

	// Load
	virtual bool Load(COpcXmlElement& cRoot);

private:

    //==========================================================================
    // Private Members

	CBHOpcDaDevice& m_oDevice;
};

#endif // _COpcDaEngine_H_