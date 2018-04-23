// App.cpp : Implementation of CApp
#include "stdafx.h"
#include <pj/types.h>
#include <pjsua-lib/pjsua.h>
#include "activex_video_agent.h"
#include "video-agent-app-head.h"
#include "video-agent-app.h"
#include "pjsua_app_common.h"

/////////////////////////////////////////////////////////////////////////////
// FROM PJSUA_APP_C
static pjsua_app_cfg_t app_cfg;
pj_str_t uri_arg;
pj_bool_t app_running = PJ_FALSE;


/////////////////////////////////////////////////////////////////////////////
// CApp

// {9CE3052A-7A32-4229-B31C-5E02E0667A77}
static const GUID IID_VideoAgent_Cred_Info =
{ 0x9ce3052a, 0x7a32, 0x4229, { 0xb3, 0x1c, 0x5e, 0x2, 0xe0, 0x66, 0x7a, 0x77 } };

// {7F6CFF0F-C5B3-41e8-B278-61CD584C1F34}
static const GUID IID_VideoAgent_Sip_Uri =
{ 0x7f6cff0f, 0xc5b3, 0x41e8, { 0xb2, 0x78, 0x61, 0xcd, 0x58, 0x4c, 0x1f, 0x34 } };

// {3B12B04F-6E48-46a7-B9E0-6C4BF1594A96}
static const GUID IID_VideoAgent_Acc_Config =
{ 0x3b12b04f, 0x6e48, 0x46a7, { 0xb9, 0xe0, 0x6c, 0x4b, 0xf1, 0x59, 0x4a, 0x96 } };

// {E4B6573D-CF5E-484d-863F-ADAD5947FBE4}
static const GUID IID_VideoAgent_Config =
{ 0xe4b6573d, 0xcf5e, 0x484d, { 0x86, 0x3f, 0xad, 0xad, 0x59, 0x47, 0xfb, 0xe4 } };

// {5043AC9E-A417-4f03-927E-D7AE52DDD064}
static const GUID IID_VideoAgent_Call_Info =
{ 0x5043ac9e, 0xa417, 0x4f03, { 0x92, 0x7e, 0xd7, 0xae, 0x52, 0xdd, 0xd0, 0x64 } };

// {2729F0BC-8A5E-4f3f-BC29-C1740A86393A}
static const GUID IID_VideoAgent_Buddy_Info =
{ 0x2729f0bc, 0x8a5e, 0x4f3f, { 0xbc, 0x29, 0xc1, 0x74, 0xa, 0x86, 0x39, 0x3a } };

// {8D345956-10B7-4450-8A06-A80D2F319EFD}
static const GUID IID_VideoAgent_Acc_Info =
{ 0x8d345956, 0x10b7, 0x4450, { 0x8a, 0x6, 0xa8, 0xd, 0x2f, 0x31, 0x9e, 0xfd } };

// {0D05907A-3E1F-4c92-9FD0-26CB6E1CC56A}
static const GUID IID_VideoAgent_Conf_Port_Info =
{ 0xd05907a, 0x3e1f, 0x4c92, { 0x9f, 0xd0, 0x26, 0xcb, 0x6e, 0x1c, 0xc5, 0x6a } };

#define SA_SIZE(lbound,ubound)  (ubound-lbound)

class Temp_Pool
{
public:
    Temp_Pool()
    {
        pool_ = pjsip_endpt_create_pool( pjsua_get_pjsip_endpt(), "activex_video_agent",
                     4000, 4000);
    }
    ~Temp_Pool()
    {
        pj_pool_release(pool_);
    }

    pj_pool_t *get_pool()
    {
        return pool_;
    }

private:
    pj_pool_t *pool_;
};


#include <atlhost.h>

typedef struct stComplexFrameRect
{
	RECT		rcMax;
	RECT		rcMin;
	RECT		rcComplex;
	RECT		rcHangup;

	PosSize_t	psMax;
	PosSize_t	psMin;
	PosSize_t	psPreviw;
	PosSize_t	psStream;
}stComplexFrameRect_t;

stComplexFrameRect_t ComplexFrameRect;

RECT setRECT(LONG left, LONG top, LONG right, LONG bottom)
{
	RECT rcX     = {0};
	rcX.left     = left;
	rcX.top      = top;
	rcX.right    = right;
	rcX.bottom   = bottom;
	return  rcX;
}
PosSize_t setPosSize(LONG left, LONG top, LONG wight, LONG height)
{
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

	cXset = cxMax/3;
	cYset = cxMax/3;

	// 这里是上下左右
	ComplexFrameRect.rcMax		= setRECT(0,        0, cxMax,	    cyMax);
	ComplexFrameRect.rcMin		= setRECT(0,        0, 0,				0);
	ComplexFrameRect.rcComplex	= setRECT(0,        0, cXset,	    cYset);
	ComplexFrameRect.rcHangup   = setRECT(0,    cYset, cXset,       cyMax);

	// 这里是左上角 大小
	ComplexFrameRect.psMin		= setPosSize(0,             0,     0,   0);
	ComplexFrameRect.psMax		= setPosSize(0,             0, cxMax,   cyMax);
	ComplexFrameRect.psPreviw   = setPosSize(0,             0, cXset,   cYset);


	ComplexFrameRect.psStream   = setPosSize(cXset/2,   0, cXset,   cYset);

	///ComplexFrameRect.psStream   = setPosSize(0,   0,			cxMax,   cyMax);


	// 化作右上角一点
	//ComplexFrameRect.psStream   = setPosSize(cxMax-1, cyMax-1, 1, 1);

}
/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////
/* app_config */
pj_status_t load_config(int argc,
            char **argv,
            pj_str_t *uri_arg)
{
    pj_status_t status = PJ_SUCCESS;
    pj_bool_t use_cli = PJ_FALSE;
    int cli_fe = 0;
    pj_uint16_t cli_telnet_port = 0;

    /** CLI options are not changable **/
    if (app_running) {
		use_cli = app_config.use_cli;
		cli_fe = app_config.cli_cfg.cli_fe;
		cli_telnet_port = app_config.cli_cfg.telnet_cfg.port;
    }
/// XXX
    // status = parse_config(argc, argv, uri_arg);
    // if (status != PJ_SUCCESS)
    // return status;

    if (app_running) {
		app_config.use_cli = use_cli;
		app_config.cli_cfg.cli_fe = cli_fe;
		app_config.cli_cfg.telnet_cfg.port = cli_telnet_port;
    }

    return status;
}

