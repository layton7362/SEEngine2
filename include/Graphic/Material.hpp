#pragma once

#include <Core/Ressource.hpp>
#include <Core/String.hpp>
#include <Graphic/Shader.hpp>
#include <variant>
#include <glm/glm.hpp>
#include <array>
#include <map>
#include <Graphic/Uniform.hpp>

#include <cstdlib> 
#include <iostream>   
#include <memory>
#include <string>

using std::array;
using std::map;
using std::variant;

class Material : public Ressource, public TraitUniform
{
protected:
    size_t programId;

    void build(array<Shader *, ShaderListType::Count> &shaders);

public:
    Material();
    Material(array<Shader *, ShaderListType::Count> shaders);
    virtual ~Material() noexcept;
    size_t getProgramId();
    void useMaterial();

    void* operator new(size_t t){
        return std::malloc(t);
    };
};

class DefaultMaterial : public Material
{

private:
    DefaultMaterial(array<Shader *, ShaderListType::Count> shaders);

public:
    DefaultMaterial();
    virtual ~DefaultMaterial() noexcept;
};