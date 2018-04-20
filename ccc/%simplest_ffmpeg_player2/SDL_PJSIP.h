////////////////////// sdl_dev.c 343
    while (SDL_PollEvent(&sevent)) {
        struct sdl_stream *strm = NULL;
        pjmedia_event pevent;


sdl_create_rend{
    vfd = pjmedia_format_get_video_format_detail(fmt, PJ_TRUE);
    strm->rect.w = (Uint16)vfd->size.w;
}


sdl_stream
sdl_create_window
////////////////////// sdl_dev.c 771
strm->window = SDL_CreateWindow("pjmedia-SDL video",
    x, y,
    strm->param.disp_size.w,
    strm->param.disp_size.h,
    flags);
////////////////////// sdl_dev.c 783
/// strm->renderer === sdlR
strm->renderer = SDL_CreateRenderer(strm->window, -1, 0);
    if (!strm->renderer) {
    sdl_log_err("SDL_CreateRenderer()");
        return PJMEDIA_VID_SYSERR;
    }
////////////////////// sdl_dev.c 827
/// strm->scr_tex === s1.sdlTexture
strm->scr_tex = SDL_CreateTexture(strm->renderer, sdl_format,
    SDL_TEXTUREACCESS_STREAMING,
    strm->rect.w, strm->rect.h);
strm->scr_texP = SDL_CreateTexture(strm->renderer, sdl_format,
    SDL_TEXTUREACCESS_STREAMING,
    strm->rectA.w, strm->rectA.h);
strm->scr_texS = SDL_CreateTexture(strm->renderer, sdl_format,
    SDL_TEXTUREACCESS_STREAMING,
    strm->rectV.w, strm->rectB.h);

\sdl_dev.c(655) : error C2039: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_stream”的声明
\sdl_dev.c(656) : error C2039: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_strssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssseam”的声明
\sdl_dev.c(656) : error C2198: “SDL_DestroyTexture”: 用于调用的参数太少
\sdl_dev.c(657) : error C2039sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_stream”的声明

\sdl_dev.c(829) : error C2039: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_stream”的声明
\sdl_dev.c(832) : error C2039: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_stream”的声明
\sdl_dev.c(899) : error C2039: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_stream”的声明
static pj_status_t resize_disp(struct sdl_stream *strm,
                               pjmedia_rect_size *new_disp_size)
                               
\sdl_dev.c(933) : error C2039: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_stream”的声明
\sdl_dev.c(934) : error C2039: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_stream”的声明
\sdl_dev.c(934) : warning C4022: “SDL_UpdateTexture”: 指针与实参 3 不匹配
\sdl_dev.c(934) : error C2198: “SDL_UpdateTexture”: 用于调用的参数太少
\sdl_dev.c(936) : error C2039: “scr_tex”: 不是“sdl_stream”的成员
        \sdl_dev.c(169) : 参见“sdl_stream”的声明
\sdl_dev.c(937) : warning C4133: “函数”: 从“SDL_Rect *”到“SDL_Texture *”的类型不兼容
\sdl_dev.c(937) : error C2198: “SDL_RenderCopy”: 用于调用的参数太少















static pjmedia_vid_dev_stream_op stream_op =
{
    &sdl_stream_get_param,
    &sdl_stream_get_cap,
    &sdl_stream_set_cap,
    &sdl_stream_start,
    NULL,
    &sdl_stream_put_frame,
    &sdl_stream_stop,
    &sdl_stream_destroy
};

static pj_status_t sdl_stream_put_frame(pjmedia_vid_dev_stream *strm,
                    const pjmedia_frame *frame)
{
    stream->frame = frame;
    job_queue_post_job(stream->sf->jq, put_frame, strm, 0, &status);
}

static pj_status_t put_frame(void *data)
{
    struct sdl_stream *stream = (struct sdl_stream *)data;
    const pjmedia_frame *frame = stream->frame;

    if (stream->scr_tex) {
        SDL_UpdateTexture(stream->scr_tex, NULL,
            frame->buf, stream->pitch);
     // SDL_UpdateTexture(s1.sdlTexture,   NULL,
     //     s1.pFrameYUV->data[0], s1.pFrameYUV->linesize[0] );

        SDL_RenderClear(stream->renderer);
        SDL_RenderCopy(stream->renderer, stream->scr_tex,
               &stream->rect, &stream->dstrect);
        SDL_RenderPresent(stream->renderer);
    }
#if PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL
    else if (stream->param.rend_id == OPENGL_DEV_IDX && stream->texture) {
    glBindTexture(GL_TEXTURE_2D, stream->texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
             stream->rect.w, stream->rect.h, 0,
             GL_RGBA, GL_UNSIGNED_BYTE, frame->buf);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0, 0); glVertex2i(0, 0);
    glTexCoord2f(1, 0); glVertex2i(stream->param.disp_size.w, 0);
    glTexCoord2f(0, 1); glVertex2i(0, stream->param.disp_size.h);
    glTexCoord2f(1, 1);
        glVertex2i(stream->param.disp_size.w, stream->param.disp_size.h);
    glEnd();
        SDL_GL_SwapWindow(stream->window);
    }
#endif /* PJMEDIA_VIDEO_DEV_SDL_HAS_OPENGL */

    return PJ_SUCCESS;
}