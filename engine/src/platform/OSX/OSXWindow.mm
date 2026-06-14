#include <CFpch.hpp>
#include "platform/OSX/OSXWindow.hpp"

namespace CanvasForge::Engine {
  OSXWindow::OSXWindow() {

  }

  OSXWindow::~OSXWindow() {

  }

  void OSXWindow::Init(RenderMode _mode) {
    NSApplication *app = [NSApplication sharedApplication];
    [app setActivationPolicy:NSApplicationActivationPolicyRegular];

    NSUInteger style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;

    NSRect frame = NSMakeRect(0, 0, m_width, m_height);

    m_CocoaWindow = [[NSWindow alloc] initWithContentRect:frame 
      styleMask:(style) 
      backing:NSBackingStoreBuffered 
      defer:NO];
    [m_CocoaWindow makeKeyAndOrderFront:nil];
    [app activateIgnoringOtherApps:YES];

    [app finishLaunching];
  }

  void OSXWindow::Update() {
    @autoreleasepool {
      NSEvent* event = nil;
      do {
        event = [NSApp nextEventMatchingMask:NSEventMaskAny
                  untilDate:[NSDate distantPast]
                  inMode:NSDefaultRunLoopMode
                  dequeue:YES];
        if (event) {
          [NSApp sendEvent:event];
        }
      } while (event);
    }
  }

  void OSXWindow::SetTitle(std::string _title) {
    if (m_CocoaWindow) {
      NSString* nsTitle = [NSString stringWithUTF8String:_title.c_str()];
      [m_CocoaWindow setTitle:nsTitle];
    }
  }

  void OSXWindow::ShutDown() {
    if (m_CocoaWindow) {
      [m_CocoaWindow orderOut:nil];
      [m_CocoaWindow release];
      m_CocoaWindow = nullptr;
    }
  }
}