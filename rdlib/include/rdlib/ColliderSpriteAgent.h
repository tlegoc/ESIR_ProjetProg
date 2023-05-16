//
// Created by theo on 15/05/23.
//

#ifndef ESIR_PROJETPROG_COLLIDERSPRITEAGENT_H
#define ESIR_PROJETPROG_COLLIDERSPRITEAGENT_H

#include "rdlib/SpriteAgent.h"
#include "rdlib/ColliderAgent.h"

namespace rdlib {
    class ColliderSpriteAgent : public SpriteAgent, public ColliderAgent {

    public:
        explicit ColliderSpriteAgent(const std::string &image,
                                     vec2 collider_pos,
                                     vec2 collider_size,
                                     vec3 position = vec3(0, 0, 0),
                                     float angle = 0.0f,
                                     vec2 size = vec2(1, 1),
                                     vec3 color = vec3(1.0f, 1.0f, 1.0f)) : SpriteAgent(image,
                                                                                        position,
                                                                                        angle,
                                                                                        size,
                                                                                        color) {
            m_collider_pos = collider_pos;
            m_collider_size = collider_size;
        };


        vec2 getColliderPosition() const override;

        vec2 getColliderSize() const override;

    private:
        vec2 m_collider_pos{};
        vec2 m_collider_size{};
    };
} // rdlib


#endif //ESIR_PROJETPROG_COLLIDERSPRITEAGENT_H
