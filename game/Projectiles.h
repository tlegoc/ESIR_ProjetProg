//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_PROJECTILES_H
#define ESIR_PROJETPROG_PROJECTILES_H


#include "rdlib/ColliderSpriteAgent.h"

class Projectiles : public rdlib::ColliderSpriteAgent{

private:

    int m_damage;
    vec2 m_direction;
    float m_speed;
    float m_lifetime = 10;

public:

    Projectiles(const std::string imgpath, vec3 pos, int damage, vec2 direction, float speed);

    void update()override;

    void onCollision(rdlib::ColliderAgent *other);


};


#endif //ESIR_PROJETPROG_PROJECTILES_H
