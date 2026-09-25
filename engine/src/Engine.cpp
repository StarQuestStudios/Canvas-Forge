#include "CFpch.hpp"
#include "Engine.hpp"
#include "renderer/Window.hpp"
#include "platform/OSX/OSXWindow.hpp"
#include "renderer/metal/MetalRenderer.hpp"

namespace CanvasForge::Engine {
  Window* Engine::m_Window;
  uint32_t Engine::m_statusCode;
  bool Engine::m_isRunning;
  Application* Engine::m_app;
  Renderer* Engine::m_Renderer;

  uint32_t Engine::Init(Application* _app, std::string _title, uint32_t _width, uint32_t _height, RenderMode _mode, RenderAPI _api) {
    /* Setup */
    Log::Init();
    Log::Message("Engine startup...");
    m_app = _app;
    m_isRunning = true;
    m_statusCode = 0;
    m_Window = new OSXWindow();
    m_Renderer = new MetalRenderer();

    if (_api != RenderAPI::None) {
      /* Setup Window */
      m_Window->m_height = 720;
      m_Window->m_width = 1080;
      m_Window->Init(_mode);
      m_Window->SetTitle(_title);
      m_Renderer->Init();

      /* Setup Renderer */
      

    }

    Log::Message("Engine initialized.");
    
    if (m_app) {
      m_app->Init();
    }

    
    while (m_isRunning && m_Window->IsOpen()) {
      /* Start Frame */
      m_Window->Update();

      if (m_app) {
        m_app->Update();
      }
    }

    /* Shutdown */
    if (m_app) {
      m_app->Shutdown();
      delete m_app;
      m_app = nullptr;
      m_Window->ShutDown();
    }

    Log::Message("Engine shutdown...");
    /* Shutdown Engine */
    

    Log::ShutDown();
    return m_statusCode;
  }

  void Engine::Quit(uint32_t _code) {
    m_statusCode = _code;
    m_isRunning = false;
  }
}