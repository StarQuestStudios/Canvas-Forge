#pragma once
#include "CFpch.hpp"

namespace CanvasForge {

  enum class RenderAPI {
    None = 0,
    Vulkan = 1,
  };

  class Engine {
  public:
    static void Init();
  };
}