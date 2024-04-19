#pragma once 

#include <map>
#include <Graphic/Mesh.hpp>
#include <glad/glad.h>

class RenderEngine
{
public:
    virtual void addMesh(Mesh *mesh) = 0;
    virtual void removeMesh(Mesh *mesh) = 0;

    virtual void buildMesh(Mesh* mesh) = 0;
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
    std::map<Mesh *, RenderData *> render_id;

public:
    virtual void addMesh(Mesh *mesh) override;
    virtual void removeMesh(Mesh *mesh) override;

    virtual void buildMesh(Mesh* mesh) override;
    virtual void dispose_meshes() override;
    virtual void renderBegin() override;
    virtual void render() override;
    virtual void renderEnd() override;
};
