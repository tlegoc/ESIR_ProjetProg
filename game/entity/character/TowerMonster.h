//
// Created by theo on 17/05/23.
//

#ifndef ESIR_PROJETPROG_TOWERMONSTER_H
#define ESIR_PROJETPROG_TOWERMONSTER_H

#include "Monster.h"

class TowerMonster : public Monster {

private :

    float m_speed;
    float m_attack_delay;
    float m_shoot_delay;
    vec2 m_direction;

public:

    TowerMonster(vec3 position);

    void update() override;

    float getSpeed() const;

    void setSpeed(float speed);

    /**
     * tire un objet de type projectile vers le joueur
     */
    void tirer();


};


#endif //ESIR_PROJETPROG_TOWERMONSTER_H
