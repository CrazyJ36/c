#include <ncurses.h>
/* TODO not echo char and respond only if getch is arrow, or
   show 'player missed' if wrong button was pressed.
*/

int main() {
  initscr(); // start curses

  /* Enables use of arrow keys(important), fn
     keys(f1, f2...).
     if this is not set, the program would end. */
  keypad(stdscr, TRUE);

  printw("This is A multiplayer game in which two people can press an arrow key. First to 10 presses wins.\n"); // rules of 'game'

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
        break; /* either this(left) or right. either or, should break to return which one happened
                  (like latch vs momentary). switch will loop again to get next 'turn'. */
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
  printf("Game over after 10 tries.\n");
  printf("Left: %d Right: %d\n", left, right);
  if (left > right) {
    printf("Left Wins!\n");
  } else if (right > left) {
    printf("Right Wins!\n");
  } else {
	  printf("Tie! Rematch\n");
  }
  return(0);
}
