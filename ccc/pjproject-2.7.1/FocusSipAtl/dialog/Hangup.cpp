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
    if( !::IsWindow(pHangup->m_hWnd) ) {
        ATLASSERT( pHangup != NULL );
        pHangup->Create(NULL, rc);
    }
    if( pHangup != NULL && ::IsWindow(pHangup->m_hWnd) )
	{
        pHangup->MoveWindow(&rcH);
    }
}
//PSWITCHTOTHISWINDOW SwitchToThisWindow;
//HMODULE hUser32=GetModuleHandle(_T("user32"));
//SwitchToThisWindow=(PSWITCHTOTHISWINDOW)GetProcAddress(hUser32,"SwitchToThisWindow");
////现在就可以使用此函数了
//SwitchToThisWindow(hwnd,FALSE);
//void CHangup::ShowHangupWindow(int IsShow)
//{
//	if( this == NULL || !::IsWindow(this->m_hWnd) )
//		return ;
//
//	if(IsShow)
//	{
//		//显示窗口
//		::ShowWindow(this->m_hWnd, SW_NORMAL);
// 
//		//前端显示
//		::SetForegroundWindow(this->m_hWnd);
// 
//		//窗口置顶
//		::SetWindowPos(this->m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
//	}
//}
void CHangup::DestroyWindow(void)
{
    if( pHangup != NULL && ::IsWindow(pHangup->m_hWnd) )
	{
		::DestroyWindow(pHangup->m_hWnd);
	    pHangup  = NULL;
	}
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
//    return 0;
//}
////////////////////////////////////////////////////////////////////////////////////////
LRESULT CHangup::OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    pHangup->DestroyWindow();
    return 0;
}

LRESULT CHangup::OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    pHangup->DestroyWindow();
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
	pHangup->DestroyWindow();
	return 0;
}
