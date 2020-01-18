#include <windows.h>

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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char mClassName[24] = "multipleTextLinesClass"; // This required two more index spaces than chars.
    MSG Msg;
	WNDCLASSEX wc;

	wc.lpfnWndProc = WndProc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW);
    wc.lpszClassName = mClassName;
    RegisterClassEx(&wc);

    HWND hWnd = CreateWindowEx(0, mClassName, "Multiple Text Lines", 
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 512, 248, NULL, NULL, hInstance, NULL);
  
    // Two lines of text using different window widgets.
    HWND hWndText1 = CreateWindow("STATIC", "Text line 1", 
        WS_CHILD | WS_VISIBLE, 10, 5, 512, 20, hWnd, NULL, hInstance, NULL);
    HWND hWndText2 = CreateWindow("STATIC", "Text line 2\ndifferent CreateWindow()'s",
        WS_CHILD | WS_VISIBLE, 10, 30, 512, 40, hWnd, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
}