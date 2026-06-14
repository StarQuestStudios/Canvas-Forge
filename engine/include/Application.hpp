#pragma once
#include "CFpch.hpp"

namespace CanvasForge::Engine {
  class Application {
  public:
    Application() {}
    virtual ~Application() {}

    virtual void Init() {}
    virtual void Update() {}
    virtual void PhyUpdate() {}

    virtual void Shutdown() {}
  };
}