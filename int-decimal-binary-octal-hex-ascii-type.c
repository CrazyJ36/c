/* These results corespond to any acsii convertion chart. Int(10) gets converted in inline string statement.
   Data Types:
   %d decimal
   %o octal
   %x hexadecimal lowercase
   %X hexadecimal capital case
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x = 10;
  printf("10 in decimal form: %d\n", x);
  printf("10 in octal form: %o\n", x);
  printf("10 in hexadecimal(lowercase): %x\n", x);
  printf("10 in hexadecimal(capital): %X\n", x);
  exit(0);
}
