#pragma once

#include <Nodes/Node3D.hpp>

class Camera;

class CameraNode : public Node3D
{
public:
    Camera *cam;

    CameraNode();
    virtual ~CameraNode() noexcept;

    virtual void update(const float &delta) override;
    virtual void dispose() override;
};
