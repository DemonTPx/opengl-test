#include "PhysicsComponent.hpp"

StrongActorComponentPtr PhysicsComponent::Build(const YAML::Node data) {
    return StrongActorComponentPtr(new PhysicsComponent());
}
