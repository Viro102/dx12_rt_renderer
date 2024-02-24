cmake_minimum_required(VERSION 3.26)
project(toy_renderer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
        src/Main.cpp
        src/Core/Window.cpp
        src/Core/Window.h
        src/Core/DX.cpp
        src/Core/DX.h
        src/Debug/DXDebugLayer.cpp
        src/Debug/DXDebugLayer.h)

add_executable(toy_renderer ${SOURCES})

target_include_directories(toy_renderer PRIVATE include)

target_link_libraries(toy_renderer PRIVATE dxguid.lib dxgi.lib d3d12.lib)
