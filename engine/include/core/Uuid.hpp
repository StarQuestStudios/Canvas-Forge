#pragma once
#include "CFpch.hpp"

namespace CanvasForge {
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
	struct hash<CanvasForge::UUID> {
		std::size_t operator()(const CanvasForge::UUID& uuid) const {
			return hash<uint64_t>()((uint64_t) uuid);
		}
	};
}