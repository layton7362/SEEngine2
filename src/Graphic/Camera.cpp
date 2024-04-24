#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Graphic/Camera.hpp>

Camera::Camera()
{
    cameraPos = vec3(0.0f, 0.0f, 0.0f);
    vec3 cameraTarget = vec3(0.0f, 0.0f, 0.0f);
    vec3 cameraDirection = normalize(cameraPos - cameraTarget);
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

Camera::~Camera()
{
}

inline mat4 Camera::lookAt(const vec3 &target, const vec3 &up)
{
    return glm::lookAt(this->cameraPos, target, up);
}
