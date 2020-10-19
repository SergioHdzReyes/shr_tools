#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include "utils.h"

#define PROGRAM_NAME "servers"
//#define _(STRING) gettext(STRING)

int
main (void)
{
  char ch;

  init_curses(true);

  if (load_configuration())
    return destroy_and_exit(EXIT_FAILURE);

  send_request();

  while ((ch = getch()) != 'q') {

  }

  return destroy_and_exit(EXIT_SUCCESS);
}
