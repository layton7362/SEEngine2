#pragma once 

#include <map>
#include <glad/glad.h>
#include <Interface.hpp>
#include <Core/Graph.hpp>
#include <Graphic/Mesh.hpp>

class Object3D;

class RenderEngine: public IDisposable
{
public:
    virtual void addObject(Object3D *mesh) = 0;

    virtual void removeObject(Object3D *mesh) = 0;

    virtual void buildMesh(Object3D* mesh) = 0;
    virtual void dispose_meshes() = 0;

    virtual void renderBegin() = 0;
    virtual void render() = 0;
    virtual void renderEnd() = 0;
};

struct RenderData
{
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
};

class OpenGLRenderEngine : public RenderEngine
{
private:
    std::map<Object3D *, RenderData *> render_id;

public:
    virtual void addObject(Object3D *mesh) override;
    virtual void removeObject(Object3D *mesh) override;

    virtual void buildMesh(Object3D* mesh) override;
    virtual void dispose_meshes() override;
    virtual void renderBegin() override;
    virtual void render() override;
    virtual void renderEnd() override;
    virtual void dispose() override;
};
