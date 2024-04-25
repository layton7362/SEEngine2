#pragma once

#include <Types.hpp>

class Camera
{
public:
    mat4 view;
    mat4 projection;

public:
    Camera(const float &fov = 45, const float &ratio = 800.0f / 600.0f, const float &near = 0.1, const float &far = 100);
    virtual ~Camera() noexcept;

    inline mat4 lookAt(const vec3 &target, const vec3 &up = std::move(AXIS_Y));
    void translate(const vec3 &translation);
    void scale(const vec3 &scale);
    void rotate(float angle, const vec3 &axis);
};
