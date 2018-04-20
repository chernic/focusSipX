#include "SDL_Button.h"

// ����1 SDL_free(mTextureBtn) SDL_DestroyTexture(mTextureBtn)
SDL_Button::~SDL_Button() {
  SDL_free(srcR);
  SDL_free(mTextureBtn);
}
SDL_Button::SDL_Button() {
  // ���±��������ڳ�ʼ��ʱ����ʼֵ
  isChecked = BTUUON_UNCHECKED;
  // ����(��ť)Ϊ��
  mTextureBtn = NULL;
  // Ĭ�ϵ����״̬����button��
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

/// ����button���¼���Ӧ����, ���ݲ�ͬʱ�丳��ֵͬ��srcR
void SDL_Button::Handle_event(SDL_Renderer *renderer, SDL_Event event, int *Checked) {
  int x=0,y=0;
  if(event.type==SDL_MOUSEMOTION) {
    // �������������ƶ��¼�����Ҫ�õ���굱ǰλ�ã�Ȼ���ж����Ƿ��ڶ����button��
    x=event.motion.x;
    y=event.motion.y;
    if((x>destR.x)&&(x<destR.x+destR.w)&&(y>destR.y)&&(y<destR.y+destR.h)){
      // �������ڶ����button��
      srcR=&(btnRect.mouseover[isChecked]);
    }else{
      // �����button��
      srcR=&(btnRect.mouseout[isChecked]);
    }
  }
  // �����������갴�������¼�
  if(event.type==SDL_MOUSEBUTTONDOWN) {
    if(event.button.button=SDL_BUTTON_LEFT){ 
      // �����������µ��¼�����Ҫ�жϰ�������ʱ������Ƿ���button�����У�����Ҫ�õ��������
      x=event.button.x;
      y=event.button.y;
      if((x>destR.x)&&(x<destR.x+destR.w)&&(y>destR.y)&&(y<destR.y+destR.h)){
        // ����
        isChecked = (isChecked==BTUUON_CHECKED)?BTUUON_UNCHECKED:BTUUON_CHECKED;

        // ���������������ʱ����괦��button��
        srcR=&(btnRect.mousedown[isChecked]);
        
        // SDL_RenderClear( renderer );
        // Show( renderer);
        // SDL_RenderPresent( renderer );
        // ���һ֡����
        SDL_Event event;
        event.type = SFM_LASTFRAME_EVENT;
        SDL_PushEvent(&event);
        
        // ͬ��
        *Checked  = (isChecked==BTUUON_CHECKED)?1:0;
      }
    }
  }
  // ��������������������¼�������ʽͬ�����������¼�
  if(event.type==SDL_MOUSEBUTTONUP) {
  if(event.button.button=SDL_BUTTON_LEFT)
  { // ��������������¼�����Ҫ�жϰ�������ʱ������Ƿ���button�����У�����Ҫ�õ��������
   x=event.button.x;
   y=event.button.y;
   if((x>destR.x)&&(x<destR.x+destR.w)&&(y>destR.y)&&(y<destR.y+destR.h))
   {// ���������������ʱ����괦��button��
    srcR=&(btnRect.mouseup[isChecked]);
   }
  }
 }
}
/// ����bmpͼƬ
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
/// ��ʾͼƬ, ��ͬѡ��, ����srcR��ֵͬ
int  SDL_Button::Show(SDL_Renderer *renderer) {
  if (!mTextureBtn) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Please firstly create texture: %s\n", SDL_GetError());
      return (-1);
  }
  SDL_RenderCopy(renderer, mTextureBtn, srcR, &destR );
  return (0);
}
