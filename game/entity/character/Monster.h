//
// Created by Thibault on 16/05/2023.
//

#ifndef ESIR_PROJETPROG_MONSTER_H
#define ESIR_PROJETPROG_MONSTER_H

#include <rdlib/ColliderSpriteAgent.h>
#include <rdlib/Time.h>
#include <rdlib/InputManager.h>


class Monster : public rdlib::ColliderSpriteAgent{

public:
    int m_pv;
    int m_damage;
    int m_invincibility;

    void setMPv(int mPv);

    void setMDamage(int mDamage);

    int getMPv() const;

    int getMDamage() const;

    Monster(const std::string &image, vec2 collider_pos, vec2 collider_size, vec3 position, float angle, vec2 size, vec3 color, int pv, int damage);

    void setPv (int a);

    /**
 * mise à jour du Monster, dégât
 */
    void update() override;

};


#endif //ESIR_PROJETPROG_MONSTER_H
