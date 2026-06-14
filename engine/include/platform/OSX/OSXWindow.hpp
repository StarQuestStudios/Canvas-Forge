#ifdef __APPLE__
#pragma once
#include "CFpch.hpp"
#include "renderer/Window.hpp"

#ifdef __OBJC__
    @class NSWindow;
#else
    typedef struct objc_object NSWindow;
#endif

namespace CanvasForge::Engine {
  class OSXWindow : public Window {
  public:
    OSXWindow();
    ~OSXWindow() override;

    void Init(RenderMode _mode) override;
    void Update() override;

    void SetTitle(std::string _title) override;

    void ShutDown() override;

  private:
    NSWindow* m_CocoaWindow;
  }; 
}
#endif // __APPLE__