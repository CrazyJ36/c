#include <windows.h>

/* Strings in '#define': you don't have to count needed characters, concatenates
   at compile time, can still use functions like sizeOf(MSG).
*/
#define MSG "Important message:\nNot really."

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
    char title[6] = "Hello";
	MessageBox(NULL, MSG, title, MB_YESNOCANCEL | MB_DEFBUTTON2 | MB_ICONQUESTION);
	exit(0);
}