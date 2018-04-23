//////////////////////////////////////////////
// P-3 :Setup encoding direction
if (si->dir & PJMEDIA_DIR_ENCODING
    && !call->local_hold)
{
    pjsua_acc *acc_enc;
    pjsua_vid_win *w;
    pjsua_vid_win_id wid;
    pj_bool_t just_created = PJ_FALSE;
    PJ_LOG(4,(THIS_FILE, "Setting up TX.."));
    pj_log_push_indent();

    acc_enc = &pjsua_var.acc[call_med->call->acc_id];

    //P-2 :
    status = pjmedia_vid_stream_get_port(
        call_med->strm.v.stream,
        PJMEDIA_DIR_ENCODING, // ABChernic : @@@@@@@
        &media_port);
        if (status != PJ_SUCCESS) {
            pj_log_pop_indent();
            goto on_error;
        }

    //S-1 : Get Windows
    wid = vid_preview_get_win(
        call_med->strm.v.cap_dev,
        PJ_FALSE);

    //P01 Create preview video window
    if (wid == PJSUA_INVALID_ID) {
        status = create_vid_win(
            PJSUA_WND_TYPE_PREVIEW,
            &media_port->info.fmt,
            call_med->strm.v.rdr_dev,
            call_med->strm.v.cap_dev,
            PJSUA_HIDE_WINDOW,
            acc_enc->cfg.vid_wnd_flags,
            NULL,
            &wid);
            if (status != PJ_SUCCESS) {
                pj_log_pop_indent();
                return status;
            }
        just_created = PJ_TRUE;
    }

    //P02 : pjsua_var.win
    w = &pjsua_var.win[wid];

    //P03 : Register to video events
    #if ENABLE_EVENT
        pjmedia_event_subscribe(
        NULL,
        &call_media_on_event,
        call_med,
        w->vp_cap);
    #endif

    // 04 : Connect renderer to stream 
#ifndef THIS_IS_NOT_USE_FOR_CAPTURER
    status = pjmedia_vid_port_connect(
        w->vp_rend,
        media_port,
        PJ_FALSE);
        if (status != PJ_SUCCESS) {
           pj_log_pop_indent();
           goto on_error;
        }
#endif

    // 05 : Connect stream to capturer
    
    status = pjmedia_vid_tee_add_dst_port2(
        w->tee,
        0,
        media_port);
        if (status != PJ_SUCCESS) {
            pj_log_pop_indent();
            goto on_error;
        }
        

    //P06 : Start capturer
    if (just_created) {
        status = pjmedia_vid_port_start(
        w->vp_cap);
        if (status != PJ_SUCCESS) {
            pj_log_pop_indent();
            goto on_error;
        }
    }

    //P07 : Done
    inc_vid_win(wid);

    //P08 : inc_vid_win
    //w->stream_running = PJ_TRUE;
    call_med->strm.v.cap_win_id = wid;
    pj_log_pop_indent();
}
