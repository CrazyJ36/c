/* Build with: > cl program.c*/
#include <windows.h>
#include <stdio.h>

#pragma comment(lib,"user32.lib") // for autolinking libs at compile time.
#pragma comment(lib,"Gdi32.lib")

int x_point = 50;
int y_point = 50;
int enemy_x = 0;
int enemy_y = 0;
int color = 0x00000000;
int enemy_color = 0x000000FF;
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
            // Must setup all needed points in WM_PAINT, or they don't get created in WinMain. 
            SetPixel(hdc, x_point, y_point, color); // params: SetPixel(BeginPaint(hWnd, &ps), x_position, y_position, color))
            SetPixel(hdc, x_point + 1, y_point + 1, color); // add diagonally from center point.
            SetPixel(hdc, x_point - 1, y_point - 1, color); // add inverted digonal from center point.
            SetPixel(hdc, x_point, y_point - 1, color); // direct above center point.
             SetPixel(hdc, x_point, y_point + 1, color); // direct below center point.
            SetPixel(hdc, x_point - 1, y_point, color); // left side of center.
            SetPixel(hdc, x_point + 1, y_point, color); // right side of center.
            SetPixel(hdc, x_point - 1, y_point + 1, color); // left top from center
            SetPixel(hdc, x_point + 1, y_point - 1, color); // right top
           

            SetPixel(hdc, enemy_x, enemy_y, 0x00000000);
            for (int line_top = 6; line_top < 326; line_top++) {
                SetPixel(hdc, line_top, 5, 0x00000000);
            }
            for (int line_bottom = 6; line_bottom < 326; line_bottom++) {
                SetPixel(hdc, line_bottom, 83, 0x00000000);
            }
            for (int line_left = 5; line_left < 84; line_left++) {
                SetPixel(hdc, 5, line_left, 0x00000000);
            }
            for (int line_right = 5; line_right < 84; line_right++) {
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
    HWND hWnd = CreateWindowEx(0, mClassName, "Avoid Meteors!", WS_OVERLAPPEDWINDOW, 740, 350, 348, 128, NULL, NULL, hInstance, NULL);
    if(hWnd == NULL) return 0;
    ShowWindow(hWnd, nCmdShow);

    // Get the threads' activity Message Loop.
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);

        if (enemy_x >= 326) {
            enemy_x = 0;
        }
        if (enemy_y >= 84) {
            enemy_y = 0;
        }
        enemy_x++;
        enemy_y++;
        InvalidateRect(hWnd, NULL, TRUE);
        SetPixel(hdc, enemy_x, enemy_y, 0x00000000);
        
        // Get messages from keys in the main loop.
        if (GetAsyncKeyState(VK_LEFT)) {
            x_point = x_point - 1;
            InvalidateRect(hWnd, NULL, TRUE);
            SetPixel(hdc, x_point, y_point, 0x00000000);
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            x_point = x_point + 1;
            InvalidateRect(hWnd, NULL, TRUE);
            SetPixel(hdc, x_point, y_point, 0x00000000);
        }
        if (GetAsyncKeyState(VK_UP)) {
            y_point = y_point - 1;
            InvalidateRect(hWnd, NULL, TRUE);
            SetPixel(hdc, x_point, y_point, 0x00000000);
 
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            y_point = y_point + 1;
            InvalidateRect(hWnd, NULL, TRUE);
            SetPixel(hdc, x_point, y_point, 0x00000000);
        }

        if (enemy_x == x_point && enemy_y == y_point ||
            x_point + 1, y_point + 1
            x_point - 1, y_point - 1
            ) {
                InvalidateRect(hWnd, NULL, TRUE);
                MessageBox(hWnd, "You're Hit!", "Score", MB_OK);
                break;
            
        }

    }

    return Msg.wParam;  // returns messages ONCE after while.
	return 0;
}