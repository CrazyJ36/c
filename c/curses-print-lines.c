#include <curses.h>
int main() {
  initscr();

  // print to stdscr - belonging to ncurses instance.
  printw("Line 1\n"); // '\n' new line for next printw().
  printw("Line 2");

  noecho(); // don't echo the next getch() character.
  getch();
  endwin();

  printf("done.\n"); // prints to linux stdin after endwin().
  return(0);
}
