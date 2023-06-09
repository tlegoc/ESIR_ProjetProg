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
        ColliderAgent() : Agent(), m_passthrough(false) {};

        bool isColliding(ColliderAgent *other, bool check_passthrough = false) const;

        std::vector<ColliderAgent *> isColliding(bool checkPassthrough = false) const;

        bool checkCollisions(vec2 pos, vec2 size) const;

        bool isPassthrough() const { return m_passthrough; }

        void setPassthrough(bool passthrough) { m_passthrough = passthrough; }

        virtual vec2 getColliderPosition() const = 0;

        virtual vec2 getColliderSize() const = 0;

    private:
        bool m_passthrough;
    };
}  // rdlib


#endif //ESIR_PROJETPROG_COLLIDERAGENT_H
