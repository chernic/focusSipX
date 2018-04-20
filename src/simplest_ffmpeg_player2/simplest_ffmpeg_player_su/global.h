#ifndef __GLOBAL_H_
#define __GLOBAL_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdio.h>
#include <string>
#define __STDC_CONSTANT_MACROS

#ifdef _WIN32
//Windows
extern "C"{
#include <Windows.h>
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "SDL2/SDL.h"
};
#else
//Linux...
#ifdef __cplusplus
extern "C"{
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <SDL2/SDL.h>
#ifdef __cplusplus
};
#endif
#endif

//Refresh Event
#define SFM_REFRESH_EVENT        (SDL_USEREVENT + 1)
#define SFM_BREAK_EVENT          (SDL_USEREVENT + 2)
#define SFM_LASTFRAME_EVENT      (SDL_USEREVENT + 3)

typedef struct SDL_Settings{
  AVFormatContext *pFormatCtx;
  AVCodecContext  *pCodecCtx;
  AVCodec         *pCodec;
  AVFrame         *pFrameYUV;
  uint8_t         *out_buffer;
  
  AVFrame         *pFrame;
  AVPacket        *packet;
  
  SDL_Texture     *sdlTexture;
  SDL_Texture     *tmpTexture;
  SDL_Rect        sdlRect;

  int             videoindex;
  int             FReaded;      // av_frame_readed
  int             FDecoded;     // avcodec_video_decoded
  int             FGot;         // got_picture;

  struct SwsContext *img_convert_ctx;
  
  void sdlSetRect(int x, int y, int w, int h){
    sdlRect.x=x;
    sdlRect.y=y;
    sdlRect.w=w;
    sdlRect.h=h;
  }
  
  SDL_Settings(){
    FReaded=0;
    FDecoded=0;
    FGot=0;
    videoindex=-1;
  }
  ~SDL_Settings()
  {
  }
  
}SDL_Settings_t;


#endif // __GLOBAL_H_