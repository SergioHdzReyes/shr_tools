#ifndef SHR_TOOLS_UTILS_H
# define SHR_TOOLS_UTILS_H

#include <ncurses.h>

#include "configuration.h"
#include "screen_configs.h"
#include "conexion.h"

void init_curses(bool turn_color);
int destroy_and_exit(int exit_status);
void bomb(char *msg);

void init_curses(bool turn_color)
{
  initscr();

  if (!has_colors())
    bomb("Terminal no cuenta con caracteristica de colores\n");

  if (start_color() != OK)
    bomb("Imposible iniciar colores.\n");

  if (turn_color) {
    start_color();
    if (!can_change_color())
      bomb("Imposible cambiar colores en terminal.\n");
  }
}

int destroy_and_exit(int exit_status)
{
  destroy_configuration();
  endwin();

  return exit_status;
}

void bomb(char *msg)
{
  endwin();
  puts(msg);
  exit(1);
}

#endif
