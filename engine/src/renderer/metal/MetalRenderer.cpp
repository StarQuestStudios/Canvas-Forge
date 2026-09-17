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
    
    m_CurrentFrame = 0;

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

    for (int i = 0; i < FRAME_IN_FLIGHT_COUNT; i++) {
      m_CommandAllocators[i] = m_Device->newCommandAllocator();
    }

    m_Drawable = m_MetalLayer->nextDrawable();

    if (m_Drawable == nullptr) {
      Log::Throw("Cannot get Drawable");
    }
    
    Log::Message("Metal4 Initilized!");
  }

  void MetalRenderer::ShutDown() {

  }

  void MetalRenderer::BeginFrame() {
    m_CurrentFrame++;
    if (m_CurrentFrame >= FRAME_IN_FLIGHT_COUNT) {
      m_CurrentFrame = m_CurrentFrame - FRAME_IN_FLIGHT_COUNT;
    }

    // Start Frame
    m_Drawable = m_MetalLayer->nextDrawable();
    m_CommandAllocators[m_CurrentFrame]->reset();
    m_CommandBuffer->beginCommandBuffer(m_CommandAllocators[m_CurrentFrame]);
  }

  void MetalRenderer::EndFrame() {
    // Render and Display Frame
    m_CommandBuffer->endCommandBuffer();
    m_CommandQueue->wait(m_Drawable);
    m_CommandQueue->commit(&m_CommandBuffer, 1);
    m_CommandQueue->signalDrawable(m_Drawable);
    m_Drawable->present();
  }


  void MetalRenderer::Clear() {
    MTL4::RenderPassDescriptor* renderPassDescriptor = MTL4::RenderPassDescriptor::alloc()->init();
    MTL::RenderPassColorAttachmentDescriptor* colorAttachment = renderPassDescriptor->colorAttachments()->object(0);
    colorAttachment->setTexture(m_Drawable->texture());
    colorAttachment->setLoadAction(MTL::LoadActionClear);
    colorAttachment->setStoreAction(MTL::StoreActionStore);

    colorAttachment->setClearColor(MTL::ClearColor(0.0f, 0.0f, 1.0f, 1.0f));

    MTL4::CommandEncoder* commandEncoder = m_CommandBuffer->renderCommandEncoder(renderPassDescriptor);
    commandEncoder->endEncoding();

    // commandEncoder->release();
    // colorAttachment->release();
    // renderPassDescriptor->release();
  }
  
  void MetalRenderer::ClearColor(Vector3 _color) {

  }
}
#endif