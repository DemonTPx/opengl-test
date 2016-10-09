#include <SDL2/SDL_opengl.h>

#pragma once

class Color {
public:
    float const red;
    float const green;
    float const blue;
    float const alpha;

    Color(float const red, float const green, float const blue, float const alpha);
    Color(float const red, float const green, float const blue);

    void commit();
};
