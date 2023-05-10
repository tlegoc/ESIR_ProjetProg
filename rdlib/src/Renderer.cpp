//
// Created by theo on 10/05/2023.
//

#include "rdlib/Renderer.h"

#include <iostream>

namespace rdlib {

    Renderer * Renderer::s_renderer = nullptr;

    Renderer::Renderer() {

    }

    Renderer *Renderer::instanciate() {
        if (s_renderer) throw std::runtime_error("A renderer instance already exists !");

        s_renderer = new Renderer();

        return s_renderer;
    }

    void Renderer::finalize() {
        delete s_renderer;
    }
} // rdlib