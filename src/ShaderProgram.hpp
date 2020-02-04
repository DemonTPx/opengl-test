#pragma once

#include <GLES3/gl3.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_opengl_glext.h>
#include <string>
#include <optional>

class ShaderProgram {

public:
    ShaderProgram(const char* vertexPath, const char* fragmentPath, std::optional<const char*> geometryPath = std::nullopt);

    void use()
    {
        glUseProgram(id);
    }

    // uniform functions
    void set1b(const std::string& name, bool b1)
    {
        glUniform1i(glGetUniformLocation(id, name.c_str()), (GLint) b1);
    }

    void set1i(const std::string& name, GLint i1)
    {
        glUniform1i(glGetUniformLocation(id, name.c_str()), i1);
    }

    void set1f(const std::string& name, GLfloat f1)
    {
        glUniform1f(glGetUniformLocation(id, name.c_str()), f1);
    }

    void set4f(const std::string& name, GLfloat f1, GLfloat f2, GLfloat f3, GLfloat f4)
    {
        glUniform4f(glGetUniformLocation(id, name.c_str()), f1, f2, f3, f4);
    }

    void setMatrix4fv(const std::string& name, GLsizei count, GLboolean transpose, const GLfloat *value)
    {
        glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), count, transpose, value);
    }

protected:
    GLuint id;

    GLuint createShader(const char* path, GLenum shaderType) const;
    void guardCompileErrors(GLuint shader) const;
    void guardLinkErrors() const;
};


