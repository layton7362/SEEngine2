#pragma once

#include <Collision/Shape3D.hpp>

class Box: public Shape3D{
    
public:
    vec3 size;

    Box();
    virtual ~Box();
};
