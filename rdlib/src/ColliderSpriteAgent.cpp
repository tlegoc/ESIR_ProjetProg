//
// Created by theo on 15/05/23.
//

#include "rdlib/ColliderSpriteAgent.h"


namespace rdlib {
    float ColliderSpriteAgent::getRadius() const {
        return (m_size.x > m_size.y ? m_size.x : m_size.y) / 2;
    }


    vec2 ColliderSpriteAgent::getCenter() const {
        // Return the center of the sprite
        return m_pos + vec3(.5f, .5f, 0);
    }
}