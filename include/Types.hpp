#pragma once 

#include <Core/String.hpp>
#include <Core/StringUnique.hpp>
#include <Core/Ressource.hpp>
#include <glm/glm.hpp>

template<typename T>
using Res = Ressource<T>;

using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::uvec2;
using glm::uvec3;
using glm::uvec4;
using glm::dvec2;
using glm::ivec2;
using glm::mat3;
using glm::mat4;

using Color3 = vec3;
using Color4 = vec4;

using ubyte = unsigned char;
using byte = char;

constexpr vec3 AXIS_X = glm::vec3(1.0f, 0.0f, 0.0f); 
constexpr vec3 AXIS_Y = glm::vec3(0.0f, 1.0f, 0.0f); 
constexpr vec3 AXIS_Z = glm::vec3(0.0f, 0.0f, 1.0f); 

