#pragma once
#include <Engine/VulkanTypes.hpp>

class VulkanPipeline
{
    class VulkanDeviceConfig* vulkanDeviceConfig; 
   
public:
    VulkanPipeline();
    virtual ~VulkanPipeline() noexcept;

    void init();

    void createRenderPass();
    void createGraphicsPipeline();
    void createFramebuffers();
    void createCommandPool();
    void createVertexBuffer();
    void createCommandBuffers();
    void createSyncObjects();
};
