#include <windows.h>
/* 
- #pragma: optional. Here, it calls "desktop program" linker in code to be
read during compilation. The Pragma pre-processor directive
itself specifies machine or operating specific Microsoft compiler features.
You can code pragma directives within macro(single instruction that expands
to A set of instructions to perform A task.) definitions.
- 'comment': A predefined pragma identifier. There are several. It places A
needed record into an obj or exe.
- lib: places A library search record in the obj file.
- "User32.LIB": uppercase optional, 2nd param requires name(or path) of the desired lib.
user32.lib is A library used to code desktop(user) apps in win32(32).

If this wasn't in the code, you would link "user32.lib" when compiling with:
> cl program.c /link User32.LIB
*/
#pragma comment(lib,"user32.lib") // or: __pragma( comment(lib,"user32.lib") ) // two underscores

/* defining strings as pre-processor forces concatenation at compile time,
  requires no memory as it's replacing text with literal, 
  and no hard-coded type means it can be used for any function.
  These can't be used if A pointer needs passed though.
*/
#define MSG "Select an option..."
#define title "Hello"
#define title2 "Confirm"
#define responseNo "Clicked No... Boo!"
#define responseYes "Clicked Yes! Hooray!"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
	int diag = MessageBox(NULL, MSG, title, MB_YESNOCANCEL | MB_DEFBUTTON2 | MB_ICONQUESTION);
	
	char response[12] = ""; // char array buffer, max 12 chars for  the if'responses'
	if (diag == IDNO) {
	strcpy(response, responseNo);
	} else if (diag == IDYES) {
		strcpy(response, responseYes);
	} else if (diag == IDCANCEL) {
	    exit(1223); // 1223 Is exit code for "the operation was cancelled by user".
	}
	MessageBox(NULL, response, title2, MB_OK);
	exit(0);
}