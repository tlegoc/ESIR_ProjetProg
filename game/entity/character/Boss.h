//
// Created by theo on 17/05/23.
//

#ifndef ESIR_PROJETPROG_BOSS_H
#define ESIR_PROJETPROG_BOSS_H

#include "Monster.h"

class Boss : public Monster {
public:
    Boss(vec3 position);

    void update() override;

private:
    vec3 m_hero_direction;
    float m_speed;
    bool m_triggered = false;
};


#endif //ESIR_PROJETPROG_BOSS_H