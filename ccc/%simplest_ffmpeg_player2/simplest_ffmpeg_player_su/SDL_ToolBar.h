#ifndef __SDL_TOOLBAR_H_
#define __SDL_TOOLBAR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SDL_Button.h"

class SDL_ToolBar {
  private:
    SDL_Rect   mBlankRect;    // ����������
  public:
    SDL_Button mButtonPlay;   // ���Ű�ť
    SDL_Button mButtonClose;  // ֹͣ��ť
    
    ~SDL_ToolBar();
    SDL_ToolBar       (SDL_Renderer *renderer, int x, int y, int w, int h);
    void Show         (SDL_Renderer *renderer, bool Showed);
    void Handle_event (SDL_Renderer *renderer, SDL_Event event, int *Checked);
};

#endif // __SDL_TOOLBAR_H_