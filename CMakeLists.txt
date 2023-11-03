CMAKE_MINIMUM_REQUIRED(VERSION 3.26)
project(toy_renderer)

set(CMAKE_CXX_STANDARD 23)
set(SOURCES ./src/Main.cpp)
set(IMGUI_SOURCES
        ./imgui/imgui.cpp
        ./imgui/imgui_demo.cpp
        ./imgui/imgui_draw.cpp
        ./imgui/imgui_widgets.cpp
        ./imgui/imgui_tables.cpp
        ./imgui/backends/imgui_impl_dx12.cpp
        ./imgui/backends/imgui_impl_win32.cpp)

add_executable(toy_renderer ${SOURCES} ${IMGUI_SOURCES})

target_include_directories(toy_renderer PRIVATE ./imgui/backends ./imgui)
target_link_libraries(toy_renderer PRIVATE dxguid.lib dxgi.lib d3d12.lib)