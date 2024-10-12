#include <Global.hpp>
#include <Engine/OpenGLRenderEngine.hpp>
#include <Engine/VulkanRenderEngine.hpp>
#include <Engine/RenderEngine.hpp>

RenderEngine *RenderEngine::getRenderEngine()
{
    static RenderEngine *re = nullptr;
    if (re)
    {
        return re;
    }
    if (strcmp(config->renderEngine(), "opengl") == 0)
    {
        re = new OpenGLRenderEngine();
        re->init();
    }
    else if (strcmp(config->renderEngine(), "vulkan") == 0)
    {
        re = new VulkanRenderEngine();
        re->init();
    }
    return re;
}