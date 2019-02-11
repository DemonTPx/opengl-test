#pragma once


#include <yaml-cpp/yaml.h>
#include "Component.hpp"

class PhysicsComponent : public Component {
public:
    static Component *Build(YAML::Node data);

    const std::string ToString() override;
};


