// ManageWindows.h : Declaration of the CApp

#ifndef __MANAGE_WINDOWS_H_
#define __MANAGE_WINDOWS_H_

#include "define.h"
#include "resource.h"       // main symbols
#include "settings.h"

#ifdef _GLOBAL_VIDEO
void ResetPJmedia(void);
void ResetPJmediaData(void);

void CreatePreviewWindow(PosSize_t psP);

void ResizePreviewWindow(PosSize_t psP);
void ResizeStreamWindow(PosSize_t psS);

int  ShowPreviewWindow(pj_bool_t IsShow);
int  ShowStreamWindow(pj_bool_t IsShow);

#endif

#endif //__MANAGE_WINDOWS_H_



