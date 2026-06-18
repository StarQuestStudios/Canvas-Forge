#include "PRpch.hpp"

namespace CFPCRuntime {
  class Runtime : public CanvasForge::Engine::Application {
  public:
    Runtime() {}

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
  return CanvasForge::Engine::Engine::Init(new CFPCRuntime::Runtime() ,"Canvas Forge Pc Runtime", 800, 600, 
  CanvasForge::Engine::RenderMode::Windowed, CanvasForge::Engine::RenderAPI::Metal);
}