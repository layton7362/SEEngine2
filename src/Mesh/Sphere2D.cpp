#include <math.h>

#include <Mesh/Sphere2D.hpp>

Sphere2D::Sphere2D(const float &radius) : Mesh(generateCircleData(radius))
{
}

Sphere2D::~Sphere2D()
{
}

MeshDataContainer Sphere2D::generateCircleData(float radius)
{
    vector<float> vertices;
    vector<float> normals;
    vector<unsigned int> indices;

    const int segments = 30;
    const float angleStep = 2.0f * M_PI / segments;

    // Generate circle vertices
    for (int i = 0; i < segments; ++i)
    {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0.0f); // z-coordinate for 2D circle
        normals.push_back(0.0f);
        normals.push_back(0.0f);
        normals.push_back(1.0f); // Normal vector pointing upwards (z-axis)
    }

    // Generate circle indices
    for (int i = 0; i < segments - 1; ++i)
    {
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }
    indices.push_back(0);
    indices.push_back(segments);
    indices.push_back(1);

    return MeshDataContainer{vertices, normals, {}, {}, {}, indices};
}
