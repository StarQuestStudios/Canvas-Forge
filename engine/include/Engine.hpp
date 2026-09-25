#pragma once
#include "CFpch.hpp"

namespace CanvasForge::Engine {

  class Window;

  enum class RenderMode {
    Windowed = 0,
    FullScreen = 1,
    Borderless = 2,
    Custom = 3
  };

  enum class RenderAPI {
    None = 0,
    Vulkan = 1,
    Metal = 2,
  };

  class Engine {
  public:
    static uint32_t Init(Application* _app, std::string _title, uint32_t _width, uint32_t _height, RenderMode _mode, RenderAPI _api);

    static void Quit(uint32_t _code = 0);

    static Window* m_Window;
    static Renderer* m_Renderer;
  private:
    static uint32_t m_statusCode;
    static bool m_isRunning;
    static Application* m_app;
  };
}