/* 
 * Copyright (C) 2017 Focustar (chernic@qq.com)
 */
#include "stdafx.h"
#include "global.h"
#include "settings.h"

int             g_transport;
pjsua_acc_id    g_acc_id;
pjsua_acc_id    g_acc_id_local;
int             g_audio_input;
int             g_audio_output;
int             g_audio_ring;

CString RemovePort(CString domain){
    int pos = domain.Find(_T(":"));
    if (pos != -1) {
        return domain.Mid(0,pos);
    } else {
        return domain;
    }
}
BOOL IsIP(CString host){
    CStringA hostA(host);
    char *pHost = hostA.GetBuffer();
    unsigned long ulAddr  = inet_addr(pHost);
    if (ulAddr !=INADDR_NONE && ulAddr != INADDR_ANY) {
        struct in_addr antelope;
        antelope.S_un.S_addr = ulAddr;
        if (strcmp(inet_ntoa(antelope),pHost)==0) {
            return TRUE;
        }
    }
    return FALSE;
}
void msip_call_hangup_fast(pjsua_call_id call_id, pjsua_call_info *p_call_info){
    pjsua_call_info call_info;
    if (!p_call_info) {
        if (pjsua_call_get_info(call_id, &call_info) == PJ_SUCCESS) {
            p_call_info = &call_info;
        }
    }
    if (p_call_info) {
        if (p_call_info->state==PJSIP_INV_STATE_CALLING
            || (p_call_info->role==PJSIP_ROLE_UAS && p_call_info->state==PJSIP_INV_STATE_CONNECTING)
            ) {
                pjsua_call *call = &pjsua_var.calls[call_id];
                pjsip_tx_data *tdata = NULL;
                // Generate an INVITE END message
                if (pjsip_inv_end_session(call->inv, 487, NULL, &tdata) != PJ_SUCCESS || !tdata) {
                    pjsip_inv_terminate(call->inv,487,PJ_TRUE);
                } else {
                    // Send that END request
                    if (pjsip_endpt_send_request(pjsua_get_pjsip_endpt(), tdata, -1, NULL, NULL) != PJ_SUCCESS) {
                        pjsip_inv_terminate(call->inv,487,PJ_TRUE);
                    }
                }
                return;
        }
    }
    pjsua_call_hangup(call_id, 0, NULL, NULL);
}

