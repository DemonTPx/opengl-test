#include "RenderComponent.hpp"
#include "../Color.hpp"


StrongActorComponentPtr RenderComponent::Build(const YAML::Node data) {
    if (data["type"].as<std::string>() == "ball") {
        return StrongActorComponentPtr(new BallRenderComponent(Color::Build(data["color"])));
    }

    return StrongActorComponentPtr(new RenderComponent());
}

BallRenderComponent::BallRenderComponent(Color color) : color(color) {
}

