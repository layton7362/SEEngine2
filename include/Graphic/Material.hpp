#pragma once

#include <Core/Base.hpp>
#include <Core/String.hpp>
#include <Graphic/Shader.hpp>
#include <variant>
#include <glm/glm.hpp>
#include <array>
#include <map>
#include <GL/gl.h> // Beispielsweise
#include <functional>

using std::array;
using std::map;
using std::variant;

using glm::mat2;
using glm::mat3;
using glm::mat4;
using glm::vec2;
using glm::vec3;
using glm::vec4;

using GLVariant = variant<
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

struct Uniform
{
    static void setVector2(GLint location, const vec2 &value)
    {
        glUniform2fv(location, 1, &value[0]);
    }

    static void setVector3(GLint location, const vec3 &value)
    {
        glUniform3fv(location, 1, &value[0]);
    }

    static void setVector4(GLint location, const vec4 &value)
    {
        glUniform4fv(location, 1, &value[0]);
    }

    static void setMatrix2(GLint location, const mat2 &value)
    {
        glUniformMatrix2fv(location, 1, GL_FALSE, &value[0][0]);
    }

    static void setMatrix3(GLint location, const mat3 &value)
    {
        glUniformMatrix3fv(location, 1, GL_FALSE, &value[0][0]);
    }

    static void setMatrix4(GLint location, const mat4 &value)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
    }

    static void setInt(GLint location, const GLint &value)
    {
        glUniform1i(location, value);
    }

    static void setFloat(GLint location, const GLfloat &value)
    {
        glUniform1f(location, value);
    }

    static void setDouble(GLint location, const GLdouble &value)
    {
        glUniform1d(location, value);
    }
};

using UniformCallable = std::function<void()>;

#define UniformCall(C) [=](){C;}

class Material : public Resource
{
protected:
    size_t programId;
    map<GLint,UniformCallable> uniforms;

    void build(array<Shader *, ShaderListType::Count> &shaders);

public:
    Material();
    Material(array<Shader *, ShaderListType::Count> shaders);
    virtual ~Material() noexcept;
    size_t getProgramId();
    void addUniform(GLint, std::function<void()>);
    void updateUniform(GLint, std::function<void()>);
    void loadUniforms();
    void useMaterial();
};

class DefaultMaterial : public Material
{

private:
    DefaultMaterial(array<Shader *, ShaderListType::Count> shaders);

public:
    DefaultMaterial();
    virtual ~DefaultMaterial() noexcept;
};