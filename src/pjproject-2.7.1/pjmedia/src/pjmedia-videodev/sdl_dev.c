/* $Id: sdl_dev.c 5392 2016-07-20 06:55:11Z riza $ */  
/* 
 * Copyright (C) 2008-2011 Teluu Inc. (http://www.teluu.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published bysdl_stream_get_sdl_window
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */
#include <pjmedia-videodev/videodev_imp.h>
#include <pj/assert.h>
#include <pj/log.h>
#include <pj/os.h>

#if defined(PJMEDIA_HAS_VIDEO) && PJMEDIA_HAS_VIDEO != 0 && \
    defined(PJMEDIA_VIDEO_DEV_HAS_SDL) && PJMEDIA_VIDEO_DEV_HAS_SDL != 0

#include <SDL.h>
// #include <SDL_Thread.h>
#include <SDL_syswm.h>
/// ABChernic
#define SFM_REFRESH_EVENT (SDL_USEREVENT + 1)

// https://stackoverflow.com/questions/13347429/sdl-loadbmp-only-returning-null
//#include <SDL_Image.h>

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
#   include "SDL_opengl.h"
#   define OPENGL_DEV_IDX 1
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */

#if !(SDL_VERSION_ATLEAST(1,3,0))
#   error "SDL 1.3 or later is required"
#endif

#if defined(PJ_DARWINOS) && PJ_DARWINOS!=0
#   include "TargetConditionals.h"
#   include <Foundation/Foundation.h>
#endif

#define THIS_FILE           "sdl_dev.c"
#define DEFAULT_CLOCK_RATE  90000
#define DEFAULT_WIDTH       640
#define DEFAULT_HEIGHT      480
#define DEFAULT_FPS         25

// ABChernic : 2018-01-30 WinAPI
// #define NOMINMAX
// #include <windows.h>
// #include <algorithm>
// #include <iostream>
// #include <vector>

/// ABChernic : 
typedef enum BTUUON_CHECK_STATE{
  BTUUON_UNCHECKED=0,
  BTUUON_CHECKED=1,
}euBtnStste;
typedef struct BtnRect{
  SDL_Rect mouseover[2];
  SDL_Rect mouseout[2];
  SDL_Rect mousedown[2];
  SDL_Rect mouseup[2];
}BtnRect_t;
typedef struct sdl_button{
    SDL_Rect        decR;
    SDL_Rect        *pSrcR;
    SDL_Texture     *pTexture;
    BtnRect_t       btnRect;
    euBtnStste      isChecked;
}sdl_button_t;
typedef struct sdl_toolbar_info{
    BOOL         isToolBarShowed;
    SDL_Rect     mBlankRect;
    sdl_button_t mPlay;
    sdl_button_t mClose;

    pjmedia_rect_size size;
}sdl_toolbar_info_t;

///////////////////////////////////////////
typedef struct sdl_fmt_info{
    pjmedia_format_id   fmt_id;
    Uint32              sdl_format;
    Uint32              Rmask;
    Uint32              Gmask;
    Uint32              Bmask;
    Uint32              Amask;
} sdl_fmt_info;

static sdl_fmt_info sdl_fmts[] = {

#if PJ_IS_BIG_ENDIAN
    {PJMEDIA_FORMAT_RGBA,  (Uint32)SDL_PIXELFORMAT_RGBA8888,
     0xFF000000, 0xFF0000, 0xFF00, 0xFF} ,
    {PJMEDIA_FORMAT_RGB24, (Uint32)SDL_PIXELFORMAT_RGB24,
     0xFF0000, 0xFF00, 0xFF, 0} ,
    {PJMEDIA_FORMAT_BGRA,  (Uint32)SDL_PIXELFORMAT_BGRA8888,
     0xFF00, 0xFF0000, 0xFF000000, 0xFF} ,
#else /* PJ_IS_BIG_ENDIAN */
    {PJMEDIA_FORMAT_RGBA,  (Uint32)SDL_PIXELFORMAT_ABGR8888,
     0xFF, 0xFF00, 0xFF0000, 0xFF000000} ,
    {PJMEDIA_FORMAT_RGB24, (Uint32)SDL_PIXELFORMAT_BGR24,
     0xFF, 0xFF00, 0xFF0000, 0} ,
    {PJMEDIA_FORMAT_BGRA,  (Uint32)SDL_PIXELFORMAT_ARGB8888,
     0xFF0000, 0xFF00, 0xFF, 0xFF000000} ,
#endif /* PJ_IS_BIG_ENDIAN */

    {PJMEDIA_FORMAT_DIB , (Uint32)SDL_PIXELFORMAT_RGB24,
     0xFF0000, 0xFF00, 0xFF, 0} ,

    {PJMEDIA_FORMAT_YUY2, SDL_PIXELFORMAT_YUY2, 0, 0, 0, 0} ,
    {PJMEDIA_FORMAT_UYVY, SDL_PIXELFORMAT_UYVY, 0, 0, 0, 0} ,
    {PJMEDIA_FORMAT_YVYU, SDL_PIXELFORMAT_YVYU, 0, 0, 0, 0} ,
    {PJMEDIA_FORMAT_I420, SDL_PIXELFORMAT_IYUV, 0, 0, 0, 0} ,
    {PJMEDIA_FORMAT_YV12, SDL_PIXELFORMAT_YV12, 0, 0, 0, 0} ,
    {PJMEDIA_FORMAT_I420JPEG, SDL_PIXELFORMAT_IYUV, 0, 0, 0, 0} ,
    {PJMEDIA_FORMAT_I422JPEG, SDL_PIXELFORMAT_YV12, 0, 0, 0, 0}
};

/* sdl_ device info */ 
struct sdl_dev_info{
    pjmedia_vid_dev_info     info;
};

/* Linked list of streams */
struct stream_list{
    PJ_DECL_LIST_MEMBER(struct stream_list);
    struct sdl_stream   *stream;
};

#define INITIAL_MAX_JOBS 64
#define JOB_QUEUE_INC_FACTOR 2

typedef pj_status_t (*job_func_ptr)(void *data);

typedef struct job {
    job_func_ptr    func;
    void           *data;
    unsigned        flags;
    pj_status_t     retval;
} job;

#if defined(PJ_DARWINOS) && PJ_DARWINOS!=0
@interface JQDelegate: NSObject
{
    @public
    job *pjob;
}

- (void)run_job;
@end

@implementation JQDelegate
- (void)run_job
{
    pjob->retval = (*pjob->func)(pjob->data);
}
@end
#endif /* PJ_DARWINOS */

typedef struct job_queue {
    pj_pool_t      *pool;
    job           **jobs;
    pj_sem_t      **job_sem;
    pj_sem_t      **old_sem;
    pj_mutex_t     *mutex;
    pj_thread_t    *thread;
    pj_sem_t       *sem;

    unsigned        size;
    unsigned        head, tail;
    pj_bool_t       is_full;
    pj_bool_t       is_quitting;
} job_queue;

/* sdl_ factory */
struct sdl_factory{
    pjmedia_vid_dev_factory  base;
    pj_pool_t           *pool;
    pj_pool_factory     *pf;

    unsigned             dev_count;
    struct sdl_dev_info         *dev_info;
    job_queue                   *jq;

    pj_thread_t         *sdl_thread;        /**< SDL thread.        */
    pj_sem_t                    *sem;
    pj_mutex_t          *mutex;
    struct stream_list       streams;
    pj_bool_t                    is_quitting;
    pj_thread_desc       thread_desc;
    pj_thread_t         *ev_thread;
};

typedef struct scream{
    pj_pool_t               *pool;           /**< Memory pool.       */
    pjmedia_vid_dev_cb      vid_cb;          /**< Stream callback.   */
    void                    *user_data;      /**< Application data.  */

    struct sdl_factory      *sf;
    const pjmedia_frame     *frame;
    pj_bool_t               is_running;
    pj_timestamp            last_ts;
    struct stream_list      list_entry;

    SDL_Window              *window;         /**< Display window.    */
    SDL_Renderer            *renderer;       /**< Display renderer.  */

    SDL_Texture             *textureP;
    Uint32                   sdl_formatP;
    SDL_Rect                 rectP;
    SDL_Rect                 dstrectP;

    SDL_Texture             *textureS;
    Uint32                   sdl_formatS;

    int                      pitch;

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    SDL_GLContext           *gl_context;
    GLuint                  texture;
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */

    pjmedia_video_apply_fmt_param vafp;

    int                     pitchS;           /**< Pitch   value.     */
    SDL_Rect                rectS;            /**< Frame   rectangle  */
    SDL_Rect                dstrectS;         /**< Display rectangle. */

    int                     thread_exit;      /* if exit              */
    int                     thread_pause;     /* if pause             */
    pj_str_t                running_dir;      /* OCX runing directory */
    sdl_toolbar_info_t      toolbar;
}sdl_scream;

/* Video stream. */
struct sdl_stream{
    pjmedia_vid_dev_stream  base;           /**< Base stream        */
    pjmedia_vid_dev_param   param;          /**< Settings           */
    sdl_scream              sp;
};

/* Prototypes */
static pj_status_t sdl_factory_init(pjmedia_vid_dev_factory *f);
static pj_status_t sdl_factory_destroy(pjmedia_vid_dev_factory *f);
static pj_status_t sdl_factory_refresh(pjmedia_vid_dev_factory *f);
static unsigned    sdl_factory_get_dev_count(pjmedia_vid_dev_factory *f);
static pj_status_t sdl_factory_get_dev_info(pjmedia_vid_dev_factory *f,unsigned index,pjmedia_vid_dev_info *info);
static pj_status_t sdl_factory_default_param(pj_pool_t *pool,pjmedia_vid_dev_factory *f,unsigned index,pjmedia_vid_dev_param *param);
static pj_status_t sdl_factory_create_stream(pjmedia_vid_dev_factory *f,pjmedia_vid_dev_param *param,const pjmedia_vid_dev_cb *cb,void *user_data,pjmedia_vid_dev_stream **p_vid_strm);
static pj_status_t resize_disp          (struct sdl_stream *strm,pjmedia_rect_size *new_disp_size);
static pj_status_t sdl_destroy_all      (void *data);

/// ABChernic : 2018-01-04 >>>
// O1
static pj_status_t sdl_stream_get_param (pjmedia_vid_dev_stream *strm,pjmedia_vid_dev_param *param);
// O2
static pj_status_t sdl_stream_get_cap   (pjmedia_vid_dev_stream *strm,pjmedia_vid_dev_cap cap,void *value);
// O3
static pj_status_t sdl_stream_set_cap   (pjmedia_vid_dev_stream *strm,pjmedia_vid_dev_cap cap,const void *value);
// O4
static pj_status_t sdl_stream_start     (pjmedia_vid_dev_stream *strm);

// O6
static pj_status_t sdl_stream_put_frame (pjmedia_vid_dev_stream *strm,const pjmedia_frame *frame);
// O7
static pj_status_t sdl_stream_stop      (pjmedia_vid_dev_stream *strm);
// O8
static pj_status_t sdl_stream_destroy   (pjmedia_vid_dev_stream *strm);
// O9
static pj_status_t sdl_stream_set_dir   (pjmedia_vid_dev_stream *strm, const void *value);

static pj_status_t sdl_stream_get_sdl_window (pjmedia_vid_dev_stream *strm, void *value);
static pj_status_t sdl_stream_set_sdl_window (pjmedia_vid_dev_stream *strm, const void *value);

// 10
static pj_status_t sdl_stream_put_previw(pjmedia_vid_dev_stream *strm,const pjmedia_frame *frame);
// 11
static pj_status_t sdl_stream_put_stream(pjmedia_vid_dev_stream *strm,const pjmedia_frame *frame);
/// ABChernic : 2018-01-04 <<<

