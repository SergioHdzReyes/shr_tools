AC_INIT([shr-tools],
[0.1],
[sergio.hdzreyes@gmail.com],
[SHR Tools],
[https://github.com/SergioHdzReyes/shr_tools])

AM_INIT_AUTOMAKE([
1.11.1
readme-alpha
subdir-objects
-Wall -Werror
])

AC_PROG_CC

LT_INIT
AC_CONFIG_MACRO_DIRS([m4])

# Checks for libcurl library
PKG_CHECK_MODULES(
    [LIBCURL], [libcurl >= 7.28.0],
    ,
    AC_MSG_ERROR([libcurl 7.28.0 or newer not found.])
)

# Checks for header files.
AC_CONFIG_HEADERS([config.h])

# Checks for libconfig++ library
PKG_CHECK_MODULES(
    [LIBCONFIGXX], [libconfig++ >= 1.4],
    ,
    AC_MSG_ERROR([libconfig++ 1.4 or newer not found.])
)

# FIXME: Replace `main' with a function in `-lconfig':
AC_CHECK_LIB([config], [main])
# FIXME: Replace `main' with a function in `-lgit2':
AC_CHECK_LIB([git2], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([getcwd setlocale])

AC_CONFIG_FILES([
Makefile
src/Makefile
])

AC_OUTPUT
