#include <GameScene/GameScenePlayground.hpp>
#include <Graphic/Material.hpp>
#include <Graphic/Mesh.hpp>
#include <Nodes/Object3D.hpp>
#include <vector>

using std::vector;

GameScenePlayground::GameScenePlayground(SceneTree &tree) : GameScene(tree)
{
}

void GameScenePlayground::init()
{
    DefaultMaterial *material = new DefaultMaterial();

    float vertices[] = {
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    vector<float> vertices_vec(std::begin(vertices), std::end(vertices));
    vector<unsigned int> indices_vec(std::begin(indices), std::end(indices));
    MeshDataContainer data;
    data[MeshData::VERTICES] = vertices_vec;
    data[MeshData::INDICES] = indices_vec;

    Mesh *mesh = new Mesh(data);

    Object3D *obj = new Object3D();
    obj->mesh = mesh;
    obj->material = new DefaultMaterial();
    tree->addNode(obj);
    // OpenGLRenderEngine renderEngien;
    // renderEngien.addMesh(&mesh);
}

void GameScenePlayground::update(const float &delta)
{
}

void GameScenePlayground::dispose()
{
}
