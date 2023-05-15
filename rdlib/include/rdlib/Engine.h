//
// Created by theo on 10/05/2023.
//

#ifndef ESIR_PROJETPROG_ENGINE_H
#define ESIR_PROJETPROG_ENGINE_H

#include "include_sdl.h"

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace rdlib {

    class Engine {
    public:
        static void quit();

        static Engine *instanciate();

        static Engine *getInstance() {
            if (!s_engine) throw std::runtime_error("No renderer instance exists !");

            return s_engine;
        }

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

        static float getCameraZoom() {
            return s_engine->m_camera_zoom;
        }

        static void setCameraZoom(float zoom) {
            s_engine->m_camera_zoom = glm::max(zoom, 0.1f);
        }

        static glm::mat4 getCameraMatrix();

        static glm::vec2 getCameraPosition() {
            return s_engine->m_camera_position;
        }

        static void setCameraPosition(glm::vec2 position) {
            s_engine->m_camera_position = position;
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
        float m_camera_zoom;
        glm::vec2 m_camera_position;

        SDL_Window *m_mainwindow;
        SDL_GLContext m_maincontext; /* Our opengl context handle */
    };

} // rdlib

#endif //ESIR_PROJETPROG_ENGINE_H
