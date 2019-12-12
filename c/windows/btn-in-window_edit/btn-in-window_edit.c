/* Build with 64 arch on 64bit windows:
   cl btn-in-window_edit.c /link User32.LIB
*/

#include <windows.h>
#include <stdio.h>

// Button ids
#define CLICKED1 (100)
#define CLICKED2 (101)

// Window Procedure
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
		case WM_PAINT:
		    PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			EndPaint(hWnd, &ps); break;

		// Button Actions using 'case the ids'
        case WM_COMMAND:
            switch(wParam) {
                case(CLICKED1):
                    MessageBox(NULL, "Clicked1", "For Button1", MB_OK); break;
                case(CLICKED2):
                    MessageBox(NULL, "Clicked2", "For Button2", MB_OK); break;
            }
		    
        default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Name for my window OS class.
    const char mClassName[9] = "wndClass";

    // Register Window Class and set some componetnt data
	WNDCLASSEX wc;
	wc.lpfnWndProc = WndProc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = mClassName;
    RegisterClassEx(&wc);

    // Create A Window
    HWND hWnd = CreateWindowEx(0, mClassName, "Title1", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 512, 248, NULL, NULL, hInstance, NULL);
    HWND hWndButton1 = CreateWindow("BUTTON", "Button1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 86, 32, hWnd, (HMENU)CLICKED1, (HINSTANCE)GetWindow(hWnd, GWL_EXSTYLE), NULL);
	HWND hWndButton2 = CreateWindow("BUTTON", "Button2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 100, 10, 86, 32, hWnd, (HMENU)CLICKED2, (HINSTANCE)GetWindow(hWnd, GWL_EXSTYLE), NULL);
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