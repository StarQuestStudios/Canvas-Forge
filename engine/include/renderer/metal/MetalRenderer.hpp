#if __APPLE__
#pragma once
#include "CFpch.hpp"
#include "renderer/Renderer.hpp"
#define NS_NO_LIBCXX_SYMBOL_STUBS

namespace MTL {
  class Device;
}

namespace MTL4 {
  class CommandQueue;
  class CommandBuffer;
  class CommandAllocator;
}

namespace CA {
  class MetalLayer;
}

namespace CanvasForge::Engine {
  class MetalRenderer : public Renderer {
  public:
    MetalRenderer();
    ~MetalRenderer() override;

    void Init() override;
    void ShutDown() override;

  private:
    MTL::Device* m_Device;
    MTL4::CommandQueue* m_CommandQueue;
    MTL4::CommandBuffer* m_CommandBuffer;
    MTL4::CommandAllocator* m_CommandAllocators[3];
    CA::MetalLayer* m_MetalLayer;
  };
}
#endif