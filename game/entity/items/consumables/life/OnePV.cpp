//
// Created by kiurow590 on 16/05/23.
//

#include "OnePV.h"

OnePV::OnePV() : GenericConsumable("assets/PV_Buff/RedFullHeart.png") { }

void OnePV::update() {
}

void OnePV::use(Agent &player) {
   // player.setLife(player.getLife() + 2);
   kill();

}