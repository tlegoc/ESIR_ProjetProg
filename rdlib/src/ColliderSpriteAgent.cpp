//
// Created by theo on 15/05/23.
//

#include "rdlib/ColliderSpriteAgent.h"

#include <iostream>

namespace rdlib {
    vec2 ColliderSpriteAgent::getColliderPosition() const {
        return (m_collider_pos - vec2(0.5f)) * m_size + vec2(getPos().x, getPos().y);
    }

    vec2 ColliderSpriteAgent::getColliderSize() const {
        return (m_collider_size) * m_size;
    }
}