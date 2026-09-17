#ifdef __APPLE__
#pragma once
#include "CFpch.hpp"
#include "renderer/Window.hpp"

#ifdef __OBJC__
    @class NSWindow;
    @class CAMetalLayer;
#else
    typedef struct objc_object NSWindow;
    typedef struct objc_object CAMetalLayer;
#endif

namespace CanvasForge::Engine {

  class MetalRenderer;

  class OSXWindow : public Window {
  public:
    OSXWindow();
    ~OSXWindow() override;

    void Init(RenderMode _mode) override;
    void Update() override;

    void SetTitle(std::string _title) override;

    void ShutDown() override;

    bool IsOpen() override;

    void* getMetalLayer();

  private:
    NSWindow* m_CocoaWindow;
    CAMetalLayer* m_MetalLayer;
  }; 
}
#endif // __APPLE__