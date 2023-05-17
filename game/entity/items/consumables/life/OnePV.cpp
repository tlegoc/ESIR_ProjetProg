//
// Created by kiurow590 on 16/05/23.
//

#include "OnePV.h"

OnePV::OnePV(vec3 pos) : GenericConsumable("assets/PV_Buff/HeartFull.png", pos) { }



void OnePV::use(Hero *player) {
    if(player->getPv() + 2 <player->getMaxPv() ){
        player->setPv(player->getPv() + 2);
    }
    kill();
}