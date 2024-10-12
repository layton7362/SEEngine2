#include <Graphic/Window.hpp>
#include <Core/Log.hpp>
#include <glad/glad.h>
#include <stdio.h>
#include <Manager/InputManager.hpp>
#include "Window.hpp"

ViewportCallback Window::callback_updateViewport = nullptr;

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Input->previousKeys[key] = Input->pressedKeys[key];
    Input->pressedKeys[key] = action == GLFW_REPEAT || action == GLFW_PRESS;
}

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    // Log::info(String(button));
    // Log::info(String(action));
    // Log::info(String(mods));
    // Log::info("===========");
}

void mousePosCallback(GLFWwindow *window, double xpos, double ypos)
{
    Input->mousePos = {xpos, ypos};
    glfwGetWindowPos(window, &Input->mousePosGlobal.x, &Input->mousePosGlobal.y);
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
    glfwSetFramebufferSizeCallback(window, this->framebufferSizeCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, mousePosCallback); 

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

void Window::swapBuffers()
{
    glfwSwapBuffers(this->window);
}

bool Window::isClosing()
{
    return glfwWindowShouldClose(this->window);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::setViewportUpdateCallback(ViewportCallback cb)
{
    Window::callback_updateViewport = cb;
}

void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    Window::callback_updateViewport(0,0, width,height);
}

void Window::dispose()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
