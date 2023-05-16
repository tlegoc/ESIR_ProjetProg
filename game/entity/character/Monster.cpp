//
// Created by Thibault on 16/05/2023.
//

#include "Monster.h"
#include "Hero.h"

Monster::Monster(const std::string &image,vec2 collider_pos, vec2 collider_size, vec3 position, float angle,
           vec2 size, vec3 color, int pv, int damage): rdlib::ColliderSpriteAgent(image, collider_pos, collider_size, position, angle, size, color), m_pv(pv), m_damage(damage), m_invincibility(0){};

void Monster::update(){

    if (m_invincibility > 0){
        m_invincibility--;
    }

    if (!isColliding().empty()) { //inflige des dégâts au monstre qui est touché par le héro
        m_color = glm::vec3(1, 0, 0);
        if(m_invincibility == 0) {
            for (auto a: isColliding()) {
                if (dynamic_cast<Hero *>(a) != nullptr) {
                    auto hero = dynamic_cast<Hero *>(a);
                    hero->setMPv(hero->getMPv() - this->getMDamage());
                    std::cout << " Vie hero " << hero->getMPv() << " " << std::endl;
                    m_invincibility = 100;
                }
            }
        }
    } else {
        m_color = glm::vec3(1, 1, 1);
    }

    if (m_pv <= 0){
        this->kill();
    }
}


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
