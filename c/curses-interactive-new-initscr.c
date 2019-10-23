/*  Starts one window, then another.
*   Multiple windows should'nt be done this way
*   of course. Use panels.
*/

#include <ncurses.h>

int main() {

  WINDOW *win1 = initscr();
  printw("Window 1, press any key for next...");
  refresh();
  getchar();
  endwin();
  clear();  // clear the screen before showing new window.

  WINDOW *win2 = initscr();
  printw("Window 2, press any key to exit...\n");
  refresh();
  getchar();
  endwin();  // retores terminal

  delwin(win1);  /* deallocates these windows */
  delwin(win2);  /* from memory */

  printf("Done.\n");
  return 0;
}
