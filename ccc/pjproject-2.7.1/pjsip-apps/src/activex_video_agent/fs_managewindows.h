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

void DisplayModeChange(void);

int InitPreviwWindow(int overlay_mode);
int MakePreviwWindow(int overlay_mode);

int MakeStreamWindow(PosSize_t psS);

int ShowPreviwWindow(pj_bool_t IsShow);
int ShowStreamWindow(pj_bool_t IsShow);

#endif

#endif //__FS_MANAGE_WINDOWS_H_
