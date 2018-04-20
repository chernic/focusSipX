#include "SDL_Button.h"

// 疑问1 SDL_free(mTextureBtn) SDL_DestroyTexture(mTextureBtn)
SDL_Button::~SDL_Button() {
  SDL_free(srcR);
  SDL_free(mTextureBtn);
}
SDL_Button::SDL_Button() {
  // 以下变量必须在初始化时赋初始值
  isChecked = BTUUON_UNCHECKED;
  // 纹理(按钮)为无
  mTextureBtn = NULL;
  // 默认的鼠标状态是在button外
  setBtnMouseoverRect( 0,     0, 320, 240 );
  setBtnMouseoutRect ( 320,   0, 320, 240 );
  setBtnMousedownRect( 0,   240, 320, 240 );
  setBtnMouseupRect  ( 320, 240, 320, 240 );
  srcR1=btnRect.mouseover[isChecked];
}
void SDL_Button::Init(SDL_Rect destr) {
  destR=destr;
};
void SDL_Button::Init(int x, int y, int w, int h) {
  destR.x=x;
  destR.y=y;
  destR.w=w;
  destR.h=h;
};
/// setBtnRect
void SDL_Button::setBtnMouseoverRect(int x, int y, int w, int h, euBtnStste is_checked) {
  btnRect.mouseover[is_checked].x=x;
  btnRect.mouseover[is_checked].y=y;
  btnRect.mouseover[is_checked].w=w;
  btnRect.mouseover[is_checked].h=h;
}
void SDL_Button::setBtnMouseoutRect (int x, int y, int w, int h, euBtnStste is_checked) {
  btnRect.mouseout[is_checked].x=x;
  btnRect.mouseout[is_checked].y=y;
  btnRect.mouseout[is_checked].w=w;
  btnRect.mouseout[is_checked].h=h;
}
void SDL_Button::setBtnMousedownRect(int x, int y, int w, int h, euBtnStste is_checked) {
  btnRect.mousedown[is_checked].x=x;
  btnRect.mousedown[is_checked].y=y;
  btnRect.mousedown[is_checked].w=w;
  btnRect.mousedown[is_checked].h=h;
}
void SDL_Button::setBtnMouseupRect  (int x, int y, int w, int h, euBtnStste is_checked) {
  btnRect.mouseup[is_checked].x=x;
  btnRect.mouseup[is_checked].y=y;
  btnRect.mouseup[is_checked].w=w;
  btnRect.mouseup[is_checked].h=h;
}

/// 定义button的事件响应动作, 根据不同时间赋不同值给srcR
void SDL_Button::Handle_event(SDL_Renderer *renderer, SDL_Event event, int *Checked) {
  int x=0,y=0;
  if(event.type==SDL_MOUSEMOTION) {
    // 如果发现了鼠标移动事件，就要得到鼠标当前位置，然后判断其是否在定义的button内
    x=event.motion.x;
    y=event.motion.y;
    if((x>destR.x)&&(x<destR.x+destR.w)&&(y>destR.y)&&(y<destR.y+destR.h)){
      // 如果鼠标在定义的button内
      srcR=&(btnRect.mouseover[isChecked]);
    }else{
      // 鼠标在button外
      srcR=&(btnRect.mouseout[isChecked]);
    }
  }
  // 如果发生了鼠标按键按下事件
  if(event.type==SDL_MOUSEBUTTONDOWN) {
    if(event.button.button=SDL_BUTTON_LEFT){ 
      // 如果是左键按下的事件，就要判断按下鼠标的时候鼠标是否处在button区域中，所以要得到鼠标坐标
      x=event.button.x;
      y=event.button.y;
      if((x>destR.x)&&(x<destR.x+destR.w)&&(y>destR.y)&&(y<destR.y+destR.h)){
        // 反相
        isChecked = (isChecked==BTUUON_CHECKED)?BTUUON_UNCHECKED:BTUUON_CHECKED;

        // 如果按下鼠标左键的时候鼠标处在button内
        srcR=&(btnRect.mousedown[isChecked]);
        
        // SDL_RenderClear( renderer );
        // Show( renderer);
        // SDL_RenderPresent( renderer );
        // 最后一帧画面
        SDL_Event event;
        event.type = SFM_LASTFRAME_EVENT;
        SDL_PushEvent(&event);
        
        // 同步
        *Checked  = (isChecked==BTUUON_CHECKED)?1:0;
      }
    }
  }
  // 如果发生了鼠标左键弹起事件，处理方式同鼠标左键按下事件
  if(event.type==SDL_MOUSEBUTTONUP) {
  if(event.button.button=SDL_BUTTON_LEFT)
  { // 如果是左键弹起的事件，就要判断按下鼠标的时候鼠标是否处在button区域中，所以要得到鼠标坐标
   x=event.button.x;
   y=event.button.y;
   if((x>destR.x)&&(x<destR.x+destR.w)&&(y>destR.y)&&(y<destR.y+destR.h))
   {// 如果按下鼠标左键的时候鼠标处在button内
    srcR=&(btnRect.mouseup[isChecked]);
   }
  }
 }
}
/// 加载bmp图片
int  SDL_Button::Load(SDL_Renderer *renderer, const char *file) {
  SDL_Surface *temp;
  /* Load the sprite image */
  temp = SDL_LoadBMP(file);
  if (temp == NULL) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, 
        "Couldn't load %s: %s", file, SDL_GetError());
      return (-1);
  }

  /* Set transparent pixel as the pixel at (0,0) */
  if (temp->format->palette) {
      SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *) temp->pixels);
  } else {
      switch (temp->format->BitsPerPixel) {
      case 15:
          SDL_SetColorKey(temp, SDL_TRUE, (*(Uint16 *) temp->pixels) & 0x00007FFF);
          break;
      case 16:
          SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *) temp->pixels);
          break;
      case 24:
          SDL_SetColorKey(temp, SDL_TRUE, (*(Uint32 *) temp->pixels) & 0x00FFFFFF);
          break;
      case 32:
          SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *) temp->pixels);
          break;
      }
  }

  /* Use this function to copy a portion of the texture 
    to the current rendering target.*/
  mTextureBtn = SDL_CreateTextureFromSurface(renderer, temp);
  if (!mTextureBtn) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s\n", SDL_GetError());
      SDL_FreeSurface(temp);
      return (-1);
  }
  if (SDL_SetTextureBlendMode(mTextureBtn, blendMode) < 0) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't set blend mode: %s\n", SDL_GetError());
      SDL_FreeSurface(temp);
      SDL_DestroyTexture(mTextureBtn);
      return (-1);
  }
  SDL_FreeSurface(temp);
  /* We're ready to roll. :) */
  return (0);
}
/// 显示图片, 不同选区, 根据srcR不同值
int  SDL_Button::Show(SDL_Renderer *renderer) {
  if (!mTextureBtn) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Please firstly create texture: %s\n", SDL_GetError());
      return (-1);
  }
  SDL_RenderCopy(renderer, mTextureBtn, srcR, &destR );
  return (0);
}
