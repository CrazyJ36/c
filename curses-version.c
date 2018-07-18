#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main()
{
	const char *vptr;
	vptr = curses_version();
	printf("%s", vptr);
    exit(0);	
}