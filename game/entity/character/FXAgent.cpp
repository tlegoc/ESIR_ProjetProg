//
// Created by theo on 17/05/23.
//

#include "FXAgent.h"


void FXAgent::update() {
    if (animationFinished()) {
        kill();
    }
}

void FXAgent::fx(glm::vec3 position, float range) {
    for (int i = 0; i < 5; i++) {
        //create new random vec3 offset between -range and range
        auto offset = glm::vec3(
                (float) (rand() % 100) / 100 * range * 2 - range,
                (float) (rand() % 100) / 100 * range * 2 - range,
                0);

        auto *fx = new FXAgent("assets/ui/fx.png", uvec2(16), .016f, position + offset);
        fx->playAnimation({0, 1, 2, 3, 4, 5}, false);
    }
}
