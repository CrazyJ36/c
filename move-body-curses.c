#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

int main() {
    initscr();
    curs_set(FALSE);
    noecho();
    keypad(stdscr, TRUE);
    clear();

    const char sprite = '+';
    int xpos = 10;
    int ypos = 10;
    int ch;

    mvprintw(xpos, ypos, &sprite);
    refresh();

    ch = getchar();
    switch(ch) {
       case KEY_UP:
           ypos = ypos + 1;
           break;
       case KEY_DOWN:
           ypos = ypos - 1;
           break;
       case KEY_LEFT:
           xpos = xpos + 1;
           break;
       case KEY_RIGHT:
       xpos = xpos - 1;
    break;
    }

   return(0);
}
