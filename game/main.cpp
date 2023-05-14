#include <iostream>

#include <rdlib/Engine.h>
#include <rdlib/Agent.h>
#include <rdlib/Time.h>

#include <iostream>
#include <thread>


class Test : public rdlib::Agent {
public:
    float m_lifetime = 0;

    void update() override {
        m_lifetime += rdlib::Time::getDelta();

        // Exit program after 5 seconds
        if (m_lifetime >= 5.0f) {
            rdlib::Engine::quit();
        }
    };
};

int main() {
    // Notre jeu
    rdlib::Engine::instanciate();

    Test *t = new Test();

    // Rien après cette ligne ne s'éxecute tant que le jeu n'est pas quitté
    while (rdlib::Engine::shouldContinue()) {
        rdlib::Engine::update();

        // Pour éviter d'avoir des appels trops rapides, ce qui fout en l'air le
        // Timer, on met un délai de 1ms.
        // On peut faire en sorte que le delai varie de façon à ce que cet
        // Ajout ne se fasse pas si Engine::update() est déjà assez long.
        rdlib::Engine::render();
    }

    // On oublie pas de finaliser le moteur, sinon il se ferme pas
    rdlib::Engine::finalize();

    return 0;
}
