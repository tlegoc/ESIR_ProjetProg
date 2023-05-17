//
// Created by theo on 16/05/23.
//

#include "SwordAgent.h"

#include <rdlib/Time.h>

SwordAgent::SwordAgent(glm::vec3 position, int damage) : ColliderSpriteSheetAgent(
        "assets/character/stone.png",
        vec2(0), vec2(1),
        uvec2(32), .016f,
        position) {

    playAnimation({0, 1, 2, 3, 4, 5}, false);
    for (auto a: isColliding()) {
        Monster *monster = dynamic_cast<Monster *>(a);
        if (monster) {
            monster->setPv(monster->getPv() - damage);
        }
    }
};

void SwordAgent::update() {
    if (animationFinished()) {
        kill();
    }
}