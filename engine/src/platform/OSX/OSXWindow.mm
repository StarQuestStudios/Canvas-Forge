#include <CFpch.hpp>
#include "platform/OSX/OSXWindow.hpp"

namespace CanvasForge {
  OSXWindow::OSXWindow() {

  }

  OSXWindow::~OSXWindow() {

  }

  void OSXWindow::Init(RenderMode _mode) {
    NSApplication *app = [NSApplication sharedApplication];
    [app setActivationPolicy:NSApplicationActivationPolicyRegular]

    NSUInteger style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;

    NSRect frame = NSMakeRect(0, 0, m_width, m_height);
    
  }

  void OSXWindow::Update() {

  }

  void OSXWindow::SetTitle(std::string _title) {

  }

  void OSXWindow::Shutdown() {

  }
}