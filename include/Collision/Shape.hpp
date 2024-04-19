#pragma once

#include <Core/Base.hpp>
#include <glm/glm.hpp>

using namespace glm;

class Shape : public Resource
{

protected:
    Shape();
    virtual ~Shape();
};
