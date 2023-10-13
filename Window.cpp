#include "Window.h"

inline LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

Window::Window() : m_hInstance(GetModuleHandle(nullptr))
{
	WNDCLASS windowClass = {};
	windowClass.lpszClassName = m_className;
	windowClass.hInstance = m_hInstance;
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.lpfnWndProc = windowProc;

	RegisterClass(&windowClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	RECT dimensions = {0, 0, 800, 600};

	AdjustWindowRect(&dimensions, style, false);

	m_hwnd = CreateWindowEx(0, m_className, L"Testing window", style, 0, 0,
	                        dimensions.right - dimensions.left,
	                        dimensions.bottom - dimensions.top,
	                        nullptr, nullptr, m_hInstance, nullptr);

	ShowWindow(m_hwnd,SW_SHOW);
}

Window::~Window()
{
	DestroyWindow(m_hwnd);
	UnregisterClass(m_className, m_hInstance);
}

bool Window::processMessages()
{
	MSG msg = {};

	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return false;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}
