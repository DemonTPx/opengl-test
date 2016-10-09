#pragma once

#include <math.h>
#include "color.hpp"

class Circle {
public:
    float const x;
    float const y;
    float const radius;
    int const numSegments;

    Color colorInner;
    Color colorOuter;

    Circle(float const x, float const y, float const radius, int const numSegments, const Color &colorInner, const Color &colorOuter);

    Circle(float const x, float const y, float const radius, int const numSegments);

    Circle(float const x, float const y, float const radius, const Color &colorInner, const Color &colorOuter);

    Circle(float const x, float const y, float const radius);

    void draw();
};
