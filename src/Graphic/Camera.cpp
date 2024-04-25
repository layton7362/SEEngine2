#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Graphic/Camera.hpp>

Camera::Camera(const float& fov, const float& ratio,const float& near,const float& far)
{
    view = mat4(1.f);
    projection = glm::perspective(glm::radians(fov), ratio, near, far);
}

Camera::~Camera()
{
}

inline mat4 Camera::lookAt(const vec3 &target, const vec3 &up)
{
    vec3&& pos = vec3(view[0][0], view[1][1], view[2][2]);
    return glm::lookAt(pos, target, up);
}


void Camera::translate(const vec3 &translation)
{
    view = glm::translate(view, translation);
}

void Camera::scale(const vec3 &scale)
{
    view = glm::scale(view, scale);
}

void Camera::rotate(float angle, const vec3 &axis)
{
    view = glm::rotate(view, angle, axis);
}