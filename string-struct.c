#include <stdio.h>

int main()
{
	char tst[12] = ___STRING(test string);
	printf("hi\n"); //  usual printf("");
	printf("%s\n", tst);  // __STRING() variable
	printf(__STRING(string function)); // string function
}
