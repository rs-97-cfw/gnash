// NetStreamGst.cpp:  Audio/video output via Gstreamer library, for Gnash.
// 
//   Copyright (C) 2005, 2006, 2007 Free Software Foundation, Inc.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

/* $Id: NetStreamGst.cpp,v 1.40 2007/05/16 12:50:26 strk Exp $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef SOUND_GST

#include "log.h"
#include "NetStreamGst.h"
#include "fn_call.h"
#include "NetStream.h"
#include "URLAccessManager.h"
#include "render.h"	
#include "movie_root.h"
#include "NetConnection.h"
//#include "action.h"

#include "gstgnashsrc.h"

#include "URL.h"

namespace gnash {

static gboolean
register_elements (GstPlugin *plugin)
{
	return gst_element_register (plugin, "gnashsrc", GST_RANK_NONE, GST_TYPE_GNASH_SRC);
}

static GstPluginDesc gnash_plugin_desc = {
	0, // GST_VERSION_MAJOR
	10, // GST_VERSION_MINOR
	"gnashsrc",
	"Use gnash as source via callbacks",
	register_elements,
	"0.0.1",
	"LGPL",
	"gnash",
	"gnash",
	"http://www.gnu.org/software/gnash/",
	GST_PADDING_INIT
};

NetStreamGst::NetStreamGst():

	pipeline(NULL),
	audiosink(NULL),
	videosink(NULL),
	decoder(NULL),
	volume(NULL),
	colorspace(NULL),
	videorate(NULL),
	videocaps(NULL),
	videoflip(NULL),
	audioconv(NULL),

	audiosource(NULL),
	videosource(NULL),
	source(NULL),
	videodecoder(NULL),
	audiodecoder(NULL),
	videoinputcaps(NULL),
	audioinputcaps(NULL),
	_handoffVideoSigHandler(0),
	_handoffAudioSigHandler(0),

#ifndef DISABLE_START_THREAD
	startThread(NULL),
#endif
	videowidth(0),
	videoheight(0),
	m_clock_offset(0),
	m_pausePlayback(false)
{
	gst_init (NULL, NULL);
}

NetStreamGst::~NetStreamGst()
{
	close();
}

void NetStreamGst::pause(int mode)
{
	if (mode == -1)
	{
		m_pause = ! m_pause;
	}
	else
	{
		m_pause = (mode == 0) ? true : false;
	}

	if (pipeline)
	{
		if (m_pause)
		{ 
			log_msg("Pausing pipeline on user request");
			if ( ! pausePipeline(false) )
			{
				log_error("Could not pause pipeline");
			}
		}
		else
		{
			if ( ! playPipeline() )
			{
				log_error("Could not play pipeline");
			}
		}
	}
}

void NetStreamGst::close()
{
	if (m_go)
	{
		m_go = false;
#ifndef DISABLE_START_THREAD
		startThread->join();
		delete startThread;
#endif
	}

	if ( ! disablePipeline() )
	{
		log_error("Can't reset pipeline on close");
	}

	// Should we keep the ref if the above failed ?
	gst_object_unref (GST_OBJECT (pipeline));

	if (m_imageframe) delete m_imageframe;

}


int
NetStreamGst::play(const std::string& c_url)
{

	// Does it have an associated NetConnection?
	if ( ! _netCon )
	{
		IF_VERBOSE_ASCODING_ERRORS(
		log_aserror(_("No NetConnection associated with this NetStream, won't play"));
		);
		return 0;
	}

	// Is it already playing ?
	if (m_go)
	{
		if (m_pause)
		{
			playPipeline();
		}
		return 0;
	}


	url += c_url;
	// Remove any "mp3:" prefix. Maybe should use this to mark as audio-only
	if (url.compare(0, 4, std::string("mp3:")) == 0) {
		url = url.substr(4);
	}
	m_go = true;

	// To avoid blocking while connecting, we use a thread.
#ifndef DISABLE_START_THREAD
	startThread = new boost::thread(boost::bind(NetStreamGst::playbackStarter, this));
#else
	startPlayback(this);
#endif
	return 0;
}


// Callback function used by Gstreamer to to attached audio and video streams
// detected by decoderbin to either the video out or audio out elements.
// Only used when not playing FLV
void
NetStreamGst::callback_newpad (GstElement* /*decodebin*/, GstPad *pad, gboolean /*last*/, gpointer data)
{

	NetStreamGst* ns = static_cast<NetStreamGst*>(data);
	GstCaps *caps;
	GstStructure *str;
	GstPad *audiopad, *videopad;

	audiopad = gst_element_get_pad (ns->audioconv, "sink");
	videopad = gst_element_get_pad (ns->colorspace, "sink");

	// check media type
	caps = gst_pad_get_caps (pad);
	str = gst_caps_get_structure (caps, 0);
	if (g_strrstr (gst_structure_get_name (str), "audio")) {
		gst_object_unref (videopad);

		// link'n'play
		gst_pad_link (pad, audiopad);

	} else if (g_strrstr (gst_structure_get_name (str), "video")) {
		gst_object_unref (audiopad);
		// Link'n'play
		gst_pad_link (pad, videopad);
	} else {
		gst_object_unref (audiopad);
		gst_object_unref (videopad);
	}
	gst_caps_unref (caps);
	return;

}

