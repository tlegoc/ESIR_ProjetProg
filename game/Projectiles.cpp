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
                         float speed)
        : ColliderSpriteAgent(image,
                              vec2(0),
                              vec2(1),
                              pos) {
    m_damage = damage;
    m_direction = direction;
    m_speed = speed;
    setPassthrough(true);

    std::cout << "Projectiles::Projectiles" << std::endl;
}

void Projectiles::update() {
    vec2 deplacement = m_direction * m_speed * rdlib::Time::getDelta();
    setPos(getPos() + vec3(deplacement, 0));
    for (auto &collider: isColliding(true)) {
        onCollision(collider);
    }
    m_lifetime -= rdlib::Time::getDelta();
    if (m_lifetime <= 0)
        kill();
}

void Projectiles::onCollision(rdlib::ColliderAgent *other) {

    // if (dynamic_cast<Hero *>(other) != nullptr) {
    //     Hero *hero = dynamic_cast<Hero *>(other);
    //     hero->setMaxPv(hero->getPv() - m_damage);
    // }

    if (dynamic_cast<Monster *>(other) != nullptr) {
        auto *monster = dynamic_cast<Monster *>(other);
        monster->setPv(monster->getPv() - m_damage);
        kill();
    }

}