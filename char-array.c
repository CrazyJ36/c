#include <stdio.h>

int main()
{
  // an array of characters. Must be at least one more byte than actual length
  // to accomodate for 'trailing zero', usual to all programming. 
  char chArr[5] = "word";

  // print our char array
  printf(chArr);
  return(0);
}
