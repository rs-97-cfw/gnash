// IOChannel.cpp - a virtual IO channel, for Gnash
//
//   Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012
//   Free Software Foundation, Inc
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


#include "IOChannel.h"

namespace gnash
{

std::uint32_t
IOChannel::read_le32() 
{
    // read_byte() is std::uint8_t, so no masks with 0xff are required.
    std::uint32_t result = static_cast<std::uint32_t>(read_byte());
    result |= static_cast<std::uint32_t>(read_byte()) << 8;
    result |= static_cast<std::uint32_t>(read_byte()) << 16;
    result |= static_cast<std::uint32_t>(read_byte()) << 24;
    return(result);
}

std::uint16_t
IOChannel::read_le16()
{
    std::uint16_t result = static_cast<std::uint16_t>(read_byte());
    result |= static_cast<std::uint16_t>(read_byte()) << 8;
    return(result);
}

int
IOChannel::read_string(char* dst, int max_length) 
{
    int i = 0;
    while (i<max_length)
    {
        dst[i] = read_byte();
        if (dst[i]=='\0') return i;
        i++;
    }
    
    dst[max_length - 1] = '\0';    // force termination.
    
    return -1;
}

std::uint8_t
IOChannel::read_byte()
{
    std::uint8_t u;
    if ( read(&u, 1) == -1 )
    {
        throw IOException("Could not read a single byte from input");
    }
    return u;
}

std::streamsize
IOChannel::write(const void* /*src*/, std::streamsize /*num*/)
{
    throw IOException("This IOChannel implementation doesn't support output");
}

} // namespace gnash
