#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include <ncurses.h>
#include "utils.h"

#define PROGRAM_NAME "servers"
//#define _(STRING) gettext(STRING)

int
main (void)
{
  char ch;

  initscr();
  load_configuration();

  send_request();

  while ((ch = getch()) != 'q') {

  }

  destroy_configuration();
  endwin();
  return EXIT_SUCCESS;
}
