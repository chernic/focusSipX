// glog_atl_test.cpp : WinMain µÄÊµÏÖ


#include "stdafx.h"
#include "resource.h"
#include "glog_atl_test_i.h"


class Cglog_atl_testModule : public CAtlExeModuleT< Cglog_atl_testModule >
{
public :
	DECLARE_LIBID(LIBID_glog_atl_testLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_GLOG_ATL_TEST, "{44602BCF-7969-4A64-946C-21681059B839}")
};

Cglog_atl_testModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}

