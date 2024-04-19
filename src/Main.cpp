
#include <Core/System.hpp>
#include <Graphic/Window.hpp>
#include <Graphic/Shader.hpp>
#include <Graphic/Material.hpp>
#include <Graphic/Mesh.hpp>
#include <iostream>
#include <array>
#include <vector>
#include <Engine/RenderEngine.hpp>

using std::vector;
using std::array;

int main()
{
    Window window(800,600,"Game");
    window.init_window();

    DefaultMaterial* material = new DefaultMaterial();

    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    vector<float> vertices_vec(std::begin(vertices), std::end(vertices));
    vector<unsigned int> indices_vec(std::begin(indices), std::end(indices));
    MeshDataContainer data;
    data[MeshData::VERTICES] = vertices_vec;
    data[MeshData::INDICES] = indices_vec;
    Mesh mesh(data);

    OpenGLRenderEngine renderEngien;
    renderEngien.addMesh(&mesh);

    while (!glfwWindowShouldClose(window.window))
    {
        window.processInput();

        renderEngien.renderBegin();

        material->useMaterial();
        
        renderEngien.render();
   
        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


