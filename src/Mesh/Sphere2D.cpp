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
    vector<vec3> vertices;
    vector<vec3> normals;
    vector<uvec3> indices;

    const int segments = 30;
    const float angleStep = 2.0f * M_PI / segments;

    // Generate circle vertices
    for (int i = 0; i < segments; ++i)
    {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        vertices.push_back({x, y, 0.0f});
        normals.push_back({0.0f, 0.0f, 1.0f}); // Normal vector pointing upwards (z-axis)
    }

    // Generate circle indices
    for (int i = 0; i < segments - 1; ++i)
    {
        indices.push_back({0, i + 1, i + 2});
    }
    indices.push_back({0, segments, 1});

    return MeshDataContainer{vertices, normals, {}, {}, {}, indices};
}
