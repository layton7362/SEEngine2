#pragma once

#include <Engine/RenderEngine.hpp>

class OpenGLRenderEngine : public RenderEngine
{
private:
    std::map<Object3D *, RenderData *> render_id;

public:
    OpenGLRenderEngine();
    virtual ~OpenGLRenderEngine() noexcept;
    virtual void addObject(Object3D *mesh) override;
    virtual void removeObject(Object3D *mesh) override;

    virtual void buildMesh(Object3D *mesh) override;
    virtual void dispose_meshes() override;
    virtual void renderBegin() override;
    virtual void render() override;
    virtual void renderEnd() override;
    virtual void dispose() override;
};