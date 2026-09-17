#if __APPLE__ && CF_RENDERAPI_METAL
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
  class MetalDrawable;
}

namespace CanvasForge::Engine {
  class MetalRenderer : public Renderer {
  public:
    MetalRenderer();
    ~MetalRenderer() override;

    void Init() override;
    void ShutDown() override;

    void BeginFrame() override;
    void EndFrame() override;

    void Clear() override;
    void ClearColor(Vector3 _color) override;

  private:
    MTL::Device* m_Device;
    MTL4::CommandQueue* m_CommandQueue;
    MTL4::CommandBuffer* m_CommandBuffer;
    MTL4::CommandAllocator* m_CommandAllocators[FRAME_IN_FLIGHT_COUNT];
    CA::MetalLayer* m_MetalLayer;
    CA::MetalDrawable* m_Drawable;
    int m_CurrentFrame;
  };
}
#endif