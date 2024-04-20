#pragma once

#include <Graphic/Mesh.hpp>

class Box2D : public Mesh {
public:
    Box2D(float width, float height); 
    virtual ~Box2D() noexcept;

private:
    MeshDataContainer generateBoxData(float width, float height);
};
