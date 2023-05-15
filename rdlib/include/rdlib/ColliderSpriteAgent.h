//
// Created by theo on 15/05/23.
//

#ifndef ESIR_PROJETPROG_COLLIDERSPRITEAGENT_H
#define ESIR_PROJETPROG_COLLIDERSPRITEAGENT_H

#include "rdlib/Sprite.h"
#include "rdlib/ColliderAgent.h"

namespace rdlib {
    class ColliderSpriteAgent : public Sprite, public ColliderAgent {

        // Same constructor as sprite
        using Sprite::Sprite;

        // Override getRadius and getCenter from ColliderAgent
        float getRadius() const override;

        vec2 getCenter() const override;
    };
} // rdlib


#endif //ESIR_PROJETPROG_COLLIDERSPRITEAGENT_H
