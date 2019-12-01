// Use 64 build tools, or it won't run.
// This is A copy of btn-in-window with some editing to see how windows code works.
#include <windows.h>
#include <stdio.h>

#define CLICKED (100)
// A function for the Window Procedure
LRESULT CALLBACK windowProcedure(HWND handlerWindow, UINT uMessage, WPARAM wParameter, LPARAM lParameter) {
    switch(uMessage) {
        case WM_CLOSE:
            DestroyWindow(handlerWindow); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
		case WM_PAINT:
		    PAINTSTRUCT ps;
			HDC hdc = BeginPaint(handlerWindow, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			EndPaint(handlerWindow, &ps); break;
		case WM_COMMAND:
		    MessageBox(NULL, "Clicked", "Done", MB_OK); break;
        default: return DefWindowProc(handlerWindow, uMessage, wParameter, lParameter);
    }
    return 0;
}
// Main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Name for my window class. Gets registered to OS
    const char mClassName[9] = "wndClass";
    // Register the Window Class and set some componetnt data
	WNDCLASSEX wc;
	wc.lpfnWndProc = windowProcedure;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = mClassName;
    RegisterClassEx(&wc);
    // Create A Window
    HWND hWnd = CreateWindowEx(0, mClassName, "Testage", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 512, 248, NULL, NULL, hInstance, NULL);
    HWND hWndButton = CreateWindow("BUTTON", "Dialog", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 86, 32, hWnd, (HMENU)CLICKED, (HINSTANCE)GetWindow(hWnd, GWL_EXSTYLE), NULL);
	// do stuff on btn click using BS_COMMANDLINK above.
	
	// Check CreateWindow success
    if(hWnd == NULL) return 0;
	// Show the window
    ShowWindow(hWnd, nCmdShow);
    // Message Loop
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}