// To Compile: gcc -o output program.c -lncurses

#include <stdio.h>
#include <ncurses.h> // ncurses headerfile
#include <unistd.h> // for in-program sleep
#include <stdlib.h> // for system("clear") function

int main()
{
  initscr();  // initialize a screen
  curs_set(FALSE);  // hide blinking cursor

  clear();  // clear the current program progress
  mvprintw(0, 0, "Hello from NCurses.\nPress any key to exit."); // (coordinate x, coordinate y, text)
  refresh(); // refresh the screen to show newer code like the line above
  getchar();  // sleep to keep showing text
  endwin();  // end the ncurses windows to return to normal terminal
  // could do system("clear") to clear the screen after ncurses finishes.
  return(0);
}
