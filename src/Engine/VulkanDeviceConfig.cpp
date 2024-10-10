#include <Global.hpp>
#include <vulkan/vulkan.h>
#include <Engine/VulkanDeviceConfig.hpp>

VulkanDeviceConfig::VulkanDeviceConfig()
{
}

VulkanDeviceConfig::~VulkanDeviceConfig()
{
}

void VulkanDeviceConfig::createVulkanInstance()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = nullptr;
    appInfo.pApplicationName = config->gameTitle();
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pNext = nullptr;
    createInfo.flags;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledLayerCount = 1;
    createInfo.ppEnabledLayerNames;
    createInfo.enabledExtensionCount;
    createInfo.ppEnabledExtensionNames;

    // vkCreateInstance(&createInfo, nullptr, &vulkanData.instance);
}

void VulkanDeviceConfig::createPhysicalDevice()
{

}

void VulkanDeviceConfig::createDevice()
{
}
