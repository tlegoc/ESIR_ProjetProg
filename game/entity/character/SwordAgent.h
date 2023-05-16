//
// Created by theo on 16/05/23.
//

#ifndef ESIR_PROJETPROG_SWORDAGENT_H
#define ESIR_PROJETPROG_SWORDAGENT_H

#include <rdlib/ColliderSpriteSheetAgent.h>

#include "Monster.h"

class SwordAgent : public rdlib::ColliderSpriteSheetAgent {
public:
    SwordAgent(vec3 position, int damage);

    void update() override;

private:
};


#endif //ESIR_PROJETPROG_SWORDAGENT_H
