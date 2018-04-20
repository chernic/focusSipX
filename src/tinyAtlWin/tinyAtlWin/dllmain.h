// dllmain.h : 模块类的声明。

class CtinyAtlWinModule : public CAtlDllModuleT< CtinyAtlWinModule >
{
public :
	DECLARE_LIBID(LIBID_tinyAtlWinLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TINYATLWIN, "{EA4942C3-B934-46E4-AB65-A802EDB51430}")
};

extern class CtinyAtlWinModule _AtlModule;
