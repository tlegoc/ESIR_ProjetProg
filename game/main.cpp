#include <iostream>

#include <rdlib/Engine.h>
#include <rdlib/Agent.h>
#include <rdlib/Time.h>
#include <rdlib/SpriteAgent.h>
#include <rdlib/ColliderSpriteAgent.h>
#include <rdlib/InputManager.h>
#include <rdlib/Map.h>

#include <iostream>
#include <thread>
#include "entity/character/Hero.h"
#include "entity/character/Monster.h"
#include "entity/items/equipments/weapon/Sword.h"
#include "glm/fwd.hpp"

/*class Test : public rdlib::ColliderSpriteAgent {
public:
    float m_lifetime = 0;

    Test(const std::string &filename) : rdlib::ColliderSpriteAgent(filename) {
    };

    Test(const std::string &filename, const glm::vec3 &position, float angle, const glm::vec2 &size,
         const glm::vec3 &color) : rdlib::ColliderSpriteAgent(filename, position, angle, size, color) {
    };

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

/*class Test2 : public rdlib::ColliderSpriteAgent {
public:
    float m_lifetime = 0;

    Test2(const std::string &filename) : rdlib::ColliderSpriteAgent(filename) {
    };

    Test2(const std::string &filename, const glm::vec3 &position, float angle, const glm::vec2 &size,
         const glm::vec3 &color) : rdlib::ColliderSpriteAgent(filename, position, angle, size, color) {
    };

    void update() override {
        if (!isColliding().empty()) {
            m_color = glm::vec3(1, 0, 0);
        } else {
            m_color = glm::vec3(1, 1, 1);
        }
    };
};*/

class MoveCamera : public rdlib::Agent {
    private:
        float m_speed;
    public:
        MoveCamera(float speed) : m_speed(speed) { }
        void update() override {
            if(rdlib::InputManager::isKeyPressed('q'))
                rdlib::Engine::setCameraPosition(rdlib::Engine::getCameraPosition() + vec2(-1, 0) * m_speed);
            if(rdlib::InputManager::isKeyPressed('d'))
                rdlib::Engine::setCameraPosition(rdlib::Engine::getCameraPosition() + vec2(1, 0) * m_speed);
            if(rdlib::InputManager::isKeyPressed('z'))
                rdlib::Engine::setCameraPosition(rdlib::Engine::getCameraPosition() + vec2(0, 1) * m_speed);
            if(rdlib::InputManager::isKeyPressed('s'))
                rdlib::Engine::setCameraPosition(rdlib::Engine::getCameraPosition() + vec2(0, -1) * m_speed);
        }
};


int main() {
    // Notre jeu
    rdlib::Engine::instanciate();
    rdlib::Engine::setCameraZoom(3);

    new MoveCamera(0.1);
    rdlib::Map::load("assets/map/map.json");

    //rdlib::Agent *s = new Test("Gamejam.png");
    //rdlib::Agent *s2 = new Test("Gamejam.png", glm::vec3(0, 0, 0), 0, glm::vec2(.5, .5), glm::vec3(1, 1, 1));
    //rdlib::Agent *s3 = new Test2("Gamejam.png", glm::vec3(0, 0.6, 0), 0, glm::vec2(.5, .5), glm::vec3(1, 1, 1));

    // Monster *s2 = new Monster("assets/character/monster_red.png", glm::vec3(0, 0, 0), 0,
                              //glm::vec2(1), glm::vec3(1, 1, 1), 10, 1);

    // Hero *s1 = new Hero("assets/props/tower11x3.png", glm::vec3(0, 0, 0), 0,
                        //glm::vec2(1), glm::vec3(1, 1, 1), 20, 50, 2, 1, 2);


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