// The callback function which unloads the decoded video frames unto the video
// output imageframe.
void 
NetStreamGst::callback_output (GstElement* /*c*/, GstBuffer *buffer, GstPad* /*pad*/, gpointer user_data)
{
	NetStreamGst* ns = static_cast<NetStreamGst*>(user_data);

	boost::mutex::scoped_lock lock(ns->image_mutex);

	// If the video size has not yet been detected, detect them
	if (ns->videowidth == 0 && ns->videoheight == 0) {
		GstPad* videopad = gst_element_get_pad (ns->colorspace, "src");
		GstCaps* caps = gst_pad_get_caps (videopad);
		GstStructure* str = gst_caps_get_structure (caps, 0);

		int height, width, ret, framerate1, framerate2;
		ret = gst_structure_get_int (str, "width", &width);
		ret &= gst_structure_get_int (str, "height", &height);
		if (ret) {
			ns->videowidth = width;
			ns->videoheight = height;
		}
		ret = gst_structure_get_fraction (str, "framerate", &framerate1, &framerate2);
		
		// Setup the output videoframe
		if (ns->m_videoFrameFormat == render::YUV) {
			ns->m_imageframe = new image::yuv(width, height);
		} else if (ns->m_videoFrameFormat == render::RGB) {
			ns->m_imageframe = new image::rgb(width, height);
		}
	}

	if (ns->m_imageframe) {
//		ns->m_imageframe->update(GST_BUFFER_DATA(buffer));
		if (ns->m_videoFrameFormat == render::YUV) {
			assert(0);

		/*	image::yuv* yuvframe = static_cast<image::yuv*>(m_imageframe);
			int copied = 0;
			uint8_t* ptr = GST_BUFFER_DATA(buffer);
			for (int i = 0; i < 3 ; i++)
			{
				int shift = (i == 0 ? 0 : 1);
				uint8_t* yuv_factor = m_Frame->data[i];
				int h = ns->videoheight >> shift;
				int w = ns->videowidth >> shift;
				for (int j = 0; j < h; j++)
				{
					copied += w;
					assert(copied <= yuvframe->size());
					memcpy(ptr, yuv_factor, w);
					yuv_factor += m_Frame->linesize[i];
					ptr += w;
				}
			}
			video->m_size = copied;*/
		} else {
			ns->m_imageframe->update(GST_BUFFER_DATA(buffer));
			ns->m_newFrameReady = true;
		}

	}

}


// The callback function which refills the audio buffer with data
// Only used when playing FLV
void NetStreamGst::audio_callback_handoff (GstElement * /*c*/, GstBuffer *buffer, GstPad* /*pad*/, gpointer user_data)
{
	NetStreamGst* ns = static_cast<NetStreamGst*>(user_data);

	FLVFrame* frame = ns->m_parser->nextAudioFrame();
	if (!frame) {
		ns->setStatus(bufferEmpty);
		ns->m_pausePlayback = true;
		return;
	}

//	if (GST_BUFFER_DATA(buffer)) delete [] GST_BUFFER_DATA(buffer);
	GST_BUFFER_SIZE(buffer) = frame->dataSize;
	GST_BUFFER_DATA(buffer) = frame->data;
	GST_BUFFER_TIMESTAMP(buffer) = (frame->timestamp + ns->m_clock_offset) * GST_MSECOND;
	delete frame;
	return;

}

// The callback function which refills the video buffer with data
// Only used when playing FLV
void
NetStreamGst::video_callback_handoff (GstElement * /*c*/, GstBuffer *buffer, GstPad* /*pad*/, gpointer user_data)
{
	//GNASH_REPORT_FUNCTION;

	NetStreamGst* ns = static_cast<NetStreamGst*>(user_data);

	FLVFrame* frame = ns->m_parser->nextVideoFrame();
	if (!frame) {
		ns->setStatus(bufferEmpty);
		ns->m_pausePlayback = true;
		return;
	}

//	if (GST_BUFFER_DATA(buffer)) delete [] GST_BUFFER_DATA(buffer);
	GST_BUFFER_SIZE(buffer) = frame->dataSize;
	GST_BUFFER_DATA(buffer) = frame->data;
	GST_BUFFER_TIMESTAMP(buffer) = (frame->timestamp + ns->m_clock_offset) * GST_MSECOND;
	delete frame;
	return;
}

void
NetStreamGst::playbackStarter(NetStreamGst* ns)
{
	ns->startPlayback();
}

