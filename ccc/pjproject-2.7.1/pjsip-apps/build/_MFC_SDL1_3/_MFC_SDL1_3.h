
// _MFC_SDL1_3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C_MFC_SDL1_3App:
// �йش����ʵ�֣������ _MFC_SDL1_3.cpp
//

class C_MFC_SDL1_3App : public CWinAppEx
{
public:
	C_MFC_SDL1_3App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C_MFC_SDL1_3App theApp;