#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Interface.hpp>

#include <Engine/RenderEngine.hpp>
#include <Engine/PhysicEngine.hpp>

#include <Graphic/Mesh.hpp>
#include <Graphic/Material.hpp>

#include <GameScene/GameSceneIncludes.hpp>

using std::vector;
using namespace glm;

class Node : public IDisposable
{
private:
    vector<Node *> children;

public:
    Node *parent = nullptr;

    bool add_child(Node *child);
    bool remove_child(Node *child);

    virtual void enter();
    virtual void update();
    virtual void dispose() override{};
};

class Node3D : public Node
{

protected:
    mat4 transformation;

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

class Object3D : public Node3D
{
public:
    Mesh *mesh;
    Material *material;
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