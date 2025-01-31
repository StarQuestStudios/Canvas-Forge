#include "PRpch.hpp"

int main() {
  return CanvasForge::Engine::Init("Canvas Forge Pc Runtime", 800, 600, CanvasForge::RenderMode::Windowed, CanvasForge::RenderAPI::Vulkan);
}