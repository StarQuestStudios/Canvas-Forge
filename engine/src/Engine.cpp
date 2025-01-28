#include "CFpch.hpp"
#include "Engine.hpp"

namespace CanvasForge {
  int Engine::m_statusCode;
  bool Engine::m_isRunning;

  int Engine::Init(std::string _title, int _width, int _height, RenderMode _mode, RenderAPI _api) {
    m_isRunning = true;
    m_statusCode = 0;
    
    return m_statusCode;
  }

  void Engine::Quit(int _code = 0) {
    m_statusCode = _code;
    m_isRunning = false;
  }
}