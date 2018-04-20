//#include "stdafx.h"
//#include "BrButton.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <SDL.h>


void GetRGBA8888Data(void *&pixels, int &width, int &height){
    // for debug
    width = 600;
    height = 400;
    pixels = calloc(width*height*4,1);  // 一像素占4字节
}
int main1(int argc, char *argv[]){
    SDL_Window      *pWindow = NULL;
    SDL_Renderer    *pRenderer = NULL;
    SDL_Texture     *pTexture;

    SDL_Rect        srcRect;
    SDL_Rect        dstRect;
    //初始化SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)    return 0;
    //创建窗口
    pWindow = SDL_CreateWindow("example04: for mediaplayer", 100, 100, 700, 590, 0);
    if (NULL == pWindow)    return 0;
    //创建Renderer
    pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    if (NULL == pRenderer)    return 0;
    //设置Renderer画笔颜色，透明度(此时透明度不会生效，因为没有设置BlendMode)
    SDL_SetRenderDrawColor(pRenderer, 0, 255, 0, 255);

    void *pixels;
    int  width, height, depth, pitch;

    GetRGBA8888Data(pixels, width, height);
    pitch = height*4;   // 每行图像所占字节数
    depth = 4*8;        // 每像素所占位数(R8位G8位B8位A8位)

    int rmask, gmask, bmask, amask;
    rmask = 0xFF000000; gmask = 0x00FF0000; bmask = 0x0000FF00; amask = 0x000000FF;     // RGBA8888模式
    //rmask = 0xFF000000; gmask = 0x00FF0000; bmask = 0x0000FF00; amask = 0x00000000;   // RGB8888模式

    //创建一个RGB Surface
    SDL_Surface *pTmpSurface = SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
    if (NULL == pTmpSurface)    return 0;

    //创建Texture
    pTexture = SDL_CreateTextureFromSurface(pRenderer,pTmpSurface);
    if (NULL == pTexture)    return 0;

    SDL_FreeSurface(pTmpSurface);

    free(pixels);
    dstRect.x = srcRect.x = 0;
    dstRect.y = srcRect.y = 0;
    dstRect.w = srcRect.w = width;
    dstRect.h = srcRect.h = height;

    //清除Renderer
    SDL_RenderClear(pRenderer);

    //Texture复制到Renderer
    SDL_RenderCopy(pRenderer, pTexture, &srcRect, &dstRect);

    //更新Renderer显示
    SDL_RenderPresent(pRenderer);

    SDL_Delay(9000);
    //清理
    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyTexture(pTexture);
    SDL_Quit();
    return 0;
}
void fillTexture(SDL_Renderer *renderer, SDL_Texture *texture, int r, int g, int b, int a){
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, NULL);
}
void prepareForRendering(SDL_Renderer *renderer){
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
}
void checkSdlError(){
    const char *sdlError = SDL_GetError();
    if(sdlError && *sdlError)
    {
        ::std::cout << "SDL ERROR: " << sdlError << ::std::endl;
    }
}
int main(int argc, char *argv[]){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_HAPTIC);

    SDL_Window *window = SDL_CreateWindow("SDL test",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        320, 240,
        SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    const int width = 50;
    const int height = 50;

    ::std::vector<SDL_Texture*> textures;

    SDL_Texture *redTexture    = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    textures.push_back(redTexture);

    SDL_Texture *greenTexture  = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    textures.push_back(greenTexture);

    SDL_Texture *purpleTexture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    textures.push_back(purpleTexture);

    // Here is setting the blend mode for each and every used texture:
    for(int i = 0; i < textures.size(); ++i){
        SDL_SetTextureBlendMode(textures[i], SDL_BLENDMODE_BLEND);
    }

    int purpleAlpha = 0;

    fillTexture(renderer, redTexture,    255,   0,   0, 255);
    fillTexture(renderer, greenTexture,    0, 255,   0, 128);
    fillTexture(renderer, purpleTexture, 255,   0, 255, purpleAlpha);

    prepareForRendering(renderer);

    bool running = true;
    while(running){
        SDL_Rect rect;
        rect.w = width;
        rect.h = height;

        SDL_RenderClear(renderer);

        rect.x = 50;
        rect.y = 50;
        SDL_RenderCopy(renderer, redTexture, NULL, &rect);

        rect.x = 75;
        rect.y = 70;
        SDL_RenderCopy(renderer, greenTexture, NULL, &rect);

        rect.x = 75;
        rect.y = 30;
        SDL_RenderCopy(renderer, purpleTexture, NULL, &rect);

        SDL_RenderPresent(renderer);

        // Process events
        {
            SDL_Event event;
            while(SDL_PollEvent(&event) == 1)
            {
                if(event.type == SDL_QUIT)
                {
                    running = false;
                }
                else if(event.type == SDL_KEYDOWN)
                {
                    switch(event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    case SDLK_a:
                        purpleAlpha = ::std::max(purpleAlpha - 32, 0);
                        fillTexture(renderer, purpleTexture, 255, 0, 255, purpleAlpha);
                        prepareForRendering(renderer);
                        ::std::cout << "Alpha: " << purpleAlpha << ::std::endl;
                        break;
                    case SDLK_s:
                        purpleAlpha = ::std::min(purpleAlpha + 32, 255);
                        fillTexture(renderer, purpleTexture, 255, 0, 255, purpleAlpha);
                        prepareForRendering(renderer);
                        ::std::cout << "Alpha: " << purpleAlpha << ::std::endl;
                        break;
                    }
                }
            }

            checkSdlError();
        }
    }

    for(int i = 0; i < textures.size(); ++i){
        SDL_DestroyTexture(textures[i]);
    }
    textures.clear();

    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

    checkSdlError();

    return 0;
}

