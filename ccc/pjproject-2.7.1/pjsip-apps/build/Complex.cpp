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

        // this->ShowWindow(SW_SHOW);
        //::ShowWindow(this->m_hWnd, SW_MAXIMIZE);
        // http://t.cn/R0SfXgP
    }
}
BOOL CComplex::ShowComplexWindow(int IsShow)
{
	if( this == NULL || !::IsWindow(this->m_hWnd) )
		return False;

	if(IsShow)
	{
		//显示窗口
		::ShowWindow(m_hWnd, SW_NORMAL);
 
		//前端显示
		::SetForegroundWindow(m_hWnd);
 
		//窗口置顶
		::SetWindowPos(m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
		return 0;
	}else
	{
		::ShowWindow(m_hWnd, SW_HIDE);
		return 0;
	}
}
BOOL CComplex::ShowWindow(void)
{
    if( this != NULL && ::IsWindow(this->m_hWnd) ) 
	{
		return ::ShowWindow(pComplex->m_hWnd, SW_SHOW);
	}
	return -1;
}
BOOL CComplex::DestroyWindow(void)
{
	BOOL Ret = 0;
    if( this != NULL && ::IsWindow(this->m_hWnd) )
	{
		Ret = ::DestroyWindow(this->m_hWnd);
	    pComplex  = NULL;
	}
	return Ret;
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
	pHangup->ShowWindow();
	ShowPreviwWindow(PJ_TRUE);
}





