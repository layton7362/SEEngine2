// #include <vulkan/vulkan.h>
// #include <Engine/VulkanRenderEngine.hpp>

// VulkanRenderEngine::VulkanRenderEngine()
// {
        
// }

// VulkanRenderEngine::~VulkanRenderEngine()
// {
        
// }

// void VulkanRenderEngine::addObject(Object3D *obj)
// {
//     if (this->render_id.count(obj) == 0)
//     {
//         this->buildMesh(obj);
//     }
// }

// void VulkanRenderEngine::removeObject(Object3D *obj)
// {
// }

// void VulkanRenderEngine::buildMesh(Object3D *obj)
// {
//     vector<vec3> vertices = obj->mesh->getVertices();
//     vector<uvec3> indices = obj->mesh->getIndices();

//     VkBuffer vertexBuffer;
//     VkDeviceMemory vertexBufferMemory;
//     VkBuffer indexBuffer;
//     VkDeviceMemory indexBufferMemory;

//     // Create vertex buffer
//     createBuffer(vertices.size() * sizeof(vec3), VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, vertexBuffer, vertexBufferMemory);

//     // Copy vertex data to buffer
//     void* vertexData;
//     vkMapMemory(device, vertexBufferMemory, 0, vertices.size() * sizeof(vec3), 0, &vertexData);
//     memcpy(vertexData, vertices.data(), (size_t)vertices.size() * sizeof(vec3));
//     vkUnmapMemory(device, vertexBufferMemory);

//     // Create index buffer
//     createBuffer(indices.size() * sizeof(uvec3), VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, indexBuffer, indexBufferMemory);

//     // Copy index data to buffer
//     void* indexData;
//     vkMapMemory(device, indexBufferMemory, 0, indices.size() * sizeof(uvec3), 0, &indexData);
//     memcpy(indexData, indices.data(), (size_t)indices.size() * sizeof(uvec3));
//     vkUnmapMemory(device, indexBufferMemory);

//     this->render_id[obj] = new RenderData{vertexBuffer, vertexBufferMemory, indexBuffer, indexBufferMemory};
// }

// void VulkanRenderEngine::renderBegin()
// {
//     // TODO: Begin Vulkan rendering
// }

// void VulkanRenderEngine::render()
// {
//     // TODO: Render objects using Vulkan
// }

// void VulkanRenderEngine::renderEnd()
// {
//     // TODO: End Vulkan rendering
// }

// void VulkanRenderEngine::dispose_meshes()
// {
//     for (auto &&id : this->render_id)
//     {
//         RenderData *data = id.second;
//         vkDestroyBuffer(device, data->vertexBuffer, nullptr);
//         vkFreeMemory(device, data->vertexBufferMemory, nullptr);
//         vkDestroyBuffer(device, data->indexBuffer, nullptr);
//         vkFreeMemory(device, data->indexBufferMemory, nullptr);
//         delete data;
//     }
// }

// void VulkanRenderEngine::dispose()
// {
//     // TODO: Dispose Vulkan resources
// }

// // Helper function to create Vulkan buffer
// void VulkanRenderEngine::createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory)
// {
//     VkBufferCreateInfo bufferInfo{};
//     bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
//     bufferInfo.size = size;
//     bufferInfo.usage = usage;
//     bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

//     if (vkCreateBuffer(device, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
//         throw std::runtime_error("Failed to create buffer!");
//     }

//     VkMemoryRequirements memRequirements;
//     vkGetBufferMemoryRequirements(device, buffer, &memRequirements);

//     VkMemoryAllocateInfo allocInfo{};
//     allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
//     allocInfo.allocationSize = memRequirements.size;
//     allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, properties);

//     if (vkAllocateMemory(device, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
//         throw std::runtime_error("Failed to allocate buffer memory!");
//     }

//     vkBindBufferMemory(device, buffer, bufferMemory, 0);
// }

// // Helper function to find suitable memory type
// uint32_t VulkanRenderEngine::findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties)
// {
//     VkPhysicalDeviceMemoryProperties memProperties;
//     vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);

//     for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
//         if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
//             return i;
//         }
//     }

//     throw std::runtime_error("Failed to find suitable memory type!");
// }
// 