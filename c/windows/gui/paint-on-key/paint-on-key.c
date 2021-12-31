/* Build with: > cl program.c /link User32.lib Gdi32.lib */
#include <windows.h>

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
            hdc = BeginPaint(hWnd, &ps);
            // params: SetPixel(BeginPaint(hWnd, &ps), x_position, y_position, color)) 
            /* Some colors for Pixel:
            Red = 0x000000FF, Green = 0x0000FF00, Blue 0x00FF0000, Black =  0x00000000, White 0x00FFFFFF; */
			SetPixel(hdc, x_point, y_point, 0x00000000);
			EndPaint(hWnd, &ps);
            // The following code block would only be able to run once as it's in the windows constructing procedure,
            // not in the Main message loop which is below in WinMain while (GetMessage()).
          /*case WM_KEYDOWN:
                switch (wParam) {
                    case VK_LEFT:
                        x_point = x_point + 5;
                        InvalidateRect(hWnd, NULL, FALSE); // (hWnd, RECT, bool_erase)
                        hdc = BeginPaint(hWnd, &ps);
                        SetPixel(hdc, x_point, y_point, 0x00000000);
                        EndPaint(hWnd, &ps);
                        UpdateWindow(hWnd);  
                }*/
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
    HWND hWnd = CreateWindowEx(0, mClassName, "Title", WS_OVERLAPPEDWINDOW, 500, 300, 128, 128, NULL, NULL, hInstance, NULL);
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
                hdc = BeginPaint(hWnd, &ps); // Painting over hWnd.
                if (GetAsyncKeyState(VK_LEFT) & 0x25) {
                    x_point = x_point - 1;
                    InvalidateRect(hWnd, NULL, TRUE); // params: (hWnd, RECT, bool_erase_rect) 
                    SetPixel(hdc, x_point, y_point, 0x00000000);
                    UpdateWindow(hWnd);
                }
                if (GetAsyncKeyState(VK_RIGHT)) {
                    x_point = x_point + 1;
                    InvalidateRect(hWnd, NULL, TRUE);
                    SetPixel(hdc, x_point, y_point, 0x00000000);
                    UpdateWindow(hWnd);
                }
                EndPaint(hWnd, &ps);
        }
    }
    return Msg.wParam;  // returns messages ONCE after while.

	return 0;
}