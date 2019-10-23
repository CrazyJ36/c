#include <ncurses.h>
#include <stdlib.h> // system("cmd")

int main() {
  initscr();
  curs_set(FALSE); // disable blinking cursor for entire windowed program.
  noecho();
  printw("Top-Left");
  mvprintw(0, 32, "Centerish"); // print from-top: 0 pixels, from-left: 32 pixels
  refresh();
  getch();
  endwin();

  // Test system commands
  int systemRet = system("");
  if (systemRet == 0) {
    system("clear");
    printf("Done.\n");
  } else {
    printf("system() returned unsuccessful.\n");
  }

  return 0;
}
