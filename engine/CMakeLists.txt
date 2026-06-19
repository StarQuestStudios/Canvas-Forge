cmake_minimum_required(VERSION 3.13.3 FATAL_ERROR)

option(Vulkan "Vulkan" OFF)
option(Metal "Metal" ON)

if (APPLE)
project(CanvasForge C CXX OBJC OBJCXX)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
else()
project(CanvasForge C CXX)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
endif()

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")

add_library(CanvasForge STATIC)
target_include_directories(CanvasForge PUBLIC include)

add_subdirectory(submodules/oslib build)
target_link_libraries(CanvasForge OSLib)

if (APPLE)
file(GLOB_RECURSE appleSources CONFIGURE_DEPENDS "src/*.mm")
target_sources(CanvasForge PRIVATE ${appleSources} ${sources})
else()
target_sources(CanvasForge PRIVATE ${sources})
endif()

target_precompile_headers(CanvasForge PRIVATE include/CFpch.hpp)

if (NOT WIN32)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

if (Metal)
add_compile_definitions(CF_RENDERAPI_METAL)
elseif(Vulkan)

endif()

if (WIN32)
add_compile_definitions(CF_PLATFORM_WIN)
elseif(APPLE)
add_compile_definitions(CF_PLATFORM_MAC)
target_include_directories(CanvasForge PRIVATE submodules/metal)
find_library(METAL_FRAMEWORK Metal REQUIRED)
find_library(FOUNDATION_FRAMEWORK Foundation REQUIRED)
find_library(QUARTZCORE_FRAMEWORK QuartzCore REQUIRED)
find_library(GAME_CONTROLLER_FRAMEWORK GameController)
find_library(COCOA_FRAMEWORK Cocoa)
target_link_libraries(CanvasForge ${GAME_CONTROLLER_FRAMEWORK} ${COCOA_FRAMEWORK} ${METAL_FRAMEWORK} ${FOUNDATION_FRAMEWORK} ${QUARTZCORE_FRAMEWORK})
elseif(UNIX)
add_compile_definitions(CF_PLATFORM_LINUX)
endif()