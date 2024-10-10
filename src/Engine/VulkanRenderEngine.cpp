#include <vulkan/vulkan.h>
#include <Engine/VulkanDeviceConfig.hpp>
#include <Engine/VulkanRenderEngine.hpp>

VulkanRenderEngine::VulkanRenderEngine()
{
}

VulkanRenderEngine::~VulkanRenderEngine()
{
}

void VulkanRenderEngine::addObject(Object3D *mesh) {}
void VulkanRenderEngine::removeObject(Object3D *mesh) {}

void VulkanRenderEngine::buildMesh(Object3D *mesh) {}
void VulkanRenderEngine::dispose_meshes() {}

void VulkanRenderEngine::renderBegin(const Color4 &clear) {}
void VulkanRenderEngine::addCameraUniform(Camera *, Object3D *) {}

void VulkanRenderEngine::render() {}
void VulkanRenderEngine::renderEnd() {}

void VulkanRenderEngine::viewportUpdate(uint16_t x, uint16_t y, uint16_t w, uint16_t h) {}

void VulkanRenderEngine::dispose()
{
}
