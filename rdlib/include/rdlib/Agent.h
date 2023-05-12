//
// Created by theo on 10/05/2023.
//

#ifndef ESIR_PROJETPROG_AGENT_H
#define ESIR_PROJETPROG_AGENT_H

#include <vector>

namespace rdlib {
    class Agent {
    public:
        enum Status {
            ALIVE,
            DEAD
        };

        Agent();

        virtual ~Agent();

        Agent(const Agent &other) = delete;

        Agent(const Agent &&other) = delete;

        virtual void update() = 0;

        virtual void kill() { m_status == Status::DEAD; }

        static void updateAll();

        static void killAll();

        static void finalize();

    protected:
        Status m_status;

    private:
        static std::vector<Agent *> s_objects;
    };
}

#endif //ESIR_PROJETPROG_AGENT_H
