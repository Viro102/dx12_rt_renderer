#include "DXInit.h"

void DXInit::create()
{
	ComPtr<IDXGIAdapter1> adapter;
	ComPtr<IDXGIFactory4> factory;
	ComPtr<ID3D12Device> device;
	ComPtr<ID3D12Debug1> debugController;

#if defined(_DEBUG)
	ComPtr<ID3D12Debug> dc;
	throwIfFailed(D3D12GetDebugInterface(IID_PPV_ARGS(&dc)));
	throwIfFailed(dc->QueryInterface(IID_PPV_ARGS(&debugController)));
	debugController->EnableDebugLayer();
	debugController->SetEnableGPUBasedValidation(true);
	dc = nullptr;
#endif

	throwIfFailed(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&factory)));

	for (UINT adapterIndex = 0; DXGI_ERROR_NOT_FOUND != factory->EnumAdapters1(adapterIndex, &adapter); ++adapterIndex)
	{
		DXGI_ADAPTER_DESC1 adapterDesc;
		adapter->GetDesc1(&adapterDesc);

		if (adapterDesc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			continue;

		if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&device))))
			break;
		adapter = nullptr;
	}
}
