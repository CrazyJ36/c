/* Doc more of this */

#include <windows.h>
// A outer function for the Window Procedure
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd); break;
        case WM_DESTROY:
            PostQuitMessage(0); break;
		// This next case section can be replaced by 'wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);' in register window below after 'WNDCLASSEX wc;'
		case WM_PAINT:
		    PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			EndPaint(hWnd, &ps);
        default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}
// Main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Name for my window class. Gets registered to OS
    const char mClassName[9] = "wndClass";
    // Register the Window Class and set some componetnt data
	WNDCLASSEX wc;
	wc.lpfnWndProc = WndProc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = mClassName;
    RegisterClassEx(&wc);
    // Create A Window
    HWND hWnd = CreateWindowEx(0, mClassName, "Title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 512, 248, NULL, NULL, hInstance, NULL);
	// Check CreateWindow success
    if(hWnd == NULL) return 0;
	// Show the window
    ShowWindow(hWnd, nCmdShow);
    // Message Loop
	MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}