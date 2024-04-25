#pragma once

#include <vector>

class RenderEngine;
class PhysicWorld;
class GameScene;
class DefaultMaterial;
class Node;
class Camera;
class AudioEngine;

class SceneTree
{
private:
    // std::vector<Camera *> cams;
    std::vector<Node *> nodes;
    RenderEngine *renderEngine = nullptr;
    PhysicWorld *physicWorld = nullptr;
    GameScene * scene = nullptr;
    AudioEngine* audioEngine = nullptr;
    
    DefaultMaterial *mat;

public:
    float delta;
    Camera* cam;    

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