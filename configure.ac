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

# Checks for header files.
AC_CONFIG_HEADERS([config.h])

PKG_CHECK_MODULES(
    [LIBCONFIGXX], [libconfig++ >= 1.4],
    ,
    AC_MSG_ERROR([libconfig++ 1.4 or newer not found.])
)

AC_CONFIG_FILES([
Makefile
src/Makefile
])

AC_OUTPUT
