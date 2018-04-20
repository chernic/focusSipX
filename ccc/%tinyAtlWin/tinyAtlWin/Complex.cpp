// Preview.cpp : CComplex 的实现

#include "stdafx.h"
#include "Complex.h"

CComplex *pComplex;

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
        this->ShowWindow(SW_SHOW);
    }
}
void CComplex::DestroyWindow(void)
{
	if( ::IsWindow(this->m_hWnd) )
		::DestroyWindow(this->m_hWnd);
}





