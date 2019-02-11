#pragma once


#include <string>
#include <vector>
#include "actor/Component.hpp"

class Entity {
public:
    void AddActor(Component * actor);
    const std::string ListActors();

private:
    std::vector<Component *> actors;
};


