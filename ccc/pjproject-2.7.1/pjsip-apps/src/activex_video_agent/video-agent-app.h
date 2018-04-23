// App.h : Declaration of the CApp

#ifndef __APP_H_
#define __APP_H_

#include "define.h"
#include "resource.h"       // main symbols
#include "settings.h"
#include "activex_video_agentCP.h"
#include "fs_managewindows.h"

#ifdef _GLOBAL_VIDEO
	extern RECT setRECT(LONG left, LONG top, LONG right, LONG bottom);
#endif
	static void on_call_media_state(pjsua_call_id call_id);

/////////////////////////////////////////////////////////////////////////////
// CApp
class ATL_NO_VTABLE CApp :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CApp, &CLSID_App>,
    public IConnectionPointContainerImpl<CApp>,
    public IDispatchImpl<IApp, &IID_IApp, &LIBID_ACTIVEVIDEOAGENTLib>,
    public CProxy_IVideoAgentEvents<CApp>
{
public:
    CApp();
    

DECLARE_REGISTRY_RESOURCEID(IDR_APP)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CApp)
    COM_INTERFACE_ENTRY(IApp)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IConnectionPointContainer)
    COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CApp)
CONNECTION_POINT_ENTRY(DIID__IVideoAgentEvents)
END_CONNECTION_POINT_MAP()

