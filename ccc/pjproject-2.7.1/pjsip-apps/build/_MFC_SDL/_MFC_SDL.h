
// _MFC_SDL.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C_MFC_SDLApp:
// �йش����ʵ�֣������ _MFC_SDL.cpp
//

class C_MFC_SDLApp : public CWinAppEx
{
public:
	C_MFC_SDLApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C_MFC_SDLApp theApp;