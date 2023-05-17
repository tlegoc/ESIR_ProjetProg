//
// Created by theo on 17/05/23.
//

#include "Boss.h"

#include "Hero.h"

Boss::Boss(vec3 position) : Monster("assets/character/boss.png", position, vec2(3, 3), vec3(1, 1, 1), 100, 10, vec2(1/3.0, 0), vec2(1/3.0, 3/4.0)) {

}

void Boss::update() {
    auto hero = Agent::getObjectsOfType<Hero>();
    if (!hero.empty()) {
        auto hero_pos = hero[0]->getPos();
        auto hero_dir = glm::normalize(hero_pos - getPos());
        auto hero_dist = glm::distance(hero_pos, getPos());

        if (hero_dist < 5 || m_triggered) {
            m_triggered = true;
            m_hero_direction = hero_dir;
            m_speed = 0.5;
        } else {
            m_speed = 0;
        }
    }

    Monster::update();
}
