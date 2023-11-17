#include "Window.h"

Window::Window() {
    WNDCLASSEXW wClassEx{
            sizeof(WNDCLASSEX),
            CS_HREDRAW | CS_VREDRAW,
            wndProc,
            0,
            0,
            m_hInstance,
            nullptr,
            nullptr,
            (HBRUSH) (COLOR_WINDOW + 1),
            nullptr,
            WINDOW_CLASS_NAME,
            nullptr
    };

    RegisterClassExW(&wClassEx);

    m_hwndMain = CreateWindowExW(
            WS_EX_ACCEPTFILES,
            WINDOW_CLASS_NAME,
            L"Testing window",
            WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            800,
            600,
            nullptr,
            nullptr,
            m_hInstance,
            nullptr);

    ShowWindow(m_hwndMain, SW_SHOWDEFAULT);
    UpdateWindow(m_hwndMain);
}

Window::~Window() {
    DestroyWindow(m_hwndMain);
}
