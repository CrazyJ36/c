/* Build with: > cl program.c*/
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <winternl.h>

#pragma comment(lib,"user32.lib") // for auto-linking libs at compile time without having to manually each time.
#pragma comment(lib,"Gdi32.lib")
#pragma comment(lib,"ntdll.lib")

int x_point = 50;
int y_point = 50;
int enemy_x = 20;
int enemy_y = 6;
int color = 0x00000000;
int enemy_color = 0x000000FF;
int score = 0;
int random = 0;
int clock_speed = -50000; // below the default of 1 millisecond.
TCHAR scoreStr[24];
PAINTSTRUCT ps;
HDC hdc;

// For delay
ULONG actualResolution;
LARGE_INTEGER interval;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
		case WM_CREATE:
            case WM_PAINT:
                hdc = BeginPaint(hWnd, &ps);

                Rectangle(hdc, 6, 5, 326, 84);

                // Must setup all initial painting in WM_PAINT, they don't get created in WinMain.
                SetPixel(hdc, x_point, y_point, color); // params: SetPixel(hdc), x_position, y_position, color))
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
                SetPixel(hdc, enemy_x + 1, enemy_y, enemy_color);
                SetPixel(hdc, enemy_x - 1, enemy_y - 2, enemy_color);
                SetPixel(hdc, enemy_x + 1, enemy_y - 1, enemy_color);

                EndPaint(hWnd, &ps);

                // Delay
                ZwSetTimerResolution(1, TRUE, &actualResolution); // modify the system clock frequency.
                interval.QuadPart = clock_speed;
                NtDelayExecution(FALSE, &interval); //Delay execution with the value of interval.

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

    // Custom Icons:
    // wc.hIcon = LoadImage(hInstance, C:\string\path\name.ico, [type 1=icon, 2=cursor, 0=bitmap], width, height, LR_LOADFROMFILE);
    wc.hIcon = LoadImage(hInstance,
        "C:\\Users\\crazy\\development\\c\\c\\windows\\gui\\avoid-meteors-game\\icon.ico",
        1, 11, 11, LR_LOADFROMFILE);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = mClassName;
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 2);
    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowEx(0, mClassName, "Avoid Meteors! by CrazyJ36", WS_OVERLAPPEDWINDOW,
        740, 350, 348, 128, NULL, NULL, hInstance, NULL);
    if(hWnd == NULL) return 0;
    ShowWindow(hWnd, nCmdShow);

    // Get the threads' activity Message Loop.
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        
        TranslateMessage(&Msg); // Always translate and dispatch messages on top or
        DispatchMessage(&Msg);

        if (enemy_x >= 324) {
            enemy_x = 6;
        }
        if (enemy_y >= 83) {
            enemy_y = 6;
        }
        random++;
        if (random % 5 == 0) {
            enemy_x = enemy_x + 2;
        } else {
            enemy_x++;
        }
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
        score++;
        _stprintf(scoreStr, _T("%d"), score);
 
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
                MessageBox(hWnd, strcat("Score: ", scoreStr), "You're Hit!", MB_OK);
                break;
        }

        if (x_point >= 323 || x_point <= 8 || y_point <= 9 || y_point >= 82) {
            MessageBox(hWnd, strcat("Score: ", scoreStr), "Out of bounds!", MB_OK);
            break;
        }

        InvalidateRect(hWnd, NULL, FALSE); // erase window each loop.
    
    }
    return Msg.wParam; // returns messages ONCE after while.

    // Freeing some vars will make the program close faster because the OS doesn't have to free them itself.
    free(&Msg);free(&ps);free(&wc);free(&hWnd);free(&hdc);free(&scoreStr);free(&lpCmdLine);free(&x_point);
    free(&y_point);free(&enemy_x);free(&enemy_y);free(&score);free(&color);free(&enemy_color);free(&clock_speed);
    free(&actualResolution);free(&interval);free(&scoreStr);free(&nCmdShow);free(&hInstance);free(&random);
	return 0;

}