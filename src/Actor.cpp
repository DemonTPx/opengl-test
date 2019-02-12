#include <sstream>
#include "Actor.hpp"

void Actor::AddComponent(Component *actor) {
    components.push_back(actor);
}

const std::string Actor::ListComponents() {
    std::stringstream stream;

    for (std::vector<Component *>::const_iterator it = components.begin(); it != components.end(); ++it) {
        stream << (*it)->ToString() << std::endl;
    }

    return stream.str();
}
