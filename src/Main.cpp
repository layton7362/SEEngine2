
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

using std::vector;
using std::array;

SceneTree tree;

void* operator new(size_t size) {
    return std::malloc(size); // Standard-Implementierung aufrufen
}

int main()
{
    Window window(800,600,"Game");
    window.init_window();

    tree.init();
    
    while (!glfwWindowShouldClose(window.window))
    {
        window.processInput();

        tree.mainUpdate();
        tree.physikUpdate();
        tree.renderUpdate();

        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


