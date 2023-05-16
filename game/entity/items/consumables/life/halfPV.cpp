//
// Created by kiurow590 on 16/05/23.
//

#include "halfPV.h"


halfPV::halfPV() : GenericConsumable("assets/buffs/RedHalfHeart.png") {
    //std::cout << "halfPV created" << std::endl;
}

void halfPV::use(Hero *player) {
    if (player->getPv() + 1 < player->getMaxPv()) {
        player->setPv(player->getPv() + 1);
    }
    kill();
}

