//
// Created by Thibault on 16/05/2023.
//

#include <rdlib/ColliderSpriteAgent.h>
#include "Hero.h"

Hero::Hero(const std::string &image, vec3 position, float angle,
           vec2 size, vec3 color, int pv, int max_pv, int m_damage, int m_shield): rdlib::ColliderSpriteAgent(image, position, angle, size, color), m_pv(20), max_pv(1), m_damage(1), m_shield(1){};

    void Hero::update() {
            m_lifetime += rdlib::Time::getDelta();

            // On fait tourner l'image de 1 degré par seconde
            if (rdlib::InputManager::isKeyPressed('a')) {
                m_angle += rdlib::Time::getDelta() * 1;
            }

            if (rdlib::InputManager::isKeyPressed('e')) {
                m_angle -= rdlib::Time::getDelta() * 1;
            }

            // On change la taille de l'image
            if (rdlib::InputManager::isKeyPressed('r')) {
                m_size.x += rdlib::Time::getDelta() * 1;
                m_size.y += rdlib::Time::getDelta() * 1;
            }

            if (rdlib::InputManager::isKeyPressed('t')) {
                m_size.x -= rdlib::Time::getDelta() * 1;
                m_size.y -= rdlib::Time::getDelta() * 1;
            }

            // On bouge en fonction des touches
            if (rdlib::InputManager::isKeyPressed('z')) {
                m_pos.y += rdlib::Time::getDelta() * 1;
            }

            if (rdlib::InputManager::isKeyPressed('s')) {
                m_pos.y -= rdlib::Time::getDelta() * 1;
            }

            if (rdlib::InputManager::isKeyPressed('q')) {
                m_pos.x -= rdlib::Time::getDelta() * 1;
            }

            if (rdlib::InputManager::isKeyPressed('d')) {
                m_pos.x += rdlib::Time::getDelta() * 1;
            }

            if (rdlib::InputManager::isKeyPressed('w')) {
                rdlib::Engine::setCameraZoom(rdlib::Engine::getCameraZoom() + rdlib::Time::getDelta() * 10);
            }

            if (rdlib::InputManager::isKeyPressed('x')) {
                rdlib::Engine::setCameraZoom(rdlib::Engine::getCameraZoom() - rdlib::Time::getDelta() * 10);
            }

            if (!isColliding().empty()) {
                m_color = glm::vec3(1, 0, 0);
            } else {
                m_color = glm::vec3(1, 1, 1);
            }
    };


