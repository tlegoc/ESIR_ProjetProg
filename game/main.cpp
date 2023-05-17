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
#include "entity/character/Boss.h"

void createGame() {
    rdlib::Map::load("assets/map/map.json");

    Monster *s2 = new Monster("assets/character/monster_red.png", glm::vec3(0, 0, 0),
                              glm::vec2(1), glm::vec3(1, 1, 1), 10, 1);

    std::cout << "--- Creating hero" << std::endl;
    Hero *s1 = new Hero(glm::vec3(1, 0, 0), 2, 20, 50, 2, 1, 2);

    Sword *s3 = new Sword(3, "Epée 1", "Pour Demacaia !");
    s3->setPos(glm::vec3(2, 1, 2));

    Boss *s4 = new Boss(glm::vec3(2, 3, 0));
}

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