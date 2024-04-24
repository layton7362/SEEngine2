#include <Graphic/DefaultMaterial.hpp>

DefaultMaterial::DefaultMaterial() : Material()
{
    ShaderVertex *vs = new ShaderVertex("res/shaders/basic.vert");
    ShaderFragment *fs = new ShaderFragment("res/shaders/basic.frag");

    std::array<Shader *, ShaderListType::Count> shaders;

    shaders[ShaderListType::VERTEX] = vs;
    shaders[ShaderListType::FRAGMENT] = fs;
    shaders[ShaderListType::GEOMETRY] = nullptr;
    shaders[ShaderListType::COMPUTE] = nullptr;

    build(shaders);
}

DefaultMaterial::~DefaultMaterial()
{
        
}

