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
    vec3 pos = vec3(transformation[3]);
    transformation[3][0] = 0;
    transformation[3][1] = 0;
    transformation[3][2] = 0;
    transformation = glm::scale(transformation, scale);
    transformation[3][0] = pos.x;
    transformation[3][1] = pos.y;
    transformation[3][2] = pos.z;
}

#include <Utils.hpp>

void Node3D::rotate(float angle, const vec3 &axis)
{
    vec3 pos = vec3(transformation[3]);
    translate(-pos);
    transformation = glm::rotate(transformation, angle, axis);
    // translate(pos)
    transformation[3][0] = pos.x;
    transformation[3][1] = pos.y;
    transformation[3][2] = pos.z;
}
