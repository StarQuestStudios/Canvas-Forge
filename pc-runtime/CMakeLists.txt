cmake_minimum_required(VERSION 3.13.3 FATAL_ERROR)

project(PcRuntime C CXX)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")
add_executable(PcRuntime ${sources})
include_directories("include")

target_precompile_headers(PcRuntime PUBLIC "include/PRpch.hpp")

set(OpenGL ON)
set(DX11 OFF)
add_subdirectory(../engine build)
target_link_libraries(PcRuntime CanvasForge)