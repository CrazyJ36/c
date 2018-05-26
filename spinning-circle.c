#include <stdio.h>
#include <unistd.h> // for usleep()
#include <stdlib.h> // for exit()

int main() {
  system("setterm -cursor off"); // this linux com
  char arr[5] = {'|','/','-','\\'};
  for (int x = 0; x < 6; x++) {
    fflush(stdout); // clears at least that character space.
    char y = arr[x];
    printf("\b%c", y);
    usleep(200000);
  }
  printf("\n");
  system("setterm -cursor on");
  return 0;
  exit(0);
}
