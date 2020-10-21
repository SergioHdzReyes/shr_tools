#ifndef SHR_TOOLS_SCREEN_CONFIGS_H
# define SHR_TOOLS_SCREEN_CONFIGS_H

#include <string.h>
#include <ncurses.h>
#include "configuration.h"

#define PINK_BLACK 1
#define GREEN_BLACK 2
#define RED_BLACK 3
#define CYAN_BLACK 4
#define WHITE_BLACK 5
#define YELLOW_BLACK 6

struct _win_info {
  int x_size, y_size;
} window_info;

void load_screen_info();
void centered_string(int row, char *string);
void draw_window_design();

#endif
