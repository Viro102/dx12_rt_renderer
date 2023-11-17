CMAKE_MINIMUM_REQUIRED(VERSION 3.26)
project(toy_renderer)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES src/Main.cpp
        src/Core/Window.cpp
        src/Core/Window.h
        include/Common.h
        src/Core/DX.cpp
        src/Core/DX.h)

add_executable(toy_renderer ${SOURCES})

target_include_directories(toy_renderer PRIVATE include)

target_link_libraries(toy_renderer PRIVATE dxguid.lib dxgi.lib d3d12.lib)