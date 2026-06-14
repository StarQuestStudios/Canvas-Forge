#pragma once
#include "CFpch.hpp"

namespace CanvasForge::Engine {
  class UUID {
  public:
    UUID();
    UUID(uint64_t _uuid);

    operator uint64_t() const { return uuid; }
    uint64_t uuid;
  };
}

namespace std {
	template<>
	struct hash<CanvasForge::Engine::UUID> {
		std::size_t operator()(const CanvasForge::Engine::UUID& uuid) const {
			return hash<uint64_t>()((uint64_t) uuid);
		}
	};
}