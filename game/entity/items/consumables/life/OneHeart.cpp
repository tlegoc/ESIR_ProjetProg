//
// Created by kiurow590 on 16/05/23.
//

#include "OneHeart.h"


OneHeart::OneHeart() : GenericConsumable("assets/PV_Buff/heartAdd.jpeg") {

}


void OneHeart::use(Hero *hero) {

    hero->setMaxPv(hero->getMaxPv()+2);
    hero->setPv(hero->getPv()+2);
    kill();
}

