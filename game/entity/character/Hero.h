//
// Created by Thibault on 16/05/2023.
//

#ifndef ESIR_PROJETPROG_CHARACTER_H
#define ESIR_PROJETPROG_CHARACTER_H

#endif //ESIR_PROJETPROG_CHARACTER_H

#include <rdlib/ColliderSpriteAgent.h>
#include <rdlib/Time.h>
#include <rdlib/InputManager.h>


class Hero : public rdlib::ColliderSpriteAgent {

public:
    Hero(const std::string &image, vec3 position, float angle, vec2 size, vec3 color, int pv, int max_pv, int m_damage, int m_shield);

   // Hero(const std::string &image, vec3 position, float angle, vec2 size, vec3 color, int pv);

    int m_pv;
    int max_pv;
    int m_damage;
    int m_shield;
    float m_lifetime = 0;

    void update() override;
    //set d'object d'Aubry
    /*Hero(const std::string &image, vec3 position = vec3(0, 0, 0), float angle = 0.0f,
                         vec2 size = vec2(1, 1), vec3 color = vec3(1.0f, 1.0f, 1.0f), int m_pv = 1, int max_pv = 1, int m_damage = 1, int m_shield = 1);
*/
    //void attack ()

};