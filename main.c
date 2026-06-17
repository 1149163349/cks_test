#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:

        // 人机交互按钮
        CreateWindowW(
            L"BUTTON",
            L"人机交互",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 150, 160, 40,
            hwnd,
            (HMENU)1,
            NULL,
            NULL);

        // 文件管理按钮
        CreateWindowW(
            L"BUTTON",
            L"文件管理",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 230, 160, 40,
            hwnd,
            (HMENU)2,
            NULL,
            NULL);

        // 退出系统按钮
        CreateWindowW(
            L"BUTTON",
            L"退出系统",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 310, 160, 40,
            hwnd,
            (HMENU)3,
            NULL,
            NULL);

        break;

    case WM_COMMAND:

        switch (LOWORD(wParam))
        {
        case 1:
            MessageBoxW(
                hwnd,
                L"你好，我是家庭看护机器人！",
                L"人机交互",
                MB_OK);
            break;

        case 2:
            MessageBoxW(
                hwnd,
                L"文件管理模块开发中……",
                L"文件管理",
                MB_OK);
            break;

        case 3:
            PostQuitMessage(0);
            break;
        }

        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    PWSTR pCmdLine,
                    int nCmdShow)
{
    WNDCLASSW wc = {0};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"RobotWindow";

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowW(
        L"RobotWindow",
        L"家庭看护机器人仿真系统",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,
        600,
        NULL,
        NULL,
        hInstance,
        NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;

    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}