void
NetStreamGst::startPlayback()
{
	NetStreamGst* ns = this; // quick hack

	boost::intrusive_ptr<NetConnection> nc = ns->_netCon;
	assert(nc);

	// Pass stuff from/to the NetConnection object.
	assert(ns);
	if ( !nc->openConnection(ns->url) ) {
		ns->setStatus(streamNotFound);
		log_debug(_("Gnash could not open movie: %s"), ns->url.c_str());
		return;
	}

	ns->inputPos = 0;

	uint8_t head[3];
	if (nc->read(head, 3) < 3) {
		ns->setStatus(streamNotFound);
		return;
	}
	nc->seek(0);
	if (head[0] == 'F' && head[1] == 'L' && head[2] == 'V') { 
		ns->m_isFLV = true;
		ns->m_parser = new FLVParser(); // TODO: define ownership, use auto_ptr !
		if (!nc->connectParser(*(ns->m_parser))) {
			ns->setStatus(streamNotFound);
			log_debug(_("Gnash could not open movie: %s"), ns->url.c_str());
			return;
			
		}
	}

	// setup the GnashNC plugin if we are not decoding FLV
	if (!ns->m_isFLV) _gst_plugin_register_static (&gnash_plugin_desc);

	// setup the pipeline
	ns->pipeline = gst_pipeline_new (NULL);

	// Check if the creation of the gstreamer pipeline was a succes
	if (!ns->pipeline) {
		gnash::log_error(_("The gstreamer pipeline element could not be created"));
		return;
	}

	bool video = false;
	bool sound = false;

	// If sound is enabled we set it up
	if (get_sound_handler()) sound = true;
	
	if (sound) {
		// create an audio sink - use oss, alsa or...? make a commandline option?
		// we first try autodetect, then alsa, then oss, then esd, then...?
		// If the gstreamer adder ever gets fixed this should be connected to the
		// adder in the soundhandler.
#if !defined(__NetBSD__)
		ns->audiosink = gst_element_factory_make ("autoaudiosink", NULL);
		if (!ns->audiosink) ns->audiosink = gst_element_factory_make ("alsasink", NULL);
		if (!ns->audiosink) ns->audiosink = gst_element_factory_make ("osssink", NULL);
#endif
		if (!ns->audiosink) ns->audiosink = gst_element_factory_make ("esdsink", NULL);

		if (!ns->audiosink) {
			log_error(_("The gstreamer audiosink element could not be created"));
			return;
		}
		// setup the audio converter
		ns->audioconv = gst_element_factory_make ("audioconvert", NULL);
		if (!ns->audioconv) {
			log_error(_("The gstreamer audioconvert element could not be created"));
			return;
		}

		// setup the volume controller
		ns->volume = gst_element_factory_make ("volume", NULL);
		if (!ns->volume) {
			log_error(_("The gstreamer volume element could not be created"));
			return;
		}

	} else  {
		ns->audiosink = gst_element_factory_make ("fakesink", NULL);
		if (!ns->audiosink) {
			log_error(_("The gstreamer fakesink element could not be created"));
			// TODO: what to do in these cases ?
			return;
		}
	}

	// setup gnashnc source if we are not decoding FLV (our homegrown source element)
	if (!ns->m_isFLV) {
		ns->source = gst_element_factory_make ("gnashsrc", NULL);
		if ( ! ns->source )
		{
			log_error("Failed to create 'gnashrc' element");
			// TODO: should we still create the gnashrc_callback below ?
		}
		gnashsrc_callback* gc = new gnashsrc_callback; // TODO: who's going to delete this ?
		gc->read = NetStreamGst::readPacket;
		gc->seek = NetStreamGst::seekMedia;
		g_object_set (G_OBJECT (ns->source), "data", ns, "callbacks", gc, NULL);
	} else {

		FLVVideoInfo* videoInfo = ns->m_parser->getVideoInfo();

		if (videoInfo) {
			video = true;
			ns->videosource = gst_element_factory_make ("fakesrc", NULL);
			if ( ! ns->videosource )
			{
				log_error("Unable to create videosource 'fakesrc' element");
				// TODO: what to do in this case ?
			}
			
			// setup fake source
			g_object_set (G_OBJECT (ns->videosource),
						"sizetype", 2, "can-activate-pull", FALSE, "signal-handoffs", TRUE, NULL);

			// Setup the callback
			if ( ! connectVideoHandoffSignal() )
			{
				log_error("Unable to connect the video 'handoff' signal handler");
				// TODO: what to do in this case ?
			}

			// Setup the input capsfilter
			ns->videoinputcaps = gst_element_factory_make ("capsfilter", NULL);
			if ( ! ns->videoinputcaps )
			{
				log_error("Unable to create videoinputcaps 'capsfilter' element");
				// TODO: what to do in this case ?
			}

			uint32_t fps = ns->m_parser->videoFrameRate(); 

			GstCaps* videonincaps;
			if (videoInfo->codec == VIDEO_CODEC_H263) {
				videonincaps = gst_caps_new_simple ("video/x-flash-video",
					"width", G_TYPE_INT, videoInfo->width,
					"height", G_TYPE_INT, videoInfo->height,
					"framerate", GST_TYPE_FRACTION, fps, 1,
					"flvversion", G_TYPE_INT, 1,
					NULL);
				ns->videodecoder = gst_element_factory_make ("ffdec_flv", NULL);
				if ( ! ns->videodecoder )
				{
					log_error("Unable to create videodecoder 'ffdec_flv' element");
					// TODO: what to do in this case ?
				}

				// Check if the element was correctly created
				if (!ns->videodecoder) {
					log_error(_("A gstreamer flashvideo (h.263) decoder element could not be created.  You probably need to install gst-ffmpeg."));
					return;
				}

			} else if (videoInfo->codec == VIDEO_CODEC_VP6) {
				videonincaps = gst_caps_new_simple ("video/x-vp6-flash",
					"width", G_TYPE_INT, 320, // We don't yet have a size extract for this codec, so we guess...
					"height", G_TYPE_INT, 240,
					"framerate", GST_TYPE_FRACTION, fps, 1,
					NULL);
				ns->videodecoder = gst_element_factory_make ("ffdec_vp6f", NULL);
				if ( ! ns->videodecoder )
				{
					log_error("Unable to create videodecoder 'ffdec_vp6f' element");
					// TODO: what to do in this case ?
				}

				// Check if the element was correctly created
				if (!ns->videodecoder) {
					log_error(_("A gstreamer flashvideo (VP6) decoder element could not be created! You probably need to install gst-ffmpeg."));
					return;
				}

			} else if (videoInfo->codec == VIDEO_CODEC_SCREENVIDEO) {
				videonincaps = gst_caps_new_simple ("video/x-flash-screen",
					"width", G_TYPE_INT, 320, // We don't yet have a size extract for this codec, so we guess...
					"height", G_TYPE_INT, 240,
					"framerate", GST_TYPE_FRACTION, fps, 1,
					NULL);
				ns->videodecoder = gst_element_factory_make ("ffdec_flashsv", NULL);

				// Check if the element was correctly created
				if (!ns->videodecoder) {
					log_error(_("A gstreamer flashvideo (ScreenVideo) decoder element could not be created! You probably need to install gst-ffmpeg."));
					return;
				}

			} else {
				log_error(_("Unsupported video codec %d"),
					  videoInfo->codec);
				return;
			}

			g_object_set (G_OBJECT (ns->videoinputcaps), "caps", videonincaps, NULL);
			gst_caps_unref (videonincaps);

		}

		FLVAudioInfo* audioInfo = ns->m_parser->getAudioInfo();
		if (!audioInfo) sound = false;

		if (sound) {
			ns->audiosource = gst_element_factory_make ("fakesrc", NULL);
			if ( ! ns->audiosource )
			{
				log_error("Unable to create audiosource 'fakesrc' element");
			}

			// setup fake source
			g_object_set (G_OBJECT (ns->audiosource),
						"sizetype", 2, "can-activate-pull", FALSE, "signal-handoffs", TRUE, NULL);

			// Setup the callback
			if ( ! connectAudioHandoffSignal() )
			{
				log_error("Unable to connect the audio 'handoff' signal handler");
				// TODO: what to do in this case ?
			}


			if (audioInfo->codec == AUDIO_CODEC_MP3) { 

				ns->audiodecoder = gst_element_factory_make ("mad", NULL);
				if ( ! ns->audiodecoder )
				{
					ns->audiodecoder = gst_element_factory_make ("flump3dec", NULL);
					// Check if the element was correctly created
					if (!ns->audiodecoder)
					{
						log_error(_("A gstreamer mp3-decoder element could not be created! You probably need to install a mp3-decoder plugin like gstreamer0.10-mad or gstreamer0.10-fluendo-mp3."));
						return;
					}
				}



				// Set the info about the stream so that gstreamer knows what it is.
				ns->audioinputcaps = gst_element_factory_make ("capsfilter", NULL);
				if (!ns->audioinputcaps)
				{
					log_error("Unable to create audioinputcaps 'capsfilter' element");
					// TODO: what to do in this case ?
				}

				GstCaps* audioincaps = gst_caps_new_simple ("audio/mpeg",
					"mpegversion", G_TYPE_INT, 1,
					"layer", G_TYPE_INT, 3,
					"rate", G_TYPE_INT, audioInfo->sampleRate,
					"channels", G_TYPE_INT, audioInfo->stereo ? 2 : 1, NULL);
				g_object_set (G_OBJECT (ns->audioinputcaps), "caps", audioincaps, NULL);
				gst_caps_unref (audioincaps);
			} else {
				log_error(_("Unsupported audio codec %d"),
					  audioInfo->codec);
				return;
			}
		}
	}

	// setup the decoder with callback, but only if we are not decoding a FLV
	if (!ns->m_isFLV) {
		ns->decoder = gst_element_factory_make ("decodebin", NULL);
		if (!ns->decoder)
		{
			log_error("Unable to create decoder 'decodebin' element");
			// TODO: what to do in this case ?
		}
		g_signal_connect (ns->decoder, "new-decoded-pad", G_CALLBACK (NetStreamGst::callback_newpad), ns);
	}

	if (video) {
		// setup the video colorspaceconverter converter
		ns->colorspace = gst_element_factory_make ("ffmpegcolorspace", NULL);
		if (!ns->colorspace)
		{
			log_error("Unable to create colorspace 'ffmpegcolorspace' element");
			// TODO: what to do in this case ?
		}

		// Setup the capsfilter which demands either YUV or RGB videoframe format
		ns->videocaps = gst_element_factory_make ("capsfilter", NULL);
		if (!ns->videocaps)
		{
			log_error("Unable to create videocaps 'capsfilter' element");
			// TODO: what to do in this case ?
		}

		GstCaps* videooutcaps;
		if (ns->m_videoFrameFormat == render::YUV) {
			videooutcaps = gst_caps_new_simple ("video/x-raw-yuv", NULL);
		} else {
			videooutcaps = gst_caps_new_simple ("video/x-raw-rgb", NULL);
		}
		g_object_set (G_OBJECT (ns->videocaps), "caps", videooutcaps, NULL);
		gst_caps_unref (videooutcaps);

		// Setup the videorate element which makes sure the frames are delivered on time.
		ns->videorate = gst_element_factory_make ("videorate", NULL);
		if (!ns->videorate)
		{
			log_error("Unable to create videorate 'videorate' element");
			// TODO: what to do in this case ?
		}

		// setup the videosink with callback
		ns->videosink = gst_element_factory_make ("fakesink", NULL);
		if (!ns->videosink)
		{
			log_error("Unable to create videosink 'fakesink' element");
			// TODO: what to do in this case ?
		}

		g_object_set (G_OBJECT (ns->videosink), "signal-handoffs", TRUE, "sync", TRUE, NULL);
		// TODO: use connectVideoSincCallback()
		g_signal_connect (ns->videosink, "handoff", G_CALLBACK (NetStreamGst::callback_output), ns);
	}

	if (ns->m_isFLV) {
		if (video && (!ns->videosource || !ns->videoinputcaps)) {
			log_error(_("Gstreamer source element(s) for video movie handling could not be created, you probably need to install gstreamer0.10-core for fakesrc and capsfilter support."));
			return;
		}
		if (sound && (!ns->audiosource || !ns->audioinputcaps)) {
			log_error(_("Gstreamer source element(s) for audio movie handling could not be created, you probably need to install gstreamer0.10-core for fakesrc and capsfilter support."));
			return;
		}

	} else {
		if (!ns->decoder || !ns->source) {
			log_error(_("Gstreamer element(s) for movie handling could not be created, you probably need to install gstreamer0.10-base for decodebin support."));
			return;
		}
	}

	if (video && (!ns->colorspace || !ns->videocaps || !ns->videorate || !ns->videosink)) {
		log_error(_("Gstreamer element(s) for video movie handling could not be created, you probably need to install gstreamer0.10-base for ffmpegcolorspace and videorate support."));
		return;
	}

	// put it all in the pipeline and link the elements
	if (!ns->m_isFLV) { 
		if (sound) gst_bin_add_many (GST_BIN (ns->pipeline),ns->audiosink, ns->audioconv, ns->volume, NULL);
		if (video) gst_bin_add_many (GST_BIN (ns->pipeline), ns->source, ns->decoder, ns->colorspace, 
					ns->videosink, ns->videorate, ns->videocaps, NULL);

		if (video || sound) gst_element_link(ns->source, ns->decoder);
		if (video) gst_element_link_many(ns->colorspace, ns->videocaps, ns->videorate, ns->videosink, NULL);
		if (sound) gst_element_link_many(ns->audioconv, ns->volume, ns->audiosink, NULL);

	} else {
		if (video) gst_bin_add_many (GST_BIN (ns->pipeline), ns->videosource, ns->videoinputcaps, ns->videodecoder, ns->colorspace, ns->videocaps, ns->videorate, ns->videosink, NULL);
		if (sound) gst_bin_add_many (GST_BIN (ns->pipeline), ns->audiosource, ns->audioinputcaps, ns->audiodecoder, ns->audioconv, ns->volume, ns->audiosink, NULL);

		if (sound) gst_element_link_many(ns->audiosource, ns->audioinputcaps, ns->audiodecoder, ns->audioconv, ns->volume, ns->audiosink, NULL);
		if (video) gst_element_link_many(ns->videosource, ns->videoinputcaps, ns->videodecoder, ns->colorspace, ns->videocaps, ns->videorate, ns->videosink, NULL);

	}

	// start playing	
	if (!ns->m_isFLV)
	{
		if (video || sound)
		{
			// TODO: should call playPipeline() ?
			gst_element_set_state (GST_ELEMENT (ns->pipeline), GST_STATE_PLAYING);
		}
	}
	else
	{
		if (video || sound)
		{
			log_msg("Pausing pipeline on startPlayback");
			if ( ! pausePipeline(true) )
			{
				log_error("Could not pause pipeline");
			}
		}
	}

	ns->setStatus(playStart);
	return;
}

