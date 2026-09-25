#pragma once
#include "CFpch.hpp"

namespace CanvasForge::Engine {
  class FrameBuffer {
  public:
    FrameBuffer() {}
    virtual ~FrameBuffer() {}
  };

  class VertexBuffer {
  public:
    VertexBuffer() {}
    virtual ~VertexBuffer() {}
  };

  class IndexBuffer {
  public:
    IndexBuffer() {}
    virtual ~IndexBuffer() {}
  };
}