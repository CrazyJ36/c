#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char sprite = 'O';
char food[6] = "-----";

int main() {
  system("setterm -cursor off");

  printf("%c ", sprite);
  printf("%s", food);

  for (int inc = 0; inc < 10; inc++) {
    printf("\b");
    usleep(200000);
  }

  printf("\n");
  system("setterm -cursor on");
  exit(0);
}
