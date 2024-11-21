#pragma once

#include <Core/ResourceType.hpp>
#include <glm/glm.hpp>

using namespace glm;

class Shape : public ResourceType
{

protected:
    Shape();
    virtual ~Shape();
};
