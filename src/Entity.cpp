#include <sstream>
#include "Entity.hpp"

void Entity::AddActor(Component *actor) {
    actors.push_back(actor);
}

const std::string Entity::ListActors() {
    std::stringstream stream;

    for (std::vector<Component *>::const_iterator it = actors.begin(); it != actors.end(); ++it) {
        stream << (*it)->ToString() << std::endl;
    }

    return stream.str();
}
