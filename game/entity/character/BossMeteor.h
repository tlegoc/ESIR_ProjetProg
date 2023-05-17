//
// Created by theo on 17/05/23.
//

#ifndef ESIR_PROJETPROG_BOSSMETEOR_H
#define ESIR_PROJETPROG_BOSSMETEOR_H

#include <rdlib/ColliderSpriteAgent.h>

class BossMeteor : public rdlib::ColliderSpriteAgent {
public:
    BossMeteor(vec3 original_position, vec3 target_position, float time_to_hit);

    void update() override;

private:
    vec3 m_original_position;
    vec3 m_target_position;
    float m_time_to_hit;
    float m_lifetime = 0;
};


#endif //ESIR_PROJETPROG_BOSSMETEOR_H
