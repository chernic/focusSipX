// SDL学习（七） Mouse Move（鼠标事件）
 
// 前面已经学习了键盘事件的简单处理，当然现在就要来学习鼠标事件了，
// 鼠标事件不必键盘难，只是多了移动的操作而已，
// 我们先看一下下面可以简单表示鼠标响应方式的Sprite Sheet：

// 下面的演示程序实现的是在屏幕中设置一个button区域，
// 该区域的显示通过判断鼠标事件（移动/远离/按下/弹起），
// 然后调用上面的sprite sheet中的sprite进行相应，
// 从而实现动态鼠标移动和按键响应的效果，首先是要定义个区域button，
// 鼠标移动到此区域中button就显示mouse over 的图片，
// 反之显示mouse over，如果鼠标左键在该区域中
// 按下就显示mouse down的图片，弹起以后
// 显示mouse up的图片（当然按下就会有弹起了..-_-）
// 下面是代码：

#include"SDL.h"
#include<string>
//屏幕相关信息定义
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;
const int SCREEN_BPP=32;
//定义四种鼠标按键状态
const int CLIP_MOUSEOVER=0;
const int CLIP_MOUSEOUT=1;
const int CLIP_MOUSEDOWN=2;
const int CLIP_MOUSEUP=3;
//定义表面
SDL_Surface *buttonSheet=NULL;
SDL_Surface *screen=NULL;
SDL_Event event;
//定义四个SDL_Rect来容纳四个按键图片的大小和offset
SDL_Rect Clip[4];
//设置各个鼠标事件图片在sprite sheet上面的范围的函数
void set_clips(){
 Clip[CLIP_MOUSEOVER].x=0;
 Clip[CLIP_MOUSEOVER].y=0;
 Clip[CLIP_MOUSEOVER].w=320;
 Clip[CLIP_MOUSEOVER].h=240;
 Clip[CLIP_MOUSEOUT].x=320;
 Clip[CLIP_MOUSEOUT].y=0;
 Clip[CLIP_MOUSEOUT].w=320;
 Clip[CLIP_MOUSEOUT].h=240;
 Clip[CLIP_MOUSEDOWN].x=0;
 Clip[CLIP_MOUSEDOWN].y=240;
 Clip[CLIP_MOUSEDOWN].w=320;
 Clip[CLIP_MOUSEDOWN].h=240;
 Clip[CLIP_MOUSEUP].x=320;
 Clip[CLIP_MOUSEUP].y=240;
 Clip[CLIP_MOUSEUP].w=320;
 Clip[CLIP_MOUSEUP].h=240;
}

//装载图片的函数
SDL_Surface *load_image(std::string filename)
{
 SDL_Surface *loadedImage=NULL;
    SDL_Surface *optimizedImage=NULL;
 loadedImage=IMG_Load(filename.c_str());
 if(loadedImage!=NULL)
 {
  optimizedImage=SDL_DisplayFormat(loadedImage);
  SDL_FreeSurface(loadedImage);
  if(optimizedImage!=NULL)
  {
   SDL_SetColorKey(optimizedImage,SDL_SRCCOLORKEY,SDL_MapRGB(optimizedImage->format,0,0xFF,0xFF));
  }
 }
 return optimizedImage;
}
//sticky两表面的函数
void apply_surface(int x,int y,SDL_Surface *source,SDL_Surface *destination,SDL_Rect *clip=NULL)
{
    SDL_Rect offset;
 offset.x=x;
 offset.y=y;
 SDL_BlitSurface(source,clip,destination,&offset);
}
//定义button类，中间封装了按键的位置和大小信息，如此一来我们就可以从sprite sheet中得到我们需要使用的按键的sprite。
//我们会偶设置button和坐标和其对于鼠标事件的响应函数，从而在button中封装一个surface用来显示现在的鼠标事件
class Button
{
private:
 SDL_Rect box;
 SDL_Rect *clip;
public:
 Button(int x,int  y,int w, int h)
  {
   //初始化button的函数
   box.x=x;
   box.y=y;
   box.w=w;
   box.h=h;
   clip=&Clip[CLIP_MOUSEOUT];//默认的鼠标状态是在button外
  };
 void handle_event();//定义button的事件响应动作
 void show();//显示当前事件的响应button
};

void Button::handle_event()
{
 int x=0,y=0;
 if(event.type==SDL_MOUSEMOTION)
 {//如果发现了鼠标移动事件，就要得到鼠标当前位置，然后判断其是否在定义的button内
  x=event.motion.x;
  y=event.motion.y;
      if((x>box.x)&&(x<box.x+box.w)&&(y>box.y)&&(y<box.y+box.h))
   {//如果鼠标在定义的button内
       clip=&Clip[CLIP_MOUSEOVER];
   }
   else
    //鼠标在button外
      clip=&Clip[CLIP_MOUSEOUT];
 }
 //如果发生了鼠标按键按下事件
 if(event.type==SDL_MOUSEBUTTONDOWN)
 {
  if(event.button.button=SDL_BUTTON_LEFT)
  { //如果是左键按下的事件，就要判断按下鼠标的时候鼠标是否处在button区域中，所以要得到鼠标坐标
   x=event.button.x;
   y=event.button.y;
   if((x>box.x)&&(x<box.x+box.w)&&(y>box.y)&&(y<box.y+box.h))
   {//如果按下鼠标左键的时候鼠标处在button内
    clip=&Clip[CLIP_MOUSEDOWN];
   }
  }
 }
 //如果发生了鼠标左键弹起事件，处理方式同鼠标左键按下事件
     if(event.type==SDL_MOUSEBUTTONUP)
 {
  if(event.button.button=SDL_BUTTON_LEFT)
  { //如果是左键弹起的事件，就要判断按下鼠标的时候鼠标是否处在button区域中，所以要得到鼠标坐标
   x=event.button.x;
   y=event.button.y;
   if((x>box.x)&&(x<box.x+box.w)&&(y>box.y)&&(y<box.y+box.h))
   {//如果按下鼠标左键的时候鼠标处在button内
    clip=&Clip[CLIP_MOUSEUP];
   }
  }
 }
 
}
//将当前的鼠标响应的button surface 显示出来
void Button::show()
{
   apply_surface(box.x,box.y,buttonSheet,screen,clip);
}
//初始化函数
bool init()
{
 if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
  return false;
     screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
  if(screen==NULL)
   return false;
  SDL_WM_SetCaption("Button Test",NULL);
  return true;
}
//sprite sheet装载函数
bool load_files()
{
 buttonSheet=load_image("D:/Users/lucy/Documents/Visual Studio 2008/Projects/SDLtest/button.png");
 if(buttonSheet==NULL)
      return false;
  return true;
}
//销毁工作
 void clean_up()
 {
  SDL_FreeSurface(buttonSheet);
  SDL_Quit();
 }
int main(int argc, char *args[])
{
 bool quit=false;
 if(init()==false)
  return 1;
 if(load_files()==false)
  return 1;
 
 Button myButton(170,120,320,240);
 set_clips();
 while(quit==false)
 {
  if(SDL_PollEvent(&event))
  {  //调用button事件处理函数
   myButton.handle_event();
   if(event.type==SDL_QUIT)
   {
    quit=true;
   }
  }
  //黄背景填充屏幕
  SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,255,255,0));
  //显示button
  myButton.show();
     //更新屏幕
  if(SDL_Flip(screen)==-1)
  {
               return 1;
  }
 }
  //收尾工作
  clean_up();
  return 0;
}
