#pragma once


#include <unordered_map>
#include "Actor.hpp"


class ActorLoader {
public:
    ActorLoader();

    StrongActorPtr Load(const char *filename);

private:
    ActorId lastActorId = 0;
    ComponentBuilderMap builders;

    ActorId GetNextActorId();
    StrongActorComponentPtr CreateComponent(std::string type, YAML::Node data);
};


