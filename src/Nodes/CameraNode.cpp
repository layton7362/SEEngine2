#include <Manager/InputManager.hpp>
#include <Graphic/Camera.hpp>
#include <Nodes/CameraNode.hpp>

CameraNode::CameraNode()
{
    cam = new Camera();
}

CameraNode::~CameraNode()
{
}

void CameraNode::update(const float& delta)
{
    const float speed = delta * 5;
    if (InputManager::isPressed(KeyCode::ARROW_RIGHT))
        translate(vec3(-speed, 0, 0));
    if (InputManager::isPressed(KeyCode::ARROW_LEFT))
        translate(vec3(speed, 0, 0));
    if (InputManager::isPressed(KeyCode::ARROW_DOWN))
        translate(vec3(0, 0, -speed));
    if (InputManager::isPressed(KeyCode::ARROW_UP))
        translate(vec3(0, 0, speed));

    cam->view = transformation;
}

void CameraNode::dispose()
{
    delete this->cam;
};
