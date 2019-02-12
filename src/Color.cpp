#include <SDL2/SDL_opengl.h>
#include "Color.hpp"


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

std::string Color::ToString() const {
    return "<Color red=" + std::to_string(red) +
                 " green=" + std::to_string(green) +
                 " blue=" + std::to_string(blue) +
                 " alpha=" + std::to_string(alpha) +
                 ">";
}

Color Color::Build(YAML::Node node) {
    if (node.IsMap() && node["r"] && node["g"] && node["b"]) {
        return {
            (float) node["r"].as<uint>(0xff),
            (float) node["g"].as<uint>(0xff),
            (float) node["b"].as<uint>(0xff),
            (float) node["a"].as<uint>(0xff)
        };
    }

    auto rgba = node.as<uint>(0);

    return {
        (float) ((rgba >> 24) & 0xff),
        (float) ((rgba >> 16) & 0xff),
        (float) ((rgba >> 8) & 0xff),
        (float) (rgba & 0xff)
    };
}
