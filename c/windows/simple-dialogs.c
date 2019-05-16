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

/*
- int: to return A status code after program completion. The return value is not used
 by the operating system, but can be used by your other programs.
- WINAPI is microsofts core set of apis'. Needed here to use the API. This Calling Convention
 defines how A function receives parameters from the caller(as in windows api stack).
- WinMain is the program entry point to the windows os. Not always required
 for cmdline programs(not worth it when using only stdio.h text program), though windows may not know
 anything about the program. Its parameters:
 - HINSTANCE hInstance: A handle id to the instance of this program used by Windows to
   identify it while loaded in memory.
 - HINSTANCE hPrevInstance: no usable meaning, was used in 16 bit Windows, always returns zero now.
 - PSTR pCmdLine: string pointer that contains the programs command line arguments.
   get these run-time args with GetCommandLine function.
 - int CmdSHow: A flag that says whether the main application will be minimized,
   maximized, or shown normally. */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    PSTR cmdLine, int nCmdShow)
{
/* int diag MessageBox: returns int(The dialog button clicked), diag reference variable name, MessageBox function.
params:
- NULL: is in place for HWND(window handler) as this program has no CreateWindow() as root window.
- MSG: A LPCSTR(long pointer const string, or other char-like type) that holds the message
 text to be displayed in the dialog. This field was defined in the pre-processor line as "Select an option...".
- title: dialog box title caption. NULL here defaults to string "error"
- MB_: defines the boxs' style and behaviour. There are numerous ways to organize the dialog per usage purpose. */
	int diag = MessageBox(NULL, MSG, title, MB_YESNOCANCEL | MB_DEFBUTTON2 | MB_ICONQUESTION);
	
	
	char response[12] = ""; // char array buffer, max 12 chars for  the if'responses'
	if (diag == IDNO) { // or 7 as ID
	strcpy(response, responseNo);
	} else if (diag == IDYES) { // or 6 
		strcpy(response, responseYes);
	} else if (diag == IDCANCEL) { // or 2
	    exit(1223); // 1223 Is exit code for "the operation was cancelled by user".
	}
	// another messagebox with 'response' text defined in the if statements above.
	MessageBox(NULL, response, title2, MB_OK); // MB_OK is status code 1
	exit(0);
}