/** app_cli **/
static pj_bool_t            pj_inited = PJ_FALSE;
static pj_caching_pool      cli_cp;
static pj_bool_t            cli_cp_inited = PJ_FALSE;
static pj_cli_t             *cli = NULL;
static pj_cli_sess          *cli_cons_sess = NULL;
static pj_cli_front_end     *telnet_front_end = NULL;

PJ_DEF(void) cli_get_info(char *info, pj_size_t size)
{
    pj_cli_telnet_info telnet_info;
    pj_cli_telnet_get_info(telnet_front_end, &telnet_info);

    pj_ansi_snprintf(info, size, "Telnet to %.*s:%d",
             (int)telnet_info.ip_address.slen,
             telnet_info.ip_address.ptr,
             telnet_info.port);
}

/** CLI callback **/
/* Called on CLI (re)started, e.g: initial start, after iOS bg */
void cli_on_started(pj_status_t status)
{
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
void cli_on_stopped(pj_bool_t restart, int argc, char* argv[])
{
    /* Notify app */
    if (app_cfg.on_stopped)
    (*app_cfg.on_stopped)(restart, argc, argv);
}
/* Called on pjsua legacy quit */
void legacy_on_stopped(pj_bool_t restart)
{
    /* Notify app */
    if (app_cfg.on_stopped)
    (*app_cfg.on_stopped)(restart, 1, NULL);
}

static pj_str_t Pj_str(pj_pool_t *pool, Pj_String s)
{
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

BSTR str2bstr(const char *str, unsigned len)
{
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
static void Cp2(BSTR *dst, const pj_str_t *src)
{
    *dst = str2bstr(src->ptr, src->slen);
}


static void SafeStringArray2pjstrarray(pj_pool_t *pool,
                       SAFEARRAY *sa, unsigned *count,
                       pj_str_t a[])
{
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

static void pjstrarray2SafeStringArray(unsigned count, const pj_str_t a[],
                       SAFEARRAY **psa)
{
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

static void AccConfig2accconfig(pj_pool_t *pool,
                VideoAgent_Acc_Config *c1,
                pjsua_acc_config *c2)
{
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

static HRESULT accconfig2AccConfig(pjsua_acc_config *c1,
                  VideoAgent_Acc_Config *c2)
{
    //unsigned i;

    //pj_memset(c2, 0, sizeof(VideoAgent_Acc_Config));
    /*
    Cp(c2->acc_uri, &c1->id);
    Cp(c2->reg_uri, &c1->reg_uri);
    Cp(c2->contact_uri, &c1->contact);
    Cp(c2->proxy_uri, &c1->proxy);
    c2->reg_timeout = c1->reg_timeout;


    IRecordInfo *pUdtRecordInfo = NULL;
    HRESULT hr = GetRecordInfoFromGuids( LIBID_ACTIVEVIDEOAGENTLib,
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

static HRESULT Config2config(pj_pool_t *pool, VideoAgent_Config *c1, pjsua_config *c2)
{
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

static HRESULT config2Config(pjsua_config *c1, VideoAgent_Config *c2)
{
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
    hr = GetRecordInfoFromGuids( LIBID_ACTIVEVIDEOAGENTLib,
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

static void callinfo2CallInfo(pjsua_call_info *c1, VideoAgent_Call_Info *c2)
{
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

static void accinfo2AccInfo(pjsua_acc_info *info1, VideoAgent_Acc_Info *info2)
{
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

static void buddyinfo2BuddyInfo(pjsua_buddy_info *info1, VideoAgent_Buddy_Info *info2)
{
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

static CApp *CApp_Instance;

CApp::CApp()
{
    CApp_Instance = this;
}

/// On 5
static void call_on_dtmf_callback(
                pjsua_call_id call_id, 
                int dtmf)
{
}
/// On 6"
static pjsip_redirect_op call_on_redirected(
                pjsua_call_id call_id,
                const pjsip_uri *target,
                const pjsip_event *e)
{
    PJ_UNUSED_ARG(e);

    if (app_config.redir_op == PJSIP_REDIRECT_PENDING) {
        char uristr[PJSIP_MAX_URL_SIZE];
        int len;

        len = pjsip_uri_print(PJSIP_URI_IN_FROMTO_HDR, target, uristr,
                      sizeof(uristr));
        if (len < 1) {
            pj_ansi_strcpy(uristr, "--URI too long--");
        }

    ///    PJ_LOG(3,("video-agent-app", "Call %d is being redirected to %.*s. "
    ///          "Press 'Ra' to accept+replace To header, 'RA' to accept, "
    ///          "'Rr' to reject, or 'Rd' to disconnect.",
    ///          call_id, len, uristr));
    }

    return app_config.redir_op;
}
/// On 7'
static void on_reg_state(
                pjsua_acc_id acc_id)
{
    CApp_Instance->Fire_OnRegState(acc_id);
}
/// On 8
static void on_incoming_subscribe(
                pjsua_acc_id acc_id,
                pjsua_srv_pres *srv_pres,
                pjsua_buddy_id buddy_id,
                const pj_str_t *from,
                pjsip_rx_data *rdata,
                pjsip_status_code *code,
                pj_str_t *reason,
                pjsua_msg_data *msg_data_)
{
}
/// On 10
static void on_buddy_evsub_state(
                pjsua_buddy_id buddy_id,
                pjsip_evsub *sub,
                pjsip_event *event)
{
}
/// On 11'
static void on_pager(
                pjsua_call_id call_id, 
          const pj_str_t *from,
          const pj_str_t *to, 
          const pj_str_t *contact,
          const pj_str_t *mime_type, 
          const pj_str_t *text)
{
    BSTR fromURI, toURI, imText;

    Cp2(&fromURI, from);
    Cp2(&toURI, to);
    Cp2(&imText, text);

    // App Actions
    CApp_Instance->Fire_OnIncomingPager(call_id, fromURI, toURI, imText);
}
/// On 12'
static void on_typing(
                pjsua_call_id call_id, 
          const pj_str_t *from,
          const pj_str_t *to, 
          const pj_str_t *contact,
                pj_bool_t is_typing)
{
    BSTR fromURI, toURI;

    Cp2(&fromURI, from);
    Cp2(&toURI, to);

    // App Actions
    CApp_Instance->Fire_OnTypingIndication(call_id, fromURI, toURI, is_typing);
}
/// On 17
static void on_transport_state(
                pjsip_transport *tp,
                pjsip_transport_state state,
          const pjsip_transport_state_info *info)
{
}
/// On 18
static void on_ice_transport_error(
                int index, 
                pj_ice_strans_op op,
                pj_status_t status, 
                void *param)
{
}
/// On 19"
static pj_status_t on_snd_dev_operation(
                int operation)
{
    int cap_dev, play_dev;

    pjsua_get_snd_dev(&cap_dev, &play_dev);
/// PJ_LOG(3,("video-agent-app.cpp", "Turning sound device %d %d %s", cap_dev, play_dev,
///              (operation? "ON":"OFF")));
    return PJ_SUCCESS;
}
/// On 20
static void on_call_media_event(
                pjsua_call_id call_id,
                unsigned med_idx,
                pjmedia_event *event)
{
}

/// app  Control !!!!
// A1
STDMETHODIMP CApp::app_create(Pj_Status *ret)
{
    *ret = pjsua_create();
    printf("app_create\n");
    return S_OK;
}
// A2
STDMETHODIMP CApp::app_default_config(VideoAgent_Config *pConfig)
{
    pjsua_config cfg;
    pjsua_config_default(&cfg);
    return config2Config(&cfg, pConfig);
}
// A3
STDMETHODIMP CApp::app_test_config(VideoAgent_Config *pConfig, BSTR *retmsg)
{
    pjsua_config cfg;
    HRESULT hr;
    Temp_Pool tp;
    char errmsg[PJ_ERR_MSG_SIZE];

    hr = Config2config(tp.get_pool(), pConfig, &cfg);
    if (FAILED(hr))
    return hr;

    //pjsua_test_config(&cfg, errmsg, sizeof(errmsg));
    *retmsg = str2bstr(errmsg, strlen(errmsg));
    return S_OK;
}

// A4
STDMETHODIMP CApp::app_init(VideoAgent_Config *pConfig, Pj_Status *pStatus)
{
    pjsua_transport_id transport_id = -1;
 ///pjsua_transport_config tcp_cfg;
    //unsigned i;
    pj_pool_t *tmp_pool;
    pj_status_t status;

    /** Create pjsua **/
    // status = pjsua_create();
    // if (status != PJ_SUCCESS)
    // return status;

    /* Create pool for application */
    app_config.pool = pjsua_pool_create("pjsua-app", 1000, 1000);
    tmp_pool = pjsua_pool_create("tmp-pjsua", 1000, 1000);;

    /* Init CLI & its FE settings */
    if (!app_running) {
    pj_cli_cfg_default(&app_config.cli_cfg.cfg);
    pj_cli_telnet_cfg_default(&app_config.cli_cfg.telnet_cfg);
    pj_cli_console_cfg_default(&app_config.cli_cfg.console_cfg);
    app_config.cli_cfg.telnet_cfg.on_started = cli_on_started;
    }

    /** Parse args **/
    status = load_config(app_cfg.argc, app_cfg.argv, &uri_arg);
    if (status != PJ_SUCCESS) {
    pj_pool_release(tmp_pool);
    return status;
    }

    /* Initialize application callbacks */
    // app_config.cfg.cb.on_call_state = &on_call_state;                       // 1
    // app_config.cfg.cb.on_call_media_state = &on_call_media_state;           // 2
    // app_config.cfg.cb.on_incoming_call = &on_incoming_call;                 // 3
    // app_config.cfg.cb.on_call_tsx_state = &on_call_tsx_state;               // 4
    // app_config.cfg.cb.on_dtmf_digit = &call_on_dtmf_callback;               // 5
    // app_config.cfg.cb.on_call_redirected = &call_on_redirected;             // 6
    // app_config.cfg.cb.on_reg_state = &on_reg_state;                         // 7
    // app_config.cfg.cb.on_incoming_subscribe = &on_incoming_subscribe;       // 8
    // app_config.cfg.cb.on_buddy_state = &on_buddy_state;                     // 9
    // app_config.cfg.cb.on_buddy_evsub_state = &on_buddy_evsub_state;         // 10
    // app_config.cfg.cb.on_pager = &on_pager;                                 // 11
    // app_config.cfg.cb.on_typing = &on_typing;                               // 12
    // app_config.cfg.cb.on_call_transfer_status = &on_call_transfer_status;   // 13
    // app_config.cfg.cb.on_call_replaced = &on_call_replaced;                 // 14
    // app_config.cfg.cb.on_nat_detect = &on_nat_detect;                       // 15
    // app_config.cfg.cb.on_mwi_info = &on_mwi_info;                           // 16
    // app_config.cfg.cb.on_transport_state = &on_transport_state;             // 17
    // app_config.cfg.cb.on_ice_transport_error = &on_ice_transport_error;     // 18
    // app_config.cfg.cb.on_snd_dev_operation = &on_snd_dev_operation;         // 19
    // app_config.cfg.cb.on_call_media_event = &on_call_media_event;           // 20
#ifdef TRANSPORT_ADAPTER_SAMPLE
    app_config.cfg.cb.on_create_media_transport = &on_create_media_transport;   // 21
#endif

    /* Set sound device latency */
    // 设置声音设备延时
    if (app_config.capture_lat > 0)
    app_config.media_cfg.snd_rec_latency = app_config.capture_lat;
    if (app_config.playback_lat)
    app_config.media_cfg.snd_play_latency = app_config.playback_lat;

    if (app_cfg.on_config_init)
    (*app_cfg.on_config_init)(&app_config);

    /* Initialize pjsua */
    // 初始化 pjsua
    status = pjsua_init(&app_config.cfg, &app_config.log_cfg,
            &app_config.media_cfg);
    if (status != PJ_SUCCESS) {
        pj_pool_release(tmp_pool);
        return S_FALSE;
    }

    return S_OK;
}
// A5
STDMETHODIMP CApp::app_start(Pj_Status *retStatus)
{
    *retStatus = pjsua_start();
    return S_OK;
}
// A6
STDMETHODIMP CApp::app_destroy(Pj_Status *retStatus)
{
    *retStatus = pjsua_destroy();
    return S_OK;
}
///  call Control !!!!
// A7
STDMETHODIMP CApp::call_get_max_count(int *retCount)
{
    *retCount = pjsua_call_get_max_count();
    return S_OK;
}

// A8
STDMETHODIMP CApp::call_get_count(int *retCount)
{
    *retCount = pjsua_call_get_count();
    return S_OK;
}
// A9
STDMETHODIMP CApp::call_is_active(pjsua_call_id call_id, Pj_Bool *retVal)
{
    *retVal = pjsua_call_is_active(call_id);
    return S_OK;
}

// A10
STDMETHODIMP CApp::call_has_media(pjsua_call_id call_id, Pj_Bool *pRet)
{
    *pRet = pjsua_call_has_media(call_id);
    return S_OK;
}

// A11
STDMETHODIMP CApp::call_get_info(pjsua_call_id call_id, VideoAgent_Call_Info *pInfo, Pj_Status *pRet)
{
    pjsua_call_info info;
    *pRet = pjsua_call_get_info(call_id, &info);
    callinfo2CallInfo(&info, pInfo);
    return S_OK;
}

STDMETHODIMP CApp::call_make_call(int acc_id, Pj_String dst_uri, int *call_id, Pj_Status *pRet)
{
    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), dst_uri);

    // CC
    if (uri_arg.slen) {
        pjsua_call_setting_default(&call_opt);
        call_opt.aud_cnt = app_config.aud_cnt;
        call_opt.vid_cnt = app_config.vid.vid_cnt;
        *pRet = pjsua_call_make_call(current_acc, &uri_arg, &call_opt,
                NULL, NULL, NULL);
    }
    return S_OK;
}

STDMETHODIMP CApp::call_answer(pjsua_call_id call_id, int status_code, Pj_Status *pRet)
{
    // CC
    *pRet = pjsua_call_answer(call_id, status_code, 
                NULL, NULL);
    return S_OK;
}

STDMETHODIMP CApp::call_hangup(pjsua_call_id call_id, Pj_Status *pRet)
{
    // CC
    pj_str_t reason = pj_str("just hangup");
    pjsua_call_hangup(call_id, 500, &reason, NULL);

    *pRet = PJ_SUCCESS;
    return S_OK;
}

STDMETHODIMP CApp::call_set_hold(pjsua_call_id call_id, Pj_Status *pRet)
{
    // CC
    if (call_id != PJSUA_INVALID_ID) {
        pjsua_call_set_hold(call_id, NULL);
    } else {
    ///    PJ_LOG(3,("video-agent-app", "No current call"));
    }
    *pRet = PJ_SUCCESS;
    return S_OK;
}

STDMETHODIMP CApp::call_release_hold(pjsua_call_id call_id, Pj_Status *pRet)
{
    // C
    if (call_id != PJSUA_INVALID_ID) {
        /*
         * re-INVITE
         */
        call_opt.flag |= PJSUA_CALL_UNHOLD;
        *pRet = pjsua_call_reinvite2(call_id, &call_opt, NULL);

    } else {
    ///    PJ_LOG(3,("video-agent-app", "No current call"));
    }
    
    return S_OK;
}

STDMETHODIMP CApp::call_xfer(pjsua_call_id call_id, Pj_String dst_uri, Pj_Status *pRet)
{
    // CC
    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), dst_uri);
    *pRet = pjsua_call_xfer(call_id, &tmp, NULL);
    return S_OK;
}

STDMETHODIMP CApp::call_dial_dtmf(pjsua_call_id call_id, Pj_String digits, Pj_Status *pRet)
{
    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), digits);
    *pRet = pjsua_call_dial_dtmf(call_id, &tmp);
    return S_OK;
}

