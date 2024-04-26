#pragma once

#include <Types.hpp>
#include "Node.hpp"

using namespace glm;

class Node3D : public Node
{
protected:
    mat4 transformation = mat4(1.0f);

public:
    Node3D();
    virtual ~Node3D() noexcept;

    void translate(const glm::vec3 &translation);
    void scale(const glm::vec3 &scale);
    void rotate(float angle, const glm::vec3 &axis);
};