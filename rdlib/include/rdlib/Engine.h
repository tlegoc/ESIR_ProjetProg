//
// Created by theo on 10/05/2023.
//

#ifndef ESIR_PROJETPROG_ENGINE_H
#define ESIR_PROJETPROG_ENGINE_H

#include "include_sdl.h"


namespace rdlib {

    class Engine {
    public:
        static void quit();

        static Engine *instanciate();

        static Engine *getInstance();

        static void finalize();

        static bool shouldContinue();

        static void update();

        static void render();

        Engine(const Engine &other) = delete;

        Engine(const Engine &&other) = delete;

    private:
        Engine();

        static Engine *s_engine;
        bool m_should_continue;

        SDL_Window *m_mainwindow;
        SDL_GLContext m_maincontext; /* Our opengl context handle */
        unsigned int m_start_time;

    };

} // rdlib

#endif //ESIR_PROJETPROG_ENGINE_H
