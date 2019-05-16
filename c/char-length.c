#include <stdio.h>
#include <string.h>

void main()
{
        // You could define the length of char array here as: 'x[5]'
        // for A character array of 'apes'. But we'll find the length.. 
	char x[] = "apes";
        // strlen() returns an int: the char length of A string which is the paramater
	int y = strlen(x);
	printf("x is %d chars\n", y);
}
