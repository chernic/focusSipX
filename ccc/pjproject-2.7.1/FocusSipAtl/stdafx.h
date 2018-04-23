// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 某些 CString 构造函数将是显式的

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