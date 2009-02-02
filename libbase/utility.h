// utility.h --	Various little utility functions, macros & typedefs.
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

#ifndef GNASH_UTILITY_H
#define GNASH_UTILITY_H

// HAVE_FINITE, HAVE_PTHREADS, WIN32, NDEBUG etc.
#ifdef HAVE_CONFIG_H
#include "gnashconfig.h"
#endif

#include <cassert>
#include <string>
#include <typeinfo>
#include <cmath>
#include <boost/cstdint.hpp>
#include <algorithm> // std::min, std::max
#include <limits>

#ifdef HAVE_PTHREADS
#include <pthread.h>
#endif

#if defined(__GNUC__) && __GNUC__ > 2
#  include <cxxabi.h>
#endif

#if defined(_WIN32) || defined(WIN32)
#ifndef NDEBUG

// On windows, replace ANSI assert with our own, for a less annoying
// debugging experience.
#ifndef __MINGW32__
#undef assert
#define assert(x)	if (!(x)) { __asm { int 3 } }
#endif
#endif // not NDEBUG
#endif // _WIN32


namespace gnash {

// Using a possible built-in pi constant M_PI, which is not in
// the C++ standard, has no conceivable advantage, so we will use this
// one. Make it as accurate as you like.
static const double PI = 3.14159265358979323846;

// Commonly-used inlined mathematical functions are defined in
// namespace gnash::utility so that it's clear where they
// come from.
namespace utility {

inline bool isFinite(double d)
{
#if defined(HAVE_FINITE) && !defined(HAVE_ISFINITE)
    return (finite(d));
#else
    // Put using namespace std; here if you have to
    // put it anywhere.
    using namespace std;
    return (isfinite(d));
#endif
}

inline double
infinite_to_zero(double x)
{
    return utility::isFinite(x) ? x : 0.0;
}

template <typename T>
inline T
clamp(T i, T min, T max)
{
	assert( min <= max );
	return std::max<T>(min, std::min<T>(i, max));
}

inline float
flerp(float a, float b, float f)
{
    return (b - a) * f + a;
}

inline int
frnd(float f) 
{
    return static_cast<int>(f + 0.5f);
}

} // end of namespace utility

/// Some of these functions could also be in the gnash::utility namespace,
/// although some are used so often that it would get annoying.

inline double
TWIPS_TO_PIXELS(int i) 
{ 
    return static_cast<double>(i / 20.0); 
}

// truncate when overflow occurs.
inline boost::int32_t
PIXELS_TO_TWIPS(double a) 
{ 

    // This truncates large values without relying on undefined behaviour.
    // For very large values of 'a' it is noticeably slower than the UB
    // version (due to fmod), but should always be legal behaviour. For
    // ordinary values (within ±1.07374e+08 pixels) it is comparable to
    // the UB version for speed. Because values outside the limit are
    // extremely rare, using this safe version has no implications for
    // performance under normal circumstances.
    static const double upperUnsignedLimit =
                std::numeric_limits<boost::uint32_t>::max() + 1.0;
    static const double upperSignedLimit =
                std::numeric_limits<boost::int32_t>::max() / 20.0;
    static const double lowerSignedLimit =
                std::numeric_limits<boost::int32_t>::min() / 20.0;

    if (a >= lowerSignedLimit && a <= upperSignedLimit)
    {
        return static_cast<boost::int32_t>(a * 20.0);
    }

    // This slow truncation happens only in very unlikely cases.
    return a >= 0 ?
        static_cast<boost::uint32_t>(std::fmod(a * 20.0, upperUnsignedLimit))
        : 
        -static_cast<boost::uint32_t>(std::fmod(-a * 20.0, upperUnsignedLimit));
}

/// \brief
/// Return the smallest multiple of given base greater or equal
/// given limit
inline unsigned int
smallestMultipleContaining(unsigned int base, unsigned int x)
{
    int f = x / base;
    if (x % base) f++;
    return base*f;
}


/// Return (unmangled) name of this instance type. Used for
/// logging in various places.
template <class T>
std::string typeName(const T& inst)
{
	std::string typeName = typeid(inst).name();
#if defined(__GNUC__) && __GNUC__ > 2
	int status;
	char* typeNameUnmangled = 
		abi::__cxa_demangle (typeName.c_str(), NULL, NULL,
				     &status);
	if (status == 0)
	{
		typeName = typeNameUnmangled;
		std::free(typeNameUnmangled);
	}
#endif // __GNUC__ > 2
	return typeName;
}

/// Used in logging.
#ifdef HAVE_PTHREADS
#else
# ifdef _WIN32
} // end namespace gnash
extern "C" unsigned long int /* DWORD WINAPI */ GetCurrentThreadId(void);
namespace gnash {
# else
/* getpid() */
#include <sys/types.h>
#include <unistd.h>
# endif
#endif

inline unsigned long int /* pthread_t */ get_thread_id(void)
{
#ifdef HAVE_PTHREADS
# ifdef __APPLE_CC__
    return reinterpret_cast<unsigned long int>(pthread_self());
# else
    // This isn't a proper style C++ cast, but FreeBSD has a problem with
    // static_cast for this as pthread_self() returns a pointer. We can
    // use that too, this ID is only used for the log file to keep output
    // from seperare threads clear.
    return (unsigned long int)pthread_self();
# endif 
#else
# ifdef _WIN32
    return GetCurrentThreadId();
# else
    return static_cast<unsigned long int>(getpid());
# endif
#endif
}

} // namespace gnash

// Handy macro to quiet compiler warnings about unused parameters/variables.
#define UNUSED(x) (x) = (x)

#endif // _GNASH_UTILITY_H


// Local Variables:
// mode: C++
// c-basic-offset: 8 
// tab-width: 8
// indent-tabs-mode: t
// End:
