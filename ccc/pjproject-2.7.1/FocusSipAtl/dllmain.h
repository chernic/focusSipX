// dllmain.h : 模块类的声明。

class CFocusSipAtlModule : public CAtlDllModuleT< CFocusSipAtlModule >
{
public :
	DECLARE_LIBID(LIBID_FocusSipAtlLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FOCUSSIPATL, "{B01F9C3F-C737-4808-B573-8F08A60456BE}")
};

extern class CFocusSipAtlModule _AtlModule;
