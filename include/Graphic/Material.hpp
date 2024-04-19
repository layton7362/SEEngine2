#pragma once

#include <Core/Base.hpp>
#include <Graphic/Shader.hpp>
#include <array>

class Material : public Resource
{
private:
    size_t programId;
    
public:
    Material(std::array<Shader*, ShaderListType::Count> shaders);
    virtual ~Material() noexcept;
    
    size_t getProgramId();
};