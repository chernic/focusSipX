// noneWin.cpp : CnoneWin 的实现
#include "stdafx.h"
#include "noneWin.h"
#include "Complex.h"

// CnoneWin

STDMETHODIMP CnoneWin::showWin(BSTR* ret)
{
	// TODO: 在此添加实现代码
	if(!pComplex)
		pComplex = new CComplex();

	RECT rc = {0};
    rc.left		= 0;
    rc.top		= 0;
    rc.right	= 500;
    rc.bottom	= 500;

	pComplex->SetComplexWindow(rc);

	return S_OK;
}

STDMETHODIMP CnoneWin::hideWin(BSTR* ret)
{
	// TODO: 在此添加实现代码
	if(!pComplex)
		pComplex = new CComplex();

	pComplex->DestroyWindow();

	return S_OK;
}

