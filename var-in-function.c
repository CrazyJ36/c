#include <stdio.h>
#include <stdlib.h>

void main()
{
  char dir[25] = "/home/thomas/development";
  char program[3] = "ls";
  char command[28]; // If this was 'command[27]': buffer overflow error.
  sprintf(command, "%s %s", program, dir); // stores 'program' and 'dir' as 'command'.

  if (system(command) != 0) {   // runs the command variable with system
    printf("The command did not succeed on this system, not running.\n");
    exit(1);
  }

  exit(0);
}
