#include <Graphic/DefaultMaterial2D.hpp>

DefaultMaterial2D::DefaultMaterial2D() : Material()
{
    ShaderVertex *vs = new ShaderVertex("_res/shaders/basic2D.vert");
    ShaderFragment *fs = new ShaderFragment("_res/shaders/basic2D.frag");

    std::array<Shader *, ShaderListType::Count> shaders;

    shaders[ShaderListType::VERTEX] = vs;
    shaders[ShaderListType::FRAGMENT] = fs;
    shaders[ShaderListType::GEOMETRY] = nullptr;
    shaders[ShaderListType::COMPUTE] = nullptr;

    build(shaders);
}

DefaultMaterial2D::~DefaultMaterial2D()
{
}
