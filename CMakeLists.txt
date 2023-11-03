CMAKE_MINIMUM_REQUIRED(VERSION 3.26)
project(toy_renderer)

set(CMAKE_CXX_STANDARD 23)
set(SOURCES ./src/Main.cpp)

add_executable(toy_renderer ${SOURCES})

target_include_directories(toy_renderer PRIVATE ./imgui/backends ./imgui)
target_link_libraries(toy_renderer PRIVATE dxguid.lib dxgi.lib d3d12.lib)