#include <Mesh/Box3D.hpp>

Box3D::Box3D(float width, float height, float depth) : Mesh(generateBoxData(width, height, depth)) 
{
}

Box3D::~Box3D()
{
}

MeshDataContainer Box3D::generateBoxData(float width, float height, float depth)
{
    vector<float> vertices{
        -width / 2.0f, -height / 2.0f, -depth / 2.0f,
        -width / 2.0f, height / 2.0f, -depth / 2.0f,
        width / 2.0f, height / 2.0f, -depth / 2.0f,
        width / 2.0f, -height / 2.0f, -depth / 2.0f,

        -width / 2.0f, -height / 2.0f, depth / 2.0f,
        -width / 2.0f, height / 2.0f, depth / 2.0f,
        width / 2.0f, height / 2.0f, depth / 2.0f,
        width / 2.0f, -height / 2.0f, depth / 2.0f};

    vector<float> normals{
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, -1.0f, 0.0f};

    vector<unsigned int> indices{
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        0, 4, 7, 7, 3, 0,
        1, 5, 6, 6, 2, 1,
        0, 1, 5, 5, 4, 0,
        3, 2, 6, 6, 7, 3};

    return MeshDataContainer{vertices, normals, {}, {}, {}, indices};
}