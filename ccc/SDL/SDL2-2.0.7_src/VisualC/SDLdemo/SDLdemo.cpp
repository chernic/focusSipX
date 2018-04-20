// #include <sdl/SDL.h>
#include <SDL.h>
#include <iostream>

void test1(void)
{
    // ��ʼ��SDL
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)== -1)) 
    {
        // ��ʼ��ʧ��, �������, ע�� SDL_GetError ����һ���ַ���, �ɶ��Ժܺ�, �ǲ��� ?
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
    }
    else
    {
        printf("SDL initialize ok!");
    }
    
	// ����SDL
    SDL_Quit();
    getchar();
}

int  test2(void)
{
  // ���� 
  SDL_Window *Window = NULL;
  // ���ڱ��� 
  SDL_Surface *WindowScreen = NULL;

  SDL_Init(SDL_INIT_VIDEO);

  // �������� 
  // Window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 400, SDL_WINDOW_SHOWN);
  
  // Window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 400, SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS); 

  Window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 400, SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS); 
  
  if (Window == NULL){
    return -1;
  }

  // ��ȡWindow�ı���    
  WindowScreen = SDL_GetWindowSurface(Window);
  if (WindowScreen == NULL){
    return -2;
  }  

  // ��䴰��
  // SDL_FillRect(WindowScreen, NULL, SDL_MapRGB(WindowScreen->format, 0xFF, 0x00, 0x00));
  // SDL_FillRect(WindowScreen, NULL, SDL_MapRGB(WindowScreen->format, 0x00, 0xFF, 0x00));
  SDL_FillRect(WindowScreen, NULL, SDL_MapRGB(WindowScreen->format, 0x00, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(Window);
  SDL_Delay(2000);

  // ������ 
  SDL_FreeSurface(WindowScreen);
  SDL_DestroyWindow(Window);
  SDL_Quit(); 

  return 0;
}

// ����SDL�ڲ��ض�����main  main ����һ�����������ʽ, ����Ϊ��, ������ϸ˵��
int main(int argc, char * argv[])
{
  // test1();
  test2();
  return 0;
}
