////////////////////////////////////////////
// S-3 : Setup decoding direction
if (si->dir & PJMEDIA_DIR_DECODING)
{
    // acc->cfg
    pjsua_vid_win *w;
    pjsua_vid_win_id wid;
    // pj_bool_t just_created = PJ_FALSE;
    PJ_LOG(4,(THIS_FILE, "Setting up RX.."));
    pj_log_push_indent();

    // (acc->cfg);

    //S-2 :
    status = pjmedia_vid_stream_get_port(
        call_med->strm.v.stream,
        PJMEDIA_DIR_DECODING, // ABChernic : @@@@@@@
        &media_port);
    if (status != PJ_SUCCESS) {
        pj_log_pop_indent();
        goto on_error;
    }

    //S-1 : Get Windows
    wid_p = vid_preview_get_win(
        call_med->strm.v.cap_dev,
        PJ_FALSE);
    //if (wid_p != PJSUA_INVALID_ID) {

    //S01 : Create stream video window
    //if (wid_p != PJSUA_INVALID_ID) {
        status = create_vid_win(
            PJSUA_WND_TYPE_STREAM,
            &media_port->info.fmt,
            call_med->strm.v.rdr_dev,
            PJSUA_INVALID_ID,
            acc->cfg.vid_in_auto_show,
            acc->cfg.vid_stream_wnd_flags,
            NULL,
            &wid);
            if (status != PJ_SUCCESS) {
                pj_log_pop_indent();
                goto on_error;
            }
        //just_created = PJ_TRUE;
    //}

    //S02 : pjsua_var.win
    w = &pjsua_var.win[wid];

    //S03 : Register to video events
    #if ENABLE_EVENT
        pjmedia_event_subscribe(
        NULL,
        &call_media_on_event,
        call_med,
        w->vp_rend);
    #endif

    // 04 : Connect renderer to stream
    status = pjmedia_vid_port_connect(
        w->vp_rend,
        media_port,
        PJ_FALSE);
        if (status != PJ_SUCCESS) {
            pj_log_pop_indent();
            goto on_error;
        }

    // 05 : Connect stream to capturer
#ifndef THIS_IS_NOT_USE_FOR_STREAM
    status = pjmedia_vid_tee_add_dst_port2(
        w->tee,
        0,
        media_port);
        if (status != PJ_SUCCESS) {
            pj_log_pop_indent();
            goto on_error;
        }
#endif

    //S06 : Start renderer
    // {
        status = pjmedia_vid_port_start(
        w->vp_rend);
        if (status != PJ_SUCCESS) {
            pj_log_pop_indent();
            goto on_error;
        }
    //}

    //S07 : Done
    inc_vid_win(wid);

    //S08 : inc_vid_win
    w->stream_running = PJ_TRUE;
    call_med->strm.v.rdr_win_id = wid;
    pj_log_pop_indent();
}