// IApp
public:
    STDMETHOD(app_destroy)(/*[out,retval]*/ Pj_Status *retStatus);
    STDMETHOD(app_start)(/*[out,retval]*/ Pj_Status *retStatus);
    STDMETHOD(aboutbox)(/*[out]*/ BSTR * str);
    STDMETHOD(app_init)(/*[in]*/ VideoAgent_Config *pConfig, /*[out,retval]*/ Pj_Status *pStatus);
    STDMETHOD(app_test_config)(/*[in]*/ VideoAgent_Config *pConfig, /*[out,retval,string]*/ BSTR *retmsg);
    STDMETHOD(app_default_config)(/*[in,out]*/ VideoAgent_Config *pConfig);
    STDMETHOD(app_create)(/*[out,retval]*/ Pj_Status *ret);
    STDMETHOD(app_compare_uri_string)(/*[in]*/ Pjsip_Uri_Context context, /*[in]*/ BSTR uri1, /*[in]*/ BSTR uri2, /*[out,retval]*/ Pj_Status *pStatus);
    STDMETHOD(app_print_uri)(/*[in]*/ Pjsip_Sip_Uri *pSipURI, Pjsip_Uri_Context context, /*[out,retval]*/ BSTR *uriText);
    STDMETHOD(app_parse_uri)(/*[in]*/ BSTR uriString, /*[out]*/ Pjsip_Sip_Uri *pSipUri, /*[out,retval]*/ Pj_Status *pStatus);
    STDMETHOD(app_handle_events)(/*[in]*/ int msec_timeout, /*[out,retval]*/ int *pEvCount);
    STDMETHOD(app_verify_sip_url)(/*[in,string]*/ Pj_String uri, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(app_get_error_msg)(/*[in]*/ Pj_Status status, /*[out,retval]*/ BSTR * errmsg);
    STDMETHOD(app_get_current_config)(/*[out,retval]*/ VideoAgent_Config *pConfig);
    STDMETHOD(app_save_config)(/*[in,string]*/ Pj_String filename, /*[in]*/ VideoAgent_Config *pConfig, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(app_load_config)(/*[in,string]*/ Pj_String filename, /*[out]*/ VideoAgent_Config *pConfig, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(recorder_destroy)(/*[in]*/ int recorder_id, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(recorder_get_conf_port)(/*[in]*/ int recorder_id, /*[out,retval]*/ int *pPort);
    STDMETHOD(recorder_create)(/*[in,string]*/ Pj_String filename, /*[out]*/ int *pRecorder_Id, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(player_destroy)(/*[in]*/ int player_id, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(player_set_pos)(/*[in]*/ int player_id, /*[in]*/ int pos, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(player_get_conf_port)(/*[in]*/ int player_id, /*[out,retval]*/ int *pPort);
    STDMETHOD(player_create)(/*[in,string]*/ Pj_String filename, /*[out]*/ int *pPlayer_Id, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(conf_disconnect)(/*[in]*/ int src_port, /*[in]*/ int sink_port, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(conf_connect)(/*[in]*/ int src_port, /*[in]*/ int sink_port, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(conf_enum_ports)(SAFEARRAY **pPortsArray);
    STDMETHOD(conf_get_port_info)(int port_id, VideoAgent_Conf_Port_Info *pInfo, Pj_Status *pRet);
    STDMETHOD(im_typing)(/*[in]*/ int acc_index, /*[in,string]*/ Pj_URI dst_uri, /*[in]*/ int is_typing, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(im_send_text)(/*[in]*/ int acc_index, /*[in,string]*/ Pj_String dst_uri, /*[in,string]*/ Pj_String text, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(buddy_subscribe_pres)(/*[in]*/ int buddy_index, /*[in]*/ int subscribe, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(buddy_add)(/*[in,string]*/ Pj_String uri, /*[out]*/ int *pBuddy_Index, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(buddy_get_info)(/*[in]*/ int buddy_index, /*[out]*/ VideoAgent_Buddy_Info *pInfo, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(buddy_get_count)(/*[out,retval]*/ int *pCount);
    STDMETHOD(buddy_del)(/*[in]*/ int buddy_index, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(acc_set_registration)(/*[in]*/ int acc_index, /*[in]*/ int reg_active, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(acc_set_online_status)(/*[in]*/ int acc_index, /*[in]*/ int is_online, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(acc_add)(/*[in]*/ VideoAgent_Acc_Config *pConfig, /*[out]*/ int *pAcc_Index, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(acc_del)(/*[out,retval]*/ int acc_index, Pj_Status *pRet);
    STDMETHOD(acc_get_info)(/*[in]*/ int acc_index, /*[out]*/ VideoAgent_Acc_Info *pInfo, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(acc_get_count)(/*[out,retval]*/ int *pCount);
    STDMETHOD(acc_enum_id)(SAFEARRAY **accIdArray);
    STDMETHOD(acc_find_for_outgoing)(/*[in]*/ BSTR url, /*[out]*/ BSTR *abc, /*[out,retval]*/ int *acc_index);
    STDMETHOD(call_hangup_all)();
    STDMETHOD(call_typing)(/*[in]*/ int call_index, /*[in]*/ int is_typing, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_send_im)(/*[in]*/ int call_index, /*[in,string]*/ Pj_String text, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_dial_dtmf)(/*[in]*/ int call_index, /*[in,string]*/ Pj_String digits, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_xfer)(/*[in]*/ int call_index, /*[in,string]*/ Pj_String dst_uri, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_release_hold)(/*[in]*/ int call_index, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_set_hold)(/*[in]*/ int call_index, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_hangup)(/*[in]*/ int call_index, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_answer)(/*[in]*/ int call_index, /*[in]*/ int status_code, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_make_call)(/*[in]*/ int acc_index, /*[in,string]*/ Pj_String dst_uri, /*[out]*/ int *call_index, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_get_info)(/*[in]*/ int call_index, /*[out]*/ VideoAgent_Call_Info *pInfo, /*[out,retval]*/ Pj_Status *pRet);
    STDMETHOD(call_has_media)(/*[in]*/ int call_index, /*[out,retval]*/ Pj_Bool *pRet);
    STDMETHOD(call_is_active)(/*[in]*/ int call_index, /*[out,retval]*/ Pj_Bool *retVal);
    STDMETHOD(call_get_count)(/*[out,retval]*/ int *retCount);
    STDMETHOD(call_get_max_count)(/*[out,retval]*/ int *retCount);
    STDMETHOD(call_get_textstat)(/* [in] */ int call_index,    /* [retval][out] */ BSTR *textstat);
    // 61
    STDMETHOD(focusua_test_sdl)(/*[out,retval]*/ Pj_Status *retmsg);
    // 62
    STDMETHOD(focusua_app_test_config)(/*[out,retval,string]*/ BSTR *retmsg);
    // 63
    STDMETHOD(focusua_init)(/*[out,retval]*/ Pj_Status *retmsg);
    // 64
    // 65
    STDMETHOD(focusua_idestroy)(/*[out,retval]*/ Pj_Status *retmsg);
    // 66
    STDMETHOD(focusua_acc_add)(
        /*[in]*/ int _00accountId,
        /*[in]*/ BSTR _01label,
        /*[in]*/ BSTR _02server,
        /*[in]*/ BSTR _03proxy,
        /*[in]*/ BSTR _04username,
        /*[in]*/ BSTR _05domain,
        /*[in]*/ int  _06port,
        /*[in]*/ BSTR _07authID,
        /*[in]*/ BSTR _08password,
        /*[in]*/ int  _09rememberPassword,
        /*[in]*/ BSTR _10displayName,
        /*[in]*/ BSTR _11voicemailNumber,
        /*[in]*/ BSTR _12srtp,
        /*[in]*/ BSTR _13transport,
        /*[in]*/ BSTR _14publicAddr,
        /*[in]*/ int  _15publish,
        /*[in]*/ int  _16ice,
        /*[in]*/ int  _17allowRewrite,
        /*[in]*/ int  _18disableSessionTimer,
        /*[out]*/ int * pAcc_Index, 
        /*[out,retval]*/ Pj_Status *retStatus);

    // 67
    STDMETHOD(focusua_call_make_call)(
        /*[in]*/ BSTR _21callId,
        /*[in]*/ BSTR _22numb,
        /*[in]*/ BSTR _23number,
        /*[in]*/ BSTR _24numberParameters,
        /*[in]*/ BSTR _25name,
        /*[in]*/ int hasVideo,
        /*[out,retval]*/ Pj_Status *retStatus);
    // 68
    STDMETHOD(focus_change_stream)(
        /*[out,retval]*/ Pj_Status *retStatus);

	STDMETHOD(focusua_call_make_call_with_settings)(
        /*[in]*/ BSTR _21callId,
        /*[in]*/ BSTR _22numb,
        /*[in]*/ BSTR _23number,
        /*[in]*/ BSTR _24numberParameters,
        /*[in]*/ BSTR _25name,
        /*[in]*/ int hasVideo,
        /*[in]*/ int overlay_mode,
        /*[in]*/ BSTR dir_string,
        /*[out,retval]*/ Pj_Status *retStatus);

};

#endif //__APP_H_



