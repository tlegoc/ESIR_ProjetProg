#include "rdlib/Agent.h"
#include <string>
#include <list>


#ifndef ESIR_PROJETPROG_MAP_H
#define ESIR_PROJETPROG_MAP_H

namespace rdlib {
    class Map {
    private:
        static std::list<Agent *> s_agents;

        static void clear();

    public:
        static bool load(const std::string &mapFile, const std::string& colliderFile);
    };
} // rdlib

#endif