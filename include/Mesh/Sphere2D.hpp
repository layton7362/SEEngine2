#pragma once

#include <Graphic/Mesh.hpp>

// TODO FIX

class Sphere2D : public Mesh {
public:
    Sphere2D(const float& radius);
    virtual ~Sphere2D() noexcept;

private:
    MeshDataContainer generateCircleData(float radius);
};