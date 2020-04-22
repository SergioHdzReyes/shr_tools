#include <config.h>
#include <stdio.h>
# include <libintl.h>
# include <locale.h>

#define PROGRAM_NAME "servers"
#define _(STRING) gettext(STRING)

#include "utils.h"

int
main (void)
{
  setlocale(LC_ALL, "");
  bindtextdomain("servers", "/usr/share/locale/");
  textdomain("servers");

  printf(_("servers"));
  return EXIT_SUCCESS;
}
