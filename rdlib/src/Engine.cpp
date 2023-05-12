//
// Created by theo on 10/05/2023.
//

#include "rdlib/Engine.h"

#include "rdlib/Agent.h"
#include "rdlib/Time.h"

#include <iostream>
#include <chrono>
#include <thread>

namespace rdlib {

    Engine *Engine::s_engine = nullptr;

    void Engine::quit() {
        s_engine->m_should_continue = false;
    }

    Engine *Engine::instanciate() {
        if (s_engine) throw std::runtime_error("A renderer instance already exists !");

        s_engine = new Engine();

        Time::update();

        return s_engine;
    }

    void Engine::finalize() {
        std::cout << "Cleaning engine" << std::endl;
        Agent::finalize();
        delete s_engine;
    }

    bool Engine::shouldContinue() {
        return s_engine->m_should_continue;
    }

    void Engine::update() {
        Agent::updateAll();
        Time::update();
    }

    Engine::Engine() {
        m_should_continue = true;
    }
} // rdlib