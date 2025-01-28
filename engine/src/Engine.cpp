#include "CFpch.hpp"
#include "Engine.hpp"

namespace CanvasForge {
  int Engine::m_statusCode;
  bool Engine::m_isRunning;

  int Engine::Init(std::string _title, int _width, int _height, RenderMode _mode, RenderAPI _api) {
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

  void Engine::Quit(int _code = 0) {
    m_statusCode = _code;
    m_isRunning = false;
  }
}