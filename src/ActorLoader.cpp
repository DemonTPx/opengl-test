#include <yaml-cpp/yaml.h>
#include <iostream>
#include <cstring>
#include "ActorLoader.hpp"
#include "actor/RenderComponent.hpp"
#include "actor/PhysicsComponent.hpp"

Actor ActorLoader::load(const char * filename) {
    auto yaml = YAML::LoadFile(filename);

    assert(yaml.IsSequence());

    auto a = new Actor;

    for (YAML::const_iterator it = yaml.begin(); it != yaml.end(); ++it) {
        YAML::Node node = *it;

        assert(node.IsMap());
        assert(node["type"]);

        auto c = componentFactory.Create(node["type"].Scalar(), node["data"]);

        if (c == nullptr) {
            std::cerr << "Failed creating component with type " << node["type"].Scalar() << std::endl;
            continue;
        }

        a->AddComponent(c);
        std::cout << "New component of type " << node["type"].Scalar() << std::endl;
    }
    
    return *a;
}
