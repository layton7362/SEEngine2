 #pragma once

#include <Collision/Shape3D.hpp>

class Sphere: public Shape3D{
    
public:
    float radius;

    Sphere();
    virtual ~Sphere();
};
