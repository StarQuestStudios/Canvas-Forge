#pragma once
#include "CFpch.hpp"

namespace CanvasForge::Engine {

  struct Vertex {
    Vector3 vPos;
    Vector2 vUV;
    int vTexID;

    Vertex() {
      vPos = Vector3();
      vUV = Vector2();
      vTexID = 0;
    }

    Vertex(Vector3 _pos) {
      vPos = _pos;
      vUV = Vector2();
      vTexID = 0;
    }

    Vertex(Vector3 _pos, Vector2 _uv) {
      vPos = _pos;
      vUV = _uv;
      vTexID = 0;
    }

    Vertex(Vector3 _pos, Vector2 _uv, int _texID) {
      vPos = _pos;
      vUV = _uv;
      vTexID = _texID;
    }
  };

  struct Mesh {
    Vertex* vertecies;
    int* indecies;

    Mesh() {
      vertecies = {};
      indecies = {};
    }

    Mesh(Vertex* _vertecies, int* _indecies) {
      memmove(vertecies, _vertecies, sizeof(_vertecies));
      memmove(indecies, _indecies, sizeof(_indecies));
    }
  };
}