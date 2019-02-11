#include <cstring>
#include "ComponentFactory.hpp"
#include "RenderComponent.hpp"
#include "PhysicsComponent.hpp"


ComponentFactory::ComponentFactory() {
    builders["render"] = RenderComponent::Build;
    builders["physics"] = PhysicsComponent::Build;
}

Component *ComponentFactory::Create(const std::string type, const YAML::Node data) {
    if ( ! builders[type]) {
        return nullptr;
    }

    return builders[type](data);
}
