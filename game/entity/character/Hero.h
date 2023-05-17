//
// Created by Thibault on 16/05/2023.
//

#ifndef ESIR_PROJETPROG_CHARACTER_H
#define ESIR_PROJETPROG_CHARACTER_H

#include <rdlib/ColliderSpriteSheetAgent.h>
#include <rdlib/Time.h>
#include <rdlib/InputManager.h>

class Hero : public rdlib::ColliderSpriteSheetAgent {

public:
    Hero(vec3 position, float speed, int pv, int max_pv, int damage, int shield, int max_shield, void(*callback)());

    // Hero(const std::string &image, vec3 position, float angle, vec2 size, vec3 color, int pv);

    int getPv() const;

    int getMaxPv() const;

    int getDamage() const;

    void setPv(int pv);

    void setMaxPv(int max_pv);

    void setDamage(int damage);

    void setShield(int shield);

    int getShield() const;

    int getMaxDamage() const;

    void setMaxDamage(int max_damage);

    int getMaxShield() const;

    void setMaxShield(int max_shield);

/**
 * mise à jour du Hero, déplacement, dégât
 */
    void update() override;
    //set d'object d'Aubry
    /*Hero(const std::string &image, vec3 position = vec3(0, 0, 0), float angle = 0.0f,
                         vec2 size = vec2(1, 1), vec3 color = vec3(1.0f, 1.0f, 1.0f), int m_pv = 1, int max_pv = 1, int m_damage = 1, int m_shield = 1);
*/
    //void attack ()

private:
    int m_pv;
    int m_max_pv;
    int m_damage;
    int m_shield;
    int m_max_shield;
    int m_max_damage;
    float m_lifetime = 0;
    float m_speed;
    float m_attack_delay;
    float m_last_fx;
    vec2 m_direction;
    void (*m_callback)();
};

#endif //ESIR_PROJETPROG_CHARACTER_H
