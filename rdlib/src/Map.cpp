#include "rdlib/Map.h"
#include "glm/fwd.hpp"
#include "rdlib/Agent.h"
#include "rdlib/ColliderSpriteAgent.h"
#include "rdlib/SpriteAgent.h"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include "json.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace rdlib {
    std::list<Agent *> Map::s_agents;

    void Map::clear() {
        while (!s_agents.empty()) {
            s_agents.front()->kill();
            s_agents.pop_front();
        }
    }

    bool Map::load(const std::string &mapFile, const std::string& colliderFile) {
        clear();

        // Load file
        std::ifstream f(mapFile);
        std::ifstream f1(colliderFile);

        // Check if file is opened
        if (!f.is_open()) {
            std::cout << "Failed to open file (" << mapFile << ")" << std::endl;
            return false;
        }
        if (!f1.is_open()) {
            std::cout << "Failed to open file (" << colliderFile << ")" << std::endl;
            return false;
        }

        // Parse
        nlohmann::json data = nlohmann::json::parse(f);
        nlohmann::json dataColl = nlohmann::json::parse(f1);

        // Map
        std::vector<std::vector<int>> map = data["map"];
        for (size_t y = 0; y < map.size(); y++) {
            for (size_t x = 0; x < map[y].size(); x++) {
                if (map[y][x] == 0) continue;
                if (x == 0 && map[y].size() - y == 0) std::cout << "0,0" << std::endl;
                auto sprite = new SpriteAgent(data["tiles"][std::to_string(map[y][x])]["src"],
                                              vec3(x, map.size() - y - 1, -1));
                s_agents.push_back(sprite);
            }
        }

        //Decoration
        for(auto dec: data["decorations"]) {
            vec3 position = vec3(dec["x"], dec["y"], 0);
            vec2 size = vec2(dec["w"], dec["h"]);
            auto sprite = new SpriteAgent(dec["src"], position, 0, size);
            s_agents.push_back(sprite);
        }

        // Colliders
        for (auto wall: data["walls"]) {
            int id = wall["id"];
            auto colldata = dataColl[std::to_string(id)];
            vec3 position = vec3(wall["x"], wall["y"], 0);
            
            auto sprite = new SpriteAgent(colldata["src"], position);

            for(auto coll: colldata["coll"]) {
                vec2 collpos = vec2(coll["x"], coll["y"]);
                vec2 collsize = vec2(coll["w"], coll["h"]);
                auto c = new ColliderSpriteAgent(colldata["src"], collpos, collsize, position);
                s_agents.push_back(c);
            }
            s_agents.push_back(sprite);
        }

        return true;
    }
} // rdlib