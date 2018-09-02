#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main()
{
    const char *ptr;
    ptr = curses_version();
    printf("%s", ptr);
    printf("\n");
    exit(0);
}
