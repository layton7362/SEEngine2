#include <Graphic/Uniform.hpp>

void TraitUniform::addUniform(GLint location, std::function<void()> callable)
{
    uniforms[location] = callable;
}

void TraitUniform::updateUniform(GLint location, std::function<void()> callable)
{
    uniforms[location] = callable;
}

void TraitUniform::loadUniforms()
{
    for (const auto &pair : uniforms)
    {
        UniformCallable call = pair.second;
        call();
    }
}
