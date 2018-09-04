#include <ncurses.h>

int main() {
  initscr(); // start curses

  /* Enables use of arrow keys(important), fn
     keys(f1, f2...).
     if this is not set, the program would end. */
  keypad(stdscr, TRUE);

  printw("Type an arrow key.\n"); // rules of 'game'

  refresh(); // refresh screen to show instructions

  int ch; // to-be user input character
  int left = 0; // player 1
  int right = 0; // player 2
  int x; // increment number for time limit
  for (x = 0; x < 10; x++)  { // increment number for time limit
    ch = getch(); // get device input

    switch(ch) { // get left or right button as 'player turn'
      case KEY_LEFT:
        left = left + 1; // increase player score
        break; /* either this(left) or right. either or, should break to return which one happened (like latch vs momentary). switch will loop again to get next 'turn'. */
      case KEY_RIGHT:
        right = right + 1;
        break;
   }

    //print result each time
    printw("left: %d, right: %d\n", left, right);
    refresh();
  }

  // after loop endwin()
  endwin();
  printf("done\n");
  return(0);
}
