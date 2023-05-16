//
// Created by Thibault on 16/05/2023.
//

#include "Hero.h"
#include "Monster.h"

Hero::Hero(const std::string &image, vec3 position, float angle,
           vec2 size, vec3 color, int pv, int max_pv, int m_damage, int m_shield, int m_maxShield)
        : rdlib::ColliderSpriteAgent(image, vec2(0), vec2(1), position, angle, size, color), m_pv(pv), m_maxPv(max_pv),
          m_damage(m_damage), m_shield(m_shield), m_maxShield(m_maxShield), m_invincibility(0) {};


void Hero::update() {
    m_lifetime += rdlib::Time::getDelta();
    if (m_invincibility > 0) {
        m_invincibility--;
    }

    // On fait tourner l'image de 1 degré par seconde
    if (rdlib::InputManager::isKeyPressed('a')) {
        m_angle += rdlib::Time::getDelta() * 1;
    }

    if (rdlib::InputManager::isKeyPressed('e')) {
        m_angle -= rdlib::Time::getDelta() * 1;
    }

    // On change la taille de l'image
    if (rdlib::InputManager::isKeyPressed('r')) {
        m_size.x += rdlib::Time::getDelta() * 1;
        m_size.y += rdlib::Time::getDelta() * 1;
    }

    if (rdlib::InputManager::isKeyPressed('t')) {
        m_size.x -= rdlib::Time::getDelta() * 1;
        m_size.y -= rdlib::Time::getDelta() * 1;
    }

    // On bouge en fonction des touches
    if (rdlib::InputManager::isKeyPressed('z')) {
        m_pos.y += rdlib::Time::getDelta() * 1;
    }

    if (rdlib::InputManager::isKeyPressed('s')) {
        m_pos.y -= rdlib::Time::getDelta() * 1;
    }

    if (rdlib::InputManager::isKeyPressed('q')) {
        m_pos.x -= rdlib::Time::getDelta() * 1;
    }

    if (rdlib::InputManager::isKeyPressed('d')) {
        m_pos.x += rdlib::Time::getDelta() * 1;
    }

    if (rdlib::InputManager::isKeyPressed('w')) {
        rdlib::Engine::setCameraZoom(rdlib::Engine::getCameraZoom() + rdlib::Time::getDelta() * 10);
    }

    if (rdlib::InputManager::isKeyPressed('x')) {
        rdlib::Engine::setCameraZoom(rdlib::Engine::getCameraZoom() - rdlib::Time::getDelta() * 10);
    }

    if (!isColliding().empty()) { //inflige des dégâts au monstre qui est touché par le héro
        m_color = glm::vec3(1, 0, 0);
        if (m_invincibility == 0) {
            for (auto a: isColliding()) {
                if (dynamic_cast<Monster *>(a) != nullptr) {
                    auto monster = dynamic_cast<Monster *>(a);
                    monster->setMPv(monster->getMPv() - this->getMDamage());
                    std::cout << " Vie monstre " << monster->getMPv() << " " << std::endl;
                    m_invincibility = 100;
                }
            }
        }
    } else {
        m_color = glm::vec3(1, 1, 1);
    }
}

int Hero::getMPv() const {
    return m_pv;
}

int Hero::getMaxPv() const {
    return m_maxPv;
}

int Hero::getMDamage() const {
    return m_damage;
}

int Hero::getMShield() const {
    return m_shield;
}

void Hero::setMPv(int mPv) {
    m_pv = mPv;
}

void Hero::setMaxPv(int maxPv) {
    m_maxPv = maxPv;
}

void Hero::setMDamage(int mDamage) {
    m_damage = mDamage;
}

void Hero::setMShield(int mShield) {
    m_shield = mShield;
};


