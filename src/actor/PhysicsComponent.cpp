#include "PhysicsComponent.hpp"

Component *PhysicsComponent::Build(const YAML::Node data) {
    return new PhysicsComponent();
}

const std::string PhysicsComponent::ToString() {
    return "<PhysicsComponent>";
}
