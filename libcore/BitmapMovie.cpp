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

#include "BitmapMovie.h"
#include "BitmapMovieDefinition.h"
#include "fill_style.h"
#include "Geometry.h" // for class path and class edge
#include "render.h" // for ::display

namespace gnash {

BitmapMovie::BitmapMovie(BitmapMovieDefinition* def, DisplayObject* parent)
	:
	Movie(def, parent),
    _def(def)
{
}

void
BitmapMovie::display()
{
    _def->shape().display(*this);
    GNASH_REPORT_FUNCTION;
}

std::auto_ptr<GnashImage>
BitmapMovie::drawToBitmap(const SWFMatrix& /* mat */, const cxform& /* cx */,
             DisplayObject::BlendMode /* bm */, const rect& /* clipRect */,
             bool /* smooth */)
{
    return std::auto_ptr<GnashImage>();
}

} // namespace gnash

