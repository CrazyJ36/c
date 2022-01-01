/* Build with: > cl program.c*/
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#pragma comment(lib,"user32.lib") // for autolinking libs at compile time.
#pragma comment(lib,"Gdi32.lib")

int x_point = 50;
int y_point = 50;
int enemy_x = 20;
int enemy_y = 6;
int color = 0x00000000;
int enemy_color = 0x000000FF;
int score = 0;
TCHAR scoreStr[24];
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
            
            Rectangle(hdc, 6, 6, 326, 84);
            // Must setup all initial painting in WM_PAINT, they don't get created in WinMain.
            SetPixel(hdc, x_point, y_point, color); // params: SetPixel(BeginPaint(hWnd, &ps), x_position, y_position, color))
            SetPixel(hdc, x_point + 1, y_point + 1, color); // add diagonally from center point.
            SetPixel(hdc, x_point - 1, y_point - 1, color); // add inverted digonal from center point.
            SetPixel(hdc, x_point, y_point - 1, color); // direct above center point.
            SetPixel(hdc, x_point - 1, y_point, color); // left side of center.
            SetPixel(hdc, x_point + 1, y_point, color); // right side of center.
            SetPixel(hdc, x_point - 1, y_point + 1, color); // left top from center
            SetPixel(hdc, x_point + 1, y_point - 1, color); // right top
            SetPixel(hdc, x_point, y_point - 2, color); // body low
            SetPixel(hdc, x_point, y_point - 3, color); // body high
            SetPixel(hdc, x_point, y_point - 4, color); // head
            SetPixel(hdc, x_point + 2, y_point - 2, color); // right arm
            SetPixel(hdc, x_point - 2, y_point - 2, color); // left arm
            SetPixel(hdc, enemy_x, enemy_y, enemy_color);

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
    wc.hbrBackground = NULL;
    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowEx(0, mClassName, "Avoid Meteors! by CrazyJ36", WS_OVERLAPPEDWINDOW, 740, 350, 348, 128, NULL, NULL, hInstance, NULL);
    if(hWnd == NULL) return 0;
    ShowWindow(hWnd, nCmdShow);

    // Get the threads' activity Message Loop.
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);

        InvalidateRect(hWnd, NULL, TRUE); // allows window to be redrawn into by erasing previous.
        if (x_point >= 323 || x_point <= 8 || y_point <= 11 || y_point >= 82) {
            _stprintf(scoreStr, _T("%d"), score);
            MessageBox(hWnd, strcat("Score: ", scoreStr), "Out of bounds!", MB_OK);
            break;
        }
        if (enemy_x == x_point && enemy_y == y_point ||
            enemy_x == x_point + 1 && enemy_y == y_point + 1 ||
            enemy_x == x_point - 1 && enemy_y == y_point - 1 ||
            enemy_x == x_point && enemy_y == y_point - 1 ||
            enemy_x == x_point - 1 && enemy_y == y_point ||
            enemy_x == x_point + 1 && enemy_y == y_point ||
            enemy_x == x_point - 1 && enemy_y == y_point + 1 ||
            enemy_x == x_point + 1 && enemy_y == y_point - 1 ||
            enemy_x == x_point && enemy_y == y_point - 2 ||
            enemy_x == x_point && enemy_y == y_point - 3 ||
            enemy_x == x_point && enemy_y == y_point - 4 ||
            enemy_x == x_point + 2 && enemy_y == y_point - 2 ||
            enemy_x == x_point - 2 && enemy_y == y_point - 2) {
                // convert int to LPCSTR
                _stprintf(scoreStr, _T("%d"), score);
                MessageBox(hWnd, strcat("Score: ", scoreStr), "You're Hit!", MB_OK);
                break;
        }
        if (enemy_x >= 325) {
            enemy_x = 6;
        }
        if (enemy_y >= 83) {
            enemy_y = 6;
        }
        enemy_x++;
        enemy_y++;
        SetPixel(hdc, enemy_x, enemy_y, enemy_color);

        // Get messages from keys in the main loop.
        if (GetAsyncKeyState(VK_LEFT)) {
            x_point = x_point - 1;
            SetPixel(hdc, x_point, y_point, color);
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            x_point = x_point + 1;
            SetPixel(hdc, x_point, y_point, color);
        }
        if (GetAsyncKeyState(VK_UP)) {
            y_point = y_point - 1;
            SetPixel(hdc, x_point, y_point, color);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            y_point = y_point + 1;
            SetPixel(hdc, x_point, y_point, color);
        }

        Sleep(1);
        score++;
    }
    return Msg.wParam;  // returns messages ONCE after while.
	return 0;
}