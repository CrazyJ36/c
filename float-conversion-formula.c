/* Shows some printf converstion formulas.
   %3.2f means
   formula to print number
   at least 3 digits wide(hundreds),
   with 2 digits after decimal point(fraction accuracy)
   The 'f' specifies that this is A floating point value.
*/
#include <stdio.h>

#define NUM 3.3493
#define NUM2 3
#define NUM3 2.1
int main()
{
   printf("%1.3f\n", NUM); // prints 3.349
   printf("%1d\n", NUM2); // 1 character-wide int
   printf("%1.1f\n", NUM3); // 1 char-wide, 2 decimal point float
   return(0);
}
