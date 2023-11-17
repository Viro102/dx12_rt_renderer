#ifndef TOY_RENDERER_DX_H
#define TOY_RENDERER_DX_H

#include <Common.h>

class DX {

public:
    void initialize();

    void update();

    void destroy();

    void render();

private:
    void loadPipeline();

    void loadAssets();

    // DirectX 12 objects
    ComPtr <ID3D12Device> m_device;

    // DXGI objects

};

#endif //TOY_RENDERER_DX_H
