#include "PRpch.hpp"

namespace CFPCRuntime {
  class Runtime : public CanvasForge::Application {
  public:
    Runtime() {

    }
    ~Runtime() {}

    void Init() override {
      
    }

    void Update() override {

    }

    void PhyUpdate() override {

    }

    void Shutdown() override {

    }
  };
}

int main() {
  return CanvasForge::Engine::Init("Canvas Forge Pc Runtime", 800, 600, 
    CanvasForge::RenderMode::Windowed, CanvasForge::RenderAPI::Vulkan);
}