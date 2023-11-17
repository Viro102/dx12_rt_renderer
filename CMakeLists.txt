CMAKE_MINIMUM_REQUIRED(VERSION 3.25)
project(toy_renderer)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES src/Main.cpp
        src/Core/Window.cpp
        src/Core/Window.h
        src/Common/Common.h)

add_executable(toy_renderer ${SOURCES})

target_link_libraries(toy_renderer PRIVATE dxguid.lib dxgi.lib d3d12.lib)