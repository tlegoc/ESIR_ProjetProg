#include <iostream>

#include <rdlib/Renderer.h>

int main() {
    // Notre jeu
    rdlib::Renderer *renderer = rdlib::Renderer::instanciate();

    // On oublie pas de finaliser le moteur, sinon il se ferme pas
    rdlib::Renderer::finalize();

    return 0;
}
