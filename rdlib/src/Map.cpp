#include "rdlib/Map.h"
#include "glm/fwd.hpp"
#include "rdlib/Agent.h"
#include "rdlib/SpriteAgent.h"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include "json.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace rdlib {
    std::list<Agent*> Map::s_agents;

    void Map::clear() {
        while (!s_agents.empty()) {
            s_agents.front()->kill();
            s_agents.pop_front();
        }
    }

    bool Map::load(const std::string& mapFile) {
        clear();

        // Load file
        std::ifstream f(mapFile);
        
        // Check if file is opened
        if (!f.is_open()) {
            std::cout << "Failed to open file (" << mapFile << ")" << std::endl;
            return false;
        }
        
        // Parse
        nlohmann::json data = nlohmann::json::parse(f);

        // Map
        std::vector<std::vector<int>> map = data["map"];
        for(size_t y = 0; y < map.size(); y++) {
            for(size_t x = 0; x < map[y].size(); x++) {
                if(map[y][x] == 0) continue;
                if(x == 0 && map[y].size() -y == 0) std::cout << "0,0" << std::endl;
                auto sprite = new SpriteAgent(data["tiles"][std::to_string(map[y][x])]["src"], vec3(x, map.size() - y, 0));
                s_agents.push_back(sprite);
            }
        }

        
        return true;   
    }
} // rdlib