// Hangup.cpp : CHangup ��ʵ��

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
    return 1;  // ʹϵͳ���ý���
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
////���ھͿ���ʹ�ô˺�����
//SwitchToThisWindow(hwnd,FALSE);
int CHangup::ShowHangupWindow(int IsShow)
{
	if( this == NULL || !::IsWindow(this->m_hWnd) )
		return -1;

	if(IsShow)
	{
		//��ʾ����
		::ShowWindow(this->m_hWnd, SW_NORMAL);
 
		//ǰ����ʾ
		::SetForegroundWindow(this->m_hWnd);
 
		//�����ö�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	call_hangup_all_noincoming();

	//CString *number  = new CString();
	//CString *message = new CString();
	//PostMessage(UM_CALL_HANGUP, (WPARAM)number, (LPARAM)message);

	pComplex->DestroyWindow();

	ResetPJmedia();

	//��������Լ�
	DestroyWindow();
	return 0;
}
