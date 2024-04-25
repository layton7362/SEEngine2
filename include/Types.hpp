#pragma once 

#include <Core/String.hpp>
#include <Core/StringUnique.hpp>
#include <Core/Ressource.hpp>
#include <glm/glm.hpp>

using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;

using ubyte = unsigned char;
using byte = char;

constexpr vec3 AXIS_X = glm::vec3(1.0f, 0.0f, 0.0f); 
constexpr vec3 AXIS_Y = glm::vec3(0.0f, 1.0f, 0.0f); 
constexpr vec3 AXIS_Z = glm::vec3(0.0f, 0.0f, 1.0f); 