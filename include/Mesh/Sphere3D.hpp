#pragma once

#include <math.h>
#include <Graphic/Mesh.hpp>

// TODO FIX

class Sphere3D : public Mesh
{

public:
    Sphere3D();

private:
    static constexpr int STACKS = 20;
    static constexpr int SLICES = 20;

public:
    Sphere3D(const float &radius);
    virtual ~Sphere3D() noexcept;

private:
    MeshDataContainer generateSphereData(float radius);
};