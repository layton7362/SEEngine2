#pragma once
 
#include <vector>
#include <algorithm>
#include <glm/glm.hpp>
#include <Collision/CollisionInclude.hpp>

using namespace glm;

class Body3D
{
public:
    vec3 position;
    std::vector<Shape3D*> shapes;

public:
    void addShape(Shape3D& shape);

public:
    Body3D();
    virtual ~Body3D();
};
