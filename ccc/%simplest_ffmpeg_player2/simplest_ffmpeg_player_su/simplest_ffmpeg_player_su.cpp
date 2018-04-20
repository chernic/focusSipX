#include <stdio.h>
#include <string>
#define __STDC_CONSTANT_MACROS

#include "global.h"
#include "SDL_Button.h"
#include "SDL_ToolBar.h"

SDL_Event gEvent;
int thread_exit=0;
int thread_pause=0;
int thread_lastframe=0;

static void SDL_GetScreenWH(int *Wid,int *Hgt){
  *Wid = GetSystemMetrics(SM_CXSCREEN);//屏幕宽度
  *Hgt = GetSystemMetrics(SM_CYSCREEN);//屏幕高度
}

static int sfp_refresh_thread(void *opaque){
  thread_exit=0;
  thread_pause=0;
  thread_lastframe=0;

  while (!thread_exit) {
    // if(!thread_pause){
      SDL_Event event;
      event.type = SFM_REFRESH_EVENT;
      SDL_PushEvent(&event);
    SDL_Delay(40);
  }
  thread_exit=0;
  thread_pause=0;
  
  //Break
  SDL_Event event;
  event.type = SFM_BREAK_EVENT;
  SDL_PushEvent(&event);
  
  return 0;
}

static void
print_string(char **text, size_t *maxlen, const char *fmt, ...){
    int len;
    va_list ap;

    va_start(ap, fmt);
    len = SDL_vsnprintf(*text, *maxlen, fmt, ap);
    if (len > 0) {
        *text += len;
        if ( ((size_t) len) < *maxlen ) {
            *maxlen -= (size_t) len;
        } else {
            *maxlen = 0;
        }
    }
    va_end(ap);
}

static void
print_modifiers(char **text, size_t *maxlen){
    int mod;
    print_string(text, maxlen, " modifiers:");
    mod = SDL_GetModState();
    if (!mod) {
        print_string(text, maxlen, " (none)");
        return;
    }
    if (mod & KMOD_LSHIFT)
        print_string(text, maxlen, " LSHIFT");
    if (mod & KMOD_RSHIFT)
        print_string(text, maxlen, " RSHIFT");
    if (mod & KMOD_LCTRL)
        print_string(text, maxlen, " LCTRL");
    if (mod & KMOD_RCTRL)
        print_string(text, maxlen, " RCTRL");
    if (mod & KMOD_LALT)
        print_string(text, maxlen, " LALT");
    if (mod & KMOD_RALT)
        print_string(text, maxlen, " RALT");
    if (mod & KMOD_LGUI)
        print_string(text, maxlen, " LGUI");
    if (mod & KMOD_RGUI)
        print_string(text, maxlen, " RGUI");
    if (mod & KMOD_NUM)
        print_string(text, maxlen, " NUM");
    if (mod & KMOD_CAPS)
        print_string(text, maxlen, " CAPS");
    if (mod & KMOD_MODE)
        print_string(text, maxlen, " MODE");
}

static void
PrintModifierState(){
    char message[512];
    char *spot;
    size_t left;

    spot = message;
    left = sizeof(message);

    print_modifiers(&spot, &left);
    SDL_Log("Initial state:%s\n", message);
}

static void
PrintKey(SDL_Keysym * sym, SDL_bool pressed, SDL_bool repeat){
    char message[512];
    char *spot;
    size_t left;

    spot = message;
    left = sizeof(message);

    /* Print the keycode, name and state */
    if (sym->sym) {
        print_string(&spot, &left,
                "Key %s:  scancode %d = %s, keycode 0x%08X = %s ",
                pressed ? "pressed " : "released",
                sym->scancode,
                SDL_GetScancodeName(sym->scancode),
                sym->sym, SDL_GetKeyName(sym->sym));
    } else {
        print_string(&spot, &left,
                "Unknown Key (scancode %d = %s) %s ",
                sym->scancode,
                SDL_GetScancodeName(sym->scancode),
                pressed ? "pressed " : "released");
    }
    print_modifiers(&spot, &left);
    if (repeat) {
        print_string(&spot, &left, " (repeat)");
    }
    SDL_Log("%s\n", message);
}

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

