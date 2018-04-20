// FocusSip.cpp : CFocusSip 的实现
#include "stdafx.h"
// ABChernic
#include <pj/types.h>
#include <pjsua-lib/pjsua.h>
#include "focusua_typedef.h"
#include "focusua_common.h"
#include "FocusSip.h"

/////////////////////////////////////////////////////////////////////////////
/// FROM PJSUA_APP_C
static focusua_app_cfg_t    app_cfg;
// ABChernic(guess): pj_ ready ==  app_ running == pj_ inited
static pj_bool_t            pj_inited = PJ_FALSE;
static pj_caching_pool      cli_cp;
static pj_bool_t            cli_cp_inited = PJ_FALSE;
static pj_cli_t             *cli = NULL;
static pj_cli_sess          *cli_cons_sess = NULL;
static pj_cli_front_end     *telnet_front_end = NULL;
/// CFocusSip
static CFocusSip            *CFocusSip_Instance;

/////////////////////////////////////////////////////////////////////////////
/// FROM PJSUA_APP_C
// 这里ID 是否需要改一下(已经改了)
// {60381F8B-91D5-4e1d-AB2B-EF3C55A86BCF}
static const GUID IID_VideoAgent_Cred_Info = 
{ 0x60381f8b, 0x91d5, 0x4e1d, { 0xab, 0x2b, 0xef, 0x3c, 0x55, 0xa8, 0x6b, 0xcf } };
// {1B943652-C2F1-4108-ACFE-B6EE0F3466A9}
static const GUID IID_VideoAgent_Sip_Uri = 
{ 0x1b943652, 0xc2f1, 0x4108, { 0xac, 0xfe, 0xb6, 0xee, 0xf, 0x34, 0x66, 0xa9 } };
// {C28315D5-C4E0-4046-9D8C-99659598A976}
static const GUID IID_VideoAgent_Acc_Config = 
{ 0xc28315d5, 0xc4e0, 0x4046, { 0x9d, 0x8c, 0x99, 0x65, 0x95, 0x98, 0xa9, 0x76 } };
// {776CB8AD-7103-4d1e-8C8D-FBAF3D6E63DE}
static const GUID IID_VideoAgent_Config = 
{ 0x776cb8ad, 0x7103, 0x4d1e, { 0x8c, 0x8d, 0xfb, 0xaf, 0x3d, 0x6e, 0x63, 0xde } };

// {A4DCBC38-A768-4682-A54F-3A273892BC4F}
static const GUID IID_VideoAgent_Call_Info = 
{ 0xa4dcbc38, 0xa768, 0x4682, { 0xa5, 0x4f, 0x3a, 0x27, 0x38, 0x92, 0xbc, 0x4f } };
// {0016ACEA-B415-422d-AFF2-F25764DF6D63}
static const GUID IID_VideoAgent_Buddy_Info = 
{ 0x16acea, 0xb415, 0x422d, { 0xaf, 0xf2, 0xf2, 0x57, 0x64, 0xdf, 0x6d, 0x63 } };
// {0209C970-B5EC-4b4c-A90A-3BF06AAEE8B9}
static const GUID IID_VideoAgent_Acc_Info = 
{ 0x209c970, 0xb5ec, 0x4b4c, { 0xa9, 0xa, 0x3b, 0xf0, 0x6a, 0xae, 0xe8, 0xb9 } };
// {6435F060-07B7-4d94-9537-151CDA58AC96}
static const GUID IID_VideoAgent_Conf_Port_Info = 
{ 0x6435f060, 0x7b7, 0x4d94, { 0x95, 0x37, 0x15, 0x1c, 0xda, 0x58, 0xac, 0x96 } };

#define SA_SIZE(lbound,ubound)  (ubound-lbound)

/////////////////////////////////////////////////////////////////////////////
/** string methods **/
static pj_str_t Pj_str(pj_pool_t *pool, Pj_String s){
    pj_str_t ret;
    unsigned len;

    len = wcslen(s);
    if (len) {
    ret.ptr = (char*)pj_pool_alloc(pool, len+1);
    ret.slen = len;
    pj_unicode_to_ansi(s, len, ret.ptr, len+1);
    ret.ptr[ret.slen] = '\0';
    } else {
    ret.ptr = NULL;
    ret.slen = 0;
    }

    return ret;
}
BSTR str2bstr(const char *str, unsigned len){
    if (len == 0) {
    return SysAllocString(L"");
    } else {
    OLECHAR *tmp;
    BSTR result;
    tmp = (OLECHAR*) malloc((len+1) * sizeof(OLECHAR));
    pj_ansi_to_unicode(str, len, tmp, len+1);
    result = SysAllocString(tmp);
    free(tmp);
    return result;
    }
}
#define Cp(d,s) Cp2(&d,s)
static void Cp2(BSTR *dst, const pj_str_t *src){
    *dst = str2bstr(src->ptr, src->slen);
}
/////////////////////////////////////////////////////////////////////////////
/** CLI callback **/
/* Called on CLI (re)started, e.g: initial start, after iOS bg */
void cli_on_started(pj_status_t status){
    /* Notify app */
    if (app_cfg.on_started) {
    if (status == PJ_SUCCESS) {
        char info[128];
        cli_get_info(info, sizeof(info));
        if (app_cfg.on_started) {
        (*app_cfg.on_started)(status, info);
        }
    } else {
        if (app_cfg.on_started) {
        (*app_cfg.on_started)(status, NULL);
        }
    }
    }
}
/* Called on CLI quit */
void cli_on_stopped(pj_bool_t restart, int argc, char* argv[]){
    /* Notify app */
    if (app_cfg.on_stopped)
    (*app_cfg.on_stopped)(restart, argc, argv);
}
/* Called on pjsua legacy quit */
void legacy_on_stopped(pj_bool_t restart){
    /* Notify app */
    if (app_cfg.on_stopped)
    (*app_cfg.on_stopped)(restart, 1, NULL);
}
/////////////////////////////////////////////////////////////////////////////
/** ui methods **/
stComplexFrameRect_t ComplexFrameRect;
RECT setRECT(LONG left, LONG top, LONG right, LONG bottom){
  RECT rcX     = {0};
  rcX.left     = left;
  rcX.top      = top;
  rcX.right    = right;
  rcX.bottom   = bottom;
  return  rcX;
}
PosSize_t setPosSize(LONG left, LONG top, LONG wight, LONG height){
  PosSize_t PosSize= {0};
  PosSize.left     = left;
  PosSize.top      = top;
  PosSize.wight    = wight;
  PosSize.height   = height;
  return  PosSize;
}
void setComplexFrameRect(void){
  int cxMax = 0; 
  int cyMax = 0; 
  int cXset = 0;
  int cYset = 0;


  cxMax = GetSystemMetrics(SM_CXSCREEN); 
  cyMax = GetSystemMetrics(SM_CYSCREEN); 

  cXset = 640;
  cYset = 480;

  // 这里是上下左右
  ComplexFrameRect.rcMax    = setRECT(0,        0, cxMax,     cyMax);
  ComplexFrameRect.rcMin    = setRECT(0,        0, 0,       0);
  ComplexFrameRect.rcComplex  = setRECT(0,        0, cXset,     cYset);
  ComplexFrameRect.rcHangup   = setRECT(0,    cYset, cXset,       cyMax);

  // 这里是左上角 大小
  ComplexFrameRect.psMin    = setPosSize(0,     0,     0,           0);
  ComplexFrameRect.psMax    = setPosSize(0,   0, cxMax,     cyMax);
  ComplexFrameRect.psPreview  = setPosSize(0,   0, cXset,     cYset);
  ComplexFrameRect.psStream   = setPosSize(cXset, 0, cxMax-cXset, cyMax);

}

