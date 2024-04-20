#pragma once

#include <vector>

class RenderEngine;
class PhysicWorld;
class GameScene;
class DefaultMaterial;
class Node;

class SceneTree
{
private:
    std::vector<Node *> nodes;
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