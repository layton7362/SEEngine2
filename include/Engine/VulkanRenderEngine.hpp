#pragma once

#include <Nodes/Object3D.hpp>
#include <vulkan/vulkan.h>
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <Engine/RenderEngine.hpp>

class VulkanRenderEngine : public RenderEngine
{
public:
    VulkanRenderEngine();
    ~VulkanRenderEngine();

    void addObject(Object3D *mesh) override;
    void removeObject(Object3D *mesh) override;

    void buildMesh(Object3D *mesh) override;
    void dispose_meshes() override;

    void renderBegin(const Color4 &clear) override;
    void addCameraUniform(Camera *, Object3D *) override;

    void render() override;
    void renderEnd() override;

    void viewportUpdate(uint16_t x, uint16_t y, uint16_t w, uint16_t h) override;

    void dispose() override;
};