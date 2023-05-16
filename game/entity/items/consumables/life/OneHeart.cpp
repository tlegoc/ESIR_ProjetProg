//
// Created by kiurow590 on 16/05/23.
//

#include "OneHeart.h"


OneHeart::OneHeart() : GenericConsumable("assets/PV_Buff/heartAdd.jpeg") {

}


void OneHeart::update() {

}

void OneHeart::use(Agent &hero) {
    //hero.setmaxPV(hero.getLife()+2);
    //hero.setLife(hero.getLife()+2);
    kill();
}

