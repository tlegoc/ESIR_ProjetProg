//
// Created by Thibault on 16/05/2023.
//

#include "Hero.h"
#include "Monster.h"
#include "SwordAgent.h"

Hero::Hero(vec3 position, float speed, int pv, int max_pv, int damage, int shield, int max_shield)
        : rdlib::ColliderSpriteSheetAgent("assets/character/player.png",
                                          vec2(7.0f/32.0f, 7.0f / 64.0f),
                                          vec2(20.0f/32.0f, 19.0f / 64.0f),
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
        if (!isColliding().empty()) {
            m_pos.x -= dir.x * m_speed * rdlib::Time::getDelta();
        }

        // We do the same for the y direction
        m_pos.y += dir.y * m_speed * rdlib::Time::getDelta();
        if (!isColliding().empty()) {
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
    if (rdlib::InputManager::isKeyPressed('e') && m_attack_delay < 0) {
        // Get the position in front of the player
        vec3 sword_pos = m_pos + vec3(m_direction, 0) * 0.5f;
        new SwordAgent(sword_pos, getDamage());
        m_attack_delay = 0.2f;
    }

    rdlib::Engine::setCameraPosition(m_pos);
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
};


