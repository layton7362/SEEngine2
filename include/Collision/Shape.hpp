#pragma once

#include <Core/RessourceType.hpp>
#include <glm/glm.hpp>

using namespace glm;

class Shape : public RessourceType
{

protected:
    Shape();
    virtual ~Shape();
};
