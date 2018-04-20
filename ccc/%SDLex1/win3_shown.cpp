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
    pixels = calloc(width*height*4,1);  // һ����ռ4�ֽ�
}
int main(int argc, char *argv[]){
    SDL_Window      *pWindow = NULL;
    SDL_Renderer    *pRenderer = NULL;
    SDL_Texture     *pTexture;

    SDL_Rect        srcRect;
    SDL_Rect        dstRect;
    //��ʼ��SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)    return 0;
    //��������
    pWindow = SDL_CreateWindow(
        "example04: for mediaplayer",
        100,
        100,
        700,
        590,
        SDL_WINDOW_SHOWN);
    if (NULL == pWindow)    return 0;


    //����Renderer
    pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    if (NULL == pRenderer)    return 0;
    //����Renderer������ɫ��͸����(��ʱ͸���Ȳ�����Ч����Ϊû������BlendMode)
    SDL_SetRenderDrawColor(pRenderer, 0, 255, 0, 255);

    void *pixels;
    int  width, height, depth, pitch;

    GetRGBA8888Data(pixels, width, height);
    pitch = height*4;   // ÿ��ͼ����ռ�ֽ���
    depth = 4*8;        // ÿ������ռλ��(R8λG8λB8λA8λ)

    int rmask, gmask, bmask, amask;
    rmask = 0xFF000000; gmask = 0x00FF0000; bmask = 0x0000FF00; amask = 0x000000FF;     // RGBA8888ģʽ
    //rmask = 0xFF000000; gmask = 0x00FF0000; bmask = 0x0000FF00; amask = 0x00000000;   // RGB8888ģʽ

    //����һ��RGB Surface
    SDL_Surface *pTmpSurface = SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
    if (NULL == pTmpSurface)    return 0;

    //����Texture
    pTexture = SDL_CreateTextureFromSurface(pRenderer,pTmpSurface);
    if (NULL == pTexture)    return 0;

    SDL_FreeSurface(pTmpSurface);

    free(pixels);
    dstRect.x = srcRect.x = 0;
    dstRect.y = srcRect.y = 0;
    dstRect.w = srcRect.w = width;
    dstRect.h = srcRect.h = height;

    /// ABChernic ��־λ
    int isChecked;
    int isToolBarShowed=0;
    int isWindowToBeClosed=0;    /* Watch keystrokes */
    while (!isWindowToBeClosed) {
        while (SDL_PollEvent(&gEvent)) {
            //���Renderer
            SDL_RenderClear(pRenderer);
            //Texture���Ƶ�Renderer
            SDL_RenderCopy(pRenderer, pTexture, &srcRect, &dstRect);
            //����Renderer��ʾ
            SDL_RenderPresent(pRenderer);

            switch (gEvent.type) {
            case SDL_MOUSEMOTION:{
                PrintText("SDL_MOUSEMOTION", gEvent.text.text);
                }break;
            case SDL_MOUSEBUTTONDOWN:{
                PrintText("SDL_MOUSEBUTTONDOWN", gEvent.text.text);
                }break;
            /// ���̲���
            case SDL_KEYUP:{
                PrintText("SDL_KEYUP", gEvent.text.text);
                isWindowToBeClosed = 1;
                }break;
            case SDL_KEYDOWN:{
                PrintText("SDL_KEYDOWN", gEvent.text.text);
                }break;
            /// �뿪����
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

    //����
    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyTexture(pTexture);
    SDL_Quit();
    return 0;
}
