// MazeGen.h : main header file for the MAZEGEN application
//

#if !defined(AFX_MAZEGEN_H__CD9F858C_C941_465F_91D9_51AC08A09015__INCLUDED_)
#define AFX_MAZEGEN_H__CD9F858C_C941_465F_91D9_51AC08A09015__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMazeGenApp:
// See MazeGen.cpp for the implementation of this class
//

class CMazeGenApp : public CWinApp
{
public:
	CMazeGenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeGenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMazeGenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZEGEN_H__CD9F858C_C941_465F_91D9_51AC08A09015__INCLUDED_)
