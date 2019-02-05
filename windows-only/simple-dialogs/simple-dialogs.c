#include <windows.h>
#pragma comment(lib,"user32.lib")

// defining here concatenates at compile time
#define MSG "Select an option.."
#define title "Hello"
#define title2 "Confirm"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
	int diag = MessageBox(NULL, MSG, title, MB_YESNOCANCEL | MB_DEFBUTTON2 | MB_ICONQUESTION);
	
	char response[12] = ""; // char array buffer, max 12 chars for  the if'responses'
	if (diag == IDNO) {
	    strcpy(response, "Clicked No");
	} else if (diag == IDYES) {
		strcpy(response, "Clicked Yes");
	} else if (diag == IDCANCEL) {
	    exit(1223); // 1223 Is exit code for "the operation was cancelled by user".
	}
	MessageBox(NULL, response, title2, MB_OK);
	exit(0);
}