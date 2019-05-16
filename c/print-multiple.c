/*  This shows how to print multiple things in one printf statement.
*/

#include <stdio.h>
int main()
{
  int num = 1;
  char letter = 't';
  printf("Items: %d %c\n", num, letter); //pre-defined items.
  printf("More: %d %c %s\n", 1, 'r', "String"); //defining in same statement.
  return(0);
}
