#include "Window.h"

Window::Window(int width, int height, const wchar_t *title) : m_width(width), m_height(height), m_title(title) {
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
            m_title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            m_width,
            m_height,
            nullptr,
            nullptr,
            m_hInstance,
            nullptr);
}

Window::~Window() {
    DestroyWindow(m_hwndMain);
    UnregisterClassW(WINDOW_CLASS_NAME, m_hInstance);
}

void Window::showWindow() {
    ShowWindow(m_hwndMain, SW_SHOWDEFAULT);
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void Window::handleResize(int newWidth, int newHeight) {
// TODO: Implement
}
