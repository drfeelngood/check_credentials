#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(check_credentials, 1.0.0, [dan@dj-agiledev.com])
AM_INIT_AUTOMAKE(check_credentials, 1.0.0)
AC_CONFIG_SRCDIR([check_credentials.c])
#AC_CONFIG_HEADER(config.h)

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([crypt], [crypt])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([shadow.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.



# Checks for library functions.
AC_CHECK_FUNCS([getspnam])
AC_OUTPUT(Makefile)