void
NetStreamGst::seek(double pos)
{

	if (!pipeline) return;

	if (m_isFLV) {
		uint32_t newpos = m_parser->seek(static_cast<uint32_t>(pos*1000));
		GstClock* clock = GST_ELEMENT_CLOCK(pipeline);
		uint64_t currenttime = gst_clock_get_time (clock);
		gst_object_unref(clock);
		
		m_clock_offset = (currenttime / GST_MSECOND) - newpos;

	} else {
		if (!gst_element_seek (pipeline, 1.0, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH,
			GST_SEEK_TYPE_SET, GST_SECOND * static_cast<long>(pos),
			GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE)) {
			log_error("Gstreamer seek failed");
			setStatus(invalidTime);
			return;
		}
	}
	setStatus(seekNotify);
}

void
NetStreamGst::advance()
{
	// Check if we should start the playback when a certain amount is buffered
	if (m_isFLV && m_pause && m_go && m_start_onbuffer && m_parser && m_parser->isTimeLoaded(m_bufferTime))
	{
		if ( ! playPipeline() )
		{
			log_error("Could not enable pipeline");
			return;
		}
	}

	// If we're out of data, but still not done loading, pause playback,
	// or stop if loading is complete
	if (m_pausePlayback)
	{
		log_debug("Playback paused (out of data?)");

		m_pausePlayback = false;
		if (_netCon->loadCompleted())
		{
			log_debug("Load completed, setting playStop status and shutting down pipeline");
			setStatus(playStop);

			// Drop gstreamer pipeline so callbacks are not called again
			if ( ! disablePipeline() )
			{
				// the state change failed
				log_error("Could not interrupt pipeline!");

				// @@ eh.. what to do then ?
			}

			m_go = false;
			m_clock_offset = 0;
		}
		else
		{
			log_msg("Pausing pipeline on ::advance() [ loadCompleted returned false ]");
			if ( !pausePipeline(true) )
			{
				log_error("Could not pause pipeline");
			}

			/// TODO: shouldn't we check 'ret' value here !!??

			int64_t pos;
			GstState current, pending;
			GstStateChangeReturn ret;
			GstFormat fmt = GST_FORMAT_TIME;

			ret = gst_element_get_state (GST_ELEMENT (pipeline), &current, &pending, 0);
			if (current != GST_STATE_NULL && gst_element_query_position (pipeline, &fmt, &pos)) {
				pos = pos / 1000000;
			} else {
				pos = 0;
			}
			// Buffer a second before continuing
			m_bufferTime = pos + 1000;
		}
	}

	// Check if there are any new status messages, and if we should
	// pass them to a event handler
	processStatusNotifications();
}

