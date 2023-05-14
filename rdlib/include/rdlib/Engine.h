//
// Created by theo on 10/05/2023.
//

#ifndef ESIR_PROJETPROG_ENGINE_H
#define ESIR_PROJETPROG_ENGINE_H

#include <GL/gl.h>
#if LINUX
#include <SDL2/SDL.h>
#else
#define SDL_MAIN_HANDLED
#include <SDL.h>
#endif


namespace rdlib {

    class Engine {
    public:
        static void quit();

        static Engine *instanciate();

        static void finalize();

        static bool shouldContinue();

        static void update();

        static void render();

        static void run();

    private:
        Engine();

        Engine(const Engine &other) = delete;

        Engine(const Engine &&other) = delete;

        static Engine *s_engine;
        bool m_should_continue;

        SDL_Window *m_mainwindow;
        SDL_GLContext m_maincontext; /* Our opengl context handle */

    };

} // rdlib

#endif //ESIR_PROJETPROG_ENGINE_H