/* Job queue prototypes */
static pj_status_t job_queue_create(pj_pool_t *pool, job_queue **pjq);
static pj_status_t job_queue_post_job(job_queue *jq, job_func_ptr func,void *data, unsigned flags,pj_status_t *retval);
static pj_status_t job_queue_destroy(job_queue *jq);
/* Operations */
static pjmedia_vid_dev_factory_op factory_op ={
    &sdl_factory_init,
    &sdl_factory_destroy,
    &sdl_factory_get_dev_count,
    &sdl_factory_get_dev_info,
    &sdl_factory_default_param,
    &sdl_factory_create_stream,
    &sdl_factory_refresh
};

/// ABChernic : sdl_dev.c)      static pjmedia_vid_dev_stream_op stream_op
/// ABChernic : videodev_imp.h) struct pjmedia_vid_dev_stream_op
/// ABChernic : videodev.c)     PJ_DEF(pj_status_t) XXX()
static pjmedia_vid_dev_stream_op stream_op ={
    &sdl_stream_get_param,          // O1 *get_param
    &sdl_stream_get_cap,            // O2 *get_cap
    &sdl_stream_set_cap,            // O3 *set_cap
    &sdl_stream_start,              // O4 *start
    NULL,                           // O5
    &sdl_stream_put_frame,          // O6 *put_frame
    &sdl_stream_stop,               // O7 *stop
    &sdl_stream_destroy,            // O8 *destroy
    &sdl_stream_set_dir,            // O9 *set_dir
    &sdl_stream_put_previw,         // 10 *put_previw
    &sdl_stream_put_stream,         // 11 *put_stream

    &sdl_stream_get_sdl_window,     // 12
    &sdl_stream_set_sdl_window,     // 13
};
/// ABChernic : 2018-01-04 <<<

/*
 * Util
 */
static void sdl_log_err(const char *op){
    PJ_LOG(1,(THIS_FILE, "%s error: %s", op, SDL_GetError()));
}

/****************************************************************************
 * Factory operations
 */
/*
 * Init sdl_ video driver.
 */
pjmedia_vid_dev_factory* pjmedia_sdl_factory(pj_pool_factory *pf){
    struct sdl_factory *f;
    pj_pool_t *pool;

    pool = pj_pool_create(pf, "sdl video", 1000, 1000, NULL);
    f = PJ_POOL_ZALLOC_T(pool, struct sdl_factory);
    f->pf = pf;
    f->pool = pool;
    f->base.op = &factory_op;

    return &f->base;
}

static pj_status_t sdl_init(void * data){
    PJ_UNUSED_ARG(data);

    if (SDL_Init(SDL_INIT_VIDEO)) {
        sdl_log_err("SDL_Init()");
        return PJMEDIA_EVID_INIT;
    }

    return PJ_SUCCESS;
}

static struct sdl_stream* find_stream(struct sdl_factory *sf,Uint32 windowID,pjmedia_event *pevent){
    struct stream_list *it, *itBegin;
    struct sdl_stream *strm = NULL;

    itBegin = &sf->streams;
    for (it = itBegin->next; it != itBegin; it = it->next) {
        if (SDL_GetWindowID(it->stream->sp.window) == windowID)
        {
            strm = it->stream;
            break;
        }
    }
 
    if (strm)
        pjmedia_event_init(pevent, PJMEDIA_EVENT_NONE, &strm->sp.last_ts,
                   strm);

    return strm;
}
/// toolbar_make
static pj_status_t sdl_toolbar_make         (struct sdl_stream *strm, int x, int y, int w, int h) {
    strm->sp.toolbar.mBlankRect.x = x;
    strm->sp.toolbar.mBlankRect.y = y;
    strm->sp.toolbar.mBlankRect.w = w;
    strm->sp.toolbar.mBlankRect.h = h;

    return PJ_SUCCESS;
};
static pj_status_t sdl_toolbar_make_play    (struct sdl_stream *strm, int WindowW, int WindowH, int ButtonW, int ButtonH) {
    // 注意这里xy是指元素块的左上角坐标
    int Plus=2;
    int x=WindowW/2-ButtonW;
    int y=WindowH-ButtonH-Plus;
    int w=ButtonW;
    int h=ButtonH;
    strm->sp.toolbar.mPlay.decR.x=x;
    strm->sp.toolbar.mPlay.decR.y=y;
    strm->sp.toolbar.mPlay.decR.w=w;
    strm->sp.toolbar.mPlay.decR.h=h;
    return PJ_SUCCESS;
};
static pj_status_t sdl_toolbar_make_close   (struct sdl_stream *strm, int WindowW, int WindowH, int ButtonW, int ButtonH) {
    // 注意这里xy是指元素块的左上角坐标
    int Plus=2;
    int x=WindowW/2;
    int y=WindowH-ButtonH-Plus;
    int w=ButtonW;
    int h=ButtonH;
    strm->sp.toolbar.mClose.decR.x=x;
    strm->sp.toolbar.mClose.decR.y=y;
    strm->sp.toolbar.mClose.decR.w=w;
    strm->sp.toolbar.mClose.decR.h=h;
    return PJ_SUCCESS;
};

/// toolbar_load
static pj_status_t sdl_toolbar_load_play    (struct sdl_stream *strm, const char *file) {
    // 输出 strm->sp.toolbar.mPlay.pTexture
    SDL_Surface   *temp;
    SDL_BlendMode blendMode = SDL_BLENDMODE_BLEND;

    //SDL_BLENDMODE_BLEND = 0x00000001
    //SDL_BLENDMODE_ADD = 0x00000002
    //SDL_BLENDMODE_MOD = 0x00000004


    SDL_Renderer *pRenderer = strm->sp.renderer;

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
    strm->sp.toolbar.mPlay.pTexture = SDL_CreateTextureFromSurface(pRenderer, temp);
    if (!strm->sp.toolbar.mPlay.pTexture) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s\n", SDL_GetError());
      SDL_FreeSurface(temp);
      return (-1);
    }
    if (SDL_SetTextureBlendMode(strm->sp.toolbar.mPlay.pTexture, blendMode) < 0) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't set blend mode: %s\n", SDL_GetError());
      SDL_FreeSurface(temp);
      SDL_DestroyTexture(strm->sp.toolbar.mPlay.pTexture);
      return (-1);
    }
    SDL_FreeSurface(temp);
    /* We're ready to roll. :) */
    return (0);
}
static pj_status_t sdl_toolbar_load_close   (struct sdl_stream *strm, const char *file) {
    // 输出 strm->sp.toolbar.mClose.pTexture
    SDL_Surface   *temp;
    SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
    SDL_Renderer *pRenderer = strm->sp.renderer;
    /* Load the sprite image */
    temp = SDL_LoadBMP(file);
    if (temp == NULL) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, 
        "sdl_toolbar_load_close Couldn't load %s: %s", file, SDL_GetError());
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
    strm->sp.toolbar.mClose.pTexture = SDL_CreateTextureFromSurface(pRenderer, temp);
    if (!strm->sp.toolbar.mClose.pTexture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(temp);
        return (-1);
    }
    if (SDL_SetTextureBlendMode(strm->sp.toolbar.mClose.pTexture, blendMode) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't set blend mode: %s\n", SDL_GetError());
        SDL_FreeSurface(temp);
        SDL_DestroyTexture(strm->sp.toolbar.mClose.pTexture);
        return (-1);
    }
    SDL_FreeSurface(temp);
    /* We're ready to roll. :) */
    return (0);
}
/// toolbar_show
static pj_status_t sdl_toolbar_update       (struct sdl_stream *strm, int x, int y, int w, int h){
    int PrevieW = strm->sp.rectP.w;
    int PrevieH = strm->sp.rectP.h;
    int WindowW = strm->param.disp_size.w;
    int WindowH = strm->param.disp_size.h;

    int ButtonW = strm->sp.toolbar.mClose.decR.w;
    int ButtonH = strm->sp.toolbar.mClose.decR.h;

	PJ_UNUSED_ARG(x);
	PJ_UNUSED_ARG(y);
	PJ_UNUSED_ARG(w);
	PJ_UNUSED_ARG(h);

	PJ_UNUSED_ARG(PrevieW);
	PJ_UNUSED_ARG(PrevieH);

    sdl_toolbar_make      (strm, WindowW, WindowH, ButtonW, ButtonH);
    sdl_toolbar_make_close(strm, WindowW, WindowH, ButtonW, ButtonH);
    sdl_toolbar_make_play (strm, WindowW, WindowH, ButtonW, ButtonH);

    return PJ_SUCCESS;
}
static pj_status_t sdl_toolbar_show         (struct sdl_stream *strm){
    SDL_SetRenderDrawColor(strm->sp.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(strm->sp.renderer, &strm->sp.toolbar.mBlankRect);
    SDL_SetRenderDrawColor(strm->sp.renderer, 0x00, 0x00, 0x00, 0x00);
    return PJ_SUCCESS;
}
static pj_status_t sdl_toolbar_show_close   (struct sdl_stream *strm){
    if (!strm->sp.toolbar.mClose.pTexture) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Please firstly create texture: %s\n", SDL_GetError());
      return PJ_FALSE;
    }
    SDL_RenderCopy(strm->sp.renderer, strm->sp.toolbar.mClose.pTexture, strm->sp.toolbar.mClose.pSrcR, &strm->sp.toolbar.mClose.decR);
    return PJ_SUCCESS;
}
static pj_status_t sdl_toolbar_show_play    (struct sdl_stream *strm){
    if (!strm->sp.toolbar.mPlay.pTexture) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Please firstly create texture: %s\n", SDL_GetError());
      return PJ_FALSE;
    }
    SDL_RenderCopy(strm->sp.renderer, strm->sp.toolbar.mPlay.pTexture, strm->sp.toolbar.mPlay.pSrcR, &strm->sp.toolbar.mPlay.decR);
    return PJ_SUCCESS;
}

