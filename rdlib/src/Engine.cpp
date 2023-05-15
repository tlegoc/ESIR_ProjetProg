//
// Created by theo on 10/05/2023.
//

#include "rdlib/Engine.h"

#include "rdlib/Agent.h"
#include "rdlib/Time.h"
#include "rdlib/Sprite.h"

#include <iostream>
#include <GL/glew.h>


void checkSDLError(int line = -1) {
#ifndef DEBUG
    const char *error = SDL_GetError();
    if (*error != '\0') {
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
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    Engine::quit();
                    break;
                default:
                    break;
            }
        }
        Agent::updateAll();
        Time::update();
    }

    void Engine::render() {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        Sprite::renderAll();

        SDL_GL_SwapWindow(s_engine->m_mainwindow);
    }

    Engine::Engine() {
        m_should_continue = true;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "Unable to initialize SDL" << std::endl;
            exit(1);
        }

        // OpenGL context
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

        m_mainwindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                        1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

        if (!m_mainwindow) {
            std::cout << "Couldn't create window" << std::endl;
            exit(1);
        }

        checkSDLError(__LINE__);

        m_maincontext = SDL_GL_CreateContext(m_mainwindow);
        checkSDLError(__LINE__);


        auto init_res = glewInit();
        if (init_res != GLEW_OK) {
            std::cout << glewGetErrorString(glewInit()) << std::endl;
        }

        SDL_GL_SetSwapInterval(1);
    }
} // rdlib
