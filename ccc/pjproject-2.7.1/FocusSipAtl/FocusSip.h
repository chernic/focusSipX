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
//#include "FocusSip_CP.h"
#include "fs_managewindows.h"


// ABChernic : OCX控件避免弹出安全警告的类  http://t.cn/8FYr3t9
#include <objsafe.h>
#include "_IVideoAgentEvents_CP.H"

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
  public IObjectSafetyImpl<CFocusSip, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
  public IConnectionPointContainerImpl<CFocusSip>
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
  COM_INTERFACE_ENTRY(IConnectionPointContainer)
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
    ////////////////////////////////////////////////////
    //// 0000000-0000000-0000000
    // 001
    STDMETHOD(aboutbox)(
        /* [retval][out] */ Fs__Str                 *ret);
    // 002
    STDMETHOD(app_construct)(
        /* [retval][out] */ Fs_Stat                 *retStatus);
    // 003
    STDMETHOD(app_destroy)(
        /* [retval][out] */ Fs_Stat                 *retStatus);

    // 004
    STDMETHOD(app_create)(
        /* [retval][out] */ Fs_Stat                 *retStatus);
    // 005
    STDMETHOD(app_init)(
        /* [retval][out] */ Fs_Stat                 *retStatus);
    // 006
    STDMETHOD(app_start)(
        /* [retval][out] */ Fs_Stat                 *retStatus);

    // 007
    STDMETHOD(app_default_config)(
        /* [retval][out] */ Fs_Stat                 *retStatus);
    // 008
    STDMETHOD(app_test_config)(
        /* [retval][out] */ Fs_Stat                 *retStatus);


    ////////////////////////////////////////////////////
    //// 1111111-1111111-1111111
    //// 101
    STDMETHOD(acc_get_count)(
        /* [retval][out] */ Fs_Numb                 *pCount);
    //// 102
    STDMETHOD(acc_get_info)(
        /* [in] */          Fs_Numb                 accIndex, 
        /* [out] */         Focusip_Acc_Info        *pInfo, 
        /* [retval][out] */ Fs_Stat                 *retStatus);
    //// 105
    STDMETHOD(acc_set_online_status)(
        /* [in] */          Fs_Numb                 accIndex,
        /* [in] */          Fs_Bool                 isOnline,
        /* [out] */         Fs_Stat                 *retStatus);
    //// 106
    STDMETHOD(acc_set_registration)(
        /* [in] */          Fs_Numb                 accIndex,
        /* [in] */          Fs_Bool                 regActive,
        /* [retval][out] */ Fs_Stat                 *retStatus);
    //// 103
    STDMETHOD(acc_add_short)(
        /* [in] */          Focusip_Acc_Config      *pAccConfig, 
        /* [retval][out] */ Fs_Stat                 *retStatus);
    //// 104
    STDMETHOD(acc_add)(
        /* [in] */        //Fs_Numb                 _00accountId,
        /* [in] */          Fs__Str                 _01label,
        /* [in] */          Fs__Str                 _02server,
        /* [in] */          Fs__Str                 _03proxy,
        /* [in] */          Fs__Str                 _04username,
        /* [in] */          Fs__Str                 _05domain,
        /* [in] */          Fs_Numb                 _06port,
        /* [in] */          Fs__Str                 _07authID,
        /* [in] */          Fs__Str                 _08password,
        /* [in] */          Fs_Numb                 _09rememberPassword,
        /* [in] */          Fs__Str                 _10displayName,
        /* [in] */          Fs__Str                 _11voicemailNumber,
        /* [in] */          Fs__Str                 _12srtp,
        /* [in] */          Fs__Str                 _13transport,
        /* [in] */          Fs__Str                 _14publicAddr,
        /* [in] */          Fs_Numb                 _15publish,
        /* [in] */          Fs_Numb                 _16ice,
        /* [in] */          Fs_Numb                 _17allowRewrite,
        /* [in] */          Fs_Numb                 _18disableSessionTimer,
        /* [out] */         Fs_Stat                 *retStatus,
        /* [retval][out] */ Fs_Numb                 *pAcc_Index);
    //// 106
    STDMETHOD(acc_del)(
        /* [in] */          Fs_Numb                 accIndex, 
        /* [retval][out] */ Fs_Stat                 *retStatus);

    ////////////////////////////////////////////////////
    //// 2222222-2222222-2222222
    //// 201
    STDMETHOD(call_get_max_count)(
        /* [retval][out] */ Fs_Numb                 *retCount);
    //// 202
    STDMETHOD(call_get_count)(
        /* [retval][out] */ Fs_Numb                 *retCount);

    //// 203(via pjsua OK)
    STDMETHOD(call_is_active)(
        /* [in] */          Fs_Numb                 callIndex,
        /* [retval][out] */ Fs_Bool                 *pIsActive);
    //// 204(via pjsua OK)
    STDMETHOD(call_has_media)(
        /* [in] */          Fs_Numb                 callIndex,
        /* [retval][out] */ Fs_Bool                 *retHasMedia);
    //// 205
    STDMETHOD(call_get_info)(
        /* [in] */          Fs_Numb                 callIndex,
        /* [out] */         Focusip_Call_Info       *pInfo, 
        /* [retval][out] */ Fs_Stat                 *retStatus);

    //// 211
    STDMETHOD(call_make_call_short)(
        /* [in] */          Fs__Str                 Uri,
        /* [in] */          Fs_Bool                 hasVideo,
        /* [retval][out] */ Fs_Numb                 *RetCallID);
    //// 212
    STDMETHOD(call_make_call)(
        /* [in] */          Fs__Str                 _1callIndex,
        /* [in] */          Fs__Str                 _2numb,
        /* [in] */          Fs__Str                 _3number,
        /* [in] */          Fs__Str                 _4Para,
        /* [in] */          Fs__Str                 _5name,
        /* [in] */          Fs_Bool                 hasVideo,
        /* [retval][out] */ Fs_Numb                 *RetCallID);

    // 213
    STDMETHOD(call_answer)(
        /* [in] */          Fs_Numb                 callIndex,
        /* [in] */          Fs_Numb                 status_code,
        /* [retval][out] */ Fs_Stat                 *retStatus);
    // 214
    STDMETHOD(call_hangup)(
        /* [in] */          Fs_Numb                 callIndex,
        /* [in] */          Fs_Numb                 code,
        /* [in] */          Fs__Str                 reason,
        /* [retval][out] */ Fs_Stat                 *retStatus);
    // 215
    STDMETHOD(call_hangup_all)(void);

    // 216
    STDMETHOD(call_set_hold)(
        /* [in] */          Fs_Numb                 callIndex,
        /* [retval][out] */ Fs_Stat                 *retStatus);
    // 217
    STDMETHOD(call_release_hold)(
        /* [in] */          Fs_Numb                 callIndex,
        /* [retval][out] */ Fs_Stat                 *retStatus);

    // 301
    STDMETHOD(vid_win_set_overlay_mode)(
        /* [in] */          Fs_Numb                 mode,
        /* [retval][out] */ Fs_Stat                 *retStatus);
    // 303
    STDMETHOD(vid_win_resize)(
        /* [in] */          Fs_Doub                 present,
        /* [retval][out] */ Fs_Stat                 *retStatus);
	BEGIN_CONNECTION_POINT_MAP(CFocusSip)
		CONNECTION_POINT_ENTRY(__uuidof(_IVideoAgentEvents))
	END_CONNECTION_POINT_MAP()
};

OBJECT_ENTRY_AUTO(__uuidof(FocusSip), CFocusSip)
