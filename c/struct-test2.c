#include <stdio.h>

// A new 'type' for data storage.
struct names {
  char one[16];
  char two[16];
};

int main() {

  // Use the new type for assigning variables.
  struct names the_names = {
    "john",
    "smith",
  };

  // Print newly assigned data.
  printf("%s\n", the_names.one);
  printf("%s\n", the_names.two);

  return 0;
}
