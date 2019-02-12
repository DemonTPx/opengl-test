#pragma once

#include <memory>
#include <map>
#include <yaml-cpp/yaml.h>

class Actor;
class ActorComponent;

typedef unsigned long ActorId;
typedef unsigned long ComponentId;

const ActorId INVALID_ACTOR_ID = 0;
const ComponentId INVALID_COMPONENT_ID = 0;

typedef std::shared_ptr<Actor> StrongActorPtr;
typedef std::weak_ptr<Actor> WeakActorPtr;
typedef std::shared_ptr<ActorComponent> StrongActorComponentPtr;
typedef std::weak_ptr<ActorComponent> WeakActorComponentPtr;

typedef StrongActorComponentPtr(*ComponentBuilder)(YAML::Node);
typedef std::map<std::string, ComponentBuilder> ComponentBuilderMap;
