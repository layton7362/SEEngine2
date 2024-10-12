#include <Engine/VulkanDeviceConfig.hpp>
#include <Engine/VulkanPipeline.hpp>

VulkanPipeline::VulkanPipeline()
{
}

VulkanPipeline::~VulkanPipeline()
{
}

void VulkanPipeline::init()
{
    vulkanDeviceConfig = new VulkanDeviceConfig();
    vulkanDeviceConfig->init();

    createRenderPass();
    createGraphicsPipeline();
    createFramebuffers();
    createCommandPool();
    createVertexBuffer();
    createCommandBuffers();
    createSyncObjects();
}

void VulkanPipeline::createRenderPass() {}
void VulkanPipeline::createGraphicsPipeline() {}
void VulkanPipeline::createFramebuffers() {}
void VulkanPipeline::createCommandPool() {}
void VulkanPipeline::createVertexBuffer() {}
void VulkanPipeline::createCommandBuffers() {}
void VulkanPipeline::createSyncObjects() {}