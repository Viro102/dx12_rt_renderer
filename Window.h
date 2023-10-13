#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&&) = delete;
	Window& operator=(Window&&) = delete;

	static bool processMessages();

private:
	HINSTANCE m_hInstance;
	HWND m_hwnd;
	const wchar_t* m_className = L"Sample Window Class";
};
