#pragma once

#include <Engine/RenderEngine.hpp>

class Camera;

class OpenGLRenderEngine : public RenderEngine
{
private:
    std::map<Object3D *, RenderData *> render_id;

public:
    OpenGLRenderEngine();
    ~OpenGLRenderEngine() noexcept;

    void addObject(Object3D *mesh) override;
    void removeObject(Object3D *mesh) override;
    void buildMesh(Object3D *mesh) override;
    void dispose_meshes() override;
    void renderBegin() override;
    void addCameraUniform(Camera *, Object3D *) override;
    void render() override;
    void renderEnd() override;
    void dispose() override;
};