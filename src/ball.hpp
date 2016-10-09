#pragma once

class Ball {
public:
    Ball(float x, float y);
    Ball(float x, float y, float r);

    float x;
    float y;
    float r;

    float velX = 0.0;
    float velY = 0.0;

    void move();
    void draw();
};
