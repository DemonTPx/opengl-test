#pragma once


#include <unordered_map>
#include "Entity.hpp"
#include "actor/ComponentFactory.hpp"

class EntityLoader {
public:
    Entity load(const char * filename);

private:
    ComponentFactory actorFactory;
};


