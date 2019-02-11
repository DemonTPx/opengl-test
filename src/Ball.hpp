#pragma once

class Ball {
public:
    Ball(float x, float y);
    Ball(float x, float y, float r);

    float x;
    float y;
    float r;

    float speed = 0.0;
    float direction = 0.0;

    void move();
    void draw();
};
