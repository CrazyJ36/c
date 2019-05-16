/* -----char-array.c-----
  This shows how to init, define, and use chars and arrays.
  Remember, if I were working with int's: int intArr[3] = {1,2,3};
e*/

#include <stdio.h>
#include <string.h>

char chArr3[] = "hello"; // global def. no reserved byte number needed. still requires the storage.

int main()
{
  // an array of characters. Must be at least one more byte than actual length
  // to accomodate for 'trailing zero', usual to all programming.

  // simple ways of using chars:
  char chArr[5] = "word"; // 5 byte array. C allow set chars when initializing.
  char myChar = 'c'; // 1 byte array. use '' for single char.
  printf("%s, %s, %c\n", chArr3, chArr, myChar); // remember comma after string setup, before variables.

 // set chars like this in an array
  char chArr2[10]; // (compiler)reserves 10 bytes of storage. sizeof(charArr2) would return 10.
  strcpy(chArr2, "123456789");; // setting value to charArr2, defined above.
				// use strcpy as char array can not
				// directly be set eg. chArr2 = "123456789";

  // changing an item in char array
  printf("%s\n", chArr2);
  chArr2[1] = 'F';
  printf("%s\n", chArr2);

  // start with an unknown char byte length.
  static char chArr4[] = "world"; // defined this way when it is a local
 				  // variable to function(main)
  printf("%s\n", chArr4);

  // char pointer
  char *p; // initialize char pointer. 'p' pointer requires 4 bytes of memory
           // on 32bit systems. can be any length of characters. size
           // will auto-increase.

  p = "d"; // p[0] is set. use it by calling the array index, which size
           // was not indicated before because this is a pointer.
  printf("%c\n", p[0]);

  return(0);
}
