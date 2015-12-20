//	Добавить обработку нажатия на клавишу клавиатуры, при
//	которой выводятся прямоугольники слева направо, сверху
//	вниз.

#include <afxwin.h>
#include <string>

int i = 0, k = 0;
bool flag = 1;
CFont *m_pFont;

class CMainWin : public CFrameWnd
{
public:
	CMainWin();
	afx_msg void OnChar(UINT ch, UINT, UINT);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT flags, CPoint Loc);
	void SetClientFont(CString Typeface, int Size, BOOL Bold, BOOL Italic);
	char pszMouseStr[50];

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
	this->Create(0, L"Обработка сообщений");

}
BEGIN_MESSAGE_MAP
	(CMainWin, CFrameWnd)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

void CMainWin::SetClientFont(CString Typeface, int Size, BOOL Bold, BOOL Italic)
{
	// Получим контекст окна
	CWindowDC winDC(this);
	// Узнаем, сколько пикселей в одном логическом дюйме
	int pixelsPerInch = winDC.GetDeviceCaps(LOGPIXELSY);
	// Узнаем высоту в пикселях шрифта размером Size пунктов
	int fontHeight = -MulDiv(Size, pixelsPerInch, 72);
	// Устанавливаем параметр жирности для функции CreateFont()

	int Weight = FW_NORMAL;
	if (Bold)
		Weight = FW_BOLD;
	// Удаляем предыдущий экземпляр шрифта -- нельзя дважды 
	// инициализировать шрифт вызовом CreateFont().
	delete m_pFont;
	m_pFont = new CFont;
	// Создание шрифта. Большинство параметров не используются.
	m_pFont->CreateFont(fontHeight, 0, 0, 0, Weight, Italic, 0, 0,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, Typeface);
}

afx_msg void CMainWin::OnChar(UINT ch, UINT, UINT)
{
	flag = 0;
	if (ch == '1') {
		flag = 0;
		k = 1;
	}
	else if (ch == '2')
	{
		flag = 0;
		k = 2;
	}
	else if (ch == '3')
	{
		flag = 0;
		k = 3;
	}
	else if (ch == '4')
	{
		flag = 0;
		k = 4;
	}
	else if (ch == '5')
	{
		flag = 0;
		k = 5;
	}
	else if (ch == '6')
	{
		flag = 0;
		k = 6;
	}
	OnPaint();
	this->InvalidateRect(0);
}


afx_msg void CMainWin::OnLButtonDown
(UINT, CPoint loc)
{

	i++;
	if (i == 5)
	{
		i = 0;
	}
	flag = 1;
	OnPaint();
	this->InvalidateRect(0);
}

afx_msg void CMainWin::OnPaint()
{
	CPaintDC dc(this);

	if (flag == 1)
	{
		switch (i)
		{
		case 0:
		{
			dc.Rectangle(5, 5, 100, 100);
			this->SetClientFont("Veranda", 25, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 200, 100));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Rectangel");
		}break;

		case 1:
		{

			dc.Arc(10, 20, 100, 100, 40, 40, 50, 50);
			this->SetClientFont("Veranda", 25, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 200, 100));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Arc");
		}
		break;

		case 2:
		{
			dc.Ellipse(10, 10, 100, 150);
			this->SetClientFont("Veranda", 25, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 200, 100));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Elips");
		}
		break;

		case 3:
		{
			dc.Chord(10, 10, 200, 200, 240, 240, 50, 50);
			this->SetClientFont("Veranda", 25, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 200, 100));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Chord");
		}
		break;

		case 4:
		{
			dc.Pie(10, 10, 200, 200, 100, 100, 250, 250);
			this->SetClientFont("Veranda", 25, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 200, 100));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Pie");		}
		break;


		}
	}

	if (flag == 0)
	{
		switch (k){
		case 0:
		{
			this->SetClientFont("Arial", 20, TRUE, FALSE);
			dc.SetTextColor(RGB(255, 0, 0));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
			break;
		}

		case 1:
		{
			this->SetClientFont("Times new Roman", 40, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 255, 0));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
		}
		break;

		case 2:
		{
			this->SetClientFont("Veranda", 25, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 200, 100));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
		}
		break;

		case 3:
		{
			this->SetClientFont("Cambria", 30, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 0, 100));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
		}
		break;

		case 4:
		{
			this->SetClientFont("Batang", 8, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 100, 200));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
		}
		break;

		case 5:
		{
			this->SetClientFont("Tahoma", 15, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 0, 200));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
		}
		break;

		case 6:
		{
			this->SetClientFont("Elephant", 25, FALSE, FALSE);
			dc.SetTextColor(RGB(255, 100, 50));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
		}
		break;

		case 7:
		{
			this->SetClientFont("Miriam", 17, FALSE, FALSE);
			dc.SetTextColor(RGB(100, 25, 50));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
		}
		break;

		case 8:
		{
			this->SetClientFont("Wide Latin", 30, FALSE, FALSE);
			dc.SetTextColor(RGB(0, 255, 50));
			dc.SelectObject(m_pFont);
			dc.TextOutW(480, 200, "Hello");
		}

		}


	}

}
CApp App;


