#include <stdio.h>
#include <windows.h> // windows only, for Sleep()
#include <stdlib.h> // for exit()
/* #include <unistd.h> // linux only, for usleep() */

int main() {
  /* Cursor still shown, but not in the way. 
    The linux way to hide the cursor was: system("setterm -cursor off");
  */ 
  char arr[5] = {'|','/','-','\\'}; // this is the array of characters that will be traversed to form a spinning circle.

  for (int z = 0; z < 3; z++) { // this makes the actual loop spin more than once

    for (int x = 0; x < 4; x++) { // this is the actual spinning animation loop
      fflush(stdout); // clears at least that character space.
      char y = arr[x];  // a new printable variable will cycle through all of the array characters
      printf("\b%c", y); // clear, then print y's character every loop
      Sleep(200); // milliseconds break so the characters can slowly appear to spin
    }

  }

  printf("\n");
  /* if off, turn cursor back on before quitting */
  exit(0);
}
