#pragma once

#include <Manager/InputManager.hpp>
#include <Graphic/Uniform.hpp>
#include <Graphic/Mesh.hpp>
#include <Graphic/Material.hpp>
#include "Node3D.hpp"
#include "Node3D.hpp"

using namespace glm;

class Object3D : public Node3D, public TraitUniform
{
public:
    map<GLint, UniformCallable> uniforms;

public:
    Mesh *mesh;
    Material *material;

    Object3D();
    virtual ~Object3D() noexcept;

    void enter() override;
    void update(const float &delta) override;

    void dispose() override; 
};
