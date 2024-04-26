#include <Graphic/Window.hpp>
#include <Core/Log.hpp>
#include <glad/glad.h>
#include <stdio.h>
#include <Manager/InputManager.hpp>

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    InputManager::previousKeys[key] = InputManager::pressedKeys[key];
    InputManager::pressedKeys[key] = action == GLFW_REPEAT || action == GLFW_PRESS;
}


void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Window::Window(size_t w, size_t h, const char *t)
{
    height = h;
    width = w;
    title = t;
}

Window::~Window()
{
}

int Window::init_window()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        Log::error("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetKeyCallback(window, keyCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log::error("Failed to initialize GLAD");

        return -1;
    }
    return 0;
}

void Window::processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void Window::terminate()
{
    glfwTerminate();
}
