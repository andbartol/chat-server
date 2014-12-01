AC_INIT([chat-server], [1.0], [bug-report@address])
#AM_PATH_CHECK
PKG_CHECK_MODULES([CHECK], [check >= 0.9.4])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

AC_PROG_CC
AM_PROG_AR
AC_PROG_LIBTOOL
AC_PROG_AWK
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])
#AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
