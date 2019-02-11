#include <yaml-cpp/yaml.h>
#include <iostream>
#include <cstring>
#include "EntityLoader.hpp"
#include "actor/RenderComponent.hpp"
#include "actor/PhysicsComponent.hpp"

Entity EntityLoader::load(const char * filename) {
    auto yaml = YAML::LoadFile(filename);

    assert(yaml.IsSequence());

    auto e = new Entity;

    for (YAML::const_iterator it = yaml.begin(); it != yaml.end(); ++it) {
        YAML::Node node = *it;

        assert(node.IsMap());
        assert(node["type"]);

        auto a = actorFactory.Create(node["type"].Scalar(), node["data"]);

        if (a == nullptr) {
            std::cerr << "Failed creating actor with type " << node["type"].Scalar() << std::endl;
            continue;
        }

        e->AddActor(a);
        std::cout << "New actor of type " << node["type"].Scalar() << std::endl;
    }
    
    return *e;
}
