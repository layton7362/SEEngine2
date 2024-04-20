#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Core/Object.hpp>

#include <Engine/RenderEngine.hpp>
#include <Engine/PhysicEngine.hpp>

#include <Graphic/Mesh.hpp>
#include <Graphic/Material.hpp>
#include <Graphic/Uniform.hpp>

#include <GameScene/GameSceneIncludes.hpp>

#include <Manager/InputManager.hpp>

using std::vector;
using namespace glm;

class Node : public Object
{
private:
    vector<Node *> children;

public:
    Node *parent = nullptr;

    bool add_child(Node *child);
    bool remove_child(Node *child);

    virtual void enter();
    virtual void update(const float& delta );
    virtual void dispose() override{};
};

class Node3D : public Node
{
protected:
    mat4 transformation = mat4(1.0f);

public:
    void translate(const glm::vec3 &translation)
    {
        transformation = glm::translate(transformation, translation);
    }

    void scale(const glm::vec3 &scale)
    {
        transformation = glm::scale(transformation, scale);
    }

    void rotate(float angle, const glm::vec3 &axis)
    {
        transformation = glm::rotate(transformation, angle, axis);
    }
};

class Object3D : public Node3D, public TraitUniform
{
public:
    map<GLint, UniformCallable> uniforms;

public:
    Mesh *mesh;
    Material *material;

    void enter() override
    {
        // translate(vec3(-1,0,0));
        GLint loc = glGetUniformLocation(material->getProgramId(), "transformation");
        addUniform(loc, UniformCall(TraitUniform::setMatrix4(loc, transformation)));
    }
    void update(const float& delta ) override
    {
        const float speed = delta * 1;
        if (InputManager::isPressed(KeyCode::ARROW_LEFT))
            translate(vec3(-speed, 0, 0));
        if (InputManager::isPressed(KeyCode::ARROW_RIGHT))
            translate(vec3(speed, 0, 0));
        if (InputManager::isPressed(KeyCode::ARROW_DOWN))
            translate(vec3(0, -speed, 0));
        if (InputManager::isPressed(KeyCode::ARROW_UP))
            translate(vec3(0, speed, 0));
        if (InputManager::isPressed(KeyCode::R))
            rotate(1 * delta , vec3(1,0,0));
        
    }
};

class RenderEngine;
class SceneTree
{
private:
    vector<Node *> nodes;
    

    RenderEngine *renderEngine = nullptr;
    PhysicWorld *physicWorld = nullptr;
    GameScene *scene = nullptr;

    DefaultMaterial *mat;

public:

    float delta;

public:

    SceneTree();
    ~SceneTree();

    void addNode(Node *node);
    Node *removeNode(Node *node);
    bool hasNode(Node *node);

    void changeScene(GameScene *scene);

    void init();
    void mainUpdate();
    void physikUpdate();
    void renderUpdate();

    void dispose();
};