int64_t
NetStreamGst::time()
{

	if (!pipeline) return 0;

	GstFormat fmt = GST_FORMAT_TIME;
	int64_t pos;
	GstStateChangeReturn ret;
	GstState current, pending;

	ret = gst_element_get_state (GST_ELEMENT (pipeline), &current, &pending, 0);

	if (current != GST_STATE_NULL && gst_element_query_position (pipeline, &fmt, &pos)) {
		pos = pos / 1000000000;

		return pos - m_clock_offset/1000;
	} else {
		return 0;
	}
}

// Gstreamer callback function
int 
NetStreamGst::readPacket(void* opaque, char* buf, int buf_size){

	NetStreamGst* ns = static_cast<NetStreamGst*>(opaque);

	boost::intrusive_ptr<NetConnection> nc = ns->_netCon;
	size_t ret = nc->read(static_cast<void*>(buf), buf_size);
	ns->inputPos += ret;

	return ret;

}

// Gstreamer callback function
int 
NetStreamGst::seekMedia(void *opaque, int offset, int whence){

	NetStreamGst* ns = static_cast<NetStreamGst*>(opaque);
	boost::intrusive_ptr<NetConnection> nc = ns->_netCon;

	bool ret;

	// Offset is absolute new position in the file
	if (whence == SEEK_SET) {
		ret = nc->seek(offset);
		if (!ret) return -1;
		ns->inputPos = offset;

	// New position is offset + old position
	} else if (whence == SEEK_CUR) {
		ret = nc->seek(ns->inputPos + offset);
		if (!ret) return -1;
		ns->inputPos = ns->inputPos + offset;

	// 	// New position is offset + end of file
	} else if (whence == SEEK_END) {
		// This is (most likely) a streamed file, so we can't seek to the end!
		// Instead we seek to 50.000 bytes... seems to work fine...
		ret = nc->seek(50000);
		ns->inputPos = 50000;
	}
	return ns->inputPos;
}