STDMETHODIMP CApp::call_send_im(pjsua_call_id call_id, Pj_String text, Pj_Status *pRet)
{
    // CC
    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), text);
    *pRet = pjsua_call_send_im(call_id, NULL, &tmp, NULL, NULL);
    return S_OK;
}

STDMETHODIMP CApp::call_typing(pjsua_call_id call_id, int is_typing, Pj_Status *pRet)
{
    // CC
    *pRet = pjsua_call_send_typing_ind(call_id, is_typing, NULL);
    return S_OK;
}

STDMETHODIMP CApp::call_hangup_all()
{
    pjsua_call_hangup_all();
    return S_OK;
}

STDMETHODIMP CApp::call_get_textstat(pjsua_call_id call_id, BSTR *textstat)
{
/// XXX
    // char buf[1024];
    // pjsua_call_dump(call_id, 1, buf, sizeof(buf), "");

    // OLECHAR wbuf[1024];
    // pj_ansi_to_unicode(buf, strlen(buf), wbuf, PJ_ARRAY_SIZE(wbuf));
    // *textstat = SysAllocString(wbuf);
    return S_OK;
}

// A22
STDMETHODIMP CApp::acc_get_count(int *pCount)
{
    // ??
    //*pCount = pjsua_get_acc_count();
    return S_OK;
}
// A23
STDMETHODIMP CApp::acc_get_info(int acc_id, VideoAgent_Acc_Info *pInfo, Pj_Status *pRet)
{
    pjsua_acc_info info;
    *pRet = pjsua_acc_get_info(acc_id, &info);
    accinfo2AccInfo(&info, pInfo);
    return S_OK;
}
// A24
STDMETHODIMP CApp::acc_add(VideoAgent_Acc_Config *pConfig, int *pAcc_Index, Pj_Status *pRet)
{
    /// ??????
    //int *pAcc_Index ==>  pj_str_t  config.id;
    Temp_Pool tp;
    pjsua_acc_config config;
    AccConfig2accconfig(tp.get_pool(), pConfig,  &config);
    
    pj_str_t id = pj_str("");// = Pj_str(pAcc_Index);
    config.id = id;
    *pRet = pjsua_acc_add(&config, PJ_TRUE, NULL);
    return S_OK;
}
// A25
STDMETHODIMP CApp::acc_set_online_status(int acc_id, int is_online, Pj_Status *pRet)
{
    *pRet = pjsua_acc_set_online_status(acc_id, is_online);
    return S_OK;
}
// A26
STDMETHODIMP CApp::acc_set_registration(int acc_id, int reg_active, Pj_Status *pRet)
{
    *pRet = pjsua_acc_set_registration(acc_id, reg_active);
    return S_OK;
}


