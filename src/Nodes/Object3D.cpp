#include <Nodes/Object3D.hpp>

Object3D::Object3D()
{
}

Object3D::~Object3D()
{
}

void Object3D::enter()
{
    // translate(vec3(-1,0,0));
    GLint loc = glGetUniformLocation(material->getProgramId(), "transformation");
    addUniform(loc, UniformCall(TraitUniform::setMatrix4(loc, transformation)));
}

void Object3D::update(const float &delta) 
{
    const float speed = delta * 1;
    if (InputManager::isPressed(KeyCode::ARROW_LEFT))
        translate(vec3(-speed, 0, 0));
    if (InputManager::isPressed(KeyCode::ARROW_RIGHT))
        translate(vec3(speed, 0, 0));
    if (InputManager::isPressed(KeyCode::ARROW_DOWN))
        translate(vec3(0, -speed, 0));
    if (InputManager::isPressed(KeyCode::ARROW_UP))
        translate(vec3(0, speed, 0));
    if (InputManager::isPressed(KeyCode::R))
        rotate(1 * delta, vec3(1, 0, 0));
}
