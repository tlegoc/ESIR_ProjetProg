//
// Created by kiurow590 on 16/05/23.
//

#include "halfPV.h"


halfPV::halfPV() : GenericConsumable("assets/PV_Buff/RedHalfHeart.png") {
    //std::cout << "halfPV created" << std::endl;
}

void halfPV::use(Hero & player){
    if(player.getMPv() + 1 <player.getMaxPv() ){
        player.setMPv(player.getMPv() + 1);
    }
    kill();
}

