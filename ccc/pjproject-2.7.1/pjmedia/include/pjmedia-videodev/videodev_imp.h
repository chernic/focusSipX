/* $Id: videodev_imp.h 4016 2012-04-04 05:05:50Z bennylp $ */
/* 
 * Copyright (C) 2008-2011 Teluu Inc. (http://www.teluu.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
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
#ifndef __VIDEODEV_IMP_H__
#define __VIDEODEV_IMP_H__

#include <pjmedia-videodev/videodev.h>

/**
 * @defgroup s8_video_device_implementors_api Video Device Implementors API
 * @ingroup video_device_api
 * @brief API for video device implementors
 * @{
 */

/**
 * Video device factory operations.
 */
typedef struct pjmedia_vid_dev_factory_op
{
    /**
     * Initialize the video device factory.
     *
     * @param f		The video device factory.
     */
    pj_status_t (*init)(pjmedia_vid_dev_factory *f);

    /**
     * Close this video device factory and release all resources back to the
     * operating system.
     *
     * @param f		The video device factory.
     */
    pj_status_t (*destroy)(pjmedia_vid_dev_factory *f);

    /**
     * Get the number of video devices installed in the system.
     *
     * @param f		The video device factory.
     */
    unsigned (*get_dev_count)(pjmedia_vid_dev_factory *f);

    /**
     * Get the video device information and capabilities.
     *
     * @param f		The video device factory.
     * @param index	Device index.
     * @param info	The video device information structure which will be
     *			initialized by this function once it returns 
     *			successfully.
     */
    pj_status_t	(*get_dev_info)(pjmedia_vid_dev_factory *f, 
				unsigned index,
				pjmedia_vid_dev_info *info);

    /**
     * Initialize the specified video device parameter with the default
     * values for the specified device.
     *
     * @param f		The video device factory.
     * @param index	Device index.
     * @param param	The video device parameter.
     */
    pj_status_t (*default_param)(pj_pool_t *pool,
                                 pjmedia_vid_dev_factory *f,
				 unsigned index,
				 pjmedia_vid_dev_param *param);

    /**
     * Open the video device and create video stream. See
     * #pjmedia_vid_dev_stream_create()
     */
    pj_status_t (*create_stream)(pjmedia_vid_dev_factory *f,
				 pjmedia_vid_dev_param *param,
				 const pjmedia_vid_dev_cb *cb,
				 void *user_data,
				 pjmedia_vid_dev_stream **p_vid_strm);

    /**
     * Refresh the list of video devices installed in the system.
     *
     * @param f     The video device factory.
     */
    pj_status_t (*refresh)(pjmedia_vid_dev_factory *f);

} pjmedia_vid_dev_factory_op;


/**
 * This structure describes a video device factory. 
 */
struct pjmedia_vid_dev_factory
{
    /** Internal data to be initialized by video subsystem. */
    struct {
    /** Driver index */
    unsigned drv_idx;
    } sys;

    /** Operations */
    pjmedia_vid_dev_factory_op *op;
};

//Video stream operations.
/// ABChernic : 2018-02-01 >>>
/// ABChernic : sdl_dev.c)      static pjmedia_vid_dev_stream_op stream_op
/// ABChernic : videodev_imp.h) struct pjmedia_vid_dev_stream_op
/// ABChernic : videodev.c)     PJ_DEF(pj_status_t) XXX()
typedef struct pjmedia_vid_dev_stream_op{ 
    pj_status_t (*get_param)(pjmedia_vid_dev_stream *strm,pjmedia_vid_dev_param *param);			// O1 sdl_stream_get_param	pjmedia_vid_dev_stream_get_param()
    pj_status_t (*get_cap)  (pjmedia_vid_dev_stream *strm,pjmedia_vid_dev_cap cap,void *value);		// O2 sdl_stream_get_cap	pjmedia_vid_dev_stream_get_cap()
    pj_status_t (*set_cap)  (pjmedia_vid_dev_stream *strm,pjmedia_vid_dev_cap cap,const void*value);// O3 sdl_stream_set_cap	pjmedia_vid_dev_stream_set_cap()
    pj_status_t (*start)    (pjmedia_vid_dev_stream *strm);											// O4 sdl_stream_start		pjmedia_vid_dev_stream_start()

    pj_status_t (*get_frame)(pjmedia_vid_dev_stream *strm,pjmedia_frame *frame);					// O5 						pjmedia_vid_dev_stream_get_frame()
    pj_status_t (*put_frame)(pjmedia_vid_dev_stream *strm,const pjmedia_frame *frame);				// O6 sdl_stream_put_frame	pjmedia_vid_dev_stream_put_frame()

    pj_status_t (*stop)     (pjmedia_vid_dev_stream *strm);											// O7 sdl_stream_stop		pjmedia_vid_dev_stream_stop()
    pj_status_t (*destroy)  (pjmedia_vid_dev_stream *strm);											// O8 sdl_stream_destroy	pjmedia_vid_dev_stream_destroy()
    pj_status_t (*set_dir)  (pjmedia_vid_dev_stream *strm,const void *value);						// O9 sdl_stream_set_dir	pjmedia_vid_dev_stream_set_dir()

    pj_status_t (*put_previw)(pjmedia_vid_dev_stream *strm,const void *value);						// 10 sdl_stream_put_previw	pjmedia_vid_dev_put_previw()
    pj_status_t (*put_stream)(pjmedia_vid_dev_stream *strm,const void *value);						// 11 sdl_stream_put_stream	pjmedia_vid_dev_put_stream()

    pj_status_t (*get_sdl_window) (pjmedia_vid_dev_stream *strm, void *value);						// 12 sdl_stream_put_previw	pjmedia_vid_dev_put_previw()
    pj_status_t (*set_sdl_window) (pjmedia_vid_dev_stream *strm, const void *value);			    // 13 sdl_stream_put_stream	pjmedia_vid_dev_put_stream()
} pjmedia_vid_dev_stream_op;
/// ABChernic : 2018-01-04 <<<

/**
 * This structure describes the video device stream.
 */
struct pjmedia_vid_dev_stream
{
    /** Internal data to be initialized by video subsystem */
    struct {
    /** Driver index */
    unsigned drv_idx;

    /** Has it been started? */
    pj_bool_t is_running;
    } sys;

    /** Operations */
    pjmedia_vid_dev_stream_op *op;
};


/**
 * Internal API: return the factory instance and device index that's local
 * to the factory for a given device ID.
 *
 * @param id		Device id.
 * @param p_f		Out: factory instance
 * @param p_local_index Out: device index within the factory
 *
 * @return		PJ_SUCCESS on success.
 */
PJ_DECL(pj_status_t)
pjmedia_vid_dev_get_local_index(pjmedia_vid_dev_index id,
                                pjmedia_vid_dev_factory **p_f,
                                unsigned *p_local_index);

/**
 * Internal API: return the global device index given a factory instance and
 * a local device index.
 *
 * @param f		Factory.
 * @param local_idx	Local index.
 * @param pid		Returned global index.
 *
 * @return		PJ_SUCCESS on success.
 */
PJ_DEF(pj_status_t)
pjmedia_vid_dev_get_global_index(const pjmedia_vid_dev_factory *f,
                                 unsigned local_idx,
                                 pjmedia_vid_dev_index *pid);

/**
 * @}
 */



#endif /* __VIDEODEV_IMP_H__ */
