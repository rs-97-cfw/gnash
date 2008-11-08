// 
//   Copyright (C) 2005, 2006, 2007, 2008 Free Software Foundation, Inc.
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

#ifndef GNASH_SWF_TEXTRECORD_H
#define GNASH_SWF_TEXTRECORD_H

#include "RGBA.h"
#include "swf.h"
#include <vector>

namespace gnash {
    class character;
    class movie_definition;
    class SWFStream;
    class SWFMatrix;
    class font;
}

namespace gnash {
namespace SWF {

/// Store a TextRecord.
//
/// This consists of style information and a number of glyphs.
/// This may be parsed from a SWFStream, or it can be constructed 
/// dynamically by TextField. A static TextField has fewer possible
/// properties than a dynamic one.
class TextRecord
{
public:

    struct GlyphEntry
    {
        int index;
        float advance;
    };

    TextRecord()
        :
        _color(0, 0, 0, 255),
        _textHeight(1.0f),
        _hasXOffset(false),
        _hasYOffset(false),
        _xOffset(0.0f),
        _yOffset(0.0f),
        _font(0),
        _underline(false)
    {}
          
    typedef std::vector<GlyphEntry> Glyphs;  
    Glyphs _glyphs;
    
    /// Read a TextRecord from the stream
    //
    /// @param in           The SWFStream to read from.
    /// @param m            The movie_definition containing this TextRecord.
    /// @param glyphBits    The number of bits per glyph
    /// @param advanceBits  The number of bits per advance
    /// @param tag          The tag type of this TextRecord. This must be
    ///                     DefineText or DefineText2
    /// @return             False if we have reached the end of the
    ///                     TextRecords, true if there are more to parse.
    bool read(SWFStream& in, movie_definition& m, int glyphBits,
            int advanceBits, tag_type tag);

    static void displayRecords(const SWFMatrix& this_mat, character* inst,
        const std::vector<SWF::TextRecord>& records, bool useEmbeddedGlyphs);

    const Glyphs& glyphs() const {
        return _glyphs;
    }

    void addGlyph(const GlyphEntry& ge, Glyphs::size_type num = 1) {
        _glyphs.insert(_glyphs.end(), num, ge);
    }

    void clearGlyphs(Glyphs::size_type num = 0) {
        if (!num) _glyphs.clear();
        else _glyphs.resize(_glyphs.size() - num);
    }

    // TODO: check font properly.
    void setFont(const font* f) {
        _font = f;
    }

    const font* getFont() const {
        return _font;
    }

    void setTextHeight(float height) {
        _textHeight = height;
    }

    float textHeight() const {
        return _textHeight;
    }

    bool hasXOffset() const {
        return _hasXOffset;
    }

    void setXOffset(float x) {
        _hasXOffset = true;
        _xOffset = x;
    }

    float xOffset() const {
        return _xOffset;
    }

    bool hasYOffset() const {
        return _hasYOffset;
    }

    void setYOffset(float y) {
        _hasYOffset = true;
        _yOffset = y;
    }

    float yOffset() const {
        return _yOffset;
    }

    void setColor(const rgba& color) {
        _color = color;
    }

    const rgba& color() const {
        return _color;
    }

    bool underline() const {
        return _underline;
    }

    void setUnderline(bool b) {
        _underline = b;
    }

private:

    /// The text color.
    rgba _color;

    /// The height of the text as a multiple of the font height.
    float _textHeight;

    /// Whether the TextRecord has an x offset.
    bool _hasXOffset;

    /// Whether the TextRecord has a y offset.
    bool _hasYOffset;

    /// The x offset of the text, by default 0.0
    float _xOffset;

    /// The y offset of the text, by default 0.0
    float _yOffset;

    /// The font associated with the TextRecord. Can be NULL.
    const font* _font;

    /// Whether the text should be underlined.
    bool _underline;
};

} // namespace SWF
} // namespace gnash


#endif