#include <windows.h>

/* Strings in '#define': you don't have to count needed characters, concatenates
   at compile time, can still use functions like sizeOf(MSG).
*/
#define MSG "Important message:\nNot really."

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
	/* MB_YESNOCANCEL shows three buttons(yes,no,cancel)
	  MB_DEFBUTTON2 mean second option(no) is the default option
	  MB_ICONQUESTION states the type of dialog(different icons and alert sounds): 
	  MB_ICON[WARNING,QUESTION,EXCLAMATION,ASTERISK]
      MessageBox can return IDOK,IDNO,IDCANCEL,IDABORT,IDRETRY,IDIGNORE.
	  These have simple numbers assigned to them as well.
	*/
	
	// Defining title string
    char title[6] = "Hello";
	
	MessageBox(NULL, MSG, title, MB_YESNOCANCEL | MB_DEFBUTTON2 | MB_ICONQUESTION);
	
	exit(0);
}