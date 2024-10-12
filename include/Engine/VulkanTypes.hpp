#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <array>
#include <optional>
#include <glm/glm.hpp>

#define VKCHECK(result, text) \
    if (result != VK_SUCCESS) \
    {                         \
    Log::error(text);         \
    }

using std::vector;

struct BufferData
{
    VkBuffer buffer;
    VkDeviceMemory memory;
};

struct VulkanData
{
    VkInstance instance;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    VkSurfaceKHR surface;
    VkDebugUtilsMessengerEXT debugMessenger;
};

struct ImageInfo
{
    uint16_t size;
    VkFormat format;
    VkExtent2D extent;
    VkSwapchainKHR swapChain;
    vector<VkImage> images;
    vector<VkImageView> views;
};

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete()
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails
{
    VkSurfaceCapabilitiesKHR capabilities;
    vector<VkSurfaceFormatKHR> formats;
    vector<VkPresentModeKHR> presentModes;
};

struct Queues
{
    VkQueue graphic;
    VkQueue present;
};

struct RenderPassData
{
    VkRenderPass renderPass;
};

struct PipelineData
{
    VkPipeline graphicPipeline;
    VkPipelineLayout pipelineLayout;
};

struct SemaphoreData
{
    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;
};

struct CommandData
{
    VkCommandPool pool;
    vector<VkCommandBuffer> buffers;
};

struct Vertex
{
    glm::vec2 pos;
    glm::vec3 color;

    static VkVertexInputBindingDescription getBindingDescription()
    {
        VkVertexInputBindingDescription bindingDescription{};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Vertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescription;
    }

    static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions()
    {
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