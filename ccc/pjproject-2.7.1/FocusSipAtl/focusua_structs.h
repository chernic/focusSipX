/* this ALWAYS GENERATED file contains the definitions for the interfaces */

/* File created by MIDL compiler version 7.00.0500 */
/* at Wed Dec 13 19:10:14 2017
 */
/* Compiler settings for ..\src\activex_video_agent\pjsua-structs.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data
    VC __declspec() decoration level:
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef __pjsua2Dstructs_h__
#define __pjsua2Dstructs_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef double Fs_Doub; // double
typedef int    Fs_Bool; // Boolean
typedef int    Fs_Numb; // Number
typedef long   Fs_Long; // Long
typedef long   Fs_Stat; // Status
typedef BSTR   Fs__Str; // String
typedef BSTR   Fs__URI; // Universal Resource Identifier ��Դ��־��

///////////////////////////////////////////////////////////////////
/* 01 URI context.(URI������)
 * enum pjsip_uri_context_e
 * From: \pjsip\include\pjsip\sip_uri.h
 */
typedef enum 
Focusip_Uri_Context{

    PJSIPX_URI_IN_REQ_URI       = 0,                                    /**< The URI is in Request URI. */

    PJSIPX_URI_IN_FROMTO_HDR    = ( PJSIPX_URI_IN_REQ_URI + 1 ) ,       /**< The URI is in From/To header. */

    PJSIPX_URI_IN_CONTACT_HDR   = ( PJSIPX_URI_IN_FROMTO_HDR + 1 ) ,    /**< The URI is in Contact header. */

    PJSIPX_URI_IN_ROUTING_HDR   = ( PJSIPX_URI_IN_CONTACT_HDR + 1 ) ,   /**< The URI is in Route/Record-Route header. */

    PJSIPX_URI_IN_OTHER         = ( PJSIPX_URI_IN_ROUTING_HDR + 1 )     /**< Other context (web page, business card, etc.) */
}Focusip_Uri_Context;

// 02 ����״̬
typedef enum 
Focusip_Call_State{
    PJSUA_CALL_STATE_NULL           = 0,
    PJSUA_CALL_STATE_CALLING        = ( PJSUA_CALL_STATE_NULL + 1 ),
    PJSUA_CALL_STATE_INCOMING       = ( PJSUA_CALL_STATE_CALLING + 1 ),
    PJSUA_CALL_STATE_EARLY          = ( PJSUA_CALL_STATE_INCOMING + 1 ),
    PJSUA_CALL_STATE_CONNECTING     = ( PJSUA_CALL_STATE_EARLY + 1 ),
    PJSUA_CALL_STATE_CONFIRMED      = ( PJSUA_CALL_STATE_CONNECTING + 1 ),
    PJSUA_CALL_STATE_DISCONNECTED   = ( PJSUA_CALL_STATE_CONFIRMED + 1 )
}Focusip_Call_State;

// 03 ��ϯ״̬
typedef enum 
Focusip_Buddy_State{
    PJSUA_BUDDY_STATE_UNKNOWN   = 0,
    PJSUA_BUDDY_STATE_ONLINE = ( PJSUA_BUDDY_STATE_UNKNOWN + 1 ) ,
    PJSUA_BUDDY_STATE_OFFLINE    = ( PJSUA_BUDDY_STATE_ONLINE + 1 )
}Focusip_Buddy_State;

