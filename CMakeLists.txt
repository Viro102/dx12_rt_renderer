cmake_minimum_required(VERSION 3.26)
project(toy_renderer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG docking
)
FetchContent_MakeAvailable(imgui)

set(SOURCES
        src/Main.cpp
        src/Core/Window.cpp
        src/Core/DX.cpp
        src/Debug/DXDebugLayer.cpp
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_win32.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_dx12.cpp)

add_compile_options(-Wall -fdiagnostics-color=always)

add_executable(toy_renderer ${SOURCES})

target_include_directories(toy_renderer PRIVATE include ${imgui_SOURCE_DIR})

target_link_libraries(toy_renderer PRIVATE dxguid dxgi d3d12)
