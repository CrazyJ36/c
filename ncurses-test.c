// To Compile: gcc -o output program.c -lncurses


#include <ncurses.h> // ncurses headerfile
#include <unistd.h> // for in-program sleep
#include <stdlib.h> // for system("clear") function

int main()
{
  initscr();  // initialize a screen
  curs_set(FALSE);  // hide blinking cursor

  clear();  // clear the current program progress
  mvprintw(0, 0, "Hello, World"); // (coordinate x, coordinate y, text)
  refresh(); // refresh the screen to show newer code like the line above
  sleep(3);  // sleep to keep showing text
  endwin();  // end the ncurses windows to return to normal terminal
  system("clear"); 
  return(0);
}
