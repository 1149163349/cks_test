#include <windows.h>
#include "file.h"

#define ID_INTERACT 1
#define ID_HEALTH   2
#define ID_SERVICE  3
#define ID_FILE     4
#define ID_ALARM    5
#define ID_EXIT     6

LRESULT CALLBACK WindowProc(HWND hwnd,
                            UINT msg,
                            WPARAM wParam,
                            LPARAM lParam)
{
    switch(msg)
    {
        case WM_CREATE:

            CreateWindow(
                "BUTTON",
                "人机交互",
                WS_VISIBLE | WS_CHILD,
                80, 80, 150, 50,
                hwnd,
                (HMENU)ID_INTERACT,
                NULL,
                NULL);

            CreateWindow(
                "BUTTON",
                "健康监测",
                WS_VISIBLE | WS_CHILD,
                300, 80, 150, 50,
                hwnd,
                (HMENU)ID_HEALTH,
                NULL,
                NULL);

            CreateWindow(
                "BUTTON",
                "家务服务",
                WS_VISIBLE | WS_CHILD,
                80, 180, 150, 50,
                hwnd,
                (HMENU)ID_SERVICE,
                NULL,
                NULL);

            CreateWindow(
                "BUTTON",
                "文件管理",
                WS_VISIBLE | WS_CHILD,
                300, 180, 150, 50,
                hwnd,
                (HMENU)ID_FILE,
                NULL,
                NULL);

            CreateWindow(
                "BUTTON",
                "紧急报警",
                WS_VISIBLE | WS_CHILD,
                80, 280, 150, 50,
                hwnd,
                (HMENU)ID_ALARM,
                NULL,
                NULL);

            CreateWindow(
                "BUTTON",
                "退出系统",
                WS_VISIBLE | WS_CHILD,
                300, 280, 150, 50,
                hwnd,
                (HMENU)ID_EXIT,
                NULL,
                NULL);

            return 0;

        case WM_COMMAND:

            switch(LOWORD(wParam))
            {
                case ID_INTERACT:

                    saveLog("人机交互");

                    MessageBox(
                        hwnd,
                        "您好，我是家庭看护机器人！",
                        "人机交互",
                        MB_OK);

                    break;

                case ID_HEALTH:

                    saveLog("健康监测");

                    MessageBox(
                        hwnd,
                        "体温：36.5℃\n心率：72次/分钟\n血压：120/80mmHg",
                        "健康监测",
                        MB_OK);

                    break;

                case ID_SERVICE:

                    saveLog("家务服务");

                    MessageBox(
                        hwnd,
                        "正在执行家务服务任务。",
                        "家务服务",
                        MB_OK);

                    break;

                case ID_FILE:
                {
                    char buffer[1000];

                    readLog(buffer);

                    MessageBox(
                        hwnd,
                        buffer,
                        "日志内容",
                        MB_OK);

                    break;
                }

                case ID_ALARM:

                    saveLog("紧急报警");

                    MessageBox(
                        hwnd,
                        "发现紧急情况！\n已通知家属！",
                        "紧急报警",
                        MB_OK | MB_ICONWARNING);

                    break;

                case ID_EXIT:


                    DestroyWindow(hwnd);

                    break;
            }

            return 0;

        case WM_DESTROY:

            PostQuitMessage(0);

            return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASS wc = {0};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "RobotWindow";

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
        "RobotWindow",
        "家庭看护机器人仿真系统",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        600,
        500,
        NULL,
        NULL,
        hInstance,
        NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}