//////////////////////////
/// handle_event start
//////////////////////////
static pj_status_t handle_event_button_play	(struct sdl_stream *strm, SDL_Event sevent){
    /// strm->sp.toolbar.mPlay.pSrcR
    /// strm->sp.toolbar.mPlay.isChecked
    SDL_Rect    decR       = strm->sp.toolbar.mPlay.decR;
    euBtnStste  isChecked  = strm->sp.toolbar.mPlay.isChecked;
    int x=0,y=0;
    if(sevent.type==SDL_MOUSEMOTION) {
        // 如果发现了鼠标移动事件，就要得到鼠标当前位置，然后判断其是否在定义的button内
        x=sevent.motion.x;
        y=sevent.motion.y;
        // 如果鼠标在定义的button内
        if((x>decR.x)&&(x<decR.x+decR.w)&&(y>decR.y)&&(y<decR.y+decR.h)){
            strm->sp.toolbar.mPlay.pSrcR = &(strm->sp.toolbar.mPlay.btnRect.mouseover[isChecked]);
        // 鼠标在button外
        }else{ 
            strm->sp.toolbar.mPlay.pSrcR = &(strm->sp.toolbar.mPlay.btnRect.mouseout[isChecked]);
        }
    }
    // 如果发生了鼠标按键按下事件
    if(sevent.type==SDL_MOUSEBUTTONDOWN) {
        if(sevent.button.button==SDL_BUTTON_LEFT){ 
            // 如果是左键按下的事件，就要判断按下鼠标的时候鼠标是否处在button区域中，所以要得到鼠标坐标
            x=sevent.button.x;
            y=sevent.button.y;
            if((x>decR.x)&&(x<decR.x+decR.w)&&(y>decR.y)&&(y<decR.y+decR.h)){
                // 反相
                strm->sp.toolbar.mPlay.isChecked = (isChecked==BTUUON_CHECKED)?BTUUON_UNCHECKED:BTUUON_CHECKED;

                // 如果按下鼠标左键的时候鼠标处在button内
                strm->sp.toolbar.mPlay.pSrcR = &(strm->sp.toolbar.mPlay.btnRect.mousedown[isChecked]);
            }
        }
    }
    // 如果发生了鼠标左键弹起事件，处理方式同鼠标左键按下事件
    if(sevent.type==SDL_MOUSEBUTTONUP) {
        if(sevent.button.button==SDL_BUTTON_LEFT)
        { // 如果是左键弹起的事件，就要判断按下鼠标的时候鼠标是否处在button区域中，所以要得到鼠标坐标
            x=sevent.button.x;
            y=sevent.button.y;
            if((x>decR.x)&&(x<decR.x+decR.w)&&(y>decR.y)&&(y<decR.y+decR.h))
            {// 如果按下鼠标左键的时候鼠标处在button内
                strm->sp.toolbar.mPlay.pSrcR = &(strm->sp.toolbar.mPlay.btnRect.mouseup[isChecked]);
            }
        }
    }
    return PJ_SUCCESS;
}
static pj_status_t handle_event_button_close(struct sdl_stream *strm, SDL_Event sevent){
    /// strm->sp.toolbar.mClose.pSrcR
    /// strm->sp.toolbar.mClose.isChecked
    SDL_Rect    decR       = strm->sp.toolbar.mClose.decR;
    euBtnStste  isChecked  = strm->sp.toolbar.mClose.isChecked;
    pj_status_t status;
    int x=0,y=0;
    if(sevent.type==SDL_MOUSEMOTION) {
        // 如果发现了鼠标移动事件，就要得到鼠标当前位置，然后判断其是否在定义的button内
        x=sevent.motion.x;
        y=sevent.motion.y;
        // 如果鼠标在定义的button内
        if((x>decR.x)&&(x<decR.x+decR.w)&&(y>decR.y)&&(y<decR.y+decR.h)){
            strm->sp.toolbar.mClose.pSrcR = &(strm->sp.toolbar.mClose.btnRect.mouseover[isChecked]);
        // 鼠标在button外
        }else{ 
            strm->sp.toolbar.mClose.pSrcR = &(strm->sp.toolbar.mClose.btnRect.mouseout[isChecked]);
        }
    }
    // 如果发生了鼠标按键按下事件
    if(sevent.type==SDL_MOUSEBUTTONDOWN) {
        if(sevent.button.button==SDL_BUTTON_LEFT){ 
            // 如果是左键按下的事件，就要判断按下鼠标的时候鼠标是否处在button区域中，所以要得到鼠标坐标
            x=sevent.button.x;
            y=sevent.button.y;
            if((x>decR.x)&&(x<decR.x+decR.w)&&(y>decR.y)&&(y<decR.y+decR.h)){
                status = sdl_destroy_all(strm);
                if (status != PJ_SUCCESS)
                    return status;  
            }
        }
    }
    // 如果发生了鼠标左键弹起事件，处理方式同鼠标左键按下事件
    if(sevent.type==SDL_MOUSEBUTTONUP) {
        if(sevent.button.button==SDL_BUTTON_LEFT){
            // 如果是左键弹起的事件，就要判断按下鼠标的时候鼠标是否处在button区域中，所以要得到鼠标坐标
            x=sevent.button.x;
            y=sevent.button.y;
            if((x>decR.x)&&(x<decR.x+decR.w)&&(y>decR.y)&&(y<decR.y+decR.h))
            {
                status = sdl_destroy_all(strm);
                if (status != PJ_SUCCESS)
                    return status;  
            }
        }
    }
    return PJ_SUCCESS;
}
static pj_status_t handle_event				(void *data){
    struct sdl_factory *sf = (struct sdl_factory*)data;
    SDL_Rect     BlankRect;
    SDL_Event    sevent;
    int x=0;
    int y=0;

    if (!pj_thread_is_registered())
    pj_thread_register("sdl_ev", sf->thread_desc, &sf->ev_thread);

    while (SDL_PollEvent(&sevent)) {
        struct sdl_stream *strm = NULL;
        pjmedia_event pevent;

        pj_mutex_lock(sf->mutex);
        pevent.type = PJMEDIA_EVENT_NONE;

        /**/
        switch(sevent.type) {
            case SDL_MOUSEMOTION:{
                strm = find_stream(sf, sevent.button.windowID, &pevent);
                if(strm && !strm->sp.thread_exit){
                    BlankRect = strm->sp.toolbar.mBlankRect;
                    x = sevent.motion.x;
                    y = sevent.motion.y;
                    if((x>BlankRect.x)&&(x<BlankRect.x+BlankRect.w)&&(y>BlankRect.y)&&(y<BlankRect.y+BlankRect.h)){
                        strm->sp.toolbar.isToolBarShowed = 1;
                    }else{
                        strm->sp.toolbar.isToolBarShowed = 0;
                    }
                }
            }break;
            // 这里是传递按钮事件关键
            // 以前是使用Windows
            case SDL_MOUSEBUTTONDOWN:{
                 strm = find_stream(sf, sevent.button.windowID, &pevent);
                 pevent.type = PJMEDIA_EVENT_MOUSE_BTN_DOWN;
            }break;
            case SDL_WINDOWEVENT:{
                strm = find_stream(sf, sevent.window.windowID, &pevent);
                switch (sevent.window.event) {
                case SDL_WINDOWEVENT_RESIZED:
                    pevent.type = PJMEDIA_EVENT_WND_RESIZED;
                    pevent.data.wnd_resized.new_size.w =
                        sevent.window.data1;
                    pevent.data.wnd_resized.new_size.h =
                        sevent.window.data2;
                    break;
                case SDL_WINDOWEVENT_CLOSE:
                    pevent.type = PJMEDIA_EVENT_WND_CLOSING;
                    break;
                }
            }break;
            default:
                break;
        }
        if (strm && pevent.type != PJMEDIA_EVENT_NONE) {
            pj_status_t status;

            // handle_event_button_play    (strm, sevent);
            // handle_event_button_close   (strm, sevent);

            pjmedia_event_publish(NULL, strm, &pevent, (pjmedia_event_publish_flag)0);

            switch (pevent.type) {
                case PJMEDIA_EVENT_WND_RESIZED:{
                    status = resize_disp(strm, &pevent.data.wnd_resized.new_size);
                    if (status != PJ_SUCCESS)
                        PJ_LOG(3, (THIS_FILE, "Failed resizing the display."));
                }
                    break;
                case PJMEDIA_EVENT_WND_CLOSING:{
                    if (pevent.data.wnd_closing.cancel) {
                        break;
                    }

                    /* Proceed to cleanup SDL. App must still call
                     * pjmedia_dev_stream_destroy() when getting WND_CLOSED
                     * event
                     */
                    sdl_stream_stop(&strm->base);
                    sdl_destroy_all(strm);
                    pjmedia_event_init(&pevent, PJMEDIA_EVENT_WND_CLOSED,
                                       &strm->sp.last_ts, strm);
                    pjmedia_event_publish(NULL, strm, &pevent, (pjmedia_event_publish_flag)0);

                    /*
                     * Note: don't access the stream after this point, it
                     * might have been destroyed
                     */
                }
                    break;
                default:
                break;
            }
        }

        pj_mutex_unlock(sf->mutex);

    }
    return PJ_SUCCESS;
}

//////////////////////////
/// handle_event end
//////////////////////////
static int sdl_ev_thread(void *data){
    struct sdl_factory *sf = (struct sdl_factory*)data;

    while(1) {
        pj_status_t status;

        pj_mutex_lock(sf->mutex);
        if (pj_list_empty(&sf->streams)) {
            pj_mutex_unlock(sf->mutex);
            /* Wait until there is any stream. */
            pj_sem_wait(sf->sem);
        } else
            pj_mutex_unlock(sf->mutex);

        if (sf->is_quitting)
            break;

        job_queue_post_job(sf->jq, handle_event, sf, 0, &status);

        pj_thread_sleep(50);
    }

    return 0;
}
static pj_status_t sdl_quit(void *data){
    PJ_UNUSED_ARG(data);
    SDL_Quit();
    return PJ_SUCCESS;
}
/* API: init factory */
static pj_status_t sdl_factory_init(pjmedia_vid_dev_factory *f){
    struct sdl_factory *sf = (struct sdl_factory*)f;
    struct sdl_dev_info *ddi;
    unsigned i, j;
    pj_status_t status;
    SDL_version version;

    pj_list_init(&sf->streams);

    status = job_queue_create(sf->pool, &sf->jq);
    if (status != PJ_SUCCESS)
        return PJMEDIA_EVID_INIT;

    job_queue_post_job(sf->jq, sdl_init, NULL, 0, &status);
    if (status != PJ_SUCCESS)
        return status;

    status = pj_mutex_create_recursive(sf->pool, "sdl_factory",
                       &sf->mutex);
    if (status != PJ_SUCCESS)
    return status;

    status = pj_sem_create(sf->pool, NULL, 0, 1, &sf->sem);
    if (status != PJ_SUCCESS)
    return status;

    /* Create event handler thread. */
    status = pj_thread_create(sf->pool, "sdl_thread", sdl_ev_thread,
                  sf, 0, 0, &sf->sdl_thread);
    if (status != PJ_SUCCESS)
        return status;

    sf->dev_count = 1;
#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    sf->dev_count++;
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */
    sf->dev_info = (struct sdl_dev_info*)
           pj_pool_calloc(sf->pool, sf->dev_count,
                  sizeof(struct sdl_dev_info));

    ddi = &sf->dev_info[0];
    pj_bzero(ddi, sizeof(*ddi));
    strncpy(ddi->info.name, "SDL renderer", sizeof(ddi->info.name));
    ddi->info.name[sizeof(ddi->info.name)-1] = '\0';
    ddi->info.fmt_cnt = PJ_ARRAY_SIZE(sdl_fmts);

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    ddi = &sf->dev_info[OPENGL_DEV_IDX];
    pj_bzero(ddi, sizeof(*ddi));
    strncpy(ddi->info.name, "SDL openGL renderer", sizeof(ddi->info.name));
    ddi->info.name[sizeof(ddi->info.name)-1] = '\0';
    ddi->info.fmt_cnt = 1;
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */

    for (i = 0; i < sf->dev_count; i++) {
        ddi = &sf->dev_info[i];
        strncpy(ddi->info.driver, "SDL", sizeof(ddi->info.driver));
        ddi->info.driver[sizeof(ddi->info.driver)-1] = '\0';
        ddi->info.dir = PJMEDIA_DIR_RENDER;
        ddi->info.has_callback = PJ_FALSE;
        ddi->info.caps = PJMEDIA_VID_DEV_CAP_FORMAT |
                         PJMEDIA_VID_DEV_CAP_OUTPUT_RESIZE;
        ddi->info.caps |= PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW;
        ddi->info.caps |= PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW_FLAGS;

        for (j = 0; j < ddi->info.fmt_cnt; j++) {
            pjmedia_format *fmt = &ddi->info.fmt[j];
            pjmedia_format_init_video(fmt, sdl_fmts[j].fmt_id,
                                      DEFAULT_WIDTH, DEFAULT_HEIGHT,
                                      DEFAULT_FPS, 1);
        }
    }

    SDL_VERSION(&version);
    PJ_LOG(4, (THIS_FILE, "SDL %d.%d initialized",
              version.major, version.minor));

    return PJ_SUCCESS;
}
/* API: destroy factory */
static pj_status_t sdl_factory_destroy(pjmedia_vid_dev_factory *f){
    struct sdl_factory *sf = (struct sdl_factory*)f;
    pj_pool_t *pool = sf->pool;
    pj_status_t status;

    pj_assert(pj_list_empty(&sf->streams));

    sf->is_quitting = PJ_TRUE;
    if (sf->sdl_thread) {
        pj_sem_post(sf->sem);
#if defined(PJ_DARWINOS) && PJ_DARWINOS!=0
        /* To prevent pj_thread_join() of getting stuck if we are in
         * the main thread and we haven't finished processing the job
         * posted by sdl_thread.
         */
        CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0, false);
#endif
        pj_thread_join(sf->sdl_thread);
        pj_thread_destroy(sf->sdl_thread);
    }

    if (sf->mutex) {
        pj_mutex_destroy(sf->mutex);
        sf->mutex = NULL;
    }

    if (sf->sem) {
        pj_sem_destroy(sf->sem);
        sf->sem = NULL;
    }

    job_queue_post_job(sf->jq, sdl_quit, NULL, 0, &status);
    job_queue_destroy(sf->jq);

    sf->pool = NULL;
    pj_pool_release(pool);

    return PJ_SUCCESS;
}
/* API: refresh the list of devices */
static pj_status_t sdl_factory_refresh(pjmedia_vid_dev_factory *f){
    PJ_UNUSED_ARG(f);
    return PJ_SUCCESS;
}
/* API: get number of devices */
static unsigned sdl_factory_get_dev_count(pjmedia_vid_dev_factory *f){
    struct sdl_factory *sf = (struct sdl_factory*)f;
    return sf->dev_count;
}
/* API: get device info */
static pj_status_t sdl_factory_get_dev_info(pjmedia_vid_dev_factory *f, unsigned index, pjmedia_vid_dev_info *info){
    struct sdl_factory *sf = (struct sdl_factory*)f;

    PJ_ASSERT_RETURN(index < sf->dev_count, PJMEDIA_EVID_INVDEV);

    pj_memcpy(info, &sf->dev_info[index].info, sizeof(*info));

    return PJ_SUCCESS;
}
/* API: create default device parameter */
static pj_status_t sdl_factory_default_param(pj_pool_t *pool, pjmedia_vid_dev_factory *f, unsigned index, pjmedia_vid_dev_param *param){
    struct sdl_factory *sf = (struct sdl_factory*)f;
    struct sdl_dev_info *di = &sf->dev_info[index];

    PJ_ASSERT_RETURN(index < sf->dev_count, PJMEDIA_EVID_INVDEV);
    
    PJ_UNUSED_ARG(pool);

    pj_bzero(param, sizeof(*param));
    param->dir = PJMEDIA_DIR_RENDER;
    param->rend_id = index;
    param->cap_id = PJMEDIA_VID_INVALID_DEV;

    /* Set the device capabilities here */
    param->flags = PJMEDIA_VID_DEV_CAP_FORMAT;
    param->fmt.type = PJMEDIA_TYPE_VIDEO;
    param->clock_rate = DEFAULT_CLOCK_RATE;
    pj_memcpy(&param->fmt, &di->info.fmt[0], sizeof(param->fmt));

    return PJ_SUCCESS;
}
static sdl_fmt_info* get_sdl_format_info(pjmedia_format_id id){
    unsigned i;

    for (i = 0; i < sizeof(sdl_fmts)/sizeof(sdl_fmts[0]); i++) {
        if (sdl_fmts[i].fmt_id == id)
            return &sdl_fmts[i];
    }

    return NULL;
}
static pj_status_t sdl_destroy(void *data){
    struct sdl_stream *strm = (struct sdl_stream *)data;
     
#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    if (strm->texture) {
    glDeleteTextures(1, &strm->texture);
    strm->texture = 0;
    }
    if (strm->gl_context) {
        SDL_GL_DeleteContext(strm->gl_context);
        strm->gl_context = NULL;
    }
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */

    if (strm->sp.textureP) {
        SDL_DestroyTexture(strm->sp.textureP);
        strm->sp.textureP = NULL;
    }
    if (strm->sp.textureS) {
        SDL_DestroyTexture(strm->sp.textureS);
        strm->sp.textureS = NULL;
    }

    if (strm->sp.renderer) {
        SDL_DestroyRenderer(strm->sp.renderer);
        strm->sp.renderer = NULL;
    }
    return PJ_SUCCESS;
}

