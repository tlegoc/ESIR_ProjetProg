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
    void setPv(int pv);

    void setDamage(int damage);

    int getPv() const;

    int getDamage() const;

    Monster(const std::string &image, vec3 position, vec2 size, vec3 color, int pv, int damage);

    /**
 * mise à jour du Monster, dégât
 */
    void update() override;

private:
    int m_pv;
    int m_damage;

};


#endif //ESIR_PROJETPROG_MONSTER_H
