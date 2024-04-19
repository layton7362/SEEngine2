
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

    ShaderVertex* vs = new ShaderVertex("shaders/basic.vert");
    ShaderFragment* fs = new ShaderFragment("shaders/basic.frag");

    std::array<Shader*, ShaderListType::Count> shaders;

    shaders[ShaderListType::VERTEX] = vs;
    shaders[ShaderListType::FRAGMENT] = fs;
    shaders[ShaderListType::GEOMETRY] = nullptr;
    shaders[ShaderListType::COMPUTE] = nullptr;

    Material* material = new Material(shaders);

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
        glUseProgram(material->getProgramId());
        renderEngien.render();
   
        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}


