/*
An array cannot be passed by value to a function. However, an array
name is a pointer, so just passing an array name to a function is
passing a pointer to the array.
*/

#include <stdio.h>

int add_nums(int *a, int num_elements);

int main() {
  int nums[5] = {1, 2, 1, 2, 1};

  printf("sum of nums: %d\n", add_nums(nums, 5));

  return 0;
}

// *a  - pointer to array nums[]. shown in main printf().
int add_nums(int *a, int num_elements) {
  int sum = 0;
  int i;

  for (i = 0; i < num_elements; i++) {
    sum += a[i];
  }

  return (sum);
}
