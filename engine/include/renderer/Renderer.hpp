#pragma once
#include "CFpch.hpp"

namespace CanvasForge::Engine {
  class Renderer {
  public:
    Renderer() {}
    virtual ~Renderer() {}

    virtual void Init() {}

    virtual void ShutDown() {}
  private:
    
  };
}