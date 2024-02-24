#pragma once

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
    ComPtr<ID3D12Device> _device;

    // DXGI objects
};