/*private*/
bool
NetStreamGst::disconnectVideoHandoffSignal()
{
	if (videosource && _handoffVideoSigHandler )
	{
		log_debug("Disconnecting video handoff signal %lu", _handoffAudioSigHandler);
		g_signal_handler_disconnect(videosource, _handoffVideoSigHandler);
		_handoffVideoSigHandler = 0;
	}

	// TODO: check return code from previous call !
	return true;
}

/*private*/
bool
NetStreamGst::disconnectAudioHandoffSignal()
{
	if ( audiosource && _handoffAudioSigHandler );
	{
		log_debug("Disconnecting audio handoff signal %lu", _handoffAudioSigHandler);
		g_signal_handler_disconnect(audiosource, _handoffAudioSigHandler);
		_handoffAudioSigHandler = 0;
	}

	// TODO: check return code from previous call !
	return true;
}

/*private*/
bool
NetStreamGst::connectVideoHandoffSignal()
{
	log_debug("Connecting video handoff signal");

	assert(_handoffVideoSigHandler == 0);

	_handoffVideoSigHandler = g_signal_connect (videosource, "handoff",
			G_CALLBACK (NetStreamGst::video_callback_handoff), this);
	log_debug("New _handoffVideoSigHandler id : %lu", _handoffVideoSigHandler);

	assert(_handoffVideoSigHandler != 0);

	// TODO: check return code from previous call !
	return true;
}

