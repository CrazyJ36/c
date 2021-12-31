/* To build: cl program.c /link User32.lib */
#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
        case WM_KEYDOWN:
            // You can use if, or switch as below.
            /*if (wParam == VK_LEFT) {
                // in the case that the wParam of WM_KEYDOWN is VK_LEFT, show this messagebox.
                MessageBox(NULL, "Left pressed.", "Confirmation", MB_OK);
            }
            break; */
            switch (wParam) {
                case VK_LEFT:
                    MessageBox(NULL, "Left pressed.", "title left", MB_OK);
                    break;
                case VK_RIGHT:
                    MessageBox(NULL, "Right pressed.", "title right", MB_OK);
                    break;
            }
        
        default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char mClassName[9] = "wndClass";
	WNDCLASSEX wc;
	wc.lpfnWndProc = WndProc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = mClassName; 
    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowEx(0, mClassName, "Title", WS_OVERLAPPEDWINDOW, 300, 300, 512, 248, NULL, NULL, hInstance, NULL);
    // Static window within our main window that displays text.
    HWND hWndText = CreateWindow("STATIC", "Press left or right", WS_VISIBLE | WS_CHILD, 10, 10, 200, 20, hWnd, NULL, hInstance, NULL);
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