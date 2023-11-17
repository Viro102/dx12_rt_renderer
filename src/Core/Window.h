#ifndef TOY_RENDERER_WINDOW_H
#define TOY_RENDERER_WINDOW_H

#include <Common.h>

class Window {

public:
    Window(int width, int height, const wchar_t *title);

    ~Window();

    void showWindow();

    static HWND getHwnd() {
        return m_hwnd;
    }

private:
    inline static const wchar_t *WINDOW_CLASS_NAME = L"dx12Renderer";
    inline static const int MIN_WIDTH = 800;
    inline static const int MIN_HEIGHT = 600;

    HINSTANCE m_hInstance = GetModuleHandleW(nullptr);
    static HWND m_hwnd;
    int m_width;
    int m_height;
    const wchar_t *m_title;

    static void handleResize(int newWidth, int newHeight);

    static LRESULT CALLBACK wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
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
};

#endif //TOY_RENDERER_WINDOW_H