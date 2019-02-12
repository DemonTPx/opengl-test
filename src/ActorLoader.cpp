#include <yaml-cpp/yaml.h>
#include <iostream>
#include <cstring>
#include "ActorLoader.hpp"
#include "actor/RenderComponent.hpp"
#include "actor/PhysicsComponent.hpp"


ActorLoader::ActorLoader() {
    builders["render"] = RenderComponent::Build;
    builders["physics"] = PhysicsComponent::Build;
}


StrongActorPtr ActorLoader::Load(const char *filename) {
    auto yaml = YAML::LoadFile(filename);

    assert(yaml.IsSequence());

    StrongActorPtr actor(new Actor(GetNextActorId()));

    for (YAML::const_iterator it = yaml.begin(); it != yaml.end(); ++it) {
        YAML::Node node = *it;

        assert(node.IsMap());
        assert(node["type"]);

        StrongActorComponentPtr component(CreateComponent(node["type"].Scalar(), node["data"]));

        if ( ! component) {
            std::cerr << "Failed creating component with type " << node["type"].Scalar() << std::endl;
            continue;
        }

        actor->AddComponent(component);
        component->SetOwner(actor);

        std::cout << "New component of type " << node["type"].Scalar() << std::endl;
    }
    
    return actor;
}

StrongActorComponentPtr ActorLoader::CreateComponent(const std::string type, const YAML::Node data) {
    if ( ! builders[type]) {
        return StrongActorComponentPtr();
    }

    return builders[type](data);
}

ActorId ActorLoader::GetNextActorId() {
    ++lastActorId;

    return lastActorId;
}
