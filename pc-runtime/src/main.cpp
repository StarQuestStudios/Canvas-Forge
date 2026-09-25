#include "PRpch.hpp"

namespace CFPCRuntime {
  class Runtime : public CanvasForge::Engine::Application {
  public:
    Runtime() {}

    ~Runtime() {}

    void Init() override {

    }

    void Update() override {
      CanvasForge::Engine::Engine::m_Renderer->SubmitClearColor(CanvasForge::Engine::Vector3(1.0f, 0.0f, 0.1f));

      CanvasForge::Engine::Engine::m_Renderer->DrawFrame(nullptr);
    }

    void PhyUpdate() override {

    }

    void Shutdown() override {

    }
  };
}

int main() {
  return CanvasForge::Engine::Engine::Init(new CFPCRuntime::Runtime() ,"Canvas Forge [Metal4]", 800, 600, 
  CanvasForge::Engine::RenderMode::Windowed, CanvasForge::Engine::RenderAPI::Metal);
}