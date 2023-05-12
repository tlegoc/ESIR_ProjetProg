//
// Created by theo on 10/05/2023.
//

#include "rdlib/Engine.h"

#include <iostream>

namespace rdlib {

    Engine * Engine::s_renderer = nullptr;

    Engine::Engine() {

    }

    Engine *Engine::instanciate() {
        if (s_renderer) throw std::runtime_error("A renderer instance already exists !");

        s_renderer = new Engine();

        return s_renderer;
    }

    void Engine::finalize() {
        delete s_renderer;
    }
} // rdlib