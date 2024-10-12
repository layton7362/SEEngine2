#pragma once

#include <Core/String.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Interface.hpp>

using ViewportCallback = void (*)(uint16_t, uint16_t, uint16_t, uint16_t);

class Window : public IDisposable
{
    size_t width;
    size_t height;
    String title;

    static ViewportCallback callback_updateViewport;

public:
    GLFWwindow *window;

    Window(size_t w, size_t h, const char *title);
    ~Window();

    int init_window();
    void processInput();
    void terminate();
    void swapBuffers();
    bool isClosing();
    void pollEvents();
    
    void setViewportUpdateCallback(ViewportCallback callback);
    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
    
    void dispose() override;
};
