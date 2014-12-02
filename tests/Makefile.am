TESTS = test
check_PROGRAMS = test
test_SOURCES = test.c $(top_builddir)/src/auth.h
test_CFLAGS = @CHECK_CFLAGS@ `pkg-config --cflags glib-2.0`
test_LDADD = $(top_builddir)/src/libauth.la $(top_builddir)/src/libcolor.la @CHECK_LIBS@
test_LDFLAGS = `pkg-config --libs glib-2.0`
