#include <Mesh/Sphere3D.hpp>

Sphere3D::Sphere3D(const float &radius) : Mesh(generateSphereData(radius))
{
}

Sphere3D::~Sphere3D()
{
}

MeshDataContainer Sphere3D::generateSphereData(float radius)
{
    vector<float> vertices;
    vector<float> normals;
    vector<unsigned int> indices;

    // Generate sphere vertices, normals, and indices
    for (int i = 0; i <= STACKS; ++i)
    {
        float phi = static_cast<float>(i) / STACKS * static_cast<float>(M_PI);
        for (int j = 0; j <= SLICES; ++j)
        {
            float theta = static_cast<float>(j) / SLICES * 2.0f * static_cast<float>(M_PI);
            float x = radius * sin(phi) * cos(theta);
            float y = radius * cos(phi);
            float z = radius * sin(phi) * sin(theta);

            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            normals.push_back(x / radius);
            normals.push_back(y / radius);
            normals.push_back(z / radius);
        }
    }

    // Generate sphere indices
    for (int i = 0; i < STACKS; ++i)
    {
        for (int j = 0; j < SLICES; ++j)
        {
            int first = (i * (SLICES + 1)) + j;
            int second = first + SLICES + 1;
            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);
            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }

    return MeshDataContainer{vertices, normals, {}, {}, {}, indices};
}