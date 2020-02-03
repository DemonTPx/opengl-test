#include "ShaderProgram.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath, std::optional<const char*> geometryPath)
{
    id = glCreateProgram();

    unsigned int vertex = createShader(vertexPath, GL_VERTEX_SHADER);
    glAttachShader(id, vertex);
    glDeleteShader(vertex);

    unsigned int fragment = createShader(fragmentPath, GL_FRAGMENT_SHADER);
    glAttachShader(id, fragment);
    glDeleteShader(fragment);

    if (geometryPath.has_value())
    {
        unsigned int geometry = createShader(geometryPath.value(), GL_GEOMETRY_SHADER);
        glAttachShader(id, geometry);
        glDeleteShader(geometry);
    }

    glLinkProgram(id);
    guardLinkErrors();
}

unsigned int ShaderProgram::createShader(const char* path, GLenum shaderType) const
{
    std::stringstream stream;
    std::ifstream shaderFile;

    try
    {
        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        shaderFile.open(path);
        stream << shaderFile.rdbuf();
        shaderFile.close();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "Error: could not read shader: " << path << std::endl;
        throw std::runtime_error("ERROR: could not read shader");
    }

    std::string stringCode = stream.str();
    const char* code = stringCode.c_str();
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);

    guardCompileErrors(shader);

    return shader;
}


void ShaderProgram::guardCompileErrors(const unsigned int shader) const
{
    int success;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if ( ! success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Error: shader compilation failed" << std::endl;
        throw std::runtime_error("Error: shader compilation failed");
    }
}


void ShaderProgram::guardLinkErrors() const
{
    int success;

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if ( ! success)
    {
        char infoLog[512];
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "Error: shader linking failed" << std::endl;
        throw std::runtime_error("Error: shader linking failed");
    }
}
