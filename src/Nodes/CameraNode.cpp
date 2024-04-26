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
    if (Input->isPressed("RIGHT"))
        translate(vec3(-speed, 0, 0));
    if (Input->isPressed("LEFT"))
        translate(vec3(speed, 0, 0));
    if (Input->isPressed("DOWN"))
        translate(vec3(0, 0, -speed));
    if (Input->isPressed("UP"))
        translate(vec3(0, 0, speed));
    if (Input->isPressed("DIVE"))
        translate(vec3(0, -speed, 0));
    if (Input->isPressed("FLY"))
        translate(vec3(0, speed, 0));
    cam->view = transformation;
}

void CameraNode::dispose()
{
    delete this->cam;
};
