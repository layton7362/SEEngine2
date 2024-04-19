#include <Graphic/Mesh.hpp>

Mesh::Mesh(const MeshDataContainer &meshData): Resource()
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
//     return this->data;
// }

const vector<float> &Mesh::getVertices() const
{
    return std::get<vector<float>>(data[MeshData::VERTICES]);
}

const vector<float> &Mesh::getNormals() const {
    return std::get<vector<float>>(data[MeshData::NORMALS]);
}

const vector<float> &Mesh::getColors() const {
    return std::get<vector<float>>(data[MeshData::COLORS]);
}

const vector<float> &Mesh::getUV1() const {
    return std::get<vector<float>>(data[MeshData::UV1]);
}

const vector<float> &Mesh::getUV2() const {
    return std::get<vector<float>>(data[MeshData::UV2]);
}

const vector<unsigned int> &Mesh::getIndices() const
{               
    return std::get<vector<unsigned int>>(data[MeshData::INDICES]);
}
