#include <vector>
#include <math.h>

#include <Graphic/DefaultMaterial.hpp>
#include <Graphic/Mesh.hpp>
#include <Nodes/Object3D.hpp>
#include <Nodes/CameraNode.hpp>
#include <Nodes/SceneTree.hpp>
#include <GameScene/GameScenePlayground.hpp>
#include <Types.hpp>

#include <Mesh/Sphere2D.hpp>
#include <Mesh/Box2D.hpp>
#include <Mesh/Box3D.hpp>


using std::vector;

GameScenePlayground::GameScenePlayground(SceneTree &tree) : GameScene(tree)
{
}

void GameScenePlayground::init()
{
    obj = new Object3D();
    obj->translate(vec3(2, 0, -5.f));
    obj->mesh = new Box3D(1, 1, 1);
    obj->material = new DefaultMaterial();

    obj2 = new Object3D();
    obj2->translate(vec3(-2, 0, -5.f));
    obj2->mesh = obj->mesh;
    obj2->material = new DefaultMaterial();

    tree->addNode(obj);
    tree->addNode(obj2);

    // TODO REMOVE
    CameraNode *cam = new CameraNode();
    cam->cam = tree->cam;
    tree->addNode(cam);
}

void GameScenePlayground::update(const float &delta)
{
    obj->rotate(0.5 * delta, AXIS_Y);
}

void GameScenePlayground::dispose()
{
    obj->dispose();
}
