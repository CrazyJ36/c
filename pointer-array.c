/* pointers can hold 'things', expressions, equations as
   it's pointing to something.
   not only one piece of data like variables.
*/

#include <stdio.h>

int main() {
  int arr[4] = {1,2,3}; // an int array. 4 index positions, 3 items
  int *pointer;  // a new pointer

  pointer = arr; /* pointers can hold "things", not
  just a single piece of data */
  for(int i = 0; i < 3; i++) {
    printf("%d", *(pointer + i)); /*    *(pointer + i) means:
    "the data pointed to, also i++ as arithmetic" */
    printf("\n");
  }
  printf("first array element: %d\n", *pointer); /*name or pointer of
  array defaults to 0 index */
  pointer++; // 0 to 1, index 2
  printf("second array element: %d\n", *pointer);
  pointer += 1; //index 3
  printf("third, final array item: %d\n", *pointer);
}
