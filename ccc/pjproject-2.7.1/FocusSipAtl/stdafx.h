// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ĳЩ CString ���캯��������ʽ��

#include <comsvcs.h>

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

// ABChernic
#define _WTL_NO_CSTRING
#include <atlstr.h>
#define _WTL_NO_WTYPES
#include <atltypes.h>
#include <atlfile.h>

using namespace ATL;

// ABChernic
#include <gdiplus.h> 
using namespace Gdiplus;

#ifndef ULONG_PTR
#define ULONG_PRT unsigned long*
#endif