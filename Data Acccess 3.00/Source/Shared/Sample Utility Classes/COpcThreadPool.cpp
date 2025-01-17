//==============================================================================
// TITLE: COpcThreadPool.cpp
//
// CONTENTS:
// 
// Manages a pool of threads that process queued messages.
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
// 2002/12/02 RSA   First release.
//

#include "StdAfx.h"
#include "COpcThreadPool.h"

//==============================================================================
// Local Declarations

static UINT g_uLastID = 0;

//==============================================================================
// Local Functions

static DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    ((COpcThreadPool*)lpParameter)->Run();
	return 0;
}

//==============================================================================
// COpcMessage

// Constructor
COpcMessage::COpcMessage(UINT uType, IOpcMessageCallback* ipCallback)
{
	m_uType = uType;
	m_uID   = (UINT)InterlockedIncrement((LONG*)&g_uLastID);

	m_ipCallback = NULL;

	if (ipCallback != NULL)
	{
		m_ipCallback = ipCallback;
		m_ipCallback->AddRef();
	}
}

// Copy Constructor
COpcMessage::COpcMessage(const COpcMessage& cMessage)
{
	m_uType      = cMessage.m_uType;
	m_uID        = cMessage.m_uID;
	m_ipCallback = cMessage.m_ipCallback;

	if (m_ipCallback != NULL)
	{
		m_ipCallback->AddRef();
	}
}

// Destructor
COpcMessage::~COpcMessage()
{
	if (m_ipCallback != NULL)
	{
		m_ipCallback->Release();
	}
}

//==============================================================================
// COpcThreadPool

// Constructor
COpcThreadPool::COpcThreadPool()
{
	m_hEvent          = NULL;
	m_uTotalThreads   = 0;
	m_uWaitingThreads = 0;
	m_uMinThreads     = 1;
	m_uMaxThreads     = 4;
}

// Destructor
COpcThreadPool::~COpcThreadPool()
{
	// check that stop was called prior to destruction.
	OPC_ASSERT(m_cQueue.GetCount() == 0);
}
    
// Start
bool COpcThreadPool::Start()
{
	COpcLock cLock(*this);

	if (m_hEvent != NULL)
	{
		Stop();
	}

	m_hEvent = CreateEvent(
		NULL,
		TRUE,
		FALSE,
		NULL
	);

	if (m_hEvent == NULL)
	{
		return false;
	}

	return true;
}

// Stop
void COpcThreadPool::Stop()
{
	COpcLock cLock(*this);

	// delete any remaining messages.
	while (m_cQueue.GetCount() > 0)
	{
		COpcMessage* pMessage = m_cQueue.RemoveHead();
		delete pMessage;
	}
	
	// close handle.
	CloseHandle(m_hEvent);
	m_hEvent = NULL;
}

// QueueMessage
bool COpcThreadPool::QueueMessage(COpcMessage* pMsg)
{
	COpcLock cLock(*this);

	// check for active queue.
	if (m_hEvent == NULL)
	{
		return false;
	}

	// add to queue.
	m_cQueue.AddTail(pMsg);

	// signal that the queue is not empty
	SetEvent(m_hEvent);

	// start a new thread if required.
	if (m_uWaitingThreads == 0 && m_uTotalThreads < m_uMaxThreads)
	{
		DWORD dwID = 0;

		HANDLE hThread = CreateThread(
			NULL,
			NULL,
			ThreadProc,
			(void*)this,
			NULL,
			&dwID);

		if (hThread == NULL)
		{
			return false;
		}

		CloseHandle(hThread);

		// increment thread count.
		m_uTotalThreads++;
	}

	return true;
}

// Run
void COpcThreadPool::Run()
{
	COpcLock cLock(*this);

	do
	{
		// increment waiting thread count.
		m_uWaitingThreads++;

		cLock.Unlock();

		// wait for message.
		DWORD dwResult = WaitForSingleObject(m_hEvent, INFINITE);

		cLock.Lock();		

		// decrement waiting thread count.
		m_uWaitingThreads--;

		// check for error or shutdown event.
		if (m_hEvent == NULL || dwResult != WAIT_OBJECT_0)
		{
			break;
		}

		// check if the queue has already been cleared.
		if (m_cQueue.GetCount() == 0)
		{
			ResetEvent(m_hEvent);

			if (m_uWaitingThreads >= m_uMinThreads)
			{
				break;
			}

			continue;
		}

		// get next message.
		COpcMessage* pMessage = m_cQueue.RemoveHead();

		// release queue lock - process message could hang.
		cLock.Unlock();

		// process message.
		pMessage->Process();
		delete pMessage;

		// re-acquire lock.
		cLock.Lock();
	}
	while (m_uWaitingThreads < m_uMinThreads);

	// decrement thread count.
	m_uTotalThreads--;
}

// SetSize
void COpcThreadPool::SetSize(UINT uMinThreads, UINT uMaxThreads)
{
	COpcLock cLock(*this);

	m_uMinThreads = uMinThreads;
	m_uMaxThreads = uMaxThreads;
}