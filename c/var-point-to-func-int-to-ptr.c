// int to pointer


#include <stdlib.h>
int main()
{
    intptr_t my_int_pointer = rand();

    // using casting like javas': Button btn = (Button) findViewById()
    printf("Random Number: %ld\n", (intptr_t)my_int_pointer);
    // uintptr_t can be used similarly for pointer-to-int

    return(0);
}
