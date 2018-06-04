#include <stdio.h>
#include <unistd.h> // for usleep()
#include <stdlib.h> // for exit()

int main() {
  system("setterm -cursor off"); // this is a linux command hides the block cursor as to not block the animation
  char arr[5] = {'|','/','-','\\'}; // this is the array of characters that will be traversed to form a spinning circle.

  for (int z = 0; z < 5; z++) { // this makes the actual loop spin more than once

    for (int x = 0; x < 5; x++) { // this is the actual spinning animation loop
      fflush(stdout); // clears at least that character space.
      char y = arr[x];  // a new printable variable will cycle through all of the array characters
      printf("\b%c", y); // clear, then print y's character every loop
      usleep(200000); // gives a break so the characters can slowly appear to spin
    }

  }

  printf("\n");
  system("setterm -cursor on"); // turn cursor back on before quitting
  return 0;
  exit(0);
}
