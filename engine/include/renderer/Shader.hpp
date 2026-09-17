#pragma once
#include "CFpch.hpp"

namespace CanvasForge::Engine {
  enum ShaderType {
    VertexShader,
    FragmentShader
  };

  class Shader {
  public:
    Shader() {}
    virtual ~Shader() {}

  private:
    
  };
}