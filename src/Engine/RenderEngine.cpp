#include <Engine/RenderEngine.hpp>

void OpenGLRenderEngine::addObject(Object3D *obj)
{
    if (this->render_id.count(obj) == 0)
    {
        this->buildMesh(obj);
    }
}

void OpenGLRenderEngine::removeObject(Object3D *obj)
{
}

void OpenGLRenderEngine::buildMesh(Object3D *obj)
{
    vector<float> vertices = obj->mesh->getVertices();
    vector<unsigned int> indices = obj->mesh->getIndices();

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    this->render_id[obj] = new RenderData{VAO, VBO, EBO};
}

void OpenGLRenderEngine::renderBegin()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
void OpenGLRenderEngine::render()
{
    for (auto &&id : this->render_id)
    {
        id.first->loadUniforms();
        RenderData *data = id.second;
        glBindVertexArray(data->VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    // glDrawArrays(GL_TRIANGLES, 0, 6);
    // glBindVertexArray(0); // no need to unbind it every time
}

void OpenGLRenderEngine::renderEnd()
{
}

void OpenGLRenderEngine::dispose_meshes()
{
    for (auto &&id : this->render_id)
    {
        Mesh *mesh = id.first->mesh;
        RenderData *data = id.second;
        glDeleteVertexArrays(1, &data->VAO);
        glDeleteBuffers(1, &data->VBO);
        glDeleteBuffers(1, &data->EBO);
        delete mesh;
        mesh = nullptr;
        // glDeleteProgram(material->getProgramId());
    }
}

void OpenGLRenderEngine::dispose()
{

    // TODO
}