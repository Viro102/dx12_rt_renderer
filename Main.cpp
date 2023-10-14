#include <iostream>

#include "DXInit.h"
#include "Window.h"

int main(int argc, char* argv[])
{
	Window window;
	std::cout << "Creating a window...\n";

	bool running = true;

	while (running)
	{
		if (!Window::processMessages())
		{
			std::cout << "Closing window...\n";
			running = false;
		}

		Sleep(10);
	}
	window.~Window();
	DXInit dxInit;
	dxInit.create();

	return 0;
}
