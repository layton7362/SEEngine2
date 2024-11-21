#pragma once

#include <Core/ResourceType.hpp>
#include <array>
#include <variant>
#include <vector>
#include <glm/glm.hpp>

using glm::uvec3;
using glm::vec2;
using glm::vec3;
using glm::vec4;
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

using Container = variant<vector<vec2>, vector<vec3>, vector<vec4>, vector<uvec3>, vector<float>>;
using MeshDataContainer = array<Container, MeshData::Count>;

class Mesh : public ResourceType
{

private:
    MeshDataContainer data;

public:
    Mesh();
    Mesh(const MeshDataContainer &);
    virtual ~Mesh() noexcept;

    MeshDataContainer &getData();

    const vector<vec3> &getVertices() const;
    const vector<vec3> &getNormals() const;
    const vector<vec4> &getColors() const;
    const vector<vec2> &getUV1() const;
    const vector<vec2> &getUV2() const;
    const vector<uvec3> &getIndices() const;

    // unsigned int getVerticesSize() const;
    // unsigned int getNormalsSize() const;
    // unsigned int getColorsSize() const;
    // unsigned int getUV1Size() const;
    // unsigned int getUV2Size() const;
    // unsigned int getIndicesSize() const;
};