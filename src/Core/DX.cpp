#include "DX.h"

void DX::initialize() {
    loadPipeline();
    loadAssets();
}

void DX::loadPipeline() {
    ComPtr<IDXGIFactory6> factory;
    CreateDXGIFactory2(0, IID_PPV_ARGS(&factory));
    D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&m_device));
}

void DX::loadAssets() {
//TODO: Implement
}
