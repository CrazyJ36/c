# Linux
Program text ui with ncurses:

1. sudo apt-get install libncurses5 libncurses5-dev
2. compile with '-lncurses' at the end of gcc command
build script is here for curses with optimization

<ncurses.h> or <curses.h> must be included

# example
-----
#include <ncurses.h>
#include <stdio.h>

int main()
{
  initscr(); // start curses screen
  printw("text in curses window"); // show text in curses window
  refresh(); // refresh to show the newly added text
  getch(); // this will wait for any key character to continue
  endwin(); // must end the screen to get back to normal terminal operation
  return(0);
}
-----
