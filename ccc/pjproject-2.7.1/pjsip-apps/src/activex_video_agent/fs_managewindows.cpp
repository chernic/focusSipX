// fs_managewindows.cpp : Implementation of CApp
#include "stdafx.h"
#include <pj/types.h>
#include <pjsua-lib/pjsua.h>

#include "fs_managewindows.h"

// 注意这变量声明为全局
pjmedia_vid_dev_index Pwidx;
pjmedia_vid_dev_index Swidx;
pjsua_vid_win_id Pvid;
pjsua_vid_win_id Svid;

inline char* UnicodeToAnsi( const wchar_t* szStr )  {
    int nLen = WideCharToMultiByte( CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL );
    if (nLen == 0)
    {
        return NULL;
    }
    char* pResult = new char[nLen];
    WideCharToMultiByte( CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL );
    return pResult;
}
void ResetPJmedia(void){
    ShowPreviwWindow(PJ_FALSE);
    ShowStreamWindow(PJ_FALSE);
    ResetPJmediaData();
}
void ResetPJmediaData(void){
    //这里必须初始化为0 否则手动关闭后不能再开启摄像头
    Pwidx = 0;
    Pvid  = PJSUA_INVALID_ID;
    Swidx = 0;
    Svid  = PJSUA_INVALID_ID;
}

pj_str_t get_local_dir(void){
    // ABChernic
    // C++获取当前模块的路径(dll/exe)
    // http://blog.csdn.net/oyt123/article/details/43532089
    char    szBuff[MAX_PATH] = {0};
    HMODULE hModuleInstance = _AtlBaseModule.GetModuleInstance();
    GetModuleFileNameA(hModuleInstance,szBuff, MAX_PATH);
    CString strTmp = CA2T(szBuff);
    CString m_strExePath = strTmp.Mid(0, strTmp.ReverseFind('\\'));

    // ABChernic
    // CString 2 wchar_t*
    // http://blog.csdn.net/andy20081251/article/details/22286243
    LPTSTR pstr = m_strExePath.GetBuffer();
    m_strExePath.ReleaseBuffer();

    // ABChernic
    //pj_str_t dir = pj_str("E:\\github\\focusSip\\src\\pjproject-2.7.1\\Debug");
    pj_str_t dir = pj_str( UnicodeToAnsi(pstr) );

    return dir;
}

Overlay_t gOverlay;

