// ManageWindows.cpp : Implementation of CApp
#include "stdafx.h"
#include <pj/types.h>
#include <pjsua-lib/pjsua.h>

#include "define.h"
#include "settings.h"
#include "ManageWindows.h"
#include "Hangup.h"
#include "Complex.h"

// 注意这变量最好声明为全局
pjmedia_vid_dev_index Pwidx;
pjmedia_vid_dev_index Swidx;
pjsua_vid_win_id Pvid;
pjsua_vid_win_id Svid;
void ResetPJmedia(void){
    ShowPreviewWindow(PJ_FALSE);
    // 不用手动关闭远程窗口
    //ShowStreamWindow(PJ_FALSE);
    ResetPJmediaData();
}
void ResetPJmediaData(void){
    //这里必须初始化为0 否则手动关闭后不能再开启摄像头
    Pwidx = 0;
    Pvid  = PJSUA_INVALID_ID;
    Swidx = 0;
    Svid  = PJSUA_INVALID_ID;
}
// 创建摄像头视频

// wnd_flags wnd_flags wnd_flags
void CreatePreviewWindow(PosSize_t psP){
    //pjsua_vid_win_id  wid;
    int id = VideoCaptureDeviceId(); 
    Pvid = pjsua_vid_preview_get_win(Pwidx);
    if (Pvid != PJSUA_INVALID_ID) {
        if (Pwidx != id) {
            pjsua_vid_preview_stop(Pwidx);
        } else {
            return;
        }
    }
    Pwidx = id;
    pjsua_vid_preview_param pre_param;
    pj_status_t status;
    pjsua_vid_preview_param_default(&pre_param);

    pre_param.show              = PJ_FALSE;
    pre_param.wnd_flags         |= PJMEDIA_VID_DEV_CAP_OUTPUT_RESIZE;
    pre_param.wnd_flags         |= PJMEDIA_VID_DEV_CAP_OUTPUT_POSITION;
    pre_param.wnd_flags         |= PJMEDIA_VID_DEV_CAP_OUTPUT_HIDE;
    pre_param.wnd_flags         |= PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW_FLAGS;


    status = pjsua_vid_preview_start(Pwidx, &pre_param);
    if (status != PJ_SUCCESS) {
        return;
    }

    ResizePreviewWindow(psP);
}
// 将摄像头视频加到窗口
// 将宽字节wchar_t*转化为单字节char*  
// wchar_t*和char*之间的互相转换的那些事
// http://blog.csdn.net/lanshengsheng2012/article/details/27553791
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
void ResizePreviewWindow(PosSize_t psP){
    pjsua_vid_win_info      wi;
    //pjsua_vid_win_id  wid;
    int id = VideoCaptureDeviceId(); 
    const pjmedia_coord     pos     = {psP.left,  psP.top};
    const pjmedia_rect_size size    = {psP.wight, psP.height};

    Pvid = pjsua_vid_preview_get_win(Pwidx);

    if (Pvid == PJSUA_INVALID_ID)
        return ;

    if (Pwidx != id)            
        return ;

    Pvid = pjsua_vid_preview_get_win(Pwidx);

    pjsua_vid_win_get_info(Pvid, &wi);

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

    pjsua_vid_win_set_pos  ( Pvid, &pos);
    pjsua_vid_win_set_size ( Pvid, &size );
    pjsua_vid_win_set_dir  ( Pvid, &dir);
    pjsua_vid_win_set_show ( Pvid, PJ_TRUE);
}
// 将来电视频加到窗口
void ResizeStreamWindow(PosSize_t psS){
    pjsua_vid_win_info wi;
    //pjsua_vid_win_id wid;
    int id = VideoStreamDeviceId(); 
    const pjmedia_coord pos         = {psS.left, psS.top};
    const pjmedia_rect_size size    = {psS.wight, psS.height};

    Swidx = id;

    Svid = pjsua_vid_stream_get_win(Swidx);

    // 获取来电视频的句柄
    pjsua_vid_win_get_info ( Svid, &wi);

    // ABChernic
    pjsua_vid_win_set_pos  ( Svid, &pos);
    pjsua_vid_win_set_size ( Svid, &size );
    pjsua_vid_win_set_show ( Svid, PJ_TRUE);

    // 将来电视频子窗口化
    //
}
int ShowPreviewWindow(pj_bool_t IsShow){
    if (Pvid == PJSUA_INVALID_ID)
        return 1;
    pjsua_vid_win_set_show ( Pvid, IsShow);
    return 0;
}
int ShowStreamWindow(pj_bool_t IsShow){
    if (Svid == PJSUA_INVALID_ID)
        return 1;
    pjsua_vid_win_set_show ( Svid, IsShow);
    return 0;
}
