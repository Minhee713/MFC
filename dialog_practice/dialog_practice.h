
// dialog_practice.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CdialogpracticeApp:
// See dialog_practice.cpp for the implementation of this class
//

class CdialogpracticeApp : public CWinApp
{
public:
	CdialogpracticeApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CdialogpracticeApp theApp;
