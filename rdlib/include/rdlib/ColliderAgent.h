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
        bool isColliding(ColliderAgent *other) const;

        std::vector<ColliderAgent*> isColliding() const;

        bool checkCollisions(vec2 pos, float size) const;

        virtual float getRadius() const = 0;
        virtual vec2 getCenter() const = 0;
    };
}  // rdlib


#endif //ESIR_PROJETPROG_COLLIDERAGENT_H
