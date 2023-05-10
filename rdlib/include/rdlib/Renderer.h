//
// Created by theo on 10/05/2023.
//

#ifndef ESIR_PROJETPROG_RENDERER_H
#define ESIR_PROJETPROG_RENDERER_H

#include <SDL.h>

namespace rdlib {

    class Renderer {
    public:
        static Renderer *instanciate();

        static void finalize();
    private:
        Renderer();
        Renderer(const Renderer & other) = delete;
        Renderer(const Renderer && other) = delete;

        static Renderer * s_renderer;
    };

} // rdlib

#endif //ESIR_PROJETPROG_RENDERER_H
