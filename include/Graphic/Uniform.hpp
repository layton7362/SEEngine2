#pragma once

#include <variant>
#include <glm/glm.hpp>
#include <array>
#include <map>
#include <glad/glad.h>
#include <functional>

using namespace glm;
using std::map;

using UniformCallable = std::function<void()>;

#define UniformCall(C) [=]() { C; }

using GLVariant = std::variant<
    vec2,
    vec3,
    vec4,
    mat2,
    mat3,
    mat4,
    GLint,
    GLuint,
    GLfloat,
    GLdouble>;

struct TraitUniform
{
private:
    map<GLint, UniformCallable> uniforms;

public:
    void addUniform(GLint, std::function<void()>);
    void updateUniform(GLint, std::function<void()>);
    void loadUniforms();

public:
    inline static void setVector2(GLint location, const vec2 &value)
    {
        glUniform2fv(location, 1, &value[0]);
    }

    inline static void setVector3(GLint location, const vec3 &value)
    {
        glUniform3fv(location, 1, &value[0]);
    }

    inline static void setVector4(GLint location, const vec4 &value)
    {
        glUniform4fv(location, 1, &value[0]);
    }

    inline static void setMatrix2(GLint location, const mat2 &value)
    {
        glUniformMatrix2fv(location, 1, GL_FALSE, &value[0][0]);
    }

    inline static void setMatrix3(GLint location, const mat3 &value)
    {
        glUniformMatrix3fv(location, 1, GL_FALSE, &value[0][0]);
    }

    inline static void setMatrix4(GLint location, const mat4 &value)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
    }

    inline static void setInt(GLint location, const GLint &value)
    {
        glUniform1i(location, value);
    }

    inline static void setFloat(GLint location, const GLfloat &value)
    {
        glUniform1f(location, value);
    }

    inline static void setDouble(GLint location, const GLdouble &value)
    {
        glUniform1d(location, value);
    }
};
