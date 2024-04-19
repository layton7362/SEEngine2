#include <Graphic/Shader.hpp>
#include <glad/glad.h>

Shader::Shader(const char *path, const ShaderType::Type &type)
{
    this->type = type;
    this->file = File::readFile(path);

    if (!file.success)
    {
        Log::error(String("File not found: ") + path);
    }

    this->genId = glCreateShader(type);
    auto code = file.data.c_str();
    glShaderSource(this->genId, 1, &code, NULL);
    glCompileShader(this->genId);

    int success;
    glGetShaderiv(this->genId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        Log::error("SHADER::COMPILATION_FAILED");
        glGetShaderInfoLog(this->genId, 512, NULL, infoLog);
        Log::error(infoLog);
    }
}

void Shader::dispose()
{
    if (this->file.success)
    {
        glDeleteShader(this->genId);
        this->file.success = false;
    }
}

ShaderVertex::ShaderVertex(const String &path) : Shader(path, ShaderType::VERTEX){
                                                     // Empty
                                                 };

ShaderFragment::ShaderFragment(const String &path) : Shader(path, ShaderType::FRAGMENT){
                                                         // Empty
                                                     };

ShaderGeometry::ShaderGeometry(const String &path) : Shader(path, ShaderType::GEOMETRY){
                                                         // Empty
                                                     };