#include "RenderComponent.hpp"
#include "../Color.hpp"


Component *RenderComponent::Build(const YAML::Node data) {
    if (data["type"].as<std::string>() == "ball") {
        return new BallRenderComponent(Color::Build(data["color"]));
    }

    return new RenderComponent();
}

const std::string RenderComponent::ToString() {
    return "<RenderComponent>";
}

BallRenderComponent::BallRenderComponent(Color color) : color(color) {
}

const std::string BallRenderComponent::ToString() {
    return "<BallRenderComponent "  + color.ToString() + ">";
}
