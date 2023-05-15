#include <iostream>

#include <rdlib/Engine.h>
#include <rdlib/Agent.h>
#include <rdlib/Time.h>
#include <rdlib/Sprite.h>
#include <rdlib/InputManager.h>

#include <iostream>
#include <thread>


class Test : public rdlib::Sprite {
public:
    float m_lifetime = 0;

    Test(const std::string &filename) : rdlib::Sprite(filename) {
    };

    Test(const std::string &filename, const glm::vec3 &position, float angle, const glm::vec2 &size,
         const glm::vec3 &color) : rdlib::Sprite(filename, position, angle, size, color) {
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
    };
};

int main() {
    // Notre jeu
    rdlib::Engine::instanciate();

    rdlib::Sprite *s = new Test("Gamejam.png");

    // Rien après cette ligne ne s'éxecute tant que le jeu n'est pas quitté
    while (rdlib::Engine::shouldContinue()) {
        rdlib::Engine::update();
        rdlib::Engine::render();
    }

    // On oublie pas de finaliser le moteur, sinon il se ferme pas
    rdlib::Engine::finalize();

    return 0;
}
