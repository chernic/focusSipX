// FocusSip.h : CFocusSip 的声明
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "resource.h"       // 主符号
#include <atlctl.h>
#include "FocusSipAtl_i.h"
// ABChernic
#include "global.h"
#include "define.h"
#include "settings.h"
#include "FocusSip_CP.h"
#include "ManageWindows.h"
#include "Complex.h"
#include "Hangup.h"

// ABChernic : OCX控件避免弹出安全警告的类  http://t.cn/8FYr3t9
#include <objsafe.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

// CFocusSip
class ATL_NO_VTABLE CFocusSip :
  public CComObjectRootEx<CComSingleThreadModel>,
  public IDispatchImpl<IFocusSip, &IID_IFocusSip, &LIBID_FocusSipAtlLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
  public IPersistStreamInitImpl<CFocusSip>,
  public IOleControlImpl<CFocusSip>,
  public IOleObjectImpl<CFocusSip>,
  public IOleInPlaceActiveObjectImpl<CFocusSip>,
  public IViewObjectExImpl<CFocusSip>,
  public IOleInPlaceObjectWindowlessImpl<CFocusSip>,
  public ISupportErrorInfo,
  public IPersistStorageImpl<CFocusSip>,
  public ISpecifyPropertyPagesImpl<CFocusSip>,
  public IQuickActivateImpl<CFocusSip>,
#ifndef _WIN32_WCE
  public IDataObjectImpl<CFocusSip>,
#endif
  public IProvideClassInfo2Impl<&CLSID_FocusSip, NULL, &LIBID_FocusSipAtlLib>,
#ifdef _WIN32_WCE // 要在 Windows CE 上正确加载该控件，要求 IObjectSafety
  public IObjectSafetyImpl<CFocusSip, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
#endif
  public CComCoClass<CFocusSip, &CLSID_FocusSip>,
  public CComControl<CFocusSip>,
  // ABChernic
  public CProxy_IVideoAgentEvents<CFocusSip>,
  /// http://t.cn/RTXGvei
  public IObjectSafetyImpl<CFocusSip, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:

  CFocusSip();

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
  OLEMISC_INVISIBLEATRUNTIME |
  OLEMISC_CANTLINKINSIDE |
  OLEMISC_INSIDEOUT |
  OLEMISC_ACTIVATEWHENVISIBLE |
  OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_FOCUSSIP)

// ABChernic : OCX控件避免弹出安全警告的类  http://t.cn/8FYr3t9
//DECLARE_INTERFACE_MAP()
//    BEGIN_INTERFACE_PART(ObjectSafety, IObjectSafety)
//        STDMETHOD(GetInterfaceSafetyOptions)(REFIID riid, DWORD __RPC_FAR *pdwSupportedOptions, DWORD __RPC_FAR *pdwEnabledOptions);
//        STDMETHOD(SetInterfaceSafetyOptions)(REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions);
//    END_INTERFACE_PART(ObjectSafety)

BEGIN_COM_MAP(CFocusSip)
  COM_INTERFACE_ENTRY(IFocusSip)
  COM_INTERFACE_ENTRY(IDispatch)
  COM_INTERFACE_ENTRY(IViewObjectEx)
  COM_INTERFACE_ENTRY(IViewObject2)
  COM_INTERFACE_ENTRY(IViewObject)
  COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
  COM_INTERFACE_ENTRY(IOleInPlaceObject)
  COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
  COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
  COM_INTERFACE_ENTRY(IOleControl)
  COM_INTERFACE_ENTRY(IOleObject)
  COM_INTERFACE_ENTRY(IPersistStreamInit)
  COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
  COM_INTERFACE_ENTRY(ISupportErrorInfo)
  COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
  COM_INTERFACE_ENTRY(IQuickActivate)
  COM_INTERFACE_ENTRY(IPersistStorage)
#ifndef _WIN32_WCE
  COM_INTERFACE_ENTRY(IDataObject)
#endif
  COM_INTERFACE_ENTRY(IProvideClassInfo)
  COM_INTERFACE_ENTRY(IProvideClassInfo2)
#ifdef _WIN32_WCE // 要在 Windows CE 上正确加载该控件，要求 IObjectSafety
  COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
#endif
  COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
END_COM_MAP()