STDMETHODIMP CApp::buddy_get_count(int *pCount)
{
    *pCount = pjsua_get_buddy_count();
    return S_OK;
}

STDMETHODIMP CApp::buddy_get_info(int buddy_index, VideoAgent_Buddy_Info *pInfo, Pj_Status *pRet)
{
    pjsua_buddy_info info;
    *pRet = pjsua_buddy_get_info(buddy_index, &info);
    buddyinfo2BuddyInfo(&info, pInfo);
    return S_OK;
}

STDMETHODIMP CApp::buddy_add(Pj_String uri, int *pBuddy_Index, Pj_Status *pRet)
{
    // CC
    char buf[128];
    pjsua_buddy_config buddy_cfg;
    pj_bzero(&buddy_cfg, sizeof(pjsua_buddy_config));

    buddy_cfg.uri = pj_str(buf);
    buddy_cfg.subscribe = PJ_TRUE;

    *pRet = pjsua_buddy_add(&buddy_cfg, pBuddy_Index);
    return S_OK;
}

STDMETHODIMP CApp::buddy_subscribe_pres(int buddy_index, int subscribe, Pj_Status *pRet)
{
    *pRet = pjsua_buddy_subscribe_pres(buddy_index, subscribe);
    return S_OK;
}

STDMETHODIMP CApp::im_send_text(int acc_id, Pj_String dst_uri, Pj_String text, Pj_Status *pRet)
{
    // CC
    Temp_Pool tp;
    pj_str_t tmp_uri = Pj_str(tp.get_pool(), dst_uri);
    pj_str_t tmp_text = Pj_str(tp.get_pool(), text);
    *pRet = pjsua_im_send(acc_id, &tmp_uri, NULL, &tmp_text, NULL, NULL);
    return S_OK;
}

