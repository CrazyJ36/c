#include <stdio.h>

int main() {
  // int x has 2 arrays with 3 characters (3 bytes allocated)
  int x[2][3] = {{1,2,3},{4,5,6}};

  int y = x[0][1]; // points to first(0 index) array (123), second item(index space 1), gives 2
  int z = x[1][2]; // gives 6

  printf("first array, second element: %d\n", y);
  printf("second array, third element: %d\n", z);

  return(0);
}
