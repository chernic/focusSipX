#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <SDL.h>

SDL_Event gEvent;
int thread_exit=0;
int thread_pause=0;
int thread_lastframe=0;

static void
PrintText(char *eventtype, char *text){
    char *spot, expanded[1024];

    expanded[0] = '\0';
    for ( spot = text; *spot; ++spot )
    {
        size_t length = SDL_strlen(expanded);
        SDL_snprintf(expanded + length, sizeof(expanded) - length, "\\x%.2x", (unsigned char)*spot);
    }
    SDL_Log("%s Text (%s): \"%s%s\"\n", eventtype, expanded, *text == '"' ? "\\" : "", text);
}

void GetRGBA8888Data(void *&pixels, int &width, int &height){
    // for debug
    width = 600;
    height = 400;
    pixels = calloc(width*height*4,1);  // 一像素占4字节
}
int main(int argc, char *argv[]){
    SDL_Window      *pWindow = NULL;
    SDL_Renderer    *pRenderer = NULL;
    SDL_Texture     *pTexture;

    SDL_Rect        srcRect;
    SDL_Rect        dstRect;
    //初始化SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)    return 0;
    //创建窗口
    pWindow = SDL_CreateWindow(
        "example04: for mediaplayer",
        100,
        100,
        700,
        590,
        SDL_WINDOW_FULLSCREEN);
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

    /// ABChernic 标志位
    int isChecked;
    int isToolBarShowed=0;
    int isWindowToBeClosed=0;    /* Watch keystrokes */
    while (!isWindowToBeClosed) {
        while (SDL_PollEvent(&gEvent)) {
            //清除Renderer
            SDL_RenderClear(pRenderer);
            //Texture复制到Renderer
            SDL_RenderCopy(pRenderer, pTexture, &srcRect, &dstRect);
            //更新Renderer显示
            SDL_RenderPresent(pRenderer);

            switch (gEvent.type) {
            case SDL_MOUSEMOTION:{
                PrintText("SDL_MOUSEMOTION", gEvent.text.text);
                }break;
            case SDL_MOUSEBUTTONDOWN:{
                PrintText("SDL_MOUSEBUTTONDOWN", gEvent.text.text);
                isWindowToBeClosed = 1;
                }break;
            /// 键盘操作
            case SDL_KEYUP:{
                PrintText("SDL_KEYUP", gEvent.text.text);
                }break;
            case SDL_KEYDOWN:{
                PrintText("SDL_KEYDOWN", gEvent.text.text);
                }break;
            /// 离开操作
            case SDL_QUIT:{
                isWindowToBeClosed = 1;
                thread_exit=1;
                }break;
            default:{
                }break;
            }
            //thread_pause=(isChecked==1)?1:0;
        }
    }

    //清理
    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyTexture(pTexture);
    SDL_Quit();
    return 0;
}
