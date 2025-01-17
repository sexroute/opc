//============================================================================
// TITLE: COpcBrowseElement.cpp
//
// CONTENTS:
// 
// A single element in the OPC server namespace.
//
// (c) Copyright 2002-2004 The OPC Foundation
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
// 2003/12/26 RSA   Moved from a DA specific class library.

#include "StdAfx.h"
#include "COpcBrowseElement.h"

//============================================================================
// Local Declarations

#define DEFAULT_SEPARATOR _T("/")

//============================================================================
// COpcBrowseElement

// Constructor
COpcBrowseElement::COpcBrowseElement(COpcBrowseElement* pParent) 
{ 
    Init(); 
    m_pParent = pParent;
}

// Init
void COpcBrowseElement::Init()
{
    m_pParent    = NULL;
    m_cItemID    = OPC_EMPTY_STRING;
    m_cName      = OPC_EMPTY_STRING;
    m_cSeparator = OPC_EMPTY_STRING;
}

// Clear
void COpcBrowseElement::Clear()
{
    while (m_cChildren.GetCount() > 0)
    {
        COpcBrowseElement* pNode = m_cChildren.RemoveHead();
        pNode->Clear();
        delete pNode;
    }

    m_cChildren.RemoveAll();

    Init();
}

// GetName
COpcString COpcBrowseElement::GetName() const
{
    return m_cName;
}

// GetItemID
COpcString COpcBrowseElement::GetItemID() const
{
    if (m_cItemID.IsEmpty())
    {
        COpcString cItemID;

        if (m_pParent != NULL)
        {
            cItemID += m_pParent->GetItemID();

            if (!cItemID.IsEmpty())
            {
                cItemID += m_pParent->GetSeparator();
            }
        }

        cItemID += m_cName;

        return cItemID;
    }

    return m_cItemID;
}

// GetBrowsePath
COpcString COpcBrowseElement::GetBrowsePath() const
{
    COpcString cPath;

    if (m_pParent != NULL)
    {
        cPath += m_pParent->GetBrowsePath();
        cPath += m_pParent->GetSeparator();
    }

    cPath += m_cName;

    return cPath;
}

// GetSeparator
COpcString COpcBrowseElement::GetSeparator() const
{
    // inheirit separator from parent if not provided.
    if (m_cSeparator.IsEmpty())
    {
        // use default separator if top level node.
        if (m_pParent == NULL)
        {
            return DEFAULT_SEPARATOR;
        }

        return m_pParent->GetSeparator();
    }

    return m_cSeparator;
}

// GetChild
COpcBrowseElement* COpcBrowseElement::GetChild(UINT uIndex) const
{
    if (uIndex > m_cChildren.GetCount())
    {
        return NULL;
    }

    OPC_POS pos = m_cChildren.GetHeadPosition();

    for (UINT ii = 0; pos != NULL; ii++)
    {
        COpcBrowseElement* pNode = m_cChildren.GetNext(pos);

        if (ii == uIndex)
        {
            return pNode;
        }
    }

    return NULL;
}
/*
// Browse
void COpcBrowseElement::Browse(
    OPCBROWSETYPE     eType, 
    const COpcString& cPath,
    COpcStringList&   cNodes
)
{
    if (eType != OPC_FLAT)
    {
        OPC_POS pos = m_cChildren.GetHeadPosition();

        while (pos != NULL)
        {
            COpcBrowseElement* pNode = m_cChildren.GetNext(pos);

            // add child to list.
            cNodes.AddTail(pNode->GetName());
        }
    }

    else
    {
        OPC_POS pos = m_cChildren.GetHeadPosition();

        while (pos != NULL)
        {
            COpcBrowseElement* pNode = m_cChildren.GetNext(pos);

            // add child to list.
            cNodes.AddTail(cPath + pNode->GetName());

            // recursively browse children.
            if (pNode->m_cChildren.GetCount() > 0)
            {
                pNode->Browse(eType, cPath + pNode->GetName() + GetSeparator(), cNodes);
            }
        }
    }
}
*/