// typedef enum
// {
// SDL_WINDOWEVENT_NONE,            Never used
// SDL_WINDOWEVENT_SHOWN,           Window has been shown
// SDL_WINDOWEVENT_HIDDEN,          Window has been hidden
// SDL_WINDOWEVENT_EXPOSED,         Window has been exposed and should be redrawn
// SDL_WINDOWEVENT_MOVED,           Window has been moved to data1, data2*/
// SDL_WINDOWEVENT_RESIZED,         Window has been resized to data1xdata2
// SDL_WINDOWEVENT_SIZE_CHANGED,    The window size has changed, either as a result of an API call or through the system or user changing the window size.
// SDL_WINDOWEVENT_MINIMIZED,       Window has been minimized
// SDL_WINDOWEVENT_MAXIMIZED,       Window has been maximized
// SDL_WINDOWEVENT_RESTORED,        Window has been restored to normal size and position
// SDL_WINDOWEVENT_LEAVE,           Window has lost mouse focus
// SDL_WINDOWEVENT_ENTER,           Window has gained mouse focus
// SDL_WINDOWEVENT_FOCUS_GAINED,    Window has gained keyboard focus
// SDL_WINDOWEVENT_FOCUS_LOST,      Window has lost keyboard focus
// SDL_WINDOWEVENT_CLOSE,           The window manager requests that the window be closed
// SDL_WINDOWEVENT_TAKE_FOCUS,      Window is being offered a focus (should SetWindowInputFocus() on itself or a subwindow, or ignore)
// SDL_WINDOWEVENT_HIT_TEST         Window had a hit test that wasn't SDL_HITTEST_NORMAL.
// } SDL_WindowEventID;

// typedef enum
// {
    // /* !!! FIXME: change this to name = (1<<x). */
    // SDL_WINDOW_FULLSCREEN            0x00000001, fullscreen window
    // SDL_WINDOW_OPENGL                0x00000002, window usable with OpenGL context
    // SDL_WINDOW_SHOWN                 0x00000004, window is visible
    // SDL_WINDOW_HIDDEN                0x00000008, window is not visible
    // SDL_WINDOW_BORDERLESS            0x00000010, no window decoration
    // SDL_WINDOW_RESIZABLE             0x00000020, window can be resized
    // SDL_WINDOW_MINIMIZED             0x00000040, window is minimized
    // SDL_WINDOW_MAXIMIZED             0x00000080, window is maximized
    // SDL_WINDOW_INPUT_GRABBED         0x00000100, window has grabbed input focus
    // SDL_WINDOW_INPUT_FOCUS           0x00000200, window has input focus
    // SDL_WINDOW_MOUSE_FOCUS           0x00000400, window has mouse focus
    // SDL_WINDOW_FULLSCREEN_DESKTOP    ( SDL_WINDOW_FULLSCREEN | 0x00001000 ),
    // SDL_WINDOW_FOREIGN               0x00000800, window not created by SDL
    // SDL_WINDOW_ALLOW_HIGHDPI         0x00002000, window should be created in high-DPI mode if supported
    // SDL_WINDOW_MOUSE_CAPTURE         0x00004000, window has mouse captured (unrelated to INPUT_GRABBED)
    // SDL_WINDOW_ALWAYS_ON_TOP         0x00008000, window should always be above others
    // SDL_WINDOW_SKIP_TASKBAR          0x00010000, window should not be added to the taskbar
    // SDL_WINDOW_UTILITY               0x00020000, window should be treated as a utility window
    // SDL_WINDOW_TOOLTIP               0x00040000, window should be treated as a tooltip
    // SDL_WINDOW_POPUP_MENU            0x00080000, window should be treated as a popup menu
    // SDL_WINDOW_VULKAN                0x10000000, window usable for Vulkan surface
// } SDL_WindowFlags;
