/*
Just as a pointer to an array can be passed into a function, a
pointer to an array can be returned.
Note that a pointer, not an array, is declared to store the value
returned by the function. Also note that when a local variable is
being passed out of a function, you need to declare it as static in
the function.
Keep in mind that a[k] is the same as *(a + k).

Also, user-defined functions, as opposed to using only
statements in main(), are useful when you need to return result
values/data from algorithmic statements.
*/

#include <stdio.h>

int * get_evens();

int main() {
  int *a;
  int k;

  a = get_evens(); /* gets first 5 even numbers */
  for (k = 0; k < 5; k++)
    printf("%d\n", a[k]);

  return 0;
}

int * get_evens() {
  static int nums[5];
  int k;
  int even = 0;

  for (k = 0; k < 5; k++) {
    nums[k] = even += 2;
  }

  return (nums);
}
