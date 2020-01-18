#include <windows.h>

// These initialize A string buffer to get editControl to global string
char STRLINE[32] = "";
HWND hWndEdit;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_COMMAND:
            
            // get current editControl text and use it
            GetWindowText(hWndEdit, STRLINE, 32);
            MessageBox(hWnd, STRLINE, "What you entered", MB_OK);
            break;

        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam); // main loop
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    const char mClassName[17] = "getEditTextClass";
    MSG Msg;
    WNDCLASSEX wc;
    wc.lpfnWndProc = WndProc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = mClassName;
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW); 
    RegisterClassEx(&wc);
    
    HWND hWnd = CreateWindowEx(0, mClassName, "Get Edit Text", 
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
        512, 248, NULL, NULL, hInstance, NULL);

    HWND hWndText2 = CreateWindow("STATIC", "Enter text, then push show.", 
        WS_VISIBLE | WS_CHILD, 10,10,512,20,
        hWnd, NULL, hInstance, NULL);
    HWND hWndButton = CreateWindow("BUTTON", "Show", 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 30, 50, 20, hWnd, (HMENU)1, (HINSTANCE)GetWindow(hWnd, GWL_EXSTYLE), NULL);

    // globally defined earier, finish setting up editControl. "EDIT" makes this an edittext 'widget'
    // DT_SINGLELINE flag is blanked(password), EM_GETLINE allows multiline.
    hWndEdit = CreateWindow("EDIT", "",
        WS_CHILD | WS_BORDER | WS_VISIBLE, 
        10, 55, 256, 20, hWnd, NULL, NULL, NULL);
    
    ShowWindow(hWnd, nCmdShow);
    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
}