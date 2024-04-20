#pragma once

#include <Graphic/Mesh.hpp>

// TODO FIX Its not 3D

class Box3D : public Mesh {
public:
    Box3D(float width, float height, float depth);
    virtual ~Box3D() noexcept;

private:
    MeshDataContainer generateBoxData(float width, float height, float depth);
};