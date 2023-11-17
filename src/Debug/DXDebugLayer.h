#ifndef TOY_RENDERER_DXDEBUGLAYER_H
#define TOY_RENDERER_DXDEBUGLAYER_H

#include <Common.h>

class DXDebugLayer {
public:
    bool init();

    void shutdown();

private:
#ifdef _DEBUG
    ComPtr<ID3D12Debug6> m_d3d12Debug;
    ComPtr<IDXGIDebug1> m_dxgiDebug;
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

#endif //TOY_RENDERER_DXDEBUGLAYER_H