// 销毁函数, 这函数会销毁 strm 并销毁 window
static pj_status_t sdl_destroy_all(void *data){
    struct sdl_stream *strm = (struct sdl_stream *)data;  
    sdl_destroy(data);
#if !defined(TARGET_OS_IPHONE) || TARGET_OS_IPHONE == 0
    if (strm->sp.window && !(strm->param.flags & PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW)){
        SDL_DestroyWindow(strm->sp.window);
    }
    strm->sp.window   = NULL;
    // AAC
    //strm->pToolBar = NULL;
#endif /* TARGET_OS_IPHONE */
    return PJ_SUCCESS;
}

// setRect
void setBtnMouseoverRect_play		(struct sdl_stream *strm, int x, int y, int w, int h, euBtnStste is_checked) {
    strm->sp.toolbar.mPlay.btnRect.mouseover[is_checked].x=x;
    strm->sp.toolbar.mPlay.btnRect.mouseover[is_checked].y=y;
    strm->sp.toolbar.mPlay.btnRect.mouseover[is_checked].w=w;
    strm->sp.toolbar.mPlay.btnRect.mouseover[is_checked].h=h;
}
void setBtnMouseoutRect_play		(struct sdl_stream *strm, int x, int y, int w, int h, euBtnStste is_checked) {
    strm->sp.toolbar.mPlay.btnRect.mouseout[is_checked].x=x;
    strm->sp.toolbar.mPlay.btnRect.mouseout[is_checked].y=y;
    strm->sp.toolbar.mPlay.btnRect.mouseout[is_checked].w=w;
    strm->sp.toolbar.mPlay.btnRect.mouseout[is_checked].h=h;
}
void setBtnMousedownRect_play		(struct sdl_stream *strm, int x, int y, int w, int h, euBtnStste is_checked) {
    strm->sp.toolbar.mPlay.btnRect.mousedown[is_checked].x=x;
    strm->sp.toolbar.mPlay.btnRect.mousedown[is_checked].y=y;
    strm->sp.toolbar.mPlay.btnRect.mousedown[is_checked].w=w;
    strm->sp.toolbar.mPlay.btnRect.mousedown[is_checked].h=h;
}
void setBtnMouseupRect_play			(struct sdl_stream *strm, int x, int y, int w, int h, euBtnStste is_checked) {
    strm->sp.toolbar.mPlay.btnRect.mouseup[is_checked].x=x;
    strm->sp.toolbar.mPlay.btnRect.mouseup[is_checked].y=y;
    strm->sp.toolbar.mPlay.btnRect.mouseup[is_checked].w=w;
    strm->sp.toolbar.mPlay.btnRect.mouseup[is_checked].h=h;
}
void setBtnMouseoverRect_close		(struct sdl_stream *strm, int x, int y, int w, int h, euBtnStste is_checked) {
    strm->sp.toolbar.mClose.btnRect.mouseover[is_checked].x=x;
    strm->sp.toolbar.mClose.btnRect.mouseover[is_checked].y=y;
    strm->sp.toolbar.mClose.btnRect.mouseover[is_checked].w=w;
    strm->sp.toolbar.mClose.btnRect.mouseover[is_checked].h=h;
}
void setBtnMouseoutRect_close		(struct sdl_stream *strm, int x, int y, int w, int h, euBtnStste is_checked) {
    strm->sp.toolbar.mClose.btnRect.mouseout[is_checked].x=x;
    strm->sp.toolbar.mClose.btnRect.mouseout[is_checked].y=y;
    strm->sp.toolbar.mClose.btnRect.mouseout[is_checked].w=w;
    strm->sp.toolbar.mClose.btnRect.mouseout[is_checked].h=h;
}
void setBtnMousedownRect_close		(struct sdl_stream *strm, int x, int y, int w, int h, euBtnStste is_checked) {
    strm->sp.toolbar.mClose.btnRect.mousedown[is_checked].x=x;
    strm->sp.toolbar.mClose.btnRect.mousedown[is_checked].y=y;
    strm->sp.toolbar.mClose.btnRect.mousedown[is_checked].w=w;
    strm->sp.toolbar.mClose.btnRect.mousedown[is_checked].h=h;
}
void setBtnMouseupRect_close		(struct sdl_stream *strm, int x, int y, int w, int h, euBtnStste is_checked) {
    strm->sp.toolbar.mClose.btnRect.mouseup[is_checked].x=x;
    strm->sp.toolbar.mClose.btnRect.mouseup[is_checked].y=y;
    strm->sp.toolbar.mClose.btnRect.mouseup[is_checked].w=w;
    strm->sp.toolbar.mClose.btnRect.mouseup[is_checked].h=h;
}

// ABChernic : 2018-01-30
static void fillTexture				(SDL_Renderer *renderer, SDL_Texture *texture, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, NULL);
}
static void prepareForRendering		(SDL_Renderer *renderer){
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
}

// sdl_log_err("SDL_CreateWindow()"); 

