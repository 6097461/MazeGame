// MazeGenDlg.h : header file
//

#if !defined(AFX_MAZEGENDLG_H__EBAF3C8E_F9B1_43C8_B9CE_B5FA8B645BF7__INCLUDED_)
#define AFX_MAZEGENDLG_H__EBAF3C8E_F9B1_43C8_B9CE_B5FA8B645BF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMazeGenDlg dialog

class CMazeGenDlg : public CDialog
{
// Construction
public:
	BOOL CantGoAnyWhere();
	void pop();
	void push(int x3,int y3);
	void MakeMaze();
	void DrawMaze();
	CMazeGenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMazeGenDlg)
	enum { IDD = IDD_MAZEGEN_DIALOG };
	int		m_COL;
	int		m_ROW;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeGenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMazeGenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMake();
	afx_msg void OnGo();
	afx_msg void OnChangeCol();
	afx_msg void OnChangeRow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZEGENDLG_H__EBAF3C8E_F9B1_43C8_B9CE_B5FA8B645BF7__INCLUDED_)
