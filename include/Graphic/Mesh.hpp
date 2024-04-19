#pragma once

#include <Core/Base.hpp>
#include <array>
#include <variant>
#include <vector>

using std::array;
using std::variant;
using std::vector;

struct MeshData
{
    enum Type
    {
        VERTICES = 0,
        NORMALS = 1,
        COLORS = 2,
        UV1 = 3,
        UV2 = 4,
        INDICES = 5,
    };
    inline static const unsigned int Count = 6;
};

using Container = variant<vector<float>,vector<unsigned int>>;
using MeshDataContainer = array<Container, MeshData::Count>;

class Mesh : public Resource
{

private:
    MeshDataContainer data;

public:
    Mesh(const MeshDataContainer &);
    virtual ~Mesh() noexcept;

    MeshDataContainer &getData();

    const vector<float> &getVertices() const;
    const vector<float> &getNormals() const;
    const vector<float> &getColors() const;
    const vector<float> &getUV1() const;
    const vector<float> &getUV2() const;
    const vector<unsigned int> &getIndices() const;
};