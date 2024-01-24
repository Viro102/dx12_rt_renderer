#pragma once

#include <Common.h>

class Window {
public:
    Window(int width, int height, const wchar_t *title);

    ~Window();

    void showWindow();

    static HWND getHwnd();

private:
    inline static const wchar_t *WINDOW_CLASS_NAME = L"dx12Renderer";
    inline static const int MIN_WIDTH = 800;
    inline static const int MIN_HEIGHT = 600;

    HINSTANCE _hInstance{GetModuleHandleW(nullptr)};
    inline static HWND _hwnd{nullptr};
    int _width;
    int _height;
    const wchar_t *_title;

    static void handleResize(int newWidth, int newHeight);

    static LRESULT CALLBACK wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
