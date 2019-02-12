#include <string>
#include <yaml-cpp/yaml.h>

#pragma once

class Color {
public:
    float const red;
    float const green;
    float const blue;
    float const alpha;

    Color(float red, float green, float blue, float alpha);
    Color(float red, float green, float blue);

    static Color Build(YAML::Node node);

    void commit();
    std::string ToString() const;
};
