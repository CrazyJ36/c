#include <stdio.h>

int main()
{
  int mint = 4;
  char mchar = 'c';
  long mlong = 1000000;
  /* - Double is A 64 bit IEEE 754 double precision Floating Point Number
     - Double the size of float, occupies twice the memory. The exact memory
       depends on system architecture.
     - Double is more precise than float for real numbers.
     - Double has 15 decimal digits of percision */
  double mdouble = 2.00000000000012;
  /* float is as 32 bit IEEE 754 single percision Floating Point Number
     float has 7 decimal digits of precision. */
  float mfloat = 1.2;

  // show mix, max values for int...
  // printf("int max value: %d\n", max_int);

  /* The mdouble is stored as  type float, because the pc converts types to binary(1001011..), and 
     becuase the compiler sees 1.2 as 1, then 2, in binary format... */

  // TODO: get double and float to print as is (double %d)
  printf("size of int %d (byte), size of char %d..., long %d, double %d, float %d\n", sizeof(mint), sizeof(mchar), sizeof(mlong), sizeof(mdouble), sizeof(mfloat));

  return(0);

}
