#pragma once
#include "CFpch.hpp"

namespace CanvasForge::Engine {
  class Renderer {
  public:
    Renderer() {}
    virtual ~Renderer() {}

    virtual void Init() {}

    virtual void ShutDown() {}

    virtual void BeginFrame() {}
    virtual void EndFrame() {}

    virtual void Clear() {}
    virtual void ClearColor(Vector3 _color) {}

  private:
    
  };
}