/* 
 * Copyright (C) 2017 Focustar (chernic@qq.com)
 */
#pragma once

#include "define.h"
#include "utf.h"
#include <pjsua-lib/pjsua.h>
#include <pjsua-lib/pjsua_internal.h>

// ABChernic
typedef void (WINAPI *PSWITCHTOTHISWINDOW) (HWND,BOOL);

typedef struct PosSize
{
    LONG    left;
    LONG    top;
    LONG    wight;
    LONG    height;
}PosSize_t;

extern int          g_transport;
extern pjsua_acc_id g_acc_id;
extern pjsua_acc_id g_acc_id_local;
extern int          g_audio_input;
extern int          g_audio_output;
extern int          g_audio_ring;



enum EUserWndMessages
{
	UM_FIRST_USER_MSG = (WM_USER + 0x100 + 1),

	UM_NOTIFYICON,

	UM_CREATE_RINGING,
	UM_CALL_ANSWER,
	UM_CALL_HANGUP,
	//UM_TAB_ICON_UPDATE,
	//UM_ON_ACCOUNT,
	//UM_ON_REG_STATE2,
	//UM_ON_CALL_STATE,
	//UM_ON_CALL_TRANSFER_STATUS,
	//UM_ON_MWI_INFO,
	//UM_ON_CALL_MEDIA_STATE,
	//UM_ON_PAGER,
	//UM_ON_PAGER_STATUS,
	//UM_ON_BUDDY_STATE,
	//UM_ON_PLAYER_PLAY,
	//UM_ON_PLAYER_STOP,
	//UM_SHELL_EXECUTE,
	//UM_SET_PANE_TEXT,
	//UM_REFRESH_LEVELS,
	//UM_USERS_DIRECTORY,
	//UM_ON_BALANCE_PLAIN,
	//UM_ON_BALANCE_OPTIONS,
	//
	//IDT_TIMER_IDLE,
	//IDT_TIMER_TONE,
	//IDT_TIMER_BALANCE,
	//IDT_TIMER_INIT_RINGIN,
	//IDT_TIMER_CALL,
	//IDT_TIMER_CONTACTS_BLINK,
	//IDT_TIMER_DIRECTORY,
	//IDT_TIMER_SAVE,
	//IDT_TIMER_SWITCH_DEVICES,
	//IDT_TIMER_HEADSET,
	//IDT_TIMER_VU_METER,
	//IDT_TIMER_AUTOANSWER,
	//
	//UM_CLOSETAB,
	//UM_DBLCLICKTAB,
	//UM_QUERYTAB,
};

enum {MSIP_MESSAGE_TYPE_LOCAL, MSIP_MESSAGE_TYPE_REMOTE, MSIP_MESSAGE_TYPE_SYSTEM};
enum {MSIP_TRANSPORT_AUTO, MSIP_TRANSPORT_TCP, MSIP_TRANSPORT_TLS};
enum {MSIP_CALL_OUT, MSIP_CALL_IN, MSIP_CALL_MISS};
enum {MSIP_SOUND_CUSTOM,MSIP_SOUND_MESSAGE_IN, MSIP_SOUND_MESSAGE_OUT, MSIP_SOUND_HANGUP, MSIP_SOUND_RINGIN, MSIP_SOUND_RINGIN2, MSIP_SOUND_RINGOUT};
enum msip_srtp_type {MSIP_SRTP_DISABLED, MSIP_SRTP};
enum msip_shortcut_type {MSIP_SHORTCUT_CALL, MSIP_SHORTCUT_VIDEOCALL, MSIP_SHORTCUT_MESSAGE, MSIP_SHORTCUT_DTMF};

struct SIPURI {
	CString name;
	CString user;
	CString domain;
	CString parameters;
};

struct call_tonegen_data
{
   pj_pool_t          *pool;
   pjmedia_port       *tonegen;
   pjsua_conf_port_id  toneslot;
};

struct call_user_data
{
    pjsua_call_id call_id;
    call_tonegen_data *tonegen_data;
    pj_timer_entry auto_hangup_timer;
    msip_srtp_type srtp;
    CString userAgent;
    CString diversion;
    CString commands;
    bool inConference;
    call_user_data(pjsua_call_id call_id): tonegen_data(NULL)
        ,inConference(false)
        ,srtp(MSIP_SRTP_DISABLED)
        {
            this->call_id = call_id;
            pj_bzero(&auto_hangup_timer, sizeof(auto_hangup_timer));
            auto_hangup_timer.id = PJSUA_INVALID_ID;
        }
};
void UpdateSoundDevicesIds();
void SetSoundDevice(int outDev, bool forse = 0);

#ifdef _GLOBAL_VIDEO
	int VideoStreamDeviceId( CString name=_T(""));
    int VideoCaptureDeviceId(CString name=_T(""));
#endif


void PJAccountAddLocal();
void PJAccountConfig(pjsua_acc_config *acc_cfg);


BOOL IsIP(CString host);
CString RemovePort(CString domain);
void msip_call_hangup_fast(pjsua_call_id call_id,pjsua_call_info *p_call_info = NULL);
CString PjToStr(const pj_str_t* str, BOOL utf = FALSE);
pj_str_t StrToPjStr(CString str);
char* StrToPj(CString str);
CString GetSIPURI(CString str, bool isSimple = false, bool isLocal = false);
void AddTransportSuffix(CString &str);
void ParseSIPURI(CString in, SIPURI* out);
void call_hangup_all_noincoming(bool onHold=false);
bool SelectSIPAccount(CString number, pjsua_acc_id &acc_id, pj_str_t &pj_uri);