void ParseSIPURI(CString in, SIPURI* out){
    //  tone_gen.toneslot = -1;
    //  tone_gen = NULL;

    // "WEwewew rewewe" <sip:qqweqwe@qwerer.com;rrrr=tttt;qweqwe=rrr?qweqwr=rqwrqwr>
    // sip:qqweqwe@qwerer.com;rrrr=tttt;qweqwe=rrr?qweqwr=rqwrqwr
    if (in.Right(1) == _T(">")) {
        in = in.Left(in.GetLength()-1);
    }
    out->name = _T("");
    out->user = _T("");
    out->domain = _T("");
    out->parameters = _T("");

    int start = in.Find( _T("sip:") );
    int end;
    if (start>0)
    {
        out->name = in.Left(start);
        out->name.Trim(_T(" \" <"));
        if (!out->name.CompareNoCase(_T("unknown")))
        {
            out->name = _T("");
        }
    }
    if (start>=0)
    {
        start+=4;
    } else {
        start = 0;
    }
    end = in.Find( _T("@"), start );
    if (end>=0)
    {
        out->user=in.Mid(start,end-start);
        start=end+1;
    }
    end = in.Find( _T(";"), start );
    if (end>=0) {
        out->domain = in.Mid(start,end-start);
        start=end;
        out->parameters = in.Mid(start);
    } else {
        end = in.Find( _T("?"), start );
        if (end>=0) {
            out->domain = in.Mid(start,end-start);
            start=end;
            out->parameters = in.Mid(start);
        } else {
            out->domain = in.Mid(start);
        }
    }
}
CString GetSIPURI(CString str, bool isSimple, bool isLocal){
    CString rab = str;
    rab.MakeLower();
    int pos = rab.Find(_T("sip:"));
    if (pos==-1)
    {
        str=_T("sip:")+str;
    }
    if (!isLocal) {
        pos = str.Find(_T("@"));
        if (accountSettings.accountId && pos==-1) {
            str.Append(_T("@")+accountSettings.account.domain);
        }
    }
    if (str.GetAt(str.GetLength()-1)=='>')
    {
        str = str.Left(str.GetLength()-1);
        if (!isSimple) {
            if (!isLocal || !accountSettings.accountId) {
                AddTransportSuffix(str);
            }
        }
        str += _T(">");
    } else {
        if (!isSimple) {
            if (!isLocal || !accountSettings.accountId) {
                AddTransportSuffix(str);
            }
        }
        str = _T("<") + str + _T(">");
    }
    return str;
}
void AddTransportSuffix(CString &str){
    switch (g_transport)
    { 
    case MSIP_TRANSPORT_TCP:
        str.Append(_T(";transport=tcp"));
        break;
    case MSIP_TRANSPORT_TLS:
        str.Append(_T(";transport=tls"));
        break;
    }
}
CString PjToStr(const pj_str_t* str, BOOL utf){
    CStringA rab;
    rab.Format("%.*s", str->slen, str->ptr);
    if (utf)
    {
#ifdef _UNICODE
        WCHAR* msg;
        Utf8DecodeCP(rab.GetBuffer(), CP_ACP, &msg);
        return msg;
#else
        return Utf8DecodeCP(rab.GetBuffer(), CP_ACP, NULL);
#endif
    } else 
    {
        return CString(rab);
    }
}
pj_str_t StrToPjStr(CString str){
    return pj_str(StrToPj(str));
}
char* StrToPj(CString str){
#ifdef _UNICODE
    return Utf8EncodeUcs2(str.GetBuffer());
#else
    return Utf8EncodeCP(str.GetBuffer(), CP_ACP);
#endif
}
bool SelectSIPAccount(CString number, pjsua_acc_id &acc_id, pj_str_t &pj_uri){
    SIPURI sipuri;
    ParseSIPURI(number, &sipuri);
    if (pjsua_acc_is_valid(g_acc_id) && pjsua_acc_is_valid(g_acc_id_local)) {
        acc_id = g_acc_id;
        if (accountSettings.account.domain != sipuri.domain) {
            int pos = sipuri.domain.Find(_T(":"));
            CString domainWithoutPort = RemovePort(sipuri.domain);
            if (domainWithoutPort.CompareNoCase(_T("localhost"))==0 || IsIP(domainWithoutPort)) {
                acc_id = g_acc_id_local;
            }
        }
    } else if (pjsua_acc_is_valid(g_acc_id)) {
        acc_id = g_acc_id;
    } else if (pjsua_acc_is_valid(g_acc_id_local)) {
        acc_id = g_acc_id_local;
    } else {
        return false;
    }
    pj_uri = StrToPjStr ( GetSIPURI(number, acc_id == g_acc_id_local, acc_id == g_acc_id_local) );
    return true;
}
void call_hangup_all_noincoming(bool onHold){
    pjsua_call_id call_ids[PJSUA_MAX_CALLS];
    unsigned count = PJSUA_MAX_CALLS;
    if (pjsua_enum_calls ( call_ids, &count)==PJ_SUCCESS)  {
        for (unsigned i = 0; i < count; ++i) {
            pjsua_call_info call_info;
            pjsua_call_get_info(call_ids[i], &call_info);
            if (call_info.role!=PJSIP_ROLE_UAS || (call_info.state!=PJSIP_INV_STATE_INCOMING && call_info.state!=PJSIP_INV_STATE_EARLY)) {
                if (onHold && call_info.media_status == PJSUA_CALL_MEDIA_LOCAL_HOLD) {
                    continue;
                }
                msip_call_hangup_fast(call_ids[i]);
            }
        }
    }
}
void SetSoundDevice(int outDev, bool forse){
    int in,out;
    if (forse || pjsua_get_snd_dev(&in,&out)!=PJ_SUCCESS || g_audio_input!=in || outDev!=out ) {
        pjsua_set_snd_dev(g_audio_input, outDev);
    }
}
void UpdateSoundDevicesIds(){
    g_audio_input=-1;
    g_audio_output=-2;
    g_audio_ring=-2;

    unsigned count = 128;
    pjmedia_aud_dev_info aud_dev_info[128];
    pjsua_enum_aud_devs(aud_dev_info, &count);

    CString audioInputDevice    = accountSettings.audioInputDevice;
    CString audioOutputDevice   = accountSettings.audioOutputDevice;
    CString audioRingDevice     = accountSettings.audioRingDevice;

    for (unsigned i=0;i<count;i++)
    {
        CString audDevName(aud_dev_info[i].name);
        if (aud_dev_info[i].input_count && !audioInputDevice.Compare(audDevName)) {
            g_audio_input = i;
        }
        if (aud_dev_info[i].output_count) {
            if (!audioOutputDevice.Compare(audDevName)) {
                g_audio_output = i;
            }
            if (!audioRingDevice.Compare(audDevName)) {
                g_audio_ring = i;
            }
        }
    }
}
int VideoStreamDeviceId(CString name){
    return PJMEDIA_VID_DEFAULT_RENDER_DEV;
}
int VideoCaptureDeviceId(CString name){
    unsigned count = 64;
    pjmedia_vid_dev_info vid_dev_info[64];
    pjsua_vid_enum_devs(vid_dev_info, &count);
    for (unsigned i=0;i<count;i++) {
        if (vid_dev_info[i].fmt_cnt && (vid_dev_info[i].dir==PJMEDIA_DIR_ENCODING || vid_dev_info[i].dir==PJMEDIA_DIR_ENCODING_DECODING)) {
            CString vidDevName(vid_dev_info[i].name);
            if ((!name.IsEmpty() && name == vidDevName)
                ||
                (name.IsEmpty() && accountSettings.videoCaptureDevice == vidDevName)) {
                return vid_dev_info[i].id;
            }
        }
    }
    return PJMEDIA_VID_DEFAULT_CAPTURE_DEV;
}

