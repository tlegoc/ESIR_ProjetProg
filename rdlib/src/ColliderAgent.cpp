//
// Created by theo on 15/05/23.
//

#include "rdlib/ColliderAgent.h"

namespace rdlib {

    bool ColliderAgent::isColliding(ColliderAgent *other) const {
        return checkCollisions(other->getCenter(), other->getRadius());
    }

    std::vector<ColliderAgent*> ColliderAgent::isColliding() const {
        auto colliders = Agent::getObjectsOfType<ColliderAgent>();
        std::vector<ColliderAgent*> colliding;

        for (auto collider : colliders) {
            if (collider != this && isColliding(collider)) {
                colliding.push_back(collider);
            }
        }

        return colliding;
    }

    bool ColliderAgent::checkCollisions(vec2 pos, float size) const {
        // Check if the two circles from the two agents are colliding
        return glm::distance(pos, getCenter()) < size + getRadius();
    }


}