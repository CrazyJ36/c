#include <stdio.h>
int main()
{
   char c;
   printf("Enter 1 character: ");
// getchar() reads the next available (1) character from stdout, returns int.
// can loop for more chars
   c = getchar();
// getchar will wait and read next char
   printf("You entered: ");
// putchar() basically prints. puts passed char, returns it.
   putchar(c);
   putchar('\n');
// return 0; and return(0); are the same
   return 0;
}