// 
pj_status_t load_config(int argc, char **argv, pj_str_t *uri_arg){
  pj_status_t status = PJ_SUCCESS;
  pj_bool_t use_cli = PJ_FALSE;
  int cli_fe = 0;
  pj_uint16_t cli_telnet_port = 0;

  /** CLI options are not changable **/
  if (pj_inited){
    use_cli = app_config.use_cli;
    cli_fe = app_config.cli_cfg.cli_fe;
    cli_telnet_port = app_config.cli_cfg.telnet_cfg.port;
  }
/// XXX
  // status = parse_config(argc, argv, uri_arg);
  // if (status != PJ_SUCCESS)
  // return status;

  if (pj_inited){
    app_config.use_cli = use_cli;
    app_config.cli_cfg.cli_fe = cli_fe;
    app_config.cli_cfg.telnet_cfg.port = cli_telnet_port;
  }

  return status;
}
PJ_DEF(void) cli_get_info(char *info, pj_size_t size) {
    pj_cli_telnet_info telnet_info;
    pj_cli_telnet_get_info(telnet_front_end, &telnet_info);

    pj_ansi_snprintf(info, size, "Telnet to %.*s:%d",
             (int)telnet_info.ip_address.slen,
             telnet_info.ip_address.ptr,
             telnet_info.port);
}
// Static
static void SafeStringArray2pjstrarray(pj_pool_t *pool, SAFEARRAY *sa, unsigned *count, pj_str_t a[]){
    if (!sa)
    *count = 0;
    else {
    HRESULT hr;
    long lbound;
    unsigned i;

    hr = SafeArrayGetLBound(sa, 1, &lbound);
    if (FAILED(hr))
        *count = 0;
    else {
        *count = 0;
        for (i=0; i<sa->cbElements; ++i) {
        BSTR str = NULL;
        long rg = lbound + i;
        hr = SafeArrayGetElement(sa, &rg, &str);
        if (FAILED(hr))
            break;
        a[*count] = Pj_str(pool, str);
        *count = *count + 1;
        }
    }
    }
}
static void pjstrarray2SafeStringArray(unsigned count, const pj_str_t a[], SAFEARRAY **psa){
    unsigned i;
    SAFEARRAY *sa;

    sa = SafeArrayCreateVector( VT_BSTR, 0, count);

    for (i=0; i<count; ++i) {
    BSTR value;
    Cp(value, &a[i]);
    long rg = i;
    SafeArrayPutElement(sa, &rg, value);
    }

    *psa = sa;
}
static void AccConfig2accconfig(pj_pool_t *pool, VideoAgent_Acc_Config *c1, pjsua_acc_config *c2){
    pj_memset(c2, 0, sizeof(pjsua_acc_config));
/*
    c2->id = Pj_str(pool, c1->acc_uri);
    c2->reg_uri = Pj_str(pool, c1->reg_uri);
    c2->contact = Pj_str(pool, c1->contact_uri);
    c2->proxy = Pj_str(pool, c1->proxy_uri);
    c2->reg_timeout = c1->reg_timeout;

    if (c1->cred_info == NULL) {
    c2->cred_count = 0;
    } else {
    unsigned i;
    long lbound;
    HRESULT hr;

    hr = SafeArrayGetLBound(c1->cred_info, 1, &lbound);
    if (FAILED(hr)) {
        c2->cred_count = 0;
    } else {
        c2->cred_count = 0;
        for (i=0; i<c1->cred_info->cbElements; ++i) {
        Pjsip_Cred_Info cred_info;
        long rg = lbound + i;
        pj_memset(&cred_info, 0, sizeof(cred_info));
        hr = SafeArrayGetElement(c1->cred_info, &rg, &cred_info);
        if (FAILED(hr))
            break;
        c2->cred_info[i].realm = Pj_str(pool, cred_info.realm);
        c2->cred_info[i].scheme = Pj_str(pool, cred_info.scheme);
        c2->cred_info[i].username = Pj_str(pool, cred_info.username);
        c2->cred_info[i].data_type = cred_info.hashed;
        c2->cred_info[i].data = Pj_str(pool, cred_info.data);
        }
        c2->cred_count = i;
    }
    }
*/
}
static HRESULT accconfig2AccConfig( pjsua_acc_config *c1, VideoAgent_Acc_Config *c2){
    //unsigned i;

    //pj_memset(c2, 0, sizeof(VideoAgent_Acc_Config));
    /*
    Cp(c2->acc_uri, &c1->id);
    Cp(c2->reg_uri, &c1->reg_uri);
    Cp(c2->contact_uri, &c1->contact);
    Cp(c2->proxy_uri, &c1->proxy);
    c2->reg_timeout = c1->reg_timeout;


    IRecordInfo *pUdtRecordInfo = NULL;
    HRESULT hr = GetRecordInfoFromGuids( LIBID_FocusSipAtlLib,
                                         1, 0,
                                         0,
                                         IID_VideoAgent_Cred_Info,
                                         &pUdtRecordInfo );
    if( FAILED( hr ) ) {
        return( hr ); //Return original HRESULT hr2 is for debug only
    }

    SAFEARRAYBOUND rgsabound[1];
    rgsabound[0].lLbound = 0;
    rgsabound[0].cElements = c1->cred_count;

    c2->cred_info = ::SafeArrayCreateEx( VT_RECORD, 1, rgsabound, pUdtRecordInfo );

    pUdtRecordInfo->Release(); //do not forget to release the interface

    for (i=0; i<c1->cred_count; ++i) {
    Pjsip_Cred_Info cred_info;

    Cp(cred_info.realm, &c1->cred_info[i].realm);
    Cp(cred_info.scheme, &c1->cred_info[i].scheme);
    Cp(cred_info.username, &c1->cred_info[i].username);
    cred_info.hashed = (c1->cred_info[i].data_type != 0);
    Cp(cred_info.data, &c1->cred_info[i].data);

    long rg = i;
    SafeArrayPutElement(c2->cred_info, &rg, &cred_info);
    }
    */
    return S_OK;
}
static HRESULT Config2config(pj_pool_t *pool, VideoAgent_Config *c1, pjsua_config *c2){
    pj_memset(c2, 0, sizeof(pjsua_config));
    /*
    c2->udp_port = c1->udp_port;
    c2->sip_host = Pj_str(pool, c1->sip_host);
    c2->sip_port = c1->sip_port;
    c2->start_rtp_port = c1->rtp_port;
    c2->msg_logging = c1->msg_logging;
    c2->max_calls = c1->max_calls;
    c2->conf_ports = c1->conf_ports;
    c2->thread_cnt = c1->thread_cnt;
    c2->stun_srv1 = Pj_str(pool, c1->stun_srv1);
    c2->stun_port1 = c1->stun_port1;
    c2->stun_srv2 = Pj_str(pool, c1->stun_srv2);
    c2->stun_port2 = c1->stun_port2;
    c2->snd_player_id = c1->snd_player_id;
    c2->snd_capture_id = c1->snd_capture_id;
    c2->clock_rate = c1->clock_rate;
    c2->null_audio = c1->null_audio;
    c2->quality = c1->quality;
    c2->complexity = c1->complexity;

    SafeStringArray2pjstrarray(pool, c1->codec_arg, &c2->codec_cnt, c2->codec_arg);

    c2->auto_answer = c1->auto_answer;
    c2->uas_refresh = c1->uas_refresh;
    c2->outbound_proxy = Pj_str(pool, c1->outbound_proxy);

    if (!c1->acc_config)
    c2->acc_cnt = 0;
    else {
    HRESULT hr;
    long lbound;
    unsigned i;

    hr = SafeArrayGetLBound(c1->acc_config, 1, &lbound);
    if (FAILED(hr))
        c2->acc_cnt = 0;
    else {
        c2->acc_cnt = 0;

        for (i=0; i<c1->acc_config->cbElements; ++i) {
        VideoAgent_Acc_Config acc_config;
        long rg = lbound + i;
        pj_memset(&acc_config, 0, sizeof(acc_config));
        hr = SafeArrayGetElement(c1->acc_config, &rg, &acc_config);
        if (FAILED(hr))
            break;
        AccConfig2accconfig(pool, &acc_config, &c2->acc_config[i]);
        }

        c2->acc_cnt = i;
    }
    }

    c2->log_level = c1->log_level;
    c2->app_log_level = c1->app_log_level;
    c2->log_decor = c1->log_decor;
    c2->log_filename = Pj_str(pool, c1->log_filename);

    SafeStringArray2pjstrarray(pool, c1->buddy_uri, &c2->buddy_cnt, c2->buddy_uri);
    */
    return S_OK;
}
static HRESULT config2Config(pjsua_config *c1, VideoAgent_Config *c2){
    //unsigned i;
    //HRESULT hr;

    pj_memset(c2, 0, sizeof(VideoAgent_Config));
    /*
    c2->udp_port = c1->udp_port;
    Cp(c2->sip_host, &c1->sip_host);
    c2->sip_port = c1->sip_port;
    c2->rtp_port = c1->start_rtp_port;
    c2->msg_logging = c1->msg_logging;
    c2->max_calls = c1->max_calls;
    c2->conf_ports = c1->conf_ports;
    c2->thread_cnt = c1->thread_cnt;
    Cp(c2->stun_srv1, &c1->stun_srv1);
    c2->stun_port1 = c1->stun_port1;
    Cp(c2->stun_srv2, &c1->stun_srv2);
    c2->stun_port2 = c1->stun_port2;
    c2->snd_player_id = c1->snd_player_id;
    c2->snd_capture_id = c1->snd_capture_id;
    c2->clock_rate = c1->clock_rate;
    c2->null_audio = c1->null_audio;
    c2->quality = c1->quality;
    c2->complexity = c1->complexity;

    pjstrarray2SafeStringArray(c1->codec_cnt, c1->codec_arg, &c2->codec_arg);

    c2->auto_answer = c1->auto_answer;
    c2->uas_refresh = c1->uas_refresh;

    Cp(c2->outbound_proxy, &c1->outbound_proxy);

    IRecordInfo *pUdtRecordInfo = NULL;
    hr = GetRecordInfoFromGuids( LIBID_FocusSipAtlLib,
                                 1, 0,
                                 0,
                                 IID_VideoAgent_Acc_Config,
                                 &pUdtRecordInfo );
    if( FAILED( hr ) ) {
        return( hr ); //Return original HRESULT hr2 is for debug only
    }

    SAFEARRAYBOUND rgsabound[1];
    rgsabound[0].lLbound = 0;
    rgsabound[0].cElements = c1->acc_cnt;

    c2->acc_config = ::SafeArrayCreateEx( VT_RECORD, 1, rgsabound, pUdtRecordInfo );

    pUdtRecordInfo->Release(); //do not forget to release the interface

    for (i=0; i<c1->acc_cnt; ++i) {
    VideoAgent_Acc_Config acc_cfg;

    hr = accconfig2AccConfig(&c1->acc_config[i], &acc_cfg);
    if (FAILED(hr))
        return hr;

    long rg = i;
    SafeArrayPutElement(c2->acc_config, &rg, &acc_cfg);
    }


    c2->log_level = c1->log_level;
    c2->app_log_level = c1->app_log_level;
    c2->log_decor = c1->log_decor;

    Cp(c2->log_filename, &c1->log_filename);

    pjstrarray2SafeStringArray(c1->buddy_cnt, c1->buddy_uri, &c2->buddy_uri);
    */
    return S_OK;
}
static void callinfo2CallInfo(pjsua_call_info *c1, VideoAgent_Call_Info *c2){
    pj_memset(c2, 0, sizeof(VideoAgent_Call_Info));
    /*
    c2->index = c1->index;
    c2->active = c1->active;
    c2->is_uac = (c1->role == PJSIP_ROLE_UAC);
    Cp(c2->local_info, &c1->local_info);
    Cp(c2->remote_info, &c1->remote_info);
    c2->state = (VideoAgent_Call_State)c1->state;
    Cp(c2->state_text, &c1->state_text);
    c2->connect_duration = c1->connect_duration.sec;
    c2->total_duration = c1->total_duration.sec;
    c2->last_status = c1->last_status;
    Cp(c2->last_status_text, &c1->last_status_text);
    c2->has_media = c1->has_media;
    c2->conf_slot = c1->conf_slot;
    */
}
static void accinfo2AccInfo(pjsua_acc_info *info1, VideoAgent_Acc_Info *info2){
    pj_memset(info2, 0, sizeof(VideoAgent_Acc_Info));
    /*
    info2->index = info1->index;
    Cp(info2->acc_uri, &info1->acc_id);
    info2->has_registration = info1->has_registration;
    info2->expires = info1->expires;
    info2->status_code = info1->status;
    Cp(info2->status_text, &info1->status_text);
    info2->online_status = info1->online_status;
    */
}
static void buddyinfo2BuddyInfo(pjsua_buddy_info *info1, VideoAgent_Buddy_Info *info2){
    pj_memset(info2, 0, sizeof(VideoAgent_Buddy_Info));
    /*
    info2->index = info1->index;
    info2->is_valid = info1->is_valid;
    Cp(info2->name, &info1->name);
    Cp(info2->display, &info1->display_name);
    Cp(info2->host, &info1->host);
    info2->port = info1->port;
    Cp(info2->uri, &info1->uri);
    info2->status = (VideoAgent_Buddy_State)info1->status;
    Cp(info2->status_text, &info1->status_text);
    info2->monitor = info1->monitor;
    */
}

