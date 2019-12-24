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
// include the general windows header
#include <windows.h>

// A outer function for the running 'Procedure' of the Window.
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        // Close button clicked
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        // destroyed, by crash maybe?
        case WM_DESTROY:
            PostQuitMessage(0); break;
        /* 
		// Window colors and graphics. background can be replaced by
        // 'wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);'
        // in WinMain below after 'WNDCLASSEX wc;'
		case WM_PAINT:
		    PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			EndPaint(hWnd, &ps);
        */
        // defining this is the windows procedure.
        default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    
    return 0;
}

// Main window definition
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Name for my window class. Gets registered to OS
    const char mClassName[9] = "wndClass";

    // Set some componetnt data, Register the Window Class.
	WNDCLASSEX wc;
	wc.lpfnWndProc = WndProc; // Use top function as this the main procedure
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    // window icon
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    // window cursor used 
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    // class name used
    wc.lpszClassName = mClassName;

    // another way to window colors (int):
    // (COLOR_WINDOW), left out for default, (COLOR_WINDOW+1), +2...
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW); 

    // register the new window class to OS.
    RegisterClassEx(&wc);

    // Create A Window
    // CW_USEDEFAULT int available for all size and position.
    HWND hWnd = CreateWindowEx(
    0,  // dwExStyle, Optional window styles
    mClassName, // lpClassName, window class used
    "Title",  // lpWindowName, window text at titlebar
    WS_OVERLAPPEDWINDOW,  // dwStyle, window style
    300,  // X, horizontal position, less is to the left of screen
    300, // Y, vertical position. less is higher on screen 
    512,  // nWidth, width of window out of screen pixels. probably not over a minimum 800. 'standard' 512
    248,  // nHeight, height of window out of screen pixels. minumum 600. 'standard' 248
    NULL,  // HWND hWndParent, Parent window
    NULL,  // HMENU hMenu, Menu
    hInstance,  // HINSTANCE hInstance, Instance Handle
    NULL // LPVOID lpParam, Additional appliation data
    );

    // Check CreateWindow success
    if(hWnd == NULL) return 0;

	// Show the window
    ShowWindow(hWnd, nCmdShow);

    // Get the threads' activity Message Loop.
    // Research and doc to send recieve messages in windows.
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;  // return messages from loop?

	return 0; // show run success to OS.
}