/// A3
static pj_status_t sdl_create_window(struct sdl_stream *strm, pj_bool_t use_app_win, Uint32 sdl_format, pjmedia_vid_dev_hwnd *hwnd){

    // ABChernic : 创建纹理四维
    setBtnMouseoverRect_play    (strm,  131,  123,  80,  80 ,BTUUON_CHECKED);
    setBtnMouseoutRect_play     (strm,  131,  123,  80,  80 ,BTUUON_CHECKED);
    setBtnMouseupRect_play      (strm,  131,  123,  80,  80 ,BTUUON_CHECKED);
    setBtnMousedownRect_play    (strm,  129,  121,  80,  80 ,BTUUON_CHECKED);
    setBtnMouseoverRect_play    (strm,  581,  27 ,  80,  80 ,BTUUON_UNCHECKED);
    setBtnMouseoutRect_play     (strm,  581,  27 ,  80,  80 ,BTUUON_UNCHECKED);
    setBtnMouseupRect_play      (strm,  581,  27 ,  80,  80 ,BTUUON_UNCHECKED);
    setBtnMousedownRect_play    (strm,  579,  25 ,  80,  80 ,BTUUON_UNCHECKED);

    setBtnMouseoverRect_close   (strm, 131,  27,   80,  80 ,BTUUON_CHECKED);
    setBtnMouseoutRect_close    (strm, 131,  27,   80,  80 ,BTUUON_CHECKED);
    setBtnMouseupRect_close     (strm, 131,  27,   80,  80 ,BTUUON_CHECKED);
    setBtnMousedownRect_close   (strm, 129,  25,   80,  80 ,BTUUON_CHECKED);
    setBtnMouseoverRect_close   (strm, 131,  27,   80,  80 ,BTUUON_UNCHECKED);
    setBtnMouseoutRect_close    (strm, 131,  27,   80,  80 ,BTUUON_UNCHECKED);
    setBtnMouseupRect_close     (strm, 131,  27,   80,  80 ,BTUUON_UNCHECKED);
    setBtnMousedownRect_close   (strm, 129,  25,   80,  80 ,BTUUON_UNCHECKED);
    
    if (!strm->sp.window) {
        Uint32 flags = 0;

        if (strm->param.flags & PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW_FLAGS) {
            if (!(strm->param.window_flags & PJMEDIA_VID_DEV_WND_BORDER))
                flags |= SDL_WINDOW_BORDERLESS;
            if (strm->param.window_flags & PJMEDIA_VID_DEV_WND_RESIZABLE)
                flags |= SDL_WINDOW_RESIZABLE;

            if (strm->param.window_flags & PJMEDIA_VID_DEV_WND_INPUT_GRABBED)
                flags |= SDL_WINDOW_INPUT_GRABBED;

            if (strm->param.window_flags & PJMEDIA_VID_DEV_WND_ALWAYS_ON_TOPD)
                flags |= SDL_WINDOW_ALWAYS_ON_TOP;
            if (strm->param.window_flags & PJMEDIA_VID_DEV_WND_ALLOW_HIGHDPI)
                flags |= SDL_WINDOW_ALLOW_HIGHDPI;
            if (strm->param.window_flags & PJMEDIA_VID_DEV_WND_UTILITY)
                flags |= SDL_WINDOW_UTILITY;
            if (strm->param.window_flags & PJMEDIA_VID_DEV_WND_SKIP_TASKBAR)
                flags |= SDL_WINDOW_SKIP_TASKBAR;

            if (strm->param.window_flags & PJMEDIA_VID_DEV_WND_INPUT_FOCUS)
                flags |= SDL_WINDOW_INPUT_FOCUS;
            if (strm->param.window_flags & PJMEDIA_VID_DEV_WND_MOUSE_FOCUS)
                flags |= SDL_WINDOW_MOUSE_FOCUS;
        } else {
            flags |= SDL_WINDOW_BORDERLESS;
        }

        if (!((strm->param.flags & PJMEDIA_VID_DEV_CAP_OUTPUT_HIDE) && strm->param.window_hide)){
            flags |= SDL_WINDOW_SHOWN;
        } else {
            flags &= ~SDL_WINDOW_SHOWN;
            flags |= SDL_WINDOW_HIDDEN;
        }

        // ABChernic
        //flags |= SDL_WINDOW_FULLSCREEN;
        //flags |= SDL_WINDOW_BORDERLESS;

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
        if (strm->param.rend_id == OPENGL_DEV_IDX)
            flags |= SDL_WINDOW_OPENGL;
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */   
        if (use_app_win) {
            /* Use the window supplied by the application. */       
            strm->sp.window = SDL_CreateWindowFrom(hwnd->info.window);

            if (!strm->sp.window) {
                sdl_log_err("SDL_CreateWindowFrom()");
                return PJMEDIA_EVID_SYSERR;
            }
        } else {
            int x, y;

            x = y = SDL_WINDOWPOS_CENTERED;
            if (strm->param.flags & PJMEDIA_VID_DEV_CAP_OUTPUT_POSITION) {
                x = strm->param.window_pos.x;
                y = strm->param.window_pos.y;
            }

            /* Create the window where we will draw. */
            // X1
            strm->sp.window  = SDL_CreateWindow(
                "pjmedia-SDL video", x, y,
                strm->param.disp_size.w,
                strm->param.disp_size.h,
                flags
                );
            if (!strm->sp.window) {
                sdl_log_err("SDL_CreateWindow()");
                return PJMEDIA_EVID_SYSERR;
            }
        }
    }

    // We must call SDL_CreateRenderer in order for draw calls to// affect this window.
    strm->sp.renderer = SDL_CreateRenderer(strm->sp.window, -1, 0);
    if (!strm->sp.renderer) {
        sdl_log_err("SDL_CreateRenderer()");
        return PJMEDIA_EVID_SYSERR;
    }

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    if (strm->param.rend_id == OPENGL_DEV_IDX) {
        strm->gl_context = SDL_GL_CreateContext(strm->sp.window);
        if (!strm->gl_context) {
            sdl_log_err("SDL_GL_CreateContext()");
            return PJMEDIA_EVID_SYSERR;
        }
        SDL_GL_MakeCurrent(strm->sp.window, strm->gl_context);

        /* Init some OpenGL settings */
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    
    /* Init the viewport */
    glViewport(0, 0, strm->param.disp_size.w, strm->param.disp_size.h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(0.0, (GLdouble)strm->param.disp_size.w,
                (GLdouble)strm->param.disp_size.h, 0.0, 0.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    /* Create a texture */
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glGenTextures(1, &strm->texture);

        if (!strm->texture)
            return PJMEDIA_EVID_SYSERR;
    } else

#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */
    // {
    // ABChernic : Save sdl_formatP
    strm->sp.sdl_formatP = sdl_format;
    strm->sp.sdl_formatS = SDL_PIXELFORMAT_IYUV;

    /// ABChernic : 选择默认纹理四维
    strm->sp.thread_exit               = 0;
    strm->sp.thread_pause              = 0;
    strm->sp.toolbar.isToolBarShowed   = 0;
    strm->sp.toolbar.mPlay.isChecked   = BTUUON_UNCHECKED;
    strm->sp.toolbar.mClose.isChecked  = BTUUON_UNCHECKED;
    strm->sp.toolbar.mPlay.pSrcR       = &strm->sp.toolbar.mPlay.btnRect.mouseover[BTUUON_UNCHECKED];
    strm->sp.toolbar.mClose.pSrcR      = &strm->sp.toolbar.mClose.btnRect.mouseover[BTUUON_UNCHECKED];

    /// ABChernic : 设置按钮四维
    sdl_toolbar_make_play (strm, strm->param.disp_size.w, strm->param.disp_size.h, 80, 80);
    sdl_toolbar_make_close(strm, strm->param.disp_size.w, strm->param.disp_size.h, 80, 80);
    sdl_toolbar_make      (strm, strm->param.disp_size.w, strm->param.disp_size.h, 80, 80);
    // }
    return PJ_SUCCESS;
}

static pj_status_t sdl_create_rend	(struct sdl_stream * strm, pjmedia_format *fmt){
    sdl_fmt_info *sdl_info;
    const pjmedia_video_format_info *vfi;
    pjmedia_video_format_detail *vfd;

    sdl_info = get_sdl_format_info((pjmedia_format_id)(fmt->id));
    vfi = pjmedia_get_video_format_info(pjmedia_video_format_mgr_instance(), fmt->id);
    if (!vfi || !sdl_info){
        return PJMEDIA_EVID_BADFORMAT;
    }

    strm->sp.vafp.size = fmt->det.vid.size;
    strm->sp.vafp.buffer = NULL;
    if (vfi->apply_fmt(vfi, &strm->sp.vafp) != PJ_SUCCESS){
        return PJMEDIA_EVID_BADFORMAT;
    }

    vfd = pjmedia_format_get_video_format_detail(fmt, PJ_TRUE);

    // ABChernic : ->rectP  ->rectS
    strm->sp.rectP.x = 0;
    strm->sp.rectP.y = 0;
    strm->sp.rectP.w = (Uint16)vfd->size.w;
    strm->sp.rectP.h = (Uint16)vfd->size.h;
    
    strm->sp.rectS.x = 0;
    strm->sp.rectS.y = 0;
    strm->sp.rectS.w = (Uint16)vfd->size.w;
    strm->sp.rectS.h = (Uint16)vfd->size.h;

    if (strm->param.disp_size.w == 0)
        strm->param.disp_size.w = (Uint16)vfd->size.w;
    if (strm->param.disp_size.h == 0)
        strm->param.disp_size.h = (Uint16)vfd->size.h;

    // ABChernic : ->dstrect1
    //strm->sp.dstrect.x = 0;
    //strm->sp.dstrect.y = 0;
    //strm->sp.dstrect.w = (Uint16)(strm->param.disp_size.w);
    //strm->sp.dstrect.h = (Uint16)(strm->param.disp_size.h);
    //
    //strm->sp.dstrectS.x = 0;
    //strm->sp.dstrectS.y = 0;
    //strm->sp.dstrectS.w = (Uint16)(strm->param.disp_size.w);
    //strm->sp.dstrectS.h = (Uint16)(strm->param.disp_size.h);

    sdl_destroy(strm);

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    if (strm->param.rend_id == OPENGL_DEV_IDX) {
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    }
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */
    
    /// ABChernic : X2
    return   sdl_create_window(///_sdl_create_rend()
        strm, 
        (strm->param.flags & PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW), 
        sdl_info->sdl_format, 
        &strm->param.window);
}
static pj_status_t sdl_create		(void *data){
    struct sdl_stream *strm = (struct sdl_stream *)data;
    return sdl_create_rend(strm, &strm->param.fmt);
}

/// 设置Preview的显示区域
static pj_status_t repose_previw	(struct sdl_stream *strm, pjmedia_coord *pos){
    strm->sp.dstrectP.x = pos->x;
    strm->sp.dstrectP.y = pos->y;
    return PJ_SUCCESS;
}
static pj_status_t resize_previw	(struct sdl_stream *strm, pjmedia_rect_size *size){
    strm->sp.dstrectP.w = size->w;
    strm->sp.dstrectP.h = size->h;
    return PJ_SUCCESS;
}
/// 设置Stream的显示区域
static pj_status_t repose_stream	(struct sdl_stream *strm, pjmedia_coord *pos){
    (strm);
    (pos);
    strm->sp.dstrectS.x = pos->x;
    strm->sp.dstrectS.y = pos->y;
    return PJ_SUCCESS;
}
static pj_status_t resize_stream	(struct sdl_stream *strm, pjmedia_rect_size *size){
    (strm);
    (size);
    strm->sp.dstrectS.w = size->w;
    strm->sp.dstrectS.h = size->h;
    return PJ_SUCCESS;
}
// 设置其他
static pj_status_t resize_disp		(struct sdl_stream *strm, pjmedia_rect_size *new_disp_size){
    pj_memcpy(&strm->param.disp_size, new_disp_size, sizeof(strm->param.disp_size));
    // 调用 PJMEDIA_VID_DEV_CAP_OUTPUT_RESIZE 会修改值strm->param.disp_size

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    else if (strm->param.rend_id == OPENGL_DEV_IDX) {
    sdl_create_rend(strm, &strm->param.fmt);
    }
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */
    return PJ_SUCCESS;
}
static pj_status_t change_format	(struct sdl_stream *strm, pjmedia_format *new_fmt){
    pj_status_t status;

    /* Recreate SDL renderer */
    status = sdl_create_rend(strm, (new_fmt? new_fmt : &strm->param.fmt));
    if (status == PJ_SUCCESS && new_fmt){
        pjmedia_format_copy(&strm->param.fmt, new_fmt);
    }
    return status;
}


/// ABChernic : 2018-01-04 >>> 前提函数 结构体 
struct strm_cap {
    struct sdl_stream   *strm;
    pjmedia_vid_dev_cap  cap;
    union {
        void            *pval;
        const void      *cpval;
    } pval;
};
struct strm_dir {
    struct sdl_stream   *strm;
    pj_str_t            dir;
};
struct strm_win {
    struct sdl_stream   *strm;
    union {
        void            *pval;
        const void      *cpval;
    } pval;
};
static pj_status_t get_sdl_window   (void *data){
    struct strm_win *swin = (struct strm_win *)data;
    struct sdl_stream *strm = swin->strm;
    void *pval = swin->pval.pval;

    pval = (void*)strm->sp.window;

    return PJ_SUCCESS;
}
static pj_status_t get_cap          (void *data){
    struct strm_cap *scap = (struct strm_cap *)data;
    struct sdl_stream *strm = scap->strm;
    pjmedia_vid_dev_cap cap = scap->cap;
    void *pval = scap->pval.pval;

    if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW)
    {
    SDL_SysWMinfo info;
    SDL_VERSION(&info.version); 

    if (SDL_GetWindowWMInfo(strm->sp.window, &info)) {
        pjmedia_vid_dev_hwnd *wnd = (pjmedia_vid_dev_hwnd *)pval;
        if (0) { }
#if defined(SDL_VIDEO_DRIVER_WINDOWS)
        else if (info.subsystem == SDL_SYSWM_WINDOWS) {
        wnd->type = PJMEDIA_VID_DEV_HWND_TYPE_WINDOWS;
        wnd->info.win.hwnd = (void *)info.info.win.window;
        }
#endif
#if defined(SDL_VIDEO_DRIVER_X11)
        else if (info.subsystem == SDL_SYSWM_X11) {
        wnd->info.x11.window = (void *)info.info.x11.window;
        wnd->info.x11.display = (void *)info.info.x11.display;
        }
#endif
#if defined(SDL_VIDEO_DRIVER_COCOA)
        else if (info.subsystem == SDL_SYSWM_COCOA) {
        wnd->info.cocoa.window = (void *)info.info.cocoa.window;
        }
#endif
#if defined(SDL_VIDEO_DRIVER_UIKIT)
        else if (info.subsystem == SDL_SYSWM_UIKIT) {
        wnd->info.ios.window = (void *)info.info.uikit.window;
        }
#endif
        else {
        return PJMEDIA_EVID_INVCAP;
        }
        return PJ_SUCCESS;
    } else
        return PJMEDIA_EVID_INVCAP;
    } else if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_POSITION) {
        SDL_GetWindowPosition(strm->sp.window, &((pjmedia_coord *)pval)->x,
                              &((pjmedia_coord *)pval)->y);
    return PJ_SUCCESS;
    } else if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_RESIZE) {
        SDL_GetWindowSize(strm->sp.window, (int *)&((pjmedia_rect_size *)pval)->w,
                          (int *)&((pjmedia_rect_size *)pval)->h);
    return PJ_SUCCESS;
    } else if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_HIDE) {
    Uint32 flag = SDL_GetWindowFlags(strm->sp.window);
    *((pj_bool_t *)pval) = (flag & SDL_WINDOW_HIDDEN)? PJ_TRUE: PJ_FALSE;
    return PJ_SUCCESS;
    } else if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW_FLAGS) {
    Uint32 flag = SDL_GetWindowFlags(strm->sp.window);
        unsigned *wnd_flags = (unsigned *)pval;
        if (!(flag & SDL_WINDOW_BORDERLESS))
            *wnd_flags |= PJMEDIA_VID_DEV_WND_BORDER;
        if (flag & SDL_WINDOW_RESIZABLE)
            *wnd_flags |= PJMEDIA_VID_DEV_WND_RESIZABLE;
    return PJ_SUCCESS;
    }

    return PJMEDIA_EVID_INVCAP;
}
static pj_status_t set_cap          (void *data){
    struct strm_cap *scap = (struct strm_cap *)data;
    struct sdl_stream *strm = scap->strm;
    pjmedia_vid_dev_cap cap = scap->cap;
    const void *pval = scap->pval.cpval;

    // 假如是设置左上顶角
    // pjsua_vid_win_set_pos->pjmedia_vid_dev_stream_set_cap->set_cap(PJMEDIA_VID_DEV_CAP_OUTPUT_POSITION)
    if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_POSITION) {
        /**
         * Setting window's position when the window is hidden also sets
         * the window's flag to shown (while the window is, actually,
         * still hidden). This causes problems later when setting/querying
         * the window's visibility.
         * See ticket #1429 (http://trac.pjsip.org/repos/ticket/1429)
         */
        Uint32 flag = SDL_GetWindowFlags(strm->sp.window);
        if (flag & SDL_WINDOW_HIDDEN)
            SDL_ShowWindow(strm->sp.window);

        SDL_SetWindowPosition(strm->sp.window, ((pjmedia_coord *)pval)->x,((pjmedia_coord *)pval)->y);

        if (flag & SDL_WINDOW_HIDDEN)
            SDL_HideWindow(strm->sp.window);

        return PJ_SUCCESS;
    // 假如是设置边长
    } else if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_HIDE) {
        if (*(pj_bool_t *)pval)
            SDL_HideWindow(strm->sp.window);
        else
            SDL_ShowWindow(strm->sp.window);
        return PJ_SUCCESS;
    } else if (cap == PJMEDIA_VID_DEV_CAP_FORMAT) {
        pj_status_t status;

        status = change_format(strm, (pjmedia_format *)pval);
        if (status != PJ_SUCCESS) {
            pj_status_t status_;
            
            /**
             * Failed to change the output format. Try to revert
             * to its original format.
             */
                status_ = change_format(strm, &strm->param.fmt);
            if (status_ != PJ_SUCCESS) {
            /**
             * This means that we failed to revert to our
             * original state!
             */
            status = PJMEDIA_EVID_ERR;
            }
        }
        return status;
    // pjsua_vid_win_set_pos->pjmedia_vid_dev_stream_set_cap->set_cap(PJMEDIA_VID_DEV_CAP_OUTPUT_RESIZE)
    } else if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_RESIZE) {
        pjmedia_rect_size *new_size = (pjmedia_rect_size *)pval;
        SDL_SetWindowSize(strm->sp.window, new_size->w, new_size->h);
        return resize_disp(strm, new_size);
    } else if (cap == PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW) {
        pjmedia_vid_dev_hwnd *hwnd = (pjmedia_vid_dev_hwnd*)pval;
        pj_status_t status = PJ_SUCCESS;
        sdl_fmt_info *sdl_info = get_sdl_format_info((pjmedia_format_id)(strm->param.fmt.id));
        /* Re-init SDL */
        status = sdl_destroy_all(strm);
        if (status != PJ_SUCCESS)
            return status;  

    // ABChernic :
    status = sdl_create_window(/// set_cap
        strm, 
        PJ_TRUE, 
        sdl_info->sdl_format, 
        hwnd);

            PJ_LOG(4, (THIS_FILE, "Re-initializing SDL with native window"
                          " %d: %s", hwnd->info.window,
                                  (status == PJ_SUCCESS? "success": "failed")));
        return status;
    // ABChernic : previw
    } else if (cap == PJMEDIA_VID_DEV_CAP_PREVIW_POS) {
        pjmedia_coord *tmp_pos = (pjmedia_coord *)pval;
        strm->param.previw_pos.x = tmp_pos->x;
        strm->param.previw_pos.y = tmp_pos->y;
        return repose_previw(strm, tmp_pos); 
    } else if (cap == PJMEDIA_VID_DEV_CAP_PREVIW_SIZE) {
        pjmedia_rect_size *tmp_size = (pjmedia_rect_size *)pval;
        strm->param.previw_size.w = tmp_size->w;
        strm->param.previw_size.h = tmp_size->h;
        return resize_previw(strm, tmp_size);
    // ABChernic : stream
    } else if (cap == PJMEDIA_VID_DEV_CAP_STREAM_POS) {
        pjmedia_coord *tmp_pos = (pjmedia_coord *)pval;
        strm->param.stream_pos.x = tmp_pos->x;
        strm->param.stream_pos.y = tmp_pos->y;
        return repose_stream(strm, tmp_pos);
    } else if (cap == PJMEDIA_VID_DEV_CAP_STREAM_SIZE) {
        pjmedia_rect_size *tmp_size = (pjmedia_rect_size *)pval;
        strm->param.stream_size.w = tmp_size->w;
        strm->param.stream_size.h = tmp_size->h;
        return resize_stream(strm, tmp_size);
    } else if (cap == PJMEDIA_VID_DEV_CAP_BUTTON_SIZE) {
        pj_status_t status = PJ_SUCCESS;
        pjmedia_rect_size *new_size = (pjmedia_rect_size *)pval;
        strm->sp.toolbar.size.w = new_size->w;
        strm->sp.toolbar.size.h = new_size->h;
        return status; 
    }
    return PJMEDIA_EVID_INVCAP;
}
static pj_status_t set_dir          (void *data){
    struct strm_dir     *sdir       = (struct strm_dir *)data;
    struct sdl_stream   *strm       = sdir->strm;
    pj_str_t            dir         = sdir->dir;
    pj_str_t            full_dir;
    pj_str_t            play_dir;
    pj_str_t            close_dir;
    char                strbuf[100];

    if (dir.slen == 0) {
        PJ_LOG(4, (THIS_FILE, "<running_dir> is null, may be we can't find the bmp of buttons."));
    }
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "BMP Dir is %s", &strbuf );

    strm->sp.running_dir=dir;
    pj_ansi_snprintf(strbuf, sizeof(strbuf),"%s\\button.bmp", strm->sp.running_dir.ptr );

    full_dir  = pj_str(strbuf);
    play_dir  = pj_str(full_dir.ptr);
    close_dir = pj_str(full_dir.ptr);

    sdl_toolbar_load_play (strm, play_dir.ptr );
    sdl_toolbar_load_close(strm, close_dir.ptr );

    return 0;
}
typedef struct sdl_mixstream{
    struct sdl_stream *strmP;
    struct sdl_stream *strmS;
}sdl_mixstream;

