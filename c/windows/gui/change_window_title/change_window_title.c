#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
        case WM_COMMAND:
            // Changing window title
            SetWindowText(hWnd, "New Window Title");

        default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char mWinClassName[9] = "wndClass";
    MSG Msg;
	WNDCLASSEX wc;

	wc.lpfnWndProc = WndProc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = mWinClassName;
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW);
    RegisterClassEx(&wc);

    HWND hWnd = CreateWindowEx(0, 
        mWinClassName, "Window Title", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 386, 128,
        NULL, NULL, hInstance, NULL);

    HWND hWndButton = CreateWindow("BUTTON", "Title", WS_VISIBLE | WS_CHILD,
        8, 8, 70, 25, hWnd, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
}