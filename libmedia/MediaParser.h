// MediaParser.h: Base class for media parsers
// 
//   Copyright (C) 2007, 2008 Free Software Foundation, Inc.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
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


#ifndef __MEDIAPARSER_H__
#define __MEDIAPARSER_H__

#ifdef HAVE_CONFIG_H
#include "gnashconfig.h"
#endif

#include <boost/scoped_array.hpp>
#include <memory>

#include "tu_file.h" // for inlines

namespace gnash {
namespace media {

/// Video frame types
enum videoFrameType
{
	/// Key frames
	KEY_FRAME = 1,

	/// Interlaced frames
	INTER_FRAME = 2,

	/// Disposable interlaced frames
	DIS_INTER_FRAME = 3
};

/// The type of the codec id passed in the AudioInfo or VideoInfo class
enum codecType
{
	/// The internal flash codec ids
	FLASH,

	/// Ffmpegs codecs ids
	//
	/// TODO: make this media-handler agnostic
	///
	FFMPEG
};

/// Video codec ids as defined in flash
enum videoCodecType
{
	/// H263/SVQ3 video codec
	VIDEO_CODEC_H263 = 2,

	/// Screenvideo codec
	VIDEO_CODEC_SCREENVIDEO = 3,

	/// On2 VP6 video codec
	VIDEO_CODEC_VP6 = 4,

	/// On2 VP6 Alpha video codec
	VIDEO_CODEC_VP6A = 5,

	/// Screenvideo2 codec
	VIDEO_CODEC_SCREENVIDEO2 = 6
};

/// Audio codec ids as defined in flash
enum audioCodecType
{
	/// Raw format.  Useful for 8-bit sounds???
	AUDIO_CODEC_RAW = 0,	

	/// ADPCM format, flash's ADPCM is a bit different for normal ADPCM
	AUDIO_CODEC_ADPCM = 1,

	/// Mp3 format
	AUDIO_CODEC_MP3 = 2,

	/// 16 bits/sample, little-endian
	AUDIO_CODEC_UNCOMPRESSED = 3,

	/// Proprietary simple format
	AUDIO_CODEC_NELLYMOSER_8HZ_MONO = 5,

	/// Proprietary simple format
	AUDIO_CODEC_NELLYMOSER = 6
};

/// \brief
/// The AudioInfo class contains information about the audiostream
/// in the file being parsed. The information stored is codec-id,
/// samplerate, samplesize, stereo, duration and codec-type.
/// timestamp,
class AudioInfo
{
public:
	AudioInfo(int codeci, boost::uint16_t sampleRatei, boost::uint16_t sampleSizei, bool stereoi, boost::uint64_t durationi, codecType typei)
		: codec(codeci),
		sampleRate(sampleRatei),
		sampleSize(sampleSizei),
		stereo(stereoi),
		duration(durationi),
		type(typei)
		{
		}

	int codec;
	boost::uint16_t sampleRate;
	boost::uint16_t sampleSize;
	bool stereo;
	boost::uint64_t duration;
	codecType type;
};

/// \brief
/// The VideoInfo class contains information about the videostream
/// in the file being parsed. The information stored is codec-id,
/// width, height, framerate, duration and codec-type.
/// timestamp,
class VideoInfo
{
public:
	VideoInfo(int codeci, boost::uint16_t widthi, boost::uint16_t heighti, boost::uint16_t frameRatei, boost::uint64_t durationi, codecType typei)
		: codec(codeci),
		width(widthi),
		height(heighti),
		frameRate(frameRatei),
		duration(durationi),
		type(typei)
	{
	}

	int codec;
	boost::uint16_t width;
	boost::uint16_t height;
	boost::uint16_t frameRate;
	boost::uint64_t duration;
	codecType type;
};

/// An encoded video frame
class EncodedVideoFrame
{
public:

	/// Create an encoded video frame
	//
	/// @param data
	///	Data buffer, ownership transferred
	///
	/// @param size
	///	Size of the data buffer
	///
	/// @param frameNum
	///	Frame number.
	///
	/// @param type
	/// 	Video frame type
	///
	/// @param timestamp
	///	Presentation timestamp, in milliseconds.
	///
	EncodedVideoFrame(boost::uint8_t* data, boost::uint32_t size,
			unsigned int frameNum,
			boost::uint64_t timestamp=0)
		:
		_size(size),
		_data(data),
		_frameNum(frameNum),
		_timestamp(timestamp)
	{}

	/// Return pointer to actual data. Ownership retained by this class.
	const boost::uint8_t* data() const { return _data.get(); }

	/// Return size of data buffer.
	boost::uint32_t dataSize() const { return _size; }

	/// Return video frame presentation timestamp
	boost::uint64_t timestamp() const { return _timestamp; }

	/// Return video frame number
	unsigned frameNum() const { return _frameNum; }

private:

	boost::uint32_t _size;
	boost::scoped_array<boost::uint8_t> _data;
	unsigned int _frameNum;
	boost::uint64_t _timestamp;
};

/// An encoded audio frame
class EncodedAudioFrame
{
public:
	boost::uint32_t dataSize;
	boost::scoped_array<boost::uint8_t> data;
	boost::uint64_t timestamp;
};

/// The MediaParser class provides cursor-based access to encoded media frames 
//
/// Cursor-based access allow seeking as close as possible to a specified time
/// and fetching frames from there on, sequentially.
/// See seek(), nextVideoFrame(), nextAudioFrame() 
///
/// Input is received from a tu_file object.
///
class MediaParser
{
public:

