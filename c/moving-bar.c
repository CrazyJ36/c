/* TODO Recreate this for practice. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // simply printing more variables for each iteration
  char bar[6] = "-----";
  char tabch[5] = "\t";

  printf("%s\n", bar);
  usleep(500000);
  printf("%s%s\n", tabch, bar);
  usleep(500000);
  printf("%s%s%s\n", tabch, tabch, bar);

  // another way with loop.
  int count = 0;

  char y[20] = " ";
  char x[20] = "-";

  while (count < 10) {
    strcat(y, x);  // strcat(taget, source); only adds another x on loop.
    printf("%s\n", y); // thing now has additional space after each loop.
    usleep(300000);
    count++;
  }

  printf("\n");
}
