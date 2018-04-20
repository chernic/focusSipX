// dllmain.h : 模块类的声明。

class CATLTutorial2008Module : public CAtlDllModuleT< CATLTutorial2008Module >
{
public :
	DECLARE_LIBID(LIBID_ATLTutorial2008Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLTUTORIAL2008, "{E815A0DE-48C9-44A0-8011-35563256C6A3}")
};

extern class CATLTutorial2008Module _AtlModule;
