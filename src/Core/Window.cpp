#include "Window.h"

Window::Window(int width, int height, const wchar_t *title) : _width(width), _height(height), _title(title) {
    WNDCLASSEXW wClassEx{
        .cbSize = sizeof(WNDCLASSEX),
        .style = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc = wndProc,
        .hInstance = _hInstance,
        .lpszClassName = WINDOW_CLASS_NAME,
    };

    RegisterClassExW(&wClassEx);

    _hwnd = CreateWindowExW(
        WS_EX_ACCEPTFILES,
        WINDOW_CLASS_NAME,
        _title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        _width,
        _height,
        nullptr,
        nullptr,
        _hInstance,
        nullptr);
}

Window::~Window() {
    DestroyWindow(_hwnd);
    UnregisterClassW(WINDOW_CLASS_NAME, _hInstance);
}

void Window::showWindow() {
    ShowWindow(_hwnd, SW_SHOWDEFAULT);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

HWND Window::getHwnd() {
    return _hwnd;
}

LRESULT CALLBACK Window::wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY: {
            PostQuitMessage(0);
            return 0;
        }

        // Handle keyboard input
        case WM_KEYDOWN: {
            switch (wParam) {
                case VK_ESCAPE:
                    DestroyWindow(hwnd);
                    break;
            }
            return 0;
        }

        // Handle resizing window
        case WM_SIZE: {
            int newWidth = LOWORD(lParam);
            int newHeight = HIWORD(lParam);
            handleResize(newWidth, newHeight);
            std::cout << "Resized to " << newWidth << "x" << newHeight << std::endl;
            return 0;
        }

        // Prevent window from being resized below minimum size
        case WM_GETMINMAXINFO: {
            auto *pInfo = reinterpret_cast<MINMAXINFO *>(lParam);

            pInfo->ptMinTrackSize.x = MIN_WIDTH;
            pInfo->ptMinTrackSize.y = MIN_HEIGHT;

            return 0;
        }


        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
};

void Window::handleResize(int newWidth, int newHeight) {
    // TODO: Implement
}