BEGIN_PROP_MAP(CFocusSip)
  PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
  PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
  // 示例项
  // PROP_ENTRY_TYPE("属性名", dispid, clsid, vtType)
  // PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CFocusSip)
  CHAIN_MSG_MAP(CComControl<CFocusSip>)
  DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// 处理程序原型:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// ISupportsErrorInfo
  STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
  {
    static const IID* arr[] =
    {
      &IID_IFocusSip,
    };

    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
      if (InlineIsEqualGUID(*arr[i], riid))
        return S_OK;
    }
    return S_FALSE;
  }

// IViewObjectEx
  DECLARE_VIEW_STATUS(0)

// IFocusSip
public:
    HRESULT OnDraw(ATL_DRAWINFO& di)
    {
    RECT& rc = *(RECT*)di.prcBounds;
    // 将剪辑区域设置为 di.prcBounds 指定的矩形
    HRGN hRgnOld = NULL;
    if (GetClipRgn(di.hdcDraw, hRgnOld) != 1)
      hRgnOld = NULL;
    bool bSelectOldRgn = false;

    HRGN hRgnNew = CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);

    if (hRgnNew != NULL)
    {
      bSelectOldRgn = (SelectClipRgn(di.hdcDraw, hRgnNew) != ERROR);
    }

    Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);
    SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
    LPCTSTR pszText = _T("ATL 8.0 : FocusSip");
#ifndef _WIN32_WCE
    TextOut(di.hdcDraw,
      (rc.left + rc.right) / 2,
      (rc.top + rc.bottom) / 2,
      pszText,
      lstrlen(pszText));
#else
    ExtTextOut(di.hdcDraw,
      (rc.left + rc.right) / 2,
      (rc.top + rc.bottom) / 2,
      ETO_OPAQUE,
      NULL,
      pszText,
      ATL::lstrlen(pszText),
      NULL);
#endif

    if (bSelectOldRgn)
      SelectClipRgn(di.hdcDraw, hRgnOld);

    return S_OK;
  }


  DECLARE_PROTECT_FINAL_CONSTRUCT()

  HRESULT FinalConstruct()
  {
    return S_OK;
  }

  void FinalRelease()
  {
  }
  // 1
  STDMETHOD(focusua_aboutbox)(
      /* [retval][out] */ Pj_Status* retStatus);
  // 2
  STDMETHOD(focusua_test_sdl)(
      /* [retval][out] */ Pj_Status* retStatus);
  // 3
  STDMETHOD(focusua_app_test_config)(
      /* [out] */ BSTR *retmsg);

  // 11
  STDMETHOD(focusua_init)(
      /* [retval][out] */ Pj_Status *retStatus);
  // 12
  STDMETHOD(focusua_idestroy)(
      /* [retval][out] */ Pj_Status *retStatus);
  // 13
  STDMETHOD(focusua_acc_add)(
      /* [in] */ BSTR AuthID, 
      /* [in] */ BSTR Password, 
      /* [in] */ BSTR Domain, 
      /* [in] */ BSTR Proxy,
      /* [retval][out] */ Pj_Status* retStatus);
  // 14
  STDMETHOD(focusua_account_add)( 
      /* [in] */ int  _00accountId,
      /* [in] */ BSTR _01label,
      /* [in] */ BSTR _02server,
      /* [in] */ BSTR _03proxy,
      /* [in] */ BSTR _04username,
      /* [in] */ BSTR _05domain,
      /* [in] */ int  _06port,
      /* [in] */ BSTR _07authID,
      /* [in] */ BSTR _08password,
      /* [in] */ int  _09rememberPassword,
      /* [in] */ BSTR _10displayName,
      /* [in] */ BSTR _11voicemailNumber,
      /* [in] */ BSTR _12srtp,
      /* [in] */ BSTR _13transport,
      /* [in] */ BSTR _14publicAddr,
      /* [in] */ int  _15publish,
      /* [in] */ int  _16ice,
      /* [in] */ int  _17allowRewrite,
      /* [in] */ int  _18disableSessionTimer,
      /* [out] */ int *pAcc_Index,
      /* [retval][out] */ Pj_Status *retStatus);
  //15
  STDMETHOD(focusua_make_call)( 
      /* [in] */ BSTR Uri,
      /* [in] */ int  hasVideo,
      /* [retval][out] */ Pj_Status *retStatus);
  //16
  STDMETHOD(focusua_call_make_call)( 
      /* [in] */  BSTR   Uri,
      /* [in] */  BSTR   Para,
      /* [in] */  BSTR   Name,
      /* [in] */  int    hasVideo,
      /* [out] */ BSTR * CallId,
      /* [retval][out] */ Pj_Status *retStatus);
};

OBJECT_ENTRY_AUTO(__uuidof(FocusSip), CFocusSip)
