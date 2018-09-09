#include <stdio.h>

int main()
{
	char tst[12] = __STRING(test string); // variable is string function
	printf("hi\n"); //  usual printf("");
	printf("%s\n", tst);  // variable insert
	printf(__STRING(string function)); // __STRING(char)
        printf("\n");
        return(0);
}
