//
// Created by theo on 17/05/23.
//

#include "GroundSlamFx.h"

void GroundSlamFx::update() {
    m_lifetime += rdlib::Time::getDelta();


    float v = (float)(1.0 - glm::pow(1.0 - m_lifetime, 4.0));
    setSize(vec2(1, 1) * (7.0f * v));
    if (m_lifetime > 1) {
        kill();
    }
}