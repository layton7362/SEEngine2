#pragma once

#include <Core/Ressource.hpp>
#include <glm/glm.hpp>

using namespace glm;

class Shape : public Ressource
{

protected:
    Shape();
    virtual ~Shape();
};
