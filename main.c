#include <windows.h>
#include "file.h"

// 按钮ID
#define ID_INTERACT 1
#define ID_SERVICE 2
#define ID_HEALTH 3
#define ID_FILE 4
#define ID_ALARM 5
#define ID_EXIT 6

// 窗口过程函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:

        // 人机交互
        CreateWindowW(
            L"BUTTON", L"人机交互",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 80, 160, 40,
            hwnd, (HMENU)ID_INTERACT,
            NULL, NULL);

        // 家务服务
        CreateWindowW(
            L"BUTTON", L"家务服务",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 140, 160, 40,
            hwnd, (HMENU)ID_SERVICE,
            NULL, NULL);

        // 健康监测
        CreateWindowW(
            L"BUTTON", L"健康监测",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 200, 160, 40,
            hwnd, (HMENU)ID_HEALTH,
            NULL, NULL);

        // 文件管理
        CreateWindowW(
            L"BUTTON", L"文件管理",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 260, 160, 40,
            hwnd, (HMENU)ID_FILE,
            NULL, NULL);

        // 紧急报警
        CreateWindowW(
            L"BUTTON", L"紧急报警",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 320, 160, 40,
            hwnd, (HMENU)ID_ALARM,
            NULL, NULL);

        // 退出系统
        CreateWindowW(
            L"BUTTON", L"退出系统",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            320, 380, 160, 40,
            hwnd, (HMENU)ID_EXIT,
            NULL, NULL);

        break;

    case WM_COMMAND:

        switch (LOWORD(wParam))
        {
        case ID_INTERACT:
            MessageBoxW(
                hwnd,
                L"你好，我是家庭看护机器人！",
                L"人机交互",
                MB_OK);
            break;

        case ID_SERVICE:
            MessageBoxW(
                hwnd,
                L"正在执行家务服务……",
                L"家务服务",
                MB_OK);
            break;

        case ID_HEALTH:
            MessageBoxW(
                hwnd,
                L"体温：36.5℃\n心率：75次/分钟\n状态正常",
                L"健康监测",
                MB_OK);
            break;

        case ID_FILE:
            MessageBoxW(
                hwnd,
                L"文件管理模块开发中……",
                L"文件管理",
                MB_OK);
            break;

        case ID_ALARM:
            MessageBoxW(
                hwnd,
                L"发现异常！\n已通知家属！",
                L"紧急报警",
                MB_OK);
            break;

        case ID_EXIT:
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

// 主函数
int WINAPI wWinMain(
    HINSTANCE hInstance,
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