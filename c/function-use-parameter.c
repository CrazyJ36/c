/*
 * A function that acts on A function parameter.
*/

#include <stdio.h>

void mfunc(char c); // The function doesn't need to return anything(it is void), as only A parameter is used.

int main()
{
    mfunc('a');
}

void mfunc(char c)
{
    printf("%c\n", c);
}
