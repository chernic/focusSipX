// Hangup.h : CHangup 的声明

#pragma once

#include "resource.h"       // 主符号

#include <atlhost.h>

#include "define.h"
#include "settings.h"
#include "ManageWindows.h"

// CHangup

class CHangup : 
    public CAxDialogImpl<CHangup>
{
public:
    CHangup()
    {
    }

    ~CHangup()
    {
    }

    void SetHangupWindow(RECT rcC);
	void DestroyWindow(void);

    enum { IDD = IDD_HANGUP };

BEGIN_MSG_MAP(CHangup)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)

	MESSAGE_HANDLER(WM_LBUTTONDOWN,OnLButtonDown)
	MESSAGE_HANDLER(WM_MOUSEMOVE,OnMouseMove)
	MESSAGE_HANDLER(WM_MOUSEHOVER,OnMouseHover)
	MESSAGE_HANDLER(WM_MOUSELEAVE,OnMouseLeave)

    COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
    COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
	COMMAND_HANDLER(IDC_BUTTON_HANGUP, BN_CLICKED, OnBnClickedHangup)
	CHAIN_MSG_MAP(CAxDialogImpl<CHangup>)

    //MESSAGE_HANDLER(UM_CREATE_RINGING, OnCreateRinging)
END_MSG_MAP()

// 处理程序原型:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT OnInitDialog	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnMouseMove		(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);  
    LRESULT OnLButtonDown	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);  
    LRESULT OnMouseHover	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);  
    LRESULT OnMouseLeave	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);  

    LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnBnClickedHangup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};

#ifdef _GLOBAL_VIDEO
extern CHangup *pHangup;
#endif

