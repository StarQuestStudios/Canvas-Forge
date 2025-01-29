#include "CFpch.hpp"
#include "Engine.hpp"

namespace CanvasForge {
  uint32_t Engine::m_statusCode;
  bool Engine::m_isRunning;

  uint32_t Engine::Init(std::string _title, uint32_t _width, uint32_t _height, RenderMode _mode, RenderAPI _api) {
    /* Setup */
    Log::Message("Engine startup...");
    m_isRunning = true;
    m_statusCode = 0;

    if (_api != RenderAPI::None) {
      /* Setup Window */


      /* Setup Renderer */


    }
    
    while (m_isRunning) {

    }

    /* Shutdown */

    return m_statusCode;
  }

  void Engine::Quit(uint32_t _code) {
    m_statusCode = _code;
    m_isRunning = false;
  }
}