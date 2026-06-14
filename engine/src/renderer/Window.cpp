#include "renderer/Window.hpp"
#ifdef __APPLE__
#include "platform/OSX/OSXWindow.hpp"
#endif

namespace CanvasForge {
  Window::Window() {

  }

  Window::~Window() {

  }

  Window* Window::createWindow() {
#ifdef __APPLE__
    return new OSXWindow();
#endif
  }
}