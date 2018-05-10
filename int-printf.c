/*
  This program breakdown:
  stdio.h for printf
  fake named integer x is assigned(converted to) 5
  printf the data-type %d putting x into it. Also putting newline with x.
*/

#include <stdio.h>

int main()
{
  int x = 5;
  printf("Printing an integer: %d\n", x);
  return(0);
}
