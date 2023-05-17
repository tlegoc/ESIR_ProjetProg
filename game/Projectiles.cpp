//
// Created by kiurow590 on 16/05/23.
//

#include "Projectiles.h"
#include "entity/character/Hero.h"
#include "entity/character/Monster.h"

Projectiles::Projectiles(std::string image,
                         vec3 pos,
                         int damage,
                         vec2 direction,
                         float speed,
                         bool damage_hero, bool damage_monster)
        : ColliderSpriteAgent(image,
                              vec2(0),
                              vec2(1),
                                  pos) {
    m_damage = damage;
    m_direction = direction;
    m_speed = speed;
    m_damage_hero = damage_hero;
    m_damage_monster = damage_monster;
    setPassthrough(true);
}

void Projectiles::update() {
    vec2 deplacement = m_direction * m_speed * rdlib::Time::getDelta();
    setPos(getPos() + vec3(deplacement, 0));
    for (auto &collider: isColliding()) {
        onCollision(collider);
    }
    m_lifetime -= rdlib::Time::getDelta();
    if (m_lifetime <= 0){
        kill();
    }
}

void Projectiles::onCollision(rdlib::ColliderAgent *other) {

    if (m_damage_hero && dynamic_cast<Hero *>(other) != nullptr) {
        Hero *hero = dynamic_cast<Hero *>(other);
        hero->setMaxPv(hero->getPv() - m_damage);
    }

    if (dynamic_cast<Monster *>(other) != nullptr) {
        Monster *monster = dynamic_cast<Monster *>(other);
        monster->setPv(monster->getPv() - m_damage);
        kill();
    }

}