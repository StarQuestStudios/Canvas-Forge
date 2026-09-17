#include <CFpch.hpp>
#include "platform/OSX/OSXWindow.hpp"
#import <QuartzCore/CAMetalLayer.h>
//#include "renderer/metal/MetalRenderer.hpp"

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

    m_MetalLayer = [[CAMetalLayer alloc] init];
    //m_MetalLayer.device = MetalRenderer::m_Device;
    m_MetalLayer.opaque = YES;
    m_MetalLayer.drawableSize = [m_CocoaWindow.contentView convertSizeToBacking:m_CocoaWindow.contentView.frame.size];

    m_CocoaWindow.contentView.layer = m_MetalLayer;

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

  void* OSXWindow::getMetalLayer() {
    return (void*) m_MetalLayer;
  }

  void OSXWindow::SetTitle(std::string _title) {
    if (m_CocoaWindow) {
      NSString* nsTitle = [NSString stringWithUTF8String:_title.c_str()];
      [m_CocoaWindow setTitle:nsTitle];
    }
  }

  bool OSXWindow::IsOpen() {
    return [m_CocoaWindow isVisible];
  }

  void OSXWindow::ShutDown() {
    if (m_CocoaWindow) {
      [m_CocoaWindow orderOut:nil];
      [m_CocoaWindow release];
      m_CocoaWindow = nullptr;
    }
  }
}