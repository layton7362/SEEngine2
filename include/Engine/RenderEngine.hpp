#pragma once

#include <map>
#include <glad/glad.h>
#include <Interface.hpp>
#include <Nodes/Object3D.hpp>
#include <Graphic/Mesh.hpp>
#include <Types.hpp>


class Object3D;
class Camera;

class RenderEngine : public IDisposable
{
public:
    virtual void addObject(Object3D *mesh) = 0;

    virtual void removeObject(Object3D *mesh) = 0;

    virtual void buildMesh(Object3D *mesh) = 0;
    virtual void dispose_meshes() = 0;

    virtual void renderBegin(const Color4& clear) = 0;
    virtual void addCameraUniform(Camera*,Object3D*) = 0;

    virtual void render() = 0;
    virtual void renderEnd() = 0;
};

struct RenderData
{
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
};
