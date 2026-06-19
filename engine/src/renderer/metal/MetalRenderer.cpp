#if __APPLE__ && CF_RENDERAPI_METAL
#include "renderer/metal/MetalRenderer.hpp"
#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#include <Metal/Metal.hpp>
#include <Foundation/Foundation.hpp>
#include <QuartzCore/QuartzCore.hpp>
#include "platform/OSX/OSXWindow.hpp"

namespace CanvasForge::Engine {
  MetalRenderer::MetalRenderer() {

  }

  MetalRenderer::~MetalRenderer() {

  }

  void MetalRenderer::Init() {
    Log::Message("Start Initilizing Metal4");
    
    m_Device = MTL::CreateSystemDefaultDevice();
    OSXWindow* window = (OSXWindow*) Engine::m_Window;
    m_MetalLayer = (CA::MetalLayer*) window->getMetalLayer();
    m_MetalLayer->setDevice(m_Device);
    m_MetalLayer->setPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB);
    m_MetalLayer->setFramebufferOnly(true);
    if (m_Device == nullptr) {
      Log::Throw("Cannot get Metal Device!");
    }

    m_CommandBuffer = m_Device->newCommandBuffer();
    if (m_CommandBuffer == nullptr) {
      Log::Throw("Cannot create the Command Buffer");
    }

    m_CommandQueue = m_Device->newMTL4CommandQueue();

    if (m_CommandQueue == nullptr) {
      Log::Throw("Cannot create the Command Queue");
    }

    m_CommandAllocators[0] = m_Device->newCommandAllocator();
    m_CommandAllocators[1] = m_Device->newCommandAllocator();
    m_CommandAllocators[2] = m_Device->newCommandAllocator();

    m_CommandAllocators[0]->reset();
    m_CommandBuffer->beginCommandBuffer(m_CommandAllocators[0]);

    CA::MetalDrawable* drawable = m_MetalLayer->nextDrawable();

    if (drawable == nullptr) {
      Log::Throw("Cannot get Drawable");
    }

    MTL4::RenderPassDescriptor* renderPassDescriptor = MTL4::RenderPassDescriptor::alloc()->init();
    MTL::RenderPassColorAttachmentDescriptor* colorAttachment = renderPassDescriptor->colorAttachments()->object(0);
    colorAttachment->setTexture(drawable->texture());
    colorAttachment->setLoadAction(MTL::LoadActionClear);
    colorAttachment->setStoreAction(MTL::StoreActionStore);

    colorAttachment->setClearColor(MTL::ClearColor(0.0f, 0.0f, 1.0f, 1.0f));

    MTL4::CommandEncoder* commandEncoder = m_CommandBuffer->renderCommandEncoder(renderPassDescriptor);
    commandEncoder->endEncoding();
    
    m_CommandBuffer->endCommandBuffer();
    m_CommandQueue->wait(drawable);
    m_CommandQueue->commit(&m_CommandBuffer, 1);
    m_CommandQueue->signalDrawable(drawable);
    drawable->present();
    

    Log::Message("Metal4 Initilized!");
  }

  void MetalRenderer::ShutDown() {

  }
}
#endif