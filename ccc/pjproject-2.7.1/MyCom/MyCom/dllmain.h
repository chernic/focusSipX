// dllmain.h : 模块类的声明。

class CMyComModule : public CAtlDllModuleT< CMyComModule >
{
public :
	DECLARE_LIBID(LIBID_MyComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MYCOM, "{D97C0F32-403D-4F0E-BA48-EAE379B60EE3}")
};

extern class CMyComModule _AtlModule;
