#pragma once

#include <map>
#include <vector>
#include <glad/glad.h>
#include <Interface.hpp>
#include <Nodes/Object3D.hpp>
#include <Graphic/Mesh.hpp>
#include <Types.hpp>

using std::vector;

class Object3D;
class Camera;

class RenderEngine : public IDisposable
{
public:
    virtual void addObject(Object3D *mesh) = 0;

    virtual void removeObject(Object3D *mesh) = 0;

    virtual void buildMesh(Object3D *mesh) = 0;
    virtual void dispose_meshes() = 0;

    virtual void renderBegin(const Color4 &clear) = 0;
    virtual void addCameraUniform(Camera *, Object3D *) = 0;

    virtual void render() = 0;
    virtual void renderEnd() = 0;

    virtual void viewportUpdate(uint16_t x, uint16_t y, uint16_t w, uint16_t h) = 0;
};

struct RenderData
{
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
};

struct MaterialData
{
    GLuint id;
    vector<Object3D *> object;
};
