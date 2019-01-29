#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
	// MB_YESNOCANCEL shows three buttons(yes,no,cancel)
	// MB_DEFBUTTON2 mean second option(no) is the default option
	// MB_ICONQUESTION states the type of dialog(different icons and alert sounds): MB_ICON[WARNING,QUESTION,EXCLAMATION,ASTERISK]
    // MessageBox can return IDOK,IDNO,IDCANCEL,IDABORT,IDRETRY,IDIGNORE. These have simple numbers assigned to them as well.
	MessageBox(NULL, "Done", "Title", MB_YESNOCANCEL | MB_DEFBUTTON2 | MB_ICONQUESTION);
	return(0);
}