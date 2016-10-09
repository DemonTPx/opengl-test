#include "color.hpp"


Color::Color(float const red, float const green, float const blue, float const alpha) :
        red(red),
        green(green),
        blue(blue),
        alpha(alpha)
{};

Color::Color(float const red, float const green, float const blue) :
        Color(red, green, blue, 1.0)
{};

void Color::commit()
{
    glColor4f(red, green, blue, alpha);
}
