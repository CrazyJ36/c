/* you can partially initialize values for arrays,
   giving array size (in []) then defining only A few actual values.
   Empty values are set to zero(0) by default.
   Arrays are stored in memory and can not be changed.
   Arrays use indexed positions ( 0 = first item, 1 = second item),
   Index of array is also refered to as the 'subscript'.

   Remember that an array name acts as a pointer to the first
   element of the array. As in:  name = &array[0]
*/

#include <stdio.h>

int main() {
  int intArr[3] = {3,2,1}; // int arrays must have no apostraphes' unless ascii is to be printed
  char charArr[3] = {'d','e','g'}; // chars must have apostraphes' as if string
  printf("intArr second value: %d \n", intArr[1]);
  printf("charArr third value: %c \n", charArr[2]);

  printf("arrays' index value can be changed by: intArr[1] = 5\n");
  intArr[1] = 5;
  printf("intArr[1] is: %d\n", intArr[1]);

  int i;
  int x;
  for (i = 0; i < 3; i++) {
    x = intArr[i];
    printf("intArr %d = %d \n", i, x);
  }

  return 0;
}
