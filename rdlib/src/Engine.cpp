//
// Created by theo on 10/05/2023.
//

#include "rdlib/Engine.h"

#include "rdlib/Agent.h"
#include "rdlib/Time.h"

#include <iostream>
#include <chrono>
#include <thread>


void checkSDLError(int line = -1)
{
#ifndef DEBUG
    const char *error = SDL_GetError();
    if (*error != '\0')
    {
        printf("SDL Error: %s\n", error);
        if (line != -1)
            printf(" + line: %i\n", line);
        SDL_ClearError();
    }
#endif
}

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

        /* Delete our opengl context, destroy our window, and shutdown SDL */
        SDL_GL_DeleteContext(s_engine->m_maincontext);
        SDL_DestroyWindow(s_engine->m_mainwindow);
        SDL_Quit();
        delete s_engine;
    }

    bool Engine::shouldContinue() {
        return s_engine->m_should_continue;
    }

    void Engine::update() {
        Agent::updateAll();
        Time::update();
    }

    void Engine::render() {
        /* Clear our buffer with a red background */
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap our back buffer to the front */
        SDL_GL_SwapWindow(s_engine->m_mainwindow);
    }

    Engine::Engine() {
        m_should_continue = true;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            /* Initialize SDL's Video subsystem */
            std::cout << "Unable to initialize SDL" << std::endl; /* Or die on error */
            exit(1);
        }

        /* Request opengl 3.2 context.
         * SDL doesn't have the ability to choose which profile at this time of writing,
         * but it should default to the core profile */
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

        /* Turn on double buffering with a 24bit Z buffer.
         * You may need to change this to 16 or 32 for your system */
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        /* Create our window centered at 512x512 resolution */
        m_mainwindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                        512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if (!m_mainwindow) {
            std::cout << "Couldn't create window" << std::endl;
            exit(1);
        }

        checkSDLError(__LINE__);

        /* Create our opengl context and attach it to our window */
        m_maincontext = SDL_GL_CreateContext(m_mainwindow);
        checkSDLError(__LINE__);


        /* This makes our buffer swap syncronized with the monitor's vertical refresh */
        SDL_GL_SetSwapInterval(1);
    }
} // rdlib
