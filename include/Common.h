#pragma once

#define NOMINMAX

#include <d3d12.h>
#include <dxgi1_6.h>
#include <iostream>
#include <windows.h>
#include <wrl/client.h>

#ifdef _DEBUG

#include <d3d12sdklayers.h>
#include <dxgidebug.h>

#endif

using Microsoft::WRL::ComPtr;
