
// _MFC_SDL1_3.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C_MFC_SDL1_3App:
// 有关此类的实现，请参阅 _MFC_SDL1_3.cpp
//

class C_MFC_SDL1_3App : public CWinAppEx
{
public:
	C_MFC_SDL1_3App();

// 重写
	public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C_MFC_SDL1_3App theApp;