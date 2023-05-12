#include <iostream>

#include <rdlib/Engine.h>

int main() {
    // Notre jeu
    rdlib::Engine *engine = rdlib::Engine::instanciate();

    // On oublie pas de finaliser le moteur, sinon il se ferme pas
    rdlib::Engine::finalize();

    return 0;
}
