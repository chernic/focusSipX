// FocusSip.cpp : CFocusSip 的实现
#include "stdafx.h"
// ABChernic
#include <pj/types.h>
#include <pjsua-lib/pjsua.h>
#include "focusua_typedef.h"
#include "focusua_common.h"

//////   Fire_OnRegState            (INT acc_index)
//////   Fire_OnBuddyState          (INT buddy_index)
//////   Fire_OnCallState           (INT call_index, Focusip_Call_Info * pInfo)
//////   Fire_OnIncomingPager       (INT call_index, BSTR fromUri, BSTR toURI, BSTR pagerText)
//////   Fire_OnTypingIndication    (INT call_index, BSTR fromUri, BSTR toURI, INT isTyping)
//////   Fire_OnIncomingCall        (INT call_index)
/// include #include "FocusSip_CP.h"
#include "FocusSip.h"
/////////////////////////////////////////////////////////////////////////////
// 要时刻检测SDL窗口关闭, 增加回调函数来响应并挂断通话

/////////////////////////////////////////////////////////////////////////////
/// FROM PJSUA_APP_C
static focusua_app_cfg_t    app_cfg;
static pj_bool_t            pj_inited  = PJ_FALSE;

static pj_caching_pool      cli_cp;
static pj_bool_t            cli_cp_inited = PJ_FALSE;
static pj_cli_t             *cli = NULL;
static pj_cli_sess          *cli_cons_sess = NULL;
static pj_cli_front_end     *telnet_front_end = NULL;
/// CFocusSip
static CFocusSip            *CFocusSip_Instance;

/////////////////////////////////////////////////////////////////////////////
/// FROM PJSUA_APP_C

// 这里ID 是否需要改一下(已经改了
// {04BA8132-E099-44e6-A668-E1B526517A9D}       // 04-
static const GUID IID_Focusip_Sip_Uri =
{ 0x04ba8132, 0xe099, 0x44e6, { 0xa6, 0x68, 0xe1, 0xb5, 0x26, 0x51, 0x7a, 0x9d } };

// {05163613-C3DB-4a72-B98A-E4BCC56DB163}       // 05-
static const GUID IID_Focusip_Cred_Info =
{ 0x05163613, 0xc3db, 0x4a72, { 0xb9, 0x8a, 0xe4, 0xbc, 0xc5, 0x6d, 0xb1, 0x63 } };

// {062143D1-58A4-4044-8A25-C13D460D4D5D}       // 06-
static const GUID IID_Focusip_Acc_Info =
{ 0x062143d1, 0x58a4, 0x4044, { 0x8a, 0x25, 0xc1, 0x3d, 0x46, 0xd, 0x4d, 0x5d } };

// {07076348-B31B-4844-8BF1-FC8DEF3BC121}       // 07-
static const GUID IID_Focusip_Call_Info =
{ 0x07076348, 0xb31b, 0x4844, { 0x8b, 0xf1, 0xfc, 0x8d, 0xef, 0x3b, 0xc1, 0x21 } };



// {08CC26A6-29F4-4006-B906-D3F0C115E487}       // 08-
static const GUID IID_Focusip_Buddy_Info =
{ 0x08cc26a6, 0x29f4, 0x4006, { 0xb9, 0x6, 0xd3, 0xf0, 0xc1, 0x15, 0xe4, 0x87 } };

// {096B030B-EB36-4cd8-A2D9-FA3C03267FF2}       // 09-
static const GUID IID_Focusip_Conf_Port_Info =
{ 0x096b030b, 0xeb36, 0x4cd8, { 0xa2, 0xd9, 0xfa, 0x3c, 0x3, 0x26, 0x7f, 0xf2 } };



// {10EB7884-24E1-4768-AF24-528CBB905E1C}       // 10-
static const GUID IID_Focusip_Reg_Info =
{ 0x10eb7884, 0x24e1, 0x4768, { 0xaf, 0x24, 0x52, 0x8c, 0xbb, 0x90, 0x5e, 0x1c } };

// {11908C68-BA3B-4e04-87FA-D1DF6B8DA88E}       // 11
static const GUID IID_Focusip_TI_Info = 
{ 0x11908c68, 0xba3b, 0x4e04, { 0x87, 0xfa, 0xd1, 0xdf, 0x6b, 0x8d, 0xa8, 0x8e } };



// {20390D89-4081-432c-BEEA-D22A8CDB1958}       // 20
static const GUID IID_Focusip_Acc_Config =
{ 0x20390d89, 0x4081, 0x432c, { 0xbe, 0xea, 0xd2, 0x2a, 0x8c, 0xdb, 0x19, 0x58 } };

// {210EF560-3388-4855-AE15-F2824B0FFF28}       // 21
static const GUID IID_Focusip_Config =
{ 0x210ef560, 0x3388, 0x4855, { 0xae, 0x15, 0xf2, 0x82, 0x4b, 0xf, 0xff, 0x28 } };



