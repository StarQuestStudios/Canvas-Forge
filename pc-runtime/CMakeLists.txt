cmake_minimum_required(VERSION 3.13.3 FATAL_ERROR)

project(PcRuntime C CXX)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")
add_executable(PcRuntime ${sources})
include_directories("include")

target_precompile_headers(PcRuntime PRIVATE "include/PRpch.hpp")

set(OpenGL OFF)
set(DX11 OFF)
set(Metal ON)
add_subdirectory(../engine build)
find_library(METAL_FRAMEWORK Metal REQUIRED)
find_library(FOUNDATION_FRAMEWORK Foundation REQUIRED)
find_library(QUARTZCORE_FRAMEWORK QuartzCore REQUIRED)

target_link_libraries(PcRuntime CanvasForge ${METAL_FRAMEWORK} ${FOUNDATION_FRAMEWORK} ${QUARTZCORE_FRAMEWORK})