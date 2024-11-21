#pragma once
#include <array>
#include <Graphic/Shader.hpp>
#include <Graphic/Material.hpp>

class DefaultMaterial : public Material
{
private:
    DefaultMaterial(std::array<Shader *, ShaderListType::Count> shaders) = delete;

    
public:
    DefaultMaterial();
    virtual ~DefaultMaterial() noexcept;
};