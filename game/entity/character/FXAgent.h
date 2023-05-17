//
// Created by theo on 17/05/23.
//

#ifndef ESIR_PROJETPROG_FXAGENT_H
#define ESIR_PROJETPROG_FXAGENT_H

#include <rdlib/SpriteSheetAgent.h>

using namespace rdlib;

class FXAgent : public SpriteSheetAgent {

public:
    FXAgent(const std::string &image,
            uvec2 tile_size,
            float frametime,
            vec3 position = vec3(0, 0, 0),
            float angle = 0.0f,
            vec2 size = vec2(.4, .4),
            vec3 color = vec3(1.0f, 1.0f, 1.0f)) : SpriteSheetAgent(image,
                                                                    tile_size,
                                                                    frametime,
                                                                    position,
                                                                    angle,
                                                                    size,
                                                                    color) {
    };

    void update() override;

    static void fx(vec3 position, float range = 0.5f);
};

// rdlib

#endif //ESIR_PROJETPROG_FXAGENT_H
