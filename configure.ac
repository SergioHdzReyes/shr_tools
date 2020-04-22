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

dnl i18n support from GNU gettext.
AM_GNU_GETTEXT_VERSION([0.18.1])
AM_GNU_GETTEXT([external])

AC_CONFIG_FILES([
Makefile
src/Makefile
po/Makefile.in
])

AC_OUTPUT
