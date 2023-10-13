#include <iostream>
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

	return 0;
}
