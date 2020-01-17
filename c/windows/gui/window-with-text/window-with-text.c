#include <windows.h>

#define my_text "This is text that will show in the window frame."

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
        default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Main window definition
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char mClassName[9] = "wndClass";
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
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW); 
    RegisterClassEx(&wc);

    HWND hWnd = CreateWindowEx( 0, mClassName, "Title", WS_OVERLAPPEDWINDOW, 300, 300, 512, 248, NULL, NULL, hInstance, NULL);

    HWND hWndText = CreateWindow("STATIC", my_text, WS_VISIBLE | WS_CHILD, 10,10,512,100, hWnd, NULL, hInstance, NULL);

    if(hWnd == NULL) return 0;
    ShowWindow(hWnd, nCmdShow);
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
	return 0;
}