#include <algorithm>
#include <Core/Log.hpp>
#include <Utils.hpp>
#include <GameScene/GameScenePlayground.hpp>
#include <Engine/OpenGLRenderEngine.hpp>
#include <Engine/AudioEngine.hpp>
#include <Engine/PhysicEngine.hpp>
#include <GameScene/GameScene.hpp>
#include <Graphic/DefaultMaterial.hpp>
#include <Graphic/Camera.hpp>
#include <Nodes/Node.hpp>
#include <Nodes/SceneTree.hpp>

SceneTree::SceneTree()
{
}

SceneTree::~SceneTree()
{
}

void SceneTree::init()
{
    this->renderEngine = new OpenGLRenderEngine();
    this->physicWorld = new PhysicWorld();
    this->cam = new Camera();
    this->audioEngine = new AudioEngine();
    this->audioEngine->init();
    // this->audioEngine->load("res/audio/Float 11 - Seep.wav");
    // this->audioEngine->play();
    //  TODO REMOVE
    mat = new DefaultMaterial();
    this->changeScene(new GameScenePlayground(*this));
}

void SceneTree::addNode(Node *node)
{
    if (!hasNode(node))
    {
        nodes.push_back(node);
        if (Object3D *object = toSubclass(Object3D, node))
        {
            this->renderEngine->addObject(object);
            this->renderEngine->addCameraUniform(this->cam, object);
        }
        node->enter();
    }
    else
    {
        Log::warning("Try to add node, which is already in tree");
    }
}

Node *SceneTree::removeNode(Node *node)
{
    auto it = std::find(nodes.begin(), nodes.end(), node);

    if (it != nodes.end())
    {
        nodes.erase(it);
        return node;
        node->parent = nullptr;
    }
    else
    {
        Log::warning("Try to remove node, which is not in tree");
        return nullptr;
    }
}

bool SceneTree::hasNode(Node *node)
{
    auto it = std::find(nodes.begin(), nodes.end(), node);
    return it != nodes.end();
}


void SceneTree::changeScene(GameScene *scene)
{
    if (scene == nullptr)
    {
        Log::warning("changeScene: Scene is nullptr. No scene changed!");
        return;
    }
    if (this->scene != nullptr)
    {
        this->scene->dispose();
        delete this->scene;
        this->scene = nullptr;
    }

    this->scene = scene;
    this->scene->init();
}

void SceneTree::mainUpdate()
{
    if (this->scene != nullptr)
    {
        this->scene->update(delta);
        for (auto &&e : nodes)
        {
            e->update(delta);
        }
    }
}

void SceneTree::physikUpdate()
{
}

void SceneTree::renderUpdate()
{
    this->renderEngine->renderBegin();
    // this->renderEngine->cameraUniform(this->cam,  );
    mat->useMaterial();
    this->renderEngine->render();
}

void SceneTree::dispose()
{
    DisposeAndDelete(physicWorld)
        DisposeAndDelete(renderEngine)
            DisposeAndDelete(scene)
}