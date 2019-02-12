#pragma once


#include <string>
#include <vector>
#include "actor/ActorComponent.hpp"
#include "Interfaces.hpp"


class Actor {
public:
    explicit Actor(ActorId id);
    ~Actor();

    void Destroy();
    void Update(int deltaMs);

    void AddComponent(StrongActorComponentPtr component);
    const std::string ListComponents();

    template <class ComponentType>
    std::weak_ptr<ComponentType> GetComponent(ComponentId id) {
        auto findIt = components.find(id);
        if (findIt == components.end()) {
            return std::weak_ptr<ComponentType>();
        }

        StrongActorComponentPtr base(findIt->second);
        std::shared_ptr<ComponentType> sub(std::static_pointer_cast<ComponentType>(base));
        std::weak_ptr<ComponentType> weakSub(sub);

        return sub;
    }

private:
    ActorId id;

    typedef std::map<ComponentId, StrongActorComponentPtr> ActorComponents;
    ActorComponents components;
};

