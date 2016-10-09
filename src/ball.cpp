#include "ball.hpp"
#include "circle.hpp"


Ball::Ball(float x, float y, float r):
        x(x),
        y(y),
        r(r) {}

Ball::Ball(float x, float y):
        Ball(x, y, 10.0) {}

void Ball::move() {
    x += speed * cos(direction);
    y += speed * sin(direction);
}

void Ball::draw() {
    Circle circle(x, y, r, 20, Color(1.0, 0.0, 0.0), Color(1.0, 0.0, 0.0));
    circle.draw();
};
