#include <Nodes/Object3D.hpp>

Object3D::Object3D()
{
}

Object3D::~Object3D()
{
}

void Object3D::enter()
{
    GLint loc = glGetUniformLocation(material->getProgramId(), "transformation");
    addUniform(loc, UniformCall(TraitUniform::setMatrix4(loc, transformation)));
}

void Object3D::update(const float &delta)
{
}

void Object3D::BuildMeshArray()
{
    packedData = vector<float>(getMeshSize());
    vector<vec3> vertices = mesh->getVertices();
    vector<vec3> normals = mesh->getNormals();
    vector<vec4> colors = mesh->getColors();
    vector<vec2> uv1 = mesh->getUV1();

    unsigned int offset = 0;
    for (const auto &vertex : vertices)
    {
        packedData[offset++] = vertex.x;
        packedData[offset++] = vertex.y;
        packedData[offset++] = vertex.z;
    }

    for (const auto &normal : normals)
    {
        packedData[offset++] = normal.x;
        packedData[offset++] = normal.y;
        packedData[offset++] = normal.z;
    }

    for (const auto &color : colors)
    {
        packedData[offset++] = color.r;
        packedData[offset++] = color.g;
        packedData[offset++] = color.b;
        packedData[offset++] = color.a;
    }

    for (const auto &uv : uv1)
    {
        packedData[offset++] = uv.x;
        packedData[offset++] = uv.y;
    }
    //  packedData[offset++] = 10000;
}

unsigned int Object3D::getMeshSize()
{
    vector<vec3> vertices = mesh->getVertices();
    vector<vec3> normals = mesh->getNormals();
    vector<vec4> colors = mesh->getColors();
    vector<vec2> uv1 = mesh->getUV1();

    return 3 * vertices.size() + 3 * normals.size() + 4 * colors.size() + 2 * uv1.size();
}

unsigned int Object3D::getTrianglesCount()
{
    if (hasIndices())
    {
        return mesh->getIndices().size();
    }else{
        return mesh->getVertices().size() ;
    }
}

bool Object3D::hasIndices()
{
    return mesh->getIndices().size() > 0;
}

void Object3D::dispose()
{
    if (disposed)
    {
        return;
    }
}