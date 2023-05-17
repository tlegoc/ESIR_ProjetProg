//
// Created by theo on 17/05/23.
//

#ifndef ESIR_PROJETPROG_GROUNDSLAMFX_H
#define ESIR_PROJETPROG_GROUNDSLAMFX_H

#include <rdlib/Time.h>
#include <rdlib/SpriteAgent.h>

class GroundSlamFx : public rdlib::SpriteAgent {

public:
    GroundSlamFx(glm::vec3 position) : SpriteAgent("assets/character/fx_groundslam.png", position, 0, vec2(0)) {
    }

    void update() override;
private:
    float m_lifetime = 0;
};


#endif //ESIR_PROJETPROG_GROUNDSLAMFX_H
