
#include <ctime>

#include <iostream>
#include <array>
#include <vector>
#include <Core/System.hpp>
#include <Core/Graph.hpp>
#include <Engine/RenderEngine.hpp>
#include <Graphic/Window.hpp>
#include <Graphic/Shader.hpp>
#include <Graphic/Material.hpp>
#include <Graphic/Mesh.hpp>

#include <Manager/InputManager.hpp>


using std::array;
using std::vector;

SceneTree tree;

void *operator new(size_t size)
{
    return std::malloc(size); // Standard-Implementierung aufrufen
}

double getTime()
{
    // auto now = std::chrono::system_clock::now();
    std::chrono::duration<double> seconds = std::chrono::system_clock::now().time_since_epoch();
    return seconds.count();
}

int main()
{
    Window window(800, 600, "Game");
    window.init_window();

    tree.init();

    const double FRAME_RATE = 60.0f;
    const double FRAME_TIME = 1.0f / FRAME_RATE;

    double time_start = getTime();
    double time_previous = time_start;

    float last_second = getTime();

    while (!glfwWindowShouldClose(window.window))
    {
        double current_time = getTime();
        double elapsed_time = current_time - time_previous;
        window.processInput();
        if (elapsed_time >= FRAME_TIME)
        {
            tree.delta = elapsed_time;
            time_previous = current_time;

            tree.mainUpdate();
            tree.physikUpdate();
            tree.renderUpdate();
            glfwSwapBuffers(window.window);
        }

        glfwPollEvents();
    }

    // dispose()

    glfwTerminate();
    return 0;
}
