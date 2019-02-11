#pragma once

#include <math.h>
#include "Color.hpp"

class Circle {
public:
    float const x;
    float const y;
    float const radius;
    int const numSegments;

    Color colorInner;
    Color colorOuter;

    Circle(float x, float y, float radius, int numSegments, const Color &colorInner, const Color &colorOuter);

    Circle(float x, float y, float radius, int numSegments);

    Circle(float x, float y, float radius, const Color &colorInner, const Color &colorOuter);

    Circle(float x, float y, float radius);

    void draw();
};
