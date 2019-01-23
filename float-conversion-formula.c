/* Shows printf converstion formula.
   %3.2f means
   formula to print number
   at least 3 digits wide(hundreds),
   with 2 digits after decimal point(fraction accuracy)
*/
#include <stdio.h>

#define NUM 3.3493
int main()
{
   printf("%1.3f\n", NUM); // prints 3.349
   return(0);
}
