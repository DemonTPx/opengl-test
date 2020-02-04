#include "Texture.h"
#include <iostream>

Texture::Texture(const char* path) : id(0)
{
    SDL_Surface * surface = IMG_Load(path);

    if ( ! surface)
    {
        std::cout << "Error: could not load texture " << path << std::endl;
        throw std::runtime_error("Error: Could not load texture");
    }

    int Mode = GL_RGB;

    if(surface->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    seti(GL_TEXTURE_WRAP_S, GL_REPEAT);
    seti(GL_TEXTURE_WRAP_T, GL_REPEAT);
    seti(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    seti(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);
    glGenerateMipmap(GL_TEXTURE_2D);
    SDL_FreeSurface(surface);
}

Texture::Texture(std::vector<std::string> faces) : id(0)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, id);

    for (unsigned int i = 0; i < faces.size(); i++)
    {
        SDL_Surface * surface = IMG_Load(faces[i].c_str());

        if ( ! surface)
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            throw std::runtime_error("Error: Could not load texture for cubemap");
        }

        int Mode = GL_RGB;

        if(surface->format->BytesPerPixel == 4) {
            Mode = GL_RGBA;
        }


        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);
        SDL_FreeSurface(surface);
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}


