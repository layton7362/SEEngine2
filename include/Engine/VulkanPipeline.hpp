#pragma once
#include <Engine/VulkanTypes.hpp>

class VulkanPipeline
{
    class VulkanDeviceConfig* vulkanDeviceConfig; 
    class RenderPassData renderPassData;
    class PipelineData pipelineData;
    class SemaphoreData semaphoreData;
    class vector<VkFramebuffer> framebuffers;
    class CommandData commandData;
    
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

    VkShaderModule createShaderModule(const class FileData &code);

};
