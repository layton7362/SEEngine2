#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Core/Object.hpp>

#include <Engine/RenderEngine.hpp>
#include <Engine/PhysicEngine.hpp>

#include <GameScene/GameScene.hpp>
#include <Nodes/Node.hpp>

using namespace glm;

class RenderEngine;
class GameScene;

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
    ~SceneTree() noexcept;

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