// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__D1920725_3220_40F4_9B04_762A3AB60D6C__INCLUDED_)
#define AFX_STDAFX_H__D1920725_3220_40F4_9B04_762A3AB60D6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;

// Chernic
// #ifdef _DEBUG
// #include <atlbase.inl>
// #endif

#include <atlcom.h>

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS    // 某些 CString 构造函数将是显式的
#define _WTL_NO_CSTRING
#include <atlstr.h>
#define _WTL_NO_WTYPES
#include <atltypes.h>
#include <atlfile.h>
#include <comsvcs.h>

// 2017-12-12
// http://t.cn/RTtaJHD
//#ifndef _INC_WINDOWS
//#include <windows.h>
//#endif /* _INC_WINDOWS */


#include <gdiplus.h> 
using namespace Gdiplus;

#ifndef ULONG_PTR
#define ULONG_PRT unsigned long*
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__D1920725_3220_40F4_9B04_762A3AB60D6C__INCLUDED)
