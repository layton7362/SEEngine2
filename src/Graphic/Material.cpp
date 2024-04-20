#include <Graphic/Material.hpp>

Material::Material()
{
    // Empty
}

Material::Material(std::array<Shader *, ShaderListType::Count> shaders) : RessourceType()
{
    this->build(shaders);
}

Material::~Material()
{
}

void Material::build(array<Shader *, ShaderListType::Count> &shaders)
{
    ShaderVertex vs = *static_cast<ShaderVertex *>(shaders.at(ShaderListType::VERTEX));
    ShaderFragment fs = *static_cast<ShaderFragment *>(shaders.at(ShaderListType::FRAGMENT));
    if (!vs.file.success || !fs.file.success)
    {
        Log::error("Error in Material. No Vertex or Fragment Shader.");
    }
    this->programId = glCreateProgram();
    glAttachShader(this->programId, vs.genId);
    glAttachShader(this->programId, fs.genId);
    glLinkProgram(this->programId);

    int success = -1;
    glGetProgramiv(this->programId, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(this->programId, 512, NULL, infoLog);
        Log::error(String("ERROR::SHADER::PROGRAM::LINKING_FAILED"));
        Log::error(infoLog);
    }

    for (size_t i = 0; i < ShaderListType::Count; i++)
    {
        Shader *shader = shaders[i];
        if (shader != nullptr)
        {
            shader->dispose();
            delete shader;
            shader = nullptr;
        }
    }
}

size_t Material::getProgramId()
{
    return this->programId;
}

void Material::useMaterial()
{
    glUseProgram(getProgramId());
    loadUniforms();
}
