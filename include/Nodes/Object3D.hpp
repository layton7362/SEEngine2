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
    Mesh *mesh;
    Material *material;
    vector<float> packedData;

    Object3D();
    virtual ~Object3D() noexcept;

    void enter() override;
    void update(const float &delta) override;

    unsigned int getMeshSize();
    unsigned int getTrianglesCount();
    bool hasIndices();
    void BuildMeshArray();
    void dispose() override; 
};
