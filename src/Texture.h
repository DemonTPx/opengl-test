#pragma once

#include <GLES3/gl3.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_opengl_glext.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>

class Texture
{
protected:
    GLuint id;

public:
    explicit Texture(const char* path);
    explicit Texture(std::vector<std::string> faces);

    void bind()
    {
        glBindTexture(GL_TEXTURE_2D, id);
    }

    void seti(GLenum pname, GLint param)
    {
        glTexParameteri(GL_TEXTURE_2D, pname, param);
    }
};
