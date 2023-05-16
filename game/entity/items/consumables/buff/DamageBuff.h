//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_DAMAGEBUFF_H
#define ESIR_PROJETPROG_DAMAGEBUFF_H


#include "../GenericConsumable.h"

class DamageBuff : public GenericConsumable {

     int m_damageBoost;

public:

    DamageBuff(const std::string &image, vec3 position = vec3(0, 0, 0));

    void use(Agent &player);

    int getDamageBoost() const;

    void update();


};


#endif //ESIR_PROJETPROG_DAMAGEBUFF_H
