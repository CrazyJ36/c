/* This shows how to properly format odd,
long numbers and strings. Reference:
https://www.cprogramming.com/tutorial/printf-format-strings.html

printf() format:
%[flag][min width][precision][length modifier][conversion specifier]

f - float number using decimal. ex: 3.1415
e - float using scientific notation. ex: 1.86e6 (same as 1,860,000)
E - Like e, but with a capital E in output. ex: 1.86E6
g - Use shorter of two representations: (f or e) (3.1 or 1.86e6)
G - Like g, except uses the shorter of f or E.

short int or  unsigned short int - h
long int or unsigned long int - l
wide characters or strings - l
long double - L
*/

#include <stdio.h>
#include <stddef.h> // standard define, for w_char in linux.
int main()
{
  short int short_int = 3;
  printf( "%hd \n", short_int );

  long int long_int = 3;
  printf( "%ld \n", long_int );

  wchar_t* wide_str = L"Wide String";
  printf( "%ls \n", wide_str );

  long double long_double = 3.1415926535;
  printf( "%Lg \n", long_double );

  printf( "%g \n", 93000000.0 ); // scientific shortening

  return 0;
}
