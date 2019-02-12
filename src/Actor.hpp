#pragma once


#include <string>
#include <vector>
#include "actor/Component.hpp"

class Actor {
public:
    void AddComponent(Component *actor);
    const std::string ListComponents();

private:
    std::vector<Component *> components;
};


