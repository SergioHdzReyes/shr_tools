#include <config.h>
#include <stdio.h>

#include "utils.h"

int
main (void)
{
  setlocale(LC_ALL, "");
  bindtextdomain("Hello!", "/usr/share/locale/");
  textdomain("Hello!");

  printf(_("Hello!"));
  return EXIT_SUCCESS;
}
