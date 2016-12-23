#include <afxwin.h>  
#include <afx.h>  
#include <string.h>  
#define _AFXDLL
CFont *m_pFont;
class CMainWin : public CFrameWnd  {
public:
	CMainWin();
	int i = 0;
	int nMouseX, nMouseY, nOldMouseX, nOldMouseY;
	char pszMouseStr[50];
	afx_msg void OnChar(UINT ch, UINT, UINT);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT flags, CPoint Loc);
	void SetClientFont(CString Typeface, int Size, BOOL Bold, BOOL Italic);
	DECLARE_MESSAGE_MAP()
};
class CApp : public CWinApp
{
public:
	BOOL InitInstance();
};

BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
CMainWin::CMainWin()
{
	nMouseX = nMouseY = nOldMouseX = nOldMouseY = 0;
	this->Create(0, L"Обработка сообщений");
}
BEGIN_MESSAGE_MAP
	(CMainWin /* класс */, CFrameWnd /* базовый класс */)
	ON_WM_CHAR()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

void CMainWin::SetClientFont(CString Typeface, int Size, BOOL Bold, BOOL Italic)
{
	CWindowDC winDC(this);
	// ??????, ??????? ???????? ? ????? ?????????? ?????
	int pixelsPerInch = winDC.GetDeviceCaps(LOGPIXELSY);
	// ?????? ?????? ? ???????? ?????? ???????? Size ???????
	int fontHeight = -MulDiv(Size, pixelsPerInch, 72);
	// ????????????? ???????? ???????? ??? ??????? CreateFont()

	int Weight = FW_NORMAL;
	if (Bold)
		Weight = FW_BOLD;
	// ??????? ?????????? ????????? ?????? -- ?????? ?????? 
	// ???????????????? ????? ??????? CreateFont().
	delete m_pFont;
	m_pFont = new CFont;
	m_pFont->CreateFont(fontHeight, 0, 0, 0, Weight, Italic, 0, 0,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, Typeface);
}
afx_msg void CMainWin::OnChar(UINT ch, UINT, UINT)
{
	switch (ch)
	{
	case '1':
		i = 1;
		OnPaint();
		break;
	case '2':
		i = 2;
		OnPaint();
		break;
	case '3':
		i = 3;
		OnPaint();
		break;
	case '4':
		i = 4;
		OnPaint();
		break;
	case '5':
		i = 5;
		OnPaint();
		break;
	case '6':
		i = 6;
		OnPaint();
		break;



	}

	this->InvalidateRect(0);
}
afx_msg void CMainWin::OnLButtonDown(UINT, CPoint loc)
{
	i = 7;
	nOldMouseX = nMouseX;
	nOldMouseY = nMouseY;
	strcpy_s(pszMouseStr, "Нажата левая кнопка");
	nMouseX = loc.x; nMouseY = loc.y;
	this->InvalidateRect(0);
}
afx_msg void CMainWin::OnPaint() {
	CPaintDC dc(this);
	if (i == 1)
	{
		CPen aPen;
		aPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		CPen* oldPen = dc.SelectObject(&aPen);//сохраняем старое перо											
		dc.Ellipse(650, 350, 700, 400);
		//возвращаем перо
		dc.SelectObject(oldPen);
	}
	if (i == 2)
	{
		CPen aPen;
		aPen.CreatePen(PS_SOLID, 2, RGB(255, 200, 50));
		CPen* oldPen = dc.SelectObject(&aPen);//сохраняем старое перо
		dc.Ellipse(600, 300, 750, 450);
		dc.SelectObject(oldPen);
	}

	if (i == 3)
	{
		CPen aPen;
		aPen.CreatePen(PS_SOLID, 2, RGB(0, 200, 50));
		CPen* oldPen = dc.SelectObject(&aPen);//сохраняем старое перо
		dc.Ellipse(550, 250, 800, 500);
		dc.SelectObject(oldPen);

	}


	if (i == 4)
	{
		CPen aPen;
		aPen.CreatePen(PS_SOLID, 2, RGB(100, 0, 200));
		CPen* oldPen = dc.SelectObject(&aPen);//сохраняем старое перо
		dc.Ellipse(500, 200, 850, 550);
		dc.SelectObject(oldPen);

	}
	if (i == 5)
	{
		CPen aPen;
		aPen.CreatePen(PS_SOLID, 2, RGB(100, 250, 200));
		CPen* oldPen = dc.SelectObject(&aPen);//сохраняем старое перо
		dc.Ellipse(450, 150, 900, 600);
		dc.SelectObject(oldPen);

	}
	if (i == 6)
	{
		CPen aPen;
		aPen.CreatePen(PS_SOLID, 2, RGB(200, 50, 250));
		CPen* oldPen = dc.SelectObject(&aPen);//сохраняем старое перо
		dc.Ellipse(400, 100, 950, 650);
		dc.SelectObject(oldPen);
	}
	if (i == 7)
	{
		for (int k = 10; k <= 115; k = k + 15)
		{
			this->SetClientFont("Arial", k, TRUE, FALSE);
			dc.SetTextColor(RGB(k + 100, 0, 0));
			dc.SelectObject(m_pFont);
			dc.TextOutW(0, 0, "Hello World");
			Sleep(2000);
		}
	}
}

CApp App;