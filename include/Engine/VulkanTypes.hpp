#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <optional>

#define VKCHECK(result, text) \
    if (result != VK_SUCCESS) \
    {                         \
        \ 
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
