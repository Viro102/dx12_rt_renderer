#ifndef TOY_RENDERER_WINDOW_H
#define TOY_RENDERER_WINDOW_H

#include "../Common/common.h"

class Window {

public:
    Window();

    ~Window();


private:
    constexpr static const wchar_t *WINDOW_CLASS_NAME = L"dx12Renderer";
    HINSTANCE m_hInstance = GetModuleHandleW(nullptr);
    HWND m_hwndMain;

    static LRESULT CALLBACK wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;

            case WM_KEYDOWN:
                switch (wParam) {
                    case VK_ESCAPE:
                        DestroyWindow(hwnd);
                        break;
                }
                return 0;

            default:
                return DefWindowProcW(hwnd, uMsg, wParam, lParam);
        }
    };
};

#endif //TOY_RENDERER_WINDOW_H