#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include "configuration.h"

#define PROGRAM_NAME "servers"
//#define _(STRING) gettext(STRING)

int
main (void)
{
  load_configuration();

  //setlocale(LC_ALL, "");
  //bindtextdomain("servers", "/usr/share/locale/");
  //textdomain("servers");
  //printf(_("servers"));

  printf("prueba");

  destroy_configuration();
  return EXIT_SUCCESS;
}
