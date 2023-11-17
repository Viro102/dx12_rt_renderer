#include "Core/Window.h"
#include "Debug/DXDebugLayer.h"

int main() {
    Window window(800, 600, L"dx12Renderer");
    window.showWindow();
    DXDebugLayer &instance = DXDebugLayer::getInstance();
    instance.init();
    instance.shutdown();
    return 0;
}