//
// Created by theo on 15/05/23.
//

#include "rdlib/ColliderAgent.h"

#include <iostream>

namespace rdlib {

    bool ColliderAgent::isColliding(ColliderAgent *other) const {
        return checkCollisions(other->getColliderPosition(), other->getColliderSize());
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

    bool ColliderAgent::checkCollisions(vec2 pos, vec2 size) const {
        vec2 my_pos = getColliderPosition();
        vec2 my_size = getColliderSize();

        return (my_pos.x < pos.x + size.x &&
                my_pos.x + my_size.x > pos.x &&
                my_pos.y < pos.y + size.y &&
                my_pos.y + my_size.y > pos.y);
    }


}