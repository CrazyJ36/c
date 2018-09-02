/* Curses basics
- compile with -lncurses
- must use initscr(); to initialize a curses screen.
- printw("text"); prints to the curses screen. don't use printf();.
- refresh(); whenever new data is to be printed in screen.
- getch(); can be used for 'press any key' interaction.
- endwin(); must be used to end the curses screen session.
*/

#include <stdio.h>
#include <curses.h>

int main()
{
  initscr(); // start a new curses screen session
  printw("Welcome to curses... Press any key to continue."); // printw() - prints to the window
  refresh(); // refresh to show new data from before
  getch(); // get any key
  clear(); // clear text form the entire curses window
  printw("New 'page'. press any key to quit"); // make another 'view'. there can be 'pages' this way
  refresh(); // refresh again to show new stuff
  getch();
  endwin(); // endwin() must be called to end the curses screen before finishing program, so normal terminal use can continue
  printf("done\n"); // after ending window, print text to normal terminal
  return(0);
}
