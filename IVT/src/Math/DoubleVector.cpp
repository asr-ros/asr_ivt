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
// Filename:  DoubleVector.cpp
// Author:    Pedram Azad
// Date:      30.05.2008
// ****************************************************************************


// ****************************************************************************
// Includes
// ****************************************************************************

#include <new> // for explicitly using correct new/delete operators on VC DSPs

#include "DoubleVector.h"



// ****************************************************************************
// Constructors / Destructor
// ****************************************************************************

CDoubleVector::CDoubleVector()
{
	dimension = 0;
	data = 0;
	m_bOwnMemory = false;
}

CDoubleVector::CDoubleVector(int nDimension, bool bHeaderOnly)
{
	dimension = nDimension;

	if (bHeaderOnly)
	{
		data = 0;
		m_bOwnMemory = false;
	}
	else
	{
        data = new double[dimension];
		m_bOwnMemory = true;
	}
}

CDoubleVector::CDoubleVector(const CDoubleVector &v, bool bHeaderOnly)
{
	dimension = v.dimension;
	
	if (bHeaderOnly)
	{
		data = 0;
		m_bOwnMemory = false;
	}
	else
	{
		data = new double[dimension];
		m_bOwnMemory = true;
	}
}

CDoubleVector::CDoubleVector(const CDoubleVector *pVector, bool bHeaderOnly)
{
	dimension = pVector->dimension;
	
	if (bHeaderOnly)
	{
		data = 0;
		m_bOwnMemory = false;
	}
	else
	{
		data = new double[dimension];
		m_bOwnMemory = true;
	}
}

CDoubleVector::~CDoubleVector()
{
    FreeMemory();
}


// ****************************************************************************
// Methods
// ****************************************************************************

void CDoubleVector::FreeMemory()
{
	if (data)
	{
		if (m_bOwnMemory)
            delete [] data;

		data = 0;
		m_bOwnMemory = false;
	}
}
