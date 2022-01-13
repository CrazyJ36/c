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
  int misses = 0;
  int inc; // increment number for time limit
  for (inc = 0; inc < 10; inc++)  { // increment number for time limit
    ch = getch(); // get device input

    switch(ch) { // get key presses as 'player turn'
      case KEY_LEFT:
        left = left + 1; // increase player score
        printw("left: %d, right: %d, miss: %d\n", left, right, misses);
        break; /* either this(left) or right. either or, should break to return which one happened
                  (like latch vs momentary). switch will loop again to get next 'turn'.*/
      case KEY_RIGHT:
        right = right + 1;
        printw("left: %d, right: %d, miss: %d\n", left, right, misses);
        break;
      default:
        misses += 1;
        printw("miss! remaining tries: %d\n", inc);
        break;

  }
    refresh();
  }

  // after loop endwin()
  endwin();
  printf("Game over after 10 tries.\n");
  printf("Left: %d Right: %d, Misses: %d\n", left, right, misses);
  if (left > right) {
    printf("Left Wins!\n");
  } else if (right > left) {
    printf("Right Wins!\n");
  } else {
	  printf("Tie! Rematch\n");
  }
  return(0);
}
