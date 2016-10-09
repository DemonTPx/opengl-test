#include <SDL2/SDL_opengl.h>

#include "circle.hpp"

Circle::Circle(float const x, float const y, float const radius, int const numSegments, const Color &colorInner, const Color &colorOuter) :
        x(x),
        y(y),
        radius(radius),
        numSegments(numSegments),
        colorInner(colorInner),
        colorOuter(colorOuter)
{};

Circle::Circle(float const x, float const y, float const radius, int const numSegments) :
        Circle(x, y, radius, numSegments, Color(1.0, 1.0, 1.0), Color(1.0, 1.0, 1.0))
{};

Circle::Circle(float const x, float const y, float const radius, const Color &colorInner, const Color &colorOuter) :
        Circle(x, y, radius, 50, colorInner, colorOuter)
{};

Circle::Circle(float const x, float const y, float const radius) :
        Circle(x, y, radius, 50)
{};

void Circle::draw()
{
    glBegin(GL_TRIANGLE_FAN);
    colorInner.commit();
    glVertex2f(x, y);
    colorOuter.commit();
    for (int n = 0; n <= numSegments; ++n) {
        float const t = (float) M_PI * 2 * (float) n / (float) numSegments;
        glVertex2f(x + (float) sin(t) * radius, y + (float) cos(t) * radius);
    }
    glEnd();
}
