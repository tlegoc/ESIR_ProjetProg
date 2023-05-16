//
// Created by Thibault on 16/05/2023.
//

#ifndef ESIR_PROJETPROG_CHARACTER_H
#define ESIR_PROJETPROG_CHARACTER_H

#endif //ESIR_PROJETPROG_CHARACTER_H

#include "hero.cpp"
#include <rdlib/SpriteAgent.h>

class hero : public rdlib::SpriteAgent {

public:
    int m_pv;
    int max_pv;
    int m_damage;
    int shield;
    //set d'object d'Aubry
    hero(const std::string &image, vec3 position = vec3(0, 0, 0), float angle = 0.0f,
                         vec2 size = vec2(1, 1), vec3 color = vec3(1.0f, 1.0f, 1.0f), int m_pv = 1, int max_pv = 1, int m_damage = 1, int shield = 1);


};