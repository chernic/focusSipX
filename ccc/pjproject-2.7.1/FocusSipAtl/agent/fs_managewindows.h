// fs_managewindows.h : Declaration of the CApp

#ifndef __FS_MANAGE_WINDOWS_H_
#define __FS_MANAGE_WINDOWS_H_

#include "resource.h"       // main symbols
#include "define.h"
#include "settings.h"
#include "fs_overlay.h"

#ifdef _GLOBAL_VIDEO

void ResetPJmedia(void);
void ResetPJmediaData(void);
pj_str_t get_local_dir(void);

int InitPreviwWindow(void);
int MakePreviwWindow(void);

int MakeStreamWindow(void);

int ShowPreviwWindow(pj_bool_t IsShow);
int ShowStreamWindow(pj_bool_t IsShow);

///////
pj_status_t fswin_get_previw_pvid  (void);
pj_status_t fswin_init_overlay_mode(int mode );
////
pj_status_t ResizePreviwWindows(double size);
pj_status_t ShiftPreviwWindows(int mode);
///////

#endif

#endif //__FS_MANAGE_WINDOWS_H_
