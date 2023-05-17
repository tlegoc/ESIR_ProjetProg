//
// Created by theo on 17/05/23.
//

#ifndef ESIR_PROJETPROG_CREATEGAME_H
#define ESIR_PROJETPROG_CREATEGAME_H

#include <rdlib/Map.h>

#include "entity/character/Hero.h"
#include "entity/character/Monster.h"
#include "entity/character/Boss.h"
#include "entity/items/equipments/weapon/Sword.h"
#include "entity/character/TowerMonster.h"

void createGame() {
    rdlib::Map::load("assets/map/map.json", "assets/map/collider.json");

    //Monster *s2 = new Monster("assets/character/monster_red.png", glm::vec3(0, 0, 0),
     //                         glm::vec2(1), glm::vec3(1, 1, 1), 10, 1);

    std::cout << "--- Creating hero" << std::endl;
    Hero *s1 = new Hero(glm::vec3(3, 3, 0), 2, 20, 50, 2, 1, 2, createGame);

    //Sword *s3 = new Sword(3, "Epée 1", "Pour Demacaia !");
    //s3->setPos(glm::vec3(2, 1, 2));

    TowerMonster *s5 = new TowerMonster(glm::vec3(7, 10, 0));


    Boss *s4 = new Boss(glm::vec3(4, 20, 0), createGame);
}

#endif //ESIR_PROJETPROG_CREATEGAME_H
