#pragma once
#include "CFpch.hpp"

namespace CanvasFroge::Engine {
  struct Vector2 {

    Vector2() {
      x = 0.0f;
      y = 0.0f;
    }

    Vector2(float _x, float _y) {
      x = _x;
      y = _y;
    }

    float x, y;
  };

  struct Vector3 {

    Vector3() {
      x = 0.0f;
      y = 0.0f;
      z = 0.0f;
    }

    Vector3(float _x, float _y, float _z) {
      x = _x;
      y = _y;
      z = _z;
    }

    float x, y, z;
  };
}