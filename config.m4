dnl $Id$
dnl config.m4 for extension geospatial

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(geospatial, for geospatial support,
dnl Make sure that the comment is aligned:
dnl [  --with-geospatial             Include geospatial support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(geospatial, whether to enable geospatial support,
dnl Make sure that the comment is aligned:
dnl [  --enable-geospatial           Enable geospatial support])

if test "$PHP_GEOSPATIAL" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-geospatial -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/geospatial.h"  # you most likely want to change this
  dnl if test -r $PHP_GEOSPATIAL/$SEARCH_FOR; then # path given as parameter
  dnl   GEOSPATIAL_DIR=$PHP_GEOSPATIAL
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for geospatial files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       GEOSPATIAL_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$GEOSPATIAL_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the geospatial distribution])
  dnl fi

  dnl # --with-geospatial -> add include path
  dnl PHP_ADD_INCLUDE($GEOSPATIAL_DIR/include)

  dnl # --with-geospatial -> check for lib and symbol presence
  dnl LIBNAME=geospatial # you may want to change this
  dnl LIBSYMBOL=geospatial # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $GEOSPATIAL_DIR/lib, GEOSPATIAL_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_GEOSPATIALLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong geospatial lib version or lib not found])
  dnl ],[
  dnl   -L$GEOSPATIAL_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(GEOSPATIAL_SHARED_LIBADD)

  PHP_NEW_EXTENSION(geospatial, geospatial.c, $ext_shared)
fi