STDMETHODIMP CApp::im_typing(int acc_id, Pj_URI dst_uri, int is_typing, Pj_Status *pRet)
{
    // CC
    Temp_Pool tp;
    pj_str_t tmp_uri = Pj_str(tp.get_pool(), dst_uri);
    *pRet = pjsua_im_typing(acc_id, &tmp_uri, is_typing, NULL);
    return S_OK;
}

STDMETHODIMP CApp::conf_connect(int src_port, int sink_port, Pj_Status *pRet)
{
    *pRet = pjsua_conf_connect(src_port, sink_port);
    return S_OK;
}

STDMETHODIMP CApp::conf_disconnect(int src_port, int sink_port, Pj_Status *pRet)
{
    *pRet = pjsua_conf_disconnect(src_port, sink_port);
    return S_OK;
}

STDMETHODIMP CApp::player_create(Pj_String filename, int *pPlayer_Id, Pj_Status *pRet)
{
    // CC
    
    unsigned play_options = 0;

    if (app_config.auto_play_hangup)
        play_options |= PJMEDIA_FILE_NO_LOOP;
    
    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), filename);
    *pRet = pjsua_player_create(&tmp, play_options, pPlayer_Id);
    return S_OK;
}

STDMETHODIMP CApp::player_get_conf_port(int player_id, int *pPort)
{
    *pPort = pjsua_player_get_conf_port(player_id);
    return S_OK;
}

STDMETHODIMP CApp::player_set_pos(int player_id, int pos, Pj_Status *pRet)
{
    *pRet = pjsua_player_set_pos(player_id, pos);
    return S_OK;
}

STDMETHODIMP CApp::player_destroy(int player_id, Pj_Status *pRet)
{
    *pRet = pjsua_player_destroy(player_id);
    return S_OK;
}

STDMETHODIMP CApp::recorder_create(Pj_String filename, int *pRecorder_Id, Pj_Status *pRet)
{
    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), filename);
    *pRet = pjsua_recorder_create(&tmp, 0, NULL, 0, 0, pRecorder_Id);
    return S_OK;
}

STDMETHODIMP CApp::recorder_get_conf_port(int recorder_id, int *pPort)
{
    *pPort = pjsua_recorder_get_conf_port(recorder_id);
    return S_OK;
}

STDMETHODIMP CApp::recorder_destroy(int recorder_id, Pj_Status *pRet)
{
    *pRet = pjsua_recorder_destroy(recorder_id);
    return S_OK;
}

STDMETHODIMP CApp::app_load_config(Pj_String filename, VideoAgent_Config *pConfig, Pj_Status *pRet)
{
    // CC
    // pjsua_config config;
    // Temp_Pool tp;
    // pj_str_t tmp = Pj_str(tp.get_pool(), filename);
    // pjsua_config_default(&config);
    // *pRet = pjsua_load_settings(tmp.ptr, &config, NULL);
    // if (*pRet == PJ_SUCCESS)
    // *pRet = config2Config(&config, pConfig);
    return S_OK;
}

STDMETHODIMP CApp::app_save_config(Pj_String filename, VideoAgent_Config *pConfig, Pj_Status *pRet)
{
    // CC
    // Temp_Pool tp;
    // pjsua_config config;
    // pj_str_t tmp = Pj_str(tp.get_pool(), filename);
    // HRESULT hr;

    // hr = Config2config(tp.get_pool(), pConfig, &config);
    // if (FAILED(hr))
    // return hr;

    // *pRet = pjsua_save_settings(tmp.ptr, &config);
    return S_OK;
}

STDMETHODIMP CApp::app_get_current_config(VideoAgent_Config *pConfig)
{
    // C
    // Temp_Pool tp;
    // pjsua_config config;

    // pjsua_get_config(tp.get_pool(), &config);
    // return config2Config(&config, pConfig);
    
    return S_OK;
}

STDMETHODIMP CApp::app_get_error_msg(Pj_Status status, BSTR * pRet)
{
    char errmsg[PJ_ERR_MSG_SIZE];
    OLECHAR werrmsg[PJ_ERR_MSG_SIZE];
    pj_strerror(status, errmsg, sizeof(errmsg));
    pj_ansi_to_unicode(errmsg, strlen(errmsg), werrmsg, PJ_ARRAY_SIZE(werrmsg));
    *pRet = SysAllocString(werrmsg);
    return S_OK;
}

STDMETHODIMP CApp::app_verify_sip_url(Pj_String uri, Pj_Status *pRet)
{
    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), uri);
    *pRet = pjsua_verify_sip_url(tmp.ptr);
    return S_OK;
}

STDMETHODIMP CApp::app_handle_events(int msec_timeout, int *pEvCount)
{
    if (msec_timeout < 0)
    msec_timeout = 0;

    *pEvCount = pjsua_handle_events(msec_timeout);
    return S_OK;
}

STDMETHODIMP CApp::app_parse_uri(BSTR uriString, Pjsip_Sip_Uri *pSipUri, Pj_Status *pStatus)
{
    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), uriString);
    pjsip_name_addr *addr;