// Find
COpcBrowseElement* COpcBrowseElement::Find(const COpcString& cPath)
{
    // remove leading separator - if it exists.
    COpcString cPrefix    = GetSeparator();
    COpcString cLocalPath = cPath;

    while (cLocalPath.Find(GetSeparator()) == 0)
    {
        cLocalPath = cLocalPath.SubStr(cPrefix.GetLength());
    }
    
    // recursively search children.
    OPC_POS pos = m_cChildren.GetHeadPosition();

    while (pos != NULL)
    {           
        COpcBrowseElement* pChild = m_cChildren.GetNext(pos);

        // check for a child with an exact name match.
        if (cLocalPath == pChild->m_cName)
        {
            return pChild;
        }

        // check if the path starts with the child name.
        COpcString cPrefix = pChild->m_cName + pChild->GetSeparator();

        // check for a child with an exact name match plus trailing separator.
        if (cLocalPath == cPrefix)
        {
            return pChild;
        }

        UINT uIndex = cLocalPath.Find(cPrefix);

        // search the child node if there is a match.
        if (uIndex == 0)
        {
            cLocalPath = cLocalPath.SubStr(cPrefix.GetLength());
            return pChild->Find(cLocalPath);
        }       
    }

    return NULL;
}

// CreateInstance
COpcBrowseElement* COpcBrowseElement::CreateInstance()
{
	return new COpcBrowseElement(this);
}

// Insert
COpcBrowseElement* COpcBrowseElement::Insert(const COpcString& cPath)
{   
    COpcString cName    = cPath;
    COpcString cSubPath = OPC_EMPTY_STRING;
    
    // check if multiple levels have been specified.
    do
    {
        UINT uIndex = cName.Find(GetSeparator());

        if (uIndex == -1)
        {
            break;
        }

        cSubPath = cName.SubStr(uIndex + GetSeparator().GetLength());
        cName    = cName.SubStr(0, uIndex);       
        
        if (!cName.IsEmpty())
        {
            break;
        }

        cName = cSubPath;
    }
    while (!cSubPath.IsEmpty());

    // invalid path specified.
    if (cName.IsEmpty())
    {
        return NULL;
    }

    // find out if node already exists.
    COpcBrowseElement* pNode = NULL;

    OPC_POS pos = m_cChildren.GetHeadPosition();

    while (pos != NULL)
    {
        pNode = m_cChildren.GetNext(pos);

        if (pNode->m_cName == cName)
        {
            // return existing node.
            if (cSubPath.IsEmpty())
            {
                return pNode;
            }

            // insert sub-path into existing node.
            return pNode->Insert(cSubPath);
        }
    }

    // create new node.
    pNode = CreateInstance();
    pNode->m_cName = cName;
    OPC_ASSERT(!pNode->m_cName.IsEmpty());
    
    COpcBrowseElement* pChild = pNode;
    
    if (!cSubPath.IsEmpty())
    {
        pChild = pNode->Insert(cSubPath);

        if (pChild == NULL)
        {
            delete pNode;
            return NULL;
        }
    }

    m_cChildren.AddTail(pNode);
    return pChild;
}

// Insert
COpcBrowseElement* COpcBrowseElement::Insert(const COpcString& cPath, const COpcString& cItemID)
{   
    COpcBrowseElement* pChild = Insert(cPath);

    if (pChild != NULL)
    {
        pChild->m_cItemID = cItemID;
    }

    return pChild;
}

// Remove
void COpcBrowseElement::Remove()
{
    // tell parent to destroy branch.
    if (m_pParent != NULL)
    {
        m_pParent->Remove(m_cName);
        return;
    }

    delete this;
}

// Remove
bool COpcBrowseElement::Remove(const COpcString& cName)
{
    // find child node.
    OPC_POS pos = m_cChildren.GetHeadPosition();

    while (pos != NULL)
    {
        COpcBrowseElement* pChild = m_cChildren[pos];

        // remove child node from list and delete it.
        if (pChild->GetName() == cName)
        {
            m_cChildren.RemoveAt(pos);

            pChild->Clear();
            delete pChild;
            
            return true;
        }

        m_cChildren.GetNext(pos);
    }

    return false;
}

// Browse
void COpcBrowseElement::Browse(
    const COpcString& cPath,
    bool              bFlat, 
    COpcStringList&   cNodes
)
{
    if (!bFlat)
    {
        OPC_POS pos = m_cChildren.GetHeadPosition();

        while (pos != NULL)
        {
            COpcBrowseElement* pNode = m_cChildren.GetNext(pos);

            // add child to list.
            cNodes.AddTail(pNode->GetName());
        }
    }

    else
    {
        OPC_POS pos = m_cChildren.GetHeadPosition();

        while (pos != NULL)
        {
            COpcBrowseElement* pNode = m_cChildren.GetNext(pos);

            // add child to list.
            cNodes.AddTail(cPath + pNode->GetName());

            // recursively browse children.
            if (pNode->m_cChildren.GetCount() > 0)
            {
                pNode->Browse(cPath + pNode->GetName() + GetSeparator(), bFlat, cNodes);
            }
        }
    }
}

