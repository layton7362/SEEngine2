#pragma once
#include <vulkan/vulkan.h>
#include <vector>

using std::vector;

struct Bufferdata
{
    VkBuffer buffer;
    VkDeviceMemory memory;
};

struct VulkanData
{
    VkInstance instance;
    VkDevice device;
    VkPhysicalDevice physicalDevice;
};

struct Images
{
    uint16_t size;
    VkFormat format;
    vector<VkSwapchainKHR> swapchains;
    vector<VkImage> images;
    vector<VkImageView> views;
};

class VulkanDeviceConfig
{

public:
    VulkanDeviceConfig();
    virtual ~VulkanDeviceConfig() noexcept;
};
