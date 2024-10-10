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
    VkPhysicalDevice physicalDevice;
    VkDevice device;
};

struct ImageInfo
{
    uint16_t size;
    VkFormat format;
    vector<VkSwapchainKHR> swapchains;
    vector<VkImage> images;
    vector<VkImageView> views;
};

class VulkanDeviceConfig
{

    VulkanData vulkanData;
    ImageInfo imageInfo;

public:
    VulkanDeviceConfig();
    virtual ~VulkanDeviceConfig() noexcept;

    void createVulkanInstance();
    void createPhysicalDevice();
    void createDevice();

    void createSwapChains();
    void createImages();
    void createImageViews();

    void createBuffer();
};
