#include <afxwin.h>
class CMyMainWnd : public CFrameWnd{
public:
	CMyMainWnd(){ // �����������
		Create(NULL, L"My title");
	}
};
class CMyApp : public CWinApp{
public:
	CMyApp(){}; // �����������
	virtual BOOL InitInstance(){
		m_pMainWnd = new CMyMainWnd();
		m_pMainWnd->ShowWindow(SW_SHOW);
		return TRUE;
	}
};
CMyApp theApp;