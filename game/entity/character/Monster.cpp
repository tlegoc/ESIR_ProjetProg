//
// Created by Thibault on 16/05/2023.
//

#include "Monster.h"
#include "Hero.h"

Monster::Monster(const std::string &image, vec3 position,
                 vec2 size, vec3 color, int pv, int damage, vec2 collider_pos, vec2 collider_size) : rdlib::ColliderSpriteAgent(image, collider_pos, collider_size,
                                                                                         position, 0, size, color),
                                                              m_pv(pv), m_damage(damage) {};

void Monster::update() {
    if (m_pv <= 0) {
        this->kill();
    }
}

int Monster::getPv() const {
    return m_pv;
}

int Monster::getDamage() const {
    return m_damage;
}

void Monster::setPv(int pv) {
    m_pv = pv;
}

void Monster::setDamage(int damage) {
    m_damage = damage;
}