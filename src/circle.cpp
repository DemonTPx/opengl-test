#include <SDL2/SDL_opengl.h>

#include "circle.hpp"

Circle::Circle(float x, float y, float radius, int numSegments) :
        x(x),
        y(y),
        radius(radius),
        numSegments(numSegments)
{};

Circle::Circle(float x, float y, float radius) :
        Circle(x, y, radius, 50)
{};

void Circle::draw()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(0.0, 0.0, 1.0, 1.0);
    glVertex2f(x, y);
    glColor4f(0.0, 0.0, 0.0, 0.5);
    for (int n = 0; n <= numSegments; ++n) {
        float const t = (float) M_PI * 2 * (float) n / (float) numSegments;
        glVertex2f(x + (float) sin(t) * radius, y + (float) cos(t) * radius);
    }
    glEnd();
}