/* 
 * struct sip_uri
 * From: \pjsip\include\pjsip\sip_uri.h
 * see : http://www.pjsip.org/pjsip/docs/html/structpjsip__uri.htm
 *
 * sipʾ��
 *     sip:user:password@localhost:5060;
 *         transport=tcp;user=ip;ttl=255;
 *         lr=1;maddr=127.0.0.1;
 *         method=ACK;pickup=hurry;
 *         message=I%20am%20sorry?
 *         Subject=Hello%20There&Server=SIP%20Server
 */ //04 SIP URI(��Դ��־��)
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("04BA8132-E099-44e6-A668-E1B526517A9D")
struct Focusip_Sip_Uri {
    Fs__Str display;        //
    Fs__Str user;           // Optional user part.                      ��ѡ��/�û�
    Fs__Str passwd;         // Optional password part.                  ��ѡ��/����
    Fs__Str host;           // Host part, always exists.                ��ѡ��/������
    Fs_Numb port;           // Optional port number, or zero.           ��ѡ��/�˿ں�
    Fs__Str param_method;   // Optional method parameter.               ��ѡ����/����
    Fs__Str param_transport;// Optional transport parameter.            ��ѡ����/����
    Fs_Numb param_ttl;      // Optional TTL param, or -1.               ��ѡ����/time-to-liveֵ
                            // ������˼��һ�����ݰ��������ϴ�������ʱ��,��λ����������,
                            // ���ʱ�䵹��ʱ��0ʱ���ݰ��������������ֵΪ255
    Fs_Numb param_lr;       // Optional loose routing param, or zero    ��ѡ����/��ɢ·��(lr)
                            // �ο�IP�еĸ���:�ϸ�·����must���ɳ�·����preferred.
    Fs__Str param_maddr;    // Optional maddr param.                    ��ѡ����/�ಥ��ַ(maddress)
                            // maddr param is not allowed in From and To header.
                            // ����ͻ���������ַ����������ô�������ӡ�maddr��������Viaͷ��ֵ�ϣ�
                            // �����������ֵָ�����Ŀ�ĵ�ַ������Ipv4��˵��Ӧ�����ӡ�ttl��������1
    Fs__Str param_other;    // Other parameters grouped together.       ��ѡ����/��������
    Fs__Str param_header;   // Optional header parameter.               ��ѡ����/
}Focusip_Sip_Uri;
 
/*
 *struct pjsip_cred_info
 *From: \pjsip\include\pjsip\sip_auth.h
 *see : \pjsip\docs\html\page_pjsip_sample_simple_ua_c.htm
 *see : http://www.pjsip.org/pjsip/docs/html/structpjsip__cred__info.htm
 *more: Message-Digest Algorithm 5(��Ϣ-ժҪ�㷨5)
 */ //05 ��֤��Ϣ
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("05163613-C3DB-4a72-B98A-E4BCC56DB163")
struct Focusip_Cred_Info{
    Fs__Str realm;          // pj_str("sip.server.realm")  ������������
    Fs__Str scheme;         // pj_str("digest")            Buffer to be filled with HMAC XX(MD5) digest.
    Fs__Str username;       // pj_str("theuser");          �û���
    Fs_Numb hashed;         // cred.data_type != 0         �ѱ�����
    Fs__Str data;           // pj_str("thepassword");      ����
}Focusip_Cred_Info;

// 06 �˻���Ϣ
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("062143D1-58A4-4044-8A25-C13D460D4D5D")
struct Focusip_Acc_Config{
    Fs__URI acc_uri;
    Fs__URI reg_uri;
    Fs__URI contact_uri;
    Fs__URI proxy_uri;
    Fs_Numb reg_timeout;
    SAFEARRAY * cred_info;
}Focusip_Acc_Config;

// 07 ͨ����Ϣ
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("07076348-B31B-4844-8BF1-FC8DEF3BC121")
struct Focusip_Call_Info{
    Fs_Numb     index;                  // c1->id;
    Fs_Bool     active;                 // pjsua_call_is_active(callIndex);
    Fs_Bool     is_uac;                 // (pjsua_call_info->role == PJSIP_ROLE_UAC)
    Fs__Str     local_info;             // pjsua_call_info->local_info
    Fs__Str     remote_info;            // pjsua_call_info->remote_info
    Fs_Numb     state;                  // pjsua_call_info->state;
    Fs__Str     state_text;             // pjsua_call_info->state_text);
    Fs_Numb     connect_duration;       // pjsua_call_info->connect_duration.sec;
    Fs_Numb     total_duration;         // pjsua_call_info->total_duration.sec;
    Fs_Numb     last_status;            // pjsua_call_info->last_status;
    Fs__Str     last_status_text;       // pjsua_call_info->last_status_text);
    Fs_Bool     has_media;              // pjsua_call_has_media(callIndex);
    Fs_Numb     conf_slot;              // pjsua_call_info->conf_slot;
}Focusip_Call_Info;

