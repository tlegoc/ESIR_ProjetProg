//
// Created by theo on 16/05/23.
//

#include "rdlib/ColliderSpriteSheetAgent.h"

namespace rdlib {
    vec2 ColliderSpriteSheetAgent::getColliderPosition() const {
        return (m_collider_pos - vec2(0.5f)) * m_size + vec2(getPos().x, getPos().y);
    }

    vec2 ColliderSpriteSheetAgent::getColliderSize() const {
        return (m_collider_size) * m_size;
    }
} // rdlib