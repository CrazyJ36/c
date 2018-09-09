/* Structures (also the composite , aggregate data type. Also called records)
   is a user-defined data type, grouping related variable members
   with different data types if desired(strings, arrays, pointers, int, char...)

*/
#include <stdio.h>

int main() {

  // 1. Struct (object structure) must be initialized first
  struct names { // type, tag, { members; };
    char n1[4];
    char n2[6];
    int npeople;
  }; // don't forget ';'

  // 2. Then that basic "structure", can be instantiated several
  // times as different variables with different values.
  struct names n  = {"jen", "james", 2};
  printf("%s\n", n.n1); // n.n1 is 'struct names {} as new struct n, position 1.

  return(0);
}