// 08 ��ϯ��Ϣ
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("08CC26A6-29F4-4006-B906-D3F0C115E487")
struct Focusip_Buddy_Info{
    Fs_Numb     index;                  // F01 ��ʶ
    Fs__Str     number;                 // F02 �绰����
    Fs__Str     name;                   // F02 ����
    Fs__Str     host;                   // F03 ������
    Fs_Numb     port;                   // F04 �˿ں�
    Fs__URI     uri;                    // F05 URI
	Fs__Str	    contact;                // F07 ��ϵ��

    Fs_Numb     status;                 // F08 ����״̬
    Fs__Str     status_text;            // F09 ״̬����

    Fs_Bool     monitor;                // F10 �Ƿ���
	Fs_Bool	    presence;	            // F11 �Ƿ��ϯ
	Fs_Bool	    directory;				// F12 �Ƿ�·��
	Fs_Bool		ringing;				// F13 �Ƿ�����	
	Fs_Bool		candidate;				// F14 �Ƿ�����
}Focusip_Buddy_Info;

// 09 �˿���Ϣ
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("096B030B-EB36-4cd8-A2D9-FA3C03267FF2")
struct Focusip_Conf_Port_Info{
    Fs_Numb slot_id;
    Fs__Str name;
    Fs_Numb clock_rate;
    Fs_Numb channel_count;
    Fs_Numb samples_per_frame;
    Fs_Numb bits_per_sample;
    SAFEARRAY * listeners;
}Focusip_Conf_Port_Info;


///////////////////////////////////////////////////////////////////
// 10 ע����Ϣ
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("10EB7884-24E1-4768-AF24-528CBB905E1C")
struct Focusip_Reg_Info{
    Fs_Numb index;
}Focusip_Reg_Info;

// 11
// typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("11908C68-BA3B-4e04-87FA-D1DF6B8DA88E")
// struct Focusip_TI_Info{
    // Fs_Numb index;
// }Focusip_TI_Info;


///////////////////////////////////////////////////////////////////
// 20 �˻���Ϣ
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("20390D89-4081-432c-BEEA-D22A8CDB1958")
struct Focusip_Acc_Info{
    Fs_Numb index;
    Fs__URI acc_uri;
    Fs_Bool has_registration;
    Fs_Numb expires;
    Fs_Numb status_code;
    Fs__Str status_text;
    Fs_Bool online_status;
}Focusip_Acc_Info;

// 21 ȫ����Ϣ
typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("210EF560-3388-4855-AE15-F2824B0FFF28")
struct Focusip_Config{
    Fs_Numb udp_port;
    Fs__Str sip_host;
    Fs_Numb sip_port;
    Fs_Numb rtp_port;
    Fs_Numb msg_logging;
    Fs_Numb max_calls;
    Fs_Numb conf_ports;
    Fs_Numb thread_cnt;
    Fs__Str stun_srv1;
    Fs_Numb stun_port1;
    Fs__Str stun_srv2;
    Fs_Numb stun_port2;
    Fs_Numb snd_player_id;
    Fs_Numb snd_capture_id;
    Fs_Numb clock_rate;
    Fs_Bool null_audio;
    Fs_Numb quality;
    Fs_Numb complexity;
    SAFEARRAY * codec_arg;
    Fs_Numb auto_answer;
    Fs_Numb uas_refresh;
    Fs__Str outbound_proxy;
    SAFEARRAY * acc_config;
    Fs_Numb log_level;
    Fs_Numb app_log_level;
    long log_decor;
    Fs__Str log_filename;
    SAFEARRAY * buddy_uri;
}Focusip_Config;



extern RPC_IF_HANDLE __MIDL_itf_pjsua2Dstructs_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_pjsua2Dstructs_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