///    char buf[1024];
///    pj_str_t s;

    addr = (pjsip_name_addr*)
    pjsip_parse_uri(tp.get_pool(), tmp.ptr, tmp.slen, PJSIP_PARSE_URI_AS_NAMEADDR);
    if (addr == NULL) {
    *pStatus = PJSIP_EINVALIDURI;
    return S_OK;
    }

    if (!PJSIP_URI_SCHEME_IS_SIP(addr) && !PJSIP_URI_SCHEME_IS_SIPS(addr)) {
    *pStatus = PJSIP_EINVALIDSCHEME;
    return S_OK;
    }

    pjsip_sip_uri *sip = (pjsip_sip_uri*)addr->uri;

    Cp2(&pSipUri->display, &addr->display);
    Cp2(&pSipUri->user, &sip->user);
    Cp2(&pSipUri->passwd, &sip->passwd);
    Cp2(&pSipUri->host, &sip->host);
    pSipUri->port = sip->port;
    Cp2(&pSipUri->param_user, &sip->user_param);
    Cp2(&pSipUri->param_method, &sip->method_param);
    Cp2(&pSipUri->param_transport, &sip->transport_param);
    pSipUri->param_ttl = sip->ttl_param;
    pSipUri->param_lr = sip->lr_param;
    Cp2(&pSipUri->param_maddr, &sip->maddr_param);

    // C
    // s.ptr = buf;
    // s.slen = pjsip_param_print_on(&sip->other_param, buf, sizeof(buf),
                  // &pjsip_PARAM_CHAR_SPEC, &pjsip_PARAM_CHAR_SPEC, ';');
    // Cp2(&pSipUri->param_other, &s);

    // C
    // s.slen = pjsip_param_print_on(&sip->header_param, buf, sizeof(buf),
                  // &pjsip_HDR_CHAR_SPEC, &pjsip_HDR_CHAR_SPEC, '?');
    // Cp2(&pSipUri->param_header, &s);

    *pStatus = PJ_SUCCESS;
    return S_OK;
}

STDMETHODIMP CApp::app_print_uri(Pjsip_Sip_Uri *pSipURI, Pjsip_Uri_Context context, BSTR *uriText)
{
    Temp_Pool tp;
    pjsip_name_addr *addr;
    pj_str_t tmp;
    char buf[1024];
    pjsip_sip_uri *sip;

    addr = pjsip_name_addr_create(tp.get_pool());
    sip = pjsip_sip_uri_create(tp.get_pool(), PJ_FALSE);
    addr->uri = (pjsip_uri*)sip;

    addr->display = Pj_str(tp.get_pool(), pSipURI->display);
    sip->user = Pj_str(tp.get_pool(), pSipURI->user);
    sip->passwd = Pj_str(tp.get_pool(), pSipURI->passwd);
    sip->host = Pj_str(tp.get_pool(), pSipURI->host);
    sip->port = pSipURI->port;
    sip->user_param = Pj_str(tp.get_pool(), pSipURI->param_user);
    sip->method_param = Pj_str(tp.get_pool(), pSipURI->param_method);
    sip->transport_param = Pj_str(tp.get_pool(), pSipURI->param_transport);
    sip->ttl_param = pSipURI->param_ttl;
    sip->lr_param = pSipURI->param_lr;
    sip->maddr_param = Pj_str(tp.get_pool(), pSipURI->param_maddr);

    /* Unfortunately can't transport params yet (no parsing function) */

    tmp.ptr = buf;
    tmp.slen = pjsip_uri_print((pjsip_uri_context_e)context, addr, buf, sizeof(buf));

    Cp2(uriText, &tmp);
    return S_OK;
}

STDMETHODIMP CApp::app_compare_uri_string(Pjsip_Uri_Context context, BSTR uri1, BSTR uri2, Pj_Status *pStatus)
{
    Temp_Pool tp;

    pj_str_t tmp_uri1 = Pj_str(tp.get_pool(), uri1);
    pj_str_t tmp_uri2 = Pj_str(tp.get_pool(), uri2);

    pjsip_uri *u1, *u2;

    u1 = pjsip_parse_uri(tp.get_pool(), tmp_uri1.ptr, tmp_uri1.slen, PJSIP_PARSE_URI_AS_NAMEADDR);
    if (u1 == NULL) {
    *pStatus = PJSIP_EINVALIDURI;
    return S_OK;
    }

    u2 = pjsip_parse_uri(tp.get_pool(), tmp_uri2.ptr, tmp_uri2.slen, PJSIP_PARSE_URI_AS_NAMEADDR);
    if (u2 == NULL) {
    *pStatus = PJSIP_EINVALIDURI;
    return S_OK;
    }

    *pStatus = pjsip_uri_cmp((pjsip_uri_context_e)context, u1, u2);
    return S_OK;
}

STDMETHODIMP CApp::buddy_del(int buddy_index, Pj_Status *pRet)
{
    *pRet = pjsua_buddy_del(buddy_index);
    return S_OK;
}

STDMETHODIMP CApp::acc_del(int acc_id, Pj_Status *pRet)
{
    *pRet = pjsua_acc_del(acc_id);
    return S_OK;
}

STDMETHODIMP CApp::acc_find_for_outgoing(BSTR url, BSTR *abc, int *acc_id)
{
    //Temp_Pool tp;

    // Chernic 2017-11-19 
    // pj_pool_create(异常)
    //pj_str_t tmp_uri = Pj_str(tp.get_pool(), url);


    CComBSTR sResult( url ); 
    *abc = sResult.Copy(); 

    *acc_id = 234;

    return S_OK;
}

STDMETHODIMP CApp::acc_enum_id(SAFEARRAY **accIdArray)
{
    int id[32];
    unsigned count = PJ_ARRAY_SIZE(id);
    unsigned i;

    // pjsua_acc_enum_id(id, &count);

    *accIdArray = SafeArrayCreateVector(VT_INT, 0, count);

    for (i=0; i<count; ++i) {
    long rg = i;
    SafeArrayPutElement(*accIdArray, &rg, &id[i]);
    }

    return S_OK;
}

STDMETHODIMP CApp::conf_enum_ports(SAFEARRAY **pPortsArray)
{
    int id[128];
    unsigned count = PJ_ARRAY_SIZE(id);
    unsigned i;

    // pjsua_conf_enum_port_ids(id, &count);

    *pPortsArray = SafeArrayCreateVector(VT_INT, 0, count);

    for (i=0; i<count; ++i) {
    long rg = i;
    SafeArrayPutElement(*pPortsArray, &rg, &id[i]);
    }

    return S_OK;
}

