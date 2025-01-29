#include "PRpch.hpp"

int main() {
  return CanvasForge::Engine::Init("", 800, 600, CanvasForge::RenderMode::Windowed, CanvasForge::RenderAPI::Vulkan);
}