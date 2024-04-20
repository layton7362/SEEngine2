#include <Nodes/SceneTree.hpp>
#include <algorithm>
#include <Core/Log.hpp>
#include <Utils.hpp>
#include <GameScene/GameScenePlayground.hpp>
#include <Engine/RenderEngine.hpp>
#include <Engine/PhysicEngine.hpp>
#include <GameScene/GameScene.hpp>
#include <Nodes/Node.hpp>

SceneTree::SceneTree()
{
    nodes = vector<Node *>(0);
}

SceneTree::~SceneTree()
{
}

void SceneTree::addNode(Node *node)
{
    if (!hasNode(node))
    {
        nodes.push_back(node);
        if (Object3D *object = ToSubclass(Object3D, node))
        {
            this->renderEngine->addObject(object);
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

void SceneTree::init()
{
    this->renderEngine = new OpenGLRenderEngine();
    this->physicWorld = new PhysicWorld();

    //  TODO REMOVE
    mat = new DefaultMaterial();
    this->changeScene(new GameScenePlayground(*this));
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
    mat->useMaterial();
    this->renderEngine->render();
}

void SceneTree::dispose()
{
    DisposeAndDelete(physicWorld)
        DisposeAndDelete(renderEngine)
            DisposeAndDelete(scene)
}