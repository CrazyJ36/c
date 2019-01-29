/* <windows.h> is A master include file that includes other important
  Windows headers like: windef.h, winnt.h, winbase.h, winuser.h, wingdi.h.
*/
#include <windows.h>

/* This commented line is A preprocessor for including A windows lib,
    by placing A comment record into an object file.
	pragma instructs the compiler to perform action at compile time.
  - pragma comment-type is one of the predefined identifiers.
    Using A string literal comment definition, as:
	#pragma comment(comment-type, [, "commentstring"])
  - pragma instance flags preprocessor command controls the way instances
    are created or updated depending on the flags.
  - You can get the same library included at cmd-line compile time with:
    > cl program.c /link User32.LIB
*/
//#pragma comment(lib,"user32.lib");

/* About the entry point.
   - WinApi is defined in windef.h. Places windows functions on the calling stack.
   - WinMain(hInstance) is an instance handle(HINSTANCE), or an id that an application
     uses to identify itself to windows. Can be an argument to other windows functions.
   - WinMain(prevInstance) is A point to save/reuse code/memory from last program
     run, or when running multiple instances. This is always null(0) since 32bit.
   - LPSTR lpCmdLine, is (long string pointer, variable command-line run task).
   - int nCmdShow is how th programs initially displays itself(normal window, maximized, etc..).
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
	{
/* MessageBox is A small dialog window.
  - First argument is normally A window handle.
  - Second arg is A string that shows as message.
  - Third is A string that appears in caption/title bar of messagebox.
  - Fourth MB_OK is predefined button constant types beginning with MB_, these are defined in winuser.h as:
    ____
    #define MB_OK 0x00000000L
    #define MB_OKCANCEL 0x00000001L	
	____
	You can use the terms MB_.., or the constant hex number as last MessageBox argument.
	Default is OK by typing 0 instead of MB_.
*/
		MessageBox(NULL, "Hello, World.", "Window Title", MB_OK);
		return 0;
	}