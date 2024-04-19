#pragma once

#include <Collision/Shape.hpp>

class Shape3D : public Shape
{
public:
    vec3 position;

protected:
    Shape3D();
    virtual ~Shape3D();
};
