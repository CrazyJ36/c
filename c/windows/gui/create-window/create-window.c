/*
   Shows how to create A window (only Windows 10 tested).
   Everything not commented is required, thing that are commented don't break
   the window creation by not being there, and are either required for other basic functions
   dealing with the os window or are very useful. 
   Building is architecture specific. So if running desktop apps for 64, use 64 build tools,
   this code with 'CreateWindow' code doesn't work on Windows7 32bit. May be the APIs' fault.
   or the app will show nothing at all, causing confusion.
   
   TODO:Doc more of this
*/

#include <windows.h>

// A outer function for the 'Procedure' of the Window.
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
        /* 
		// Window colors. Can be replaced by
        // 'wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);'
        // in WinMain below after 'WNDCLASSEX wc;'
		case WM_PAINT:
		    PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			EndPaint(hWnd, &ps);
        */
        default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Name for my window class. Gets registered to OS
    const char mClassName[9] = "wndClass";

    // Set some componetnt data, Register the Window Class.
	WNDCLASSEX wc;
	wc.lpfnWndProc = WndProc; // Use top function as this the main procedure
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = mClassName;

    // background colors (int): (COLOR_WINDOW), left out for default, (COLOR_WINDOW+1), +2...
    // wc.hbrBackground = (HBRUSH)(COLOR_WINDOW); 

    RegisterClassEx(&wc);

    // Create A Window
    HWND hWnd = CreateWindowEx(0, mClassName, "Title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 512, 248, NULL, NULL, hInstance, NULL);

	/*
    // Check CreateWindow success
    if(hWnd == NULL) return 0;
    */

	// Show the window
    ShowWindow(hWnd, nCmdShow);

    // Get the threads' activity Message Loop
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    // return Msg.wParam;

	// return 0;
}