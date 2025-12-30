#ifdef __APPLE__
#pragma once
#include "CFpch.hpp"
#include "renderer/Window.hpp"

namespace CanvasForge {
  class OSXWindow : public Window {
  public:
    OSXWindow();
    ~OSXWindow() override;

    void Init(RenderMode _mode) override;
    void Update() override;

    void SetTitle(std::string _title) override;

    void ShutDown() override;

  private:
  
  }; 
}
#endif // __APPLE__