// Preview.cpp : CComplex 的实现

#include "stdafx.h"
#include "Complex.h"
#include "Hangup.h"
#include <SDL.h>

#ifdef _GLOBAL_VIDEO
CComplex    *pComplex;
#endif

LRESULT CComplex::OnInitDialog	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    CAxDialogImpl<CComplex>::OnInitDialog(uMsg, wParam, lParam, bHandled);

    bHandled = TRUE;
    return 1;  // 使系统设置焦点
}
/////////////////////////////////////////////////////////////////////////////////
// CComplex
void CComplex::SetComplexWindow(RECT rcC)
{
    RECT rc = {0};
    if( !::IsWindow(this->m_hWnd) ) {
        ATLASSERT( this != NULL );
        this->Create(NULL, rc);
    }
    if( this != NULL && ::IsWindow(this->m_hWnd) ) {
        this->MoveWindow(&rcC);
        // http://blog.csdn.net/shanshangyouzhiyangm/article/details/51954472
    }
}
//void CComplex::ShowComplexWindow(int IsShow)
//{
//	if( this == NULL || !::IsWindow(this->m_hWnd) )
//		return;
//
//	if(IsShow)
//	{
//		//显示窗口
//		::ShowWindow(m_hWnd, SW_NORMAL);
// 
//		//前端显示
//		::SetForegroundWindow(m_hWnd);
// 
//		//窗口置顶
//		::SetWindowPos(m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
//	}
//}
void CComplex::DestroyWindow(void)
{
    if( pComplex != NULL && ::IsWindow(pComplex->m_hWnd) )
	{
		::DestroyWindow(pComplex->m_hWnd);
	    pComplex  = NULL;
	}
}
//void CComplex::_OnPaint(void)
//{
	//// 黑色画笔
	//HBRUSH  bg_black_brush_ = AtlGetStockBrush(BLACK_BRUSH);
	//   CPaintDC hdc(m_hWnd);  
	// 
	//   CRect client_rect;  
	//   GetClientRect(&client_rect);  
	// 
	//   CMemoryDC mdc(hdc,client_rect);  
	//   mdc.SetBkMode(TRANSPARENT);  
	//   Gdiplus::Graphics graphics(mdc);  
	// 
	//   mdc.FillRect(client_rect,bg_black_brush_);  
//}

LRESULT CComplex::OnLButtonDown	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	OnCreateRing();
	return 0; 
}
LRESULT CComplex::OnMouseMove	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0; 
}
LRESULT CComplex::OnMouseHover	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	OnCreateRing();
	return 0; 
}
LRESULT CComplex::OnMouseLeave	(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0; 
}

LRESULT CComplex::OnHangup		(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	DestroyWindow();
	return 0; 
}
LRESULT CComplex::OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    DestroyWindow();
    return 0;
}

LRESULT CComplex::OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{    
	DestroyWindow();
    return 0;
}
void CComplex::OnCreateRing(void)
{
	pHangup->ShowWindow(SW_SHOW);
	ShowPreviewWindow(PJ_TRUE);

	//CString *number  = new CString();
	//CString *message = new CString();
	//PostMessage(UM_CREATE_RINGING, (WPARAM)number, (LPARAM)message);
}





