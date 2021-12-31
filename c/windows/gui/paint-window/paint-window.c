/*  Use of Rectangle() requires the Gdi32.lib.
 So to build: cl program.c /link User32.lib Gdi32.lib   */
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
		case WM_PAINT:
		    PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);

            // Rectangle(handle_device_context, left, top, right, bottom);
            Rectangle(hdc, 20, 10, 200, 100);
            EndPaint(hWnd,  &ps);
     
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
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW - 1); 
    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowEx(0, mClassName, "Title", WS_OVERLAPPEDWINDOW, 300, 300, 512, 248, NULL, NULL, hInstance, NULL);
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