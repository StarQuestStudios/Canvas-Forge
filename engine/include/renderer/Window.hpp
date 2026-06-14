#pragma once
#include "CFpch.hpp"

namespace CanvasForge {
  class Window {
  public:
    Window();
    virtual ~Window();

    virtual void Init(RenderMode _mode) = 0;
    virtual void Update() = 0;

    virtual void SetTitle(std::string _title) = 0;

    virtual void ShutDown() = 0;

    static Window* createWindow();

    uint32_t m_width;
    uint32_t m_height;
  };
}