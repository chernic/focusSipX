// Hangup.cpp : CHangup 的实现

#include "stdafx.h"
#include "Complex.h"
#include "Hangup.h"

#ifdef _GLOBAL_VIDEO
CHangup     *pHangup;
#endif

// CHangup
LRESULT CHangup::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    CAxDialogImpl<CHangup>::OnInitDialog(uMsg, wParam, lParam, bHandled);

    bHandled = TRUE;
    return 1;  // 使系统设置焦点
}

/////////////////////////////////////////////////////////////////////////////////
void CHangup::SetHangupWindow(RECT rcH)
{
    RECT rc = {0};
    if( !::IsWindow(this->m_hWnd) ) {
        ATLASSERT( this != NULL );
        this->Create(NULL, rc);
    }
    if( this != NULL && ::IsWindow(this->m_hWnd) ) {
        this->MoveWindow(&rcH);
        //this->ShowWindow(SW_SHOW);
    }
}
//PSWITCHTOTHISWINDOW SwitchToThisWindow;
//HMODULE hUser32=GetModuleHandle(_T("user32"));
//SwitchToThisWindow=(PSWITCHTOTHISWINDOW)GetProcAddress(hUser32,"SwitchToThisWindow");
////现在就可以使用此函数了
//SwitchToThisWindow(hwnd,FALSE);
int CHangup::ShowHangupWindow(int IsShow)
{
	if( this == NULL || !::IsWindow(this->m_hWnd) )
		return -1;

	if(IsShow)
	{
		//显示窗口
		::ShowWindow(this->m_hWnd, SW_NORMAL);
 
		//前端显示
		::SetForegroundWindow(this->m_hWnd);
 
		//窗口置顶
		::SetWindowPos(this->m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	}else
	{
		this->ShowWindow();
	}
	return 0;
}
BOOL CHangup::ShowWindow(void)
{
    if( this != NULL && ::IsWindow(this->m_hWnd) )
	{
		return ::ShowWindow(this->m_hWnd, SW_SHOW);
	}
	return -1;
}
BOOL CHangup::DestroyWindow(void)
{
	BOOL Ret = 0;
    if( this != NULL && ::IsWindow(this->m_hWnd) )
	{
		Ret = ::DestroyWindow(this->m_hWnd);
	    pHangup  = NULL;
	}
	return Ret;
}
/////////////////////////////////////////////////////////////////////////////////
LRESULT CHangup::OnLButtonDown	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0; 
}
LRESULT CHangup::OnMouseMove	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0; 
}
LRESULT CHangup::OnMouseHover	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0; 
}
LRESULT CHangup::OnMouseLeave	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0; 
}

//LRESULT CHangup::OnCreateRinging(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
//{
//	if(!pHangup)	
//		pHangup = new CHangup();
//	pHangup->ShowWindow(SW_SHOW);
//	//pHangup->ShowHangupWindow(SW_SHOW);
//
//    return 0;
//}
////////////////////////////////////////////////////////////////////////////////////////
LRESULT CHangup::OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    DestroyWindow();
    return 0;
}

LRESULT CHangup::OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    DestroyWindow();
    return 0;
}
LRESULT CHangup::OnBnClickedHangup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: 在此添加控件通知处理程序代码
	call_hangup_all_noincoming();

	//CString *number  = new CString();
	//CString *message = new CString();
	//PostMessage(UM_CALL_HANGUP, (WPARAM)number, (LPARAM)message);

	pComplex->DestroyWindow();

	ResetPJmedia();

	//最后销毁自己
	DestroyWindow();
	return 0;
}
