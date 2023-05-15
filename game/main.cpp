#include <iostream>

#include <rdlib/Engine.h>
#include <rdlib/Agent.h>
#include <rdlib/Time.h>
#include <rdlib/Sprite.h>

#include <iostream>
#include <thread>


class Test : public rdlib::Sprite {
public:
    float m_lifetime = 0;

    Test(const std::string &filename) : rdlib::Sprite(filename) {
    };

    void update() override {
        m_lifetime += rdlib::Time::getDelta();

        // On fait tourner l'image de 1 degré par seconde
        //m_angle = m_lifetime * 3.14159265358979;
    };
};

int main() {
    // Notre jeu
    rdlib::Engine::instanciate();

    rdlib::Sprite *s = new rdlib::Sprite("Gamejam.png", glm::vec3(0, 0, 0), 0, vec2(.5f, .5f), glm::vec3(1, 1, 1));

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
