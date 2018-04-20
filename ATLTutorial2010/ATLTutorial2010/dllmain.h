// dllmain.h : 模块类的声明。

class CATLTutorial2010Module : public ATL::CAtlDllModuleT< CATLTutorial2010Module >
{
public :
	DECLARE_LIBID(LIBID_ATLTutorial2010Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLTUTORIAL2010, "{13AA1034-232B-4847-9929-2937346B1B31}")
};

extern class CATLTutorial2010Module _AtlModule;
