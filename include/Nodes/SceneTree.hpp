#pragma once

#include <vector>
#include <Types.hpp>

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

    Color4 clearColor = Color4(0.2f, 0.3f, 0.3f, 1.0f);

    

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
    void viewportUpdate(uint16_t x,uint16_t y,uint16_t w,uint16_t h);
    void dispose();
};