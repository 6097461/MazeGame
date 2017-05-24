// MazeGenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MazeGen.h"
#include "MazeGenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAXCOL 20
#define MAXROW 20

struct Stack {
	int x,y;
};


int Maze[MAXCOL][MAXROW][4], StackCount, rx,ry,m, COL, ROW, x1,y1,x2,y2,step,counter;
BOOL visited[MAXCOL][MAXROW],CantGo[4];
struct Stack St[MAXCOL*MAXROW], StartPoint, EndPoint;
char buffer[5];
/////////////////////////////////////////////////////////////////////////////
// CMazeGenDlg dialog

CMazeGenDlg::CMazeGenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMazeGenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMazeGenDlg)
	m_COL = 0;
	m_ROW = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMazeGenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMazeGenDlg)
	DDX_Text(pDX, IDC_COL, m_COL);
	DDX_Text(pDX, IDC_ROW, m_ROW);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMazeGenDlg, CDialog)
	//{{AFX_MSG_MAP(CMazeGenDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MAKE, OnMake)
	ON_BN_CLICKED(IDC_GO, OnGo)
	ON_EN_CHANGE(IDC_COL, OnChangeCol)
	ON_EN_CHANGE(IDC_ROW, OnChangeRow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeGenDlg message handlers


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMazeGenDlg::push(int x3, int y3)
{
	St[StackCount].x = x3;
	St[StackCount].y = y3;
}

void CMazeGenDlg::pop()
{
	rx = St[StackCount].x;
	ry = St[StackCount].y;
}

BOOL CMazeGenDlg::CantGoAnyWhere()
{
	if ((CantGo[0]==TRUE) && (CantGo[1]==TRUE) &&
		(CantGo[2]==TRUE) && (CantGo[3]==TRUE)) 
		return TRUE;
	else return FALSE;
}

void CMazeGenDlg::DrawMaze()
{
	CClientDC dc(this);
	int x3 = x1+COL*step+5; 
	int y3 = y1+ROW*step+5;
	dc.Rectangle(x1-5,y1-5,x2+5,y2+5);
	x3 = StartPoint.x*step+x1+2;
	y3 = StartPoint.y*step+y1+2;
	dc.TextOut(x3,y3,"S");
	
	x3 = EndPoint.x*step+x1+2;
	y3 = EndPoint.y*step+y1+2;
	dc.TextOut(x3,y3,"E");

	for (int i=0;i<COL;i++) {
		for (int j=0;j<ROW;j++) {
			for (int k=0;k<4;k++) {
				int x = x1 + i*step;
				int y = y1 + j*step;
				if (Maze[i][j][k] == 1) {
					switch(k) {
					case 0 : dc.MoveTo(x,y); dc.LineTo(x+step,y); break; // 위가로
					case 1 : dc.MoveTo(x+step,y); dc.LineTo(x+step,y+step); break; // 두번째세로
					case 2 : dc.MoveTo(x+step,y+step); dc.LineTo(x,y+step); break; // 아래가로
					case 3 : dc.MoveTo(x,y+step); dc.LineTo(x,y); break; // 첫번째세로
					}
				Sleep(2);
				}
			}
		}
	}
}

void CMazeGenDlg::MakeMaze()
{
	int r1x,r1y,r2,r3x, r3y, trx1,try1, tr2;
	BOOL stay=FALSE;
	for (int i=0;i<4;i++) CantGo[i]=FALSE;

	// srand(GetCurrentTime());
	r1x = rand() % COL; 
	r1y = rand() % ROW; // 처음시작셀
	rx = r1x; ry = r1y;
	push(rx,ry);
	StackCount++;
	StartPoint.x = rx;
	StartPoint.y = ry;
	m=1;
	int NoWhereToGo=0;

	do {
		stay = FALSE;
		r2 = rand() % 4; // 진행방향
        // if ((rx==trx1) && (ry==try1) && (tr2==r2)) {
		//	do {
		//		r2 = rand() % 4;
		//	} while (r2==tr2);
		//	StackCount++;
		// }
		// else if ((rx==trx1) && (ry==try1) && (tr2!=r2))
        // { StackCount++; }

		trx1 = rx; try1 = ry;
		switch(r2) {
		case 0 : r3x = rx; r3y = ry-1; if (r3y<0) { r3y=0; stay=TRUE; } break; // 위방향
		case 1 : r3x = rx+1; if (r3x==COL) { r3x=COL-1; stay = TRUE; } r3y = ry; break; // 오른쪽
		case 2 : r3x = rx; r3y = ry+1; if (r3y==ROW) { r3y = ROW-1; stay = TRUE; } break; // 아래쪽
		case 3 : r3x = rx-1; if (r3x<0) { r3x=0; stay = TRUE; } r3y = ry; break; // 왼쪽
		}

		if (((Maze[r3x][r3y][0]==1) && (Maze[r3x][r3y][1]==1) &&
			(Maze[r3x][r3y][2]==1) && (Maze[r3x][r3y][3]==1)) && (stay==FALSE))// 사면이 다 막혔으면
			{	
				Maze[rx][ry][r2] = 0;
				switch(r2) {
				case 0 : Maze[r3x][r3y][2]=0; break;
				case 1 : Maze[r3x][r3y][3]=0; break;
				case 2 : Maze[r3x][r3y][0]=0; break;
				case 3 : Maze[r3x][r3y][1]=0; break;
				}
				visited[r3x][r3y] = TRUE;
				push(r3x,r3y);
				StackCount++;
				rx = r3x; ry = r3y;
				m++; 
    	    	for (int i=0;i<4;i++) CantGo[i]=FALSE;
		}
		else { 
				CantGo[r2]=TRUE;
				BOOL CanGo = CantGoAnyWhere();
				if (CanGo) {
					for (int i=0;i<4;i++) { CantGo[i]=FALSE; }
					StackCount--; pop(); }
				
		    // 갈데가 없으면
		}
		tr2 = r2;
	} while (m<(COL*ROW));
	EndPoint.x = rx;
	EndPoint.y = ry;
	DrawMaze();
}

BOOL CMazeGenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	x1 = 20; y1= 50; x2 = 270; y2 = 300;
	COL = 5; ROW = COL;
	m_COL = COL;
	m_ROW = ROW;
	UpdateData(FALSE);
	step = (x2-x1) / ROW;
	for (int i=0;i<COL;i++)
		for (int j=0;j<ROW;j++)
		{
			visited[i][j] = FALSE;
			for (int k=0;k<4;k++)
				Maze[i][j][k] = 1;
		}// 초기에는 벽이 다 막혀있음
	StackCount = 0;
	counter = 1;
	for (i=0;i<4;i++) CantGo[i]=FALSE;
	// m_COL = COL; m_ROW = ROW; UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMazeGenDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	OnInitDialog();
	MakeMaze();

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMazeGenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CMazeGenDlg::OnMake() 
{
	// TODO: Add your control notification handler code here
	for (int i=0;i<COL;i++)
		for (int j=0;j<ROW;j++)
		{
			visited[i][j] = FALSE;
			for (int k=0;k<4;k++)
				Maze[i][j][k] = 1;
		}// 초기에는 벽이 다 막혀있음
	StackCount = 0;
	MakeMaze();	
}

void CMazeGenDlg::OnGo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	COL = m_COL; ROW = COL;
	if ((COL<5) || (COL>20)) {
		AfxMessageBox("미로크기는 5~20까지입니다!!");
		m_COL = 5; m_ROW = 5;
		UpdateData(FALSE);
	} else {
	step = (x2-x1) / ROW;
	for (int i=0;i<COL;i++)
		for (int j=0;j<ROW;j++)
		{
			visited[i][j] = FALSE;
			for (int k=0;k<4;k++)
				Maze[i][j][k] = 1;
		}// 초기에는 벽이 다 막혀있음
	StackCount = 0;
	MakeMaze();
	counter++;
	for (i=0;i<4;i++) CantGo[i]=FALSE;
	}
}

void CMazeGenDlg::OnChangeCol() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_ROW=GetDlgItemInt(IDC_COL);
	SetDlgItemInt(IDC_ROW,m_ROW,TRUE);
}

void CMazeGenDlg::OnChangeRow() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_COL=GetDlgItemInt(IDC_ROW);
	SetDlgItemInt(IDC_COL,m_COL,TRUE);
}	

