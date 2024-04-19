#include <Graphic/Material.hpp>

Material::Material()
{
    // Empty
}

Material::Material(std::array<Shader *, ShaderListType::Count> shaders) : Ressource()
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

void Material::addUniform(GLint location, std::function<void()> callable)
{
    uniforms[location] = callable;
}

void Material::updateUniform(GLint location, std::function<void()> callable)
{
    uniforms[location] = callable;
}

void Material::loadUniforms()
{
   for (const auto& pair : uniforms) {
        UniformCallable call = pair.second;
        call();
    }

}

void Material::useMaterial()
{
    glUseProgram(getProgramId());
    loadUniforms();
}

DefaultMaterial::DefaultMaterial() : Material()
{
    ShaderVertex *vs = new ShaderVertex("res/shaders/basic.vert");
    ShaderFragment *fs = new ShaderFragment("res/shaders/basic.frag");

    std::array<Shader *, ShaderListType::Count> shaders;

    shaders[ShaderListType::VERTEX] = vs;
    shaders[ShaderListType::FRAGMENT] = fs;
    shaders[ShaderListType::GEOMETRY] = nullptr;
    shaders[ShaderListType::COMPUTE] = nullptr;

    build(shaders);

    GLint location = glGetUniformLocation(getProgramId(), "shift_x");
    GLint location2 = glGetUniformLocation(getProgramId(), "shift_y");

    addUniform(location, UniformCall(Uniform::setFloat(location, 1)));
    addUniform(location2, UniformCall(Uniform::setFloat(location2, 0)));
}

DefaultMaterial::DefaultMaterial(array<Shader *, ShaderListType::Count> shaders) : Material(shaders)
{
}

DefaultMaterial::~DefaultMaterial() noexcept
{
}