/*private*/
bool
NetStreamGst::connectAudioHandoffSignal()
{
	log_debug("Connecting audio handoff signal");

	assert(_handoffAudioSigHandler == 0);

	_handoffAudioSigHandler = g_signal_connect (audiosource, "handoff",
			G_CALLBACK (NetStreamGst::audio_callback_handoff), this);

	log_debug("New _handoffAudioSigHandler id : %lu", _handoffAudioSigHandler);

	assert(_handoffAudioSigHandler != 0);

	// TODO: check return code from previous call !
	return true;
}

/*private*/
bool
NetStreamGst::disablePipeline()
{
	boost::mutex::scoped_lock lock(_pipelineMutex);

	// Disconnect the handoff handler
	// TODO: VERIFY THE SIGNAL WILL BE RESTORED WHEN NEEDED !!
	if ( videosource ) disconnectVideoHandoffSignal();
	if ( audiosource ) disconnectAudioHandoffSignal();

	// Drop gstreamer pipeline so callbacks are not called again
	GstStateChangeReturn ret =  gst_element_set_state (GST_ELEMENT (pipeline), GST_STATE_NULL);
	if ( ret == GST_STATE_CHANGE_FAILURE )
	{
		// the state change failed
		log_error("Could not interrupt pipeline!");
		return false;

		// @@ eh.. what to do then ?
	}
	else if ( ret == GST_STATE_CHANGE_SUCCESS )
	{
		// the state change succeeded
		log_debug("State change to NULL successful");

		// just make sure
		GstState current, pending;
		ret = gst_element_get_state (GST_ELEMENT (pipeline), &current, &pending, 0);
		if (current != GST_STATE_NULL )
		{
			log_error("State change to NULL NOT confirmed !");
			return false;
		}
	}
	else if ( ret == GST_STATE_CHANGE_ASYNC )
	{
		// The element will perform the remainder of the state change
		// asynchronously in another thread
		// We'll wait for it...

		log_debug("State change to NULL will be asynchronous.. waiting for it");

		GstState current, pending;
		do {
			ret = gst_element_get_state (GST_ELEMENT (pipeline), &current, &pending, GST_SECOND*1); 

			log_debug(" NULL state change still not completed after X seconds");

		} while ( ret == GST_STATE_CHANGE_ASYNC && current != GST_STATE_NULL );

		if ( ret == GST_STATE_CHANGE_SUCCESS )
		{
			assert ( current == GST_STATE_NULL );
			log_debug(" Async NULL completed successfully");
		}
		else if ( ret == GST_STATE_CHANGE_FAILURE )
		{
			assert ( current != GST_STATE_NULL );
			log_debug(" Async NULL completed failing.");
			return false;
		}
		else abort();


	}
	else if ( ret == GST_STATE_CHANGE_NO_PREROLL )
	{
		// the state change succeeded but the element
		// cannot produce data in PAUSED.
		// This typically happens with live sources.
		log_debug("State change succeeded but the element cannot produce data in PAUSED");

		// @@ what to do in this case ?
	}
	else
	{
		log_error("Unknown return code from gst_element_set_state");
		return false;
	}

	return true;

}

