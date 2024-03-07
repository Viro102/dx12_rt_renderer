#pragma once

#include <Common.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl/client.h>

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
    ComPtr<ID3D12CommandQueue> _commandQueue;
    ComPtr<ID3D12CommandAllocator> _commandAllocator;
    ComPtr<ID3D12GraphicsCommandList> _commandList;
    ComPtr<ID3D12DescriptorHeap> _rtvHeap;
    ComPtr<ID3D12Resource2> _renderTargets[2];

    // DXGI objects
    ComPtr<IDXGISwapChain4> _swapChain;

    D3D12_VIEWPORT _viewport{0, 0, 800, 600, 0, 1};
    D3D12_RECT _scissorRect{0, 0, 800, 600};

    UINT _rtvDescriptorSize;
    UINT _frameIndex;
};