// FocusSip : Callback 1 ()
static void on_reg_state2(pjsua_acc_id acc_id, pjsua_reg_info *info){
    //if (!IsWindow(mainDlg->m_hWnd))   {
    //  return;
    // }
    //CString *str = NULL;
    //PostMessage(mainDlg->m_hWnd, UM_ON_REG_STATE2, (WPARAM) info->cbparam->code, (LPARAM) str);
}
// FocusSip : Callback 2 
static void on_call_state(pjsua_call_id call_id, pjsip_event *e){
    pjsua_call_info call_info;
    pjsua_call_get_info(call_id, &call_info);
    
    // App Actions
    VideoAgent_Call_Info *Call_Info = new VideoAgent_Call_Info;
    callinfo2CallInfo(&call_info, Call_Info);


	// ABChernic : 暂时有问题
//////CFocusSip_Instance->Fire_OnCallState(call_id, Call_Info);
}
// FocusSip : Callback 3 ()
static void on_dtmf_digit(pjsua_call_id call_id, int digit){
    //char signal[2];
    //signal[0] = digit;
    //signal[1] = 0;
    //call_play_digit(-1, signal);
}
// FocusSip : Callback 4 ()
static void on_call_tsx_state(pjsua_call_id call_id,pjsip_transaction *tsx,pjsip_event *e){
}
//////////////////////////////////////////////////////////////////
// MicroSip : Callback 5 ()
static void on_call_media_state(pjsua_call_id call_id){
  pjsua_call_info *call_info = new pjsua_call_info();
  if (pjsua_call_get_info(call_id, call_info) != PJ_SUCCESS || call_info->state == PJSIP_INV_STATE_NULL) {
    return;
  }

#ifdef _GLOBAL_VIDEO
    ResizeStreamWindow ( ComplexFrameRect.psStream );
    ResizePreviewWindow( ComplexFrameRect.psPreview);

    ShowStreamWindow(PJ_TRUE);
    ShowPreviewWindow(PJ_TRUE);
#endif
}
//////////////////////////////////////////////////////////////////
// FocusSip : Callback 6
static void on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id,pjsip_rx_data *rdata){
    CFocusSip_Instance->Fire_OnIncomingCall(call_id);
}
// FocusSip : Callback 7 ()
static void on_nat_detect(const pj_stun_nat_detect_result *res){
}
// FocusSip : Callback 8
static void on_buddy_state(pjsua_buddy_id buddy_id){
    CFocusSip_Instance->Fire_OnBuddyState(buddy_id);
}
// FocusSip : Callback 9 ()
static void on_pager2(pjsua_call_id call_id, const pj_str_t *from, const pj_str_t *to, const pj_str_t *contact, const pj_str_t *mime_type, const pj_str_t *body, pjsip_rx_data *rdata, pjsua_acc_id acc_id){
    //if (IsWindow(mainDlg->m_hWnd)) {
    //  CString *number = new CString();
    //  CString *message = new CString();
    //  number->SetString(PjToStr(from, TRUE));
    //  message->SetString(PjToStr(body, TRUE));
    //  message->Trim();
    //  //-- fix wrong domain
    //  SIPURI sipuri;
    //  ParseSIPURI(*number, &sipuri);
    //  if (accountSettings.accountId && account == acc_id) {
    //      if (IsIP(sipuri.domain)) {
    //          sipuri.domain = accountSettings.account.domain;
    //      }
    //      if (!sipuri.user.IsEmpty()) {
    //          number->Format(_T("%s@%s"),sipuri.user,sipuri.domain);
    //      } else {
    //          number->SetString(sipuri.domain);
    //      }
    //  }
    //  //--
    //  mainDlg->PostMessage(UM_ON_PAGER, (WPARAM)number, (LPARAM)message);
    // }
}
// FocusSip : Callback 10  ()
static void on_pager_status2(pjsua_call_id call_id, const pj_str_t *to, const pj_str_t *body, void *user_data, pjsip_status_code status, const pj_str_t *reason, pjsip_tx_data *tdata, pjsip_rx_data *rdata, pjsua_acc_id acc_id){
    //if (status != 200) {
    //  if (IsWindow(mainDlg->m_hWnd)) {
    //      CString *number = new CString();
    //      CString *message = new CString();
    //      number->SetString(PjToStr(to, TRUE));
    //      message->SetString(PjToStr(reason, TRUE));
    //      message->Trim();
    //      //-- fix wrong domain
    //      SIPURI sipuri;
    //      ParseSIPURI(*number, &sipuri);
    //      if (accountSettings.accountId && account == acc_id) {
    //          if (IsIP(sipuri.domain)) {
    //              sipuri.domain = accountSettings.account.domain;
    //          }
    //          if (!sipuri.user.IsEmpty()) {
    //              number->Format(_T("%s@%s"),sipuri.user,sipuri.domain);
    //          } else {
    //              number->SetString(sipuri.domain);
    //          }
    //      }
    //      //--
    //      mainDlg->PostMessage(UM_ON_PAGER_STATUS, (WPARAM)number, (LPARAM)message);
    //  }
    // }
}
// FocusSip : Callback 11 ()
static void on_call_transfer_request2(pjsua_call_id call_id, const pj_str_t *dst, pjsip_status_code *code, pjsua_call_setting *opt){
    //SIPURI sipuri;
    //ParseSIPURI(PjToStr(dst,TRUE),&sipuri);
    //// display transfer request
    //pj_bool_t cont;
    //CString number = sipuri.user;
    //if (number.IsEmpty()) {
    //  number = sipuri.domain;
    // } else if (!accountSettings.accountId || sipuri.domain != accountSettings.account.domain){
    //  number.Append(_T("@")+sipuri.domain);
    // }
    //pj_str_t status_text = StrToPjStr(number);
    //on_call_transfer_status(call_id,
    //  0,
    //  &status_text,
    //  PJ_FALSE,
    //  &cont);
    ////--
    //if (!code) {
    //  // if our function call
    //  return;
    // }
    //// deny transfer if we already have a call with same dest address
    //pjsua_call_id call_ids[PJSUA_MAX_CALLS];
    //unsigned calls_count = PJSUA_MAX_CALLS;
    //unsigned calls_count_cmp = 0;
    //if (pjsua_enum_calls ( call_ids, &calls_count)==PJ_SUCCESS)  {
    //  for (unsigned i = 0; i < calls_count; ++i) {
    //      pjsua_call_info call_info_curr;
    //      if (pjsua_call_get_info(call_ids[i], &call_info_curr) == PJ_SUCCESS) {
    //          SIPURI sipuri_curr;
    //          ParseSIPURI(PjToStr(&call_info_curr.remote_info, TRUE), &sipuri_curr);
    //          if (sipuri.user+_T("@")+sipuri.domain == sipuri_curr.user+_T("@")+sipuri_curr.domain
    //              ) {
    //                  *code = PJSIP_SC_DECLINE;
    //                  break;
    //          }
    //      }
    //  }
    // }
}
// FocusSip : Callback 12 ()
static void on_call_transfer_status(pjsua_call_id call_id,int status_code, const pj_str_t *status_text,pj_bool_t final,pj_bool_t *p_cont){
}
// FocusSip : Callback 13
static void on_call_replace_request2(pjsua_call_id call_id, pjsip_rx_data *rdata, int *st_code, pj_str_t *st_text, pjsua_call_setting *opt){
    pjsua_call_info call_info;
    if (pjsua_call_get_info(call_id, &call_info) == PJ_SUCCESS) {
        if (!call_info.rem_vid_cnt) {
            opt->vid_cnt = 0;
        }
    } else {
        opt->vid_cnt = 0;
    }
}
// FocusSip : Callback 14()
static void on_call_replaced(pjsua_call_id old_call_id,pjsua_call_id new_call_id){
}
// FocusSip : Callback 15()
static void on_mwi_info(pjsua_acc_id acc_id, pjsua_mwi_info *mwi_info){
}

