/* This shows why some long types need
to be formatted properly.
*/

#include <stdio.h>

int main() {

  // short int, unsigned short int - h
  short int i = 3;
  printf( "%hd", i );

  // long int or unsigned long int - l
  long int i = 3;
  printf( "%ld", i );

  // wide characters or strings - l
  wchar_t* wide_str = L"Wide String";
  printf( "%ls", wide_str );

  // long double - L
  long double d = 3.1415926535;
  printf( "%Lg", d );

  printf("\n");
  return 0;

}
