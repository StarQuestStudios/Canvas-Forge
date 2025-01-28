#pragma once
#include "CFpch.hpp"

namespace CanvasForge {

  enum class RenderMode {
    Windowed = 0,
    FullScreen = 1,
    Borderless = 2,
    Custom = 3
  };

  enum class RenderAPI {
    None = 0,
    Vulkan = 1,
  };

  class Engine {
  public:
    static void Init(std::string _title, int _width, int _height, RenderMode _mode, RenderAPI _api);
  };
}