void DisplayModeChange(void){
    int w = GetSystemMetrics(SM_CXSCREEN)/2;
    int h = GetSystemMetrics(SM_CYSCREEN)/2;

  // gOverlay.switch2NavbarL(w, h);
  // gOverlay.switch2NavbarR(w, h);
  // gOverlay.switch2FooterL(w, h);
  // gOverlay.switch2FooterR(w, h);
    
  // gOverlay.switchInNavbarL(w, h);
  // gOverlay.switchInNavbarR(w, h);
  // gOverlay.switchInFooterL(w, h);
     gOverlay.switchInFooterR(w, h);
}
int InitPreviwWindow(int overlay_mode){
    //pjsua_vid_win_id  wid;
    int id = VideoCaptureDeviceId();
    Pvid = pjsua_vid_preview_get_win(Pwidx);
    if (Pvid != PJSUA_INVALID_ID) {
        if (Pwidx != id) {
            pjsua_vid_preview_stop(Pwidx);
        } else {
            return -1;
        }
    }
    Pwidx = id;

    pjsua_vid_preview_param pre_param;

    pj_status_t status;

    pjsua_vid_preview_param_default(&pre_param);

    //pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_INPUT_GRABBED;     // 004
    pre_param.show             = PJ_FALSE;
    //pre_param.wnd.info.window  = win;

    /*
     * Window flags.  The value is a bitmask combination of
     * #pjmedia_vid_dev_wnd_flag.
     *
     * Default: 0.
     */
    // pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_BORDER;         // 001
    // pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_RESIZABLE;      // 002
    pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_ALWAYS_ON_TOPD;    // 008

    pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_ALLOW_HIGHDPI;     // 016
    pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_UTILITY;           // 032
    pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_SKIP_TASKBAR;      // 064
    // pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_INPUT_FOCUS;    // 128
    // pre_param.wnd_flags       |= PJMEDIA_VID_DEV_WND_MOUSE_FOCUS;    // 256

    status = pjsua_vid_preview_start(Pwidx, &pre_param);
    if (status != PJ_SUCCESS) {
        return -1;
    }

    MakePreviwWindow(overlay_mode);

    return 0;
}
int MakePreviwWindow(int overlay_mode){
    pjsua_vid_win_info      wi;
    int id = VideoCaptureDeviceId();

    Pvid = pjsua_vid_preview_get_win(Pwidx);
    if (Pvid == PJSUA_INVALID_ID)
        return -1;
    if (Pwidx != id)
        return -1;
    Pvid = pjsua_vid_preview_get_win(Pwidx);
    pjsua_vid_win_get_info(Pvid, &wi);

    pj_str_t dir = get_local_dir();

    int w = GetSystemMetrics(SM_CXSCREEN)/2;
    int h = GetSystemMetrics(SM_CYSCREEN)/2;

    switch(overlay_mode){
        case IN_NAVBAR_L:{
            gOverlay.switchInNavbarL(w, h);
        }break;
        
        case IN_NAVBAR_R:{
            gOverlay.switchInNavbarR(w, h);
        }break;
        
        case IN_FOOTER_L:{
            gOverlay.switchInFooterL(w, h);
        }break;
        
        case IN_FOOTER_R:{
            gOverlay.switchInFooterR(w, h);
        }break;
    }
    
    // ABChernic
    pjsua_vid_win_set_pos        ( Pvid, &gOverlay.Complex.pos );
    pjsua_vid_win_set_size       ( Pvid, &gOverlay.Complex.siz );

    pjsua_vid_win_set_previw_pos ( Pvid, &gOverlay.Foreground.pos );
    pjsua_vid_win_set_previw_size( Pvid, &gOverlay.Foreground.siz );

    pjsua_vid_win_set_stream_pos ( Pvid, &gOverlay.Background.pos );
    pjsua_vid_win_set_stream_size( Pvid, &gOverlay.Background.siz );

    pjsua_vid_win_set_button_size( Pvid, &gOverlay.Button.siz  );
    pjsua_vid_win_set_dir        ( Pvid, &dir);

    return 0;
}
int MakeStreamWindow(PosSize_t psS){

    pjsua_vid_win_info wi;
    int id = VideoStreamDeviceId();

    // 获取来电视频的句柄
    Swidx = id;
    Svid = pjsua_vid_stream_get_win(Swidx);
    //if (Svid == PJSUA_INVALID_ID)
    //    return -1;
    //if (Swidx != id)
    //    return -1;
    pjsua_vid_win_get_info ( Svid, &wi);

    pj_str_t dir = get_local_dir();

    // ABChernic
    pjsua_vid_win_set_pos           ( Svid, &gOverlay.Stream.pos);
    pjsua_vid_win_set_size          ( Svid, &gOverlay.Stream.siz);
  //pjsua_vid_win_set_previw_pos    ( Pvid, &gOverlay.Foreground.pos  );
  //pjsua_vid_win_set_previw_size   ( Pvid, &gOverlay.Foreground.siz  );
    
  //pjsua_vid_win_set_stream_pos    ( Svid, &gOverlay.Background.pos  );
  //pjsua_vid_win_set_stream_size   ( Svid, &gOverlay.Background.siz  );
    pjsua_vid_win_set_stream_pos    ( Svid, &gOverlay.Stream.pos);
    pjsua_vid_win_set_stream_size   ( Svid, &gOverlay.Stream.siz);

    const pjmedia_rect_size btn_size = {0,0};
    pjsua_vid_win_set_button_size   ( Svid, &btn_size );
    pjsua_vid_win_set_dir           ( Svid, &dir);
    return 0;
}

int ShowPreviwWindow(pj_bool_t IsShow){
    if (Pvid == PJSUA_INVALID_ID)
        return 1;

    if( gOverlay.IsComplexShow == PJ_TRUE ){
        pjsua_vid_win_set_show ( Pvid, IsShow);
    }else{
        pjsua_vid_win_set_show ( Pvid, PJ_FALSE);
    }
    return 0;
}
int ShowStreamWindow(pj_bool_t IsShow){
    if (Svid == PJSUA_INVALID_ID)
        return 1;
    
    if( gOverlay.IsStreamShow == PJ_TRUE ){
        pjsua_vid_win_set_show ( Svid, IsShow);
    }else{
        pjsua_vid_win_set_show ( Svid, PJ_FALSE);
    }
    return 0;
}

