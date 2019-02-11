#pragma once


#include <yaml-cpp/yaml.h>
#include "Component.hpp"

typedef Component* (*ComponentBuilder)(YAML::Node);

class ComponentFactory {
public:
    ComponentFactory();

    Component * Create(std::string type, YAML::Node data);

private:
    std::map<std::string, ComponentBuilder> builders;
};
