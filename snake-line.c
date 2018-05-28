/* To make the snake appear to go horizontal, fflush(stdout)
   befor every printf().
*/

#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 0;

  while (x < 4) {
    printf("\\\n");
    usleep(300000);
    printf("/\n");
    usleep(300000);
    x++;
  }

  return 0;
}
