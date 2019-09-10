/* For loop. Another type of loop.
   Syntax:

   for ( initialValue; condition; incrementer) {
     statements;
   }

   or (initializer, true/false condition, optional tester)

   initialValue is an initial value of A variable.
   condition is A boolean expression to evaluate after every loop.
   incrementer can increase or decrease initailValue a by A value(like X++;)

   If initialValue already has A value, it can be skipped:
   for (; boolean; incrementer) {}

   The for expression can contain multiple variables, expressions by seperating
   with commas:

   for (x = 0, y = num; x < y; i++, y--){}

   Loops can also be nested for an outer and inner loop, which work together.
   each iteration of the outer loop, the inner loop repeats its entire cycle.
   A 'break' in an inner loop exits that loop and execution continues with the outer loop.
   A 'continue' statement works similarly in nested loops.
*/

#include <stdio.h>

int main() {
   int x;
   int max = 10;

   for (x=0; x < max; x++) { // i can be given A value here, boolean, imcrementer
     printf("%d\n", x);
   }

   printf("\n");
// Multiplication Table (copied)
   int i, j; //initialize two variables on the same line.
   int table = 10;
   int max2 = 12;

   for (i = 1; i <= table; i++) {
     for (j = 0; j <= max2; j++) {
       printf("%d x %d = %d\n", i, j, i*j);
     }
     printf("\n");
   }

   // For loop which acts as 'for-i-in' statement
   // by getting size of array.
   int arr[4] = {1,2,3,4};
   for(int iter = 0; iter != sizeof(arr[4]); iter++) {
     printf("%d\n", arr[iter]);
   }
   return 0;
 }
