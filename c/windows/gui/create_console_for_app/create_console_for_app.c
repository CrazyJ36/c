#include <windows.h>
#include <stdio.h>
#include <io.h>

// Random IDs for buttons.
#define BTN1 1

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {

        // Get the clicked command from BTN1, which is initialized to the window in WinMain().
        case WM_COMMAND:
            switch(wParam) {
                case(BTN1):
                    // Setup A filestream to stdout for the open console and print to it.
                    FILE *f;
                    freopen_s(&f, "CONOUT$", "w", stdout); 
                    printf("test printf on our console window.\n");
                    return 0;
            }

        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
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
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wc.lpszClassName = mClassName;
    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowEx(0, mClassName, "App with Console", WS_OVERLAPPEDWINDOW, 248, 512, 348, 248, NULL, NULL, hInstance, NULL);
    if(hWnd == NULL) return 0;

    // Attach A button to our apps' hWnd window.
    HWND hWndButton1 = CreateWindow("BUTTON", "Button1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 86, 32, hWnd, (HMENU)BTN1, (HINSTANCE)GetWindow(hWnd, GWL_EXSTYLE), NULL);
    // Open/Attach A console to this application for use in WM_COMMAND in WndProc.
    AllocConsole();
    
    ShowWindow(hWnd, nCmdShow);
    MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}
