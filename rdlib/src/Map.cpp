#include "rdlib/Map.h"
#include "rdlib/Agent.h"
#include "rdlib/SpriteAgent.h"
#include <algorithm>
#include <fstream>
#include "json.hpp"
#include <iostream>

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
        if (!f.is_open())
            return false;
        
        // Parse
        nlohmann::json data = nlohmann::json::parse(f);
        std::cout << data["background"]["image"] << std::endl;

        

        int x = data["background"]["x"];
        int y = data["background"]["y"];

        std::cout << x << " " << y << std::endl;
        return true;   
    }
} // rdlib