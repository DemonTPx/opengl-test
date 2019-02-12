#pragma once


#include <yaml-cpp/yaml.h>
#include "ActorComponent.hpp"
#include "../Color.hpp"

class RenderComponent : public ActorComponent {
public:
    static StrongActorComponentPtr Build(YAML::Node data);

    std::string GetName() const override { return "RenderComponent"; };
};

class BallRenderComponent : public RenderComponent {
public:
    explicit BallRenderComponent(Color color);

    std::string GetName() const override { return "BallRenderComponent"; };
    std::string AttributesToString() const override { return "color=" + color.ToString(); };

private:
    Color color;
};
