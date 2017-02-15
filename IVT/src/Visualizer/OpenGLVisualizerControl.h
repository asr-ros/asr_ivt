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
// Filename:  OpenGLVisualizerControl.h
// Author:    Florian Hecht
// Date:      2009
// ****************************************************************************


#ifndef _OPENGL_VISUALIZER_CONTROL_H_
#define _OPENGL_VISUALIZER_CONTROL_H_


// ****************************************************************************
// Necessary includes
// ****************************************************************************

#include "Interfaces/MainWindowEventInterface.h"
#include "Math/Math3d.h"


// ****************************************************************************
// Forward declarations
// ****************************************************************************

class CMainWindowInterface;
class COpenGLVisualizer;



// ****************************************************************************
// COpenGLVisualizerControl
// ****************************************************************************

class COpenGLVisualizerControl : public CMainWindowEventInterface
{
public:
	// constructor
	COpenGLVisualizerControl(WIDGET_HANDLE widget, int width, int height, COpenGLVisualizer *visualizer, CMainWindowInterface *main_window, CMainWindowEventInterface *event_callback);
	

	// public methods
	void SetViewMatrix(const Transformation3d &transformation);
	const Transformation3d &GetViewMatrix();
	void ResetViewMatrix();
	
	void Update();
	
	// CMainWindowEventInterface
	
	// this two events are specific for the image widget
	void RectSelected(WIDGET_HANDLE widget, int x0, int y0, int x1, int y1);
	void PointClicked(WIDGET_HANDLE widget, int x, int y);
	
	// the following events are only generated for image and GL widgets
	void MouseDown(WIDGET_HANDLE widget, int button, int x, int y);
	void MouseUp(WIDGET_HANDLE widget, int button, int x, int y);
	void MouseMove(WIDGET_HANDLE widget, int x, int y);
	void KeyDown(WIDGET_HANDLE widget, int key);
	void KeyUp(WIDGET_HANDLE widget, int key);

	// this event is only emitted for buttons
	void ButtonPushed(WIDGET_HANDLE widget);

	// this event is generated by check boxes, sliders, text edits (value = -1)
	// and combo boxes
	void ValueChanged(WIDGET_HANDLE widget, int value);
	
	
private:
	WIDGET_HANDLE			m_widget;
	COpenGLVisualizer		*m_visualizer;
	CMainWindowInterface		*m_main_window;
	CMainWindowEventInterface	*m_event_callback;
	
	Transformation3d		m_ViewMatrix;
	
	int				m_width;
	int				m_height;
	
	int				m_mouse_mode;
	int				m_mouse_old_x;
	int				m_mouse_old_y;
};



#endif /* _OPENGL_VISUALIZER_CONTROL_H_ */
