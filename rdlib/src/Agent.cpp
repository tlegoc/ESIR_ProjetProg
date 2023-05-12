//
// Created by theo on 10/05/2023.
//

#include "rdlib/Agent.h"

#include "rdlib/Engine.h"

#include <iostream>

namespace rdlib {
    std::vector<Agent *> Agent::s_objects = {};

    Agent::Agent() {
        m_status = Status::ALIVE;
        s_objects.push_back(this);
    }

    Agent::~Agent() = default;

    void Agent::updateAll() {
        auto it = s_objects.begin();
        while (it != s_objects.end()) {
            if ((*it)->m_status == Status::DEAD) {
                delete (*it);
                it = s_objects.erase(it);
            } else {
                (*it)->update();
                it++;
            }
        }
    }

    void Agent::finalize() {
        std::cout << "Cleaning agents" << std::endl;
        auto it = s_objects.begin();
        while (it != s_objects.end()) {
            delete (*it);
            it = s_objects.erase(it);
        }
    }
}