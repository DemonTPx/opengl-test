#pragma once


#include <yaml-cpp/yaml.h>
#include "ActorComponent.hpp"

class PhysicsComponent : public ActorComponent {
public:
    static StrongActorComponentPtr Build(YAML::Node data);

    std::string GetName() const override { return "PhysicsComponent"; };
};


