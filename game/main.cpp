#include <iostream>

#include <rdlib/Engine.h>
#include <rdlib/Agent.h>
#include <rdlib/Time.h>

#include <iostream>
#include <thread>

#include <glm/glm.hpp>

using namespace rdlib;

class Test : public Agent {
public:
    float m_lifetime = 0;

    void update() override {
        m_lifetime += Time::getDelta();

        // Exit program after 5 seconds
        if (m_lifetime >= 5.0f) {
            Engine::quit();
        }
    };
};

int main() {
    // Notre jeu
    Engine::instanciate();

    Test *t = new Test();

    // Rien après cette ligne ne s'éxecute tant que le jeu n'est pas quitté
    while (Engine::shouldContinue()) {
        Engine::update();

        // Pour éviter d'avoir des appels trops rapides, ce qui fout en l'air le
        // Timer, on met un délai de 1ms.
        // On peut faire en sorte que le delai varie de façon à ce que cet
        // Ajout ne se fasse pas si Engine::update() est déjà assez long.
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    // On oublie pas de finaliser le moteur, sinon il se ferme pas
    Engine::finalize();

    return 0;
}
