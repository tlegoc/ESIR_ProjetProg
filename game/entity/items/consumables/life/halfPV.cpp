//
// Created by kiurow590 on 16/05/23.
//

#include "halfPV.h"


halfPV::halfPV() : GenericConsumable("assets/PV_Buff/RedHalfHeart.png") {
    //std::cout << "halfPV created" << std::endl;
}

void halfPV::use(Agent & hero){
    //hero.setLife(hero.getLife() + 1);
    kill();
}

void halfPV::update() {
    //std::cout << "halfPV updated" << std::endl;
}
