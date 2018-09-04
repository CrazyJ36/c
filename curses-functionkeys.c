#include <ncurses.h>

int main() {
  initscr();

  /* Enables use of arrow keys(important), fn keys(f1, f2...).
     if this is not set, the program would end. */
  keypad(stdscr, TRUE);

  printw("Type an arrow key.\n");

  refresh();

  int ch;
  int left = 0;
  int right = 0;
  int x;
  for (x = 0; x < 10; x++)  {
    ch = getch();

    switch(ch) {
      case KEY_LEFT:
        left = left + 1;
        break;
      case KEY_RIGHT:
        right = right + 1;
        break;
   }

    printw("left: %d, right: %d\n", left, right);
    refresh();
  }

  endwin();
  printf("done\n");

  return(0);
}
