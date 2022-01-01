/* Build with: > cl program.c*/
#include <windows.h>

#pragma comment(lib,"user32.lib") // for autolinking libs at compile time.
#pragma comment(lib,"Gdi32.lib")

PAINTSTRUCT ps;
HDC hdc;
x_pos = 10;
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
		case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            // Initial Paint
            SetPixel(hdc, x_pos, 10, 0x00000000); // start pixel
            
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
    HWND hWnd = CreateWindowEx(0, mClassName, "Title", WS_OVERLAPPEDWINDOW, 740, 350, 348, 128, NULL, NULL, hInstance, NULL);
    if(hWnd == NULL) return 0;
    ShowWindow(hWnd, nCmdShow);

    // Get the threads' activity Message Loop.
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);

        if (GetAsyncKeyState(VK_LEFT)) {
            InvalidateRect(hWnd, &ps.rcPaint, FALSE);
            x_pos = x_pos + 5;
            // New Paint after initial WM_PAINT
            SetPixel(hdc, x_pos, 10, 0x00000000); // params: SetPixel(BeginPaint(hWnd, &ps), x_position, y_position, color))
        }

    }
    return Msg.wParam; 
	return 0;
}