CFocusSip::CFocusSip(){
    CFocusSip_Instance = this;
}


// FocusSip 1
STDMETHODIMP CFocusSip::focusua_aboutbox(Pj_Status* retStatus){
  // TODO: 在此添加实现代码

  * retStatus = 1;

  return S_OK;
}
// FocusSip 2
STDMETHODIMP CFocusSip::focusua_test_sdl(Pj_Status* retStatus){
  RECT rcC = {0, 0, 500, 500};
  //if(!pTEST_SDL2)
  //  pTEST_SDL2 = new TEST_SDL2(); 
  //pTEST_SDL2->SetWindow( rcC );

  * retStatus = 2;
    return S_OK;
}
// FocusSip 3
STDMETHODIMP CFocusSip::focusua_app_test_config(BSTR *retmsg){
    pjsua_config cfg;
    
    char errmsg[PJ_ERR_MSG_SIZE];
    
    pjsua_config_default(&cfg);
    
    mypjsua_test_config(&cfg, errmsg, sizeof(errmsg));
    
    *retmsg = str2bstr(errmsg, strlen(errmsg));
    
    printf("app_test_config_ed\n");
    return S_OK;
}
// FocusSip 11
STDMETHODIMP CFocusSip::focusua_init(Pj_Status *retStatus){
    //pageContacts->isSubscribed = FALSE;CreateResizePreviewWindow
    //player_id = PJSUA_INVALID_ID;
    // check updates
  if(!pj_inited){
    // pj create
    pj_status_t             status;
    pjsua_config            ua_cfg;
    pjsua_media_config      media_cfg;
    pjsua_transport_config  cfg;

    // Must create pjsua before anything else!
    status = pjsua_create();
    if (status != PJ_SUCCESS){
      *retStatus = -1;
      return status;
    }

    // Initialize configs with default settings.
    pjsua_config_default(&ua_cfg);
    pjsua_media_config_default(&media_cfg);

    CString userAgent;
    if (accountSettings.userAgent.IsEmpty()) {
      userAgent.Format(_T("%s/%s"), _T("FocusSIP"), _T("1.0.0"));
      ua_cfg.user_agent = StrToPjStr(userAgent);
    } else {
      ua_cfg.user_agent = StrToPjStr(accountSettings.userAgent);
    }

    ua_cfg.cb.on_reg_state2             =   &on_reg_state2;     //CC
    ua_cfg.cb.on_call_state             =   &on_call_state;     //CC
    ua_cfg.cb.on_dtmf_digit             =   &on_dtmf_digit;
    ua_cfg.cb.on_call_tsx_state         =   &on_call_tsx_state;

    ua_cfg.cb.on_call_media_state       =   &on_call_media_state;
    ua_cfg.cb.on_incoming_call          =   &on_incoming_call;  //CC
    ua_cfg.cb.on_nat_detect             =   &on_nat_detect;
    ua_cfg.cb.on_buddy_state            =   &on_buddy_state;    //CC
    ua_cfg.cb.on_pager2                 =   &on_pager2;
    ua_cfg.cb.on_pager_status2          =   &on_pager_status2;
    ua_cfg.cb.on_call_transfer_request2 =   &on_call_transfer_request2; 
    ua_cfg.cb.on_call_transfer_status   =   &on_call_transfer_status;

    ua_cfg.cb.on_call_replace_request2  =   &on_call_replace_request2;
    ua_cfg.cb.on_call_replaced          =   &on_call_replaced;

    ua_cfg.cb.on_mwi_info               =   &on_mwi_info;

    ua_cfg.srtp_secure_signaling        =   0;

  /*
  TODO: accountSettings.account: public_addr
  */

    if (accountSettings.enableSTUN && !accountSettings.stun.IsEmpty()) {
      ua_cfg.stun_srv_cnt=1;
      ua_cfg.stun_srv[0] = StrToPjStr( accountSettings.stun );
    }

    media_cfg.enable_ice = PJ_FALSE;
    media_cfg.no_vad = accountSettings.vad ? PJ_FALSE : PJ_TRUE;
    media_cfg.ec_tail_len = accountSettings.ec ? PJSUA_DEFAULT_EC_TAIL_LEN : 0;

    media_cfg.clock_rate=44100;
    media_cfg.channel_count=2;

    // Initialize focusua
    if (0) { //if (accountSettings.enableLog) {
      pjsua_logging_config log_cfg;
      pjsua_logging_config_default(&log_cfg);
      ////--
      //CStringA buf;
      //int len = accountSettings.logFile.GetLength()+1;
      //LPSTR pBuf = buf.GetBuffer(len);
      //WideCharToMultiByte(CP_ACP,0,accountSettings.logFile.GetBuffer(),-1,pBuf,len,NULL,NULL);
      //log_cfg.log_filename = pj_str(pBuf);
      //log_cfg.decor |= PJ_LOG_HAS_CR;
      //accountSettings.logFile = pBuf;
      //--
      status = pjsua_init(&ua_cfg, &log_cfg, &media_cfg);
    } else {
      status = pjsua_init(&ua_cfg, NULL, &media_cfg);
    }
    if (status != PJ_SUCCESS) {
      pjsua_destroy();
      *retStatus = -1;
      return S_FALSE;
    }

    // Start pjsua
    status = pjsua_start();
    if (status != PJ_SUCCESS) {
      pjsua_destroy();
      *retStatus = -1;
      return S_FALSE;
    }

    pj_inited = PJ_TRUE;

    // Set snd devices
    UpdateSoundDevicesIds();

    //Set aud codecs prio
    if (accountSettings.audioCodecs.IsEmpty())
    {
      accountSettings.audioCodecs = _T(_GLOBAL_CODECS_ENABLED);
    }
    /*
    if (accountSettings.audioCodecs.GetLength())
    {
      pjsua_codec_info codec_info[64];
      unsigned count = 64;
      pjsua_enum_codecs(codec_info, &count);
      for (unsigned i=0;i<count;i++) {
        pjsua_codec_set_priority(&codec_info[i].codec_id, PJMEDIA_CODEC_PRIO_DISABLED);
        CString rab = PjToStr(&codec_info[i].codec_id);
        if (!audioCodecList.Find(rab)) {
          audioCodecList.AddTail(rab);
          rab.Append(_T("~"));
          audioCodecList.AddTail(rab);
        }
      }
      POSITION pos = audioCodecList.GetHeadPosition();
      while (pos) {
        POSITION posKey = pos;
        CString key = audioCodecList.GetNext(pos);
        POSITION posValue = pos;
        CString value = audioCodecList.GetNext(pos);
        pj_str_t codec_id = StrToPjStr(key);
        pjmedia_codec_param param;
        if (pjsua_codec_get_param(&codec_id, &param)!=PJ_SUCCESS) {
          audioCodecList.RemoveAt(posKey);
          audioCodecList.RemoveAt(posValue);
        }
      };

      int curPos = 0;
      int i = PJMEDIA_CODEC_PRIO_NORMAL;
      CString resToken = accountSettings.audioCodecs.Tokenize(_T(" "),curPos);
      while (!resToken.IsEmpty()) {
        pj_str_t codec_id = StrToPjStr(resToken);

        pjsua_codec_set_priority(&codec_id, i);
            resToken= accountSettings.audioCodecs.Tokenize(_T(" "),curPos);
        i--;
      }
    }
    */

  #ifdef _GLOBAL_VIDEO
    //Set vid codecs prio
    if (accountSettings.videoCodec.GetLength())
    {
      pj_str_t codec_id = StrToPjStr(accountSettings.videoCodec);
      pjsua_vid_codec_set_priority(&codec_id,255);
    }
    int bitrate;
    if (accountSettings.disableH264) {
      pjsua_vid_codec_set_priority(&pj_str("H264"),0);
    } else
    {
      const pj_str_t codec_id = {"H264", 4};
      pjmedia_vid_codec_param param;
      pjsua_vid_codec_get_param(&codec_id, &param);
      if (atoi(CStringA(accountSettings.bitrateH264))) {
        bitrate = 1000 * atoi(CStringA(accountSettings.bitrateH264));
        param.enc_fmt.det.vid.avg_bps = bitrate;
        param.enc_fmt.det.vid.max_bps = bitrate;
      }
      pjsua_vid_codec_set_param(&codec_id, &param);
    }
    if (accountSettings.disableH263) {
      pjsua_vid_codec_set_priority(&pj_str("H263"),0);
    } else {
      if (atoi(CStringA(accountSettings.bitrateH263))) {
        const pj_str_t codec_id = {"H263", 4};
        pjmedia_vid_codec_param param;
        pjsua_vid_codec_get_param(&codec_id, &param);
        bitrate = 1000 * atoi(CStringA(accountSettings.bitrateH263));
        param.enc_fmt.det.vid.avg_bps = bitrate;
        param.enc_fmt.det.vid.max_bps = bitrate;
        pjsua_vid_codec_set_param(&codec_id, &param);
      }
    }
    if (accountSettings.disableVP8) {
      pjsua_vid_codec_set_priority(&pj_str("VP8"),0);
    } else {
      if (atoi(CStringA(accountSettings.bitrateVP8))) {
        const pj_str_t codec_id = {"VP8", 4};
        pjmedia_vid_codec_param param;
        pjsua_vid_codec_get_param(&codec_id, &param);
        bitrate = 1000 * atoi(CStringA(accountSettings.bitrateVP8));
        param.enc_fmt.det.vid.avg_bps = bitrate;
        param.enc_fmt.det.vid.max_bps = bitrate;
        pjsua_vid_codec_set_param(&codec_id, &param);
      }
    }
  #endif

    // Create transport
    transport_udp_local = -1;
    transport_udp = -1;
    transport_tcp = -1;
    transport_tls = -1;

    pjsua_transport_config_default(&cfg);
    cfg.public_addr = StrToPjStr( accountSettings.account.publicAddr );

    if (accountSettings.sourcePort) {
      cfg.port=accountSettings.sourcePort;
      status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, &transport_udp);
      if (status != PJ_SUCCESS) {
        cfg.port=0;
        pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, &transport_udp);
      } 
      if (MACRO_ENABLE_LOCAL_ACCOUNT) {
        if (accountSettings.sourcePort == 5060 ) {
          transport_udp_local = transport_udp;
        } else {
          cfg.port=5060;
          status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, &transport_udp_local);
          if (status != PJ_SUCCESS) {
            transport_udp_local = transport_udp;
          }
        }
      }
    } else {
      if (MACRO_ENABLE_LOCAL_ACCOUNT) {
        cfg.port=5060;
        status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, &transport_udp_local);
        if (status != PJ_SUCCESS) {
          transport_udp_local = -1;
        }
      }
      cfg.port=0;
      pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, &transport_udp);
      if (transport_udp_local == -1) {
        transport_udp_local = transport_udp;
      }
    }

    cfg.port = MACRO_ENABLE_LOCAL_ACCOUNT ? 5060 : 0;
    status = pjsua_transport_create(PJSIP_TRANSPORT_TCP, &cfg, &transport_tcp);
    if (status != PJ_SUCCESS && cfg.port) {
      cfg.port=0;
      pjsua_transport_create(PJSIP_TRANSPORT_TCP, &cfg, &transport_tcp);
    }

    cfg.port = MACRO_ENABLE_LOCAL_ACCOUNT ? 5061 : 0;
    status = pjsua_transport_create(PJSIP_TRANSPORT_TLS, &cfg, &transport_tls);
    if (status != PJ_SUCCESS && cfg.port) {
      cfg.port=0;
      pjsua_transport_create(PJSIP_TRANSPORT_TLS, &cfg, &transport_tls);
    }

    if (accountSettings.usersDirectory.Find(_T("%s"))==-1 && accountSettings.usersDirectory.Find(_T("{"))==-1) {
  ///     UsersDirectoryLoad();
    }

    g_acc_id = PJSUA_INVALID_ID;
    g_acc_id_local = PJSUA_INVALID_ID;

    //PJAccountAddLocal();

    *retStatus = 0;
    return S_OK;
  }else
  {
    *retStatus = 1;
    return S_FALSE;
  }
}
// FocusSip 12
STDMETHODIMP CFocusSip::focusua_idestroy(Pj_Status *retStatus){
  if(pj_inited){
    pj_inited = PJ_FALSE;
    *retStatus = pjsua_destroy();
  }
  *retStatus = -1;
  return S_OK;
}
// FocusSip 13
STDMETHODIMP CFocusSip::focusua_acc_add(BSTR AuthID, BSTR Password, BSTR Domain, BSTR Proxy, Pj_Status *retStatus){
  if(NULL == AuthID){
    *retStatus = -1;
    return S_FALSE;
  }
  if(NULL == Password){
    *retStatus = -1;
    return S_FALSE;
  }
  if(NULL == Domain){
    *retStatus = -1;
    return S_FALSE;
  }
  int  _00accountId           = 1;
  BSTR _01label               = AuthID;
  BSTR _02server              = Domain;
  BSTR _03proxy               = str2bstr("", 0);
  BSTR _04username            = AuthID;
  BSTR _05domain              = Domain;
  int  _06port                = 0;
  BSTR _07authID              = AuthID;
  BSTR _08password            = Password;
  int  _09rememberPassword    = 1;
  BSTR _10displayName         = AuthID;
  BSTR _11voicemailNumber     = str2bstr("", 0);
  BSTR _12srtp                = str2bstr("", 0);
  BSTR _13transport           = str2bstr("", 0);
  BSTR _14publicAddr          = str2bstr("", 0);
  int  _15publish             = 0;
  int  _16ice                 = 0;
  int  _17allowRewrite        = 0;
  int  _18disableSessionTimer = 0;
  int pAcc_Index = 0;

  Pj_Status pRet = 0;

  focusua_account_add(
    _00accountId,   _01label,           _02server,        _03proxy,               _04username,    
    _05domain,      _06port,            _07authID,        _08password,            _09rememberPassword,    
    _10displayName, _11voicemailNumber, _12srtp,          _13transport,           _14publicAddr,    
    _15publish,     _16ice,             _17allowRewrite,  _18disableSessionTimer, &pAcc_Index,
    &pRet
  );
  *retStatus = pRet;
  return S_OK;
}
// FocusSip 14
STDMETHODIMP CFocusSip::focusua_account_add(
    int  _00accountId,
    BSTR _01label,
    BSTR _02server,
    BSTR _03proxy,
    BSTR _04username,
    BSTR _05domain,
    int  _06port,
    BSTR _07authID,
    BSTR _08password,
    int  _09rememberPassword,
    BSTR _10displayName,
    BSTR _11voicemailNumber,
    BSTR _12srtp,
    BSTR _13transport,
    BSTR _14publicAddr,
    int  _15publish,
    int  _16ice,
    int  _17allowRewrite,
    int  _18disableSessionTimer,
    int * pAcc_Index,
    Pj_Status *retStatus)
{
    accountSettings.accountId                   = _00accountId;
    accountSettings.account.label               = _01label;
    accountSettings.account.server              = _02server;
    accountSettings.account.proxy               = _03proxy;
    accountSettings.account.username            = _04username;
    accountSettings.account.domain              = _05domain;
    accountSettings.account.port                = _06port;
    accountSettings.account.authID              = _07authID;
    accountSettings.account.password            = _08password;
    accountSettings.account.rememberPassword    = _09rememberPassword;
    accountSettings.account.displayName         = _10displayName;
    accountSettings.account.voicemailNumber     = _11voicemailNumber;
    accountSettings.account.srtp                = _12srtp;
    accountSettings.account.transport           = _13transport;
    accountSettings.account.publicAddr          = _14publicAddr;
    accountSettings.account.publish             = _15publish;
    accountSettings.account.ice                 = _16ice;
    accountSettings.account.allowRewrite        = _17allowRewrite;
    accountSettings.account.disableSessionTimer = _18disableSessionTimer;

    pjsua_acc_config acc_cfg;
    PJAccountConfig(&acc_cfg);

    if (!accountSettings.accountId) {
        return S_FALSE;
    }

    // 11 default: ""
    if (!accountSettings.account.voicemailNumber.IsEmpty()) {
        acc_cfg.mwi_enabled = PJ_TRUE;
    }
    // 12 default: ""
    if (accountSettings.account.srtp ==_T("optional")) {
        acc_cfg.use_srtp = PJMEDIA_SRTP_OPTIONAL;
    } else if (accountSettings.account.srtp ==_T("mandatory")) {
        acc_cfg.use_srtp = PJMEDIA_SRTP_MANDATORY;
    } else {
        acc_cfg.use_srtp = PJMEDIA_SRTP_DISABLED;
    }
    // 13 default: ""
    /*
    transport = MSIP_TRANSPORT_AUTO;
    if (accountSettings.account.transport==_T("udp") && transport_udp!=-1) {
        acc_cfg.transport_id = transport_udp;
    } else if (accountSettings.account.transport==_T("tcp") && transport_tcp!=-1) {
        transport = MSIP_TRANSPORT_TCP;
    } else if (accountSettings.account.transport==_T("tls") && transport_tls!=-1) {
        transport = MSIP_TRANSPORT_TLS;
    }
    */

    // 14 default: ""
    acc_cfg.rtp_cfg.public_addr     = StrToPjStr( accountSettings.account.publicAddr );
    // 15 default: 0
    acc_cfg.publish_enabled         = accountSettings.account.publish ? PJ_TRUE : PJ_FALSE; 
    // 16 default: 0
    acc_cfg.ice_cfg.enable_ice      = accountSettings.account.ice ? PJ_TRUE : PJ_FALSE;
    // 17 default: 0
    acc_cfg.allow_via_rewrite       = accountSettings.account.allowRewrite ? PJ_TRUE : PJ_FALSE;
    acc_cfg.ice_cfg_use             = PJSUA_ICE_CONFIG_USE_CUSTOM;
    acc_cfg.allow_sdp_nat_rewrite   = acc_cfg.allow_via_rewrite;
    acc_cfg.allow_contact_rewrite   = acc_cfg.allow_via_rewrite ? 2 : PJ_FALSE;
    // 18 default: 0
    if (accountSettings.account.disableSessionTimer) {
        acc_cfg.use_timer = PJSUA_SIP_TIMER_INACTIVE; 
    }

    /*
    CString str;
    str.Format(_T("%s..."),Translate(_T("Connecting")));
    UpdateWindowText(str);
    */
    // 03 default:
    /*CString proxy;
    if (!accountSettings.account.proxy.IsEmpty()) {
        acc_cfg.proxy_cnt = 1;
        proxy.Format(_T("sip:%s"),accountSettings.account.proxy);
        AddTransportSuffix(proxy);
        acc_cfg.proxy[0] = StrToPjStr( proxy );
    }*/
    // 10 default:
    CString localURI;
    if (!accountSettings.account.displayName.IsEmpty()) {
        localURI = _T("\"") + accountSettings.account.displayName + _T("\" ");
    }
    // 04 default: 1005
    // 07 default: 1005
    // 08 default: 1234
    localURI += GetSIPURI(accountSettings.account.username);
    acc_cfg.id                      = StrToPjStr(localURI);
    acc_cfg.cred_count              = 1;
    acc_cfg.cred_info[0].username   = StrToPjStr(!accountSettings.account.authID.IsEmpty()? accountSettings.account.authID : accountSettings.account.username);
    acc_cfg.cred_info[0].realm      = pj_str("*");
    acc_cfg.cred_info[0].scheme     = pj_str("Digest");
    acc_cfg.cred_info[0].data_type  = PJSIP_CRED_DATA_PLAIN_PASSWD;
    acc_cfg.cred_info[0].data       = StrToPjStr( accountSettings.account.password );
    // 02 default: 192.168.1.249:15020
    CString regURI;
    if (accountSettings.account.server.IsEmpty()) {
        acc_cfg.register_on_acc_add = PJ_FALSE;
    } else {
        regURI.Format(_T("sip:%s"),accountSettings.account.server);
        AddTransportSuffix(regURI);
        acc_cfg.reg_uri = StrToPjStr( regURI );
    }
    //-- port knocker

    pj_status_t status = pjsua_acc_add(&acc_cfg, PJ_TRUE, &g_acc_id); // pjsua_acc_id account;
    if (status == PJ_SUCCESS) {
        *pAcc_Index = g_acc_id;
        *retStatus  = 0;
        return S_OK;
    } else {
        *pAcc_Index = g_acc_id;
        *retStatus = -1;
        return S_FALSE;
    }
}
// FocusSip 15
STDMETHODIMP CFocusSip::focusua_make_call(
    BSTR Uri,
    int hasVideo,
    Pj_Status *retStatus
){
  BSTR _Uri       = Uri;
  BSTR _Para      = str2bstr("", 0);
  BSTR _Name      = str2bstr("", 0);
  int _hasVideo   = 1;
  BSTR _pCallId   = str2bstr("-1", 0);
  Pj_Status       pRet;
  focusua_call_make_call(_Uri, _Para, _Name, _hasVideo, &_pCallId, &pRet);

  *retStatus      = pRet;
  return S_OK;
}