static pj_status_t put_frame_prwviw (void *data){
    struct sdl_stream   *strm      = (struct sdl_stream *)data;
    struct sdl_stream   *pre_strm;
    const pjmedia_frame *frame     = strm->sp.frame;
    const pjmedia_frame *pre_frame = strm->sp.frame;
    int isRead = 0;

    SDL_Renderer* renderer = strm->sp.renderer;

    Uint32     sdl_formatP = strm->sp.sdl_formatP;
    int           sizePw   = strm->sp.rectP.w;  // strm->param.previw_size.w;
    int           sizePh   = strm->sp.rectP.h;  // strm->param.previw_size.h;

    Uint32     sdl_formatS = strm->sp.sdl_formatS;
    int           sizeSw   = strm->sp.rectS.w;  // strm->param.stream_size.w;
    int           sizeSh   = strm->sp.rectS.h;  // strm->param.stream_size.h;

    int WindowX = strm->sp.rectP.w;
    int WindowY = 0;
    int WindowW = strm->param.disp_size.w;
    int WindowH = strm->param.disp_size.h;

    pre_strm  = strm->sp.list_entry.prev->stream;
    if(pre_strm && pre_strm->sp.is_running){
        pre_frame = pre_strm->sp.frame;
        if(pre_frame){
            if (pre_frame->size==0 || pre_frame->buf==NULL || pre_frame->size < pre_strm->sp.vafp.framebytes){
                isRead = 0;
            }
            else{
                isRead = 1;
            }
        }else
        {
            isRead = 0;
        }
    }else{
        isRead = 0;
    }

    sdl_formatP     = strm->sp.sdl_formatP;
    sizePw          = strm->sp.rectP.w;  // strm->param.previw_size.w;
    sizePh          = strm->sp.rectP.h;  // strm->param.previw_size.h;
    strm->sp.pitch  = sizePw * SDL_BYTESPERPIXEL(sdl_formatP);

    if (strm->sp.textureP == NULL && sizePw!=0 && sizePh!=0) {
		// 只能创建一次!!!
        strm->sp.textureP = SDL_CreateTexture(renderer, sdl_formatP, SDL_TEXTUREACCESS_STREAMING, sizePw, sizePh);
        if (strm->sp.textureP == NULL) {
            sdl_log_err("scr_texP::SDL_CreateTexture()");
            return PJMEDIA_EVID_SYSERR;
        }
    }

	/*
    sdl_formatS		= strm->sp.sdl_formatS;
    sizeSw			= strm->sp.rectS.w;  // strm->param.stream_size.w;
    sizeSh			= strm->sp.rectS.h;  // strm->param.stream_size.h;
    strm->sp.pitchS = sizeSw * SDL_BYTESPERPIXEL(sdl_formatS);

    if (strm->sp.textureS == NULL && sizeSw!=0 && sizeSh!=0) {
        strm->sp.textureS = SDL_CreateTexture(renderer, sdl_formatS, SDL_TEXTUREACCESS_STREAMING, sizeSw, sizeSh);
        if (strm->sp.textureS == NULL) {
            sdl_log_err("scr_texP::SDL_CreateTexture()");
            return PJMEDIA_EVID_SYSERR;
        }
    }
	*/


    if (strm->sp.textureP) {

		// 拷贝P
        SDL_UpdateTexture(strm->sp.textureP,  NULL, frame->buf, strm->sp.pitch);

		// 拷贝S (当 "isRead非0" 且 "pre_frame存在" 且 "buf不为空" )
        if(isRead && pre_frame && pre_frame->buf!=NULL){

			//if(pre_strm && pre_strm->sp.is_running){
				/// 计算S
				sdl_formatS	    = pre_strm->sp.sdl_formatP;
				sizeSw		    = pre_strm->sp.rectP.w;//红框		//strm->sp.rectS.w // 紫框
				sizeSh		    = pre_strm->sp.rectP.h;//红框		//strm->sp.rectS.h // 紫框
				strm->sp.pitchS = sizeSw * SDL_BYTESPERPIXEL(sdl_formatS);
			//}
            SDL_UpdateTexture(strm->sp.textureS,   NULL, pre_frame->buf, strm->sp.pitchS/* 192 */);
        }

        SDL_RenderClear  (strm->sp.renderer);


		/// 计算边框S大小 ==> 呈现S
		//strm->sp.dstrectS.x = 0;
		//strm->sp.dstrectS.y = 0;
		//strm->sp.dstrectS.w = strm->param.disp_size.w;
		//strm->sp.dstrectS.h = strm->param.disp_size.h;

		// 呈现S (当 "isRead非0" 且 "pre_frame存在" 且 "buf不为空" )
        if(isRead && pre_frame && pre_frame->buf!=NULL ){
			
			if (strm->sp.textureS == NULL && sizeSw!=0 && sizeSh!=0) {
				// 只能创建一次!!!
				strm->sp.textureS = SDL_CreateTexture(renderer, sdl_formatS, SDL_TEXTUREACCESS_STREAMING, sizeSw, sizeSh);
				if (strm->sp.textureS == NULL) {
					sdl_log_err("scr_texP::SDL_CreateTexture()");
					return PJMEDIA_EVID_SYSERR;
				}
			}
            SDL_RenderCopy  (strm->sp.renderer, strm->sp.textureS,  NULL, &strm->sp.dstrectS);
        }

		/// 计算边框P大小 ==> 呈现P
		//strm->sp.dstrectP.x = 0;
		//strm->sp.dstrectP.y = 0;
		//strm->sp.dstrectP.w = (strm->param.disp_size.w)/2;
		//strm->sp.dstrectP.h = (strm->param.disp_size.h)/2;

		/// 呈现P

        SDL_RenderCopy  (strm->sp.renderer, strm->sp.textureP,  NULL, &strm->sp.dstrectP);
		/*
			//sdl_toolbar_update(strm, WindowX, WindowY, WindowW, WindowH);       
			//if(strm->sp.toolbar.isToolBarShowed){
			//    sdl_toolbar_show      (strm); // update strm->sp.toolbar.mBlankRect
			//    sdl_toolbar_show_play (strm); // update strm->sp.toolbar.mClose.decR 
			//    sdl_toolbar_show_close(strm); // update strm->sp.toolbar.mClose.decR
			//}
		*/

        SDL_RenderPresent(strm->sp.renderer);
    }

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    else if (strm->param.rend_id == OPENGL_DEV_IDX && strm->texture) {
    glBindTexture(GL_TEXTURE_2D, strm->texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
             strm->rect.w, strm->rect.h, 0,
             GL_RGBA, GL_UNSIGNED_BYTE, frame->buf);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0, 0); glVertex2i(0, 0);
    glTexCoord2f(1, 0); glVertex2i(strm->param.disp_size.w, 0);
    glTexCoord2f(0, 1); glVertex2i(0, strm->param.disp_size.h);
    glTexCoord2f(1, 1);
        glVertex2i(strm->param.disp_size.w, strm->param.disp_size.h);
    glEnd();
        SDL_GL_SwapWindow(strm->sp.window);
    }
