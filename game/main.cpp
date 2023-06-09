#include <iostream>

#include <rdlib/Engine.h>

#include "CreateGame.h"

#include <iostream>
#include <thread>
#include "entity/character/Hero.h"
#include "entity/character/Monster.h"
#include "entity/items/equipments/weapon/Sword.h"
#include "entity/character/Boss.h"
int main() {
    // Notre jeu
    rdlib::Engine::instanciate();
    rdlib::Engine::setCameraZoom(3);
  
    createGame();

    // Rien après cette ligne ne s'éxecute tant que le jeu n'est pas quitté
    while (rdlib::Engine::shouldContinue()) {
        rdlib::Engine::update();
        rdlib::Engine::render();
    }

    // On oublie pas de finaliser le moteur, sinon il se ferme pas
    rdlib::Engine::finalize();

    return 0;
}