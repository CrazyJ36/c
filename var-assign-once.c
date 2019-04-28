// var-assign-once.c
/* Ways of quickly assigning new variables.

// Note/Learned
   Notice and remember not to use float precision formatting at
   input(scanf). Float precision is only useful at print-time, or you may
   get back an attempted formatting that's not what you input.
*/
#define NUM 3 // assigning A constant. set before compile(pre-process).
                  // uses cpu, no memory.
#include <stdio.h>

int main()
{
  int a, b; // init two integers on one line.
  char txt[20];
  float c;
  printf("Type: int int float string\n");
  // user-set 'list', one line, &a.. needed for vars addresses,
  // unless var acts as  pointer like test.
  scanf("%d %d %f %s", &a, &b, &c, txt);
  // print all thats'^ result..
  printf("a: %d , b: %d, c: %0.1f, NUM: %d, txt: %s.\n", a, b, c, NUM, txt);
  return(0);
}
