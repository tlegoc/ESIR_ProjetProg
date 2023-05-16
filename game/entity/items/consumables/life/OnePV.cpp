//
// Created by kiurow590 on 16/05/23.
//

#include "OnePV.h"

OnePV::OnePV() : GenericConsumable("assets/PV_Buff/RedFullHeart.png") { }



void OnePV::use(Hero &player) {
    if(player.getMPv() + 2 <player.getMaxPv() ){
        player.setMPv(player.getMPv() + 2);
    }
    kill();

}