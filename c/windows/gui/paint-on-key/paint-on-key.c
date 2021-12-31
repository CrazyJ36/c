/* Build with: > cl program.c*/
#include <windows.h>

#pragma comment(lib,"user32.lib") // for autolinking libs at compile time.
#pragma comment(lib,"Gdi32.lib")

int x_point = 50;
int y_point = 50;
int enemy_x = 0;
int enemy_y = 0;

PAINTSTRUCT ps;
HDC hdc;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
		case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
			SetPixel(hdc, x_point, y_point, 0x00000000); // params: SetPixel(BeginPaint(hWnd, &ps), x_position, y_position, color))
            for (int line_top = 6; line_top < 326; line_top++) {
                InvalidateRect(hWnd, NULL, FALSE);
                SetPixel(hdc, line_top, 5, 0x00000000);
            }
            for (int line_bottom = 6; line_bottom < 326; line_bottom++) {
                InvalidateRect(hWnd, NULL, FALSE);
                SetPixel(hdc, line_bottom, 83, 0x00000000);
            }
            for (int line_left = 5; line_left < 84; line_left++) {
                InvalidateRect(hWnd, NULL, FALSE);
                SetPixel(hdc, 5, line_left, 0x00000000);
            }
            for (int line_right = 5; line_right < 84; line_right++) {
                InvalidateRect(hWnd, NULL, FALSE);
                SetPixel(hdc, 326, line_right, 0x00000000);
            }
            EndPaint(hWnd, &ps);
            return 0;
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
    HWND hWnd = CreateWindowEx(0, mClassName, "Title", WS_OVERLAPPEDWINDOW, 740, 350, 348, 128, NULL, NULL, hInstance, NULL);
    if(hWnd == NULL) return 0;
    ShowWindow(hWnd, nCmdShow);

    // Get the threads' activity Message Loop.
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
        // Get messages from keys in the main loop.
        if (GetAsyncKeyState(VK_LEFT)) {
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
        if (GetAsyncKeyState(VK_UP)) {
            y_point = y_point - 1;
            InvalidateRect(hWnd, NULL, TRUE);
            SetPixel(hdc, x_point, y_point, 0x00000000);
            UpdateWindow(hWnd);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            y_point = y_point + 1;
            InvalidateRect(hWnd, NULL, TRUE);
            SetPixel(hdc, x_point, y_point, 0x00000000);
            UpdateWindow(hWnd);
        }
        
    }
    return Msg.wParam;  // returns messages ONCE after while.

	return 0;
}