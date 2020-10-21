#include "screen_configs.h"

void load_screen_info()
{
  getmaxyx(stdscr, window_info.y_size, window_info.x_size);

  start_color();
  init_pair(PINK_BLACK, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
  init_pair(RED_BLACK, COLOR_RED, COLOR_BLACK);
  init_pair(CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);
  init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
  init_pair(YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
}

void centered_string(int row, char *string)
{
  int len, indent;

  len = strlen(string);
  indent = (window_info.x_size - len);
  indent /= 2;

  mvaddstr(row, indent, string);
  refresh();
}

void draw_window_design()
{
  int col = 3, curr_row = 1;

  attrset(A_BOLD | COLOR_PAIR(YELLOW_BLACK));
  mvaddstr(curr_row++, col, "             ¶____¶");
  mvaddstr(curr_row++, col, "         ¶_¶¶¶¶¶¶¶¶¶¶");
  mvaddstr(curr_row++, col, "     ¶¶¶¶¶¶¶_________¶");
  mvaddstr(curr_row++, col, "   ¶¶¶¶¶_____________¶");
  mvaddstr(curr_row++, col, "   ¶_________________¶");
  mvaddstr(curr_row++, col, "    ¶________________¶¶");
  mvaddstr(curr_row++, col, "    ¶¶________________¶");
  mvaddstr(curr_row++, col, "     ¶________________¶¶");
  mvaddstr(curr_row++, col, "     ¶¶_______¶¶¶____¶¶¶");
  mvaddstr(curr_row++, col, "      ¶_____¶¶___¶¶_¶___¶");
  mvaddstr(curr_row++, col, "      ¶_____¶¶_____¶____¶");
  mvaddstr(curr_row++, col, "      ¶¶____¶______¶¶¶¶¶¶¶");
  mvaddstr(curr_row++, col, "       ¶____¶¶__¶¶¶_____¶¶");
  mvaddstr(curr_row++, col, "      ¶¶¶¶____¶¶¶¶_____¶¶");
  mvaddstr(curr_row++, col, "      ¶¶¶_______________¶¶");
  mvaddstr(curr_row++, col, "       ¶¶¶______________¶¶");
  mvaddstr(curr_row++, col, "        ¶_____¶¶¶¶¶¶¶¶¶¶¶");
  mvaddstr(curr_row++, col, "       ¶¶_______¶¶¶¶¶");
  mvaddstr(curr_row++, col, "      ¶¶¶¶¶_____¶");
  mvaddstr(curr_row++, col, "   ¶¶¶¶__¶¶¶¶¶¶¶¶");
  mvaddstr(curr_row++, col, "  ¶¶____¶¶_____¶¶");
  mvaddstr(curr_row++, col, " ¶¶_____¶¶______¶¶");
  mvaddstr(curr_row++, col, "¶¶______¶¶_______¶¶");
  mvaddstr(curr_row++, col, " ¶¶¶¶¶___¶¶______¶¶");
  mvaddstr(curr_row++, col, " ¶__¶¶¶¶¶¶_______¶¶");
  mvaddstr(curr_row++, col, "¶¶____¶___________¶¶");
  mvaddstr(curr_row++, col, "¶____¶¶__________¶¶¶");
  mvaddstr(curr_row++, col, "¶____¶¶____________¶");
  mvaddstr(curr_row++, col, "¶_____¶___________¶¶¶");
  mvaddstr(curr_row++, col, "¶_____¶¶¶¶¶¶¶¶¶¶¶¶¶_¶");
  mvaddstr(curr_row++, col, "¶______¶_________¶___¶");
  mvaddstr(curr_row++, col, "¶¶¶¶__¶__________¶_¶¶¶");
  mvaddstr(curr_row++, col, " ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶");
  mvaddstr(curr_row++, col, "   ¶¶¶¶¶¶¶¶¶____¶");
  mvaddstr(curr_row++, col, "   ¶¶___¶__¶____¶");
  mvaddstr(curr_row++, col, "   ¶____¶__¶____¶");
  mvaddstr(curr_row++, col, "   ¶¶___¶__¶____¶¶");
  mvaddstr(curr_row++, col, "  ¶_______¶¶¶¶¶¶¶¶¶¶");
  mvaddstr(curr_row++, col, " ¶¶¶¶¶¶¶¶¶¶¶__¶¶¶¶¶¶¶");
  mvaddstr(curr_row++, col, " ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶");


  attrset(A_BOLD | A_BLINK | COLOR_PAIR(PINK_BLACK));
  centered_string(2, (char *)config_info.company);

  attrset(COLOR_PAIR(CYAN_BLACK));
  centered_string(3, (char *)config_info.description);

  int x = 0, y = 2;
  int curr_pos_x = 0, curr_pos_y = 0;
  do {
    move(curr_pos_y, curr_pos_x);
    addch('*');

    switch (x) {
    case 0:
      curr_pos_x++;
      break;
    case 1:
      curr_pos_x--;
      break;
    }

    switch (y) {
    case 0:
      curr_pos_y++;
      break;
    case 1:
      curr_pos_y--;
      break;
    }

    if ((curr_pos_x == (window_info.x_size - 1)) && (curr_pos_y == 0)) {
      y = 0;
      x = 2;
    } else if ((curr_pos_x == (window_info.x_size - 1)) && (curr_pos_y == (window_info.y_size - 1))) {
      y = 2;
      x = 1;
    } else if ((curr_pos_x == 0) && (curr_pos_y == (window_info.y_size - 1))) {
      y = 1;
      x = 2;
    }

    napms(3);
    refresh();

  } while(!((curr_pos_x == 0) && (curr_pos_y == 0)));
}
