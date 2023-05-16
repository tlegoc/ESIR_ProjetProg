#include <iostream>

#include <rdlib/Engine.h>
#include <rdlib/Agent.h>
#include <rdlib/Time.h>
#include <rdlib/SpriteAgent.h>
#include <rdlib/ColliderSpriteAgent.h>
#include <rdlib/InputManager.h>

#include <iostream>
#include <thread>
#include "entity/items/equipments/weapon/Sword.h"


class Test : public rdlib::ColliderSpriteAgent {
public:
    float m_lifetime = 0;

    Test(const std::string &filename) : rdlib::ColliderSpriteAgent(filename, vec2(0, 0), vec2(1, 1)) {};

    void update() override {
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
};

class Test2 : public rdlib::ColliderSpriteAgent {
public:
    float m_lifetime = 0;

    Test2(const std::string &filename) : rdlib::ColliderSpriteAgent(filename, glm::vec2(0, 0), glm::vec2(1, 1)) {
    };

    void update() override {
        if (!isColliding().empty()) {
            m_color = glm::vec3(1, 0, 0);
        } else {
            m_color = glm::vec3(1, 1, 1);
        }
    };
};

int main() {
    // Notre jeu
    rdlib::Engine::instanciate();
    rdlib::Engine::setCameraZoom(3);

    Test *s = new Test("assets/ground_stone/tile001.png");
    s->setSize(vec2(1, 3));
    rdlib::Agent *s2 = new Test2("assets/ground_stone/tile001.png");

    // rdlib::Agent *s = new Sword( 10,  ("Sword"),("A sword"));


    // Rien après cette ligne ne s'éxecute tant que le jeu n'est pas quitté
    while (rdlib::Engine::shouldContinue()) {
        rdlib::Engine::update();
        rdlib::Engine::render();
    }

    // On oublie pas de finaliser le moteur, sinon il se ferme pas
    rdlib::Engine::finalize();

    return 0;
}
