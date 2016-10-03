#pragma once

#include <math.h>

class Circle {
public:
    float x_;
    float y_;
    float radius_;
    int numSegments_;

    Circle(float x, float y, float radius, int numSegments) : x_(x), y_(y), radius_(radius), numSegments_(numSegments) {};
    Circle(float x, float y, float radius): Circle(x, y, radius, 50) {};

    void draw();
};
