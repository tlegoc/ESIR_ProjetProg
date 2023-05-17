//
// Created by kiurow590 on 17/05/23.
//

#ifndef ESIR_PROJETPROG_MOBTOWER_H
#define ESIR_PROJETPROG_MOBTOWER_H


#include "Monster.h"

class MobTower : public Monster {

private :

    float m_speed;
    float m_attack_delay;
    float m_shoot_delay;
    vec2 m_direction;

public:

MobTower(vec3 position);

    void update() override;

    float getSpeed() const;

    void setSpeed(float speed);

    /**
     * tire un objet de type projectile vers le joueur
     */
    void tirer();


};


#endif //ESIR_PROJETPROG_MOBTOWER_H