STDMETHODIMP CApp::conf_get_port_info(int port_id, VideoAgent_Conf_Port_Info *pInfo, Pj_Status *pRet)
{
    unsigned i;
    pjsua_conf_port_info info;

    *pRet = pjsua_conf_get_port_info(port_id, &info);
    if (*pRet != PJ_SUCCESS)
    return S_OK;

    pInfo->slot_id = info.slot_id;
    Cp2(&pInfo->name, &info.name);
    pInfo->clock_rate = info.clock_rate;
    pInfo->channel_count = info.channel_count;
    pInfo->samples_per_frame = info.samples_per_frame;
    pInfo->bits_per_sample = info.bits_per_sample;

    pInfo->listeners = SafeArrayCreateVector(VT_INT, 0, info.listener_cnt);

    for (i=0; i<info.listener_cnt; ++i) {
    long rg = i;
    SafeArrayPutElement(pInfo->listeners, &rg, &info.listeners[i]);
    }

    return S_OK;
}

// A58
STDMETHODIMP CApp::aboutbox(BSTR * str)
{
     int len = SysStringLen(*str);   // 注：此方法修改BSTR，不能破坏原占用内存，不能越界访问
     for (int i = 0; i < len; i++)
              *str[i] = '0' + i;
     return S_OK;
}

