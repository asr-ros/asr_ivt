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

#ifndef _EXTRINSIC_PARAMETER_CALCULATOR_CV_H_
#define _EXTRINSIC_PARAMETER_CALCULATOR_CV_H_

#include "opencv/cv.h"
// ****************************************************************************
// Forward declarations
// ****************************************************************************

class CCalibration;
class CByteImage;
struct Mat3d;
struct Vec3d;
struct Vec2d;



// ****************************************************************************
// ExtrinsicParameterCalculatorCV
// ****************************************************************************

namespace ExtrinsicParameterCalculatorCV
{
	bool GetPointsAndTranslationAndRotation(const CCalibration *pCalibration,
		const CByteImage *pImage, int nColumns, int nRows, float fSquareSize, // input
		Vec2d *pPoints, Mat3d &rotation, Vec3d &translation); // output
		
	void DrawExtrinsic(CByteImage *pResultImage, const CCalibration *pCalibration, const Vec2d *pPoints, int nPoints, float fSquareSize);
}



#endif /* _EXTRINSIC_PARAMETER_CALCULATOR_CV_H_ */

