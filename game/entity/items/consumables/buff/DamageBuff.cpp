//
// Created by kiurow590 on 16/05/23.
//

#include "DamageBuff.h"


DamageBuff::DamageBuff(const std::string &image, vec3 position) : GenericConsumable(image, position),
                                                                  m_damageBoost(10) {}

void DamageBuff::use(Agent &player) {
   // player.setDamage(player.getDamage() + m_damageBoost);

    kill();
}

int DamageBuff::getDamageBoost() const {
    return m_damageBoost;
}

void DamageBuff::update() {}

