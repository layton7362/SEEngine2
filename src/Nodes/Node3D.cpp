#include <glm/gtc/matrix_transform.hpp>
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
    vec4 pos = vec4(vec3(transformation[3]), 1.0f);
    transformation[3] = vec4(0, 0, 0, 1);
    transformation = glm::scale(transformation, scale);
    transformation[3] = pos;
}

#include <Utils.hpp>

void Node3D::rotate(float angle, const vec3 &axis)
{
    vec4 pos = vec4(vec3(transformation[3]), 1.0f);
    transformation[3] = vec4(0, 0, 0, 1);
    transformation = glm::rotate(transformation, angle, axis);
    transformation[3] = pos;
}
