// #include <sdl/SDL.h>
#include <SDL.h>
#include <iostream>

void test1(void)
{
    // 初始化SDL
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)== -1)) 
    {
        // 初始化失败, 打出错误, 注意 SDL_GetError 返回一个字符串, 可读性很好, 是不是 ?
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
    }
    else
    {
        printf("SDL initialize ok!");
    }
    
	// 结束SDL
    SDL_Quit();
    getchar();
}

int  test2(void)
{
  // 窗口 
  SDL_Window *Window = NULL;
  // 窗口表面 
  SDL_Surface *WindowScreen = NULL;

  SDL_Init(SDL_INIT_VIDEO);

  // 创建窗口 
  // Window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 400, SDL_WINDOW_SHOWN);
  
  // Window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 400, SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS); 

  Window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 400, SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS); 
  
  if (Window == NULL){
    return -1;
  }

  // 获取Window的表面    
  WindowScreen = SDL_GetWindowSurface(Window);
  if (WindowScreen == NULL){
    return -2;
  }  

  // 填充窗口
  // SDL_FillRect(WindowScreen, NULL, SDL_MapRGB(WindowScreen->format, 0xFF, 0x00, 0x00));
  // SDL_FillRect(WindowScreen, NULL, SDL_MapRGB(WindowScreen->format, 0x00, 0xFF, 0x00));
  SDL_FillRect(WindowScreen, NULL, SDL_MapRGB(WindowScreen->format, 0x00, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(Window);
  SDL_Delay(2000);

  // 清理函数 
  SDL_FreeSurface(WindowScreen);
  SDL_DestroyWindow(Window);
  SDL_Quit(); 

  return 0;
}

// 由于SDL内部重定义了main  main 函数一定得是这个形式, 具体为何, 后面详细说明
int main(int argc, char * argv[])
{
  // test1();
  test2();
  return 0;
}
