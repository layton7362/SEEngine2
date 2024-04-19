#pragma once

#include <Collision/CollisionInclude.hpp>

class CollisionUtil
{
private:
    CollisionUtil(){};
    virtual ~CollisionUtil(){};

public:
    static bool collide(Box &obj1, Box &obj2);
    static bool collide(Sphere &obj1, Box &obj2);
    static bool collide(Sphere &obj1, Sphere &obj2);
};
