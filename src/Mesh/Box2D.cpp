#include <Mesh/Box2D.hpp>

Box2D::Box2D(float width, float height) : Mesh(generateBoxData(width, height))
{
}

Box2D::~Box2D()
{
}

MeshDataContainer Box2D::generateBoxData(float width, float height)
{
    vector<float> vertices{
        -width / 2.0f, -height / 2.0f, 0.0f,
        -width / 2.0f, height / 2.0f, 0.0f,
        width / 2.0f, height / 2.0f, 0.0f,
        width / 2.0f, -height / 2.0f, 0.0f};

    vector<float> normals{
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f};

    vector<unsigned int> indices{
        0, 1, 2, 2, 3, 0};

    return MeshDataContainer{vertices, normals, {}, {}, {}, indices};
}