// MicroSip : Focusua 1 ()
static void on_reg_state2(pjsua_acc_id acc_id, pjsua_reg_info *info){
    //if (!IsWindow(mainDlg->m_hWnd))   {
    //  return;
    // }
    //CString *str = NULL;
    //PostMessage(mainDlg->m_hWnd, UM_ON_REG_STATE2, (WPARAM) info->cbparam->code, (LPARAM) str);
}
// MicroSip : Focusua 2 
static void on_call_state(pjsua_call_id call_id, pjsip_event *e){
    pjsua_call_info call_info;
    pjsua_call_get_info(call_id, &call_info);
    
    // App Actions

/// ABChernic : 2018-02-01
/// VideoAgent_Call_Info *Call_Info = new VideoAgent_Call_Info;
/// callinfo2CallInfo(&call_info, Call_Info);
/// CApp_Instance->Fire_OnCallState(call_id, Call_Info);

}
// MicroSip : Focusua 3 ()
static void on_dtmf_digit(pjsua_call_id call_id, int digit){
    //char signal[2];
    //signal[0] = digit;
    //signal[1] = 0;
    //call_play_digit(-1, signal);
}
// MicroSip : Focusua 4 ()
static void on_call_tsx_state(pjsua_call_id call_id,pjsip_transaction *tsx,pjsip_event *e){
}
// MicroSip : Focusua 6
static void on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id,pjsip_rx_data *rdata){
    CApp_Instance->Fire_OnIncomingCall(call_id);
}
// MicroSip : Focusua 7 ()
static void on_nat_detect(const pj_stun_nat_detect_result *res){
}
// MicroSip : Focusua 8
static void on_buddy_state(pjsua_buddy_id buddy_id){
    CApp_Instance->Fire_OnBuddyState(buddy_id);
}
// MicroSip : Focusua 9 ()
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
// MicroSip : Focusua 10  ()
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
// MicroSip : Focusua 11 ()
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
// MicroSip : Focusua 12 ()
static void on_call_transfer_status(pjsua_call_id call_id,int status_code, const pj_str_t *status_text,pj_bool_t final,pj_bool_t *p_cont){
}
// MicroSip : Focusua 13
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
// MicroSip : Focusua 14()
static void on_call_replaced(pjsua_call_id old_call_id,pjsua_call_id new_call_id){
}
// MicroSip : Focusua 15()
static void on_mwi_info(pjsua_acc_id acc_id, pjsua_mwi_info *mwi_info){
}
// A61 test SDL
STDMETHODIMP CApp::focusua_test_sdl(
    Pj_Status *retStatus
){
	RECT rcC = {0, 0, 500, 500};
	//if(!pTEST_SDL2)
	//	pTEST_SDL2 = new TEST_SDL2(); 
	//pTEST_SDL2->SetWindow( rcC );

    return S_OK;
}
// A62
STDMETHODIMP CApp::focusua_app_test_config(BSTR *retmsg)
{
    pjsua_config cfg;
    
    char errmsg[PJ_ERR_MSG_SIZE];
    
    pjsua_config_default(&cfg);
    
    mypjsua_test_config(&cfg, errmsg, sizeof(errmsg));
    
    *retmsg = str2bstr(errmsg, strlen(errmsg));
    
    printf("app_test_config_ed\n");
    return S_OK;
}
// A63
STDMETHODIMP CApp::focusua_init(Pj_Status *retStatus)
{
    //pageContacts->isSubscribed = FALSE;CreateAddPreviewToWindow
    //player_id = PJSUA_INVALID_ID;
    // check updates
	if(!pj_ready)
	{
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

		if (accountSettings.enableSTUN && !accountSettings.stun.IsEmpty()) 
		{
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

		pj_ready = true;

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
// A64
/*
STDMETHODIMP CApp::focus_app_start(Pj_Status *retStatus)
{
    Pj_Status status;

    *retStatus = pjsua_start();
    if (*retStatus != PJ_SUCCESS) {
        pjsua_destroy();
        return S_FALSE;
    }

    UpdateSoundDevicesIds();

    /// VIDEO
#ifdef _GLOBAL_VIDEO
    pj_uint32_t bitrate;
    if (_DISABLEH264) {
        pjsua_vid_codec_set_priority(&pj_str("H264"),0);
    } else
    {
        const pj_str_t codec_id = {"H264", 4};
        pjmedia_vid_codec_param param;
        pjsua_vid_codec_get_param(&codec_id, &param);
        if (1) {
            bitrate = 1000 * _BITRATEH264;
            param.enc_fmt.det.vid.avg_bps = bitrate;
            param.enc_fmt.det.vid.max_bps = bitrate;
        }
        pjsua_vid_codec_set_param(&codec_id, &param);
    }
    if (_DISABLEH263) {
        pjsua_vid_codec_set_priority(&pj_str("H263"),0);
    } else {
        if (1) {
            const pj_str_t codec_id = {"H263", 4};
            pjmedia_vid_codec_param param;
            pjsua_vid_codec_get_param(&codec_id, &param);
            bitrate = 1000 * _BITRATEH263;
            param.enc_fmt.det.vid.avg_bps = bitrate;
            param.enc_fmt.det.vid.max_bps = bitrate;
            pjsua_vid_codec_set_param(&codec_id, &param);
        }
    }
    if (_DISABLEVP8) {
        pjsua_vid_codec_set_priority(&pj_str("VP8"),0);
    } else {
        if (1) {
            const pj_str_t codec_id = {"VP8", 4};
            pjmedia_vid_codec_param param;
            pjsua_vid_codec_get_param(&codec_id, &param);
            bitrate = 1000 * (pj_uint32_t)_BITRATEVP8;
            param.enc_fmt.det.vid.avg_bps = bitrate;
            param.enc_fmt.det.vid.max_bps = bitrate;
            pjsua_vid_codec_set_param(&codec_id, &param);
        }
    }
#endif

    pjsua_transport_config cfg;

    transport_udp_local = -1;
    transport_udp = -1;
    transport_tcp = -1;
    transport_tls = -1;

    pjsua_transport_config_default(&cfg);

    Temp_Pool tp;
    pj_str_t tmp = Pj_str(tp.get_pool(), Pj_String("") );
    cfg.public_addr = tmp;

    if (_SOURCEPORT) {
        cfg.port=_SOURCEPORT;
        status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, &transport_udp);
        if (status != PJ_SUCCESS) {
            cfg.port=0;
            pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, &transport_udp);
        }
        if (_MACRO_ENABLE_LOCAL_ACCOUNT) {
            if (_SOURCEPORT == 5060 ) {
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
        if (_MACRO_ENABLE_LOCAL_ACCOUNT) {
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

    cfg.port = _MACRO_ENABLE_LOCAL_ACCOUNT ? 5060 : 0;
    status = pjsua_transport_create(PJSIP_TRANSPORT_TCP, &cfg, &transport_tcp);
    if (status != PJ_SUCCESS && cfg.port) {
        cfg.port=0;
        pjsua_transport_create(PJSIP_TRANSPORT_TCP, &cfg, &transport_tcp);
    }

    cfg.port = _MACRO_ENABLE_LOCAL_ACCOUNT ? 5061 : 0;
    status = pjsua_transport_create(PJSIP_TRANSPORT_TLS, &cfg, &transport_tls);
    if (status != PJ_SUCCESS && cfg.port) {
        cfg.port=0;
        pjsua_transport_create(PJSIP_TRANSPORT_TLS, &cfg, &transport_tls);
    }

    // if (_USERSDIRECTORY) {
        // UsersDirectoryLoad();
    // }

    return S_OK;
}
*/
// A65
STDMETHODIMP CApp::focusua_idestroy(Pj_Status *retStatus)
{
    if (pj_ready)  {
        //if (pageContacts) {
        //  pageContacts->PresenceUnsubsribe();
        // }
        //call_deinit_tonegen(-1);

        //toneCalls.RemoveAll();
        
        //if (IsWindow(m_hWnd)) {
        //  KillTimer(IDT_TIMER_TONE);
        // }

///     PlayerStop();

        //if (accountSettings.accountId) {
        //  PJAccountDelete();
        // }

        pj_ready = false;

        *retStatus = pjsua_destroy();
    }
    return S_OK;
}
// A66
STDMETHODIMP CApp::focusua_acc_add(
    int _00accountId,
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
// A67 
STDMETHODIMP CApp::focusua_call_make_call(
    BSTR _21callId,
    BSTR _22numb,
    BSTR _23number,
    BSTR _24numberParameters,
    BSTR _25name,
    int hasVideo,
    Pj_Status *retStatus
){
    bool singleMode = true;

    // make_call 1
    pjsua_acc_id acc_id;
    // make_call 2
    pj_str_t pj_uri;
    if (!SelectSIPAccount(_23number,acc_id,pj_uri)) {
        // Account dummy;
        // *pStatus = accountSettings.AccountLoad(1,&dummy) ? PJSIP_EAUTHACCDISABLED : PJSIP_EAUTHACCNOTFOUND;
        // return PJSUA_INVALID_ID;
        return S_FALSE;
    }

    if (singleMode) {
        call_hangup_all_noincoming();
    }

    // #ifdef _GLOBAL_VIDEO
    setComplexFrameRect();
    ResetPJmediaData();

    DisplayModeChange();

    //int overlay_mode = IN_NAVBAR_L;
     int overlay_mode = IN_NAVBAR_R;
    // int overlay_mode = IN_FOOTER_L;
    // int overlay_mode = IN_FOOTER_R;

    InitPreviwWindow( overlay_mode );

    ShowPreviwWindow( PJ_FALSE );
    ShowStreamWindow( PJ_FALSE );
    // #endif

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

// MicroSip : Focusua 5 ()
static void on_call_media_state(pjsua_call_id call_id){
    pjsua_call_info *call_info = new pjsua_call_info();
    if (pjsua_call_get_info(call_id, call_info) != PJ_SUCCESS || call_info->state == PJSIP_INV_STATE_NULL) {
        return;
    }

#ifdef _GLOBAL_VIDEO
    MakeStreamWindow( ComplexFrameRect.psStream );

    ShowPreviwWindow( PJ_TRUE );
    ShowStreamWindow( PJ_TRUE );
#endif
}
// A68 ===> MicroSip : Focusua 5 ()
STDMETHODIMP CApp::focus_change_stream(
    Pj_Status *retStatus
){
    on_call_media_state(-1);
    return S_OK;
}

// A69
STDMETHODIMP CApp::focusua_call_make_call_with_settings(
    BSTR _21callId,
    BSTR _22numb,
    BSTR _23number,
    BSTR _24numberParameters,
    BSTR _25name,
    int hasVideo,
    int overlay_mode,
    BSTR dir_string,
    Pj_Status *retStatus
){
    bool singleMode = true;

    // make_call 1
    pjsua_acc_id acc_id;
    // make_call 2
    pj_str_t pj_uri;
    if (!SelectSIPAccount(_23number,acc_id,pj_uri)) {
        // Account dummy;
        // *pStatus = accountSettings.AccountLoad(1,&dummy) ? PJSIP_EAUTHACCDISABLED : PJSIP_EAUTHACCNOTFOUND;
        // return PJSUA_INVALID_ID;
        return S_FALSE;
    }
    
    if (singleMode) {
        call_hangup_all_noincoming();
    }

    // #ifdef _GLOBAL_VIDEO
    setComplexFrameRect();
    ResetPJmediaData();

    DisplayModeChange();

    InitPreviwWindow( overlay_mode );

    ShowPreviwWindow( PJ_FALSE );
    ShowStreamWindow( PJ_FALSE );
    // #endif

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

