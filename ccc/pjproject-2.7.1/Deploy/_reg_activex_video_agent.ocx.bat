@echo off

cd i386-Win32-vc8-Debug
regsvr32 "activex_video_agent.ocx"

@pause
@exit



@REM _IVideoAgentEvernts\{DC91CBCE-4B9E-4369-80B9-39341EEFD814}
@REM App\ {F89DA516-42E5-43A0-8EF7-A960BA386CAB}
@REM IApp\{93462247-DA4E-4602-817B-26BA0C824E23}


_Dhwctrl\{F7C8D6A5-2595-4C2E-8403-121DD9F74317}
_DhwctrlEvents\{719102D4-D504-40AB-9E02-28D867193C49}
hwctrl\{E383BAC1-70D3-4A19-82B1-7C3237865791}




<OBJECT ID="hwctrl1" WIDTH=780 HEIGHT=84
 CLASSID="CLSID:E383BAC1-70D3-4A19-82B1-7C3237865791">
    <PARAM NAME="_Version" VALUE="65536">
    <PARAM NAME="_ExtentX" VALUE="20638">
    <PARAM NAME="_ExtentY" VALUE="2223">
    <PARAM NAME="_StockProps" VALUE="0">
</OBJECT>


QueryInterface  
AddRef
Release
GetTypeInfoCount
GetTypeInfo
GetIDsOfNames
Invoke
app_create
app_default_config
app_test_config
app_init
app_start
app_destroy
call_get_max_count
call_get_count
call_is_active
call_has_media
call_get_info
call_make_call
call_answer
call_hangup
call_set_hold
call_release_hold
call_xfer
call_dial_dtmf
call_send_im
call_typing
call_hangup_all
acc_get_count
acc_get_info
acc_add
acc_set_online_status
acc_set_registration
buddy_get_count
buddy_get_info
buddy_add
buddy_subscribe_pres
im_send_text
im_typing
conf_connect
conf_disconnect
player_create
player_get_conf_port
player_set_pos
player_destroy
recorder_create
recorder_get_conf_port
recorder_destroy
app_load_config
app_save_config
app_get_current_config
app_get_error_msg
app_verify_sip_url
call_get_textstat
app_handle_events
app_parse_uri
app_print_uri
app_compare_uri_string
buddy_del
acc_del
acc_find_for_outgoing
acc_enum_id
conf_enum_ports
conf_get_port_info







@REM F:\200_svn_icip6prj_totif\PjsipOcx\ABC\videoX\pjproject-2.7.1\Debug\activex_video_agent.ocx
@REM F:\200_svn_icip6prj_totif\PjsipOcx\ABC\videoX\hwctrl\debug\hwctrl.ocx

{DC91CBCE-4B9E-4369-80B9-39341EEFD814}
    ProxyStubClsid      {0002-*}
    ProxyStubClsid32    {0002-*}
    TypeLib             1.0

activex_video_agent.App
    CLSID               {F89DA516-42E5-43A0-8EF7-A960BA386CAB}
    CurVer              activex_video_agent.App.1

activex_video_agent.App.1
    CLSID               {F89DA516-42E5-43A0-8EF7-A960BA386CAB}

{F89DA516-42E5-43A0-8EF7-A960BA386CAB}
    InprocServer32      f:\200_svn_icip6prj_totif\PjsipOcx\ABC\videoX\pjproject-2.7.1\Debug\activex_video_agent.ocx
    ProgID              activex_video_agent.App.1
    Programmable
    TypeLib             {11E70413-8434-41B6-A5B6-F7DF79FEFC1A}
    TypeLib             activex_video_agent.App

{93462247-DA4E-4602-817B-26BA0C824E23}
    ProxyStubClsid      {0002-*}
    ProxyStubClsid32    {0002-*}
    TypeLib             1.0



###############################################################################
HKCR
{
	ActivePJSUA.App.1 = s 'App Class'
	{
		CLSID = s '{F89DA516-42E5-43A0-8EF7-A960BA386CAB}'
	}
	ActivePJSUA.App = s 'App Cla\ss'
	{
		CLSID = s '{F89DA516-42E5-43A0-8EF7-A960BA386CAB}'
		CurVer = s 'ActivePJSUA.App.1'
	}
	NoRemove CLSID
	{
		ForceRemove {F89DA516-42E5-43A0-8EF7-A960BA386CAB} = s 'App Class'
		{
			ProgID = s 'ActivePJSUA.App.1'
			VersionIndependentProgID = s 'ActivePJSUA.App'
			ForceRemove 'Programmable'
			InprocServer32 = s '%MODULE%'
			{
				val ThreadingModel = s 'Apartment'
			}
			'TypeLib' = s '{11E70413-8434-41B6-A5B6-F7DF79FEFC1A}'
		}
	}
}
###############################################################################
HKCR
{
    activex_video_agent.App.1 = s 'App Class'
    {
        CLSID = s '{F89DA516-42E5-43A0-8EF7-A960BA386CAB}'
    }
    activex_video_agent.App = s 'App Class'
    {
        CLSID = s '{F89DA516-42E5-43A0-8EF7-A960BA386CAB}'
        CurVer = s 'activex_video_agent.App.1'
    }
    NoRemove CLSID
    {
        ForceRemove {F89DA516-42E5-43A0-8EF7-A960BA386CAB} = s 'App Class'
        {
            ProgID = s 'activex_video_agent.App.1'
            VersionIndependentProgID = s 'activex_video_agent.App'
            ForceRemove 'Programmable'
            InprocServer32 = s '%MODULE%'
            {
                val ThreadingModel = s 'Apartment'
            }
            'TypeLib' = s '{11E70413-8434-41B6-A5B6-F7DF79FEFC1A}'
        }
    }
}