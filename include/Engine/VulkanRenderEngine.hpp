#pragma once

#include <Nodes/Object3D.hpp>
#include <vulkan/vulkan.h>
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <Engine/RenderEngine.hpp>


struct Vertex {
    glm::vec2 pos;
    glm::vec3 color;

    static VkVertexInputBindingDescription getBindingDescription() {
        VkVertexInputBindingDescription bindingDescription{};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Vertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescription;
    }

    static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions() {
        std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};

        attributeDescriptions[0].binding = 0;
        attributeDescriptions[0].location = 0;
        attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
        attributeDescriptions[0].offset = offsetof(Vertex, pos);

        attributeDescriptions[1].binding = 0;
        attributeDescriptions[1].location = 1;
        attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
        attributeDescriptions[1].offset = offsetof(Vertex, color);

        return attributeDescriptions;
    }
};

class VulkanRenderEngine : public RenderEngine
{
private:
    class VulkanDeviceConfig* vulkanDeviceConfig; 

public:
    VulkanRenderEngine();
    ~VulkanRenderEngine();

    void init() override;
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