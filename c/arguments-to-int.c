// arg-to-int.c
// Convert cli argument, which is char pointer, to long integer.

#include <stdio.h>
#include <stdlib.h> // for string-to-long(strtol), exit()

int main(int argc, char *argv[]) {

  if (argc >= 2) {
      int converted = atoi(argv[1]);
      printf("Converted to INT from char: %d\n", converted);
  } else {
      printf("You must enter a number argument at command line. Try again.\n");
  }

  exit(0);
}
