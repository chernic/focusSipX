#include "stdafx.h"
#include "dh_window_bg_brush_helper.h"

DhWindowBgBrushHelper::DhWindowBgBrushHelper()
{
	
}

DhWindowBgBrushHelper::~DhWindowBgBrushHelper()
{
	std::map<HWND,HBRUSH>::iterator ite =  hbrush.begin();
	for(; ite != hbrush.end(); ++ite) 
	{
		ATLASSERT(ite->second != NULL);
		::DeleteObject(ite->second);
	}
	hbrush.clear();
}


void DhWindowBgBrushHelper::AddSubWindow(HWND hwnd,HBITMAP parent_background)
{
	CWindow child(hwnd);
	CWindow parent = child.GetParent();

	RECT rect;
	RECT parent_window_rect;
	RECT parent_client_rect;
	parent.GetWindowRect(&parent_window_rect);
	parent.GetClientRect(&parent_client_rect);

	child.GetWindowRect(&rect);
	parent.ScreenToClient(&rect);

	long width = rect.right - rect.left;
	long height = rect.bottom - rect.top;

	//CDC sdc; 
	//CDC ddc;
	//sdc.CreateCompatibleDC(NULL);
	//ddc.CreateCompatibleDC(NULL);
	//CBitmap destBmp;
	//destBmp.CreateCompatibleBitmap(CClientDC(NULL),width,height);
	//sdc.SelectBitmap(parent_background);
	//ddc.SelectBitmap(destBmp);
	//ddc.BitBlt(0, 0, width, height, sdc, rect.left, rect.top, SRCCOPY );

	//CBrush bs ;
	//bs.CreatePatternBrush(destBmp);
	//hbrush[hwnd] = bs;

	//bs.Detach();
}

HBRUSH DhWindowBgBrushHelper::GetHBRUSH(HWND hwnd)
{
	ATLASSERT(hwnd);

	if(hbrush.find(hwnd) != hbrush.end())
	{
		return hbrush[hwnd];
	}
	return NULL;
}