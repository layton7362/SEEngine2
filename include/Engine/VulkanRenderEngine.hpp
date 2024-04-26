// #pragma once

// #include <Nodes/Object3D.hpp>
// #include <vulkan/vulkan.h>
// #include <vector>
// #include <map>
// #include <glm/glm.hpp>

// class VulkanRenderEngine
// {
// public:
//     VulkanRenderEngine(/* Pass any necessary parameters here */);
//     ~VulkanRenderEngine();

//     void addObject(Object3D *obj);
//     void removeObject(Object3D *obj);
//     void renderBegin(const );
//     void render();
//     void renderEnd();
//     void dispose_meshes();
//     void dispose();

// private:
//     struct RenderData {
//         VkBuffer vertexBuffer;
//         VkDeviceMemory vertexBufferMemory;
//         VkBuffer indexBuffer;
//         VkDeviceMemory indexBufferMemory;
//     };

//     std::map<Object3D*, RenderData*> render_id;

//     VkDevice device;
//     VkPhysicalDevice physicalDevice; // If needed, replace with appropriate physical device handle

//     void buildMesh(Object3D *obj);
//     void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
//     uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
// };