#endif 

    return PJ_SUCCESS;
}
// Windows_S
static pj_status_t put_frame_stream (void *data){
    struct sdl_stream   *strm   = (struct sdl_stream *)data;
    const pjmedia_frame *frame  = strm->sp.frame;
    SDL_Renderer * Renderer     = strm->sp.renderer;

    Uint32     sdl_formatP      = strm->sp.sdl_formatP;
    int           sizePw        = strm->sp.rectP.w;  // strm->param.previw_size.w;
    int           sizePh        = strm->sp.rectP.h;  // strm->param.previw_size.h;

	/*
    Uint32     sdl_formatS      = strm->sp.sdl_formatS;
    int           sizeSw        = strm->sp.rectS.w; // strm->param.stream_size.w;
    int           sizeSh        = strm->sp.rectS.h; // strm->param.stream_size.h;
	*/

    strm->sp.pitch  = sizePw * SDL_BYTESPERPIXEL(sdl_formatP);

    if (strm->sp.textureP == NULL && sizePw!=0 && sizePh!=0) {
        strm->sp.textureP = SDL_CreateTexture(Renderer, sdl_formatP, SDL_TEXTUREACCESS_STREAMING, sizePw, sizePh);
        if (strm->sp.textureP == NULL) {
            sdl_log_err("scr_texP::SDL_CreateTexture()");
            return PJMEDIA_EVID_SYSERR;
        }
    }

	/*
    //strm->sp.pitchS = sizeSw * SDL_BYTESPERPIXEL(sdl_formatS);
    //if (strm->sp.textureS == NULL && sizeSw!=0 && sizeSh!=0) {
    //  strm->sp.textureS = SDL_CreateTexture(Renderer, sdl_formatS, SDL_TEXTUREACCESS_STREAMING, sizeSw, sizeSh);
    //  if (strm->sp.textureS == NULL) {
    //      sdl_log_err("scr_texP::SDL_CreateTexture()");
    //      return PJMEDIA_EVID_SYSERR;
    //  }
    // }
	*/

    SDL_UpdateTexture(strm->sp.textureP, NULL, frame->buf, strm->sp.pitch );//192 
    if (strm->sp.textureP) {
        SDL_RenderClear  (Renderer);
        SDL_RenderCopy   (Renderer, strm->sp.textureP, NULL, NULL);
        //SDL_RenderCopy   (Ren derer, strm->sp.textureS, NULL, NULL);// 这里或变成全绿色
        SDL_RenderPresent(Renderer);
    }

#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    else if (strm->param.rend_id == OPENGL_DEV_IDX && strm->texture) {
    glBindTexture(GL_TEXTURE_2D, strm->texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
             strm->rect.w, strm->rect.h, 0,
             GL_RGBA, GL_UNSIGNED_BYTE, frame->buf);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0, 0); glVertex2i(0, 0);
    glTexCoord2f(1, 0); glVertex2i(strm->param.disp_size.w, 0);
    glTexCoord2f(0, 1); glVertex2i(0, strm->param.disp_size.h);
    glTexCoord2f(1, 1);
        glVertex2i(strm->param.disp_size.w, strm->param.disp_size.h);
    glEnd();
        SDL_GL_SwapWindow(strm->sp.window);
    }
#endif 

    return PJ_SUCCESS;
}
/// ABChernic : 2018-01-04 <<<


/// ABChernic : 2018-01-04 >>> 
/* API: Put frame from stream */    //############################################# O1 sdl_stream_get_param
static pj_status_t sdl_stream_get_param         (pjmedia_vid_dev_stream *s, pjmedia_vid_dev_param *pi){
    struct sdl_stream *strm = (struct sdl_stream*)s;

    PJ_ASSERT_RETURN(strm && pi, PJ_EINVAL);

    pj_memcpy(pi, &strm->param, sizeof(*pi));

    if (sdl_stream_get_cap(s, PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW,
               &pi->window) == PJ_SUCCESS)
    {
    pi->flags |= PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW;
    }
    if (sdl_stream_get_cap(s, PJMEDIA_VID_DEV_CAP_OUTPUT_POSITION,
               &pi->window_pos) == PJ_SUCCESS)
    {
    pi->flags |= PJMEDIA_VID_DEV_CAP_OUTPUT_POSITION;
    }
    if (sdl_stream_get_cap(s, PJMEDIA_VID_DEV_CAP_OUTPUT_RESIZE,
               &pi->disp_size) == PJ_SUCCESS)
    {
    pi->flags |= PJMEDIA_VID_DEV_CAP_OUTPUT_RESIZE;
    }
    if (sdl_stream_get_cap(s, PJMEDIA_VID_DEV_CAP_OUTPUT_HIDE,
               &pi->window_hide) == PJ_SUCCESS)
    {
    pi->flags |= PJMEDIA_VID_DEV_CAP_OUTPUT_HIDE;
    }
    if (sdl_stream_get_cap(s, PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW_FLAGS,
               &pi->window_flags) == PJ_SUCCESS)
    {
    pi->flags |= PJMEDIA_VID_DEV_CAP_OUTPUT_WINDOW_FLAGS;
    }

    return PJ_SUCCESS;
}

/* API: get_cap               */    //############################################# O2 sdl_stream_get_cap //get_cap
static pj_status_t sdl_stream_get_cap           (pjmedia_vid_dev_stream *s, pjmedia_vid_dev_cap cap, void *pval){
    struct sdl_stream *strm = (struct sdl_stream*)s;
    struct strm_cap scap;
    pj_status_t status;

    PJ_ASSERT_RETURN(s && pval, PJ_EINVAL);

    scap.strm = strm;
    scap.cap = cap;
    scap.pval.pval = pval;

    job_queue_post_job(strm->sp.sf->jq, get_cap, &scap, 0, &status);

    return status;
}

/* API: set_cap               */    //############################################# O3 sdl_stream_set_cap //set_cap
static pj_status_t sdl_stream_set_cap           (pjmedia_vid_dev_stream *s, pjmedia_vid_dev_cap cap, const void *pval){
    struct sdl_stream *strm = (struct sdl_stream*)s;
    struct strm_cap scap;
    pj_status_t status;

    PJ_ASSERT_RETURN(s && pval, PJ_EINVAL);

    scap.strm = strm;
    scap.cap = cap;
    scap.pval.cpval = pval;

    job_queue_post_job(strm->sp.sf->jq, set_cap, &scap, 0, &status);

    return status;
}


/* API: Start stream. */            //############################################# O4 sdl_stream_start
static pj_status_t sdl_stream_start             (pjmedia_vid_dev_stream *strm){
    struct sdl_stream *stream = (struct sdl_stream*)strm;

    PJ_LOG(4, (THIS_FILE, "Starting sdl video stream"));

    stream->sp.is_running = PJ_TRUE;

    return PJ_SUCCESS;
}
/* API: Put frame from stream */    //############################################# O6 sdl_stream_put_frame
static pj_status_t sdl_stream_put_frame         (pjmedia_vid_dev_stream *strm, const pjmedia_frame *frame){
    struct sdl_stream *stream = (struct sdl_stream*)strm;
    pj_status_t status = 0;
    //SDL_Thread *video_tid;

    (status);
    stream->sp.last_ts.u64 = frame->timestamp.u64;

    if (!stream->sp.is_running)
    return PJ_EINVALIDOP;

    if (frame->size==0 || frame->buf==NULL ||
    frame->size < stream->sp.vafp.framebytes)
    return PJ_SUCCESS;

    stream->sp.frame = frame;
////// ABChernic: 2018-01-25
    //job_queue_post_job(stream->sp.sf->jq, put_frame, strm, 0, &status);
    
    return status;
}
/* API: Stop stream. */             //############################################# O7 sdl_stream_stop
static pj_status_t sdl_stream_stop              (pjmedia_vid_dev_stream *strm){
    struct sdl_stream *stream = (struct sdl_stream*)strm;

    PJ_LOG(4, (THIS_FILE, "Stopping sdl video stream"));

    stream->sp.is_running = PJ_FALSE;

    return PJ_SUCCESS;
}
/* API: Destroy stream. */          //############################################# O8 sdl_stream_destroy
static pj_status_t sdl_stream_destroy           (pjmedia_vid_dev_stream *strm){
    struct sdl_stream *stream = (struct sdl_stream*)strm;
    pj_status_t status;

    PJ_ASSERT_RETURN(stream != NULL, PJ_EINVAL);

    sdl_stream_stop(strm);

    job_queue_post_job(stream->sp.sf->jq, sdl_destroy_all, strm, 0, &status);
    if (status != PJ_SUCCESS)
        return status;

    pj_mutex_lock(stream->sp.sf->mutex);
    if (!pj_list_empty(&stream->sp.list_entry))
    pj_list_erase(&stream->sp.list_entry);
    pj_mutex_unlock(stream->sp.sf->mutex);

    pj_pool_release(stream->sp.pool);

    return PJ_SUCCESS;
}
/* API: set_dir. */                 //############################################# O9 sdl_stream_set_dir //set_dir
static pj_status_t sdl_stream_set_dir           (pjmedia_vid_dev_stream *s, const void *pval){
    struct sdl_stream *strm = (struct sdl_stream*)s;
    struct strm_dir sdir;
    pj_status_t status;

    PJ_ASSERT_RETURN(s && pval, PJ_EINVAL);

    sdir.strm = strm;
    sdir.dir  = *(pj_str_t*)pval;

    job_queue_post_job(strm->sp.sf->jq, set_dir, &sdir, 0, &status);

    return status;
}

