
#include <array>
#include <algorithm>
#include <Graphic/Camera.hpp>
#include <Engine/OpenGLRenderEngine.hpp>
#include <Utils.hpp>

OpenGLRenderEngine::OpenGLRenderEngine()
{
}

OpenGLRenderEngine::~OpenGLRenderEngine()
{
}

void OpenGLRenderEngine::addObject(Object3D *obj)
{
    if (this->meshIds.count(obj->mesh.get()) == 0)
    {
        this->buildMesh(obj);

        // this->materialIds[obj->material] = MaterialData(-1, obj);
        addMaterial(obj);
    }
}

void OpenGLRenderEngine::removeObject(Object3D *obj)
{
}

void OpenGLRenderEngine::addMaterial(Object3D *obj)
{
    if (materialIds.find(obj->material) == materialIds.end())
    {
        materialIds[obj->material] = new MaterialData{0, vector<Object3D *>()};
    }
    materialIds[obj->material]->object.push_back(obj);
    std::sort(materialIds[obj->material]->object.begin(), materialIds[obj->material]->object.end());
}

void OpenGLRenderEngine::buildMesh(Object3D *obj)
{
    obj->BuildMeshArray();

    vector<vec3> vertices = obj->mesh->getVertices();
    vector<vec3> normals = obj->mesh->getNormals();
    vector<vec4> colors = obj->mesh->getColors();
    vector<vec2> uv1 = obj->mesh->getUV1();
    vector<uvec3> indices = obj->mesh->getIndices();

    const unsigned int offsetNormal = vertices.size() * sizeof(vec3);
    const unsigned int offsetColor = offsetNormal + normals.size() * sizeof(vec3);
    const unsigned int offsetUV = offsetColor + colors.size() * sizeof(vec4);

    const vector<float> &data = obj->packedData;

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
    // glBufferData(GL_COPY_READ_BUFFER, sizeof(float) * data.size(), a, GL_STATIC_READ);

    if (obj->hasIndices())
    {
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uvec3) * indices.size(), indices.data(), GL_STATIC_DRAW);
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void *>(offsetNormal));
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_TRUE, 0, reinterpret_cast<void *>(offsetColor));
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void *>(offsetUV));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);

    this->meshIds[obj->mesh.get()] = new RenderData{VAO, VBO, EBO};
}

void OpenGLRenderEngine::renderBegin(const Color4 &clear)
{
    glClearColor(clear.r, clear.g, clear.b, clear.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void OpenGLRenderEngine::addCameraUniform(Camera *cam, Object3D *obj)
{
    const GLint &progId = obj->material->getProgramId();
    const GLint locView = glGetUniformLocation(progId, "view");
    const GLint locProj = glGetUniformLocation(progId, "projection");
    obj->addUniform(locView, UniformCall(TraitUniform::setMatrix4(locView, glm::inverse(cam->view))));
    obj->addUniform(locProj, UniformCall(TraitUniform::setMatrix4(locProj, cam->projection)));
}

void OpenGLRenderEngine::render()
{
    for (auto &&id : this->materialIds)
    {
        Material *mat = id.first;
        MaterialData *data = id.second;
        mat->useMaterial();
        mat->loadUniforms();
        for (Object3D *obj : data->object)
        {
            obj->loadUniforms();
            RenderData *mdata = meshIds[obj->mesh.get()];
            glBindVertexArray(mdata->VAO);
            if (obj->hasIndices())
            {
                glDrawElements(GL_TRIANGLES, obj->getTrianglesCount(), GL_UNSIGNED_INT, 0);
            }
            else
            {
                glDrawArrays(GL_TRIANGLES, 0, obj->getTrianglesCount());
            }
        }
    }
}

void OpenGLRenderEngine::renderEnd()
{
}

void OpenGLRenderEngine::dispose_meshes()
{
    // for (auto &&id : this->render_id)
    // {
    //     Mesh *mesh = id.first->mesh;
    //     RenderData *data = id.second;
    //     glDeleteVertexArrays(1, &data->VAO);
    //     glDeleteBuffers(1, &data->VBO);
    //     glDeleteBuffers(1, &data->EBO);
    //     delete mesh;
    //     mesh = nullptr;
    // glDeleteProgram(material->getProgramId());
    // }
}

void OpenGLRenderEngine::dispose()
{
    // TODO
}

void OpenGLRenderEngine::viewportUpdate(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
    glViewport(x, y, w, h);
}
