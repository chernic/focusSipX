// Preview.h : CComplex ������
// ATL3.0�еĴ�����-�ͻ���ʹ��ATL����DUI��ܵ����
// http://blog.csdn.net/klarclm/article/details/7160982

#pragma once

#include "resource.h"       // ������

//#include <Windows.h>  
#include <string>
#include <atlhost.h>
#include "atlapp.h"
#include "atlmisc.h"
#include "atlframe.h"

#include "define.h"
#include "settings.h"
#include "ManageWindows.h"

// CComplex
class CComplex : 
    public CAxDialogImpl<CComplex>
{
public:
    CComplex()
    {
    }

    ~CComplex()
    {
    }
	void OnCreateRing(void);

    void SetComplexWindow(RECT rcC);
	void DestroyWindow(void);

    enum { IDD = IDD_COMPLEX };

BEGIN_MSG_MAP(CComplex) // ���ú�ʵ��ProcessWindowMessage���������Էַ���Ϣ
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	//MESSAGE_HANDLER(WM_PAINT,OnPaint)

	MESSAGE_HANDLER(WM_LBUTTONDOWN,OnLButtonDown)  
	MESSAGE_HANDLER(WM_MOUSEMOVE,OnMouseMove)  
	MESSAGE_HANDLER(WM_MOUSEHOVER,OnMouseHover)  
	MESSAGE_HANDLER(WM_MOUSELEAVE,OnMouseLeave)  

    COMMAND_HANDLER(IDOK,     BN_CLICKED, OnClickedOK)
    COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)

	CHAIN_MSG_MAP(CAxDialogImpl<CComplex>)
END_MSG_MAP()

// �������ԭ��:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnInitDialog	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnMouseMove		(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);  
    LRESULT OnLButtonDown	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);  
    LRESULT OnMouseHover	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);  
    LRESULT OnMouseLeave	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnHangup		(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
};

#ifdef _GLOBAL_VIDEO
extern CComplex *pComplex;
#endif

