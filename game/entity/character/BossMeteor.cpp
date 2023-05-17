//
// Created by theo on 17/05/23.
//

#include "BossMeteor.h"

#include "FXAgent.h"
#include "Hero.h"

#include <rdlib/Time.h>
#include <iostream>

BossMeteor::BossMeteor(glm::vec3 original_position, glm::vec3 target_position, float time_to_hit) :
        rdlib::ColliderSpriteAgent("assets/character/meteor.png", vec2(0), vec2(1), original_position, 0.0f, glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f)) {
    m_target_position = target_position;
    m_time_to_hit = time_to_hit;
    m_original_position = original_position;
    setPassthrough(true);
}

void BossMeteor::update() {
    // Lerp position
    glm::vec3 new_position = glm::mix(m_original_position, m_target_position, m_lifetime / m_time_to_hit);
    m_pos = new_position;

    if (m_lifetime > m_time_to_hit) {
        FXAgent::fx(m_pos, .3);
        // if collision with hero, damage hero by 3
        auto a = isColliding();
        if (!a.empty()) {
            for (auto &i : a) {
                if (dynamic_cast<Hero *>(i) != nullptr) {
                    std::cout << "Hero hit by meteor" << std::endl;
                    dynamic_cast<Hero *>(i)->setPv(dynamic_cast<Hero *>(i)->getPv() - 3);
                }
            }
        }

        kill();
    }

    m_lifetime += rdlib::Time::getDelta();
}