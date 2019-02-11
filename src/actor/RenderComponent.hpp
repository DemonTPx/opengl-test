#pragma once


#include <yaml-cpp/yaml.h>
#include "Component.hpp"
#include "../Color.hpp"

class RenderComponent : public Component {
public:
    static Component *Build(YAML::Node data);

    const std::string ToString() override;
};

class BallRenderComponent : public RenderComponent {
public:
    explicit BallRenderComponent(Color color);

private:
    Color color;
    const std::string ToString() override;
};
