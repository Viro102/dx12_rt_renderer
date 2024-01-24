#include "DXDebugLayer.h"

bool DXDebugLayer::init() {
#ifdef _DEBUG
    if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&_d3d12Debug)))) {
        _d3d12Debug->EnableDebugLayer();

        if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&_dxgiDebug)))) {
            _dxgiDebug->EnableLeakTrackingForThread();
            return true;
        }
    }
#endif

    return false;
}

void DXDebugLayer::shutdown() {
#ifdef _DEBUG
    if (_dxgiDebug) {
        OutputDebugStringW(L"DXGI Reports living device objects:\n");
        _dxgiDebug->ReportLiveObjects(
            DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_FLAGS(DXGI_DEBUG_RLO_DETAIL | DXGI_DEBUG_RLO_IGNORE_INTERNAL)
        );
    }

    _dxgiDebug->Release();
    _d3d12Debug->Release();
#endif
}