#define SA_SIZE(lbound,ubound)  (ubound-lbound)

static void on_call_media_state(pjsua_call_id call_id);

static void on_reg_state2(
        pjsua_acc_id acc_id,
        pjsua_reg_info *info);

static void on_call_state(
        pjsua_call_id call_id,
        pjsip_event *e);

static void on_dtmf_digit(
        pjsua_call_id call_id,
        int digit);

static void on_call_tsx_state(
        pjsua_call_id call_id,
        pjsip_transaction *tsx,
        pjsip_event *e);

static void on_incoming_call(
        pjsua_acc_id acc_id,
        pjsua_call_id call_id,
        pjsip_rx_data *rdata);

static void on_nat_detect(
        const pj_stun_nat_detect_result *res);

static void on_buddy_state(
        pjsua_buddy_id buddy_id);

static void on_pager2(
        pjsua_call_id call_id,
        const pj_str_t *from,
        const pj_str_t *to,
        const pj_str_t *contact,
        const pj_str_t *mime_type,
        const pj_str_t *body,
        pjsip_rx_data *rdata,
        pjsua_acc_id acc_id);

static void on_pager_status2(
        pjsua_call_id call_id,
        const pj_str_t *to,
        const pj_str_t *body,
        void *user_data,
        pjsip_status_code status,
        const pj_str_t *reason,
        pjsip_tx_data *tdata,
        pjsip_rx_data *rdata,
        pjsua_acc_id acc_id);

static void on_call_transfer_request2(
        pjsua_call_id call_id,
        const pj_str_t *dst,
        pjsip_status_code *code,
        pjsua_call_setting *opt);

static void on_call_transfer_status(
        pjsua_call_id call_id,
        int status_code,
        const pj_str_t *status_text,
        pj_bool_t final,
        pj_bool_t *p_cont);

static void on_call_replace_request2(
        pjsua_call_id call_id,
        pjsip_rx_data *rdata,
        int *st_code,
        pj_str_t *st_text,
        pjsua_call_setting *opt);

static void on_call_replaced(
        pjsua_call_id old_call_id,
        pjsua_call_id new_call_id);

static void on_mwi_info(
        pjsua_acc_id acc_id,
        pjsua_mwi_info *mwi_info);

static void on_stream_created(
        pjsua_call_id call_id,
        pjmedia_stream *strm,
        unsigned stream_idx,
        pjmedia_port **p_port);

static void on_stream_created2(
        pjsua_call_id call_id,
        pjsua_on_stream_created_param *param);

static void on_stream_destroyed(
        pjsua_call_id call_id,
        pjmedia_stream *strm,
        unsigned stream_idx);

CFocusSip::CFocusSip(){
    CFocusSip_Instance = this;
}

