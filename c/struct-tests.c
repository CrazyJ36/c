/* -----struct-tests.c-----
   Structures (also the composite, custom, aggregate data type. Also called records)
   is a user-defined data type, grouping related variable members
   with different data types if desired(strings, arrays, pointers, int, char...)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // 1. Struct (object structure) should be initialized as:
  // struct CapitalName { any-data-type item-name; any-data-type item-name; };
  // in squiggle brackets, semicolon at the end as A struct type definition is A statement.
  struct NamesRef { // Usage: type, Tag, { members; };
    char nameFirst[10]; // values cannot be assigned here, as the main struct is
    char nameLast[10]; // the 'reference setting for different values'
    int age;
  }; // don't forget ';'

  // 2. Then that basic "structure", can be instantiated several
  // times as different variables with different values to use the same data form.

  // New NamesRef object called names_object, where NamesRef.nameFirst="Jen", NamesRef.nameLast="James"...
  struct NamesRef names_object  = {"Jen", "James", 19}; // This predefines A new NamesRef type of object. No array type complaint.
  printf("Using NamesRef structured data in A new object.\nnames_object.nameFirst= %s\n",
    names_object.nameFirst); // n.n1 is 'struct names {} as new struct n, position 1.

  // Another way of using the original NamesRef struct
  struct NamesRef names_object2; // new object based on NamesRef.
  // names_object2.nameFirst="Bob"; // This won't work to expression array types(compiler complaint). Use strcpy():
  strcpy(names_object2.nameFirst, "Bob"); // char* strcpy(char*, const char);
  printf("Another NamesRef object using different values(new name):\nnames_object2.nameFirst= %s\n",
    names_object2.nameFirst);

  exit(0);
}
