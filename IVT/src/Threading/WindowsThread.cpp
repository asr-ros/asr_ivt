// ****************************************************************************
// This file is part of the Integrating Vision Toolkit (IVT).
//
// The IVT is maintained by the Karlsruhe Institute of Technology (KIT)
// (www.kit.edu) in cooperation with the company Keyetech (www.keyetech.de).
//
// Copyright (C) 2014 Karlsruhe Institute of Technology (KIT).
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the KIT nor the names of its contributors may be
//    used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE KIT AND CONTRIBUTORS “AS IS” AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE KIT OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ****************************************************************************
// ****************************************************************************
// Filename:  WindowsThread.cpp
// Author:    Pedram Azad
// Date:      2004
// ****************************************************************************


// ****************************************************************************
// Includes
// ****************************************************************************

#include <new> // for explicitly using correct new/delete operators on VC DSPs

#include "WindowsThread.h"

#include <windows.h>



// ****************************************************************************
// ThreadRoutine
// ****************************************************************************

unsigned long __stdcall ThreadRoutine(void *pParameter)
{
	const int nRet = ((CThreadBase *) pParameter)->_ThreadMethod();
	((CThreadBase *) pParameter)->m_bCompletelyDone = true;
	return (unsigned long) nRet;
}


// ****************************************************************************
// Constructor / Destructor
// ****************************************************************************

CWindowsThread::CWindowsThread()
{
	m_hThreadHandle = NULL;
	m_hFinishedEvent = NULL;
}

CWindowsThread::~CWindowsThread()
{
	Stop();
}


// ****************************************************************************
// Methods
// ****************************************************************************

void CWindowsThread::_Start()
{
	if (m_hThreadHandle)
		return;

	m_hThreadHandle = CreateThread(NULL, 0, ThreadRoutine, this, 0, NULL);
	m_hFinishedEvent = CreateEvent(0, FALSE, FALSE, 0);
}

void CWindowsThread::_Stop()
{
	if (!m_hThreadHandle)
		return;
	
	// wait and kill thread after timeout
	WaitForSingleObject(m_hFinishedEvent, m_nKillThreadTimeout);

	CloseHandle(m_hThreadHandle);
	CloseHandle(m_hFinishedEvent);

	m_hThreadHandle = NULL;
	m_hFinishedEvent = NULL;
}

void CWindowsThread::ThreadMethodFinished()
{
	if (m_hFinishedEvent)
		SetEvent(m_hFinishedEvent);
}
