#pragma once
#include <Core/Log.hpp>
#include <Interface.hpp>
#include <Engine/VulkanTypes.hpp>

class VulkanDeviceConfig : public IDisposable
{
    bool enableValidationLayers = true;

    const vector<const char *> validationLayers = {
        "VK_LAYER_KHRONOS_validation"};

    const vector<const char *> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME,
        VK_KHR_SURFACE_EXTENSION_NAME
        // VK_KHR_WIN32_SURFACE_EXTENSION_NAME

        };

public:
    const uint8_t MAX_FRAMES = 2;
    VulkanData vulkanData;
    ImageInfo imageInfo;
    VkAllocationCallbacks *alloc = nullptr;
    VkDebugUtilsMessengerEXT debugMessenger;
    Queues queues;

public:
    VulkanDeviceConfig();
    virtual ~VulkanDeviceConfig() noexcept;

    void init();
    void createVulkanInstance();
    void setupDebugMessenger();
    void createSurface();
    void createPhysicalDevice();
    void createDevice();
    void createSwapChains();
    void createImageViews();

    void dispose() override;

    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    BufferData createBuffer(const VkDeviceSize size, const VkBufferCreateFlags flags, const VkBufferUsageFlags usage, const VkMemoryPropertyFlags memoryFlag);
    QueueFamilyIndices findQueueFamilies(const VkPhysicalDevice& device);
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    vector<const char *> getRequiredExtensions();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDebugUtilsMessengerEXT *pDebugMessenger);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    bool checkValidationLayerSupport();

};
