#include <Graphic/DefaultMaterial.hpp>
#include <Graphic/Mesh.hpp>
#include <Nodes/Object3D.hpp>
#include <vector>
#include <Nodes/SceneTree.hpp>
#include <GameScene/GameScenePlayground.hpp>

#include <Mesh/Sphere2D.hpp>
#include <Mesh/Box2D.hpp>

using std::vector;

GameScenePlayground::GameScenePlayground(SceneTree &tree) : GameScene(tree)
{
}

void GameScenePlayground::init()
{
    DefaultMaterial *material = new DefaultMaterial();

    vec3 vertices[] = {
       { 0.5f, 0.5f, 0.0f},   // top right
       { 0.5f, -0.5f, 0.0f},  // bottom right
       { -0.5f, -0.5f, 0.0f}, // bottom left
       { -0.5f, 0.5f, 0.0f}   // top left
    };
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    vector<vec3> vertices_vec(std::begin(vertices), std::end(vertices));
    vector<uvec3> indices_vec(std::begin(indices), std::end(indices));
    MeshDataContainer data;
    data[MeshData::VERTICES] = vertices_vec;
    data[MeshData::INDICES] = indices_vec;

    Mesh *mesh = new Mesh(data);

    // obj = new Object3D();
    // obj->mesh = mesh;
    // obj->material = new DefaultMaterial();
    // tree->addNode(obj);

    player = new Object3D();
    player->mesh = mesh;
    player->material = new DefaultMaterial();
    tree->addNode(player);
}

void GameScenePlayground::update(const float &delta)
{
    const float speed = delta * 1;
    if (InputManager::isPressed(KeyCode::ARROW_LEFT))
        player->translate(vec3(-speed, 0, 0));
    if (InputManager::isPressed(KeyCode::ARROW_RIGHT))
        player->translate(vec3(speed, 0, 0));
    if (InputManager::isPressed(KeyCode::ARROW_DOWN))
        player->translate(vec3(0, -speed, 0));
    if (InputManager::isPressed(KeyCode::ARROW_UP))
        player->translate(vec3(0, speed, 0));
    if (InputManager::isPressed(KeyCode::R))
        player->rotate(1 * delta, vec3(1, 0, 0));
}

void GameScenePlayground::dispose()
{
    obj->dispose();
}
