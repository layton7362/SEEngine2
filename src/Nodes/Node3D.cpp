#include <Nodes/Node3D.hpp>

Node3D::Node3D()
{
}

Node3D::~Node3D()
{
}

void Node3D::translate(const vec3 &translation)
{
    transformation = glm::translate(transformation, translation);
}

void Node3D::scale(const vec3 &scale)
{
    transformation = glm::scale(transformation, scale);
}

void Node3D::rotate(float angle, const vec3 &axis)
{
    transformation = glm::rotate(transformation, angle, axis);
}
