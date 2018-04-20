#ifndef __SDL_BUTTON_H_
#define __SDL_BUTTON_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "global.h"

typedef enum BTUUON_CHECK_STATE{
  BTUUON_UNCHECKED=0,
  BTUUON_CHECKED=1,
}euBtnStste;

typedef struct BtnRect{
  SDL_Rect mouseover[2];
  SDL_Rect mouseout[2];
  SDL_Rect mousedown[2];
  SDL_Rect mouseup[2];
}BtnRect_t;

// SDL_Button 类    封装了按键的位置和大小信息
// 纹理(Texture)    某帧时某种显示效果
// 渲染器(Renderer) 显卡中的元件，某种显示效果集合，如视频、图片等
class SDL_Button {
  private:
    SDL_BlendMode blendMode;        // 叠加模式类型
    euBtnStste    isChecked;
  public:
    BtnRect_t     btnRect;
    SDL_Rect      srcR1;            // Texture  内容(纹理) 边框
    SDL_Rect      *srcR;            // Texture  内容(纹理) 边框
    SDL_Rect      destR;            // Renderer 容器(渲染器)边框

    //mTextureBtn=>mRenderer=>mWindow
    //SDL_Window    *mWindow;       // 屏幕窗口
    //SDL_Renderer  *mRenderer;     // 渲染器 别称Surface
    SDL_Texture   *mTextureBtn;     // 纹理(按钮)

    ~SDL_Button();
    SDL_Button();
    /// 这是定按钮的位置
    void Init(SDL_Rect destr);
    void Init(int x, int y, int w, int h);

    /// setBtnRect 这是定按钮所用图片的分割位置
    void setBtnMouseoverRect  (int x, int y, int w, int h, euBtnStste is_checked=BTUUON_UNCHECKED);
    void setBtnMouseoutRect   (int x, int y, int w, int h, euBtnStste is_checked=BTUUON_UNCHECKED);
    void setBtnMousedownRect  (int x, int y, int w, int h, euBtnStste is_checked=BTUUON_UNCHECKED);
    void setBtnMouseupRect    (int x, int y, int w, int h, euBtnStste is_checked=BTUUON_UNCHECKED);

    /// 定义button的事件响应动作
    void  Handle_event(SDL_Renderer *renderer, SDL_Event event, int *done);
    int   Load(SDL_Renderer *renderer, const char *file);
    int   Show(SDL_Renderer *renderer);
};

#endif // __SDL_BUTTON_H_