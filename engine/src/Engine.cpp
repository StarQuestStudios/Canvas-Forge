#include "CFpch.hpp"
#include "Engine.hpp"

namespace CanvasForge {
  uint32_t Engine::m_statusCode;
  bool Engine::m_isRunning;
  Application* Engine::m_app;

  uint32_t Engine::Init(Application* _app, std::string _title, uint32_t _width, uint32_t _height, RenderMode _mode, RenderAPI _api) {
    /* Setup */
    Log::Init();
    Log::Message("Engine startup...");
    m_app = _app;
    m_isRunning = true;
    m_statusCode = 0;

    if (_api != RenderAPI::None) {
      /* Setup Window */


      /* Setup Renderer */
      

    }

    if (m_app) {
      m_app->Init();
    }
    
    while (m_isRunning) {
      /* Start Frame */


      if (m_app) {
        m_app->Update();
      }

      /* End Frame */

    }

    /* Shutdown */
    if (m_app) {
      m_app->Shutdown();
      delete m_app;
      m_app = nullptr;
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