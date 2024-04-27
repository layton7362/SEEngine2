#pragma once

#include <Engine/RenderEngine.hpp>

class Camera;

class OpenGLRenderEngine : public RenderEngine
{
private:
    // std::map<Object3D *, RenderData *> render_id;
    std::map<class Mesh *, RenderData *> meshIds;
    std::map<class Material*, MaterialData *> materialIds;

public:
    OpenGLRenderEngine();
    ~OpenGLRenderEngine() noexcept;

    void addObject(Object3D *mesh) override;
    void removeObject(Object3D *mesh) override;
    void addMaterial(Object3D* obj);
    void buildMesh(Object3D *mesh) override;
    void dispose_meshes() override;
    void renderBegin(const Color4& clear) override;
    void addCameraUniform(Camera *, Object3D *) override;
    void render() override;
    void renderEnd() override;
    void dispose() override;
};