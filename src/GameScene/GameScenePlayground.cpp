#include <vector>
#include <math.h>

#include <Graphic/DefaultMaterial.hpp>
#include <Graphic/DefaultMaterial2D.hpp>
#include <Graphic/Mesh.hpp>
#include <Nodes/Object3D.hpp>
#include <Nodes/CameraNode.hpp>
#include <Nodes/SceneTree.hpp>
#include <GameScene/GameScenePlayground.hpp>
#include <Types.hpp>
#include <Manager/InputManager.hpp>
#include <Mesh/Sphere2D.hpp>
#include <Mesh/Box2D.hpp>
#include <Mesh/Box3D.hpp>
#include <Misc/Config.hpp>

using std::vector;

GameScenePlayground::GameScenePlayground(SceneTree &tree) : GameScene(tree)
{
}

void GameScenePlayground::init()
{
    obj = new Object3D();
    obj->name = "3D Mash";
    obj->translate(vec3(2, 0, -5.f));
    obj->mesh = new Box3D(1, 1, 1);
    obj->material = new DefaultMaterial();


    vec3 pos = config->temp();
    obj2 = new Object3D();
    obj2->name = "2D Mash";
    obj2->translate(pos);
    obj2->mesh = new Box3D(1, 1, 1);
    obj2->material = new DefaultMaterial2D();

    tree->addNode(obj);
    tree->addNode(obj2);

    // TODO REMOVE
    CameraNode *cam = new CameraNode();
    cam->cam = tree->cam;
    tree->addNode(cam);
}

void GameScenePlayground::update(const float &delta)
{
    if (Input->isPressed(KeyCode::R))
        obj->rotate(0.5 * delta, AXIS_Y);
    if (Input->isPressed(KeyCode::E))
        obj->rotate(-0.5 * delta, AXIS_Y);
    if (Input->isPressed(KeyCode::S))
        obj->scale(vec3(1) + vec3(1) * delta);
    if (Input->isPressed(KeyCode::A))
        obj->scale(vec3(1) - vec3(1) * delta);
}

void GameScenePlayground::dispose()
{
    obj->dispose();
}
