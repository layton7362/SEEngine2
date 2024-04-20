#pragma once

#include <Collision/CollisionInclude.hpp>

class CollisionUtil
{
private:
    CollisionUtil(){};
    virtual ~CollisionUtil(){};

public:
    static bool collide(BoxShape &obj1, BoxShape &obj2);
    static bool collide(Sphere &obj1, BoxShape &obj2);
    static bool collide(Sphere &obj1, Sphere &obj2);
};