int  main(int argc, char* argv[]) {
  int             sdlScreenW;
  int             sdlScreenH;
  int             aTexW;
  int             aTexH;
  int             bTexW;
  int             bTexH;
  SDL_Renderer   *sdlR;         // C渲染
  SDL_Window     *sdlWindow;    // B窗口
  SDL_Thread     *video_tid;    // A线程
  
  char s1_filepath[] = "tc10.h264";
  char s2_filepath[] = "slamtv60.h264";

  SDL_Settings_t s1, s2;
  av_register_all();
  avformat_network_init();
  
  unsigned int    i;
  
  /// 1 pFormatCtx<AVCodecContext> / videoindex       <== filepath
  {// avformat_alloc_context
  s1.pFormatCtx = avformat_alloc_context();
  s2.pFormatCtx = avformat_alloc_context();
  /////// S1
  if(avformat_open_input(&s1.pFormatCtx,s1_filepath,NULL,NULL)!=0){
    printf("Couldn't open input stream.\n");
    return -1;
  }
  if(avformat_find_stream_info(s1.pFormatCtx,NULL)<0){
    printf("Couldn't find stream information.\n");
    return -1;
  }
  for(i=0; i<s1.pFormatCtx->nb_streams; i++)
    if(s1.pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO){
      s1.videoindex=i;
      break;
  }
  if(s1.videoindex==-1){
    printf("Didn't find a video stream.\n");
    return -1;
  }
  /////// S2
  if(avformat_open_input(&s2.pFormatCtx, s2_filepath,NULL,NULL)!=0){
    printf("Couldn't open input stream.\n");
    return -1;
  }
  if(avformat_find_stream_info(s2.pFormatCtx,NULL)<0){
    printf("Couldn't find stream information.\n");
    return -1;
  }
  for(i=0; i<s2.pFormatCtx->nb_streams; i++)
    if(s2.pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO){
      s2.videoindex=i;
      break;
  }
  if(s2.videoindex==-1){
    printf("Didn't find a video stream.\n");
    return -1;
  }
  }

  /// 2 [pCodec] pCodecCtx                            <==  pFormatCtx/videoindex
  {// avcodec_open2( [pCodec] pCodecCtx )
  s1.pCodecCtx = s1.pFormatCtx->streams[s1.videoindex]->codec;
  s1.pCodec    = avcodec_find_decoder(s1.pCodecCtx->codec_id);
  if(s1.pCodec==NULL){
    printf("Codec not found.\n");
    return -1;
  }
  if(avcodec_open2(s1.pCodecCtx, s1.pCodec,NULL)<0){
    printf("Could not open codec.\n");
    return -1;
  }
  /////// S2
  s2.pCodecCtx = s2.pFormatCtx->streams[s2.videoindex]->codec;
  s2.pCodec    = avcodec_find_decoder(s2.pCodecCtx->codec_id);
  if(s2.pCodec==NULL){
    printf("Codec not found.\n");
    return -1;
  }
  if(avcodec_open2(s2.pCodecCtx, s2.pCodec,NULL)<0){
    printf("Could not open codec.\n");
    return -1;
  }
  }

  /// 3 [out_buffer<uint8_t>] / pFrameYUV<AVFrame>      <== pCodecCtx
  {// avpicture_fill([out_buffer]/pFrameYUV)
  s1.pFrameYUV  = av_frame_alloc();
  s1.out_buffer = (uint8_t *)av_malloc(avpicture_get_size(PIX_FMT_YUV420P,   s1.pCodecCtx->width, s1.pCodecCtx->height));
  avpicture_fill ((AVPicture *)s1.pFrameYUV, s1.out_buffer, PIX_FMT_YUV420P, s1.pCodecCtx->width, s1.pCodecCtx->height);
  //Output Info-----------------------------
  printf("---------------- File Information ---------------\n");
  av_dump_format(s1.pFormatCtx,0,s1_filepath,0);
  printf("-------------------------------------------------\n");
  s1.img_convert_ctx = sws_getContext(s1.pCodecCtx->width, s1.pCodecCtx->height, s1.pCodecCtx->pix_fmt,
    s1.pCodecCtx->width, s1.pCodecCtx->height, PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);
  /////// S2
  s2.pFrameYUV  = av_frame_alloc();
  s2.out_buffer = (uint8_t *)av_malloc(avpicture_get_size(PIX_FMT_YUV420P,   s2.pCodecCtx->width, s2.pCodecCtx->height));
  avpicture_fill ((AVPicture *)s2.pFrameYUV, s2.out_buffer, PIX_FMT_YUV420P, s2.pCodecCtx->width, s2.pCodecCtx->height);
  //Output Info-----------------------------
  printf("---------------- File Information ---------------\n");
  av_dump_format(s2.pFormatCtx,0,s1_filepath,0);
  printf("-------------------------------------------------\n");
  s2.img_convert_ctx = sws_getContext(s2.pCodecCtx->width, s2.pCodecCtx->height, s2.pCodecCtx->pix_fmt,
    s2.pCodecCtx->width, s2.pCodecCtx->height, PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);
  }

  {// A线程 video_tid   <SDL_Thread>
  video_tid = SDL_CreateThread(sfp_refresh_thread,NULL,NULL);
  }

  /// 这里设置屏幕大小高和宽(SDL 2.0 Support for multiple windows)
  sdlScreenW = 720;
  sdlScreenH = 560;
  /// 这里获取屏幕大小
  //SDL_GetScreenWH(&sdlScreenW, &sdlScreenH);
  {// B窗口 sdlWindow<SDL_Window>                       <== sdlScreenW/sdlScreenH
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
    printf( "Could not initialize SDL - %s\n", SDL_GetError());
    return -1;
  }
  /// 这里创建屏幕
  sdlWindow = SDL_CreateWindow(
    "Simplest ffmpeg player's Window",
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED,
    sdlScreenW,
    sdlScreenH,
    SDL_WINDOW_OPENGL);
    // SDL_WINDOW_OPENGL|SDL_WINDOW_FULLSCREEN);
  if(!sdlWindow){
    printf("SDL: could not create window - exiting:%s\n",SDL_GetError());
    return -1;
  }
  }

  {// C渲染 sdlR<SDL_Renderer>/sdlTexture<SDL_Texture>  <== sdlWindow
  aTexW         = s1.pCodecCtx->width;
  aTexH         = s1.pCodecCtx->height;
  bTexW         = s2.pCodecCtx->width;
  bTexH         = s2.pCodecCtx->height;

  sdlR          = SDL_CreateRenderer(sdlWindow, -1, 0);

  s1.sdlTexture = SDL_CreateTexture(sdlR, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING, aTexW, aTexH);

  s2.sdlTexture = SDL_CreateTexture(sdlR, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING, bTexW, bTexH);

  }

  s1.sdlSetRect(0, 0, s1.pCodecCtx->width, s1.pCodecCtx->height);
  s2.sdlSetRect(0, 0, sdlScreenW/3, sdlScreenH/2);         // 大概显示为左上角屏幕的六分之一

  // Run-Time Check Failure #3 - The variable 'event' is being used 
  // without being initialized.
  SDL_StartTextInput();

  /* Print initial modifier state */
  SDL_PumpEvents();
  PrintModifierState();

  /// ABChernic 按钮设置
  SDL_ToolBar ToolBar(sdlR, sdlScreenW, sdlScreenH, 80, 80);
  SDL_ToolBar *pToolBar=&ToolBar;

  /// ABChernic 标志位
  int isChecked;
  int isToolBarShowed=0;
  int isWindowToBeClosed=0;    /* Watch keystrokes */

  while (!isWindowToBeClosed) {
    /* Check for gEvent */
    /*SDL_WaitEvent(&gEvent); emscripten does not like waiting*/
    while (SDL_PollEvent(&gEvent)) {
      /// ABChernic 按钮纹理区设置
      pToolBar->Handle_event              (sdlR, gEvent, &isToolBarShowed);
      pToolBar->mButtonPlay.Handle_event  (sdlR, gEvent, &isChecked);
      pToolBar->mButtonClose.Handle_event (sdlR, gEvent, &isWindowToBeClosed);

      // pFrame
      s1.pFrame = av_frame_alloc();
      s2.pFrame = av_frame_alloc();
      // packet
      s1.packet = (AVPacket *)av_malloc(sizeof(AVPacket));
      s2.packet = (AVPacket *)av_malloc(sizeof(AVPacket));

      /// 1 pFormatCtx
      /// 1 videoindex
      /// 2 pCodecCtx
      /// 3 pFrameYUV
      // FReaded  已读数据
      // FDecoded 已经解码
      // FGot     解码结果
      /// C sdlTexture
      switch (gEvent.type) {
      case SFM_LASTFRAME_EVENT:
      case SFM_REFRESH_EVENT:{    /// 屏幕刷新
        SDL_RenderClear(sdlR);
        if(!thread_pause){
          if(av_read_frame(s1.pFormatCtx, s1.packet)>=0){
            s1.FReaded=1;
          }
          if(av_read_frame(s2.pFormatCtx, s2.packet)>=0){
            s2.FReaded=1;
          }
          if(s1.FReaded || s2.FReaded){
            if( (s1.packet->stream_index==s1.videoindex) || (s2.packet->stream_index==s2.videoindex) ){
              if(s1.FReaded){
                s1.FDecoded = avcodec_decode_video2(s1.pCodecCtx, s1.pFrame, &s1.FGot, s1.packet);
              }
              if(s2.FReaded){
                s2.FDecoded = avcodec_decode_video2(s2.pCodecCtx, s2.pFrame, &s2.FGot, s2.packet);
              }
              if( (s1.FDecoded < 0) || (s2.FDecoded < 0) ){
                printf("Decode Error.\n");
                return -1;
              }
              if(s1.FGot||s2.FGot){
                // 图像一 满屏
                if(s1.FReaded && s1.FDecoded){
                  sws_scale(s1.img_convert_ctx, (const uint8_t* const*)s1.pFrame->data, s1.pFrame->linesize, 0,
                  s1.pCodecCtx->height, s1.pFrameYUV->data, s1.pFrameYUV->linesize);

                  SDL_UpdateTexture( s1.sdlTexture, NULL, s1.pFrameYUV->data[0], s1.pFrameYUV->linesize[0] );
                  s1.tmpTexture = s1.sdlTexture;
                  SDL_RenderCopy( sdlR, s1.sdlTexture, NULL, NULL);
                }
                // 图像二根据实际大小显示
                if(s2.FReaded && s2.FDecoded){
                    sws_scale(s2.img_convert_ctx, (const uint8_t* const*)s2.pFrame->data, s2.pFrame->linesize, 0,
                    s2.pCodecCtx->height, s2.pFrameYUV->data, s2.pFrameYUV->linesize);

                    SDL_UpdateTexture( s2.sdlTexture, NULL, s2.pFrameYUV->data[0], s2.pFrameYUV->linesize[0] );
                    s2.tmpTexture = s2.sdlTexture;
                    SDL_RenderCopy( sdlR, s2.sdlTexture, NULL, &s2.sdlRect );
                }
              }
            }
            if(s1.FReaded){
              av_free_packet(s1.packet);
            }
            if(s2.FReaded){
              av_free_packet(s2.packet);
            }
          }else{ //Exit Thread
            thread_exit=1;
          }
        }else{
          #ifndef _NOT_USE_TEMP_TEXTURE_WHEN_PAUSE
          // 当参数二为NULL时, 则不绘屏幕, 屏幕显示当前画笔颜色.
          SDL_RenderCopy( sdlR, s1.FGot?s1.tmpTexture:NULL, NULL, NULL);
          SDL_RenderCopy( sdlR, s2.FGot?s2.tmpTexture:NULL, NULL, &s2.sdlRect );
          #endif
        }
        // 自动隐藏工具栏,独立于视频
        if(isToolBarShowed){
          pToolBar->Show(sdlR, true);
        }
        SDL_RenderPresent(sdlR);
      }
          break;
      case SDL_TEXTEDITING:{      /// 文字操作
          // PrintText("EDIT", event.text.text);
      }
          break;
      case SDL_TEXTINPUT:{
          // PrintText("INPUT", event.text.text);
      }
          break;
      case SDL_MOUSEMOTION:{
      }
          break;
      case SDL_MOUSEBUTTONDOWN:{  /// 鼠标输入
          /* Left button quits the app, other buttons toggles text input */
          if (gEvent.button.button == SDL_BUTTON_LEFT) {
              //isWindowToBeClosed = 1;
          } else {
            // if (SDL_IsTextInputActive()) {
                // SDL_Log("Stopping text input\n");
                // SDL_StopTextInput();
            // } else {
                // SDL_Log("Starting text input\n");
                // SDL_StartTextInput();
            // }
          }
      }
          break;
      /// 键盘操作
      case SDL_KEYUP:{
          PrintKey(&gEvent.key.keysym, (gEvent.key.state == SDL_PRESSED) 
            ? SDL_TRUE : SDL_FALSE, (gEvent.key.repeat) ? SDL_TRUE : SDL_FALSE);
      }
          break;
      case SDL_KEYDOWN:{
        //Pause
        if(gEvent.key.keysym.sym==SDLK_SPACE)
          thread_pause=!thread_pause;
      }
          break;
      /// 离开操作
      case SDL_QUIT:{
          isWindowToBeClosed = 1;
          thread_exit=1;
      }
          break;
      case SFM_BREAK_EVENT:{
      }
          break;
      default:{
      }
          break;
      }
      thread_pause=(isChecked==1)?1:0;
    }

#ifdef __EMSCRIPTEN__
    if (isWindowToBeClosed) {
        emscripten_cancel_main_loop();
    }
#endif
  }

  {// Released
  sws_freeContext(s1.img_convert_ctx);
  sws_freeContext(s2.img_convert_ctx);

  SDL_Quit();
  //--------------
  av_frame_free(&s1.pFrameYUV);
  av_frame_free(&s2.pFrameYUV);
  av_frame_free(&s1.pFrame);
  av_frame_free(&s2.pFrame);
  avcodec_close(s1.pCodecCtx);
  avcodec_close(s2.pCodecCtx);
  avformat_close_input(&s1.pFormatCtx);
  avformat_close_input(&s2.pFormatCtx);
  }

  return 0;
}
