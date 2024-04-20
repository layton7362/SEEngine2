#pragma once

#include <Collision/Shape3D.hpp>

class BoxShape: public Shape3D{
    
public:
    vec3 size;

    BoxShape();
    virtual ~BoxShape();
};
