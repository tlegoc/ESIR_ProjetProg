//
// Created by theo on 17/05/23.
//

#include "TowerMonster.h"
#include "Hero.h"
#include "../../Projectiles.h"

#include "../items/consumables/life/OnePV.h"

#include "FXAgent.h"

TowerMonster::TowerMonster(glm::vec3 position) : Monster("assets/props/tower11x3.png", position, vec2(1, 3), vec3(1, 1, 1), 20, 5,
                                                         vec2(1 / 3.0, 0), vec2(1 / 3.0, 2 / 4.0)), m_shoot_delay(1.0f),
                                                 m_attack_delay(1.0f), m_direction(vec2(0, 0)) {
    m_speed = 0.1;
}

void TowerMonster::update() {
    auto hero = Agent::getObjectsOfType<Hero>();
    if (!hero.empty()) {
        vec3 hero_pos = hero[0]->getPos();
        vec3 hero_dir = glm::normalize(hero_pos - getPos());
        float hero_dist = glm::distance(hero_pos, getPos());

        m_shoot_delay -= rdlib::Time::getDelta();
        if (hero_dist < 5) {
            m_pos += hero_dir * m_speed * rdlib::Time::getDelta();
            if (m_shoot_delay < 0) {
                std::cout << "shoot" << std::endl;
                tirer();
                m_shoot_delay = 1.0f;
            }
        }
    }

    if (getPv() <= 0) {
        new OnePV(getPos());
        this->kill();
        FXAgent::fx(m_pos, .3);
    }
}

float TowerMonster::getSpeed() const {
    return m_speed;
}

void TowerMonster::setSpeed(float speed) {
    m_speed = speed;
}

void TowerMonster::tirer() {
    std::cout << "MobTower::tirer()" << std::endl;
    auto hero = Agent::getObjectsOfType<Hero>();
    vec3 hero_pos = hero[0]->getPos();
    vec3 direction = glm::normalize(hero_pos - getPos());
    new Projectiles("assets/sword/arrow.png", getPos() + vec3(0, 0, 1), getDamage(), direction, 5, true, false);
}