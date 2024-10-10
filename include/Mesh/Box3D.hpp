#pragma once

#include <Graphic/Mesh.hpp>

class Box3D : public Mesh
{
public:
    float width = 1.0f;
    float height = 1.0f;
    float depth = 1.0f;

public:
    Box3D();
    Box3D(float width, float height, float depth);
    virtual ~Box3D() noexcept;

    MeshDataContainer generateBoxData();
};