#include "SDL_ToolBar.h"

SDL_ToolBar::SDL_ToolBar(SDL_Renderer *renderer, int WindowW, int WindowH, int ButtonW, int ButtonH) 
{ 
  int Plus=2;
  int x=(WindowW-ButtonW)/2;
  int y=WindowH-ButtonH-Plus;
  int w=ButtonW;
  int h=ButtonH;
  mButtonPlay.Init(x-ButtonW,y,w,h);
  mButtonClose.Init(x+ButtonW,y,w,h);
  
  mBlankRect.x = 0;
  mBlankRect.y = WindowH-ButtonH-Plus;
  mBlankRect.w = WindowW;
  mBlankRect.h = ButtonH+Plus;

  mButtonPlay.Load(renderer,"timg.bmp");
  mButtonClose.Load(renderer,"timg.bmp");
  
  ///////////////////////////////////////////////////
  // 18 131 244 581
  // 27 123
  // UnCheck ==> 显示播放 131/123
  mButtonPlay.setBtnMouseoverRect  ( 131,  123,  80,  80 ,BTUUON_CHECKED);
  mButtonPlay.setBtnMouseoutRect   ( 131,  123,  80,  80 ,BTUUON_CHECKED);
  mButtonPlay.setBtnMouseupRect    ( 131,  123,  80,  80 ,BTUUON_CHECKED);  // 按完弹起变播放
  mButtonPlay.setBtnMousedownRect  ( 129,  121,  80,  80 ,BTUUON_CHECKED);
  // Check   ==> 显示暂停 581/27
  mButtonPlay.setBtnMouseoverRect  ( 581,  27 , 80,  80 ,BTUUON_UNCHECKED);
  mButtonPlay.setBtnMouseoutRect   ( 581,  27 , 80,  80 ,BTUUON_UNCHECKED);
  mButtonPlay.setBtnMouseupRect    ( 581,  27 , 80,  80 ,BTUUON_UNCHECKED); // 按完弹起变暂停
  mButtonPlay.setBtnMousedownRect  ( 579,  25 , 80,  80 ,BTUUON_UNCHECKED);

  mButtonClose.setBtnMouseoverRect ( 131,  27,  80,  80 ,BTUUON_UNCHECKED);
  mButtonClose.setBtnMouseoutRect  ( 131,  27,  80,  80 ,BTUUON_UNCHECKED);
  mButtonClose.setBtnMouseupRect   ( 131,  27 , 80,  80 ,BTUUON_UNCHECKED);
  mButtonClose.setBtnMousedownRect ( 129,  25,  80,  80 ,BTUUON_UNCHECKED);
  mButtonClose.setBtnMouseoverRect ( 131,  27,  80,  80 ,BTUUON_CHECKED);
  mButtonClose.setBtnMouseoutRect  ( 131,  27,  80,  80 ,BTUUON_CHECKED);
  mButtonClose.setBtnMouseupRect   ( 131,  27 , 80,  80 ,BTUUON_CHECKED);
  mButtonClose.setBtnMousedownRect ( 129,  25,  80,  80 ,BTUUON_CHECKED);
}

SDL_ToolBar::~SDL_ToolBar() {
}
void SDL_ToolBar::Show(SDL_Renderer *renderer, bool Showed) {
  // 自动隐藏工具栏,独立于视频
  if(Showed){
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &mBlankRect);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    
    mButtonPlay.Show(renderer);
    mButtonClose.Show(renderer);
  }
}
void SDL_ToolBar::Handle_event(SDL_Renderer *renderer, SDL_Event event, int *Checked) {
  int x=0,y=0;
  if(event.type==SDL_MOUSEMOTION) {
    // 如果发现了鼠标移动事件，判断是否位于操作栏上方
    x = event.motion.x;
    y = event.motion.y;
    if((x>mBlankRect.x)&&(x<mBlankRect.x+mBlankRect.w)&&(y>mBlankRect.y)&&(y<mBlankRect.y+mBlankRect.h)){
      *Checked = true;
    }else{
      *Checked = false;
    }
  }
}