void PJAccountAddLocal(){
    if (MACRO_ENABLE_LOCAL_ACCOUNT) {
        pjsua_acc_config acc_cfg;
        //PJAccountConfig(&acc_cfg);
        pjsua_acc_config_default(&acc_cfg);
        acc_cfg.priority--;
        pjsua_transport_data *t = &pjsua_var.tpdata[0];
        CString localURI;
        localURI.Format(_T("<sip:%s>"), PjToStr(&t->local_name.host));
        acc_cfg.id = StrToPjStr(localURI);
        pjsua_acc_add(&acc_cfg, PJ_TRUE, &g_acc_id_local);
        acc_cfg.priority++;
    }
}

// vid_wnd_flags
// vid_stream_wnd_flags
void PJAccountConfig(pjsua_acc_config *acc_cfg){
    pjsua_acc_config_default(acc_cfg);
#ifdef _GLOBAL_VIDEO
    acc_cfg->vid_in_auto_show       = PJ_TRUE;
    acc_cfg->vid_out_auto_transmit  = PJ_TRUE;
    acc_cfg->vid_cap_dev            = VideoCaptureDeviceId();

    // 这里设置了窗口 一般属性
    //acc_cfg->vid_wnd_flags        = PJMEDIA_VID_DEV_WND_RESIZABLE;
    //acc_cfg->vid_wnd_flags        = PJMEDIA_VID_DEV_WND_BORDER; // 0.0 这是有边框的意思

    acc_cfg->vid_wnd_flags          = PJMEDIA_VID_DEV_WND_UTILITY | PJMEDIA_VID_DEV_WND_ALWAYS_ON_TOPD | PJMEDIA_VID_DEV_WND_INPUT_FOCUS | PJMEDIA_VID_DEV_WND_MOUSE_FOCUS
    | PJMEDIA_VID_DEV_WND_ALLOW_HIGHDPI | PJMEDIA_VID_DEV_WND_SKIP_TASKBAR;


    // 这里设置了窗口 自定义属性
    acc_cfg->vid_stream_wnd_flags   = PJMEDIA_VID_DEV_WND_UTILITY | PJMEDIA_VID_DEV_WND_ALWAYS_ON_TOPD 
        | PJMEDIA_VID_DEV_WND_ALLOW_HIGHDPI | PJMEDIA_VID_DEV_WND_SKIP_TASKBAR;


    // PJMEDIA_VID_DEV_WND_INPUT_GRABBED 类似VM 将鼠标困住

    // 假如 vid_stream_wnd_flags 不是总在前方 将不能覆盖任务栏

    // 暂时不是这里
    //acc_cfg->vid_preview_wnd_flags  = PJMEDIA_VID_DEV_WND_UTILITY | PJMEDIA_VID_DEV_WND_ALWAYS_ON_TOPD | PJMEDIA_VID_DEV_WND_ALLOW_HIGHDPI;

#endif

}

