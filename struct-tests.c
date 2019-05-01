/* Structures (also the composite , aggregate data type. Also called records)
   is a user-defined data type, grouping related variable members
   with different data types if desired(strings, arrays, pointers, int, char...)

*/
#include <stdio.h>

int main() {

  // 1. Struct (object structure) must be initialized first
  struct Names { // type, tag, { members; };
    char nameFirst[4]; // values cannot be assigned here, as the main struct is
    char nameLast[6]; // the 'setting for different values'
    int npeople;
  }; // don't forget ';'

  // 2. Then that basic "structure", can be instantiated several
  // times as different variables with different values.
  struct names names_ref_object  = {"Jen", "James", 2};
  printf("%s\n", n.n1); // n.n1 is 'struct names {} as new struct n, position 1.
  print
  return(0);
}
