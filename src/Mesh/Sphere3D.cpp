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
    vector<uvec3> indices;

    // add top vertex


    // auto v0 = mesh.add_vertex(Point(0, 1, 0));

    // // generate vertices per stack / slice
    // for (int i = 0; i < n_stacks - 1; i++)
    // {
    //     auto phi = M_PI * double(i + 1) / double(n_stacks);
    //     for (int j = 0; j < n_slices; j++)
    //     {
    //         auto theta = 2.0 * M_PI * double(j) / double(n_slices);
    //         auto x = std::sin(phi) * std::cos(theta);
    //         auto y = std::cos(phi);
    //         auto z = std::sin(phi) * std::sin(theta);
    //         mesh.add_vertex(Point(x, y, z));
    //     }
    // }

    // // add bottom vertex
    // auto v1 = mesh.add_vertex(Point(0, -1, 0));

    // // add top / bottom triangles
    // for (int i = 0; i < n_slices; ++i)
    // {
    //     auto i0 = i + 1;
    //     auto i1 = (i + 1) % n_slices + 1;
    //     mesh.add_triangle(v0, Vertex(i1), Vertex(i0));
    //     i0 = i + n_slices * (n_stacks - 2) + 1;
    //     i1 = (i + 1) % n_slices + n_slices * (n_stacks - 2) + 1;
    //     mesh.add_triangle(v1, Vertex(i0), Vertex(i1));
    // }

    // // add quads per stack / slice
    // for (int j = 0; j < n_stacks - 2; j++)
    // {
    //     auto j0 = j * n_slices + 1;
    //     auto j1 = (j + 1) * n_slices + 1;
    //     for (int i = 0; i < n_slices; i++)
    //     {
    //         auto i0 = j0 + i;
    //         auto i1 = j0 + (i + 1) % n_slices;
    //         auto i2 = j1 + (i + 1) % n_slices;
    //         auto i3 = j1 + i;
    //         mesh.add_quad(Vertex(i0), Vertex(i1),
    //                       Vertex(i2), Vertex(i3));
    //     }
    // }

    return MeshDataContainer{vertices, normals, {}, {}, {}, indices};
}