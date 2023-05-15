//
// Created by theo on 10/05/2023.
//

#include "rdlib/Engine.h"

#include "rdlib/Agent.h"
#include "rdlib/Time.h"
#include "rdlib/Sprite.h"
#include "rdlib/InputManager.h"

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
        InputManager::instanciate();

        return s_engine;
    }

    void Engine::finalize() {
        std::cout << "Cleaning engine" << std::endl;
        Agent::finalize();
        InputManager::finalize();

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
                case SDL_KEYDOWN:
                    if (e.key.keysym.sym == SDLK_ESCAPE) Engine::quit();
                    InputManager::addKey(e.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    InputManager::removeKey(e.key.keysym.sym);
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

    Engine::Engine(unsigned int width, unsigned int height) {
        m_should_continue = true;
        m_width = width;
        m_height = height;
        m_camera_zoom = 1.0f;
        m_camera_position = glm::vec2(0.0f, 0.0f);

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

    glm::mat4 Engine::getCameraMatrix() {
        // Calculate orthographic projection based on camera zoom and position
        unsigned int width = Engine::getWidth();
        unsigned int height = Engine::getHeight();
        float aspect = (float) width / (float) height;

        glm::mat4 camera = glm::ortho(-aspect * s_engine->m_camera_zoom + s_engine->m_camera_position.x,
                                      aspect * s_engine->m_camera_zoom + s_engine->m_camera_position.x,
                                      -s_engine->m_camera_zoom + s_engine->m_camera_position.y,
                                      s_engine->m_camera_zoom + s_engine->m_camera_position.y,
                                      -1.0f, 1.0f);

        return camera;
    }
} // rdlib
