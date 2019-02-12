#include <sstream>
#include "actor/ActorComponent.hpp"
#include "Actor.hpp"

Actor::Actor(ActorId id): id(id) {

}

void Actor::AddComponent(StrongActorComponentPtr component) {
    std::pair<ActorComponents::iterator, bool> success = components.insert(std::make_pair(component->GetId(), component));
    assert(success.second);
}

const std::string Actor::ListComponents() {
    std::stringstream stream;

    stream << "Actor id " << id << std::endl;

    for (auto &it : components) {
        stream << it.second->ToString() << std::endl;
    }

    return stream.str();
}

Actor::~Actor() {
    assert(components.empty());
}

void Actor::Destroy() {
    components.clear();
}

void Actor::Update(int deltaMs) {
    for (auto &it : components) {
        it.second->Update(deltaMs);
    }
}
