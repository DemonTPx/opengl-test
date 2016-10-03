#include <SDL2/SDL_opengl.h>

#include "circle.hpp"

void Circle::draw()
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x_, y_);
    for (int n = 0; n <= numSegments_; ++n) {
        float const t = (float) M_PI * 2 * (float) n / (float) numSegments_;
        glVertex2f(x_ + (float) sin(t) * radius_, y_ + (float) cos(t) * radius_);
    }
    glEnd();
}
