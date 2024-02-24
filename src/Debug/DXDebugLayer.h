#pragma once

#include <Common.h>

class DXDebugLayer {
  public:
    bool init();

    void shutdown();

  private:
#ifdef _DEBUG
    ComPtr<ID3D12Debug6> _d3d12Debug;
    ComPtr<IDXGIDebug1> _dxgiDebug;
#endif

    // singleton
  public:
    DXDebugLayer(const DXDebugLayer &) = delete;

    DXDebugLayer &operator=(const DXDebugLayer &) = delete;

    static DXDebugLayer &getInstance() {
        static DXDebugLayer instance;
        return instance;
    }

  private:
    DXDebugLayer() = default;
};
