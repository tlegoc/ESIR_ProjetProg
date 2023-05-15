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

        static unsigned int getWidth() {
            return s_engine->m_width;
        }

        static unsigned int getHeight() {
            return s_engine->m_height;
        }

        Engine(const Engine &other) = delete;

        Engine(const Engine &&other) = delete;

        Engine &operator=(const Engine &other) = delete;

    private:
        explicit Engine(unsigned int width = 1280, unsigned int height = 720);

        static Engine *s_engine;
        bool m_should_continue;
        unsigned int m_width;
        unsigned int m_height;

        SDL_Window *m_mainwindow;
        SDL_GLContext m_maincontext; /* Our opengl context handle */
    };

} // rdlib

#endif //ESIR_PROJETPROG_ENGINE_H
