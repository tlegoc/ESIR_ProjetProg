//
// Created by kiurow590 on 16/05/23.
//

#include "Projectiles.h"
#include "entity/character/Hero.h"
#include "entity/character/Monster.h"

#include <typeinfo>


Projectiles::Projectiles(const std::string imgpath, vec3 pos, int damage, vec2 direction, float speed) : ColliderSpriteAgent(imgpath, pos, vec2(1) ){
    this->m_damage = damage;
    this->m_direction = direction;
    this->m_speed = speed;
}

void Projectiles::update(){
    vec2 deplacement = m_direction * m_speed * rdlib::Time::getDelta() ;
    setPos(getPos() + vec3(deplacement, 0));
    for (auto &collider : this->isColliding(true)) {
        this->onCollision(collider);
    }
    m_lifetime -= rdlib::Time::getDelta();
}

void Projectiles::onCollision(rdlib::ColliderAgent *other){

    if(dynamic_cast<Hero *>(other)){
        Hero *hero = dynamic_cast<Hero *>(other);
        hero->setMaxPv(hero->getPv()-this->m_damage);

    }

    if(dynamic_cast<Monster *>(other)){
        auto *monster = dynamic_cast<Monster *>(other);
        monster->setPv(monster->getPv()-this->m_damage);
    }
    kill();

}