/////////////////////////////////////////////////////////////////////////////
/** string methods **/
static pj_str_t Pj_str(pj_pool_t *pool, Fs__Str s){
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

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
static void AccConfig2accconfig     (pj_pool_t *pool,         Focusip_Acc_Config *c1, pjsua_acc_config *c2){
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
static HRESULT accconfig2AccConfig  (pjsua_acc_config *c1,    Focusip_Acc_Config *c2){
    //unsigned i;

    //pj_memset(c2, 0, sizeof(Focusip_Acc_Config));
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
                                         IID_Focusip_Cred_Info,
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
///
static HRESULT Config2config        (pj_pool_t *pool,         Focusip_Config *c1,     pjsua_config *c2){
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
        Focusip_Acc_Config acc_config;
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
static HRESULT config2Config        (pjsua_config *c1,        Focusip_Config *c2){
    //unsigned i;
    //HRESULT hr;

    pj_memset(c2, 0, sizeof(Focusip_Config));
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
                                 IID_Focusip_Acc_Config,
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
    Focusip_Acc_Config acc_cfg;

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
////
static void reginfo2RegInfo         (pjsua_reg_info *c1,      Focusip_Reg_Info *c2){
}
///
static void callinfo2CallInfo       (pjsua_call_info *c1,     Focusip_Call_Info *c2){
    pj_memset(c2, 0, sizeof(Focusip_Call_Info));

    pjsua_call_id callIndex =  c1->id;
    c2->index               =  callIndex;
    c2->active              =  pjsua_call_is_active(callIndex);
    c2->is_uac              = (c1->role == PJSIP_ROLE_UAC);
    Cp(c2->local_info,        &c1->local_info);
    Cp(c2->remote_info,       &c1->remote_info);
    c2->state               = (Focusip_Call_State)c1->state;
    Cp(c2->state_text,        &c1->state_text);
    c2->connect_duration    =  c1->connect_duration.sec;
    c2->total_duration      =  c1->total_duration.sec;
    c2->last_status         =  c1->last_status;
    Cp(c2->last_status_text,  &c1->last_status_text);
    c2->has_media           =  pjsua_call_has_media(callIndex);
    c2->conf_slot           =  c1->conf_slot;
}
static void accinfo2AccInfo         (pjsua_acc_info *info1,   Focusip_Acc_Info *info2){
    pj_memset(info2, 0, sizeof(Focusip_Acc_Info));
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
static void buddyinfo2BuddyInfo     (pjsua_buddy_info *info1, Focusip_Buddy_Info *info2){
    pj_memset(info2, 0, sizeof(Focusip_Buddy_Info));
    /*
    info2->index = info1->index;
    info2->is_valid = info1->is_valid;
    Cp(info2->name, &info1->name);
    Cp(info2->display, &info1->display_name);
    Cp(info2->host, &info1->host);
    info2->port = info1->port;
    Cp(info2->uri, &info1->uri);
    info2->status = (Focusip_Buddy_State)info1->status;
    Cp(info2->status_text, &info1->status_text);
    info2->monitor = info1->monitor;
    */
}



///////////////////////////////////////////////////////////////////////////
// Fuction Fuction Fuction Fuction Fuction Fuction Fuction Fuction Fuction
///////////////////////////////////////////////////////////////////////////
// 001 // (OK)
STDMETHODIMP CFocusSip::aboutbox(
        /* [retval][out] */                 Fs__Str                 *ret)
{
    * ret = str2bstr("www.focustar.net", 0);
    return S_OK;
}
// 002 // (OK) pjsua
STDMETHODIMP CFocusSip::app_construct(
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    if(pj_inited){
        *retStatus = PJ_EEXISTS;
        return S_FALSE;
    }

    // pj create
    pj_status_t             status;
    pjsua_config            ua_cfg;
    pjsua_media_config      media_cfg;
    pjsua_transport_config  tcfg;

    // Must create pjsua before anything else!
    status = pjsua_create();
    if (status != PJ_SUCCESS){
        *retStatus = EU_PJSUA_CREATE_FAILED; // 170002
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
    
    ua_cfg.cb.on_call_state             =   &on_call_state;             // 01
    ua_cfg.cb.on_incoming_call          =   &on_incoming_call;          // 02
    ua_cfg.cb.on_call_tsx_state         =   &on_call_tsx_state;         // 03
    ua_cfg.cb.on_call_media_state       =   &on_call_media_state;       // 04

    ua_cfg.cb.on_stream_created         =   &on_stream_created;         // 06
    ua_cfg.cb.on_stream_created2        =   &on_stream_created2;        // 07
    ua_cfg.cb.on_stream_destroyed       =   &on_stream_destroyed;       // 08

    ua_cfg.cb.on_dtmf_digit             =   &on_dtmf_digit;             // 09
    ua_cfg.cb.on_call_transfer_status   =   &on_call_transfer_status;   // 11
    ua_cfg.cb.on_call_transfer_request2 =   &on_call_transfer_request2; // 12
    ua_cfg.cb.on_call_replace_request2  =   &on_call_replace_request2;  // 14
    ua_cfg.cb.on_call_replaced          =   &on_call_replaced;          // 15

    ua_cfg.cb.on_reg_state2             =   &on_reg_state2;             // 21
    ua_cfg.cb.on_buddy_state            =   &on_buddy_state;            // 24
    ua_cfg.cb.on_pager2                 =   &on_pager2;                 // 27
    ua_cfg.cb.on_pager_status2          =   &on_pager_status2;          // 29
    ua_cfg.cb.on_nat_detect             =   &on_nat_detect;             // 32

    ua_cfg.cb.on_mwi_info               =   &on_mwi_info;               // 34

    // ua_cfg.on_stream_created

    ua_cfg.srtp_secure_signaling        =   0;

    if (accountSettings.enableSTUN && !accountSettings.stun.IsEmpty()) {
        ua_cfg.stun_srv_cnt=1;
        ua_cfg.stun_srv[0] = StrToPjStr( accountSettings.stun );
    }

    media_cfg.enable_ice = PJ_FALSE;
    media_cfg.no_vad = accountSettings.vad ? PJ_FALSE : PJ_TRUE;
    media_cfg.ec_tail_len = accountSettings.ec ? PJSUA_DEFAULT_EC_TAIL_LEN : 0;

    media_cfg.clock_rate=44100;
    media_cfg.channel_count=2;

    if (1) {
        pjsua_logging_config log_cfg; // = pjsua_var.log_cfg;
        pjsua_logging_config_default(&log_cfg);

		/* Set default logging settings */
		//pjsua_logging_config_default(&pjsua_var.log_cfg);/*配置log系统的参数*/

		//log_cfg.cb
//		log_cfg.msg_logging = PJ_TRUE;

//		log_cfg.level = 5;

		log_cfg.console_level = 4;
		log_cfg.log_filename =pj_str("abc.txt");

//		log_cfg.decor = PJ_LOG_HAS_SENDER | PJ_LOG_HAS_TIME | PJ_LOG_HAS_MICRO_SEC | PJ_LOG_HAS_NEWLINE | PJ_LOG_HAS_SPACE;
//#if defined(PJ_WIN32) && PJ_WIN32 != 0
//		log_cfg.decor |= PJ_LOG_HAS_COLOR;
//#endif
        status = pjsua_init(&ua_cfg, &log_cfg, &media_cfg);

		pj_log_init();
		PJ_LOG(4, ( "FocusSip.cpp", "log_cfg.level = %d",log_cfg.level) );

    } else {
        status = pjsua_init(&ua_cfg, NULL, &media_cfg);
    }
    if (status != PJ_SUCCESS) {
        pjsua_destroy();
        *retStatus = EU_PJSUA_INIT_FAILED; // 170003
        return S_FALSE;
    }

    // pageContacts->isSubscribed = FALSE;
	// CreateResizePreviewWindow
    // player_id = PJSUA_INVALID_ID;
    // check updates

    // Start pjsua
    status = pjsua_start();
    if (status != PJ_SUCCESS) {
        pjsua_destroy();
        *retStatus = EU_PJSUA_START_FAILED; // 170004
        return S_FALSE;
    }

    pj_inited = PJ_TRUE;

    // Set snd devices
    UpdateSoundDevicesIds();

    //Set aud codecs prio
    if (accountSettings.audioCodecs.IsEmpty()){
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

    pjsua_transport_config_default(&tcfg);
    tcfg.public_addr = StrToPjStr( accountSettings.account.publicAddr );

    if (accountSettings.sourcePort) {
      tcfg.port=accountSettings.sourcePort;
      status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &tcfg, &transport_udp);
      if (status != PJ_SUCCESS) {
        tcfg.port=0;
        pjsua_transport_create(PJSIP_TRANSPORT_UDP, &tcfg, &transport_udp);
      }
      if (MACRO_ENABLE_LOCAL_ACCOUNT) {
        if (accountSettings.sourcePort == 5060 ) {
          transport_udp_local = transport_udp;
        } else {
          tcfg.port=5060;
          status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &tcfg, &transport_udp_local);
          if (status != PJ_SUCCESS) {
            transport_udp_local = transport_udp;
          }
        }
      }
    } else {
      if (MACRO_ENABLE_LOCAL_ACCOUNT) {
        tcfg.port=5060;
        status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &tcfg, &transport_udp_local);
        if (status != PJ_SUCCESS) {
          transport_udp_local = -1;
        }
      }
      tcfg.port=0;
      pjsua_transport_create(PJSIP_TRANSPORT_UDP, &tcfg, &transport_udp);
      if (transport_udp_local == -1) {
        transport_udp_local = transport_udp;
      }
    }


    tcfg.port = MACRO_ENABLE_LOCAL_ACCOUNT ? 5060 : 0;
    status = pjsua_transport_create(PJSIP_TRANSPORT_TCP, &tcfg, &transport_tcp);
    if (status != PJ_SUCCESS && tcfg.port) {
        tcfg.port=0;
        pjsua_transport_create(PJSIP_TRANSPORT_TCP, &tcfg, &transport_tcp);
    }


    tcfg.port = MACRO_ENABLE_LOCAL_ACCOUNT ? 5061 : 0;
    status = pjsua_transport_create(PJSIP_TRANSPORT_TLS, &tcfg, &transport_tls);
    if (status != PJ_SUCCESS && tcfg.port) {
        tcfg.port=0;
        pjsua_transport_create(PJSIP_TRANSPORT_TLS, &tcfg, &transport_tls);
    }


    if (accountSettings.usersDirectory.Find(_T("%s"))==-1 && accountSettings.usersDirectory.Find(_T("{"))==-1) {
        /// UsersDirectoryLoad();
    }

    g_acc_id = PJSUA_INVALID_ID;
    g_acc_id_local = PJSUA_INVALID_ID;


    *retStatus = PJ_SUCCESS;

    return S_OK;
}
// 003 // (OK) pjsua
STDMETHODIMP CFocusSip::app_destroy(
        /* [retval][out] */                 Fs_Stat                 *retStatus){
    if(!pj_inited){
        *retStatus = EU_PJSUA_UN_CONSTRUCT;
        return S_FALSE;
    }

    pj_inited = PJ_FALSE;

    pj_status_t state = pjsua_destroy();
    *retStatus = state;
    return S_OK;
}
// 004 // (OK) pjsua
STDMETHODIMP CFocusSip::app_create(
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    if(!pj_inited){
        *retStatus = EU_PJSUA_UN_CONSTRUCT;
        return S_FALSE;
    }
    //pj_started = PJ_FALSE;

    //*retStatus = app_create();

    *retStatus = -1;
    return S_FALSE;
}
// 005 // (OK) pjsua
STDMETHODIMP CFocusSip::app_init(
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    if(!pj_inited){
        *retStatus = EU_PJSUA_UN_CONSTRUCT;
        return S_FALSE;
    }
    // pj_started = PJ_FALSE;

    // *retStatus = pjsua_init();

    *retStatus = -1;
    return S_FALSE;
}
// 006 // (OK) pjsua
STDMETHODIMP CFocusSip::app_start(
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    if(!pj_inited){
        *retStatus = EU_PJSUA_UN_CONSTRUCT;
        return S_FALSE;
    }
    //pj_started = PJ_FALSE;

    pj_status_t state = pjsua_start();
    *retStatus = state;
    return S_OK;
}
// 007 // (OK)
STDMETHODIMP CFocusSip::app_default_config(
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    // TODO: 在此添加实现代码
    *retStatus = 7;
    return S_OK;
}
// 008 // (OK)
STDMETHODIMP CFocusSip::app_test_config(
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    // TODO: 在此添加实现代码
    *retStatus = 8;
    return S_OK;
}
// 101 // (OK) pjsua
STDMETHODIMP CFocusSip::acc_get_count(
        /* [retval][out] */                 Fs_Numb                 *pCount)
{
    unsigned state = pjsua_acc_get_count();

    *pCount = state;

    return S_OK;
}
// 102  // pjsua(out NOT OK)
STDMETHODIMP CFocusSip::acc_get_info(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [out] */                         Focusip_Acc_Info        *pCallInfo,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    pjsua_acc_info info;
    pj_status_t state = pjsua_acc_get_info(callIndex, &info);
    *retStatus = state;
    return S_OK;
}
// 105  // (OK) pjsua
STDMETHODIMP CFocusSip::acc_set_online_status(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [in] */                          Fs_Numb                 isOnline,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    pj_status_t state = pjsua_acc_set_online_status(callIndex, isOnline);
    *retStatus = state;
    return S_OK;
}
// 106  // (OK) pjsua
STDMETHODIMP CFocusSip::acc_set_registration(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [in] */                          Fs_Numb                 regToBeActive,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    pj_status_t state = pjsua_acc_set_registration(callIndex, regToBeActive);
    *retStatus = state;
    return S_OK;
}
// 103
STDMETHODIMP CFocusSip::acc_add_short(
        /* [in] */                          Focusip_Acc_Config      *pAccConfig,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    // TODO: 在此添加实现代码
    *retStatus = 12;
    return S_OK;
}
// 104
STDMETHODIMP CFocusSip::acc_add(
        /* [in] */                          // int                  _00accountId,
        /* [in] */                          Fs__Str                 _01label,
        /* [in] */                          Fs__Str                 _02server,
        /* [in] */                          Fs__Str                 _03proxy,
        /* [in] */                          Fs__Str                 _04username,
        /* [in] */                          Fs__Str                 _05domain,
        /* [in] */                          Fs_Numb                 _06port,
        /* [in] */                          Fs__Str                 _07authID,
        /* [in] */                          Fs__Str                 _08password,
        /* [in] */                          Fs_Numb                 _09rememberPassword,
        /* [in] */                          Fs__Str                 _10displayName,
        /* [in] */                          Fs__Str                 _11voicemailNumber,
        /* [in] */                          Fs__Str                 _12srtp,
        /* [in] */                          Fs__Str                 _13transport,
        /* [in] */                          Fs__Str                 _14publicAddr,
        /* [in] */                          Fs_Numb                 _15publish,
        /* [in] */                          Fs_Numb                 _16ice,
        /* [in] */                          Fs_Numb                 _17allowRewrite,
        /* [in] */                          Fs_Numb                 _18disableSessionTimer,
        /* [out] */                         Fs_Stat                 *retStatus,
        /* [retval][out] */                 Fs_Numb                 *retAccIndex)
{
    if(!pj_inited){
        *retStatus   = EU_PJSUA_UN_CONSTRUCT;
        *retAccIndex = EU_PJSUA_UN_CONSTRUCT;
        return S_FALSE;
    }

    ///////////////////////////////////////////////////
    // 20180330 Chernic增加异常检查
    int current_count =  pjsua_acc_get_count();
    if( current_count >= PJSUA_MAX_ACC){
        *retAccIndex = PJSUA_INVALID_ID;
        *retStatus   = EU_ACC_FULL;
        return S_OK;
    }
    ///////////////////////////////////////////////////


    //accountSettings.accountId                   = _00accountId;
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


    // ABChernic : 20180319 去掉参数
    /*
    if (!accountSettings.accountId) {
        return S_FALSE;
    }
    */
    // ABChernic : 20180319

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
    // 02 default: 192.168.1.250:15020
    CString regURI;
    if (accountSettings.account.server.IsEmpty()) {
        acc_cfg.register_on_acc_add = PJ_FALSE;
    } else {
        regURI.Format(_T("sip:%s"),accountSettings.account.server);
        AddTransportSuffix(regURI);
        acc_cfg.reg_uri = StrToPjStr( regURI );
    }
    //-- port knocker

    g_acc_id = accountSettings.accountId;

    pj_status_t status = pjsua_acc_add(&acc_cfg, PJ_TRUE, &g_acc_id); // pjsua_acc_id account;
    if (status == PJ_SUCCESS) {
        *retAccIndex  = g_acc_id;
        *retStatus    = status;
        return S_OK;
    } else {
        // 由于javascript只能有一个返回值, 所以这里暂时使用 retAccIndex 来返回错误代码
        *retAccIndex = status;              //PJSUA_INVALID_ID
        *retStatus   = status;
        return S_FALSE;
    }
}
// 106
STDMETHODIMP CFocusSip::acc_del(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    *retStatus = pjsua_acc_del(callIndex);
    return S_OK;
}
// 201
STDMETHODIMP CFocusSip::call_get_max_count(
        /* [retval][out] */                 Fs_Numb                 *retCount)
{
    unsigned nCount = pjsua_call_get_max_count();

    *retCount = nCount;
    return S_OK;
}
// 202
STDMETHODIMP CFocusSip::call_get_count(
        /* [retval][out] */                 Fs_Numb                 *retCount)
{
    unsigned nCount = pjsua_call_get_count();

    *retCount = nCount;
    return S_OK;
}
// 203(via pjsua OK)
STDMETHODIMP CFocusSip::call_is_active(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [retval][out] */                 Fs_Bool                 *retIsActive)
{
    pj_bool_t bIsRet = pjsua_call_is_active(callIndex);

   *retIsActive = bIsRet;
    return S_OK;
}
// 204(via pjsua OK)
STDMETHODIMP CFocusSip::call_has_media(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [retval][out] */                 Fs_Bool                 *retHasMedia)
{
    pj_bool_t bIsRet = PJ_FALSE;

    PJ_USE_EXCEPTION;  // declare local exception stack.

    PJ_TRY {
        bIsRet = pjsua_call_has_media(callIndex);
    }
    PJ_CATCH_ANY {
        return S_FALSE;
    }
    PJ_END;

    *retHasMedia = bIsRet;
    return S_OK;
}
// 205
STDMETHODIMP CFocusSip::call_get_info(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [out] */                         Focusip_Call_Info       *pCallInfo,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    *retStatus = 205;
    return S_OK;
}
////////////////////////////////////////////////////
// 211
STDMETHODIMP CFocusSip::call_make_call_short(
        /* [in] */                          Fs__Str                 Uri,
        /* [in] */                          Fs_Bool                 hasVideo,
        /* [retval][out] */                 Fs_Numb                 *RetCallID)
{
  //BSTR _Uri       = Uri;
  //BSTR _Para      = str2bstr("", 0);
  //BSTR _Name      = str2bstr("", 0);
  //int _hasVideo   = 1;
  //BSTR _pCallId   = str2bstr("-1", 0);
  //Fs_Stat  pRet = 0;

    BSTR _21callId              = str2bstr("", 0);
    BSTR _22numb                = str2bstr("", 0);
    BSTR _23number              = Uri;
    BSTR _24numberParameters    = str2bstr("", 0);
    BSTR _25name                = str2bstr("", 0);

    int _hasVideo               = hasVideo;
    int _RetCallID                  = 0;

    int ret = call_make_call(_21callId, _22numb, _23number, _24numberParameters, _25name, _hasVideo, &_RetCallID);

    if (ret == S_OK) {
        *RetCallID  = _RetCallID;
        return S_OK;
    } else {
        *RetCallID = -1;
        return S_FALSE;
    }
}
// 212
STDMETHODIMP CFocusSip::call_make_call(
        /* [in] */                          Fs__Str                 _1callIndex,
        /* [in] */                          Fs__Str                 _2numb,
        /* [in] */                          Fs__Str                 _3number,
        /* [in] */                          Fs__Str                 _4Para,
        /* [in] */                          Fs__Str                 _5name,
        /* [in] */                          Fs_Numb                 hasVideo,
        /* [retval][out] */                 Fs_Numb                 *RetCallID)
{
    bool singleMode = true;

    // make_call 1
    pjsua_acc_id acc_id = PJSUA_INVALID_ID;                                 // 1 acc_id
    // make_call 2
    pj_str_t pj_uri     = pj_str("");                                       // 2 pj_uri
    if (!SelectSIPAccount(_3number,acc_id,pj_uri)) {
        // Account dummy;
        // *pStatus = accountSettings.AccountLoad(1,&dummy) ? PJSIP_EAUTHACCDISABLED : PJSIP_EAUTHACCNOTFOUND;
        // return PJSUA_INVALID_ID;
        return S_FALSE;
    }

    if (singleMode) {
        call_hangup_all_noincoming();
    }

    // #ifdef _GLOBAL_VIDEO
    //setComplexFrameRect();
    ResetPJmediaData();

    int overlay_mode = IN_NAVBAR_L;
    //int overlay_mode = IN_NAVBAR_R;
    // int overlay_mode = IN_FOOTER_L;
    // int overlay_mode = IN_FOOTER_R;

    fswin_init_overlay_mode(overlay_mode);
    InitPreviwWindow();

    ShowPreviwWindow( PJ_FALSE );
    ShowStreamWindow( PJ_FALSE );
    // #endif

    SetSoundDevice(g_audio_output);

    // make_call 3
    pjsua_call_setting call_setting;
    pjsua_call_setting_default(&call_setting);                              // 3 call_setting
    call_setting.flag = 0;
    call_setting.vid_cnt=hasVideo ? 1 : 0;
    // make_call 4
    call_user_data *user_data = new call_user_data(PJSUA_INVALID_ID);       // 4 user_data
    user_data->commands = "";
    // make_call 6
    pjsua_call_id call_id = PJSUA_INVALID_ID;                               // 6

    pj_status_t status = pjsua_call_make_call(
        acc_id,
        &pj_uri,
        &call_setting,
        user_data,
        NULL,
        &call_id);
    if (status == PJ_SUCCESS) {
        *RetCallID = call_id;
        return S_OK;
    } else {
        *RetCallID = -1;
        return S_FALSE;
    }
}
// 213
STDMETHODIMP CFocusSip::call_answer(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [in] */                          Fs_Numb                 statusCode,
                                            Fs_Stat                 *retStatus)
{
    pj_status_t status = pjsua_call_answer(callIndex, statusCode, NULL, NULL);

    // pjsua_call_answer(call_id, 180, NULL, NULL);
    // pjsua_call_answer2(call_id, &call_setting, 200, NULL, NULL)

    *retStatus = status;
    return S_OK;
}
// 214
STDMETHODIMP CFocusSip::call_hangup(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [in] */                          Fs_Numb                 code,
        /* [in] */                          Fs__Str                 reason,
                                            Fs_Stat                 *retStatus)
{
    pj_str_t str_reason = pj_str("");

    pj_status_t status = pjsua_call_hangup(callIndex, code, NULL, NULL);

    *retStatus = status;
    return S_OK;
}
// 215
STDMETHODIMP CFocusSip::call_hangup_all(void)
{
    pjsua_call_hangup_all();

    return S_OK;
}
// 216
STDMETHODIMP CFocusSip::call_set_hold(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    if (callIndex != PJSUA_INVALID_ID) {
        *retStatus =  pjsua_call_set_hold(callIndex, NULL);

    } else {
        /// PJ_LOG(3,("video-agent-app", "No current call"));

        *retStatus = EINVAL;
    }
    return S_OK;
}
// 217
STDMETHODIMP CFocusSip::call_release_hold(
        /* [in] */                          Fs_Numb                 callIndex,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    if (callIndex != PJSUA_INVALID_ID) {
        /// re-INVITE
        call_opt.flag |= PJSUA_CALL_UNHOLD;
        *retStatus = pjsua_call_reinvite2(callIndex, &call_opt, NULL);

    } else {
        /// PJ_LOG(3,("video-agent-app", "No current call"));
        *retStatus = EINVAL;
    }
    return S_OK;
}
/*
// 218
//STDMETHODIMP CFocusSip::call_xfer(void){
//
//    return S_OK;
// }
*/
// 301
STDMETHODIMP CFocusSip::vid_win_set_overlay_mode(
        /* [in] */                          Fs_Numb                 mode,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    pj_status_t status = ShiftPreviwWindows(mode);
    if(status == PJ_SUCCESS)
    {
        *retStatus  = PJ_SUCCESS;
        return S_OK;
    }else
    {
        *retStatus = -1;
        return S_FALSE;
    }
    return S_FALSE;
}
STDMETHODIMP CFocusSip::vid_win_resize(
        /* [in] */                          Fs_Doub                 present,
        /* [retval][out] */                 Fs_Stat                 *retStatus)
{
    pj_status_t status = ResizePreviwWindows(present);
    if(status == PJ_SUCCESS)
    {
        *retStatus  = PJ_SUCCESS;
        return S_OK;
    }else
    {
        *retStatus = -1;
        return S_FALSE;
    }
    return S_FALSE;
}


/////////////////////////////////////////////////////////////////////////////
// Callback Callback Callback Callback Callback Callback Callback Callback
/////////////////////////////////////////////////////////////////////////////

static void on_call_state(                          // FocusSip : Callback 01 pjsua.h
        pjsua_call_id call_id,
        pjsip_event *e)
{
    pjsua_call_info call_info;
    pjsua_call_get_info(call_id, &call_info);

    // App Actions
    Focusip_Call_Info *Call_Info = new Focusip_Call_Info;
    callinfo2CallInfo(&call_info, Call_Info);
    // 假如hangup, 把本地摄像头视频也关掉
    // ABChernic : 暂时有问题?
    CFocusSip_Instance->Fire_OnCallState(call_id, Call_Info);
}



//
static void on_incoming_call(                       // FocusSip : Callback 02 pjsua.h
        pjsua_acc_id acc_id,
        pjsua_call_id call_id,
        pjsip_rx_data *rdata)
{
    CFocusSip_Instance->Fire_OnIncomingCall(call_id);
}
//
static void on_call_tsx_state(                      // FocusSip : Callback 03 pjsua.h
        pjsua_call_id call_id,
        pjsip_transaction *tsx,
        pjsip_event *e){
}
//
static void on_call_media_state(                    // FocusSip : Callback 04 pjsua.h
        /* [in] */  pjsua_call_id   callIndex)
{

    pjsua_call_info *call_info = new pjsua_call_info();

    if (pjsua_call_get_info(callIndex, call_info) != PJ_SUCCESS || call_info->state == PJSIP_INV_STATE_NULL) {
        return;
    }

    //#ifdef _GLOBAL_VIDEO
    MakeStreamWindow( );

    ShowPreviwWindow( PJ_TRUE );
    ShowStreamWindow( PJ_TRUE );
    //#endif
}
//
static void on_stream_created(                      // FocusSip : Callback 06 pjsua.h XXXXXXXXXXXXXXXXX
        pjsua_call_id call_id,
        pjmedia_stream *strm,
        unsigned stream_idx,
        pjmedia_port **p_port)
{
    int callback = 6;
	(void * ) call_id;
}
//
static void on_stream_created2(                     // FocusSip : Callback 07 pjsua.h XXXXXXXXXXXXXXXXX
        pjsua_call_id call_id,
        pjsua_on_stream_created_param *param)
{
    int callback = 7;

	(void * ) call_id;
}
//
static void on_stream_destroyed(                    // FocusSip : Callback 08 pjsua.h XXXXXXXXXXXXXXXXX
        pjsua_call_id call_id,
        pjmedia_stream *strm,
        unsigned stream_idx)
{
    int callback = 8;
	(void * ) call_id;
}
//
static void on_dtmf_digit(
        pjsua_call_id call_id, int digit)           // FocusSip : Callback 09 pjsua.h
{
    //char signal[2];
    //signal[0] = digit;
    //signal[1] = 0;
    //call_play_digit(-1, signal);
}
//
static void on_call_transfer_request2(              // FocusSip : Callback 11 pjsua.h
        pjsua_call_id call_id,
        const pj_str_t *dst,
        pjsip_status_code *code,
        pjsua_call_setting *opt)
{
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
//
static void on_call_transfer_status(                // FocusSip : Callback 12 pjsua.h
        pjsua_call_id call_id,
        int status_code,
        const pj_str_t *status_text,
        pj_bool_t final,
        pj_bool_t *p_cont)
{
}
//
static void on_call_replace_request2(               // FocusSip : Callback 14 pjsua.h
        pjsua_call_id call_id,
        pjsip_rx_data *rdata,
        int *st_code, pj_str_t *st_text,
        pjsua_call_setting *opt)
{
    pjsua_call_info call_info;
    if (pjsua_call_get_info(call_id, &call_info) == PJ_SUCCESS) {
        if (!call_info.rem_vid_cnt) {
            opt->vid_cnt = 0;
        }
    } else {
        opt->vid_cnt = 0;
    }
}
//
static void on_call_replaced(                       // FocusSip : Callback 15 pjsua.h
        pjsua_call_id old_call_id,
        pjsua_call_id new_call_id)
{
}
//
static void on_reg_state2(                          // FocusSip : Callback 21 pjsua.h
        pjsua_acc_id acc_id,
        pjsua_reg_info *info)
{
    if( info->cbparam->code ){
        // log
    }

	pjsua_reg_info rinfo;
	Focusip_Reg_Info *Reg_Info = new Focusip_Reg_Info;
	reginfo2RegInfo(&rinfo, Reg_Info);

    // ABChernic : 暂时有问题?
    CFocusSip_Instance->Fire_OnRegState(acc_id);
    return;
}
//
static void on_buddy_state(                         // FocusSip : Callback 24 pjsua.h
        pjsua_buddy_id buddy_id)
{
    CFocusSip_Instance->Fire_OnBuddyState(buddy_id);
}
//
static void on_pager2(                              // FocusSip : Callback 27 pjsua.h
        pjsua_call_id call_id,
        const pj_str_t *from,
        const pj_str_t *to,
        const pj_str_t *contact,
        const pj_str_t *mime_type,
        const pj_str_t *body,
        pjsip_rx_data *rdata,
        pjsua_acc_id acc_id)
{
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
//
static void on_pager_status2(                       // FocusSip : Callback 29 pjsua.h
        pjsua_call_id call_id,
        const pj_str_t *to,
        const pj_str_t *body,
        void *user_data,
        pjsip_status_code status,
        const pj_str_t *reason,
        pjsip_tx_data *tdata,
        pjsip_rx_data *rdata,
        pjsua_acc_id acc_id)
{
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
//
static void on_nat_detect(                          // FocusSip : Callback 32 pjsua.h
        const pj_stun_nat_detect_result *res){
}
//
static void on_mwi_info(                            // FocusSip : Callback 34 pjsua.h
        pjsua_acc_id acc_id, pjsua_mwi_info *mwi_info){
}