/*private*/
bool
NetStreamGst::playPipeline()
{
	boost::mutex::scoped_lock lock(_pipelineMutex);

	log_debug("Setting status to bufferFull and enabling pipeline");

	if ( videosource && ! _handoffVideoSigHandler )
	{
		connectVideoHandoffSignal();
	}

	if ( audiosource && ! _handoffAudioSigHandler )
	{
		connectAudioHandoffSignal();
	}

	if (!m_go) { 
		setStatus(playStart);
		m_go = true;
	}
	m_pause = false;
	m_start_onbuffer = false;


	// Set pipeline to PLAYING state
	GstStateChangeReturn ret =  gst_element_set_state (GST_ELEMENT (pipeline), GST_STATE_PLAYING);
	if ( ret == GST_STATE_CHANGE_FAILURE )
	{
		// the state change failed
		log_error("Could not set pipeline state to PLAYING!");
		return false;

		// @@ eh.. what to do then ?
	}
	else if ( ret == GST_STATE_CHANGE_SUCCESS )
	{
		// the state change succeeded
		log_debug("State change to PLAYING successful");

		// just make sure
		GstState current, pending;
		ret = gst_element_get_state (GST_ELEMENT (pipeline), &current, &pending, 0);
		if (current != GST_STATE_PLAYING )
		{
			log_error("State change to PLAYING NOT confirmed !");
			return false;
		}
	}
	else if ( ret == GST_STATE_CHANGE_ASYNC )
	{
		// The element will perform the remainder of the state change
		// asynchronously in another thread
		// We'll wait for it...

		log_debug("State change to play will be asynchronous.. waiting for it");

		GstState current, pending;
		do {
			ret = gst_element_get_state (GST_ELEMENT (pipeline), &current, &pending, GST_SECOND*1); 

			log_debug(" Play still not completed after X seconds");

		} while ( ret == GST_STATE_CHANGE_ASYNC && current != GST_STATE_PLAYING );

		if ( ret == GST_STATE_CHANGE_SUCCESS )
		{
			assert ( current == GST_STATE_PLAYING );
			log_debug(" Async play completed successfully");
		}
		else if ( ret == GST_STATE_CHANGE_FAILURE )
		{
			assert ( current != GST_STATE_PLAYING );
			log_debug(" Async play completed failing.");
			return false;
		}
		else abort();

	}
	else if ( ret == GST_STATE_CHANGE_NO_PREROLL )
	{
		// the state change succeeded but the element
		// cannot produce data in PAUSED.
		// This typically happens with live sources.
		log_debug("State change succeeded but the element cannot produce data in PAUSED");

		// @@ what to do in this case ?
	}
	else
	{
		log_error("Unknown return code from gst_element_set_state");
		return false;
	}

	return true;

}

/*private*/
bool
NetStreamGst::pausePipeline(bool startOnBuffer)
{
	boost::mutex::scoped_lock lock(_pipelineMutex);

	log_debug("Setting pipeline state to PAUSE");

	if ( ! m_go )
	{
		log_debug("Won't set the pipeline to PAUSE state if m_go is false");
		return false;
	}


	if ( videosource && ! _handoffVideoSigHandler )
	{
		connectVideoHandoffSignal();
	}

	if ( audiosource && ! _handoffAudioSigHandler )
	{
		connectAudioHandoffSignal();
	}

	m_pause = true;
	m_start_onbuffer = startOnBuffer;

	// Set pipeline to PAUSE state
	GstStateChangeReturn ret =  gst_element_set_state (GST_ELEMENT (pipeline), GST_STATE_PAUSED);
	if ( ret == GST_STATE_CHANGE_FAILURE )
	{
		// the state change failed
		log_error("Could not interrupt pipeline!");
		return false;
	}
	else if ( ret == GST_STATE_CHANGE_SUCCESS )
	{
		// the state change succeeded
		log_debug("State change to PAUSE successful");

		// just make sure
		GstState current, pending;
		ret = gst_element_get_state (GST_ELEMENT (pipeline), &current, &pending, 0);
		if (current != GST_STATE_PAUSED )
		{
			log_error("State change to PLAYING NOT confirmed !");
			return false;
		}
	}
	else if ( ret == GST_STATE_CHANGE_ASYNC )
	{
		// The element will perform the remainder of the state change
		// asynchronously in another thread
		// We'll wait for it...

		log_debug("State change to paused will be asynchronous.. waiting for it");

		GstState current, pending;
		do {
			ret = gst_element_get_state (GST_ELEMENT (pipeline), &current, &pending, GST_SECOND*1); 

			log_debug(" Pause still not completed after X seconds");

		} while ( ret == GST_STATE_CHANGE_ASYNC && current != GST_STATE_PAUSED );

		if ( ret == GST_STATE_CHANGE_SUCCESS )
		{
			assert ( current == GST_STATE_PAUSED );
			log_debug(" Async pause completed successfully");
		}
		else if ( ret == GST_STATE_CHANGE_FAILURE )
		{
			assert ( current != GST_STATE_PAUSED );
			log_debug(" Async pause completed failing.");
			return false;
		}
		else abort();

	}
	else if ( ret == GST_STATE_CHANGE_NO_PREROLL )
	{
		// the state change succeeded but the element
		// cannot produce data in PAUSED.
		// This typically happens with live sources.
		log_debug("State change succeeded but the element cannot produce data in PAUSED");

		// @@ what to do in this case ?
	}
	else
	{
		log_error("Unknown return code from gst_element_set_state");
		return false;
	}

	return true;

}


} // gnash namespcae

#endif // SOUND_GST