/// ABChernic : sdl_dev.c)      static pjmedia_vid_dev_stream_op stream_op
/// ABChernic : videodev_imp.h) struct pjmedia_vid_dev_stream_op
/// ABChernic : videodev.c)     PJ_DEF(pj_status_t) XXX()
static pj_status_t sdl_stream_get_sdl_window    (pjmedia_vid_dev_stream *s, void *pval){
    /*
    struct sdl_stream *strm = (struct sdl_stream*)s;
    pj_status_t status = PJ_SUCCESS;
    SDL_Window *Xpval = (SDL_Window *)pval;
    //int *Xpval = (SDL_Window *)pval;
    //Xpval = a;


    PJ_ASSERT_RETURN(s && pval, PJ_EINVAL);
    pval = strm->sp.window;
    */

    struct sdl_stream *strm = (struct sdl_stream*)s;
    struct strm_win swin;
    pj_status_t status;

    PJ_ASSERT_RETURN(s && pval, PJ_EINVAL);

    swin.strm = strm;
    swin.pval.pval = pval;

    job_queue_post_job(strm->sp.sf->jq, get_sdl_window, &swin, 0, &status);

    return status;
}
static pj_status_t sdl_stream_set_sdl_window    (pjmedia_vid_dev_stream *s, const void *pval){
    struct sdl_stream *strm = (struct sdl_stream*)s;
    pj_status_t status = PJ_SUCCESS;
    (strm);
    (pval);

    return status;
}

static pj_status_t sdl_stream_put_previw        (pjmedia_vid_dev_stream *strm, const pjmedia_frame *frame){
    struct sdl_stream *stream = (struct sdl_stream*)strm;
    pj_status_t status = 0;

    (status);
    stream->sp.last_ts.u64 = frame->timestamp.u64;

    if (!stream->sp.is_running)
    return PJ_EINVALIDOP;

    if (frame->size==0 || frame->buf==NULL ||
    frame->size < stream->sp.vafp.framebytes)
    return PJ_SUCCESS;

    stream->sp.frame = frame;
    job_queue_post_job(stream->sp.sf->jq, put_frame_prwviw, strm, 0, &status);
    return status;
}
static pj_status_t sdl_stream_put_stream        (pjmedia_vid_dev_stream *strm, const pjmedia_frame *frame){
    struct sdl_stream *stream = (struct sdl_stream*)strm;
    pj_status_t status = 0;

    (status);
    stream->sp.last_ts.u64 = frame->timestamp.u64;

    if (!stream->sp.is_running)
    return PJ_EINVALIDOP;

    if (frame->size==0 || frame->buf==NULL ||
    frame->size < stream->sp.vafp.framebytes)
    return PJ_SUCCESS;

    stream->sp.frame = frame;
    job_queue_post_job(stream->sp.sf->jq, put_frame_stream, strm, 0, &status);
    return status;
}
/// ABChernic : 2018-01-04 <<<

/* API: create stream */
static pj_status_t sdl_factory_create_stream    (pjmedia_vid_dev_factory *f, pjmedia_vid_dev_param *param, const pjmedia_vid_dev_cb *cb, void *user_data, pjmedia_vid_dev_stream **p_vid_strm){

    pj_status_t status;
    struct sdl_stream *strm;

    struct sdl_factory *sfP = (struct sdl_factory*)f;
    pj_pool_t *poolP;

    //struct sdl_factory *sfS   = (struct sdl_factory*)f;
    //pj_pool_t *poolS;

    PJ_ASSERT_RETURN(param->dir == PJMEDIA_DIR_RENDER, PJ_EINVAL);

    /* Create and Initialize stream descriptor */
    poolP = pj_pool_create(sfP->pf, "sdl-dev", 1000, 1000, NULL);
    PJ_ASSERT_RETURN(poolP != NULL, PJ_ENOMEM);

    strm = PJ_POOL_ZALLOC_T(poolP, struct sdl_stream);
    pj_memcpy(&strm->param, param, sizeof(*param));
    strm->sp.pool              = poolP;
    strm->sp.sf                = sfP;
    pj_memcpy(&strm->sp.vid_cb, cb, sizeof(*cb));
    pj_list_init(&strm->sp.list_entry);
    strm->sp.list_entry.stream = strm;
    strm->sp.user_data         = user_data;

    /* Create render stream here */
    job_queue_post_job(sfP->jq, sdl_create, strm, 0, &status);
    if (status != PJ_SUCCESS) {
        goto on_error;
    }
    pj_mutex_lock(strm->sp.sf->mutex);
    if (pj_list_empty(&strm->sp.sf->streams))
        pj_sem_post(strm->sp.sf->sem);
    pj_list_insert_after(&strm->sp.sf->streams, &strm->sp.list_entry);
    pj_mutex_unlock(strm->sp.sf->mutex);

    /* Done */
    strm->base.op = &stream_op;
    *p_vid_strm = &strm->base;

    return PJ_SUCCESS;

on_error:
    sdl_stream_destroy(&strm->base);
    return status;
}

/****************************************************************************
 * Job queue implementation
 */
#if PJ_DARWINOS==0
static int job_thread(void * data)
{
    job_queue *jq = (job_queue *)data;

    while (1) {
        job *jb;

    /* Wait until there is a job. */
        pj_sem_wait(jq->sem);

        /* Make sure there is no pending jobs before we quit. */
        if (jq->is_quitting && jq->head == jq->tail && !jq->is_full)
            break;

        jb = jq->jobs[jq->head];
        jb->retval = (*jb->func)(jb->data);
        /* If job queue is full and we already finish all the pending
         * jobs, increase the size.
         */
        if (jq->is_full && ((jq->head + 1) % jq->size == jq->tail)) {
            unsigned i, head;
            pj_status_t status;

            if (jq->old_sem) {
                for (i = 0; i < jq->size / JOB_QUEUE_INC_FACTOR; i++) {
                    pj_sem_destroy(jq->old_sem[i]);
                }
            }
            jq->old_sem = jq->job_sem;

            /* Double the job queue size. */
            jq->size *= JOB_QUEUE_INC_FACTOR;
            pj_sem_destroy(jq->sem);
            status = pj_sem_create(jq->pool, "thread_sem", 0, jq->size + 1,
                                   &jq->sem);
            if (status != PJ_SUCCESS) {
                PJ_LOG(3, (THIS_FILE, "Failed growing SDL job queue size."));
                return 0;
            }
            jq->jobs = (job **)pj_pool_calloc(jq->pool, jq->size,
                                              sizeof(job *));
            jq->job_sem = (pj_sem_t **) pj_pool_calloc(jq->pool, jq->size,
                                                       sizeof(pj_sem_t *));
            for (i = 0; i < jq->size; i++) {
                status = pj_sem_create(jq->pool, "job_sem", 0, 1,
                                       &jq->job_sem[i]);
                if (status != PJ_SUCCESS) {
                    PJ_LOG(3, (THIS_FILE, "Failed growing SDL job "
                                          "queue size."));
                    return 0;
                }
            }
            jq->is_full = PJ_FALSE;
            head = jq->head;
            jq->head = jq->tail = 0;
            pj_sem_post(jq->old_sem[head]);
        } else {
            pj_sem_post(jq->job_sem[jq->head]);
            jq->head = (jq->head + 1) % jq->size;
        }
    }

    return 0;
}
#endif

static pj_status_t job_queue_create(pj_pool_t *pool, job_queue **pjq){
    unsigned i;
    pj_status_t status;

    job_queue *jq = PJ_POOL_ZALLOC_T(pool, job_queue);
    jq->pool = pool;
    jq->size = INITIAL_MAX_JOBS;
    status = pj_sem_create(pool, "thread_sem", 0, jq->size + 1, &jq->sem);
    if (status != PJ_SUCCESS)
        goto on_error;
    jq->jobs = (job **)pj_pool_calloc(pool, jq->size, sizeof(job *));
    jq->job_sem = (pj_sem_t **) pj_pool_calloc(pool, jq->size,
                                               sizeof(pj_sem_t *));
    for (i = 0; i < jq->size; i++) {
        status = pj_sem_create(pool, "job_sem", 0, 1, &jq->job_sem[i]);
        if (status != PJ_SUCCESS)
            goto on_error;
    }

    status = pj_mutex_create_recursive(pool, "job_mutex", &jq->mutex);
    if (status != PJ_SUCCESS)
        goto on_error;

#if defined(PJ_DARWINOS) && PJ_DARWINOS!=0
    PJ_UNUSED_ARG(status);
#else
    status = pj_thread_create(pool, "job_th", job_thread, jq, 0, 0,
                              &jq->thread);
    if (status != PJ_SUCCESS)
        goto on_error;
#endif /* PJ_DARWINOS */

    *pjq = jq;
    return PJ_SUCCESS;

on_error:
    job_queue_destroy(jq);
    return status;
}

static pj_status_t job_queue_post_job(job_queue *jq, job_func_ptr func, void *data, unsigned flags, pj_status_t *retval){
    job jb;
    int tail;

    if (jq->is_quitting)
        return PJ_EBUSY;

    jb.func = func;
    jb.data = data;
    jb.flags = flags;

#if defined(PJ_DARWINOS) && PJ_DARWINOS!=0
    PJ_UNUSED_ARG(tail);
    NSAutoreleasePool *apool = [[NSAutoreleasePool alloc]init];
    JQDelegate *jqd = [[JQDelegate alloc]init];
    jqd->pjob = &jb;
    [jqd performSelectorOnMainThread:@selector(run_job)
     withObject:nil waitUntilDone:YES];
    [jqd release];
    [apool release];
#else /* PJ_DARWINOS */
    pj_mutex_lock(jq->mutex);
    jq->jobs[jq->tail] = &jb;
    tail = jq->tail;
    jq->tail = (jq->tail + 1) % jq->size;
    if (jq->tail == jq->head) {
    jq->is_full = PJ_TRUE;
        PJ_LOG(4, (THIS_FILE, "SDL job queue is full, increasing "
                              "the queue size."));
        pj_sem_post(jq->sem);
        /* Wait until our posted job is completed. */
        pj_sem_wait(jq->job_sem[tail]);
        pj_mutex_unlock(jq->mutex);
    } else {
        pj_mutex_unlock(jq->mutex);
        pj_sem_post(jq->sem);
        /* Wait until our posted job is completed. */
        pj_sem_wait(jq->job_sem[tail]);
    }
#endif /* PJ_DARWINOS */

    *retval = jb.retval;

    return PJ_SUCCESS;
}

static pj_status_t job_queue_destroy(job_queue *jq){
    unsigned i;

    jq->is_quitting = PJ_TRUE;

    if (jq->thread) {
        pj_sem_post(jq->sem);
        pj_thread_join(jq->thread);
        pj_thread_destroy(jq->thread);
    }

    if (jq->sem) {
        pj_sem_destroy(jq->sem);
        jq->sem = NULL;
    }
    for (i = 0; i < jq->size; i++) {
        if (jq->job_sem[i]) {
            pj_sem_destroy(jq->job_sem[i]);
            jq->job_sem[i] = NULL;
        }
    }
    if (jq->old_sem) {
        for (i = 0; i < jq->size / JOB_QUEUE_INC_FACTOR; i++) {
            if (jq->old_sem[i]) {
                pj_sem_destroy(jq->old_sem[i]);
                jq->old_sem[i] = NULL;
            }
        }
    }
    if (jq->mutex) {
        pj_mutex_destroy(jq->mutex);
        jq->mutex = NULL;
    }

    return PJ_SUCCESS;
}

#ifdef _MSC_VER
#   if defined(PJMEDIA_SDL_LIB)
#   pragma comment( lib, PJMEDIA_SDL_LIB)
#   elif SDL_VERSION_ATLEAST(2,0,0)
#   pragma comment( lib, "sdl2.lib")
#   elif SDL_VERSION_ATLEAST(1,3,0)
#   pragma comment( lib, "sdl.lib")
#   endif
#   if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
#   pragma comment(lib, "OpenGL32.lib")
#   endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */
#endif /* _MSC_VER */

#endif  /* PJMEDIA_VIDEO_DEV_HAS_SDL */
