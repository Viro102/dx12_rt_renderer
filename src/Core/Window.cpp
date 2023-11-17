#include "Window.h"

HWND Window::m_hwnd = nullptr;

Window::Window(int width, int height, const wchar_t *title) : m_width(width), m_height(height), m_title(title) {
    WNDCLASSEXW wClassEx{
            .cbSize = sizeof(WNDCLASSEX),
            .style = CS_HREDRAW | CS_VREDRAW,
            .lpfnWndProc = wndProc,
            .hInstance = m_hInstance,
            .lpszClassName = WINDOW_CLASS_NAME,
    };

    RegisterClassExW(&wClassEx);

    m_hwnd = CreateWindowExW(
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
    DestroyWindow(m_hwnd);
    UnregisterClassW(WINDOW_CLASS_NAME, m_hInstance);
}

void Window::showWindow() {
    ShowWindow(m_hwnd, SW_SHOWDEFAULT);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void Window::handleResize(int newWidth, int newHeight) {
// TODO: Implement
}
