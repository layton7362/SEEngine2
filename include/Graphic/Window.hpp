#pragma once

#include <Core/String.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
    size_t width;
    size_t height;
    String title;

public:
    GLFWwindow *window;

    Window(size_t w, size_t h, const char *title);
    ~Window();

    int init_window();
    void processInput();
    void terminate();

};
