//
// Created by Thibault on 16/05/2023.
//

#include "Monster.h"

Monster::Monster(const std::string &image, vec3 position, float angle,
           vec2 size, vec3 color, int pv, int damage): rdlib::ColliderSpriteAgent(image, position, angle, size, color), m_pv(pv), m_damage(damage){};

int Monster::getMPv() const {
    return m_pv;
}

int Monster::getMDamage() const {
    return m_damage;
}

void Monster::setMPv(int mPv) {
    m_pv = mPv;
}

void Monster::setMDamage(int mDamage) {
    m_damage = mDamage;
}
