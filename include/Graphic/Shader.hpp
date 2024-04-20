#pragma once

#include <Core/RessourceType.hpp>
#include <Core/String.hpp>
#include <Core/File.hpp>
#include <glad/glad.h>

class ShaderType
{
public:
    enum Type
    {
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER,
        GEOMETRY = GL_GEOMETRY_SHADER,
        COMPUTE = GL_COMPUTE_SHADER,
    };
    inline static const size_t Count = 4;
};

class ShaderListType
{
public:
    enum Type
    {
        VERTEX = 0,
        FRAGMENT = 1,
        GEOMETRY = 2,
        COMPUTE = 3,

    };
    inline static const size_t Count = 4;
};

class Shader : public RessourceType
{
public:
    FileData file;
    unsigned int genId;
    ShaderType::Type type;

public:
    Shader(const char *path, const ShaderType::Type &type);
    void dispose();
};

class ShaderVertex : public Shader
{

public:
    ShaderVertex(const String &path);
};

class ShaderFragment : public Shader
{

public:
    ShaderFragment(const String &path);
};

class ShaderGeometry : public Shader
{
public:
    ShaderGeometry(const String &path);
};
