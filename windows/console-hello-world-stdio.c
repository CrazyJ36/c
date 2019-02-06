/* No different than linux, uses stdio.h. Console apps don't need WinMain,
   TODO: Look into the ability to use WINAPI functions(requiring windows.h)
   with console apps.*/

#include <stdio.h>
int main()
{
    printf("Hello, World!");
	return 0;
}