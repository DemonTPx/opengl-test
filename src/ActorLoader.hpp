#pragma once


#include <unordered_map>
#include "Actor.hpp"
#include "actor/ComponentFactory.hpp"

class ActorLoader {
public:
    Actor load(const char * filename);

private:
    ComponentFactory componentFactory;
};