	MediaParser(std::auto_ptr<tu_file> stream)
		:
		_isAudioMp3(false),
		_isAudioNellymoser(false),
		_stream(stream),
		_parsingComplete(false)
	{}

	// Classes with virtual methods (virtual classes)
	// must have a virtual destructor, or the destructors
	// of subclasses will never be invoked, tipically resulting
	// in memory leaks..
	//
	virtual ~MediaParser() {};

	/// Returns the "bufferlength", meaning the difference between the
	/// current frames timestamp and the timestamp of the last parseable
	/// frame. Returns the difference in milliseconds.
	//
	virtual boost::uint32_t getBufferLength()=0;

	/// Get timestamp of the video frame which would be returned on nextVideoFrame
	//
	/// @return false if there no video frame left
	///         (either none or no more)
	///
	virtual bool nextVideoFrameTimestamp(boost::uint64_t& ts)=0;

	/// Returns the next video frame in the parsed buffer, advancing video cursor.
	//
	/// If no frame has been played before the first frame is returned.
	/// If there is no more frames in the parsed buffer NULL is returned.
	/// you can check with parsingCompleted() to know wheter this is due to 
	/// EOF reached.
	///
	virtual std::auto_ptr<EncodedVideoFrame> nextVideoFrame()=0;

	/// Get timestamp of the audio frame which would be returned on nextAudioFrame
	//
	/// @return false if there no video frame left
	///         (either none or no more)
	///
	virtual bool nextAudioFrameTimestamp(boost::uint64_t& ts)=0;

	/// Returns the next audio frame in the parsed buffer, advancing audio cursor.
	//
	/// If no frame has been played before the first frame is returned.
	/// If there is no more frames in the parsed buffer NULL is returned.
	/// you can check with parsingCompleted() to know wheter this is due to 
	/// EOF reached.
	///
	virtual std::auto_ptr<EncodedAudioFrame> nextAudioFrame()=0;

	/// Is the input MP3?
	//
	/// @return if the input audio is MP3
	///
	bool isAudioMp3() { return _isAudioMp3; }

	/// Is the input Nellymoser?
	//
	/// @return if the input audio is Nellymoser
	///
	bool isAudioNellymoser() { return _isAudioNellymoser; }

	/// Setup the parser
	//
	/// @return whether we'll be able to parse the file.
	///
	virtual bool setupParser() { return false; }

	/// Returns a VideoInfo class about the videostream
	//
	/// @return a VideoInfo class about the videostream,
	///         or zero if stream contains no video
	///
	virtual VideoInfo* getVideoInfo() { return 0; }

	/// Returns a AudioInfo class about the audiostream
	//
	/// @return a AudioInfo class about the audiostream,
	///         or zero if stream contains no audio
	///
	virtual AudioInfo* getAudioInfo() { return 0; }

	/// Seeks to the closest possible position the given position.
	//
	/// Valid seekable position are constrained by key-frames when
	/// video data is available. Actual seek position should be always
	/// less of equal the requested one.
	///
	/// @return the position the seek reached
	///
	virtual boost::uint32_t seek(boost::uint32_t) { return 0; }

	/// Returns the framedelay from the last to the current
	/// audioframe in milliseconds. This is used for framerate.
	//
	/// @return the diff between the current and last frame
	///
	virtual boost::uint32_t audioFrameDelay() { return 0; }

	/// Returns the framedelay from the last to the current
	/// videoframe in milliseconds. 
	//
	/// @return the diff between the current and last frame
	///
	virtual boost::uint32_t videoFrameDelay() { return 0; }

	/// Returns the framerate of the video
	//
	/// @return the framerate of the video
	///
	virtual boost::uint16_t videoFrameRate() { return 0; }

	/// Returns the last parsed position in the file in bytes
	virtual boost::uint32_t getLastParsedPos() { return 0; }

	/// Parse next input chunk
	//
	/// Returns true if something was parsed, false otherwise.
	/// See parsingCompleted().
	///
	virtual bool parseNextChunk() { return false; }

	/// Return true of parsing is completed
	//
	/// If this function returns true, any call to nextVideoFrame()
	/// or nextAudioFrame() will always return NULL
	///
	bool parsingCompleted() const { return _parsingComplete; }

	/// Return number of bytes parsed so far
	virtual boost::uint64_t getBytesLoaded() const { return 0; }

	/// Return total number of bytes in input
	boost::uint64_t getBytesTotal() const
	{
		return _stream->get_size();
	}

protected:

	/// Is the input audio MP3?
	bool _isAudioMp3;

	/// Is the input audio Nellymoser?
	bool _isAudioNellymoser;

	/// The stream used to access the file
	std::auto_ptr<tu_file> _stream;

	/// Whether the parsing is complete or not
	bool _parsingComplete;
};


} // gnash.media namespace 
} // namespace gnash

#endif // __MEDIAPARSER_H__
