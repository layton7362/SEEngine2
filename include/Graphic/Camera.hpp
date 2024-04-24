#pragma once

#include <Types.hpp>


class Camera
{
public: 
    vec3 cameraPos;  
    mat4 view;    
    mat4 projection;    

public:
    Camera();
    virtual ~Camera() noexcept;

    inline mat4 lookAt(const vec3& target, const vec3& up = std::move(AXIS_Y));
};
