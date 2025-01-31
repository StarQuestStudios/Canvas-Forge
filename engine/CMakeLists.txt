cmake_minimum_required(VERSION 3.13.3 FATAL_ERROR)

option(Vulkan "Vulkan" OFF)

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
target_include_directories(CanvasForge PUBLIC backend)

add_subdirectory(submodules/oslib build)
target_link_libraries(CanvasForge OSLib)

if (APPLE)
file(GLOB_RECURSE appleSources CONFIGURE_DEPENDS "src/*.mm")
target_sources(CanvasForge PRIVATE ${appleSources} ${sources})
else()
target_sources(CanvasForge PRIVATE ${sources})
endif()

target_precompile_headers(CanvasForge PUBLIC include/CFpch.hpp)

# set(ENTT_INCLUDE_NATVIS ON)
# add_subdirectory(submodules/entt)
# target_link_libraries(CanvasForge EnTT::EnTT)

# add_subdirectory(submodules/glm)
# target_link_libraries(CanvasForge glm::glm)

if (NOT WIN32)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

if (WIN32)
add_compile_definitions(CF_PLATFORM_WIN)
elseif(APPLE)
add_compile_definitions(CF_PLATFORM_MAC)
find_library(GAME_CONTROLLER_FRAMEWORK GameController)
target_link_libraries(CanvasForge ${GAME_CONTROLLER_FRAMEWORK})
elseif(UNIX)
add_compile_definitions(CF_PLATFORM_LINUX)
endif()

if (WIN32 OR APPLE OR UNIX)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_USE_MENUBAR OFF CACHE BOOL "" FORCE)

# add_subdirectory(submodules/glfw)
# target_link_libraries(CanvasForge glfw)
endif()