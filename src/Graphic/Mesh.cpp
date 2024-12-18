#include <Graphic/Mesh.hpp>

Mesh::Mesh():ResourceType()
{
}

Mesh::Mesh(const MeshDataContainer &meshData) : ResourceType()
{
    data[MeshData::VERTICES] = meshData[MeshData::VERTICES];
    data[MeshData::NORMALS] = meshData[MeshData::NORMALS];
    data[MeshData::COLORS] = meshData[MeshData::COLORS];
    data[MeshData::UV1] = meshData[MeshData::UV1];
    data[MeshData::UV2] = meshData[MeshData::UV2];
    data[MeshData::INDICES] = meshData[MeshData::INDICES];
}

Mesh::~Mesh() noexcept
{
    // Empty
}

// MeshDatContainer &Mesh::getData()
// {
// return this->data;
// }

const vector<vec3> &Mesh::getVertices() const
{
    return std::get<vector<vec3>>(data[MeshData::VERTICES]);
}

const vector<vec3> &Mesh::getNormals() const
{
    return std::get<vector<vec3>>(data[MeshData::NORMALS]);
}

const vector<vec4> &Mesh::getColors() const
{
    return std::get<vector<vec4>>(data[MeshData::COLORS]);
}

const vector<vec2> &Mesh::getUV1() const
{
    return std::get<vector<vec2>>(data[MeshData::UV1]);
}

const vector<vec2> &Mesh::getUV2() const
{
    return std::get<vector<vec2>>(data[MeshData::UV2]);
}

const vector<uvec3> &Mesh::getIndices() const
{
    return std::get<vector<uvec3>>(data[MeshData::INDICES]);
}
