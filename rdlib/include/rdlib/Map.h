#include "rdlib/Agent.h"
#include <string>
#include <list>

namespace rdlib {
    class Map {
    private:
        static std::list<Agent*> s_agents;

        static void clear();
    public:
        static bool load(const std::string& mapFile);
};
} // rdlib
