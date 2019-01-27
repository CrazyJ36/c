#include <windows.h>
//#pragma comment(lib,"user32.lib");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
	{
		MessageBox(NULL, "Hello, World.", "Window Title", MB_OK);
		return 0;
	}