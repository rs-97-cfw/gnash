// BitmapMovieDefinition.cpp:  Bitmap movie definition, for Gnash.
// 
//   Copyright (C) 2007, 2008, 2009 Free Software Foundation, Inc.
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
//

#include "smart_ptr.h" // GNASH_USE_GC
#include "BitmapMovie.h"
#include "BitmapMovieDefinition.h"
#include "fill_style.h"
#include "Geometry.h" // for class path and class edge
#include "render.h" // for ::display
#include "GnashImage.h"
#include "log.h"
#include "Shape.h"

namespace gnash {

Movie*
BitmapMovieDefinition::create_Movie(DisplayObject* parent)
{
    // It's possible for this to fail.
    if (!_bitmap.get()) return 0;

	// Set its boundaries
	_shape.setBounds(_framesize);

	// Add the bitmap fill style (fill style 0)

	SWFMatrix mat;
	mat.set_scale(1.0/20, 1.0/20); // bitmap fills get SWFMatrix reversed
	fill_style bmFill(_bitmap.get(), mat);
	const size_t fillLeft = _shape.add_fill_style(bmFill);

	// Define a rectangle filled with the bitmap style

	// We use one twip for each pixel in the image
	// The DisplayObject will be scaled * 20
	// when placed in BitmapMovie's DisplayList
	boost::int32_t w = _framesize.width(); 
	boost::int32_t h = _framesize.height(); 

	IF_VERBOSE_PARSE(
	    log_parse(_("Creating a shape_definition wrapping a %g x %g bitmap"),
            w, h);
	);

	Path bmPath(w, h, fillLeft, 0, 0, false);
	bmPath.drawLineTo(w, 0);
	bmPath.drawLineTo(0, 0);
	bmPath.drawLineTo(0, h);
	bmPath.drawLineTo(w, h);

	// Add the path 

	_shape.add_path(bmPath);

    return new BitmapMovie(this, parent);
}

DisplayObject*
BitmapMovieDefinition::createDisplayObject(DisplayObject* /*parent*/,
        int /*id*/)
{
    return 0;
}

BitmapMovieDefinition::BitmapMovieDefinition(std::auto_ptr<GnashImage> image,
		const std::string& url)
	:
	_version(6),
	// GnashImage size is in pixels
	_framesize(0, 0, image->width()*20, image->height()*20),
	_framecount(1),
	_framerate(12),
	_url(url),
	_bytesTotal(image->size()),
	_bitmap(render::createBitmapInfo(image))
{
}

#ifdef GNASH_USE_GC
void
BitmapMovieDefinition::markReachableResources() const
{
	if (_bitmap.get()) _bitmap->setReachable();
}
#endif // GNASH_USE_GC

} // namespace gnash
