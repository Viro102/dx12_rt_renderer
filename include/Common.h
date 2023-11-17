#ifndef TOY_RENDERER_COMMON_H
#define TOY_RENDERER_COMMON_H

#define NOMINMAX

#include <windows.h>
#include <dxgi1_6.h>
#include <d3d12.h>
#include <wrl/client.h>
#include <iostream>

#ifdef _DEBUG

#include <d3d12sdklayers.h>
#include <dxgidebug.h>

#endif

using Microsoft::WRL::ComPtr;


#endif //TOY_RENDERER_COMMON_H
