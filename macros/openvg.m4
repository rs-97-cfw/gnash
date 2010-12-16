dnl  
dnl Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010 Free Software Foundation, Inc.
dnl  
dnl  This program is free software; you can redistribute it and/or modify
dnl  it under the terms of the GNU General Public License as published by
dnl  the Free Software Foundation; either version 3 of the License, or
dnl  (at your option) any later version.
dnl  
dnl  This program is distributed in the hope that it will be useful,
dnl  but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl  GNU General Public License for more details.
dnl  You should have received a copy of the GNU General Public License
dnl  along with this program; if not, write to the Free Software
dnl  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

AC_DEFUN([GNASH_PATH_OPENVG],
[
  mesavg=no
  dnl Look for the headers.
  AC_ARG_WITH(openvg_includes, AC_HELP_STRING([--with-openvg-includes], [directory where Openvg headers are]), with_openvg_includes=${withval})
  AC_CACHE_VAL(ac_cv_path_openvg_includes,[
    if test x"${with_openvg_includes}" != x; then
      if test -f ${with_openvg_includes}/openvg.h; then
        ac_cv_path_openvg_includes="`(cd ${with_openvg_includes}; pwd)`"
      else
        AC_MSG_ERROR([${with_openvg_includes} directory doesn't contain VG/openvg.h])
      fi
    fi
  ])

  dnl If the include path hasn't been specified, go look for it.
  if test x"${ac_cv_path_openvg_includes}" = x; then
    AC_MSG_CHECKING([for Openvg headers])
    for i in $incllist; do
      if test -f $i/VG/openvg.h; then
      dnl We have the libMesa version of OpenVG 1.0.1
        if test -f $i/VG/vgext.h; then
           mesavg=yes
        fi
        if test x"$i" != x"/usr/include"; then
          ac_cv_path_openvg_includes="-I$i"
          break
        else
          ac_cv_path_openvg_includes="default"
          break
        fi
      fi
    done
  fi

  if test x"${ac_cv_path_openvg_includes}" = x; then
    AC_CHECK_HEADERS([VG/open.h], [ac_cv_path_openvg_includes=""])
  fi

  if test x"${ac_cv_path_openvg_includes}" != x -a x"${ac_cv_path_openvg_includes}" != x"default"; then
    if test x$mesavg = xyes; then
      OPENVG_CFLAGS="${ac_cv_path_openvg_includes}"
      AC_DEFINE(HAVE_VG_VGEXT_H, 1, [Have LibMESA OpenVG])
    else
      OPENVG_CFLAGS="-DOPENVG_STATIC_LIBRARY ${ac_cv_path_openvg_includes}"
      AC_DEFINE(HAVE_VG_EXT_H, 1, [Have Freescale OpenVG])
    fi
  else
    if test x$mesavg = xyes; then
      OPENVG_CFLAGS=""
    else
      OPENVG_CFLAGS="-DOPENVG_STATIC_LIBRARY"
    fi
  fi
  AC_MSG_RESULT(${ac_cv_path_openvg_includes})

  dnl Look for the libraries.
  AC_ARG_WITH(openvg_lib, AC_HELP_STRING([--with-openvg-lib], [directory where Openvg libraries are]), with_openvg_lib=${withval})
  AC_CACHE_VAL(ac_cv_path_openvg_lib,[
    if test x"${with_openvg_lib}" != x ; then
      if test -f ${with_openvg_lib}/libOpenVG.a -o -f ${with_openvg_lib}/libOpenVG.${shlibext}; then
        ac_cv_path_openvg_lib="-L`(cd ${with_openvg_lib}; pwd)` -lOpenVG"
      fi
    fi
  ])

  if test x"${ac_cv_path_openvg_lib}" = x; then
    for i in $libslist; do
      if test -f $i/libOpenVG.${shlibext} -o -f $i/libOpenVG.a; then
        if test ! x"$i" = x"/usr/lib" -a ! x"$i" = x"/usr/lib64"; then
          ac_cv_path_openvg_lib="-L$i -lOpenVG"
          break
       else
          ac_cv_path_openvg_lib="-lOpenVG"
          break
       fi
      fi
    done
  fi
  if test x"${ac_cv_path_openvg_lib}" = x; then
    AC_CHECK_LIB([OpenVG], [vgClear], [ac_cv_path_openvg_lib="-lOpenVG"])
  fi

  if test x"${ac_cv_path_openvg_lib}" != x ; then
    OPENVG_LIBS="${ac_cv_path_openvg_lib}"
    has_openvg="yes"
  else
    OPENVG_LIBS=""
  fi
  
  AC_SUBST(OPENVG_CFLAGS)
  AC_SUBST(OPENVG_LIBS)
])

# Local Variables:
# c-basic-offset: 2
# tab-width: 2
# indent-tabs-mode: nil
# End:
