#ifdef __APPLE__ && CF_RENDERAPI_METAL
#pragma once
#include "CFpch.hpp"
#include "renderer/Shader.hpp"

namespace CanvasForge::Engine {
  class MetalShader : public Shader {
  public:
    MetalShader() {

    }

    ~MetalShader() override {
      
    }

  private:
    
  };
}

#endif