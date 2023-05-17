//
// Created by Thibault on 16/05/2023.
//

#include "Hero.h"
#include "Monster.h"
#include "SwordAgent.h"
#include "../items/GenericItem.h"
#include "../../Projectiles.h"
#include <typeinfo>

#include <rdlib/UserInterface.h>

Hero::Hero(vec3 position, float speed, int pv, int max_pv, int damage, int shield, int max_shield)
        : rdlib::ColliderSpriteSheetAgent("assets/character/player.png",
                                          vec2(7.0f / 32.0f, 7.0f / 64.0f),
                                          vec2(20.0f / 32.0f, 19.0f / 64.0f),
                                          vec2(32, 64),
                                          .16f,
                                          position,
                                          0,
                                          vec2(1, 2),
                                          vec3(1)),
          m_pv(pv),
          m_max_pv(max_pv),
          m_damage(damage),
          m_shield(shield),
          m_max_shield(max_shield),
          m_direction(vec2(0, -1)),
          m_speed(speed) {

};


void Hero::update() {
    m_lifetime += rdlib::Time::getDelta();

    // On bouge en fonction des touches
    vec2 dir = vec2(0, 0);
    if (rdlib::InputManager::isKeyPressed('z')) {
        dir.y += 1;
    }

    if (rdlib::InputManager::isKeyPressed('s')) {
        dir.y -= 1;
    }

    if (rdlib::InputManager::isKeyPressed('q')) {
        dir.x -= 1;
    }

    if (rdlib::InputManager::isKeyPressed('d')) {
        dir.x += 1;
    }


    if (glm::length(dir) > 0.001) {
        dir = glm::normalize(dir);
        // We move the x direction first,
        // check collisions and if there is one, we go back
        m_pos.x += dir.x * m_speed * rdlib::Time::getDelta();
        if (!isColliding(true).empty()) {
            m_pos.x -= dir.x * m_speed * rdlib::Time::getDelta();
        }

        // We do the same for the y direction
        m_pos.y += dir.y * m_speed * rdlib::Time::getDelta();
        if (!isColliding(true).empty()) {
            m_pos.y -= dir.y * m_speed * rdlib::Time::getDelta();
        }

        m_direction = dir;
    }

    if (abs(m_direction.x) > abs(m_direction.y)) {
        if (m_direction.x > 0) {
            playAnimation({3}, true);
        } else {
            playAnimation({2}, true);
        }
    } else {
        if (m_direction.y > 0) {
            playAnimation({1}, true);
        } else {
            playAnimation({0}, true);
        }
    }

    m_attack_delay -= rdlib::Time::getDelta();
    if (rdlib::InputManager::isKeyPressed('a') && m_attack_delay < 0) {
        vec2 dir = vec2(0);
        if (abs(m_direction.x) > abs(m_direction.y)) {
            if (m_direction.x > 0) {
                dir = vec2(1, 0);
            } else {
                dir = vec2(-1, 0);
            }
        } else {
            if (m_direction.y > 0) {
                dir = vec2(0, 1);
            } else {
                dir = vec2(0, -1);
            }
        }
        // Get the position in front of the player
        vec3 sword_pos = m_pos + vec3(glm::normalize(dir), 0) * 0.9f + vec3(0, 0, 2.0f);
        //new SwordAgent(sword_pos, getDamage());
        new Projectiles("assets/sword/arrow.png", sword_pos, getDamage(), glm::normalize(dir), 10, false, true);
        m_attack_delay = 0.2f;
    }

    if (rdlib::InputManager::isKeyPressed('e')) {
        for (auto a: isColliding()) {
            if (dynamic_cast<GenericItem *>(a) != nullptr) {
                auto item = dynamic_cast<GenericItem *>(a);
                item->use(this);
            }
        }
    }

    rdlib::Engine::setCameraPosition(m_pos);
    rdlib::UserInterface::addImage("assets/character/player.png", vec2(-0.95f, 0.8f), vec2(0.2f, 0.2f), vec3(1));
}

int Hero::getPv() const {
    return m_pv;
}

int Hero::getMaxPv() const {
    return m_max_pv;
}

int Hero::getDamage() const {
    return m_damage;
}

int Hero::getShield() const {
    return m_shield;
}

void Hero::setPv(int pv) {
    m_pv = pv;
}

void Hero::setMaxPv(int max_pv) {
    m_max_pv = max_pv;
}

void Hero::setDamage(int damage) {
    m_damage = damage;
}

void Hero::setShield(int shield) {
    m_shield = shield;
}

int Hero::getMaxDamage() const {
    return m_max_damage;
}

void Hero::setMaxDamage(int max_damage) {
    m_max_damage = max_damage;
}

int Hero::getMaxShield() const {
    return m_max_shield;
}

void Hero::setMaxShield(int max_shield) {
    m_max_shield = max_shield;
};


