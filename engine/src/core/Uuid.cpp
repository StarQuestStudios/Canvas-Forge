#include "CFpch.hpp"
#include "core/Uuid.hpp"

namespace CanvasForge::Engine {
	static std::random_device randomDevice;
	static std::mt19937_64 engine(randomDevice());
	static std::uniform_int_distribution<uint64_t> UniformDistribution;

  UUID::UUID() {
    uuid = UniformDistribution(engine);
  }

  UUID::UUID(uint64_t _uuid) {
    uuid = _uuid;
  }
}