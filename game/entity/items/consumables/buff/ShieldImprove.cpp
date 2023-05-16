//
// Created by kiurow590 on 16/05/23.
//

#include "ShieldImprove.h"

ShieldImprove::ShieldImprove(int shield_improve) : GenericConsumable(" " ),
                                                   m_shield_improve(shield_improve) {}

void ShieldImprove::use(Hero *hero) {
    if(hero->getShield() + m_shield_improve < hero->getMaxShield()){
        hero->setShield(hero->getShield() + m_shield_improve);
    }
    kill();
}


