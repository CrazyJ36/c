/* Build with: > cl program.c*/
#include <windows.h>

#pragma comment(lib,"user32.lib") // for autolinking libs at compile time.
#pragma comment(lib,"Gdi32.lib")

int x_point = 50;
int y_point = 50;
PAINTSTRUCT ps;
HDC hdc;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
		case WM_PAINT:
        PAINTSTRUCT ps;
            hdc = BeginPaint(hWnd, &ps); 
			SetPixel(hdc, x_point, y_point, 0x00000000); // params: SetPixel(BeginPaint(hWnd, &ps), x_position, y_position, color))
			EndPaint(hWnd, &ps);
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
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW);
    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowEx(0, mClassName, "Title", WS_OVERLAPPEDWINDOW, 300, 300, 512, 248, NULL, NULL, hInstance, NULL);
    if(hWnd == NULL) return 0;
    ShowWindow(hWnd, nCmdShow);

    // Get the threads' activity Message Loop.
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);

        // Get messages from keydown in the main loop.
        switch (Msg.message) {
            case WM_KEYDOWN:
                if (GetAsyncKeyState(VK_LEFT) & 0x25) {
                    x_point = x_point - 1;
                    InvalidateRect(hWnd, NULL, TRUE);
                    SetPixel(hdc, x_point, y_point, 0x00000000);
                    UpdateWindow(hWnd);
                }
                if (GetAsyncKeyState(VK_RIGHT)) {
                    x_point = x_point + 1;
                    InvalidateRect(hWnd, NULL, TRUE);
                    SetPixel(hdc, x_point, y_point, 0x00000000);
                    UpdateWindow(hWnd);

                }
        }
    }
    return Msg.wParam;  // returns messages ONCE after while.

	return 0;
}