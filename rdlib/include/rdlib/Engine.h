//
// Created by theo on 10/05/2023.
//

#ifndef ESIR_PROJETPROG_ENGINE_H
#define ESIR_PROJETPROG_ENGINE_H

#include <SDL.h>
#include <GL/gl.h>

namespace rdlib {

    class Engine {
    public:
        static Engine *instanciate();

        static void finalize();
    private:
        Engine();
        Engine(const Engine & other) = delete;
        Engine(const Engine && other) = delete;

        static Engine * s_renderer;
    };

} // rdlib

#endif //ESIR_PROJETPROG_ENGINE_H
