#pragma once

#include <math.h>

class Circle {
public:
    float x;
    float y;
    float radius;
    int numSegments;

    Circle(float x, float y, float radius, int numSegments);
    Circle(float x, float y, float radius);

    void draw();
};
