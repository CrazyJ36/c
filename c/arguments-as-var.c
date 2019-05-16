#include <stdio.h>

int main(int argc, char *argv[])
{
	char *arg = argv[1];
	printf("arg 1 is: %s\n", &arg);
	return(0);
}