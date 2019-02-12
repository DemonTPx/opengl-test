#pragma once


#include <string>
#include "../Interfaces.hpp"

class ActorComponent {
public:
    virtual void Update(int deltaMs) {};

    virtual ComponentId GetId() const { return GetIdFromName(GetName()); };
    virtual std::string GetName() const = 0;
    virtual std::string ToString() const { return "<" + GetName() + " " + AttributesToString() + ">"; };
    virtual std::string AttributesToString() const { return "empty"; };
    void SetOwner(StrongActorPtr owner) { this->owner = owner; }

    static ComponentId GetIdFromName(std::string name) {
        std::hash<std::string> fn;

        return reinterpret_cast<ComponentId>(fn(name));
    }
private:
    StrongActorPtr owner;
};