// FocusSip 15
STDMETHODIMP CFocusSip::focusua_call_make_call(
    BSTR Uri,
    BSTR Para,
    BSTR Name,
    int  hasVideo,
    BSTR* CallId,
    Pj_Status *retStatus
){
    bool singleMode = true;

    // make_call 1
    pjsua_acc_id acc_id;
    // make_call 2
    pj_str_t pj_uri;
    if (!SelectSIPAccount(Uri,acc_id,pj_uri)) {
        // Account dummy;
        // *pStatus = accountSettings.AccountLoad(1,&dummy) ? PJSIP_EAUTHACCDISABLED : PJSIP_EAUTHACCNOTFOUND;
        // return PJSUA_INVALID_ID;
        return S_FALSE;
    }
    
    if (singleMode) {
        call_hangup_all_noincoming();
    }
    
#ifdef _GLOBAL_VIDEO
    setComplexFrameRect();
    ResetPJmediaData();

    CreatePreviewWindow( ComplexFrameRect.psPreview );
    ShowPreviewWindow(PJ_TRUE);
#endif

    SetSoundDevice(g_audio_output);

    // make_call 3
    pjsua_call_setting call_setting;
    pjsua_call_setting_default(&call_setting);
    call_setting.flag = 0;
    call_setting.vid_cnt=hasVideo ? 1 : 0;
    // make_call 4
    call_user_data *user_data = new call_user_data(PJSUA_INVALID_ID);
    user_data->commands = "";
    // make_call 6
    pjsua_call_id call_id;

    pj_status_t status = pjsua_call_make_call(
        acc_id,
        &pj_uri,
        &call_setting,
        user_data,
        NULL,
        &call_id);
    if (status == PJ_SUCCESS) {
        *retStatus  = 0;
        return S_OK;
    } else {
        *retStatus = -1;
        return S_FALSE;
    }
}
