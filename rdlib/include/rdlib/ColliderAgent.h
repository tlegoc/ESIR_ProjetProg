//
// Created by theo on 15/05/23.
//

#ifndef ESIR_PROJETPROG_COLLIDERAGENT_H
#define ESIR_PROJETPROG_COLLIDERAGENT_H

#include "Agent.h"

#include <glm/glm.hpp>

using namespace glm;

namespace rdlib {
    class ColliderAgent : public virtual Agent {
    public:
        ColliderAgent() : Agent() {};

        bool isColliding(ColliderAgent *other) const;

        std::vector<ColliderAgent*> isColliding() const;

        bool checkCollisions(vec2 pos, vec2 size) const;

        virtual vec2 getColliderPosition() const = 0;
        virtual vec2 getColliderSize() const = 0;
    };
}  // rdlib


#endif //ESIR_PROJETPROG_COLLIDERAGENT_H
